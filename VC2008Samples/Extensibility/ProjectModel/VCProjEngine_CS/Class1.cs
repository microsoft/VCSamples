using System;
using Microsoft.VisualStudio.VCProjectEngine;

namespace Samples
{
	class VCProjectManipulation
	{
		static void Main(string[] args)
		{
			try 
			{
				// Create a project engine
				VCProjectEngine projEngine = new VCProjectEngineObject();

				// Load a project, change the name, add a configuration
				VCProject project = (VCProject)projEngine.LoadProject(@"..\..\..\MyProject\MyProject.vcproj");
				if(project != null)
				{
					//Change the project's name
					project.Name = "Voila";
					//Add a new configuration
					project.AddConfiguration("Whichever Name");
					
					// Get the debug configuration and change the type to application
					VCConfiguration configuration = (VCConfiguration) (((IVCCollection) project.Configurations).Item("Debug"));
					if(configuration != null)
					{
						configuration.ConfigurationType = ConfigurationTypes.typeApplication;
					}
					else
						Console.WriteLine(@"I Couldn't find the configuration");

					// Get the linker tool from the configration.
					VCLinkerTool linkerTool = (VCLinkerTool)(((IVCCollection) configuration.Tools).Item("VCLinkerTool"));
					if(linkerTool != null)
					{
						// Change the ShowProgress property to "Display All Progress Messages (/VERBOSE)"
						linkerTool.ShowProgress = linkProgressOption.linkProgressAll;
					}
					else
						Console.WriteLine(@"I Couldn't find the linkerTool");

					// Add a cpp file called New.cpp
					if (project.CanAddFile("New.cpp")) 
						project.AddFile("New.cpp");
					else
						Console.WriteLine(@"I Couldn't add the file");

					// Access the files collection
					IVCCollection filesCollection = (IVCCollection) project.Files;
					if(filesCollection != null)
					{

						// Access a cpp files called bar.cpp that is already in the project.
						VCFile file = (VCFile) (filesCollection.Item("Existing.cpp"));

						if(file != null)
						{
							// Access the release configuration of this file.
							VCFileConfiguration fileConfiguration = (VCFileConfiguration) (((IVCCollection) file.FileConfigurations).Item("Release|Win32"));

							// Get the compiler tool associated with this file.
							VCCLCompilerTool compilerTool = (VCCLCompilerTool) fileConfiguration.Tool;

							// Change the optimization property to Full Optimization (/Ox)
							compilerTool.Optimization = optimizeOption.optimizeFull;
						}
						else
							Console.WriteLine(@"I Couldn't find the file");

						// Save the project, then remove it.
						project.ProjectFile = "MyNewProject.vcproj";
						project.Save();
					}
					else
						Console.WriteLine(@"I Couldn't find the file collection");
				}
				else
					Console.WriteLine(@"I Couldn't find the project");
			}
			catch (Exception e) 
			{
				Console.WriteLine("Operation failed for the following reason: {0}", e.Message);
			}
		}
	}
}
