#include "stdafx.h"
#using "NileWebService.dll"

namespace Nile
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Web;
	using namespace System::Web::Services;
	using namespace System::Web::UI;
	using namespace System::Web::UI::HtmlControls;
    	
    public ref class Checkout : public Page
    {	
    protected:
		// These objects are bound to controls on checkout.aspx.  The object name must match
		// the value of the id attribute in the .aspx file.  These objects will be instantiate
		// by ASP.NET automatically.

		HtmlGenericControl^  ShoppingCartPlaceHolder;
		HtmlGenericControl^  TotalsPlaceHolder;
		HtmlGenericControl^  CreditCardInfoPlaceHolder;		
		HtmlInputButton^	SubmitButton;

        NileWebService^ _nileWebService;
        int             _customerID;
        int             _sessionID;

    public:
        Checkout();

    protected:
        void Page_Init(Object^ sender, EventArgs^ args);		
		void Page_Load(Object^ sender, EventArgs^ args);		
    
        void Submit_Click(Object^ sender, EventArgs^ args);      
    };
}