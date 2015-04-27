/*********************************************/
/* Copyright 2015 Eamon Lightning            */
/* Assignment: Guitar Synthesizer            */
/* Date: February 6, 2015                    */
/* File: RingBuffer.cpp                      */
/*********************************************/

#include <stdint.h>

#include <vector>
#include <stdexcept>
#include <string>

#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) : _size(0), _first(0), _last(0), _capacity(capacity) {
  
  if (capacity < 1) {
    std::string exceptionMessage;
    exceptionMessage = "RB constructor: capacity must be greater than zero.";
    throw std::invalid_argument(exceptionMessage);
  }

  _RB.resize(capacity);
}

int RingBuffer::size() {
  
  return _size;
}

bool RingBuffer::isEmpty() {
  
  return (_size == 0) ? true : false;
}

bool RingBuffer::isFull() {
  
  return (_size == _capacity) ? true : false;
}

void RingBuffer::enqueue(int16_t x) {
  
  if (isFull()) {
    throw std::runtime_error("can't enqueue to a full ring.");
  }
  _RB[_last] = x;

  if (++_last == _capacity) {
    _last = 0;
  } 

  _size++;
}

int16_t RingBuffer::dequeue() {
  
  if (isEmpty()) {
    throw std::runtime_error("can't dequeue from an empty ring.");
  }
  
  int16_t temp = _RB[_first];
  
  _RB[_first] = 0.0;

  if (++_first == _capacity) {
    _first = 0;
  }

  _size--;

  return temp;
}

int16_t RingBuffer::peek() {
  
  if (isEmpty()) {
    throw std::runtime_error("can't dequeue from an empty ring.");
  }
  
  return _RB[_first];
}

void RingBuffer::empty() {
  
  _first = _last = _size = 0;
}
