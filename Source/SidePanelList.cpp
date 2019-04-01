#include "../JuceLibraryCode/JuceHeader.h"
#include "SidePanelList.h"

SidePanelList::SidePanelList()
{
    setOpaque(true);
    addAndMakeVisible(m_entries);
    m_entries.setModel(this);
    m_entries.setRowHeight(40);
}

SidePanelList::~SidePanelList()
{

}

void SidePanelList::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (SidePanel::backgroundColour));   // clear the background

}

void SidePanelList::resized()
{
    m_entries.setBounds(getLocalBounds());
}

void SidePanelList::paintListBoxItem(int rowNumber, Graphics& g, int width, int height, bool rowIsSelected)
{
    if (rowNumber < 0 || rowNumber >= getNumRows())
        return;

    Rectangle<int> bounds(0, 0, width, height);
    auto textColour = findColour(Label::textColourId);
    g.setColour(textColour.withAlpha(0.4f));

    if (rowNumber == 0)
        g.fillRect(bounds.removeFromTop(2).reduced(10, 0));

    g.fillRect(bounds.removeFromBottom(2).reduced(10, 0));

    if (rowIsSelected)
    {
        g.setColour(findColour(TextEditor::highlightColourId).withAlpha(0.4f));
        g.fillRect(bounds);
        textColour = findColour(TextEditor::highlightedTextColourId);
    }

    g.setColour(textColour);
    g.drawFittedText(m_sidePanelEntries[rowNumber], bounds, Justification::centred, 1);
}

void SidePanelList::addEntry(const String& entry)
{
    m_entries.deselectAllRows();
    m_sidePanelEntries.add(entry);
    m_entries.updateContent();
}

int SidePanelList::getNumRows()
{
    return m_sidePanelEntries.size();
}

void SidePanelList::selectedRowsChanged(int row)
{
    if (row < 0)
        return;
    m_callback(row);
}

void SidePanelList::setEntrySelectionCallback(std::function<void(int)> callback)
{
    m_callback = callback;
}