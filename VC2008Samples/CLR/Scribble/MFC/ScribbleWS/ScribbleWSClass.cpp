#include "stdafx.h"
#include "ScribbleWSClass.h"
#include "Global.asax.h"


namespace ScribbleWS
{
	//
	// Shape Class
	//
	Shape::Shape() {
	}

	Shape::Shape(String^ name) {
		this->name = name;
	}

	Shape^ Shape::CreateRectangle(int width, int height) {
		Shape^ shape = gcnew Shape("Rectangle");
		shape->points = gcnew array<Point>(5);

		shape->points[0].X = 0;
		shape->points[0].Y = 0;
		shape->points[1].X = 0;
		shape->points[1].Y = height;
		shape->points[2].X = width;
		shape->points[2].Y = height;
		shape->points[3].X = width;
		shape->points[3].Y = 0;
		shape->points[4].X = 0;
		shape->points[4].Y = 0;

		return shape;
	}

	Shape^ Shape::CreateCircle(int radius) {
		Shape^ shape = gcnew Shape("Circle");
		shape->points = gcnew array<Point>(361);

		for (int i = 0; i <= 90; i++) {
			shape->points[i].X = (int)(radius * (Math::Cos(((double)i / 180) * Math::PI)));
			shape->points[i].Y = (int)(radius * (Math::Sin(((double)i / 180) * Math::PI)));
			shape->points[180 - i].X = - shape->points[i].X;
			shape->points[180 - i].Y = shape->points[i].Y;
			shape->points[180 + i].X = - shape->points[i].X;
			shape->points[180 + i].Y = - shape->points[i].Y;
			shape->points[360 - i].X = shape->points[i].X;
			shape->points[360 - i].Y = - shape->points[i].Y;
		}

		return shape;
	}

	//
	// WEB SERVICE METHODS
	//
    
	Shape^ ScribbleWSClass::GetRectangle(int width, int height) {
		return Shape::CreateRectangle(width, height);
    }

	Shape^ ScribbleWSClass::GetCircle(int radius) {
		return Shape::CreateCircle(radius);
    }
};
