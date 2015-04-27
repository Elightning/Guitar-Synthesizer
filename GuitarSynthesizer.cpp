/*********************************************/
/* Copyright 2015 Eamon Lightning            */
/* Assignment: Guitar Synthesizer            */
/* Date: February 6, 2015                    */
/* File: GuitarSynthesizer.cpp               */
/*********************************************/

#include <math.h>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <stdexcept>
#include <string>

#include "GuitarString.hpp"

int main() {
  
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero Lite");
  sf::Event event;

  std::vector<std::vector<sf::Int16> > samples(37);
  std::vector<sf::SoundBuffer> soundBuffers(37);
  std::vector<sf::Sound> sounds(37);

  int i, j, index;

  int duration = 2;  // An arbitrary duration of 2 seconds

  for (i = 0; i < 37; i++) {
    double frequency = 440 * pow(2, ((i - 24) / 12.0));
    GuitarString GS(frequency);
    GS.pluck();
    for (j = 0; j < (SAMPLE_RATE * duration); j++) {
      samples[i].push_back(GS.sample());
      GS.tic();
    }
  }

  for (i = 0; i < 37; i++) {
    if (!soundBuffers[i].loadFromSamples(&samples[i][0],
      samples[i].size(), 1, SAMPLE_RATE)) {
      throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
    }
    sounds[i].setBuffer(soundBuffers[i]);
  }

  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
       case sf::Event::Closed:
        window.close();
        break;
       case sf::Event::TextEntered:
        index = keyboard.find(event.text.unicode);
        if (index < 37 )
          sounds[index].play();
        break;
       default:
      break;
      }
    }

    window.clear();
    window.display();
  }

  return 0;
}
