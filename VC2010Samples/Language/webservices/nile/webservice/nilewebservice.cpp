#include "stdafx.h"
#include "nilewebservice.h"

using namespace Nile;

NileWebService::NileWebService()
{
	// NileWebService objects will have a NileConnection member.  Creating NileConnection objects
	// is expensive, so we want to be able to re-use a single instance.  The problem is that ASP.NET
	// Web Services are stateless; meaning that for each web method call, there will be a new instance
	// of NileWebService created.  So, We are going to cache our NileConnection object in the 
	// Application state.This way, all instances of NileWebService can share this resource.  
	
	// First see if we already have an instance to use.  Application state objects are stored
	// as Object*, so we have to cast to NileConnection*.  There are 3 options for casting in 
	// Managed Extensions for C++:
	//
	//		__try_cast   : This will throw an exception if the cast fails.
	//		dynamic_cast : This will return null if the cast fails.
	//		static_cast  : This will force the compiler to allow the cast.  This should be used
	//					   with caution.
	//
	// We'll use dynamic_cast, so we'll treat a failing cast as if we couldn't find our connection
	// object.
	
	_nileConnection = dynamic_cast<NileConnection^>(this->Application->Get("_nileConnection"));
	
	if (!_nileConnection)
	{
		// create a new instance and store it if we don't have one
		_nileConnection = gcnew NileConnection(CONNECTION_STRING);        
		this->Application->Set("_nileConnection", _nileConnection);
	}
}

bool NileWebService::VerifyUser(String^     userID,
								String^,
								[Out] Int32%   customerID,
								[Out] Int32%   sessionID)
{    
	sessionID = -1;
	customerID = -1;

    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdGetUserParam;
    SqlParameterCollection^ ps = cmd->Parameters;

	ps[0]->Value = userID;
	ps[1]->Value = Convert::DBNull;
	
    try
    {
        cmd->ExecuteNonQuery();          
        
		customerID = Int32::Parse(ps[1]->Value->ToString());

        if (&customerID != nullptr)
        {           
            // if the customerId is not 0, then create a session id for the users as well
            cmd = _nileConnection->_cmdGetSessionParam;
            ps = cmd->Parameters;
            ps[0]->Value = Convert::DBNull;

            cmd->ExecuteNonQuery();
			
			sessionID = Int32::Parse(ps[0]->Value->ToString());
        }
    }
    catch(Exception^ e)
    {
		// for debugging if you have connection problems
		String^ s = e->ToString();
		System::Console::WriteLine(s);
        sessionID = -1;
        customerID = -1;

		// close our db connection to be safe if any exceptions are thrown; we don't want our
		// connection to be in an invalid state
        
        _nileConnection->Disconnect();
    }

    return ((sessionID != -1) && (customerID != -1));    
}

bool NileWebService::UpdateAccount( int	    customerId,
									String^ firstName,
									String^ lastName,
									String^ email,
									String^ phone,
									String^ userName,
									String^ password,
									String^ address1,
									String^ city,
									String^ state,
									String^ zip,
									String^ creditCard,
									String^ creditCardExpiration)
{
	bool succeeded = false;

    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdUpdateCustomer;
    SqlParameterCollection^ ps = cmd->Parameters;

	ps[0]->Value = customerId;
    ps[1]->Value = firstName;
    ps[2]->Value = lastName;
    ps[3]->Value = address1;
    ps[4]->Value = city;
    ps[5]->Value = state;
	ps[6]->Value = zip;
    ps[7]->Value = email;
    ps[8]->Value = phone;
    ps[9]->Value = creditCard;
    ps[10]->Value = creditCardExpiration;
    ps[11]->Value = userName;
    ps[12]->Value = password;

    try
    {   
        cmd->ExecuteNonQuery();
		succeeded = true;
    }
    catch(Exception^)
    {
        // close our db connection to be safe if any exceptions are thrown; we don't want our
		// connection to be in an invalid state
        
        _nileConnection->Disconnect();
    }

    return succeeded;
}

bool NileWebService::PlaceOrder(int      customerId,
								int      sessionId,
								Decimal  netAmount)
{
	bool succeeded = false;

    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdPurchaseCartForSession2;
    SqlParameterCollection^ ps = cmd->Parameters;
        
    ps[0]->Value = customerId;
    ps[1]->Value = sessionId;
    ps[2]->Value = netAmount;
	ps[3]->Value = Decimal::Multiply (netAmount, (Decimal)0.05);
	ps[4]->Value = Decimal::Multiply (netAmount, (Decimal)1.05);

    try
    {       
        cmd->ExecuteNonQuery();
        succeeded = true;
    }
    catch(Exception^)
    {    
        // close our db connection to be safe if any exceptions are thrown; we don't want our
		// connection to be in an invalid state
        
        _nileConnection->Disconnect();
    }

    return succeeded;      
}

