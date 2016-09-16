// This is the main DLL file.

#include "stdafx.h"

#include "ScribbleApp.h"

using namespace System::Drawing;

namespace ScribbleApp
{
	public
	interface class IScribbleDoc
	{
	public:
		void DrawLine(Point ^ p1, Point ^ p2);
		void SetPenColor(Color c);
		Color GetPenColor();
	};

	public
	interface class IScribbleApp
	{
	public:
		IScribbleDoc ^ GetDocument();
	};

	public
	interface class IScribblePlugin
	{
	public:
		property System::String ^ Name;
		void Run(IScribbleApp ^ iScribApp);
	};
}