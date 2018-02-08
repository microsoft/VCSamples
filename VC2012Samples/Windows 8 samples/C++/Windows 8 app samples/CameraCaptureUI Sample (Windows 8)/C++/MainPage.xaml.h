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


    public ref class MainPage sealed
    {
    public:
        MainPage();

    protected:
		virtual void LoadState(Platform::Object^ navigationParameter, Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState);
		virtual void SaveState(Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState);
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

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

        void NotifyUser(Platform::String^ strMessage, NotifyType type);
        void LoadScenario(Platform::String^ scenarioName);
        event Windows::Foundation::EventHandler<Platform::Object^>^ ScenarioLoaded;

    private:
        void PopulateScenarios();

        Platform::Collections::Vector<Object^>^ ScenarioList;
        Windows::UI::Xaml::Controls::Frame^ HiddenFrame;
        void Footer_Click(Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        bool autoSizeInputSectionWhenSnapped;

        void Scenarios_SelectionChanged(Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);

    internal:
        static MainPage^ Current;

    };
}