bool NileWebService::GetAccountInfo(int      customerId,
									String^ firstName,
									String^ lastName,
									String^ email,
									String^ phone,
									String^ userName,
									String^ password,
									String^ address1,
									String^ city,
									String^ state,
									String^ zip,
									String^ creditCard,
									String^ creditCardExpiration)
{
	bool succeeded = false;

    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdGetUserDetailsParam;
    SqlParameterCollection^ ps = cmd->Parameters;
        
    ps[0]->Value = customerId;
    for (int i = 1; i <= 12; i++) 
	{
        ps[i]->Value = Convert::DBNull;
    }

    try 
    {
        cmd->ExecuteNonQuery();
                
        firstName            = ps[1]->Value->ToString();
        lastName             = ps[2]->Value->ToString();
        address1             = ps[3]->Value->ToString();
        city                 = ps[4]->Value->ToString();
        state                = ps[5]->Value->ToString();
        zip                  = ps[6]->Value->ToString();
        email                = ps[7]->Value->ToString();
        phone                = ps[8]->Value->ToString();
        creditCard           = ps[9]->Value->ToString();
        creditCardExpiration = ps[10]->Value->ToString();
        userName             = ps[11]->Value->ToString();
        password             = ps[12]->Value->ToString();

        succeeded = true;
    }
    catch(Exception^)
    {        
        firstName            = "";
        lastName             = "";
        email                = "";
        phone                = "";
        userName             = "";
        password             = "";
        address1             = "";
        city                 = "";
        state                = "";
        zip                  = "";
        creditCard           = "";
        creditCardExpiration = "";
    
        // close our db connection to be safe if any exceptions are thrown; we don't want our
        // connection to be in an invalid state

        _nileConnection->Disconnect();
    }

    return succeeded;
}

bool NileWebService::CreateAccount( String^   firstName,
									String^   lastName,
									String^   email,
									String^   phone,
									String^   userName,
									String^   password,
									String^   address1,
									String^   city,
									String^   state,
									String^   zip,
									String^   creditCard,
									String^   creditCardExpiration,
									[Out] Int32% customerId,
									[Out] Int32% sessionId)
{
	bool succeeded = true;

	_nileConnection->EnsureConnection();
	SqlCommand^ cmd = _nileConnection->_cmdAddCustomer2;
	SqlParameterCollection^ ps = cmd->Parameters;

	ps[0]->Value = firstName;
	ps[1]->Value = lastName;
	ps[2]->Value = address1;
	ps[3]->Value = city;
	ps[4]->Value = state;
	ps[5]->Value = zip;
	ps[6]->Value = email;
	ps[7]->Value = phone;
	ps[8]->Value = creditCard;
	ps[9]->Value = creditCardExpiration;
	ps[10]->Value = userName;
	ps[11]->Value = password;
	ps[12]->Value = Convert::DBNull;

	try
	{
		cmd->ExecuteNonQuery();
		customerId = Int32::Parse(ps[12]->Value->ToString());

		cmd = _nileConnection->_cmdGetSessionParam;
		ps = cmd->Parameters;
		ps[0]->Value = Convert::DBNull;

		cmd->ExecuteNonQuery();
		sessionId = Int32::Parse(ps[0]->Value->ToString());
	}
	catch(Exception^)
	{
		succeeded = false;
        customerId = -1;
		sessionId = -1;
        
        // close our db connection to be safe if any exceptions are thrown; we don't want our
        // connection to be in an invalid state
		_nileConnection->Disconnect();		
	}

	return succeeded;
}

bool NileWebService::AddToOrUpdateCart(int sessionId, int productId)
{
    bool succeeded = false;

    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdAddToOrUpdateCart;
    SqlParameterCollection^ ps = cmd->Parameters;
    ps[0]->Value = sessionId;
    ps[1]->Value = productId;

    try
    {           
        cmd->ExecuteNonQuery();
        succeeded = true;
    }
    catch(Exception^)
    {        
        // close our db connection to be safe if any exceptions are thrown; we don't want our
        // connection to be in an invalid state
        _nileConnection->Disconnect();
    }

    return succeeded;
}

bool NileWebService::UpdateCart(int itemID, int quantity, int sessionID)
{
	bool succeeded = false;

    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdUpdateCart;
    SqlParameterCollection^ ps = cmd->Parameters;

    ps[0]->Value = itemID;
    ps[1]->Value = quantity;
	ps[2]->Value = sessionID;

    try
    {
        cmd->ExecuteNonQuery();
        succeeded = true;
    }       
    catch(Exception^)
    {
        // close our db connection to be safe if any exceptions are thrown; we don't want our
        // connection to be in an invalid state
        _nileConnection->Disconnect();
    }   

    return succeeded;
}

