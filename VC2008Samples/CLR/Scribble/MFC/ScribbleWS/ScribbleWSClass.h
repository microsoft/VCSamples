// ScribbleWSClass.h

#pragma once

using namespace System;
using namespace System::Web;
using namespace System::Web::Services;
using namespace System::Xml::Serialization;
using namespace System::Drawing;
using namespace cli;


namespace ScribbleWS
{
	[XmlRoot("Shape", IsNullable=false)]
	public ref class Shape {
	public:
		[XmlAttribute("Name")]
		System::String^ name;

		[XmlArray("Points", IsNullable=false)]
		[XmlArrayItem("Point", IsNullable=false)]
		array<Point>^ points;

	public:
		Shape(void);
		Shape(String^ n);

		static Shape^ CreateRectangle(int width, int height);
		static Shape^ CreateCircle(int radius);
	};


    public ref class ScribbleWSClass : public System::Web::Services::WebService {
        
    public:
		ScribbleWSClass()
		{
			InitializeComponent();
		}
	protected:
		~ScribbleWSClass()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent()
		{
		}	
#pragma endregion

		// WEB SERVICE METHODS

	public:
        [System::Web::Services::WebMethod] 
        Shape ^GetRectangle(int width, int height);

        [System::Web::Services::WebMethod] 
        Shape ^GetCircle(int radius);
	};

}