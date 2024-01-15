// RandWriter.h
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <ps6>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/11/2022>
 *Sources Of Help: <professor and classmates through discord>
************************************************************/
#pragma once
#include<iostream>
#include<string>
#include <map>
#include<random>
#include<ctime>
#include <chrono>  // NOLINT [build/c++11]
#include<vector>
#include <SFML/System.hpp>

class RandWriter {
 public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string kgram) const;
    int freq(std::string kgram, char c) const;
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);
    friend std::ostream& operator<<(std::ostream& os, const RandWriter& obj);

    void substring();
 private:
    std::string m_text;
    std::string m_text_circular;
    int m_order;
    std::map<std::string, std::map<char, int>> myMap;
};
