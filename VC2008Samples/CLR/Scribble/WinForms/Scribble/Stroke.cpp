#include "Stroke.h"

Stroke::Stroke( int nPenWidth )
{
   penWidth = nPenWidth;
   pointArray = gcnew ArrayList;
}

Stroke::~Stroke(){}

void Stroke::DrawStroke( Graphics^ g )
{
   Pen^ myPen = gcnew Pen( Color::Black,(float)penWidth );
   for ( int i = 1; i < pointArray->Count; i++ )
   {
      Point^ p1 = dynamic_cast<Point^>(pointArray[ i - 1 ]);
      Point^ p2 = dynamic_cast<Point^>(pointArray[ i ]);
      g->DrawLine( myPen,  *p1,  *p2 );

   }
   delete myPen;
}

void Stroke::FinishStroke()
{
   if ( pointArray->Count == 0 )
   {
      boundingRect.Size = Size::Empty;
      return;
   }

   Point^ pt = dynamic_cast<Point^>(pointArray[ 0 ]);
   boundingRect = Rectangle(pt->X,pt->Y,0,0);
   for ( int i = 1; i < pointArray->Count; i++ )
   {
      pt = dynamic_cast<Point^>(pointArray[ i ]);
      boundingRect = Rectangle::FromLTRB( Min( boundingRect.Left, pt->X ), Min( boundingRect.Top, pt->Y ), Max( boundingRect.Right, pt->X ), Max( boundingRect.Bottom, pt->Y ) );

   }
   boundingRect.Inflate( Size((int)penWidth,(int)penWidth) );
   return;
}