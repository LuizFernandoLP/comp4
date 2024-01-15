//main.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps5>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/5/2022>
 *Sources Of Help: <professor, peers in discord, a bunch of youtube videos and documentations>
************************************************************/
#include"EDistance.h"

int main() {
    sf::Clock clock;
    sf::Time t;

    std::string sequence1, sequence2;
    std::cin >> sequence1 >> sequence2;
    int gap_ = 2;

    EDistance obj(sequence1, sequence2, gap_);
    int optDist = obj.optDistance();

    std::cout << "Edit distance = " << optDist << std::endl;
    std::cout << obj.alignment();

    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";
    return 0;
}
