#region Using directives

using System;
using System.Collections.Generic;
using ScribbleApp;
using System.Windows.Forms;
using System.Text;

#endregion

namespace CSPenColor
{
	public class MyPlugin : IScribblePlugin
	{
		public void Run(IScribbleApp iScribApp)
		{
			IScribbleDoc scribDoc = iScribApp.GetDocument();

			ColorDialog colorChooser = new ColorDialog();
			
			if (colorChooser.ShowDialog() == DialogResult.OK)
			{
				scribDoc.SetPenColor(colorChooser.Color);
			}
		}

		public String Name
		{
			get
			{
				return name;
			}

			set
			{
			}
		}

		private String name = "Pen Color";
	}
}
