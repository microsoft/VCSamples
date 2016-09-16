//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


namespace PUZZLE
{
	using System;
	using System.Drawing;
	using System.Collections;
	using System.ComponentModel;
	using System.Windows.Forms;

	/// <summary>
	///    Summary description for AboutForm.
	/// </summary>

	public class AboutForm : System.Windows.Forms.Form
	{
		/// <summary> 
		///    Required designer variable
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button ok;

		public AboutForm()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		///    Clean up any resources being used
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}
		#region Windows Form Designer generated code
		/// <summary>
		///    Required method for Designer support - do not modify
		///    the contents of this method with the code editor
		/// </summary>
		private void InitializeComponent()
		{
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(AboutForm));
			this.ok = new System.Windows.Forms.Button();
			this.label4 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// ok
			// 
			this.ok.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ok.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.ok.Location = new System.Drawing.Point(114, 128);
			this.ok.Name = "ok";
			this.ok.TabIndex = 1;
			this.ok.Text = "&Ok";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(48, 48);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(208, 16);
			this.label4.TabIndex = 5;
			this.label4.Text = "Copyright (c) 1981-2001 Microsoft Corp.";
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(48, 72);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(200, 16);
			this.label5.TabIndex = 6;
			this.label5.Text = "Steven Toscano, Microsoft Corp.";
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(48, 16);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(208, 16);
			this.label1.TabIndex = 2;
			this.label1.Text = "Microsoft (R) Tile Puzzle .NET Application";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(48, 88);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(200, 23);
			this.label2.TabIndex = 7;
			
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(48, 32);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 16);
			this.label3.TabIndex = 4;
			this.label3.Text = "Version 1.0";
			// 
			// AboutForm
			// 
			this.AutoScaleDimensions = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(304, 170);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.label2,
																		  this.label5,
																		  this.label4,
																		  this.label3,
																		  this.label1,
																		  this.ok});
			this.Font = new System.Drawing.Font("Tahoma", 8F);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "AboutForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
			this.Text = "About Tile Puzzle 1.0";
			this.ResumeLayout(false);

		}
		#endregion
	}
}