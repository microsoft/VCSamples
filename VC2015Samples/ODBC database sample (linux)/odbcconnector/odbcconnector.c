#include <stdio.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>

#define RESULT_LEN  256

#define CHECK_ERROR(e, s, h, t) ({\
            if (e!=SQL_SUCCESS && e != SQL_SUCCESS_WITH_INFO) {extract_error(s, h, t); goto exit;} \
})
void extract_error(char *fn, SQLHANDLE handle, SQLSMALLINT type)
{
	SQLINTEGER i = 0;
	SQLINTEGER NativeError;
	SQLCHAR SQLState[7];
	SQLCHAR MessageText[256];
	SQLSMALLINT TextLength;
	SQLRETURN ret;

	fprintf(stderr, "\nThe driver reported the following error %s\n", fn);
	do
	{
		ret = SQLGetDiagRec(type, handle, ++i, SQLState, &NativeError,
			MessageText, sizeof(MessageText), &TextLength);
		if (SQL_SUCCEEDED(ret)) {
			printf("%s:%ld:%ld:%s\n",
				SQLState, (long)i, (long)NativeError, MessageText);
		}
	} while (ret == SQL_SUCCESS);
}
int main() {

	SQLHENV   henv = SQL_NULL_HENV;   // Environment
	SQLHDBC   hdbc = SQL_NULL_HDBC;   // Connection handle
	SQLHSTMT  hstmt = SQL_NULL_HSTMT;  // Statement handle
	SQLRETURN retcode;
	SQLCHAR strResult[RESULT_LEN];
	SQLCHAR outstr[1024];
	SQLSMALLINT outstrlen;
	int i = 0;
	// Allocate environment handle
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_ENV)",
		henv, SQL_HANDLE_ENV);
	// Set the ODBC version environment attribute
	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
		(SQLPOINTER*)SQL_OV_ODBC3, 0);
	CHECK_ERROR(retcode, "SQLSetEnvAttr(SQL_ATTR_ODBC_VERSION)",
		henv, SQL_HANDLE_ENV);

	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
		(SQLPOINTER*)SQL_OV_ODBC3, 0);
	CHECK_ERROR(retcode, "SQLSetEnvAttr(SQL_ATTR_ODBC_VERSION)",
		henv, SQL_HANDLE_ENV);
	// Allocate connection handle
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_DBC)",
		hdbc, SQL_HANDLE_DBC);
	// Set login timeout to 5 seconds
	SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);
	CHECK_ERROR(retcode, "SQLSetConnectAttr(SQL_LOGIN_TIMEOUT)",
		hdbc, SQL_HANDLE_DBC);
	// Connect to data source, replace with your connection string
	retcode = SQLDriverConnect(hdbc, NULL, "<replace-with-your-connection-string>", SQL_NTS, outstr, sizeof(outstr), &outstrlen, SQL_DRIVER_NOPROMPT);
	// Allocate statement handle
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_STMT)",
		hstmt, SQL_HANDLE_STMT);
	retcode = SQLExecDirect(hstmt,
		(SQLCHAR*) "SELECT DB_NAME()", SQL_NTS);
	CHECK_ERROR(retcode, "SQLExecDirect()", hstmt, SQL_HANDLE_STMT);

	// Bind columns

	retcode = SQLBindCol(hstmt, 1, SQL_C_CHAR, &strResult, RESULT_LEN, 0);


	// Fetch and print each row of data until SQL_NO_DATA returned.
	for (i = 0; ; i++) {
		retcode = SQLFetch(hstmt);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
			printf("Result is: %s", strResult);
		}
		else {
			if (retcode != SQL_NO_DATA) {
				CHECK_ERROR(retcode, "SQLFetch()", hstmt, SQL_HANDLE_STMT);
			}
			else {
				break;
			}
		}
	}

exit:
	printf("\nComplete.\n");
	// Free handles
	// Statement
	if (hstmt != SQL_NULL_HSTMT)
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	// Connection
	if (hdbc != SQL_NULL_HDBC) {
		SQLDisconnect(hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	}
	// Environment
	if (henv != SQL_NULL_HENV)
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
	return 0;
}

