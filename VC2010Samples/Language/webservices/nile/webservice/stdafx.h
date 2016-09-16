#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Web.dll>
#using <System.Web.Services.dll>
#using <System.EnterpriseServices.dll>
#using <System.Transactions.dll>
#using <System.Xml.dll>

// TODO change this connection string to match your database setup
//#error TODO set CONNECTION_STRING to a OLEDB connection string that matches your SQL Server installation.  Please see the documentation for details.
//
// For example: "Data Source=localhost;Initial Catalog=nile;Persist Security Info=True;User ID=foo;Password=foo;Connect Timeout=1000"
#define CONNECTION_STRING "Some string"

// Managed extensions for C++ doesn't define a null
#define null 0

// These are the names of cookies that are used by various pages.  Keep them defined
// here so it'll be easy to change them if necessary
#define SESSION_ID	"sessionID"
#define CUSTOMER_ID	"customerID"

// These are pages that other pages re-direct to
#define LOGIN				"login.htm"
#define NILE_FRAME			"nile.htm"
#define NILE_NOFRAME		"main.htm"
#define SHOPPING_CART		"cart.aspx"
#define THANK_YOU			"thankyou.htm"
#define ACCOUNT				"account.aspx"
#define CHECKOUT			"checkout.aspx"
#define EMPTY_CART          "emptycart.htm"

// Message
#define NO_SHOPPING_CART_ITEMS	"There are no items in your shopping cart."
#define SESSION_EXPIRED			"Your session has expired, please re-login."