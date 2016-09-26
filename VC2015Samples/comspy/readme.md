
 
# Spy
The COM+
system event publisher publishes events using COM+ LCE services. The COMSpy sample application provides an example of a program
which subscribes to these published events. COMSpy
shows what is going on inside a COM+ process by displaying and logging the
following event metrics

Application	Activity
Thread 		Transaction
Method   	Object
ObjectConstruct	Instance
ObjectPool   	Security
Identity   	Queued Component
Exceptioin   	Resource
CRM   		User
Load Balancing	Event Store



## Project Files

Folder Name	Description
spy\COMSpy	Executable for COMSpy
spy\COMSpyFace	A utility project for COMSpy interface files
spy\COMSpyCtl	A control that shows how to subscribe to COM+ events
spy\COMSpyAudit	An in-proc COM component that shows an auditing mechanism for logging events to a SQL Server Database


## Auditing

To use the SQLServer auditing feature, you must do the following before you run COMSpy

1. Create a SQL Server Database for COMSpy Auditing. 

2. Run ComSpyAudit.sql script under Spy\ComSpyAudit directory to create the following tables in your SQL Server database. 

    | Table Name |	Description |
    |------------|--------------|
    AppEvents	| For Application Event Metrics |
    ActivityEvents |	For Activity Event Metrics
    ThreadEvents |	For Thread Event Metrics
    TransactionEvents |	For Transaction Event Metrics
    MethodEvents |	For Method Event Metrics
    ObjectEvents|	For Object, ObjectConstruction and Instance Event Metrics
    ObjectPoolEvents|	For ObjectPool Event Metrics
    SecurityEvents|	For Security and Identity Event Metrics
    QCEvents|	For Queued Components Event Metrics
    ExceptioinEvents|	For Exceptioin Event Metrics
    ResourceEvents|	For Resource Event Metrics
    CRMEvents|	For CRM Event Metrics
    LBEvents|	For Load Balancing Event Metrics

3. Create an ODBC DSN named "ComSpyAudit" that connects to your SQL Server database. 


## Build Notes

1. Set the [MSSDK]\include, [MSSDK]\lib in the header files and library files paths in your IDE environment. 

2. Load Spy project workspace by using spy\spy.sln (requires VS 8.0). 

3. Build COMSpyFace project first in order to generate the correct header files for the rest of the spy projects. 

4. Set the active project to COMSpy and then build all. 

Note: This sample uses ATL/MFC.  Make sure Visual Studio 8.0 is installed on your machine and the include path has references to the atlmfc headers location.


## To run Spy

1. Run COMSpy.exe. 

2. If you would like to log events to a file, choose Log to File from the Options menu and specify the name of a log file. 

3. If you would like to log events to a SQL Server database, right click on the spy window to bring up the pop-up menu and choose Audit to db from the Options submenu. 

4. Choose Select Events from the COMSpy menu or pop-up menu. 

5. Select an Application or a Process that you would like to monitor from the Select Application or Process list box. 

6. Select events from the Select Application or Process Events list box for the Application or Process selected in step 5. 

7. Repeat step 5 and 6 for the Applications or Processes that you would like to monitor. 

8. Select events from the Select System Events list box if you would like to monitor the system events. 

9. Click OK. COMSpy will display events as they are received. 


