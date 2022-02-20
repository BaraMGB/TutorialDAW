include_guard()

cmake_minimum_required (VERSION 3.15...3.20)

project(TutorialDAW)

add_subdirectory(modules/modules/juce)

juce_add_modules(modules/modules/tracktion_engine)
juce_add_modules(modules/modules/tracktion_graph)

add_subdirectory(App)
