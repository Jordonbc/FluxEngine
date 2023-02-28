workspace "FluxEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "FluxEngine"
	location "FluxEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{

	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "on"
		systemversion "latest"
		defines
		{
			"FLUX_PLATFORM_WINDOWS",
			"FLUX_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/".. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "FLUX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FLUX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FLUX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Flux/src"
	}

	links
	{
		"FluxEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "on"
		systemversion "latest"
		defines
		{
			"FLUX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FLUX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FLUX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FLUX_DIST"
		optimize "On"