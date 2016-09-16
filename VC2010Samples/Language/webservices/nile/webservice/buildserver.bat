REM build the web service
cl /clr:oldSyntax /LD nileconnection.cpp nilewebservice.cpp /link /OUT:NileWebService.dll 