// This is the main DLL file.

#include <cliext\adapter>
#include <cliext\algorithm>
#include <cliext\vector>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "MyAlgorithm.h"
#include "StlClrLibrary.h"
#include "native.h"

void StlClrLibrary::Tools::Shuffle(System::Collections::Generic::IList<System::String^>^ list)
{
	// copying the list to a local vector
	cliext::vector<System::String^> v(list);
	
	// shuffling
	cliext::random_shuffle(v.begin(), v.end());

	// marshal back the list
	int i = 0;
	for each(System::String^ str in v)
	{
		list[i]=str;
		i++;
	}
}

void StlClrLibrary::Tools::BubbleSort(System::Collections::Generic::IList<System::String^>^ list)
{
	//You don't need to create a temporary vector copy, you can use collection adapters
	cliext::collection_adapter<System::Collections::Generic::IList<System::String^>> adapter(list);
	MyAlgor::BubbleSort(adapter.begin(),adapter.end());
}

void StlClrLibrary::Tools::BubbleStep(System::Collections::Generic::IList<System::String^>^ list)
{
	//You don't need to create a temporary vector copy, you can use collection adapters
	typedef cliext::collection_adapter<System::Collections::Generic::IList<System::String^>> MyCont;
	MyCont adapter(list);
	
	// this is not exactly bubble sort, but it's fun to look at how it get sorted.
	MyCont::iterator prev, current; 
	prev = current = adapter.begin();
	current++;
	for( ; current < adapter.end(); prev=current, ++current)
	{
		// exit this function when we did a swap
		if (MyAlgor::BubbleStep(prev, current))
			break;
	}
}

// Same as BubbleSort(), but the native version
void StlClrLibrary::Tools::BubbleSortNative(System::Collections::Generic::IList<System::String^>^ list)
{
	// marshal to a native local vector first
	std::vector<std::string> native_vec;
	for each(System::String^ str in list)
	{
		native_vec.push_back(msclr::interop::marshal_as<std::string>(str));
	}

	// calling a native function that will do the sorting
	Native::BubbleSort(native_vec);
	
	// marshal back the list
	int i = 0;
	for each(std::string str in native_vec)
	{
		list[i]=msclr::interop::marshal_as<System::String^>(str);
		i++;
	}
}

