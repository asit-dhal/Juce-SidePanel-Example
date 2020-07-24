#pragma once

#include <JuceHeader.h>

class MainComponent   : public Component,
    public Button::Listener
{
public:
    MainComponent();
    ~MainComponent();

    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked(Button*) override;

private:

    void homeButtonClicked();
    void settingsButtonClicked();
    void listEntryClicked(int index);

    TextButton m_invokeSidePanel;
    Label m_sidePanelStatus;
    SidePanel m_sidePanel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
