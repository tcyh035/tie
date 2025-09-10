workspace "Tie"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tie"
    location "Tie"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions 
        {
             "/utf-8"
        }

        defines
        {
            "TIE_PLATFORM_WINDOWS",
            "TIE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "TIE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "TIE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TIE_DIST"
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
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Tie/vendor/spdlog/include",
        "Tie/src"
    }

    links
    {
        "Tie"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions 
        {
             "/utf-8"
        }

        defines
        {
            "TIE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TIE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "TIE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TIE_DIST"
        optimize "On"