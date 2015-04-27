/*********************************************/
/* Copyright 2015 Eamon Lightning            */
/* Assignment: Guitar Synthesizer            */
/* Date: February 6, 2015                    */
/* File: GuitarString.hpp                    */
/*********************************************/

#ifndef _GUITARSTRING
#define _GUITARSTRING

#include <SFML/Audio.hpp>

#include <vector>

#include "RingBuffer.hpp"

#define SAMPLE_RATE 44100
#define EDecayFactor 0.996

class GuitarString {
 public:
  explicit GuitarString(double frequency);
  explicit GuitarString(std::vector<sf::Int16> init);
  ~GuitarString();
  void pluck();
  void tic();
  sf::Int16 sample();
 private:
  RingBuffer *_p_RB;
};

#endif
