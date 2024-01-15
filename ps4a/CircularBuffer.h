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
