//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


namespace PUZZLE {
	
	using System;
	using System.Drawing;
	using System.Windows.Forms;
	using System.ComponentModel;
	using System.ComponentModel.Design;
	using System.Diagnostics;

	public enum MoveDirectionEnum
	{
		eUp = 0,
		eRight = 1,
		eDown = 2,
		eLeft = 3
	}
			
	public class PuzzleBoard 
	{
		private Form frmParent;
		private Rectangle ParentRect = new Rectangle();
		private static int cxInit = 60;
		private static int nBlankTile = 0;		// Use '0' to indicate a blank tile (blank block in the board)
		private Bitmap bmpTile = null;
		protected Point pt;
		private int boardCol;			// Board column
		private int boardRow;			// Board row
		public	int[] boardData;
		private int MaxTiles;
		private string PuzzleFileName = "puzzle1.bmp";
		
		public Point Position
		{
			get {return pt;}
			set {pt = value;
				RedrawBoard();}
		}
		
		public void RePosition(Rectangle rc)
		{
			//Point ptSav = Point.Copy(pt);
			Point ptSav = pt;
			this.ParentRect = rc;
			pt.X = Math.Max(rc.X,rc.X + ((rc.Width - bounds.Width)/2));
			pt.Y = Math.Max(rc.Y,rc.Y + ((rc.Height - bounds.Height)/2));
			if (pt != ptSav)
				RedrawBoard();
		}
		
		public PuzzleBoard()
		{
			pt = new Point(0,0);
			boardRow = 3;
			boardCol = 3;
			setSize(boardRow, boardCol);
			boardData = new int[MaxTiles];
			
			for (int i = 0; i < MaxTiles; i++)
				boardData[i] = (i+1)%MaxTiles;

			cxTile = cyTile = cxInit;
			bounds = new Rectangle(0,0,boardCol*cxTile,boardRow*cyTile);
		}
		
		public PuzzleBoard(Form frmParent)
		{
			pt = new Point(0,0);
			boardRow = 3;
			boardCol = 3;
			setSize(boardRow, boardCol);
			boardData = new int[MaxTiles];

			for (int i = 0; i < MaxTiles; i++)
				boardData[i] = (i+1)%MaxTiles;

			cxTile = cyTile = cxInit;
			bounds = new Rectangle(0,0,boardCol*cxTile,boardRow*cyTile);
			this.frmParent = frmParent;
		}
		
		public int Row
		{
			get {return boardRow;}
		}

		public int Col
		{
			get {return boardCol;}
		}

		public bool setSize(int row, int col)
		{
			boardRow = row;
			boardCol = col;
			MaxTiles = row * col;
			boardData = new int[MaxTiles];
			// Reload image
			if (bmpTile != null)
				LoadImageToBoard();
			return true;
		}
		
		public bool InitTile(int[] boardData, bool fRedraw)
		{
			this.boardData = boardData;
			if (fRedraw)
				RedrawBoard();		
			return true;
		}
		
		//
		// Given a position on board, return rectangle
		//
		private Rectangle CalcRect(int i)
		{
			Rectangle rc;
			rc = new Rectangle();
			rc.X = pt.X + ((i%boardCol)* cxTile) + 1;
			rc.Y = pt.Y + ((i/boardCol) * cyTile) + 1;
			rc.Width = cxTile-1;
			rc.Height = cyTile-1;
			return rc;
		}
		
		//
		//	Draw grid & tiles
		//	(Erase background if needed)
		//
		public bool RedrawBoard(Graphics g)
		{
			return RedrawBoard(g,0,this.MaxTiles-1);
		}
		
		public bool RedrawBoard(Graphics g, int iFirst, int iLast)
		{
			int i;
			SolidBrush brBlankTile = new SolidBrush(Color.DarkGreen);
			SolidBrush brBackground = new SolidBrush(Color.White);
			
			if (frmParent != null)
			{
				SolidBrush brGreen = new SolidBrush(Color.Green);
				Region rgn = new Region(this.ParentRect);
				Rectangle rcBoard = new Rectangle(pt.X,pt.Y,(boardCol*cxTile)+1,(boardRow*cyTile)+1);
				rgn.Xor(rcBoard);
				g.FillRegion(brGreen,rgn);
			}
			
			Pen penBlack = new Pen(Color.Black);
			g.DrawRectangle(penBlack,pt.X,pt.Y,(boardCol*cxTile)+1,(boardRow*cyTile)+1);
			
			for (i = 1; i < boardRow; i++)
				g.DrawLine(penBlack, pt.X, pt.Y+(cyTile * i), pt.X+(cxTile*boardCol), pt.Y + (cyTile * i));

			for (i = 1; i < boardCol; i++)
				g.DrawLine(penBlack, pt.X+(cxTile*i), pt.Y, pt.X+(cxTile*i), pt.Y+(cyTile*boardRow));

			for (i = iFirst; i < (iLast+1); i++)
			{
				if (boardData[i] != 0)
				{
					// Draw tile
					if (bmpTile == null)
					{
						StringFormat strFormat = new StringFormat(StringFormatFlags.DirectionRightToLeft);
						strFormat.Alignment = StringAlignment.Center;
						strFormat.LineAlignment = StringAlignment.Center;

						g.FillRectangle(brBackground,CalcRect(i));
						g.DrawString(boardData[i].ToString(),
							new Font("Tahoma",8.0f),
							Brushes.Black,
							CalcRect(i),
							strFormat);
					}
					else
					{
						g.DrawImage(this.imgTile[boardData[i]-1],CalcRect(i));
					}
				}
				else
				{
					// Draw black tile
					g.FillRectangle(brBlankTile,CalcRect(i));
				}
			}
			
			return (true);
			
		}

