//
//  MaxiFMVoice.cpp
//  MidiWaveGen - App
//
//  Created by Hayden Setlik on 8/27/20.
//

#include "MaxiFMVoice.hpp"
void MaxiFMVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound *, int /*currentpitchwheelpos*/)
{
        level =  velocity / 5.0;
        env1.trigger = 1;
        auto cyclesPerSecond = juce::MidiMessage::getMidiNoteInHertz (midiNoteNumber);
        frequency = cyclesPerSecond;
}
void MaxiFMVoice::stopNote(float velocity, bool allowTailOff)
{
    env1.trigger = 0;
    allowTailOff = true;
    if(velocity == 0)
        clearCurrentNote();
}
void MaxiFMVoice::renderNextBlock(juce::AudioSampleBuffer &outputBuffer, int startSample, int numSamples)
{
    env1.setAttack(25);
    env1.setDecay(25);
    env1.setSustain(0.5);
    env1.setRelease(250);
    for(int sample = 0; sample < numSamples; ++sample)
    {
        double rawSample = osc1.sinewave(frequency);
        double envSample = env1.adsr(rawSample, env1.trigger) * level;
        for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            outputBuffer.addSample(channel, startSample, envSample);
        }
        ++startSample;
    }
}
