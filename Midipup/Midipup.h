/*
  Midipup.cpp - Library for playing midi dogs.
  Created by Daniel Dominguez, August 3rd, 2018.
  Released into the public domain.
*/

#ifndef Midipup_h
#define Midipup_h

#include <Arduino.h>

#define MIDI_DEFAULT_NOTE_DELAY		30
#define MIDI_DEFAULT_VELOCITY           110
#define MIDI_DEFAULT_CHANNEL             0
#define MIDI_DEFAULT_BUTTON_STATE        false
#define MIDI_D_NOTE                     60
#define MIDI_D_PIN                      16



class Midipup
{
    int _pin;    
    byte _chan;
    byte _note;    
    byte _veloc;
    long _delays;
    bool _flag;
    bool _butstate;
    
  public:

  //Constructor
  Midipup(int pin, byte note);
  Midipup();
    void midi_poll();
    void set_pin(int pin);
    void set_veloc(byte veloc);
    void set_delays(long delays);
    void set_note(byte note);
    void noteOn();
    void noteOff();
    bool scan();
    int result();
    void set_chan(byte chan);


    
};

#endif
