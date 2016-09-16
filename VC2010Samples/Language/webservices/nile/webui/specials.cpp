#include "stdafx.h"
#include "specials.h"

using namespace System::Text;
using namespace System::Collections;
using namespace Nile;

Specials::Specials()
{
	this->Init += gcnew EventHandler(this, &Nile::Specials::Page_Init);	
}

void Specials::Page_Init(Object^, EventArgs^ )
{		
	// instantiate a reference to our nile web service
	NileWebService^ nileWebService = gcnew NileWebService();
	
	// use a string builder to create a stream of HTML
	StringBuilder^ html = gcnew StringBuilder();

	// get a list of specials from the nile web service
	array<SpecialData^>^ results;
	if (nileWebService->ListBySpecials(results))
    {
		// build an HTML list of specials
		int numResults = results->Length;
		for(int i = 0; i < numResults; i++)
		{
			SpecialData^ ss = results[i];
			html->Append(String::Format("<li><b>{0}</b><br>by {1} <br><br>", ss->Title, ss->Author));
		}
	}
    else
    {
		// not a fatal error if we couldn't get specials, just output an error message
        html->Append("<li>Could not get specials"); 
	}
	SpecialsPlaceHolder->InnerHtml = html->ToString();	
}