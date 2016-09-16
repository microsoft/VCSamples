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
    	
    public ref class AddToCart : public Page
    {
    public:
        AddToCart();

    protected:
        void Page_Init(Object^ sender, EventArgs^ args);
        void Page_Load(Object^ sender, EventArgs^ args);
    };
}