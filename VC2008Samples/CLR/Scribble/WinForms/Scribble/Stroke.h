#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Collections;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;

[Serializable]
ref class Stroke
{
public:
   int penWidth;
   ArrayList^ pointArray;
   Rectangle boundingRect;
   Stroke( int nPenWidth );
   ~Stroke();
   Rectangle GetBoundingRectangle()
   {
      return boundingRect;
   }

   void DrawStroke( Graphics^ g );
   void FinishStroke();
   int Min( int x, int y )
   {
      return (x < y) ? x : y;
   }

   int Max( int x, int y )
   {
      return (x > y) ? x : y;
   }

};
