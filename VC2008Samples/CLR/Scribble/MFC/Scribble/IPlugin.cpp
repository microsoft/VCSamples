#using <mscorlib.dll>

public __gc __interface
IPlugin
{
   void Load();
   void Run();
   void Stop();
};