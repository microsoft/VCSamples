#include "stdafx.h"

using namespace System;
using namespace System::Web;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Web::SessionState;

namespace ScribbleWS 
{

    /// <summary>
    ///    Summary description for Global.
    /// </summary>
	public ref class Global : public System::Web::HttpApplication
    {
	protected:
		void Application_Start(Object ^sender, EventArgs ^e)
        {

        }
 
		void Session_Start(Object ^sender, EventArgs ^e)
        {

        }

        void Application_BeginRequest(Object ^sender, EventArgs ^e)
        {

        }

		void Application_EndRequest(Object ^sender, EventArgs ^e)
        {

        }

        void Session_End(Object ^sender, EventArgs ^e)
        {

        }

        void Application_End(Object ^sender, EventArgs ^e)
        {

        }
    };
}

