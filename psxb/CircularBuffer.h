//CircularBuffer.h
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps4b>
 *Instructor's name: <Dr. James Daly>
 *Date: <3/22/2022>
 *Sources Of Help: <classmates and professor + documentation>
************************************************************/

#pragma once
#include "CircularBuffer.h"
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#include <chrono>  // NOLINT [build/c++11]
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include<random>
#include<ctime>
#include<memory>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100
#define DECAY 0.996


class CircularBuffer{
 public:
    explicit CircularBuffer(size_t capacity);
    size_t size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
 private:
    int front;
    int back;
    int16_t *arr;
    size_t m_capacity;
};
