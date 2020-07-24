cmake_minimum_required(VERSION 3.12)

project(JuceSidePanelExample VERSION 0.0.2)

add_subdirectory(JUCE)

juce_add_gui_app(JuceSidePanelExample
	BUNDLE_ID aditdhal
	NEEDS_CURL TRUE
)

juce_generate_juce_header(JuceSidePanelExample)

set(SRCS
	app/Main.cpp
	app/MainComponent.cpp
	app/SidePanelHeader.cpp
	app/SidePanelList.cpp
)

target_sources(JuceSidePanelExample PRIVATE
	${SRCS}
)

target_include_directories(JuceSidePanelExample PRIVATE
	app
)

target_compile_definitions(JuceSidePanelExample PRIVATE
	JUCE_ALLOW_STATIC_NULL_VARIABLES=0
	JUCE_STRICT_REFCOUNTEDPOINTER=1
	JUCE_USE_CURL=1
)

target_link_libraries(JuceSidePanelExample PRIVATE
	juce::juce_core
	juce::juce_events
	juce::juce_gui_basics
)
