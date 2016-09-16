#include "stdafx.h"
#using "NileWebService.dll"

namespace Nile
{
	using namespace System;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Web;
	using namespace System::Web::Services;
	using namespace System::Web::UI;
	using namespace System::Web::UI::HtmlControls;
    	
    public ref class Account : public Page
    {
    public:
        // These objects are bound to controls on account.aspx.  The object name must match
		// the value of the id attribute in the .aspx file.  These objects will be instantiate
		// by ASP.NET automatically.

        HtmlInputText	^FirstNameField;
        HtmlInputText	^LastNameField;
        HtmlInputText	^AddressField;
        HtmlInputText	^CityField;
	    HtmlInputText	^StateField;
	    HtmlInputText	^ZipField;
	    HtmlInputText	^EmailField;
	    HtmlInputText	^PhoneField;
	    HtmlInputText	^CreditField;
	    HtmlInputText	^DateField;
	    HtmlInputText	^UserField;
	    HtmlInputText	^PasswordField;
		HtmlInputButton	^SubmitButton;

    protected:
        int _customerID;
        NileWebService ^_nileWebService;

	public:
		Account();
		
    protected:
		void Page_Init(Object^ sender, EventArgs^ args);
		void Submit_Click(Object^ sender, EventArgs^ args);
        void Page_Load(Object^ sender, EventArgs ^args);

		void CreateAccount();
		void UpdateAccount();
    };
}