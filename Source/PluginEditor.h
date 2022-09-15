/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class GainandDelayPluginTutorialAudioProcessorEditor  : public juce::AudioProcessorEditor, 
                                                        public juce::Slider::Listener
{
public:
    GainandDelayPluginTutorialAudioProcessorEditor (GainandDelayPluginTutorialAudioProcessor&);
    ~GainandDelayPluginTutorialAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

private:
    juce::Slider delaySlider;
    juce::Slider gainSlider;

    juce::Label gainLabel; 
    juce::Label delayLabel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainandDelayPluginTutorialAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainandDelayPluginTutorialAudioProcessorEditor)
};
