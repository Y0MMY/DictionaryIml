workspace "DictionaryIml"
	architecture "x64"
	targetdir "build"
	
	configurations 
	{ 
		"Debug", 
        "Release",
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DictionaryIml"
    location "DictionaryIml"
    kind "ConsoleApp"
    language "C++"
    
	targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{ 
		"%{prj.name}/include/**.hpp", 
		"%{prj.name}/Source/**.cpp",
	}
    
	includedirs 
	{
		"%{prj.name}/include",
		"%{prj.name}/Source"
    }
	
	filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        
    
   filter "configurations:Debug"
        defines "DEBUG"
		runtime "Debug"
        symbols "On"
  