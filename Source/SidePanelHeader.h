#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SidePanelHeader : public Component
{
public:
    SidePanelHeader(const String& titleText);
    ~SidePanelHeader();
    void paint (Graphics&) override;
    void resized() override;
    void setHomeButtonClicked(std::function<void()> callback);
    void setSettingButtonClicked(std::function<void()> callback);

private:
    Label m_titleLabel;
    ShapeButton m_homeButton{ "Home", Colours::transparentBlack, Colours::transparentBlack, Colours::transparentBlack },
        m_settingsButton{ "Settings", Colours::transparentBlack, Colours::transparentBlack, Colours::transparentBlack };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SidePanelHeader)
};
