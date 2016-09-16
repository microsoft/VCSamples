#include "stdafx.h"
#include "account.h"

using namespace Nile;

Account::Account()
{
	_customerID = -1;	
	_nileWebService = gcnew NileWebService();

	this->Init += gcnew EventHandler(this, &Nile::Account::Page_Init);	
}

void Account::Page_Init(Object^, EventArgs^)
{
	SubmitButton->ServerClick += gcnew EventHandler(this, &Nile::Account::Submit_Click);
	this->Load += gcnew EventHandler(this, &Nile::Account::Page_Load);
}

void Account::Submit_Click(Object^, EventArgs^)
{
	if (_customerID == -1)
	{		
		CreateAccount();
	}	
	else
	{
		UpdateAccount();
	}
}

void Account::Page_Load(Object^, EventArgs^)
{
    
    
	// Check to see if we have a customer id cookie.  If we do, then we can 
	// get the customer id from that cookie.  The customer id will be used to 
	// retrieve that customer's account information.  If we don't have a
	// customer cookie then return immediately.  The fields in account.aspx 
	// will stay blank, which the customer can fill in to create their account.
    
    HttpCookie^ customerCookie = Request->Cookies[CUSTOMER_ID];    
	if (!customerCookie)
	{
		return;
	}
	
	// get a customer id from the cookie
	_customerID = Int32::Parse(customerCookie->Value);
	
	// Only display our customer data if we have not been posted to.  IsPostBack will
	// be true when account.aspx is submitted.  This would happen in the submit button 
	// on that page is clicked.  We don't want to re-display our data if we have been
	// posted to.
	
    if (!IsPostBack)
	{
		// get the customer id
		_customerID = Int32::Parse(customerCookie->Value);
	
        // show the customer's information
        String^ fname;
		String^ lname;
        String^ email;
		String^ phone;
		String^ user;
		String^ password;
		String^ address;
		String^ city;
		String^ state;
		String^ zip;
		String^ credit;
		String^ date;

		if (_nileWebService->GetAccountInfo(_customerID,
											fname,
		                      				lname,
                                  			email,
                                  			phone,
                                   			user,
                                  			password,
                                  			address,
                                  			city,
                                  			state,
                                  			zip,
                                  			credit,
                      			            date))
		{
				FirstNameField->Value = fname;
				LastNameField->Value  = lname;
				AddressField->Value   = address;
				CityField->Value      = city;
				StateField->Value     = state;
				ZipField->Value       = zip;
				EmailField->Value     = email;
				PhoneField->Value     = phone;
				CreditField->Value    = credit;
				DateField->Value      = date;	
				UserField->Value      = user;
				PasswordField->Value  = password;		
		}		
	}	
}

void Account::UpdateAccount()
{
	// make sure we don't put nulls in the database
	String^ fname		= (FirstNameField->Value == nullptr)	? " " : FirstNameField->Value;
	String^ lname		= (LastNameField->Value == nullptr)	? " " : LastNameField->Value;
	String^ email		= (EmailField->Value == nullptr)		? " " : EmailField->Value;
	String^ phone		= (PhoneField->Value == nullptr)		? " " : PhoneField->Value;
	String^ user		= (UserField->Value == nullptr)		? " " : UserField->Value;
	String^ password	= (PasswordField->Value == nullptr)	? " " : PasswordField->Value;
	String^ address		= (AddressField->Value == nullptr)		? " " : AddressField->Value;
	String^ city		= (CityField->Value == nullptr)		? " " : CityField->Value;
	String^ state		= (StateField->Value == nullptr)		? " " : StateField->Value;
	String^ zip			= (ZipField->Value == nullptr)			? "0" : ZipField->Value;
	String^ credit		= (CreditField->Value == nullptr)		? " " : CreditField->Value;
	String^ date		= (DateField->Value == nullptr)		? " " : DateField->Value;

	// update our account
	_nileWebService->UpdateAccount(	_customerID,
									fname,
									lname,
		 							email,
		 							phone,
									user,
	 								password,
    	 							address,
    	 							city,
    	 							state,
    	 							zip,
    	 							credit,
    	 							date);	
	// redirect to the main page
	Response->Redirect(NILE_NOFRAME);
}

void Account::CreateAccount()
{
	// make sure we don't put nulls in the database
	String^ fname		= (FirstNameField->Value == nullptr)	? " " : FirstNameField->Value;
	String^ lname		= (LastNameField->Value == nullptr)	? " " : LastNameField->Value;
	String^ email		= (EmailField->Value == nullptr)		? " " : EmailField->Value;
	String^ phone		= (PhoneField->Value == nullptr)		? " " : PhoneField->Value;
	String^ user		= (UserField->Value == nullptr)		? " " : UserField->Value;
	String^ password	= (PasswordField->Value == nullptr)	? " " : PasswordField->Value;
	String^ address		= (AddressField->Value == nullptr)		? " " : AddressField->Value;
	String^ city		= (CityField->Value == nullptr)		? " " : CityField->Value;
	String^ state		= (StateField->Value == nullptr)		? " " : StateField->Value;
	String^ zip			= (ZipField->Value == nullptr)			? "0" : ZipField->Value;
	String^ credit		= (CreditField->Value == nullptr)		? " " : CreditField->Value;
	String^ date		= (DateField->Value == nullptr)		? " " : DateField->Value;

	int sessionID = -1;
	if (_nileWebService->CreateAccount( fname,
										lname,
		 								email,
				 						phone,
										user,
	 									password,
    	 			 					address,
    	 								city,
    	 								state,
    	 								zip,
    	 				 				credit,
    	 								date,
					 					_customerID,
					 					sessionID))
	{
		// store our customer session id in cookies
		HttpCookie^ customerCookie = gcnew HttpCookie(CUSTOMER_ID, _customerID.ToString());
		HttpCookie^ sessionCookie = gcnew HttpCookie(SESSION_ID, sessionID.ToString());

		Response->Cookies->Add(customerCookie);
		Response->Cookies->Add(sessionCookie);

		// redirect to the main page
		Response->Redirect(NILE_FRAME);
	}
	else
	{		
		// Something went wrong, we could not create the user's account, redirect back to the
		// login page.
		Response->Redirect(LOGIN);
	}
}