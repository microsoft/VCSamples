//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// MainPage.xaml.h
// Declaration of the MainPage.xaml class.
//

#pragma once

#include "pch.h"
#include "MainPage.g.h"
#include "Constants.h"

namespace SDKSample
{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};

	public ref class MainPageSizeChangedEventArgs sealed
	{
	public:

	private:
	};

	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:

	internal:
		property bool AutoSizeInputSectionWhenSnapped
		{
			bool get()
			{
				return autoSizeInputSectionWhenSnapped;
			}

			void set(bool value)
			{
				autoSizeInputSectionWhenSnapped = value;
			}
		}

		property Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ LaunchArgs
		{
			Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ get()
			{
				return safe_cast<App^>(App::Current)->LaunchArgs;
			}
		}

		void NotifyUser(Platform::String^ strMessage, NotifyType type);
		void LoadScenario(Platform::String^ scenarioName);
		event Windows::Foundation::EventHandler<Platform::Object^>^ ScenarioLoaded;
		event Windows::Foundation::EventHandler<MainPageSizeChangedEventArgs^>^ MainPageResized;

	private:
		void PopulateScenarios();

		Platform::Collections::Vector<Object^>^ ScenarioList;
		Windows::UI::Xaml::Controls::Frame^ HiddenFrame;
		void Footer_Click(Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		bool autoSizeInputSectionWhenSnapped;

		void MainPage_SizeChanged(Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
		void Scenarios_SelectionChanged(Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);

	internal:
		static MainPage^ Current;

	private:
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
