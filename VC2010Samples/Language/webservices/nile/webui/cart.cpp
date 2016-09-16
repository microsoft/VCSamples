#include "stdafx.h"
#include "cart.h"

using namespace Nile;
using namespace System::Text;

Cart::Cart()
{
    this->Init += gcnew EventHandler(this, &Nile::Cart::Page_Init);
}

void Cart::Page_Init(Object^, EventArgs^)
{
    this->Load += gcnew EventHandler(this, &Nile::Cart::Page_Load);

	CheckOutButton->ServerClick += gcnew EventHandler(this, &Nile::Cart::CheckOutButton_Click);
	ContinueShoppingButton->ServerClick += gcnew EventHandler(this, &Nile::Cart::ContinueShoppingButton_Click);		
}

void Cart::Page_Load(Object^, EventArgs^)
{
	// instantiate a reference to our nile web service
	_nileWebService = gcnew NileWebService();
        
    // check to see if we have a sessionID
    HttpCookie^ sessionCookie = Request->Cookies[SESSION_ID];

    if (!sessionCookie)
    {				
		// if we can't get a session id, tell the user to re-login and get out of here
		Response->Write("Your session has timed out, please re-login.");
		Response->End();

		return;
    }

    // get our session id
	_sessionID = Int32::Parse(sessionCookie->Value);                   

	// get the contents of our shopping cart
	array<ShoppingCartItem^>^ cartItems;
	if (!_nileWebService->ViewCart(_sessionID, cartItems))
	{
		// If we can't get the shopping cart, there isn't much we can do.  Output an error
		// message and return.

		Response->Write("Error, could not access shopping cart.  Sorry about the inconvenience, please re-login");
		Response->End();

		return;
	}

	// if there is nothing in the user's shopping cart, just redirect to a friendly message
	if (!cartItems)
	{
        Response->Redirect(EMPTY_CART);
		
		return;
	}

	// show the contents of our shopping cart
	StringBuilder^ cartHtml = gcnew StringBuilder();
	int numCartItems = cartItems->Length;

	for (int i = 0; i < numCartItems; i ++)
	{		
		ShoppingCartItem^ shoppingCartItem = cartItems[i];
		String^ quantity = shoppingCartItem->Quantity.ToString();

		cartHtml->Append(String::Format("<tr><td><input name=quantity value=\"{0}\" type=text size=4></td>", quantity));
		cartHtml->Append(String::Format("<td><u><b>{0}</b></u><br>{1},${2}</td>", shoppingCartItem->BookData->Title, shoppingCartItem->BookData->Author, shoppingCartItem->BookData->Price));
		cartHtml->Append(String::Format("<td><input id=\"itemid\" name=\"itemid\" value=\"{0}\" type=\"hidden\"></td>", shoppingCartItem->BookData->BookId));
		cartHtml->Append(String::Format("<td><input id=\"origqty\" name=\"origqty\" value=\"{0}\" type=\"hidden\"></td></tr>", quantity));
	}

	CartItemsPlaceHolder->InnerHtml = cartHtml->ToString();
}

void Cart::CheckOutButton_Click(Object^, EventArgs^)
{	
	// The user may have changed the quantities of the items they purchased.  UpdateQuantity()
	// makes any updates that are necessary.	 
	UpdateQuantity();
	
	// redirect to check out page for the user to checkout
	Response->Redirect(CHECKOUT);
}

void Cart::ContinueShoppingButton_Click(Object^, EventArgs^)
{
	// The user may have changed the quantities of the items they purchased.  UpdateQuantity()
	// makes any updates that are necessary.	 
	UpdateQuantity();
	
	// redirect to main page for the user to continue shopping
	Response->Redirect(NILE_NOFRAME);
}

void Cart::UpdateQuantity()
{
	// For each book the customer has purchased, we are interested in 3 pieces of data; the
	// book id, the original quantity, and a new quantity.  The new quantity will only be different
	// from the original quantity if the user changed it.  This information is stored in 3 separate
	// arrays of strings.
		
	// Get all the ID's of all the books the user bought.  ASP.NET deals with multiple values in 
	// a query string with the same name by returning them in an array.  		
	array<String^>^ items = Request->Form->GetValues("itemid");
	
	// if the user didn't buy anything we can return now
	if (items == nullptr)
		return;

	// get all of the 'new' quanitities
	array<String^>^ quantities = Request->Form->GetValues("quantity");

	// get all of the original quantities
	array<String^>^ origqtys = Request->Form->GetValues("origqty");        
    
	// No need to do any error checking on these arrays since the user can only change
	// values in them, not affect their structure

	// For each of the items the customer bought, compare the original quantity with the
	// new quantity.  If this value has changed, call into our nile web service to update this
	// in their shopping cart
    int numItems = items->Length;
	for (int i = 0; i < numItems; i++)
	{		
		// need to trim the values in the quantities array because they have trailing blanks
		// when these values come from the DB
		if (String::Compare(quantities[i]->Trim(), origqtys[i]) != 0)
		{
			// If we get here, then the quantity value has changed.  We need to get the book
			// ID and call into our nile web service to update the quantity.
			_nileWebService->UpdateCart(Int32::Parse(items[i]), Int32::Parse(quantities[i]), _sessionID);
        }
	}
}
