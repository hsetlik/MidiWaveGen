//
//  SliderGroup.hpp
//  ADSRSliderSet - App
//
//  Created by Hayden Setlik on 9/2/20.
//

#pragma once
#include <JuceHeader.h>
#include <stdio.h>
#include </Users/hayden/Desktop/Programming/Maximilian/maximilian.h>

class SliderGroup : public juce::Component, public juce::Slider::Listener
{
public:
    SliderGroup();
    ~SliderGroup() {}
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;
    juce::Slider aTimeSlider;
    juce::Slider dTimeSlider;
    juce::Slider sLevelSlider;
    juce::Slider rTimeSlider;
private:
};