bool NileWebService::ViewCart(int sessionId, array<ShoppingCartItem^>^ items)
{
	bool succeeded = false;

	_nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdViewCart;
    SqlParameterCollection^ ps = cmd->Parameters;

    ps[0]->Value = sessionId;

    try
    {
		items = gcnew array<ShoppingCartItem^>(0);

		// execute our stored proc to get our customer's shopping cart items
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read())
		{
			// ShoppingCartItem is a nested struct.  It includes a BookData
			// struct member as well as quantity integer value

			ShoppingCartItem^ shoppingCartItem = gcnew ShoppingCartItem();
						
			// Get our book data.  Note that we can't fill in the retail member since our
			// stored proc does not return it.  We still want to nest BookData inside
			// ShoppingCartData because it will be a good example of how nested structs can be
			// passed from a web service

			BookData^ bookData = gcnew BookData();

			bookData->BookId = reader->GetInt32(0).ToString();
			bookData->Title  = reader->GetString(1)->ToString();
			bookData->Author = reader->GetString(2)->ToString();
			bookData->Price	 = String::Format("{0:C}", reader->GetDecimal(3).ToString());
			shoppingCartItem->BookData = bookData;

			shoppingCartItem->Quantity = reader->GetInt32(4);

			// add the item to our list
			((IList^)items)->Add(shoppingCartItem);
		}
       reader->Close();
	   succeeded = true;
    }
    catch(Exception^)
    {
        // close our db connection to be safe if any exceptions are thrown; we don't want our
        // connection to be in an invalid state
        _nileConnection->Disconnect();
    }

	return succeeded;
}

bool NileWebService::ListByAuthor(String^ author, array<BookData^>^ results)
{
	_nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdTestSearchByAuthorForward;
    SqlParameterCollection^ ps = cmd->Parameters;
    ps[0]->Value = author;

    return GetBookDataListFromCmd(cmd, results);    
}

bool NileWebService::ListBySubject(int subjectId, array<BookData^>^ results)
{
    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdSearchByExactSubject;
    SqlParameterCollection^ ps = cmd->Parameters;
    ps[0]->Value = subjectId;

    return GetBookDataListFromCmd(cmd, results);    
}

bool NileWebService::ListBySubjectName(String^ subjectName, array<BookData^>^ results)
{
	_nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdTestSearchBySubjectForward;
    SqlParameterCollection^ ps = cmd->Parameters;
    ps[0]->Value = subjectName;

    return GetBookDataListFromCmd(cmd, results);    
}

bool NileWebService::ListByTitle(String^ title, array<BookData^>^ results)
{
    _nileConnection->EnsureConnection();
    SqlCommand^ cmd = _nileConnection->_cmdTestSearchByTitleForward;
    SqlParameterCollection^ ps = cmd->Parameters;
    ps[0]->Value = title;

	return GetBookDataListFromCmd(cmd, results);    
}

bool NileWebService::ListBySpecials(array<SpecialData^>^ specials)
{
	// return our results in an array list
	specials = gcnew array<SpecialData^>(0);
	
	// make sure we have a connection to our database
	_nileConnection->EnsureConnection();

    SqlCommand^ cmd = _nileConnection->_cmdGetSpecials;
    try
    {
		// call our stored proc to get the specials	
        SqlDataReader^ results = cmd->ExecuteReader();
		
		while (results->Read())        
		{			
			SpecialData^ ss = gcnew SpecialData();
			ss->Title = results->GetString(1);
			ss->Author = results->GetString(2);
                
			((IList^)specials)->Add(ss);
		}
        results->Close();      
    }
    catch(Exception^)
    {
        // close our db connection to be safe if any exceptions are thrown; we don't want our
        // connection to be in an invalid state
        _nileConnection->Disconnect();
    }   

    // success indicates that we have specials
	return ((IList^)specials)->Count > 0;
}

bool NileWebService::GetBookDataListFromCmd(SqlCommand^ cmd, array<BookData^>^ bookDataList)
{
	bool succeeded = false;
	try
    {
        SqlDataReader^ reader = cmd->ExecuteReader();	
		
		bookDataList = gcnew array<BookData^>(0);
		while (reader->Read())
		{			
			// add each book to our list
			BookData^ bookData = gcnew BookData();
	   
			Decimal price = reader->GetDecimal(3);
			Decimal retail = reader->GetDecimal(4);
			Decimal save = retail - price;

			bookData->BookId = reader->GetInt32(0).ToString();
			bookData->Title	 = reader->GetString(1);
			bookData->Author = reader->GetString(2);

            // format our prices now as strings since we hardly ever have to deal with them as numerical values;
            // most of the time, we are just going to display them
			bookData->Price	 = String::Format("{0:C}", price.ToString());
			bookData->Retail = String::Format("{0:C}", retail.ToString());
			bookData->Save	 = String::Format("{0:C}", save.ToString());

			((IList^)bookDataList)->Add(bookData);
		}		
		reader->Close();
		succeeded = true;
	}
    catch(Exception^)
    {
		// close our db connection to be safe if any exceptions are thrown; we don't want our
		// connection to be in an invalid state
        _nileConnection->Disconnect();
    }   

	return succeeded;
}
