project(TutorialDAW VERSION 0.1.0)

set (TargetName ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# If we are using MSVC we want static runtime linkage
if (MSVC)
    set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# If we are compiling for macOS we want to target OS versions down to 10.11
if (APPLE)
    set (CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE INTERNAL "")
    set (CMAKE_OSX_ARCHITECTURES "x86_64")
endif()


# Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)


juce_add_console_app(${TargetName} PRODUCT_NAME "TutorialDAW")
juce_generate_juce_header(${TargetName})

target_sources(${TargetName} PRIVATE
        main.cpp
        MainComponent.cpp
        MainWindow.cpp
        )

target_compile_definitions(${TargetName} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_PROJECT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_VERSION>"
        TRACKTION_JUCE7=1)

target_compile_definitions (${TargetName} PUBLIC
        JUCE_JACK=1
        JUCE_WASAPI=1
        JUCE_PLUGINHOST_VST3=1
        JUCE_PLUGINHOST_LADSPA=1
        JUCE_PLUGINHOST_AU=1
        JUCE_USE_FLAC=1
        JUCE_USE_MP3AUDIOFORMAT=1
        JUCE_USE_WINDOWS_MEDIA_FORMAT=1
        DONT_SET_USING_JUCE_NAMESPACE=1
	JUCE_MODAL_LOOPS_PERMITTED=1)



target_link_libraries(${TargetName} PRIVATE
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        juce::juce_gui_extra
        tracktion_engine
	)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
 target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE "-latomic")
 target_link_options(${CMAKE_PROJECT_NAME} PRIVATE "-m64")
endif()
