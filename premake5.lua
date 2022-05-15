workspace "MyWorkspace"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64" }
   location "build"
   startproject "Sandbox"

-- Include directories relative to root folder (sln directory)
IncludeDir = {}
IncludeDir["SDL2"] = "libs/sdl2/include"
IncludeDir["Cookie"] = "Cookie/include"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "libs/sdl2/SDL2.lua"
	include "libs/sdl2/SDL2main.lua"
group ""

project "Cookie"
	kind "SharedLib"
	language "C++"
	location "build/Cookie"
	
	-- Output directory
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")
	
	-- Files
	files 
	{ 
		"%{prj.name}/src/**.cpp", 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/include/**.h",
	}

	includedirs
	{
		IncludeDir.SDL2,
		IncludeDir.Cookie,
		"%{prj.name}/src/third_party",
	}

	links 
	{
		"SDL2",
		"opengl32"
	}

	-- Platforms
	filter { "platforms:Win32" }
		system "Windows" 
		architecture "x86"

	filter { "platforms:Win64" }
		system "Windows"
		architecture "x86_64"

	-- Configurations
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	location "build/Sandbox"
	
	-- Output directory
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	-- Files
	files 
	{
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		IncludeDir.SDL2,
		IncludeDir.Cookie,
	}

	links 
	{
		"Cookie",
		"SDL2",
		"opengl32"
	}
	
	-- Platforms
	filter { "platforms:Win32" }
		system "Windows"
		architecture "x86"

	filter { "platforms:Win64" }
		system "Windows"
		architecture "x86_64"

	-- Configurations
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		postbuildcommands
		{
			("{COPY} ../../bin/" .. outputdir .. "/Cookie/Cookie.dll ../../bin/" .. outputdir .. "/%{prj.name}"),
			("{COPY} ../../libs/sdl2/Binaries/" .. outputdir .. "/SDL2.dll ../../bin/" .. outputdir .. "/%{prj.name}")
		}