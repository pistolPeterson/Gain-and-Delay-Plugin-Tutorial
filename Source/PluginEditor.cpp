/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainandDelayPluginTutorialAudioProcessorEditor::GainandDelayPluginTutorialAudioProcessorEditor (GainandDelayPluginTutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //Gain Slider 
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(0.0f, 1.0f, 0.01f);
    gainSlider.setValue(0.5f); 
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);


    //Gain Label
    addAndMakeVisible(gainLabel);
    gainLabel.setText("Gain", juce::dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, true);
    gainLabel.setJustificationType(juce::Justification::centredBottom);


    //Delay Slider 
    delaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    delaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    delaySlider.setRange(1, 100, 1);
    delaySlider.setValue(10);
    delaySlider.addListener(this);
    addAndMakeVisible(delaySlider);

    //Delay Label
    addAndMakeVisible(delayLabel);
    delayLabel.setText("Delay Amt", juce::dontSendNotification);
    delayLabel.attachToComponent(&delaySlider, true);
    delayLabel.setJustificationType(juce::Justification::centredBottom);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

GainandDelayPluginTutorialAudioProcessorEditor::~GainandDelayPluginTutorialAudioProcessorEditor()
{
}

//==============================================================================
void GainandDelayPluginTutorialAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World! Pete's Delay and Gain Plugin", getLocalBounds(), juce::Justification::centredTop, 1);
}

void GainandDelayPluginTutorialAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
 
    // subcomponents in your editor..

    gainSlider.setBounds(getWidth() / 2, getHeight() / 2 - 50, 33, 150);
    delaySlider.setBounds(getWidth() / 5, getHeight()  / 2 - 50, 33, 150);
}

void GainandDelayPluginTutorialAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
   
    if (slider == &gainSlider)
    {
        DBG("gain slider moving");
        audioProcessor.gain = gainSlider.getValue();
    }
    if (slider == &delaySlider)
    {
        DBG("delay slider moving");
        audioProcessor.delay = delaySlider.getValue();
    }
}
