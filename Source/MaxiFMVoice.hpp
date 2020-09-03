//
//  MaxiFMVoice.hpp
//  MidiWaveGen - App
//
//  Created by Hayden Setlik on 8/27/20.
//
#pragma once
#include "/Users/hayden/Desktop/Programming/Maximilian/maximilian.h"
#include <JuceHeader.h>
#include "SliderGroup.hpp"


struct MaxiFMSound   : public juce::SynthesiserSound
{
    MaxiFMSound() {}

    bool appliesToNote    (int) override        { return true; }
    bool appliesToChannel (int) override        { return true; }
};
//note: everything to do with the SynthesiserSound struct is in this header file

struct MaxiFMVoice   : public juce::SynthesiserVoice
{
    MaxiFMVoice() {}

    bool canPlaySound (juce::SynthesiserSound* sound) override
    {
        return dynamic_cast<MaxiFMSound*> (sound) != nullptr;
    }

    void startNote (int midiNoteNumber, float velocity,
                    juce::SynthesiserSound*,
                    int /*currentPitchWheelPosition*/) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void pitchWheelMoved (int) override      {}
    void controllerMoved (int, int) override {}
    void renderNextBlock (juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    

private:
    double currentAngle = 0.0, angleDelta = 0.0, level = 0.0, tailOff = 0.0;
    maxiOsc osc1;
    maxiEnv env1;
    double frequency = 0.0;
};

