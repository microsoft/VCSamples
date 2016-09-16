#include "stdafx.h"
#include "addtocart.h"

using namespace Nile;

AddToCart::AddToCart()
{
    this->Init += gcnew EventHandler(this, &Nile::AddToCart::Page_Init);
}

void AddToCart::Page_Init(Object^, EventArgs^)
{
    this->Load += gcnew EventHandler(this, &Nile::AddToCart::Page_Load);
}

void AddToCart::Page_Load(Object^, EventArgs^)
{ 
    // get our session id
    HttpCookie^ sessionCookie = Request->Cookies[SESSION_ID];
    
    if (!sessionCookie)
    {		
		// if we can't get a session id, tell the user to re-login and get out of here
		Response->Write("Your session has timed out, please re-login.");
		Response->End();

		return;		
    }
    int sessionID = Int32::Parse(sessionCookie->Value);

    NileWebService^ nileWebService = gcnew NileWebService();
                
    // get our book id
    int bookID = Int32::Parse(Request->QueryString->Get("id"));

    // call into our nile web service to add this book to the users shopping cart
    nileWebService->AddToOrUpdateCart(sessionID, bookID);
                
	// redirect to the cart page so the user can see what they purchased
	Response->Redirect(SHOPPING_CART);
}