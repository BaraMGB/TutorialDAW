#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

namespace te = tracktion_engine;
class MainComponent : public juce::Component
    {
    public:
        MainComponent();

        void paint(juce::Graphics&) override;
        void resized() override;

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};


