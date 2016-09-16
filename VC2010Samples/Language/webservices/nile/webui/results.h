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
    
	// This enumerated type is used to indicate what category of books the user wants to
	// search on.
	enum ResultsCategoryEnum
    {
	   AuthorCat 		= 1,
	   TitleCat 		= 2,
	   SubjectCat 		= 3,
	   SpecialCat 		= 4,
	   SubjectNameCat 	= 5
    };

	// define the number of items per page that we'll show in our results
	#define	PAGE_SIZE 10

    public ref class Results : public Page
    {	
	protected:
		// These objects are bound to controls on results.aspx.  The object name must match
		// the value of the id attribute in the .aspx file.  These objects will be instantiate
		// by ASP.NET automatically.

		HtmlGenericControl^ NumResultsPlaceHolder;
	        HtmlGenericControl^ PreviousLinkPlaceHolder;
		HtmlGenericControl^ CurrentPagePlaceHolder; 
		HtmlGenericControl^ NumPagesPlaceHolder;
		HtmlGenericControl^ NextLinkPlaceHolder;
		HtmlGenericControl^ ResultsPlaceHolder;
		
		String^ _category;
	    String^ _criteria;
	    int		_page;

		array<BookData^>^ _results;
	public:
		Results();	

	protected:
		void Page_Init(Object^ sender, EventArgs^ receiver);		
		void Page_Load(Object^ sender, EventArgs^ receiver);		

		void ShowResults();

		bool ValidateParams();    
    };	
};