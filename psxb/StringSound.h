// StringSound.h
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
#include"CircularBuffer.h"
#include<vector>
#include<memory>

class StringSound {
 public:
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound(const StringSound &obj) = delete;  // no copy const
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
 private:
    std::shared_ptr<CircularBuffer> buffer = NULL;
    int length;
    int mtime;
};
