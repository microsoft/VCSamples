Imports System
Imports Microsoft.VisualStudio.VCProjectEngine

Module Module1
    Sub Main()
        Try

            ' Create a project engine
            Dim projEngine As New VCProjectEngineObject()

            ' Load a project, change the name, add a configuration
            Dim project As VCProject = projEngine.LoadProject("..\MyProject\MyProject.vcproj")
            If Not project Is Nothing Then

                'Change the project's name
                project.Name = "Voila"
                'Add a new configuration
                project.AddConfiguration("Whichever Name")

                ' Get the debug configuration and change the type to application
                Dim configuration As VCConfiguration = CType(project.Configurations, IVCCollection).Item("Debug")
                If Not configuration Is Nothing Then
                    configuration.ConfigurationType = ConfigurationTypes.typeApplication
                Else
                    Console.WriteLine("I Couldn't find the configuration")
                End If
                ' Get the linker tool from the configration.
                Dim linkerTool As VCLinkerTool = CType(configuration.Tools, IVCCollection).Item("VCLinkerTool")
                If Not linkerTool Is Nothing Then

                    ' Change the ShowProgress property to "Display All Progress Messages (/VERBOSE)"
                    linkerTool.ShowProgress = linkProgressOption.linkProgressAll

                Else
                    Console.WriteLine("I Couldn't find the linkerTool")
                End If
                ' Add a cpp file called New.cpp
                If (project.CanAddFile("New.cpp")) Then
                    project.AddFile("New.cpp")
                Else
                    Console.WriteLine("I Couldn't add the file")
                End If

                ' Access the files collection
                Dim filesCollection As IVCCollection = project.Files
                If Not filesCollection Is Nothing Then


                    ' Access a cpp files called Existing.cpp that is already in the project.
                    Dim file As VCFile = filesCollection.Item("Existing.cpp")

                    If Not file Is Nothing Then

                        ' Access the release configuration of this file.
                        Dim fileConfiguration As VCFileConfiguration = CType(file.FileConfigurations, IVCCollection).Item("Release|Win32")

                        ' Get the compiler tool associated with this file.
                        Dim compilerTool As VCCLCompilerTool = fileConfiguration.Tool

                        ' Change the optimization property to Full Optimization (/Ox)
                        compilerTool.Optimization = optimizeOption.optimizeFull

                    Else
                        Console.WriteLine("I Couldn't find the file")
                    End If
                    ' Save the project, then remove it.
                    project.ProjectFile = "MyNewProject.vcproj"
                    project.Save()

                Else
                    Console.WriteLine("I Couldn't find the file collection")
                End If
            Else
                Console.WriteLine("I Couldn't find the project")
            End If

			catch e as Exception 

            Console.WriteLine("Operation failed for the following reason: {0}", e.Message)
        End Try
    End Sub

End Module
