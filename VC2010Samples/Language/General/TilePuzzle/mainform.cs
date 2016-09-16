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
	using System.Collections;
	using System.ComponentModel;
	using System.Drawing;
	using System.Windows.Forms;
	using System.Windows.Forms.ComponentModel;
	using System.Threading;
	using System.Diagnostics;
	using System.Runtime.InteropServices;
	using TileDriver;

	enum GameLevelEnum
	{
		Beginner = 1,
		Intermediate = 5,
		Expert = 10
	}

	enum GameToolbarButtonEnum
	{
		Undo = 0,
		Redo = 1,
		Solve = 2,
	}

	enum ImageIndexEnum
	{
		iImgUndo = 0,
		iImgRedo = 1,
		iImgSolve = 2,
	}

	/// <summary>
	///    Summary description for MainForm.
	/// </summary>

	public class MainForm : System.Windows.Forms.Form
	{
		private System.ComponentModel.IContainer components;
		private System.Windows.Forms.ImageList imgToolbar;
		private System.Windows.Forms.StatusBarPanel statusPanel;
		private System.Windows.Forms.StatusBar statusbar;
		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.ToolBarButton tbbtnUndo;
		private System.Windows.Forms.ToolBarButton tbbtnRedo;
		private System.Windows.Forms.ToolBarButton tbbtnSeprt;
		private System.Windows.Forms.ToolBarButton tbbtnSolve;
		private System.Windows.Forms.ToolBar toolbar;
		private System.Windows.Forms.MainMenu mainMenu;
		private System.Windows.Forms.MenuItem mnuGame;
		private System.Windows.Forms.MenuItem mnuNew;
		private System.Windows.Forms.MenuItem mnuLine1;
		private System.Windows.Forms.MenuItem mnuUndo;
		private System.Windows.Forms.MenuItem mnuRedo;
		private System.Windows.Forms.MenuItem mnuSolvePuzzle;
		private System.Windows.Forms.MenuItem mnuLine2;
		private System.Windows.Forms.MenuItem mnuExit;
		private System.Windows.Forms.MenuItem mnuView;
		private System.Windows.Forms.MenuItem mnuViewToolbar;
		private System.Windows.Forms.MenuItem mnuViewStatusbar;
		private System.Windows.Forms.MenuItem mnuOptions;
		private System.Windows.Forms.MenuItem mnuUseImage;
		private System.Windows.Forms.MenuItem mnuChangeImage;
		private System.Windows.Forms.MenuItem mnuLine3;
		private System.Windows.Forms.MenuItem mnuFastPlayBack;
		private System.Windows.Forms.MenuItem mnuAlgType;
		private System.Windows.Forms.MenuItem mnuAlg0;
		private System.Windows.Forms.MenuItem mnuAlg1;
		private System.Windows.Forms.MenuItem mnuAlg2;
		private System.Windows.Forms.MenuItem mnuAlg3;
		private System.Windows.Forms.MenuItem mnuRunAll;
		private System.Windows.Forms.MenuItem mnuSpeed;
		private System.Windows.Forms.MenuItem mnuShort;
		private System.Windows.Forms.MenuItem mnuLine4;
		private System.Windows.Forms.MenuItem mnuGameLevel;
		private System.Windows.Forms.MenuItem mnuLevel0;
		private System.Windows.Forms.MenuItem mnuLevel1;
		private System.Windows.Forms.MenuItem mnuLevel2;
		private System.Windows.Forms.MenuItem mnuBoardSize;
		private System.Windows.Forms.MenuItem mnuBoardSize0;
		private System.Windows.Forms.MenuItem mnuBoardSize1;
		private System.Windows.Forms.MenuItem mnuBoardSize2;
		private System.Windows.Forms.MenuItem mnuBoardSize3;
		private System.Windows.Forms.MenuItem mnuBoardSize4;
		private System.Windows.Forms.MenuItem mnuBoardSize5;
		private System.Windows.Forms.MenuItem mnuBoardSize6;
		private System.Windows.Forms.MenuItem mnuLine5;
		private System.Windows.Forms.MenuItem mnuFitToWindow;
		private System.Windows.Forms.MenuItem mnuHelp;
		private System.Windows.Forms.MenuItem mnuAbout;

		int	iThreadParam0 = 0;
		int iThreadParam1 = 0;
		private PuzzleBoard MainBoard;
		private GameLevelEnum nDifficulty;
		private Thread SolvingThread;
		private Driver m_Driver;
		private int nPlayBackSpeed = 500;
		private int AlgType;
		private int[] rgSolveSteps;
		private string sBackgroundPic;
		private object[] rgThreadParams;
		private bool fGameFinished;
		private bool fFitToWindow = true;
		private bool fSolveFinished = true;
		private bool fThreadRunning = false;
		private static bool fSelfTest = false;
		private static readonly string filter = "Tile Puzzle Files (*.tpz)|*.tpz|All Files (*.*)|*.*";

		public MainForm()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializedComponent call
			//

			fGameFinished = true;
			nDifficulty = GameLevelEnum.Beginner;	// Easiest level

			try {
				m_Driver = new TileDriver.Driver();
			}
			catch(Exception e) {
				Console.WriteLine("MainForm.MainForm() : Caught exception while instantiating TileDriver object.");
				Console.WriteLine((e.Message).ToString());
			}
			
			Debug.Assert(m_Driver != null, "m_Driver != null", "Cannot create 'Driver' object!");

			
			//
			// Init board
			//
			//
			MainBoard = new PuzzleBoard(this);
			int[] rgGoal = new int[MainBoard.MaxTile];
			for (int i = 0; i < MainBoard.MaxTile; i++)
				rgGoal[i] = i+1;
			rgGoal[MainBoard.MaxTile-1] = 0;
			MainBoard.InitTile(rgGoal,false);

			this.UpdateLevelMenu();
			this.UpdateBoardSizeMenu(3,3);
			this.UpdateAlgMenu(3);
			this.UpdateStatusPanel();
			this.UpdateToolbarButton();
			this.AlgType = 3;
			this.On_ReSize(null,null);

			// Load a default image
			mnuUseImage.Checked = true;
			mnuChangeImage.Enabled = true;
			this.sBackgroundPic = "ImageFromEmbedResource";
			MainBoard.ChangeImage();

			if(fSelfTest) {
				OnNewGame(this, new EventArgs());
				Thread.Sleep(10);
				OnSolve(this, new EventArgs());
			}
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
			this.components = new System.ComponentModel.Container();
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(MainForm));
			this.mnuAlg3 = new System.Windows.Forms.MenuItem();
			this.mnuAlg0 = new System.Windows.Forms.MenuItem();
			this.mnuAlg1 = new System.Windows.Forms.MenuItem();
			this.mnuAlgType = new System.Windows.Forms.MenuItem();
			this.mnuAlg2 = new System.Windows.Forms.MenuItem();
			this.mnuRunAll = new System.Windows.Forms.MenuItem();
			this.mnuSpeed = new System.Windows.Forms.MenuItem();
			this.mnuShort = new System.Windows.Forms.MenuItem();
			this.mnuViewStatusbar = new System.Windows.Forms.MenuItem();
			this.mnuRedo = new System.Windows.Forms.MenuItem();
			this.mnuFastPlayBack = new System.Windows.Forms.MenuItem();
			this.tbbtnSolve = new System.Windows.Forms.ToolBarButton();
			this.tbbtnUndo = new System.Windows.Forms.ToolBarButton();
			this.mnuView = new System.Windows.Forms.MenuItem();
			this.mnuViewToolbar = new System.Windows.Forms.MenuItem();
			this.imgToolbar = new System.Windows.Forms.ImageList(this.components);
			this.mnuExit = new System.Windows.Forms.MenuItem();
			this.mnuOptions = new System.Windows.Forms.MenuItem();
			this.mnuUseImage = new System.Windows.Forms.MenuItem();
			this.mnuChangeImage = new System.Windows.Forms.MenuItem();
			this.mnuLine3 = new System.Windows.Forms.MenuItem();
			this.mnuLine4 = new System.Windows.Forms.MenuItem();
			this.mnuGameLevel = new System.Windows.Forms.MenuItem();
			this.mnuLevel0 = new System.Windows.Forms.MenuItem();
			this.mnuLevel1 = new System.Windows.Forms.MenuItem();
			this.mnuLevel2 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize0 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize1 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize2 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize3 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize4 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize5 = new System.Windows.Forms.MenuItem();
			this.mnuBoardSize6 = new System.Windows.Forms.MenuItem();
			this.mnuLine5 = new System.Windows.Forms.MenuItem();
			this.mnuFitToWindow = new System.Windows.Forms.MenuItem();
			this.mnuNew = new System.Windows.Forms.MenuItem();
			this.mnuGame = new System.Windows.Forms.MenuItem();
			this.mnuLine1 = new System.Windows.Forms.MenuItem();
			this.mnuUndo = new System.Windows.Forms.MenuItem();
			this.mnuSolvePuzzle = new System.Windows.Forms.MenuItem();
			this.mnuLine2 = new System.Windows.Forms.MenuItem();
			this.mnuHelp = new System.Windows.Forms.MenuItem();
			this.mnuAbout = new System.Windows.Forms.MenuItem();
			this.statusbar = new System.Windows.Forms.StatusBar();
			this.statusPanel = new System.Windows.Forms.StatusBarPanel();
			this.mainMenu = new System.Windows.Forms.MainMenu();
			this.tbbtnRedo = new System.Windows.Forms.ToolBarButton();
			this.tbbtnSeprt = new System.Windows.Forms.ToolBarButton();
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.toolbar = new System.Windows.Forms.ToolBar();
			((System.ComponentModel.ISupportInitialize)(this.statusPanel)).BeginInit();
			this.SuspendLayout();
			// 
			// mnuAlg3
			// 
			this.mnuAlg3.Index = 3;
			this.mnuAlg3.Text = "A*&2 Heuristic";
			this.mnuAlg3.Click += new System.EventHandler(this.OnAlg3);
			// 
			// mnuAlg0
			// 
			this.mnuAlg0.Index = 0;
			this.mnuAlg0.Text = "&Breadth First Search";
			this.mnuAlg0.Click += new System.EventHandler(this.OnAlg0);
			// 
			// mnuAlg1
			// 
			this.mnuAlg1.Index = 1;
			this.mnuAlg1.Text = "&Depth First Search";
			this.mnuAlg1.Click += new System.EventHandler(this.OnAlg1);
			// 
			// mnuAlgType
			// 
			this.mnuAlgType.Index = 4;
			this.mnuAlgType.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					   this.mnuAlg0,
																					   this.mnuAlg1,
																					   this.mnuAlg2,
																					   this.mnuAlg3,
																					   this.mnuRunAll});
			this.mnuAlgType.Text = "&Algorithm Type";
			// 
			// mnuAlg2
			// 
			this.mnuAlg2.Index = 2;
			this.mnuAlg2.Text = "A*&1 Heuristic";
			this.mnuAlg2.Click += new System.EventHandler(this.OnAlg2);
			// 
			// mnuRunAll
			// 
			this.mnuRunAll.Enabled = false;
			this.mnuRunAll.Index = 4;
			this.mnuRunAll.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.mnuSpeed,
																					  this.mnuShort});
			this.mnuRunAll.Text = "&Run all concurrently";
			// 
			// mnuSpeed
			// 
			this.mnuSpeed.Index = 0;
			this.mnuSpeed.Text = "Favor &algorithm speed";
			this.mnuSpeed.Click += new System.EventHandler(this.OnAlgSpeed);
			// 
			// mnuShort
			// 
			this.mnuShort.Index = 1;
			this.mnuShort.Text = "Favor &shorter solution (slow)";
			this.mnuShort.Click += new System.EventHandler(this.OnAlgShort);
			// 
			// mnuViewStatusbar
			// 
			this.mnuViewStatusbar.Checked = true;
			this.mnuViewStatusbar.Index = 1;
			this.mnuViewStatusbar.Text = "&Status bar";
			this.mnuViewStatusbar.Click += new System.EventHandler(this.OnViewStatusBar);
			// 
			// mnuRedo
			// 
			this.mnuRedo.Index = 3;
			this.mnuRedo.Shortcut = System.Windows.Forms.Shortcut.CtrlY;
			this.mnuRedo.Text = "&Redo";
			this.mnuRedo.Click += new System.EventHandler(this.OnRedoMove);
			// 
			// mnuFastPlayBack
			// 
			this.mnuFastPlayBack.Index = 3;
			this.mnuFastPlayBack.Text = "&Fast Solve Animation";
			this.mnuFastPlayBack.Click += new System.EventHandler(this.OnFastPlayBack);
			// 
			// tbbtnSolve
			// 
			this.tbbtnSolve.ImageIndex = 2;
			this.tbbtnSolve.ToolTipText = "Solve Puzzle";
			// 
			// tbbtnUndo
			// 
			this.tbbtnUndo.ImageIndex = 0;
			this.tbbtnUndo.ToolTipText = "Undo Move";
			// 
			// mnuView
			// 
			this.mnuView.Index = 1;
			this.mnuView.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					this.mnuViewToolbar,
																					this.mnuViewStatusbar});
			this.mnuView.Text = "&View";
			// 
			// mnuViewToolbar
			// 
			this.mnuViewToolbar.Checked = true;
			this.mnuViewToolbar.Index = 0;
			this.mnuViewToolbar.Text = "&Toolbar";
			this.mnuViewToolbar.Click += new System.EventHandler(this.OnViewToolBar);
			// 
			// imgToolbar
			// 
			this.imgToolbar.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
			this.imgToolbar.ImageSize = new System.Drawing.Size(24, 22);
			this.imgToolbar.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imgToolbar.ImageStream")));
			this.imgToolbar.TransparentColor = System.Drawing.Color.Magenta;
			// 
			// mnuExit
			// 
			this.mnuExit.Index = 6;
			this.mnuExit.Shortcut = System.Windows.Forms.Shortcut.AltF4;
			this.mnuExit.Text = "E&xit";
			this.mnuExit.Click += new System.EventHandler(this.OnExitGame);
			// 
			// mnuOptions
			// 
			this.mnuOptions.Index = 2;
			this.mnuOptions.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					   this.mnuUseImage,
																					   this.mnuChangeImage,
																					   this.mnuLine3,
																					   this.mnuFastPlayBack,
																					   this.mnuAlgType,
																					   this.mnuLine4,
																					   this.mnuGameLevel,
																					   this.mnuBoardSize});
			this.mnuOptions.Text = "&Options";
			// 
			// mnuUseImage
			// 
			this.mnuUseImage.Index = 0;
			this.mnuUseImage.Text = "&Use Image";
			this.mnuUseImage.Click += new System.EventHandler(this.OnUseImage);
			// 
			// mnuChangeImage
			// 
			this.mnuChangeImage.Enabled = false;
			this.mnuChangeImage.Index = 1;
			this.mnuChangeImage.Text = "&Change Image";
			this.mnuChangeImage.Click += new System.EventHandler(this.OnChangeImage);
			// 
			// mnuLine3
			// 
			this.mnuLine3.Index = 2;
			this.mnuLine3.Text = "-";
			// 
			// mnuLine4
			// 
			this.mnuLine4.Index = 5;
			this.mnuLine4.Text = "-";
			// 
			// mnuGameLevel
			// 
			this.mnuGameLevel.Index = 6;
			this.mnuGameLevel.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																						 this.mnuLevel0,
																						 this.mnuLevel1,
																						 this.mnuLevel2});
			this.mnuGameLevel.Text = "Game &Level";
			// 
			// mnuLevel0
			// 
			this.mnuLevel0.Index = 0;
			this.mnuLevel0.Text = "&Beginner";
			this.mnuLevel0.Click += new System.EventHandler(this.OnLevelBeginner);
			// 
			// mnuLevel1
			// 
			this.mnuLevel1.Index = 1;
			this.mnuLevel1.Text = "&Intermediate";
			this.mnuLevel1.Click += new System.EventHandler(this.OnLevelIntermediate);
			// 
			// mnuLevel2
			// 
			this.mnuLevel2.Index = 2;
			this.mnuLevel2.Text = "&Expert";
			this.mnuLevel2.Click += new System.EventHandler(this.OnLevelExpert);
			// 
			// mnuBoardSize
			// 
			this.mnuBoardSize.Index = 7;
			this.mnuBoardSize.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																						 this.mnuBoardSize0,
																						 this.mnuBoardSize1,
																						 this.mnuBoardSize2,
																						 this.mnuBoardSize3,
																						 this.mnuBoardSize4,
																						 this.mnuBoardSize5,
																						 this.mnuBoardSize6,
																						 this.mnuLine5,
																						 this.mnuFitToWindow});
			this.mnuBoardSize.Text = "&Board Size";
			// 
			// mnuBoardSize0
			// 
			this.mnuBoardSize0.Index = 0;
			this.mnuBoardSize0.Text = "&3x3";
			this.mnuBoardSize0.Click += new System.EventHandler(this.OnBoardSize3x3);
			// 
			// mnuBoardSize1
			// 
			this.mnuBoardSize1.Index = 1;
			this.mnuBoardSize1.Text = "&4x4";
			this.mnuBoardSize1.Click += new System.EventHandler(this.OnBoardSize4x4);
			// 
			// mnuBoardSize2
			// 
			this.mnuBoardSize2.Index = 2;
			this.mnuBoardSize2.Text = "&5x5";
			this.mnuBoardSize2.Click += new System.EventHandler(this.OnBoardSize5x5);
			// 
			// mnuBoardSize3
			// 
			this.mnuBoardSize3.Index = 3;
			this.mnuBoardSize3.Text = "&6x6";
			this.mnuBoardSize3.Click += new System.EventHandler(this.OnBoardSize6x6);
			// 
			// mnuBoardSize4
			// 
			this.mnuBoardSize4.Index = 4;
			this.mnuBoardSize4.Text = "&7x7";
			this.mnuBoardSize4.Click += new System.EventHandler(this.OnBoardSize7x7);
			// 
			// mnuBoardSize5
			// 
			this.mnuBoardSize5.Index = 5;
			this.mnuBoardSize5.Text = "&8x8";
			this.mnuBoardSize5.Click += new System.EventHandler(this.OnBoardSize8x8);
			// 
			// mnuBoardSize6
			// 
			this.mnuBoardSize6.Enabled = false;
			this.mnuBoardSize6.Index = 6;
			this.mnuBoardSize6.Text = "&Customize...";
			this.mnuBoardSize6.Click += new System.EventHandler(this.OnBoardSizeCustomize);
			// 
			// mnuLine5
			// 
			this.mnuLine5.Index = 7;
			this.mnuLine5.Text = "-";
			// 
			// mnuFitToWindow
			// 
			this.mnuFitToWindow.Checked = true;
			this.mnuFitToWindow.Index = 8;
			this.mnuFitToWindow.Text = "&Fit To Window";
			this.mnuFitToWindow.Click += new System.EventHandler(this.OnFitToWindow);
			// 
			// mnuNew
			// 
			this.mnuNew.Index = 0;
			this.mnuNew.Shortcut = System.Windows.Forms.Shortcut.F2;
			this.mnuNew.Text = "&New";
			this.mnuNew.Click += new System.EventHandler(this.OnNewGame);
			// 
			// mnuGame
			// 
			this.mnuGame.Index = 0;
			this.mnuGame.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					this.mnuNew,
																					this.mnuLine1,
																					this.mnuUndo,
																					this.mnuRedo,
																					this.mnuSolvePuzzle,
																					this.mnuLine2,
																					this.mnuExit});
			this.mnuGame.Text = "&Game";
			// 
			// mnuLine1
			// 
			this.mnuLine1.Index = 1;
			this.mnuLine1.Text = "-";
			// 
			// mnuUndo
			// 
			this.mnuUndo.Index = 2;
			this.mnuUndo.Shortcut = System.Windows.Forms.Shortcut.CtrlZ;
			this.mnuUndo.Text = "&Undo";
			this.mnuUndo.Click += new System.EventHandler(this.OnUndoMove);
			// 
			// mnuSolvePuzzle
			// 
			this.mnuSolvePuzzle.Index = 4;
			this.mnuSolvePuzzle.Text = "Sol&ve Puzzle";
			this.mnuSolvePuzzle.Click += new System.EventHandler(this.OnSolve);
			// 
			// mnuLine2
			// 
			this.mnuLine2.Index = 5;
			this.mnuLine2.Text = "-";
			// 
			// mnuHelp
			// 
			this.mnuHelp.Index = 3;
			this.mnuHelp.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					this.mnuAbout});
			this.mnuHelp.Text = "&Help";
			// 
			// mnuAbout
			// 
			this.mnuAbout.Index = 0;
			this.mnuAbout.Text = "&About...";
			this.mnuAbout.Click += new System.EventHandler(this.OnAbout);
			// 
			// statusbar
			// 
			this.statusbar.Location = new System.Drawing.Point(0, 233);
			this.statusbar.Name = "statusbar";
			this.statusbar.Panels.AddRange(new System.Windows.Forms.StatusBarPanel[] {
																						 this.statusPanel});
			this.statusbar.ShowPanels = true;
			this.statusbar.Size = new System.Drawing.Size(292, 20);
			this.statusbar.TabIndex = 1;
			this.statusbar.Text = "statusbar";
			// 
			// statusPanel
			// 
			this.statusPanel.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Spring;
			this.statusPanel.Text = "Initializing...";
			this.statusPanel.Width = 276;
			// 
			// mainMenu
			// 
			this.mainMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					 this.mnuGame,
																					 this.mnuView,
																					 this.mnuOptions,
																					 this.mnuHelp});
			// 
			// tbbtnRedo
			// 
			this.tbbtnRedo.ImageIndex = 1;
			this.tbbtnRedo.ToolTipText = "Redo Move";
			// 
			// tbbtnSeprt
			// 
			this.tbbtnSeprt.Style = System.Windows.Forms.ToolBarButtonStyle.Separator;
			// 
			// pictureBox1
			// 
			this.pictureBox1.Image = ((System.Drawing.Bitmap)(resources.GetObject("pictureBox1.Image")));
			this.pictureBox1.Location = new System.Drawing.Point(88, 56);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(0, 0);
			this.pictureBox1.TabIndex = 0;
			this.pictureBox1.TabStop = false;
			// 
			// toolbar
			// 
			this.toolbar.Buttons.AddRange(new System.Windows.Forms.ToolBarButton[] {
																					   this.tbbtnUndo,
																					   this.tbbtnRedo,
																					   this.tbbtnSeprt,
																					   this.tbbtnSolve});
			this.toolbar.ButtonSize = new System.Drawing.Size(24, 22);
			this.toolbar.DropDownArrows = true;
			this.toolbar.ImageList = this.imgToolbar;
			this.toolbar.Name = "toolbar";
			this.toolbar.ShowToolTips = true;
			this.toolbar.Size = new System.Drawing.Size(292, 31);
			this.toolbar.TabIndex = 0;
			this.toolbar.ButtonClick += new System.Windows.Forms.ToolBarButtonClickEventHandler(this.OnToolBarButtonClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.Size(5, 13);
			this.BackColor = System.Drawing.Color.Green;
			this.ClientSize = new System.Drawing.Size(292, 253);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.toolbar,
																		  this.statusbar});
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Menu = this.mainMenu;
			this.Name = "MainForm";
			this.Text = "Tile Puzzle 1.0";
			this.Resize += new System.EventHandler(this.On_ReSize);
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.On_MouseDown);
			this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.On_KeyUp);
			this.Paint += new System.Windows.Forms.PaintEventHandler(this.On_Paint);
			((System.ComponentModel.ISupportInitialize)(this.statusPanel)).EndInit();
			this.ResumeLayout(false);

		}
		#endregion
	    
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		public static void Main(string[] args)
		{
			if( (args.Length > 0) && args[0].Equals("selftest")) 
			{
				Console.WriteLine("Running selftest...");
				MainForm.fSelfTest = true;
				Application.Run(new MainForm());
			}
			else
				Application.Run(new MainForm());
		}
	 
		//
		// Event handler
		//
		private void NYI(object sender, EventArgs e)
		{
			MessageBox.Show("Not implemented",this.Text);
		}
		
		private void OnNewGame(object sender, EventArgs e)
		{
			// Do not allow the user to click anything when they play back the solution
			if (fThreadRunning)
				return;

			if (fGameFinished ||
				(DialogResult.Yes == MessageBox.Show("Do you want to resign this game?", this.Text, MessageBoxButtons.YesNo, MessageBoxIcon.Question)))
			{
				NewGameHelper();
			}
		}
		
		private void NewGameHelper()
		{
			//
			// Generate new game
			//
			int[] rgInit;
		
			try
			{
				statusPanel.Text = "Creating new random board";
				rgInit = m_Driver.NewGame(MainBoard.Row, MainBoard.Col,(int)this.nDifficulty);
				statusPanel.Text = "Ready";
				this.fGameFinished = false;
			}
			catch (Exception e)
			{
				Console.WriteLine("Mainform.NewGameHelper() -- Unknown exception in NewGameHelper()!!!\n"+e.ToString());
				
				rgInit = new int[MainBoard.MaxTile];
				for (int i = 0; i < (MainBoard.MaxTile-1); i++)
				{
					rgInit[i] = i+1;
				}
				rgInit[MainBoard.MaxTile-1] = 0;
				this.fGameFinished = true;
			}
			//
			// Update Menu & Toolbar
			//
			UpdateToolbarButton();
			
			//
			// Update board
			//
	#if _DEBUG
			{
				Console.Write("Generated Board: ");
				for (int i = 0; i < MainBoard.MaxTile; i++)
				{
					Console.Write(rgInit[i].ToString());
				}
				Console.WriteLine(" ");
			}
	#endif // _DEBUG
			MainBoard.InitTile(rgInit, true);
			UpdateStatusPanel();

			this.On_ReSize(null,null);
		}
		
		private void OnLoadGame(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			OpenFileDialog fd = new OpenFileDialog();
			fd.Filter = filter;
			
			if (fd.ShowDialog() == DialogResult.OK)
			{
				// TODO: Pass selected file name to MCPP, get initial state, draw board
			}
		}
		
		private void OnSaveGame(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			SaveFileDialog fd = new SaveFileDialog();
			fd.Filter = filter;
			
			if (fd.ShowDialog() == DialogResult.OK)
			{
				// TODO: Pass selected file name to MCPP, then continue the game.
			}
		}
		
		private void EnableUndo(bool fEnabled)
		{
			if (tbbtnUndo.Enabled != fEnabled)
			{
				tbbtnUndo.Enabled = fEnabled;
				mnuUndo.Enabled = fEnabled;
			}
		}
		
		private void EnableRedo(bool fEnabled)
		{
			if (tbbtnRedo.Enabled != fEnabled)
			{
				tbbtnRedo.Enabled = fEnabled;
				mnuRedo.Enabled = fEnabled;
			}
		}
		
		private void EnableSolve(bool fEnabled)
		{
			if  (tbbtnSolve.Enabled != fEnabled)
			{
				tbbtnSolve.Enabled = fEnabled;
				mnuSolvePuzzle.Enabled = fEnabled;
			}
		}
		
		private void OnUndoMove(object sender, EventArgs e)
		{
			try {
				Debug.Assert(m_Driver != null,"m_Driver == null", "Cannot create 'Driver' object!");
				int[] rgTemp;
				rgTemp = m_Driver.UndoMove();
	#if _DEBUG
				Console.WriteLine("OnUndoMove called\nDriver returned:"+rgTemp[0].ToString()+","+
					rgTemp[1].ToString()+","+rgTemp[2].ToString()+","+rgTemp[3].ToString());
	#endif // _DEBUG
				if(rgTemp[0] != 4)
				{
					MainBoard.Move(rgTemp[1],rgTemp[2]);
				}
				// Update Menu & Toolbar
				EnableUndo(m_Driver.CanUndo());
				EnableRedo(m_Driver.CanRedo());
			}
			catch (Exception e2)
			{
				Console.WriteLine("Unknown exception in OnUndoMove()!");
				Console.WriteLine(e2.ToString());
			}
		}
			
		
		private void OnRedoMove(object sender, EventArgs e)
		{
			Debug.Assert(m_Driver != null,"m_Driver == null", "Cannot create 'Driver' object!");
			int[] rgTemp;
			rgTemp = m_Driver.RedoMove();
	#if _DEBUG
			Console.WriteLine("OnRedoMove called\nDriver returned:"+rgTemp[0].ToString()+","+
				rgTemp[1].ToString()+","+rgTemp[2].ToString()+","+rgTemp[3].ToString());
	#endif // _DEBUG
			if(rgTemp[0] != 4)
			{
				MainBoard.Move(rgTemp[1],rgTemp[2]);
			}
			// Update Menu & Toolbar
			EnableUndo(m_Driver.CanUndo());
			EnableRedo(m_Driver.CanRedo());
		}

		private void OnExitGame(object sender, EventArgs e)
		{
			this.Close();
		}
		
		private void OnAbout(object sender, EventArgs e)
		{
			AboutForm af = new AboutForm();
			af.ShowDialog(this);
			af.Dispose();
		}
		
		private void OnViewStatusBar(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			mnuViewStatusbar.Checked = !mnuViewStatusbar.Checked;
			this.statusbar.Visible = mnuViewStatusbar.Checked;
			this.On_ReSize(null,null);
		}

		private void OnViewToolBar(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			mnuViewToolbar.Checked = !mnuViewToolbar.Checked;
			toolbar.Visible = mnuViewToolbar.Checked;
			this.On_ReSize(null,null);
		}

		private void OnUseImage(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			mnuUseImage.Checked = !mnuUseImage.Checked;
			if (!mnuUseImage.Checked)
			{
				MainBoard.ChangeImage(null);
				mnuChangeImage.Enabled = false;
			}
			else
			{
				mnuChangeImage.Enabled = true;
				if(this.sBackgroundPic.Equals("ImageFromEmbedResource"))
				{
					MainBoard.ChangeImage();
				}
				else 
				{
					MainBoard.ChangeImage(this.sBackgroundPic);	
				}
			}
		}

		private void OnChangeImage(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			OpenFileDialog fd = new OpenFileDialog();
			fd.Filter = "Bitmap Files|*.bmp";
			
			if (fd.ShowDialog() == DialogResult.OK)
			{
				this.sBackgroundPic = fd.FileName;
				MainBoard.ChangeImage(fd.FileName);
			}
		}

		private void OnBoardSize3x3(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeHelper(3,3);
		}

		private void OnBoardSize4x4(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeHelper(4,4);
		}

		private void OnBoardSize5x5(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeHelper(5,5);
		}

		private void OnBoardSize6x6(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeHelper(6,6);
		}

		private void OnBoardSize7x7(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeHelper(7,7);
		}

		private void OnBoardSize8x8(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeHelper(8,8);
		}
		
		private void OnAlg0(object sender, EventArgs e)
		{
			AlgType = 0;
			UpdateAlgMenu(0);
		}
		private void OnAlg1(object sender, EventArgs e)
		{
			AlgType = 1;
			UpdateAlgMenu(1);
		}
		private void OnAlg2(object sender, EventArgs e)
		{
			AlgType = 2;
			UpdateAlgMenu(2);
		}
		private void OnAlg3(object sender, EventArgs e)
		{
			AlgType = 3;
			UpdateAlgMenu(3);
		}
		private void OnAlgSpeed(object sender, EventArgs e)
		{
			AlgType = 4;
			UpdateAlgMenu(4);
		}
		private void OnAlgShort(object sender, EventArgs e)
		{
			AlgType = 5;
			UpdateAlgMenu(5);
		}

		private void OnFitToWindow(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			fFitToWindow = mnuFitToWindow.Checked = !mnuFitToWindow.Checked;
			this.On_ReSize(null,null);
		}
		
		private void OnBoardSizeCustomize(object sender, EventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			BoardSizeForm bd = new BoardSizeForm();
			bd.Row = MainBoard.Row;
			bd.Col = MainBoard.Col;
			
			if (DialogResult.OK == bd.ShowDialog(this))
			{
				if ((bd.Row != MainBoard.Row) || (bd.Col != MainBoard.Col))
				{
	#if _DEBUG
					Console.WriteLine("User select: "+bd.Col.ToString()+"x"+bd.Row.ToString());
	#endif // _DEBUG
					BoardSizeHelper(bd.Row,bd.Col);
				}
			}
			bd.Dispose();
		}
		
		private void BoardSizeHelper(int row, int col)
		{
			if (DialogResult.Yes == MessageBox.Show("Do you want to resign this game?",this.Text,MessageBoxButtons.YesNo))
			{
				MainBoard.setSize(row,col);
				UpdateBoardSizeMenu(row, col);
				NewGameHelper();
			}
		}

		//
		// ToolBar Event Handler
		//
		private void OnToolBarButtonClick(object sender, ToolBarButtonClickEventArgs e)
		{
	#if _DEBUG
			Console.WriteLine("OnToolBarButtonClick");
	#endif //_DEBUG
			if (e.Button == tbbtnUndo)
			{
	#if _DEBUG
				Console.WriteLine("- Clicked Undo");
	#endif // _DEBUG
				this.OnUndoMove(sender,null);
			}
			else if (e.Button == tbbtnRedo)
			{
	#if _DEBUG
				Console.WriteLine("- Clicked Redo");
	#endif // _DEBUG
				this.OnRedoMove(sender,null);
			}
			else if (e.Button == tbbtnSolve)
			{
	#if _DEBUG
				Console.WriteLine("Solve Button:OnButtonClickEvent");
	#endif // _DEBUG
				SolvePuzzle();
			}
		}

		private void OnSolve(object sender, EventArgs e)
		{
			SolvePuzzle();
		}

		private void SolvePuzzle()
		{
			if (fThreadRunning)
			{
				// Driver::Solve is running, then safe to kill thread
				if (!fSolveFinished)
				{
					fThreadRunning = false;
					m_Driver.CancelSolve();
				}
	#if _DEBUG
				Console.WriteLine("Cancel Thread");
	#endif // _DEBUG
				// Cancel Thread
				fThreadRunning = false;

				// Enable other menus/button
				tbbtnUndo.Enabled = true;
				tbbtnRedo.Enabled = true;
				tbbtnSolve.Pushed = false;
				mnuSolvePuzzle.Text = "Sol&ve Puzzle";
				UpdateStatusPanel();
			}
			else
			{
				this.rgThreadParams = new object[]
				{
					this.iThreadParam0,
					this.iThreadParam1
				};
				try
				{
					// Update all toolbar buttons
					tbbtnUndo.Enabled = false;
					mnuUndo.Enabled = false;
					tbbtnRedo.Enabled = false;
					mnuRedo.Enabled = false;
					tbbtnSolve.Pushed = true;
					mnuSolvePuzzle.Text = "Stop Sol&ving";

					SolvingThread = new Thread( new ThreadStart(this.SolvingThreadProc) );

					if (SolvingThread != null)
					{
						SolvingThread.Priority = ThreadPriority.Lowest;
						SolvingThread.Start();
	#if _DEBUG
						Console.WriteLine("Thread Background? :" + SolvingThread.IsBackground.ToString());
	#endif // _DEBUG
					}
				}
				catch(Exception e)
				{
					Console.WriteLine(e.ToString());
				}
			}
		}

		private void SolvingThreadProc()
		{
			try
			{
				int i =0;

	#if _DEBUG
				Console.WriteLine("SolveThread Created!");
				Console.WriteLine("====================");
	#endif // _DEBUG

				fSolveFinished = false;
				fThreadRunning = true;

				// Call MCPP to get SolveSteps and number of solve steps,
				// then playback solve steps
				int[] rgInit=new int[MainBoard.MaxTile];
				int[] rgGoal=new int[MainBoard.MaxTile];

				for (i = 0; i < (MainBoard.MaxTile); i++)
					{
						rgInit[i] = MainBoard.boardData[i];
						rgGoal[i] = (i+1)%MainBoard.MaxTile;
					}

				// This is true when user clicks cancel solve before IP gets here!
				if (!fThreadRunning)
					return;

				statusPanel.Text = "Finding the solution, please wait... (click on solve button again to abort)";
				rgSolveSteps = m_Driver.Solve(ref AlgType);
				statusPanel.Text = "Ready";
				fSolveFinished = true;
				Thread.Sleep(50);
				String[] AlgName = new String[5] {
					"Breadth first","Depth first","A*1 Heuristic","A*2 Heuristic",""
				};
				statusPanel.Text = AlgName[AlgType] + " found solution in " + rgSolveSteps[0].ToString() + " step(s)";
			
				for (i = 1; fThreadRunning && (i <= rgSolveSteps[0]); i++)
				{
					lock(this.MainBoard)
					{
						int[] rgRet;

						rgRet = m_Driver.MoveByDirection(rgSolveSteps[i]);

						if (rgRet[0] != 4)
						{
							MainBoard.Move(rgRet[1],rgRet[2]);
							if (rgRet[3] == 1)
							{
								// Game finished
								fGameFinished = true;
								OnGameFinished();
								fThreadRunning = false;
							}
						}
						else
						{
							//
							// Error! stop playback
							//
							fThreadRunning = false;
						}
					}
					Thread.Sleep(this.nPlayBackSpeed);
				}			
				
				// Stop Solving
				statusPanel.Text = "Ready";
				toolbar.Invoke(new MethodInvoker(this.tbPosSolveProc));
				UpdateStatusPanel();
				Thread.Sleep(1000);
				
	#if _DEBUG
				Console.WriteLine("End Thread");
	#endif // _DEBUG
				fThreadRunning = false;

			}
			catch (ThreadInterruptedException e)
			{
				Console.WriteLine("Thread stop by exception!\n\t::"+e.ToString());
			}
			catch (Exception e2)
			{
				toolbar.Invoke(new MethodInvoker(this.tbPosSolveProc));
				Console.WriteLine("Got another exception!\n\t"+e2.ToString());
			}
		}

		private void tbPreSolveProc()
		{
			tbbtnSolve.Pushed = true;
			tbbtnUndo.Enabled = false;
			mnuUndo.Enabled = false;
			tbbtnRedo.Enabled = false;
			mnuRedo.Enabled = false;
		}

		private void tbPosSolveProc()
		{
			tbbtnSolve.Pushed = false;
			tbbtnUndo.Enabled = false;
			mnuUndo.Enabled = false;
			tbbtnRedo.Enabled = false;
			mnuRedo.Enabled = false;
			
			// Disable Solve button & menu if game is finished
			if (fGameFinished)
			{
				tbbtnSolve.Enabled = false;
				mnuSolvePuzzle.Enabled = false;
			}
			UpdateStatusPanel();
			mnuSolvePuzzle.Text = "Sol&ve Puzzle";

			if(fSelfTest) OnExitGame(this, new EventArgs());
		}

		//
		// Paint Event Handler
		//
		private void On_Paint(object sender, PaintEventArgs e)
		{
			if (MainBoard != null)
				MainBoard.RedrawBoard(e.Graphics);
		}

		private void On_ReSize(object sender, EventArgs e)
		{
			Rectangle rc;
		
			rc = this.ClientRectangle;
			
			if (toolbar.Visible)
			{
				rc.Y += toolbar.Height;
				rc.Height -= toolbar.Height;
			}
		
			if (this.statusbar.Visible)
				rc.Height -= this.statusbar.Height;
			
			if (fFitToWindow)
			{
				int cxTile = Math.Min((rc.Height-2) / MainBoard.Row, (rc.Width-2) / MainBoard.Col);
				MainBoard.TileSize = new Point(cxTile,cxTile);
			}

			MainBoard.RePosition(rc);
		}

		private void OnGameFinished()
		{
			if (!fThreadRunning)
			{
				if (DialogResult.Yes == MessageBox.Show("Congratulation, YOU WIN!\n\nDo you want to start a new game?",this.Text,MessageBoxButtons.YesNo, MessageBoxIcon.Question))
				{
					NewGameHelper();
				}
				else
				{
					UpdateStatusPanel();
				}
			}
			else
			{
				if(!fSelfTest) MessageBox.Show("Congratulation, YOU WIN!",this.Text);
				UpdateStatusPanel();
			}
		}	

		private void On_MouseDown(object sender, MouseEventArgs e)
		{
			// Not allow user to click anything when play back the solution
			if (fThreadRunning)
				return;

			if (!this.fGameFinished)
			{
				try{
					int iPosition = MainBoard.GetItemClicked(e);
					if (iPosition == MainBoard.MaxTile)	// invalid entry, not clicking at the tiles.
						return;
					
					int[] rgMoveInfo = m_Driver.MoveByPosition(iPosition);
					
					if (rgMoveInfo[0] != 4)
					{
						MainBoard.Move(rgMoveInfo[1],rgMoveInfo[2]);
						EnableUndo(m_Driver.CanUndo());
						EnableRedo(m_Driver.CanRedo());
						if (rgMoveInfo[3] == 1)
						{
							// Game finish
							fGameFinished = true;
							this.OnGameFinished();
						}
					}
					else
					{
						NativeMethods.MessageBeep(0);
						String old = statusPanel.Text;
						statusPanel.Text = "Cannot move this tile";
						Thread.Sleep(800);
						statusPanel.Text = old;
					}
				}
				catch (Exception e2)
				{
					Console.WriteLine("Unknown exception in OnMouseDown()");
					Console.WriteLine(e2.ToString());
				}
			}
			else
			{
				NewGameHelper();
			}
		}

		private void OnLevelBeginner(object sender, EventArgs e)
		{
			LevelChangeHelper(GameLevelEnum.Beginner);
		}
		private void OnLevelIntermediate(object sender, EventArgs e)
		{
			LevelChangeHelper(GameLevelEnum.Intermediate);
		}
		private void OnLevelExpert(object sender, EventArgs e)
		{
			LevelChangeHelper(GameLevelEnum.Expert);
		}
		private void UpdateLevelMenu()
		{
			mnuLevel0.Checked = false;
			mnuLevel1.Checked = false;
			mnuLevel2.Checked = false;
			
			switch (this.nDifficulty)
			{
			case GameLevelEnum.Beginner:
				mnuSolvePuzzle.Enabled = true;
				if (tbbtnSolve != null)
					tbbtnSolve.Enabled = true;
				mnuLevel0.Checked = true;
				break;
			case GameLevelEnum.Intermediate:
				mnuSolvePuzzle.Enabled = true;
				if (tbbtnSolve != null)
					tbbtnSolve.Enabled = true;
				mnuLevel1.Checked = true;
				break;
			case GameLevelEnum.Expert:
				mnuSolvePuzzle.Enabled = false;
				if (tbbtnSolve != null)
					tbbtnSolve.Enabled = false;
				mnuLevel2.Checked = true;
				break;
			}
		}
		
		private void UpdateBoardSizeMenu(int row, int col)
		{
			mnuBoardSize0.Checked = false;
			mnuBoardSize1.Checked = false;
			mnuBoardSize2.Checked = false;
			mnuBoardSize3.Checked = false;
			mnuBoardSize4.Checked = false;
			mnuBoardSize5.Checked = false;
			mnuBoardSize6.Checked = false;
			
			if( row == 3 && col == 3) {
				mnuBoardSize0.Checked = true;
			}
			else if(row == 4 && col == 4) {
				mnuBoardSize1.Checked = true;
			}
			else if(row == 5 && col == 5) {
				mnuBoardSize2.Checked = true;
			}
			else if(row == 6 && col == 6) {
				mnuBoardSize3.Checked = true;
			}
			else if(row == 7 && col == 7) {
				mnuBoardSize4.Checked = true;
			}
			else if(row == 8 && col == 8) {
				mnuBoardSize5.Checked = true;
			}
		}

		private void UpdateAlgMenu(int AlgType)
		{
			mnuAlg0.Checked = false;
			mnuAlg1.Checked = false;
			mnuAlg2.Checked = false;
			mnuAlg3.Checked = false;
			mnuSpeed.Checked = false;
			mnuShort.Checked = false;

			switch(AlgType) {
			case 0:
				mnuAlg0.Checked = true;
				break;
			case 1:
				mnuAlg1.Checked = true;
				break;
			case 2:
				mnuAlg2.Checked = true;
				break;
			case 3:
				mnuAlg3.Checked = true;
				break;
			case 4:
				mnuSpeed.Checked = true;
				break;
			case 5:
				mnuShort.Checked = true;
				break;
			}
		}

		private void UpdateToolbarButton()
		{
			EnableSolve(!fGameFinished);
			EnableUndo(m_Driver.CanUndo());
			EnableRedo(m_Driver.CanRedo());
		}
		
		private void UpdateStatusPanel()
		{
			if (this.fGameFinished)
				this.statusPanel.Text = "Click on board to start a new game";
			else
				this.statusPanel.Text = "Ready";
		}
		
		private void LevelChangeHelper(GameLevelEnum nDifficulty)
		{
			if ((this.nDifficulty != nDifficulty) &&
				(this.fGameFinished || 
				(DialogResult.Yes == MessageBox.Show("Do you want to resign this game?",
						this.Text,MessageBoxButtons.YesNo,MessageBoxIcon.Question))))
			{
				this.nDifficulty = nDifficulty;
				UpdateLevelMenu();
				NewGameHelper();
			}
		}
		
		private void OnFastPlayBack(object sender, EventArgs e)
		{
			mnuFastPlayBack.Checked = !mnuFastPlayBack.Checked;
			if (mnuFastPlayBack.Checked)
				this.nPlayBackSpeed = 50;
			else
				this.nPlayBackSpeed = 500;
		}

		//
		// User Input Handler
		//
		private void On_KeyUp(object source, KeyEventArgs e)
		{
	#if _DEBUG
			Console.WriteLine(e.KeyCode.ToString());
	#endif
			switch (e.KeyCode)
			{
			case Keys.Up:
	#if _DEBUG
				MessageBox.Show("Up");
	#endif
				break;
			case Keys.Down:
	#if _DEBUG
				MessageBox.Show("Down");
	#endif
				break;
			case Keys.Left:
	#if _DEBUG
				MessageBox.Show("Left");
	#endif
				break;
			case Keys.Right:
	#if _DEBUG
				MessageBox.Show("Right");
	#endif
				break;
			}
		}
	}

	/// <summary>
	///    Summary description for NativeMethods.
	/// </summary>

	class NativeMethods
	{
		[DllImportAttribute("user32.dll")]
		public static extern int MessageBeep(int iType);
	}
}