		public bool Move(int iPosFrom, int iPosTo)
		{
			int iTmp;
			
			if ((iPosFrom >= (boardCol*boardRow)) ||
				(iPosTo >= (boardCol*boardRow)))
			{
				Console.WriteLine("Invalid Direction");	
				return false;
			}

			iTmp = boardData[iPosFrom];
			boardData[iPosFrom] = boardData[iPosTo];
			boardData[iPosTo] = iTmp;
			// We don't have to redraw all tiles here!
			Graphics g = frmParent.CreateGraphics();
			RedrawBoard(g,iPosFrom,iPosFrom);
			RedrawBoard(g,iPosTo,iPosTo);
			g.Dispose();
			g = null;
			
			return true;
		}
		
		public bool RedrawBoard()
		{
			bool fRet;
			Graphics g = frmParent.CreateGraphics();
			fRet = RedrawBoard(g);
			g.Dispose(); g = null;
			return fRet;
		}

		public void ChangeImage()
		{
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(MainForm));

			PuzzleFileName = "ImageFromEmbedResource";
			
			if (bmpTile != null)
			{
				bmpTile.Dispose();
				bmpTile = null;
			}

			bmpTile = (System.Drawing.Bitmap)resources.GetObject("pictureBox1.Image");
		
			if (null != bmpTile)
				LoadImageToBoard();

			RedrawBoard();
		}

		public void ChangeImage(string FileName)
		{
			PuzzleFileName = FileName;
			
			if (bmpTile != null)
			{
				bmpTile.Dispose();
				bmpTile = null;
			}
			if (null != FileName)
			{
				bmpTile = new Bitmap(PuzzleFileName);
			}
		
			if (null != bmpTile)	
				LoadImageToBoard();

			RedrawBoard();
		}
		
		private void LoadImageToBoard()
		{
			int i, j, k;
			int X, Y;
			Bitmap canvas;
			Color cl;
			this.imgTile = new Image[MaxTiles];
			int PixelPerRow = bmpTile.Width/boardRow;
			int PixelPerCol = bmpTile.Height/boardCol;

			for (i = 0; i < MaxTiles; i++)
			{
				X = ((i%boardCol) * PixelPerRow);
				Y = ((i/boardRow) * PixelPerCol);
				canvas = new Bitmap(PixelPerRow, PixelPerCol);
				for (k = 0; k < PixelPerCol; k++)
				{
					for (j = 0; j < PixelPerRow; j++)
					{
						cl = this.bmpTile.GetPixel(X + j, Y + k);
						canvas.SetPixel(j, k, cl);
					}
				}
				this.imgTile[i] = canvas;
			}
		}
		
		public int GetItemClicked(MouseEventArgs e)
		{
			Point p = new Point(0,0);
			p.X = e.X - pt.X;
			p.Y = e.Y - pt.Y;
			
			if ((p.X < bounds.X) || (p.X > (bounds.X+bounds.Width)))
			{
				return MaxTiles;
			}
			if ((p.Y < bounds.Y) || (p.Y > (bounds.Y+bounds.Height)))
			{
				return MaxTiles;
			}			
			
			for (int i = 0; i < MaxTiles; i++)
			{
				if ((p.X > (bounds.X + (i%boardCol)*cxTile))
					&& (p.X < (bounds.X + ((i%boardCol+1)*cxTile))) && (p.Y > (bounds.Y + (i/boardCol)*cyTile))
					&& (p.Y < (bounds.Y + ((i/boardCol+1)*cyTile))))
				{
					return i;
				}
			}
			return MaxTiles;
		}

		public void MyMove(int iPosFrom)
		{
			int iPosTo;	
		
			for (iPosTo = 0; iPosTo < (boardCol*boardRow); iPosTo++)
			{
				if (boardData[iPosTo] == nBlankTile)
					break;
			}			
			Debug.Assert(iPosTo < (boardCol*boardRow), "iPosTo < (boardCol*boardRow)", "Can't find the blank block in board.");
		
			Move(iPosFrom, iPosTo);
		}		

		
		internal Image[] imgTile;
		
		internal Rectangle bounds;
		
		protected int cxTile;
		protected int cyTile;
		public int TileWidth
		{
			get {return cxTile;}
			set {
			cxTile = value;
			bounds = new Rectangle(0,0,boardCol*cxTile,boardRow*cyTile);
			}
		}
		public int TileHeight
		{
			get {return cyTile;}
			set {
			cyTile = value;
			bounds = new Rectangle(0,0,boardCol*cxTile,boardRow*cyTile);
			}
		}
		public Point TileSize
		{
			get { return new Point(cxTile,cyTile);}
			set {
				Point pt = value;
				cxTile = pt.X;
				cyTile = pt.Y;
				bounds = new Rectangle(0,0,boardCol*cxTile,boardRow*cyTile);
				}
		}

		public int MaxTile
		{
			get {return MaxTiles;}
		}		
	}
}

