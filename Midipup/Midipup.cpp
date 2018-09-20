/*
  Midipup.cpp - Library for playing midi dogs.
  Created by Daniel Dominguez, August 3rd, 2018.
  Released into the public domain.
*/

#include <Arduino.h>
#include <Midipup.h>
#include <MIDIUSB.h>


//constructors -initializes object
//one is the the default, the other is the paramterized constructor

Midipup::Midipup()
{
  
  _pin = MIDI_D_PIN ;
  _note = MIDI_D_NOTE;
  _veloc = MIDI_DEFAULT_VELOCITY;
  _delays = MIDI_DEFAULT_NOTE_DELAY;
  _chan = MIDI_DEFAULT_CHANNEL;
  _butstate = MIDI_DEFAULT_BUTTON_STATE;
  pinMode(_pin, INPUT_PULLUP);
  
}


Midipup::Midipup(int pin, byte note)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _note = note;
  _veloc = MIDI_DEFAULT_VELOCITY;
  _delays = MIDI_DEFAULT_NOTE_DELAY;
  _chan = MIDI_DEFAULT_CHANNEL;
  _butstate = MIDI_DEFAULT_BUTTON_STATE;
  
}

void Midipup::set_pin(int pin)
{
  _pin = pin; 
}

void Midipup::set_veloc(byte veloc)
{
  _veloc = veloc;
}

void Midipup::set_delays(long delays)
{
  _delays = delays;
}

void Midipup::set_note(byte note)
{
  _note = note;
}

void Midipup::set_chan(byte chan)
{
  _chan = chan;
}

bool Midipup::scan() 
{
_butstate = digitalRead(_pin);
return _butstate;
}

int Midipup::result()
{
return _chan;
}

void Midipup::noteOn() {
  midiEventPacket_t noteOn = {0x09, 0x90 | _chan, _note, _veloc};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

void Midipup::noteOff() {
  midiEventPacket_t noteOff = {0x08, 0x80 | _chan, _note, _veloc};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}


void Midipup::midi_poll() {
  if ((digitalRead(_pin) == LOW) & (_butstate == false)) {
      Midipup::noteOn();
      _butstate = true;
    } else if ((digitalRead(_pin) == LOW) & (_butstate == true)) {
      ; //do nothing
    } else if ((digitalRead(_pin) == HIGH) & (_butstate == true)) {
      Midipup::noteOff();
      _butstate = false;
    }
}







