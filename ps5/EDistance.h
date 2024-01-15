// EDistance.h
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps5>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/5/2022>
 *Sources Of Help: <professor, peers in discord, a bunch of youtube videos and documentations>
************************************************************/
#pragma once
#include <algorithm>
#include<iostream>
#include<string>
#include <vector>
#include <SFML/System.hpp>

class EDistance{
 public:
    EDistance(std::string sequence1, std::string sequence2, int gapPenalty);
    int penalty(char a, char b);
    int printPenalty(std::string a, std::string b);
    int min(int a, int b, int c);
    int optDistance();
    std::string alignment();
 private:
    std::string sequence_1, sequence_2;
    std::string seq1Final, seq2Final;
    size_t m, n;
    int Pgap;
    std::vector<std::vector<int> > m_2dMatrix;
};
