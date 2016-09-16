#include "stdafx.h"
#include "checkout.h"

using namespace System::Text;
using namespace Nile;

Checkout::Checkout()
{
    this->Init += gcnew EventHandler(this, &Nile::Checkout::Page_Init);
}

void Checkout::Page_Init(Object^, EventArgs^)
{
    this->Load += gcnew EventHandler(this, &Nile::Checkout::Page_Load);
	SubmitButton->ServerClick += gcnew EventHandler(this, &Nile::Checkout::Submit_Click);
}

void Checkout::Page_Load(Object^, EventArgs^)
{
    HttpCookie^ sessionCookie = Request->Cookies[SESSION_ID];
    HttpCookie^ customerCookie = Request->Cookies[CUSTOMER_ID];
        
    if ((sessionCookie == nullptr) || (customerCookie == nullptr))
    {
        Response->Write(SESSION_EXPIRED);
        Response->End();
        return;
    }    

    _sessionID = Int32::Parse(sessionCookie->Value);
    _customerID = Int32::Parse(customerCookie->Value);

    _nileWebService = gcnew NileWebService();    

    // show the contents of our shopping cart	
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

	// create a stream of HTML for our shopping cart items
	StringBuilder^ cartHtml = gcnew StringBuilder();
	int numCartItems = cartItems->Length;
	Decimal netAmount = (Decimal)0.0;

	for (int i = 0; i < numCartItems; i ++)
	{		
		ShoppingCartItem^ shoppingCartItem = cartItems[i];
						
		cartHtml->Append(String::Format("<TR><TD>{0}</TD>", shoppingCartItem->BookData->Title));
		cartHtml->Append(String::Format("<TD style=\"width:10%;\" align=\"Right\">{0}</TD>", shoppingCartItem->Quantity.ToString()));
		cartHtml->Append(String::Format("<TD style=\"width:10%;\" align=\"Right\">${0}</TD></TR>", shoppingCartItem->BookData->Price));
	
		// keep a running total of the shopping cart items
		netAmount = Decimal::Add(netAmount, Decimal::Multiply(shoppingCartItem->Quantity, Decimal::Parse(shoppingCartItem->BookData->Price)));
	}	
	// show our shopping cart
	ShoppingCartPlaceHolder->InnerHtml = cartHtml->ToString();

	// create a stream of HTML for the total
	StringBuilder^ totalsHtml = gcnew StringBuilder();

	totalsHtml->Append("<TR><TD colspan=3><HR></TD></TR>");
	totalsHtml->Append("<TR><TD colspan=2><B>Subtotal:</B></TD>");
	totalsHtml->Append(String::Format("<TD align=right>${0}</TD></TR>", String::Format("{0:C}", netAmount.ToString())));
	totalsHtml->Append("<TR><TD colspan=2><B>Tax (5%):</B></TD>");
	totalsHtml->Append(String::Format("<TD align=right>${0}</TD></TR>", String::Format("{0:C}", Decimal::Multiply((Decimal)0.05, netAmount).ToString())));
	totalsHtml->Append("<TR><TD colspan=2><B>Total:</B></TD>");

	// show our net amount and store it in a hidden field
	String^ netAmountStr = String::Format("{0:C}", Decimal::Multiply((Decimal)1.05, netAmount).ToString());
	totalsHtml->Append(String::Format("<TD align=right>${0}</TD></TR>", netAmountStr));

	// we'll need this value when we submit the order
	totalsHtml->Append(String::Format("<input type=\"hidden\" name=\"NetAmount\" value=\"{0}\"/>", netAmountStr));
	
	// show our totals table
	TotalsPlaceHolder->InnerHtml = totalsHtml->ToString();

	// create a stream of HTML for our customers credit card information
	StringBuilder^ creditCardHtml = gcnew StringBuilder();

	// get the customer's credit card information
	String^ firstName;
	String^ lastName;
	String^ email;
	String^ phone;
	String^ userName;
	String^ password;
	String^ address1;
	String^ city;
	String^ state;
	String^ zip;
	String^ creditCard;
	String^ creditCardExpiration;

	if (!_nileWebService->GetAccountInfo(_customerID,
										firstName,
										lastName,
										email,
										phone,
										userName,
										password,
										address1,
										city,
										state,
										zip,
										creditCard,
										creditCardExpiration))
	{
		// Not being able to get the customer's credit card information isn't a fatal error.  
		// Just show and error message.
		creditCardHtml->Append("<TR><TD>Could not get credit card information</TD></TR>");
	}
	else
	{
		creditCardHtml->Append(String::Format("<table border=\"0\"><TR><TD align=right><B>Name:</B></TD><TD>{0} {1}</TD>", firstName, lastName));
		creditCardHtml->Append(String::Format("<TR><TD align=right><B>Credit Card:</B></TD><TD>{0}</TD>", creditCard));
		creditCardHtml->Append(String::Format("<TR><TD align=right><B>Credit Card<BR>Expiration:</B></TD><TD valign=top>{0}</TD></TR></table>", creditCardExpiration));
	
		creditCardHtml->Append("<table cellpadding=\"2\" cellspacing=\"2\" width=\"100%\" border=\"2\" align=\"center\"><tr>");
		creditCardHtml->Append("<td colspan=\"2\" align=\"center\"><font color=\"#000000\"><font size=\"3\">Billing Info</font></font></td></tr></table>");
		
		creditCardHtml->Append(String::Format("<table border=\"0\"><TR><TD align=right><B>Name:</B></TD><TD>{0} {1}</TD>", firstName, lastName));
		creditCardHtml->Append(String::Format("<TR><TD align=right><B>Addres:</B></TD><TD valign=top>{0}</TD>", address1));
		creditCardHtml->Append(String::Format("<TD>{0},{1},{2}</TD></TR></table>", city, state, zip));		
	}
	CreditCardInfoPlaceHolder->InnerHtml = creditCardHtml->ToString();
}
   
void Checkout::Submit_Click(Object^, EventArgs^)
{	
	if (!_nileWebService->PlaceOrder(_customerID, _sessionID, Decimal::Parse(Request->Form["NetAmount"])))
	{
		// nothing we can really do if there is an error at this stage
		Response->Write("Sorry, we could not process your order!");
		Response->End();

		return;
	}
       
    // this finishes the user's buy, direct them to a generic thank you page
	Response->Redirect(THANK_YOU);
}
