project "Sandbox"
	kind "ConsoleApp"
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
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Cookie/include",
	}

	links 
	{
		"Cookie",
	}
	
	-- Platforms
	filter "platforms:Win32"
		system "windows"
		architecture "x86"

	filter "platforms:Win64"
		system "windows"
		architecture "x86_64"

	-- Configurations
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
	filter "system:windows"
		systemversion "latest"

		links "SDL2main"

		postbuildcommands
		{
			("{COPY} %{wks.location}/bin/" .. outputdir .. "/Cookie/Cookie.dll %{wks.location}/bin/" .. outputdir .. "/%{prj.name}"),
			("{COPY} %{wks.location}/bin/" .. outputdir .. "/SDL2/SDL2.dll %{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
		}