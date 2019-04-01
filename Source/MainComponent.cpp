#include "MainComponent.h"
#include "SidePanelList.h"
#include "SidePanelHeader.h"

MainComponent::MainComponent(): m_invokeSidePanel("Sidepanel", "Show Sidepanel"),
    m_sidePanel("", 250, true, nullptr, false)
{
    addAndMakeVisible(m_invokeSidePanel);
    addAndMakeVisible(m_sidePanelStatus);
    addAndMakeVisible(m_sidePanel);

    m_sidePanelStatus.setText("status", dontSendNotification);
    setSize (600, 400);

    m_invokeSidePanel.addListener(this);

    auto sidePanelHeader = new SidePanelHeader("Side Panel");
    sidePanelHeader->setHomeButtonClicked([&]() { homeButtonClicked(); });
    sidePanelHeader->setSettingButtonClicked([&]() { settingsButtonClicked(); });
    m_sidePanel.setTitleBarComponent(sidePanelHeader, true);

    auto sidePanelList = new SidePanelList;
    sidePanelList->addEntry("Entry 1");
    sidePanelList->addEntry("Entry 2");
    sidePanelList->addEntry("Entry 3");
    sidePanelList->setEntrySelectionCallback([&](int index) { listEntryClicked(index); });
    m_sidePanel.setContent(sidePanelList);
}

MainComponent::~MainComponent()
{
    m_invokeSidePanel.removeListener(this);
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void MainComponent::resized()
{
    auto localBounds = getLocalBounds();
    if (localBounds.getHeight() / 2 - 50 > 5)
        localBounds.removeFromTop(localBounds.getHeight() / 2 - 50);
    if (localBounds.getWidth() / 2 - 50 > 5)
        localBounds.removeFromLeft(localBounds.getWidth() / 2 - 50);

    auto buttonBound = localBounds.removeFromTop(30).removeFromRight(150);
    auto statusLabelBound = localBounds.removeFromTop(30).removeFromRight(150).reduced(5);
    m_invokeSidePanel.setBounds(buttonBound);
    m_sidePanelStatus.setBounds(statusLabelBound);
}

void MainComponent::buttonClicked(Button* btn)
{
    if (btn == &m_invokeSidePanel)
    {
        m_sidePanel.showOrHide(true);
    }
}

void MainComponent::homeButtonClicked()
{
    m_sidePanelStatus.setText("Home Button Clicked", dontSendNotification);
}

void MainComponent::settingsButtonClicked()
{
    m_sidePanelStatus.setText("Settings Button Clicked", dontSendNotification);
}

void MainComponent::listEntryClicked(int index)
{
    m_sidePanelStatus.setText(String("Entry ") + String(index+1) + " Clicked", dontSendNotification);
}
