/*********************************************/
/* Copyright 2015 Eamon Lightning            */
/* Assignment: Guitar Synthesizer            */
/* Date: February 6, 2015                    */
/* File: RingBuffer.hpp                      */
/*********************************************/

#ifndef _RINGBUFFER
#define _RINGBUFFER

#include <stdint.h>

#include <vector>

class RingBuffer {
 public:
  explicit RingBuffer(int capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
  void empty();
 private:
  std::vector<int16_t> _RB;
  int _size;
  int _capacity;
  int _first;
  int _last;
};

#endif
