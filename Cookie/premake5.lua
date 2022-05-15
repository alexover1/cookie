project "Cookie"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	-- Output directory
	location "%{wks.location}/build/%{prj.name}"
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")
	
	-- Files
	files 
	{ 
		"src/**.cpp", 
		"src/**.h",
		"include/**.h",
	}

	includedirs
	{
		"include",
		IncludeDir.SDL2,
		IncludeDir.Glad
	}

	links 
	{
		"SDL2",
		"Glad",
		"opengl32.lib"
	}

	-- Platforms
	filter { "platforms:Win32" }
		system "windows" 
		architecture "x86"

	filter { "platforms:Win64" }
		system "windows"
		architecture "x86_64"

	-- Configurations
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"