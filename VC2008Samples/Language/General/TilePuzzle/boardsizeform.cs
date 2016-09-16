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
	using System.Windows.Forms.ComponentModel;

	/// <summary>
	///    Summary description for BoardSizeForm.
	/// </summary>

	public class BoardSizeForm : System.Windows.Forms.Form
	{
		/// <summary> 
		///    Required designer variable
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Button cancel;
		private System.Windows.Forms.Button ok;
		private System.Windows.Forms.TextBox edtCol;
		private System.Windows.Forms.TextBox edtRow;
		private System.Windows.Forms.Label txtLabel2;
		private System.Windows.Forms.Label txtLabel1;

		internal int row = 3;
		internal int col = 3;
		internal int xForm = 30;

		public BoardSizeForm()
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
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(BoardSizeForm));
			this.txtLabel2 = new System.Windows.Forms.Label();
			this.cancel = new System.Windows.Forms.Button();
			this.edtCol = new System.Windows.Forms.TextBox();
			this.ok = new System.Windows.Forms.Button();
			this.txtLabel1 = new System.Windows.Forms.Label();
			this.edtRow = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// txtLabel2
			// 
			this.txtLabel2.Location = new System.Drawing.Point(48, 40);
			this.txtLabel2.Name = "txtLabel2";
			this.txtLabel2.Size = new System.Drawing.Size(50, 16);
			this.txtLabel2.TabIndex = 2;
			this.txtLabel2.Text = "Col:";
			// 
			// cancel
			// 
			this.cancel.Anchor = System.Windows.Forms.AnchorStyles.None;
			this.cancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.cancel.Location = new System.Drawing.Point(101, 73);
			this.cancel.Name = "cancel";
			this.cancel.Size = new System.Drawing.Size(48, 24);
			this.cancel.TabIndex = 5;
			this.cancel.Text = "&Cancel";
			// 
			// edtCol
			// 
			this.edtCol.Location = new System.Drawing.Point(120, 40);
			this.edtCol.Name = "edtCol";
			this.edtCol.Size = new System.Drawing.Size(25, 20);
			this.edtCol.TabIndex = 3;
			this.edtCol.Text = "";
			// 
			// ok
			// 
			this.ok.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ok.DialogResult = System.Windows.Forms.DialogResult.OK;
			this.ok.Location = new System.Drawing.Point(37, 74);
			this.ok.Name = "ok";
			this.ok.Size = new System.Drawing.Size(48, 24);
			this.ok.TabIndex = 4;
			this.ok.Text = "&Ok";
			// 
			// txtLabel1
			// 
			this.txtLabel1.Location = new System.Drawing.Point(48, 16);
			this.txtLabel1.Name = "txtLabel1";
			this.txtLabel1.Size = new System.Drawing.Size(50, 20);
			this.txtLabel1.TabIndex = 0;
			this.txtLabel1.Text = "Row:";
			// 
			// edtRow
			// 
			this.edtRow.Location = new System.Drawing.Point(120, 13);
			this.edtRow.Name = "edtRow";
			this.edtRow.Size = new System.Drawing.Size(25, 20);
			this.edtRow.TabIndex = 1;
			this.edtRow.Text = "";
			// 
			// BoardSizeForm
			// 
			this.AutoScaleDimensions = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(189, 116);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.cancel,
																		  this.ok,
																		  this.edtCol,
																		  this.edtRow,
																		  this.txtLabel2,
																		  this.txtLabel1});
			this.Font = new System.Drawing.Font("Tahoma", 8F);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "BoardSizeForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
			this.Text = "Customize Board Size";
			this.ResumeLayout(false);

		}
		#endregion

		public int Row
		{
			set
			{
				if (value > 0)
				{
					row = value;
					edtRow.Text = row.ToString();
				}
			}
			get
			{
				int i;
				try
				{

					i = Convert.ToInt32(edtRow.Text);
	#if _DEBUG
									Console.WriteLine("-----row------");
									 Console.WriteLine("i=" + i);
									 Console.WriteLine("edtRow.Text="+edtRow.Text);
									 Console.WriteLine("-----row------");
	#endif

				}
				catch(Exception e)
				{
	                        
					i = 1;
					edtRow.Text = "1";
					Console.WriteLine(e.ToString());
				}
				row = Math.Max(1,i);
				return row;
			}
		}	

		public int Col
		{
			set
			{
				if (value > 0)
					col = value;
					edtCol.Text = col.ToString();
			}
			get
			{
				int i;
				try
				{
	                            
					i = Convert.ToInt32(edtCol.Text);
	#if _DEBUG
									 Console.WriteLine("-----col------");
									 Console.WriteLine("i=" + i);
									 Console.WriteLine("edtCol.Text="+edtCol.Text);
									 Console.WriteLine("-----col------");
	#endif
				}
				catch(Exception e)
				{
	                        
					i = 1;
					edtCol.Text = "1";
					Console.WriteLine(e.ToString());
				}
				col = Math.Max(1,i);
				return col;
			}
		}	
	}
}
