//
//  SliderGroup.cpp
//  ADSRSliderSet - App
//
//  Created by Hayden Setlik on 9/2/20.
//

#include "SliderGroup.hpp"

SliderGroup::SliderGroup()
{
    addAndMakeVisible(aTimeSlider);
    addAndMakeVisible(dTimeSlider);
    addAndMakeVisible(sLevelSlider);
    addAndMakeVisible(rTimeSlider);
    
    aTimeSlider.setSliderStyle(juce::Slider::LinearVertical);
    dTimeSlider.setSliderStyle(juce::Slider::LinearVertical);
    sLevelSlider.setSliderStyle(juce::Slider::LinearVertical);
    rTimeSlider.setSliderStyle(juce::Slider::LinearVertical);
    
    aTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,
                                false,
                                getParentWidth() / 4,
                                40);
    dTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,
    false,
    getParentWidth() / 4,
    40);
    sLevelSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,
    false,
    getParentWidth() / 4,
    40);
    rTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,
    false,
    getParentWidth() / 4,
    40);
    
    aTimeSlider.setTextValueSuffix(" ms");
    dTimeSlider.setTextValueSuffix(" ms");
    sLevelSlider.setTextValueSuffix(" %");
    rTimeSlider.setTextValueSuffix(" ms");
    
    aTimeSlider.addListener(this);
    dTimeSlider.addListener(this);
    sLevelSlider.addListener(this);
    rTimeSlider.addListener(this);
    
    aTimeSlider.setRange(0.5f, 3000.0f);
    dTimeSlider.setRange(0.5f, 3000.0f);
    sLevelSlider.setRange(0.0f, 1.0f);
    rTimeSlider.setRange(0.5f, 3000.0f);
    
    aTimeSlider.setNumDecimalPlacesToDisplay(4);
    dTimeSlider.setNumDecimalPlacesToDisplay(4);
    sLevelSlider.setNumDecimalPlacesToDisplay(4);
    rTimeSlider.setNumDecimalPlacesToDisplay(4);

}

void SliderGroup::resized()
{
    int xWidth = getWidth() / 4;
    aTimeSlider.setBounds(0, 0, xWidth, getHeight() - 40);
    dTimeSlider.setBounds(xWidth,0, xWidth, getHeight() - 40);
    sLevelSlider.setBounds(2 * xWidth, 0, xWidth, getHeight() - 40);
    rTimeSlider.setBounds(3 * xWidth, 0, xWidth, getHeight() - 40);
}

void SliderGroup::sliderValueChanged(juce::Slider* slider)
{
    printf("slider changed\n");
}

