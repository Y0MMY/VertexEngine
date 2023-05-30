workspace "VertexEngine"
	architecture "x64"
	targetdir "build"
	
	configurations 
	{ 
		"Debug", 
        "Release",
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
project "VertexEngine"
    location "VertexEngine"
    kind "StaticLib"
    language "C++"
    
	targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader("pch.hpp")
	pchsource("VertexEngine/Source/pch.cpp")
	forceincludes { "pch.hpp" }

	files 
	{ 
		"%{prj.name}/Source/VertexEngine/**.cpp",
		"%{prj.name}/include/VertexEngine/**.hpp", 

		"%{prj.name}/Source/pch.hpp", 
		"%{prj.name}/Source/pch.cpp", 
    }

    includedirs
	{
		"%{prj.name}/include",
		"%{prj.name}/Source",

		"%{prj.name}/include/VertexEngine",
		"%{prj.name}/Source/VertexEngine",
		"vendor",
	}

	links
	{
	}
    
	filter "system:windows"
		cppdialect "C++17"
        staticruntime "On"
        
		defines 
		{ 
            "VE_PLATFORM_WINDOWS"
		}
					
    filter "configurations:Debug"
        defines "VE_DEBUG"
		runtime "Debug"
        symbols "On"

group ""

group "Tools"
project "PlayVerse"
    location "PlayVerse"
    kind "ConsoleApp"
    language "C++"
    
	targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")

	dependson 
	{ 
		"VertexEngine"
    }
    
	files 
	{ 
		"%{prj.name}/Source/**.h", 
		"%{prj.name}/Source/**.c", 
		"%{prj.name}/Source/**.hpp", 
		"%{prj.name}/Source/**.cpp" 
	}
    
	includedirs 
	{
        "%{prj.name}/Source",
        "VertexEngine/include",
        "vendor",
    }
	
	filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        
		links 
		{ 
			"VertexEngine",
		}
        
		defines 
		{ 
            "VE_PLATFORM_WINDOWS",
		}
    
   filter "configurations:Debug"
        defines "VE_DEBUG"
		runtime "Debug"
        symbols "On"
group ""   
  