#include "stdafx.h"

namespace Nile
{
	using namespace System;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	
	public ref class NileConnection
	{
	internal:      
			String^             _connectionString;
			SqlConnection^      _sqlConnection;
			SqlCommand^         _cmdGetUserParam;
			SqlCommand^         _cmdGetSessionParam;
			SqlCommand^         _cmdUpdateCustomer;
			SqlCommand^         _cmdPurchaseCartForSession2;
			SqlCommand^         _cmdGetUserDetails;
			SqlCommand^         _cmdGetUserDetailsParam;
			SqlCommand^         _cmdAddCustomer2;
			SqlCommand^         _cmdTestSearchByAuthorForward;
			SqlCommand^         _cmdSearchByExactSubject;
			SqlCommand^         _cmdTestSearchBySubjectForward;
			SqlCommand^         _cmdTestSearchByTitleForward;
			SqlCommand^         _cmdGetSpecials;
			SqlCommand^         _cmdAddToOrUpdateCart;
			SqlCommand^         _cmdUpdateCart;
			SqlCommand^         _cmdViewCart;
	public:
			NileConnection(String^ connection);
	internal:
			void EnsureConnection();
			void Disconnect();
	};
}