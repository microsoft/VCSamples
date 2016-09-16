#pragma once
// PluginBld.h : interface of the PluginBuilder class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related 
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
/////////////////////////////////////////////////////////////////////////////

#ifdef _MANAGED

#using <mscorlib.dll>
#using <System.Xml.dll>


using namespace System;
using namespace System::Xml;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace ScribbleApp;

ref class PluginLoadException : Exception
{
   static String ^ exceptMesg = "Error loading plugin";
public:
   PluginLoadException(String ^ mesg, Exception ^ inner) :
      Exception(String::Format("{0} : {1}", exceptMesg, mesg, inner))
   {
      
   }
};

ref class PluginFileException : Exception
{
   static String ^ exceptMesg = "Error in plugin file";
public:
   PluginFileException(String ^ mesg, Exception ^ inner) :
      Exception(String::Format("{0} : {1}", exceptMesg, mesg, inner))
   {
      
   }
};

ref class PluginBuilder
{
public:
	static List<IScribblePlugin ^> ^ GetPlugins(String ^ pluginFileName);
private:
	static IScribblePlugin ^ GetPlugin(String ^ assemblyPath, String ^ assemblyName);
    static List<String ^> ^ ReadPluginFile(String ^ pluginFilePath, String ^ pluginFileName);
};

#endif