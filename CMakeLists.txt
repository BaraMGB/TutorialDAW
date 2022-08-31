include_guard()

cmake_minimum_required (VERSION 3.15...3.20)

project(TutorialDAW)

add_subdirectory(modules/juce)

juce_add_modules(modules/tracktion/modules/tracktion_engine)
juce_add_modules(modules/tracktion/modules/tracktion_graph)
juce_add_modules(modules/tracktion/modules/tracktion_core)

add_subdirectory(App)
