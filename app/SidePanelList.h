#pragma once

#include <JuceHeader.h>

class SidePanelList : public Component,
    public ListBoxModel
{
public:
    SidePanelList();
    ~SidePanelList();

    void paint (Graphics&) override;
    void resized() override;
    void paintListBoxItem(int rowNumber, Graphics& g, int width, int height, bool rowIsSelected) override;
    int getNumRows() override;
    void addEntry(const String& entry);
    void selectedRowsChanged(int row) override;
    void setEntrySelectionCallback(std::function<void(int)> callback);

private:
    ListBox m_entries;
    StringArray m_sidePanelEntries;
    std::function<void(int)> m_callback;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SidePanelList)
};
