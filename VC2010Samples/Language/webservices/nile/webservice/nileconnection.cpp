#include "stdafx.h"
#include "nileconnection.h"
using namespace Nile;

NileConnection::NileConnection(String^ connection) 
{
    _connectionString = connection;
}

void NileConnection::EnsureConnection() 
{
    // if our connection has already been created, get out of here (EnsureConnection has 
	// succeeded)
	if (_sqlConnection)
        return;
   
	// otherwise, create the connection
    try 
	{
        // re-use these variables to access information about each of our stored procs
        SqlParameterCollection^ ps;
        SqlParameter^ p;

		// connect to our database
		_sqlConnection = gcnew SqlConnection(_connectionString);
        _sqlConnection->Open();

		// SqlCommand objects allow us to access our stored procedures.  We'll create all
		// the commands we need at start up.  NileConnection instances should be cached, so
		// this expensive start up code is only executed once.
	
		// create SqlCommand for sp_GetUserParam and add its parameters
        _cmdGetUserParam = gcnew SqlCommand("sp_GetUserParam", _sqlConnection);
		_cmdGetUserParam->CommandType = CommandType::StoredProcedure;
        ps = _cmdGetUserParam->Parameters;
        ps->Add(gcnew SqlParameter("@_username", SqlDbType::VarChar, 50));
        p = ps->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));
		p->Direction = ParameterDirection::Output;

		// create SqlCommand for sp_GetSessionParam and add its parameters
        _cmdGetSessionParam = gcnew SqlCommand("sp_GetSessionParam", _sqlConnection);
        _cmdGetSessionParam->CommandType = CommandType::StoredProcedure;
        p = _cmdGetSessionParam->Parameters->Add(gcnew SqlParameter("@_sessionid", SqlDbType::Int));
		p->Direction = ParameterDirection::Output;
        
		// create SqlCommand for sp_UpdateCustomer and add its parameters
        _cmdUpdateCustomer = gcnew SqlCommand("sp_UpdateCustomer", _sqlConnection);
		_cmdUpdateCustomer->CommandType = CommandType::StoredProcedure;
        ps = _cmdUpdateCustomer->Parameters;
        ps->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_firstname", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_lastname", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_address1", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_city", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_state", SqlDbType::VarChar, 2));
		ps->Add(gcnew SqlParameter("@_zip", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_email", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_phone", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_creditcard", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_creditcardexpiration", SqlDbType::VarChar, 4));
		ps->Add(gcnew SqlParameter("@_username", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_password", SqlDbType::VarChar, 50));

		// create SqlCommand for sp_PurchaseCartForSession2 and add its parameters
        _cmdPurchaseCartForSession2 = gcnew SqlCommand("sp_PurchaseCartForSession2", _sqlConnection);
        _cmdPurchaseCartForSession2->CommandType = CommandType::StoredProcedure;
        ps = _cmdPurchaseCartForSession2->Parameters;
        ps->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_sessionid",SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_netamount",SqlDbType::Money));
		ps->Add(gcnew SqlParameter("@_taxamount",SqlDbType::Money));
		ps->Add(gcnew SqlParameter("@_totalamount", SqlDbType::Money));

		// create SqlCommand for sp_PurchaseCartForSession2 and add its parameters
        _cmdGetUserDetails = gcnew SqlCommand("sp_GetUserDetails", _sqlConnection);
        _cmdGetUserDetails->CommandType = CommandType::StoredProcedure;
		_cmdGetUserDetails->Parameters->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));

		// create SqlCommand for sp_GetUserDetailsParam and add its parameters
        _cmdGetUserDetailsParam = gcnew SqlCommand("sp_GetUserDetailsParam", _sqlConnection);
        _cmdGetUserDetailsParam->CommandType = CommandType::StoredProcedure;
		ps = _cmdGetUserDetailsParam->Parameters;
        ps->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_firstname", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_lastname", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_address1", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_city", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_state", SqlDbType::VarChar, 2));
		ps->Add(gcnew SqlParameter("@_zip", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_email", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_phone", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_creditcard", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_creditcardexpiration", SqlDbType::VarChar, 4));
		ps->Add(gcnew SqlParameter("@_username", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_password", SqlDbType::VarChar, 50));
        for (int i = 1; i <= 12; i++) 
		{
			ps[i]->Direction = ParameterDirection::Output;			
        }

		// create SqlCommand for sp_AddCustomer2 and add its parameters
        _cmdAddCustomer2 = gcnew SqlCommand("sp_AddCustomer2", _sqlConnection);
        _cmdAddCustomer2->CommandType = CommandType::StoredProcedure;
        ps = _cmdAddCustomer2->Parameters;
        ps->Add(gcnew SqlParameter("@_firstname", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_lastname", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_address1", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_city", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_state", SqlDbType::VarChar, 2));
		ps->Add(gcnew SqlParameter("@_zip", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_email", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_phone", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_creditcard", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_creditcardexpiration", SqlDbType::VarChar, 4));
		ps->Add(gcnew SqlParameter("@_username", SqlDbType::VarChar, 50));
		ps->Add(gcnew SqlParameter("@_password", SqlDbType::VarChar, 50));
		p = ps->Add(gcnew SqlParameter("@_userid", SqlDbType::Int));
		p->Direction = ParameterDirection::Output;

		// create SqlCommand for sp_TestSearchByAuthorForward and add its parameters
        _cmdTestSearchByAuthorForward = gcnew SqlCommand("sp_TestSearchByAuthorForward", _sqlConnection); 
		_cmdTestSearchByAuthorForward->CommandType = CommandType::StoredProcedure;
		_cmdTestSearchByAuthorForward->Parameters->Add(gcnew SqlParameter("@_author", SqlDbType::VarChar, 50));

		// create SqlCommand for sp_SearchByExactSubject and add its parameters
        _cmdSearchByExactSubject = gcnew SqlCommand("sp_SearchByExactSubject", _sqlConnection); 
		_cmdSearchByExactSubject->CommandType = CommandType::StoredProcedure;
		_cmdSearchByExactSubject->Parameters->Add(gcnew SqlParameter("@_subjectid", SqlDbType::Int));

		// create SqlCommand for sp_TestSearchBySubjectForward and add its parameters
        _cmdTestSearchBySubjectForward = gcnew SqlCommand("sp_TestSearchBySubjectForward", _sqlConnection);
		_cmdTestSearchBySubjectForward->CommandType = CommandType::StoredProcedure;
		_cmdTestSearchBySubjectForward->Parameters->Add(gcnew SqlParameter("@_subjectname", SqlDbType::VarChar, 50));

		// create SqlCommand for sp_TestSearchByTitleForward and add its parameters
        _cmdTestSearchByTitleForward = gcnew SqlCommand("sp_TestSearchByTitleForward", _sqlConnection);
		_cmdTestSearchByTitleForward->CommandType = CommandType::StoredProcedure;
		_cmdTestSearchByTitleForward->Parameters->Add(gcnew SqlParameter("@_booktitle", SqlDbType::VarChar, 50));

		// create SqlCommand for sp_GetSpecials and add its parameters
        _cmdGetSpecials = gcnew SqlCommand("sp_GetSpecials", _sqlConnection);
		_cmdGetSpecials->CommandType = CommandType::StoredProcedure;

		// create SqlCommand for sp_AddToOrUpdateCart and add its parameters
        _cmdAddToOrUpdateCart = gcnew SqlCommand("sp_AddToOrUpdateCart", _sqlConnection);
		_cmdAddToOrUpdateCart->CommandType = CommandType::StoredProcedure;
		ps = _cmdAddToOrUpdateCart->Parameters;
        ps->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_productid", SqlDbType::Int));
        
		// create SqlCommand for sp_UpdateCart2 and add its parameters
        _cmdUpdateCart = gcnew SqlCommand("sp_UpdateCart2", _sqlConnection);                
		_cmdUpdateCart->CommandType = CommandType::StoredProcedure;
		ps = _cmdUpdateCart->Parameters;
        ps->Add(gcnew SqlParameter("@_itemid", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_quantity", SqlDbType::Int));
		ps->Add(gcnew SqlParameter("@_sessionid", SqlDbType::Int));

		// create SqlCommand for sp_ViewCart and add its parameters
        _cmdViewCart = gcnew SqlCommand("sp_ViewCart", _sqlConnection);
		_cmdViewCart->CommandType = CommandType::StoredProcedure;
		_cmdViewCart->Parameters->Add(gcnew SqlParameter("@_customerid", SqlDbType::Int));
    }
    catch(Exception^)
	{
		// get rid of our connection if anything goes wrong and re-throw the exception
        Disconnect();
        throw;
    }
}

void NileConnection::Disconnect()
{
    if (_sqlConnection) 
	{	
        _sqlConnection->Close();
        _sqlConnection = nullptr;
    }
}