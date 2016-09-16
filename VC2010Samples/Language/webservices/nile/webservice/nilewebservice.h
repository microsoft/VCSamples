#pragma once

#include "nileconnection.h"
#include "stdafx.h"

using namespace System::Runtime::InteropServices;

namespace Nile
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Web;
	using namespace System::Web::Services;
	using namespace System::Web::Services::Protocols;
	using namespace System::Xml::Serialization;
    
	public ref struct BookData
	{	
	        String^ BookId;
	        String^ Title;
	        String^ Author;
	        String^ Price;
	        String^ Retail;
	        String^ Save;    
	};

	public ref struct SpecialData
	{		
		String^ Author;
		String^ Title;
	};

	public ref struct ShoppingCartItem
	{
		BookData^ BookData;
		int       Quantity;
	};

	public ref class NileWebService : public WebService
	{
	protected:
		NileConnection^ _nileConnection;
		
	public:
	
		NileWebService();

		// need ref for our output parameters
		[WebMethod]
        bool VerifyUser(String^     userID,
                        String^     password,
                        [Out] Int32%	customerID,
                        [Out] Int32%	sessionID);

		[WebMethod]
        bool UpdateAccount(int	   customerId,
                           String^ firstName,
                           String^ lastName,
						   String^ email,
						   String^ phone,
						   String^ userName,
						   String^ password,
						   String^ address1,
						   String^ city,
						   String^ state,
						   String^ zip,
						   String^ creditCard,
						   String^ creditCardExpiration);

		[WebMethod]
        bool PlaceOrder(int      customerId,
						int      sessionId,
                        Decimal  netAmount);
    
		[WebMethod]
		bool GetAccountInfo(int      customerId,
							String^ firstName,
							String^ lastName,
							String^ email,
							String^ phone,
							String^ userName,
							String^ password,
							String^ address1,
							String^ city,
							String^ state,
							String^ zip,
							String^ creditCard,
							String^ creditCardExpiration);
    
		[WebMethod]
        bool CreateAccount(String^   firstName,
						   String^   lastName,
						   String^   email,
						   String^   phone,
						   String^   userName,
						   String^   password,
						   String^   address1,
					  	   String^   city,
						   String^   state,
						   String^   zip,
						   String^   creditCard,
						   String^   creditCardExpiration,
                           [Out] Int32% customerId,
                           [Out] Int32% sessionId);

        [WebMethod]
        bool AddToOrUpdateCart(int sessionId, int productId);

		[WebMethod]
        bool UpdateCart(int itemID, int quantity, int sessionID);
				
		[WebMethod]
        bool ViewCart(int sessionId, array<ShoppingCartItem^>^ items);

		[WebMethod]
        bool ListByAuthor(String^ author, array<BookData^>^ results);

		[WebMethod]
        bool ListBySubject(int subjectId, array<BookData^>^ results);

		[WebMethod]
		bool ListBySubjectName(String^ subjectName, array<BookData^>^ results);

		[WebMethod]
		bool ListByTitle(String^ title, array<BookData^>^ results);

		[WebMethod]
		bool ListBySpecials(array<SpecialData^>^ specials);
		
	protected:		
		bool GetBookDataListFromCmd(SqlCommand^ cmd, array<BookData^>^ bookDataList);		
    };
}