Imports ScribbleApp
Imports System.Drawing

Public Class MyPlugin
    Implements IScribblePlugin

    Public Property Name() As String Implements IScribblePlugin.Name
        Get
            Return "Draw Shapes"
        End Get
        Set(ByVal value As String)
        End Set
    End Property

    Private Sub DrawSquare(ByVal scribDoc As IScribbleDoc, ByVal x As Integer, ByVal y As Integer, ByVal w As Integer, ByVal h As Integer)
        Dim sqWidth As Integer = w
        Dim sqHeight As Integer = -h
        Dim sqStartX As Integer = x
        Dim sqStartY As Integer = y

        scribDoc.DrawLine(New Point(sqStartX, sqStartY), New Point(sqStartX + sqWidth, sqStartY))
        scribDoc.DrawLine(New Point(sqStartX, sqStartY), New Point(sqStartX, sqStartY + sqHeight))
        scribDoc.DrawLine(New Point(sqStartX, sqStartY + sqHeight), New Point(sqStartX + sqWidth, sqStartY + sqHeight))
        scribDoc.DrawLine(New Point(sqStartX + sqWidth, sqStartY), New Point(sqStartX + sqWidth, sqStartY + sqHeight))
    End Sub
    Public Sub Run(ByVal iScribApp As IScribbleApp) Implements IScribblePlugin.Run
        Dim scribDoc As IScribbleDoc = iScribApp.GetDocument()
        Dim oldColor As Color = scribDoc.GetPenColor()

        scribDoc.SetPenColor(Color.Red)
        DrawSquare(scribDoc, 30, -30, 40, 40)
        scribDoc.SetPenColor(Color.Blue)
        DrawSquare(scribDoc, 80, -30, 40, 40)
        scribDoc.SetPenColor(Color.Green)
        DrawSquare(scribDoc, 130, -30, 40, 40)

        scribDoc.SetPenColor(oldColor)
    End Sub
End Class
