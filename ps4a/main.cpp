//main.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps4a>
 *Instructor's name: <Dr. James Daly>
 *Date: <3/22/2022>
 *Sources Of Help: <professor and youtube video about ring buffer>
************************************************************/
#include"CircularBuffer.h"

int main() {
    CircularBuffer obj(5);

    // should throw an exception -- good
    // CircularBuffer obj2(0);

    // should be empty -- good
    if (obj.isEmpty()) {
        std::cout <<"is empty" << std::endl;
    }
    // should not print -- good
    if (obj.isFull()) {
        std::cout <<"is Full" << std::endl;
    }
    // should throw an exception -- good
    // cout << obj.peek();

    std::cout << "size: " << obj.size() << std::endl;
    obj.enqueue(1);
    std::cout << "size: " << obj.size() << std::endl;
    obj.enqueue(2);
    std::cout << "size: " << obj.size() << std::endl;
    obj.enqueue(3);
    std::cout << "size: " << obj.size() << std::endl;
    obj.enqueue(4);
    std::cout << "size: " << obj.size() << std::endl;
    obj.enqueue(5);
    std::cout << "size: " << obj.size() << std::endl;

    // should display 1 -- good
    std::cout << "peek: " << obj.peek() << std::endl;

    // should be full -- good
    if (obj.isFull()) {
        std::cout << "is Full" << std::endl;
    }

    // should not print -- good
    if (obj.isEmpty()) {
        std::cout<< "is empty" << std::endl;
    }

    // should throw an exception -- good
    // obj.enqueue(6);

    obj.dequeue();

    // size should be 4 - good
    std::cout << "size: " << obj.size() << std::endl;

    // should display 2 -- good
    std::cout << "peek: " << obj.peek() << std::endl;

    // should be able to enqueue again - good
    obj.enqueue(7);

    // size should be 5 -- good
    std::cout << "size: " << obj.size() << std::endl;

    return 0;
}
