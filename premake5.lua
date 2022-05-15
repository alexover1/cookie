workspace "Cookie"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64" }
   startproject "Sandbox"

-- Include directories relative to root folder (sln directory)
IncludeDir = {}
IncludeDir["SDL2"] = "%{wks.location}/libs/sdl2/include"
IncludeDir["Glad"] = "%{wks.location}/libs/glad/include"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "libs/sdl2"
	include "libs/glad"
group ""

include "Cookie"
include "Sandbox"