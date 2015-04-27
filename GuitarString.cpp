/*********************************************/
/* Copyright 2015 Eamon Lightning            */
/* Assignment: Guitar Synthesizer            */
/* Date: February 6, 2015                    */
/* File: GuitarString.cpp                    */
/*********************************************/

#include <math.h>
#include <SFML/Audio.hpp>

#include <vector>

#include "GuitarString.hpp"
#include "RingBuffer.hpp"

GuitarString::GuitarString(double frequency) {
  
  int bufferCapacity = ceil(SAMPLE_RATE / frequency);
  
  _p_RB = new RingBuffer(bufferCapacity);
}

GuitarString::GuitarString(std::vector<sf::Int16> init) {
  
  _p_RB = new RingBuffer(init.size());
  
  for (unsigned int i = 0; i < init.size(); i++) {
    _p_RB->enqueue(init[i]);
  }
}

GuitarString::~GuitarString() {
  
  delete _p_RB;
}

void GuitarString::pluck() {
  
  _p_RB->empty();
  
  while (! _p_RB->isFull()) _p_RB->enqueue((sf::Int16)(rand() & 0xffff)); 
}

void GuitarString::tic() {
  
  int16_t currentSample = _p_RB->dequeue();
  int16_t nextSample = _p_RB->peek();
  int16_t newSample = ((nextSample + currentSample) / 2) * EDecayFactor;
  
  _p_RB->enqueue(newSample);
  
}

sf::Int16 GuitarString::sample() {
  
  return _p_RB->peek();
}
