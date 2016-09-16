
#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <atlbase.h>

#include <iostream>
using namespace std;

#import <VCProjectEngine.dll> raw_interfaces_only raw_native_types
using namespace VCProjectEngineLibrary;


int main( )
{

	CoInitialize( NULL );

	HRESULT hr = S_OK;
	// Create the VCProjectEngine
	CComPtr<VCProjectEngine> spEngine;
	hr = CoCreateInstance( __uuidof(VCProjectEngineObject), NULL, CLSCTX_INPROC_SERVER, __uuidof(VCProjectEngine), (void**)&spEngine );
	if( FAILED( hr ) || !spEngine )
	{
		cout << "Error: cannot create VCProjectEngine object." << endl;
		CoUninitialize(); 
		return 1;
	}

	// Open an existing project.
	CComPtr<IDispatch> spDispProj;
	hr = spEngine->LoadProject( CComBSTR( L"MyProject.vcproj" ), &spDispProj );
	if( FAILED( hr ) || !spDispProj )
	{
		cout << "Error: cannot open the specified project." << endl;
		CoUninitialize(); 
		return 1;
	}
	CComQIPtr<VCProject> spProject = spDispProj;
	if( !spProject )
	{
		cout << "Error: cannot query VCProject interface." << endl;
		CoUninitialize(); 
		return 1;
	}

	// Change the project's name to "Voila"
	hr = spProject->put_Name( CComBSTR( L"Voila" ) );
	if( FAILED( hr ) )
		cout << "Error: cannot change project name." << endl;

	// Add a new configuration to the project
	hr = spProject->AddConfiguration( CComBSTR( L"Whichever Name" ) );
	if( FAILED( hr ) )
		cout << "Error: cannot add a new configuration." << endl;

	// Access the configurations collection of the project
	CComPtr<IDispatch> spDispConfigs;
	hr = spProject->get_Configurations( &spDispConfigs );
	if( FAILED( hr ) || !spDispConfigs )
	{
		cout << "Error: cannot access the configurations collecion." << endl;
		CoUninitialize(); 
		return 1;
	}
	CComQIPtr<IVCCollection> spConfigCol = spDispConfigs;

	// Enumerate the Configurations collection by name to get the Debug configuration of the project
	CComPtr<IDispatch> spDispConfig;
	hr = spConfigCol->Item( CComVariant( L"Debug" ), &spDispConfig );
	if( FAILED( hr ) || !spDispConfig )
	{
		cout << "Error: cannot get the Debug configuraion." << endl;
		CoUninitialize(); 
		return 1;
	}
	CComQIPtr<VCConfiguration> spConfig = spDispConfig;

	// If you want to change the Configuration Type of the project from the default Dll to Exe
	hr = spConfig->put_ConfigurationType( typeApplication  );
	if( FAILED( hr ) )
		cout << "Error: cannot change configuration type." << endl;

	// Access the Tools collection for this configuration
	CComPtr<IDispatch> spDispTools;
	hr = spConfig->get_Tools( &spDispTools );
	if( FAILED( hr ) )
	{
		cout << "Error: cannot access the tools collection." << endl;
		CoUninitialize(); 
		return 1;
	}
	CComQIPtr<IVCCollection> spToolCol = spDispTools;

	// Enumerate the Tools collection by name to get the Linker tool
	CComPtr<IDispatch> spDispTool;
	hr = spToolCol->Item( CComVariant( L"VCLinkerTool" ), &spDispTool );
	if( FAILED( hr ) )
		cout << "Error: cannot get IDispatch interface of the linker tool." << endl;
	else
	{
		// Get the VCLinkerTool interface and directly change a property
		CComPtr<VCLinkerTool> spLinker;
		hr = spDispTool->QueryInterface( __uuidof( VCLinkerTool ), (void**)&spLinker );
		if( FAILED( hr ) || !spLinker )
			cout << "Error: cannot get the raw interface of the linker tool." << endl;
		else
		{
			// linkProgressOption is the enum that defines all the options for the ShowProgress property
			linkProgressOption enumDefault;
			// Access the ShowProgress property
			hr = spLinker->get_ShowProgress( &enumDefault );
			if( FAILED( hr ) )
				cout << "Error: cannot get the default value of Show Progress property." << endl;

			// Change the ShowProgress property to "Display All Progress Messages (/VERBOSE)"
			enumDefault = linkProgressAll;
			hr = spLinker->put_ShowProgress( enumDefault );
			if( FAILED( hr ) )
				cout << "Error: cannot change the Show Progress property from default to Display All Progress Messages (/VERBOSE)." << endl;
		}
	}

	// Add a cpp file called New.cpp to the project
	VARIANT_BOOL var;
	CComPtr<IDispatch> spDispFile;

	hr = spProject->CanAddFile( CComBSTR( L"New.cpp" ), &var );
	if( SUCCEEDED( hr ) && var )
	{
		hr = spProject->AddFile( CComBSTR( L"New.cpp" ), &spDispFile );
		if( FAILED( hr ) )
			cout << "Error: cannot add a new source file." << endl;
		// ...
	}


	// Access Files collection
	CComPtr<IDispatch> spDispFiles;
	hr = spProject->get_Files( &spDispFiles );
	if( SUCCEEDED( hr ) )
	{
		CComQIPtr<IVCCollection> spCol = spDispFiles;

		// Access a cpp file called "Existing.cpp" that is already in the project
		CComPtr<IDispatch> spDispAnotherFile;
		hr = spCol->Item( CComVariant( L"Existing.cpp" ), &spDispAnotherFile );
		if( SUCCEEDED( hr ) )
		{
			CComQIPtr<VCFile> spFile = spDispAnotherFile;

			// Access FileConfigurations collection of this file
			CComPtr<IDispatch> spDispCol;
			hr = spFile->get_FileConfigurations( &spDispCol );
			if( SUCCEEDED( hr ) )
			{
				CComQIPtr<IVCCollection> spFileConfigs = spDispCol;

				// Access the "Release" configuration of this file
				CComPtr<IDispatch> spDispFileConfig;
				hr = spFileConfigs->Item( CComVariant( L"Release|Win32" ), &spDispFileConfig );
				if( SUCCEEDED( hr ) )
				{
					CComQIPtr<VCFileConfiguration> spFileConfig = spDispFileConfig;

					// Get the default tool associated with this configuration of this file
					CComPtr<IDispatch> spDispFileTool;
					hr = spFileConfig->get_Tool( &spDispFileTool );
					if( SUCCEEDED( hr ) )
					{
						// A different way of changing a property.  This time through the IDispatch interface
						// Change the Optimization property to Full Optimization (/Ox)
						CComDispatchDriver drFileTool( spDispFileTool );
						CComVariant var1( optimizeFull );
						hr = drFileTool.PutPropertyByName( CComBSTR( L"Optimization" ), &var1 );
						if( FAILED( hr ) )
							cout << "Error: cannot change Optimization property from default to Full Optimization (/Ox)." << endl;
					}
					else
						cout << "Error: cannot get the tool associated with the source file." << endl;
				}
				else
					cout << "Error: cannot get the Release configuration of the source file." << endl;
			}
			else
				cout << "Error: cannot get the file level configurations collection." << endl;
		}
		//...

	}

	// Save to a new project so users can compare with the original
	hr = spProject->put_ProjectFile( CComBSTR( L"MyNewProject.vcproj" ) );
	if( FAILED( hr ) )
		cout << "Error: cannot set new project file name." << endl;

	hr = spProject->Save( );
	if( FAILED( hr ) )
		cout << "Error: cannot save project." << endl;

	spEngine->RemoveProject( spDispProj );

	CoUninitialize();
	
	return 0;
}