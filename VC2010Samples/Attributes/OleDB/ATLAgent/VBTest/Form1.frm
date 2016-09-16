VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "DTL Test"
   ClientHeight    =   4095
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4740
   LinkTopic       =   "Form1"
   ScaleHeight     =   4095
   ScaleWidth      =   4740
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdFile 
      Caption         =   "Speak File"
      Height          =   375
      Left            =   3120
      TabIndex        =   6
      Top             =   3120
      Width           =   1215
   End
   Begin VB.TextBox txtFile 
      Height          =   405
      Left            =   360
      TabIndex        =   5
      Text            =   "d:\atl25\nonship\samples\atlagent\agentctl.cpp"
      Top             =   3120
      Width           =   2415
   End
   Begin VB.TextBox txtSpeed 
      Height          =   405
      Left            =   360
      TabIndex        =   4
      Text            =   "10"
      Top             =   2520
      Width           =   2415
   End
   Begin VB.CommandButton cmdSpeak 
      Caption         =   "Speak"
      Height          =   375
      Left            =   3120
      TabIndex        =   3
      Top             =   1920
      Width           =   1215
   End
   Begin VB.TextBox txtSpeak 
      Height          =   375
      Left            =   360
      TabIndex        =   2
      Text            =   "This is a test"
      Top             =   1920
      Width           =   2415
   End
   Begin VB.CommandButton cmdPlay 
      Caption         =   "Play"
      Height          =   375
      Left            =   1200
      TabIndex        =   1
      Top             =   1080
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "ATL Agent Test"
      BeginProperty Font 
         Name            =   "Comic Sans MS"
         Size            =   15.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim agent As CAgentCtl

Private Sub cmdFile_Click()
    agent.Speed = txtSpeed
    agent.SpeakFile (txtFile)
End Sub

Private Sub cmdPlay_Click()
    agent.Speed = txtSpeed
    agent.Play
End Sub

Private Sub cmdSpeak_Click()
    agent.Speed = txtSpeed
    agent.SpeakText (txtSpeak)
End Sub

Private Sub Form_Load()
    Set agent = New CAgentCtl
End Sub

