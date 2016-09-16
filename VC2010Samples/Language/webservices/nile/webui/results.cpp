#include "stdafx.h"
#include "results.h"

using namespace Nile;
using namespace System::Text;

Results::Results()
{
	this->Init += gcnew EventHandler(this, &Nile::Results::Page_Init);	
}

void Results::Page_Init(Object^, EventArgs^)
{
	this->Load += gcnew EventHandler(this, &Nile::Results::Page_Load);
}

void Results::Page_Load(Object^, EventArgs^)
{
	// make sure we have valid parameters
	if (!ValidateParams())
	{
		// nothing we can do if we don't have valid parmeters
		Response->Write("Wrong parameters specified");
		Response->End();		

		return;
	}

	// instantiate a reference to our nile web service
	NileWebService^ nileWebService = gcnew NileWebService();

	// based on the category the customer is interested in, call into our nile web service
	// to search for matches
	bool retVal = false;
	ResultsCategoryEnum category = (ResultsCategoryEnum)Int32::Parse(_category);

	switch(category)
	{                
		case AuthorCat:
        {
            retVal = nileWebService->ListByAuthor(_criteria, _results);
            break;
        }
        case TitleCat:
        {        
            retVal = nileWebService->ListByTitle(_criteria, _results);
            break;
        }
        case SubjectCat:
        {            
            retVal = nileWebService->ListBySubject(Int32::Parse(_criteria), _results);
            break;
        }                
        case SubjectNameCat:
        {        
            retVal = nileWebService->ListBySubjectName(_criteria, _results);
            break;
        }
    }

    if (!retVal)
    {
		// Any empty search is not an error, so getting here indicates that something
		// serious went wrong.  We can recover, so just output an error message and 
		// return.
        Response->Write("Error, could not perform search");
        Response->End();

		return;
    }
	
	// show our results
	ShowResults();
}

void Results::ShowResults()
{
	// get the number of results that we have
	int numResults = _results->Length;

	// show the number of results that we have
	NumResultsPlaceHolder->InnerHtml = numResults.ToString();	

	// we don't need to do anything else if we don't have any results
	if (numResults == 0)
		return;

	// based on the number of results, calculate how many pages of results we have; remember to 
	// to round up
	int numPages = (int)Decimal::Add((Decimal)numResults / (Decimal)PAGE_SIZE, (Decimal)0.9);

	// show our current page
	CurrentPagePlaceHolder->InnerHtml = _page.ToString();

	// show the number of pages that we have
	NumPagesPlaceHolder->InnerHtml = numPages.ToString();

	// show previous and next links if we have multiple results
	int prevPage = _page - 1;
	int nextPage = _page + 1;

	if (prevPage > 0)
	{		
		PreviousLinkPlaceHolder->InnerHtml = String::Format("<A HREF=\"results.aspx?category={0}&criteria={1}&page={2}\">Previous</A>", _category, _criteria, prevPage.ToString());
	}

	if (nextPage <= numPages)
	{
		NextLinkPlaceHolder->InnerHtml = String::Format("<A HREF=\"results.aspx?category={0}&criteria={1}&page={2}\">Next</A>", _category, _criteria, nextPage.ToString());
	}	

	// show our results
	StringBuilder^ resultsHtml = gcnew StringBuilder();
	for (int i = 0; i < numResults; i++)
	{
		BookData^ bd = _results[i];
		resultsHtml->Append("<TR><TD align=\"CENTER\" rowspan=\"2\"><FONT size=\"2\">");
		resultsHtml->Append(String::Format("<A href=\"AddToCart.aspx?id={0}\">Add to<BR>Shopping<BR>Cart</A></FONT></TD>", bd->BookId));
		resultsHtml->Append(String::Format("<TD>{0}</TD>", bd->Title));
		resultsHtml->Append(String::Format("<TD>{0}</TD></TR>", bd->Author));
		resultsHtml->Append("<TR><TD COLSPAN=\"2\"><B>");
		resultsHtml->Append(String::Format("<FONT color=\"#000000\">Your price: </FONT></B><FONT color=\"#ff0009\"><B>${0}</B></FONT>", bd->Price));
		resultsHtml->Append(String::Format(" - <FONT color=\"#000b91\">You save ${0} </FONT>!", bd->Save));
		resultsHtml->Append(String::Format("&nbsp; (Suggested retail price: ${0})&nbsp;</TD>", bd->Retail));
		resultsHtml->Append("</TR><TR><TD colspan=\"3\" height=\"12\"></TD></TR>");
	}

	ResultsPlaceHolder->InnerHtml = resultsHtml->ToString();
}

bool Results::ValidateParams()
{	
	_category = Request->QueryString->Get("category");
	_criteria = Request->QueryString->Get("criteria");
	
	String^ tempPage = Request->QueryString->Get("page");
	if (!tempPage)
		_page = 1;
	else
		_page = Int32::Parse(tempPage);

	// this case implies we've come from search.htm
	// otherwise, we came from the browse.htm page
	if ((_category == nullptr) && (_criteria == nullptr))
	{
		// get the author, title and subject; these values were
		// submitted from the search form
		String^ author, ^ title, ^ subject;

		author	= Request->Form->Get("AuthorField");
		title	= Request->Form->Get("TitleField");
		subject = Request->Form->Get("SubjectField");

		if (!author->Equals(""))
		{
			_category = "1";
			_criteria = author;
		}
		else if (!title->Equals(""))
		{
			_category = "2";
			_criteria = title;
		}
		else if (subject->Equals(""))
		{
			_category = "5";
			_criteria = subject;
		}
		else
		{
			// we are in an invalid state, get out of here
			return false;
		}
	}
			
	return true;    
}
