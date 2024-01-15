//CircularBuffer.h
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps4a>
 *Instructor's name: <Dr. James Daly>
 *Date: <3/22/2022>
 *Sources Of Help: <professor and youtube video about ring buffer>
************************************************************/

#pragma once
#include <stdint.h>
#include<iostream>
#include<string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "CircularBuffer.h"
#include "StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100


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
