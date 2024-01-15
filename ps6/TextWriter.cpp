// TextWriter.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <ps6>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/11/2022>
 *Sources Of Help: <professor and classmates through discord>
************************************************************/
#include"RandWriter.h"

int main(int argc, char* argv[]) {
    sf::Clock clock;
    sf::Time t;

    std::string str;
    std::string fullText;
    int orderK = std::stoi(argv[1]);
    int m_length = std::stoi(argv[2]);

    while (getline(std::cin, str)) {
        fullText = fullText + str;
    }
    RandWriter obj(fullText, orderK);
    std::string stringGen;
    std::string firstK;
    for (int i = 0; i < orderK; i++) {
        firstK = firstK + fullText[i];
    }
    stringGen = obj.generate(firstK, m_length);
    std::cout << "random: " << stringGen << std::endl;
    std::cout << obj << std::endl;

    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";

    return 0;
}
