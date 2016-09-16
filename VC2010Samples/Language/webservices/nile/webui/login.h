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
    
    public ref class Login : public Page
    {
    public:
        Login();

    protected:
        void Page_Init(Object^ sender, EventArgs^ receiver);		
		void Page_Load(Object^ sender, EventArgs^ receiver);		
    };
}