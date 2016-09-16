#include "stdafx.h"
#include "login.h"

using namespace Nile;

Login::Login()
{
	this->Init += gcnew EventHandler(this, &Nile::Login::Page_Init);		
}

void Login::Page_Init(Object^, EventArgs^)
{
	this->Load += gcnew EventHandler(this, &Nile::Login::Page_Load);
}

void Login::Page_Load(Object^, EventArgs^)
{   
    // instantiate a reference to our web service
    NileWebService^ nileWebService = gcnew NileWebService();
    
    // try to verify the user
    int customerID = 0;
    int sessionID = 0;

    // call into our web service to verify the user    
    if (!nileWebService->VerifyUser(Request->QueryString->Get("UserNameField"), 
                                    Request->QueryString->Get("PasswordField"), 
                                    customerID, 
                                    sessionID))
    {        
		// if the user does not exist, redirect to account.aspx so the user can 
        // create a new account
        Response->Redirect(ACCOUNT);
    }    
    else
    {
        // otherwise, store our customer session id in cookies
        HttpCookie^ customerCookie = gcnew HttpCookie(CUSTOMER_ID, customerID.ToString());
        HttpCookie^ sessionCookie = gcnew HttpCookie(SESSION_ID, sessionID.ToString());

        Response->Cookies->Add(customerCookie);
        Response->Cookies->Add(sessionCookie);

        // redirect to the main page so our customer can start shopping
	    Response->Redirect(NILE_FRAME);    
    }
}
