#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Web.dll>
#using <System.Web.Services.dll>
#using <System.EnterpriseServices.dll>
#using <System.Xml.dll>

// TODO change this connection string to match your database setup
#define CONNECTION_STRING "Data Source=daqa_ss80;Initial Catalog=Nile;User ID=sa;Password="

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