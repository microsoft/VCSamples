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
// MainPage.xaml.cpp
// Implementation of the MainPage.xaml class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "App.xaml.h"

#include <collection.h>

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Platform;
using namespace SDKSample;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::ViewManagement;

MainPage^ MainPage::Current = nullptr;

MainPage::MainPage()
{
    InitializeComponent();

    // This frame is hidden, meaning it is never shown.  It is simply used to load
    // each scenario page and then pluck out the input and output sections and
    // place them into the UserControls on the main page.
    HiddenFrame = ref new Windows::UI::Xaml::Controls::Frame();
    HiddenFrame->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
    ContentRoot->Children->Append(HiddenFrame);

    FeatureName->Text = FEATURE_NAME;

    this->SizeChanged += ref new SizeChangedEventHandler(this, &MainPage::MainPage_SizeChanged);
    Scenarios->SelectionChanged += ref new SelectionChangedEventHandler(this, &MainPage::Scenarios_SelectionChanged);

    MainPage::Current = this;
    autoSizeInputSectionWhenSnapped = true;
}

/// <summary>
/// We need to handle SizeChanged so that we can make the sample layout property
/// in the various layouts.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void MainPage::MainPage_SizeChanged(Object^ sender, SizeChangedEventArgs^ e)
{
    MainPageSizeChangedEventArgs^ args = ref new MainPageSizeChangedEventArgs();
    MainPageResized(this, args);
}

void MainPage::PopulateScenarios()
{
    ScenarioList = ref new Platform::Collections::Vector<Object^>();

    // Populate the ListBox with the list of scenarios as defined in Constants.cpp.
    for (unsigned int i = 0; i < scenarios->Length; ++i)
    {
        Scenario s = scenarios[i];
        ListBoxItem^ item = ref new ListBoxItem();
        item->Name = s.ClassName;
        item->Content = (i + 1).ToString() + ") " + s.Title;
        ScenarioList->Append(item);
    }

    // Bind the ListBox to the scenario list.
    Scenarios->ItemsSource = ScenarioList;
    Scenarios->ScrollIntoView(Scenarios->SelectedItem);
}

/// <summary>
/// This method is responsible for loading the individual input and output sections for each scenario.  This 
/// is based on navigating a hidden Frame to the ScenarioX.xaml page and then extracting out the input
/// and output sections into the respective UserControl on the main page.
/// </summary>
/// <param name="scenarioName"></param>
void MainPage::LoadScenario(String^ scenarioName)
{
    autoSizeInputSectionWhenSnapped = true;

    // Load the ScenarioX.xaml file into the Frame.
    TypeName scenarioType = {scenarioName, TypeKind::Custom};
    HiddenFrame->Navigate(scenarioType, this);

    // Get the top element, the Page, so we can look up the elements
    // that represent the input and output sections of the ScenarioX file.
    Page^ hiddenPage = safe_cast<Page^>(HiddenFrame->Content);

    // Get each element.
    UIElement^ input = safe_cast<UIElement^>(hiddenPage->FindName("Input"));
    UIElement^ output = safe_cast<UIElement^>(hiddenPage->FindName("Output"));

    if (input == nullptr)
    {
        // Malformed input section.
        NotifyUser("Cannot load scenario input section for " + scenarioName + 
            "  Make sure root of input section markup has x:Name of 'Input'", NotifyType::ErrorMessage);
        return;
    }

    if (output == nullptr)
    {
        // Malformed output section.
        NotifyUser("Cannot load scenario output section for " + scenarioName + 
            "  Make sure root of output section markup has x:Name of 'Output'", NotifyType::ErrorMessage);
        return;
    }

    // Find the LayoutRoot which parents the input and output sections in the main page.
    Panel^ panel = safe_cast<Panel^>(hiddenPage->FindName("LayoutRoot"));

    if (panel != nullptr)
    {
        unsigned int index = 0;
        UIElementCollection^ collection = panel->Children;

        // Get rid of the content that is currently in the intput and output sections.
        collection->IndexOf(input, &index);
        collection->RemoveAt(index);

        collection->IndexOf(output, &index);
        collection->RemoveAt(index);

        // Populate the input and output sections with the newly loaded content.
        InputSection->Content = input;
        OutputSection->Content = output;

        ScenarioLoaded(this, nullptr);
    }
    else
    {
        // Malformed Scenario file.
        NotifyUser("Cannot load scenario: " + scenarioName + ".  Make sure root tag in the '" + 
            scenarioName + "' file has an x:Name of 'LayoutRoot'", NotifyType::ErrorMessage);
    }
}

void MainPage::Scenarios_SelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
{
    if (Scenarios->SelectedItem != nullptr)
    {
        NotifyUser("", NotifyType::StatusMessage);

        LoadScenario((safe_cast<ListBoxItem^>(Scenarios->SelectedItem))->Name);
    }
}

void MainPage::NotifyUser(String^ strMessage, NotifyType type)
{
    switch (type)
    {
    case NotifyType::StatusMessage:
        // Use the status message style.
        StatusBlock->Style = safe_cast<Windows::UI::Xaml::Style^>(this->Resources->Lookup("StatusStyle"));
        break;
    case NotifyType::ErrorMessage:
        // Use the error message style.
        StatusBlock->Style = safe_cast<Windows::UI::Xaml::Style^>(this->Resources->Lookup("ErrorStyle"));
        break;
    default:
        break;
    }
    StatusBlock->Text = strMessage;

    // Collapsed the StatusBlock if it has no text to conserve real estate.
    if (StatusBlock->Text != "")
    {
        StatusBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
    }
    else
    {
        StatusBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
    }
}

void MainPage::Footer_Click(Object^ sender, RoutedEventArgs^ e)
{
    auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
    Windows::System::Launcher::LaunchUriAsync(uri);
}




void SDKSample::MainPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	PopulateScenarios();
}
