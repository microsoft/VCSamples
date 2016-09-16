// PluginBld.cpp : implementation of the CScribbleDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#include "pluginbld.h"

#ifdef _MANAGED

using namespace System::Reflection;

List<IScribblePlugin ^> ^
PluginBuilder::GetPlugins(String ^ pluginFileName)
{
	// Retrieve application directory
	// we assume that the plugins XML file and the assemblies to be loaded
	// exist in the application directory
	Assembly ^ appAssembly = Assembly::GetExecutingAssembly();
	String ^ appDir = System::IO::Path::GetDirectoryName(appAssembly->Location);

	List<String ^> ^ pluginNameList = ReadPluginFile(appDir, pluginFileName);
	List<IScribblePlugin ^> ^ ipa = gcnew List<IScribblePlugin ^>();

	for (int IScribblePlugin = 0; IScribblePlugin < pluginNameList->Count; ++IScribblePlugin)
	{
		ipa->Add(GetPlugin(appDir, dynamic_cast<String ^>(pluginNameList->default[IScribblePlugin])));
	}

	return ipa;
}

IScribblePlugin ^
PluginBuilder::GetPlugin(String ^ assemblyPath, String ^ assemblyName)
{
	Assembly ^ assem = nullptr;
	Type ^ pluginType = nullptr;
	String ^ pluginInterfaceName = "IScribblePlugin";

	try
	{
		String ^ assemblyLocation = assemblyPath? System::IO::Path::Combine(assemblyPath, assemblyName) : assemblyName;
		assem = Assembly::LoadFrom(assemblyLocation);
	}
	catch (Exception ^ e)
	{
		throw gcnew PluginLoadException(e->Message, e);
	}

	array<Module ^> ^ modules = assem->GetModules();
	for (int iMod = 0; iMod < modules->Length; ++iMod)
	{
		array<Type ^> ^ types = modules[iMod]->GetTypes();
		for (int iType = 0; iType < types->Length; ++iType)
		{
			array<Type ^> ^ interfaces = types[iType]->GetInterfaces();
			for (int iIface = 0; iIface < interfaces->Length; ++iIface)
			{
				if (interfaces[iIface]->Name->Equals(pluginInterfaceName))
				{
					pluginType = types[iType];
				}
			}
		}
	}

	if (pluginType == nullptr)
	{
		throw gcnew PluginLoadException(
			String::Format("Could not find type IScribblePlugin in {0}", assemblyName), nullptr);
	}

	IScribblePlugin ^ ip = dynamic_cast<IScribblePlugin ^>(Activator::CreateInstance(pluginType));
	return ip;
}

List<String ^> ^
PluginBuilder::ReadPluginFile(String ^ pluginFilePath, String ^ pluginFileName) 
{
	String ^ pluginLocation = pluginFilePath? System::IO::Path::Combine(pluginFilePath, pluginFileName) : pluginFileName;
	XmlTextReader ^ reader = nullptr;
	XmlDocument ^ xmlDoc = nullptr;
	List<String ^> ^ pluginNameList = gcnew List<String ^>();

	try 
	{
		reader = gcnew XmlTextReader(pluginLocation);
		xmlDoc = gcnew XmlDocument();
		xmlDoc->Load(reader);
		XmlNodeList^ nodeList = xmlDoc->DocumentElement->SelectNodes("/Plugins/Plugin");
		System::Collections::IEnumerator^ nodeEnum = nodeList->GetEnumerator();

		while (nodeEnum->MoveNext()) 
		{
			XmlNode^ node = dynamic_cast<XmlNode^>(nodeEnum->Current);
			XmlAttribute^ attrib = node->Attributes["Assembly"];

			pluginNameList->Add(attrib->Value);
		}
	} 
	catch (Exception^ exp) 
	{
		throw gcnew PluginFileException ("Failed to load XML plugin data file.", exp);
	} 
	finally 
	{
		if (reader != nullptr) 
		{
			reader->Close();
		}
	}

	return pluginNameList;
}

#endif