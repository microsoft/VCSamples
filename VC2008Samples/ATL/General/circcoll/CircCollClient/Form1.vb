Public Class Form1
    Inherits System.Windows.Forms.Form

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub
    Friend WithEvents Button1 As System.Windows.Forms.Button

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.Container

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(24, 16)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(112, 32)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "GetCircleCollection"
        '
        'Form1
        '
        Me.ClientSize = New System.Drawing.Size(643, 557)
        Me.Controls.AddRange(New System.Windows.Forms.Control() {Me.Button1})
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim s As Object
        Dim circ As Object
        Dim i As Object
        Dim coll As Object

        Dim g As System.Drawing.Graphics
        g = Me.CreateGraphics

        ' get a collection of objects
        Dim x As New CIRCCOLLLib.MyCircleCollectionCreator()
        coll = x.GetCircles(5)

        Dim drawFont As Font
        drawFont = New Font("Arial", 10)

        Dim drawBrush As SolidBrush
        drawBrush = New SolidBrush(Color.Black)

        Dim drawFormat As StringFormat
        drawFormat = New StringFormat()

        ' Draw the circles
        For i = 1 To coll.Count
            g.FillEllipse(New SolidBrush(Color.FromArgb(Rnd() * 255, Rnd() * 255, Rnd() * 255)), New System.Drawing.RectangleF(coll.Item(i).XCenter - coll.Item(i).Radius, coll.Item(i).YCenter - coll.Item(i).Radius, 2 * coll.Item(i).Radius, 2 * coll.Item(i).Radius))
            g.DrawString(coll.Item(i).Label, drawFont, drawBrush, coll.Item(i).XCenter, coll.Item(i).YCenter, drawFormat)
        Next i

        MsgBox("Now change values and redraw")

        Me.Refresh()
        ' change vaules of objects inside the collection
        For i = 1 To coll.Count
            circ = coll.Item(i)
            s = "New "
            s = s + circ.Label
            circ.Radius = circ.Radius * CDbl(0.5)
            circ.XCenter = circ.XCenter + 50 * i
            circ.YCenter = circ.YCenter + 50 * i
            circ.Label = s
        Next i

        ' now redraw to show new values
        For Each circ In coll
            g.FillEllipse(New SolidBrush(Color.FromArgb(Rnd() * 255, Rnd() * 255, Rnd() * 255)), New System.Drawing.RectangleF(circ.XCenter - circ.Radius, circ.YCenter - circ.Radius, 2 * circ.Radius, 2 * circ.Radius))
            g.DrawString(circ.Label, drawFont, drawBrush, circ.XCenter, circ.YCenter, drawFormat)
        Next circ

    End Sub
End Class
