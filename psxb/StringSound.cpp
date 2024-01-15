// StringSound.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps4b>
 *Instructor's name: <Dr. James Daly>
 *Date: <3/22/2022>
 *Sources Of Help: <classmates and professor + documentation>
************************************************************/
#include"CircularBuffer.h"
#include"StringSound.h"
#include<vector>
#include<memory>

StringSound::StringSound(double frequency) {
    mtime = 0;
    int i = 1;
    int mLength = ceil(SAMPLES_PER_SEC/frequency);
    length = mLength;
    buffer = std::make_shared<CircularBuffer>(length);
    while (i == 1) {
        if (buffer->isFull() == 0)
            buffer->enqueue(0);
        else
            i = 1;
    }
    auto f1 = [](int x){
        if (x == 0)
            throw std::runtime_error("buffer isn't full");
    };
    f1(static_cast<int>(buffer->isFull()));
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    mtime = 0;
    buffer = std::make_shared<CircularBuffer>(length);
    for (size_t i = 0; i < init.size(); i++) {
        buffer->enqueue(init[i]);
    }
}


void StringSound::pluck() {
    for (int i = 0; i < length; i++) {
        std::default_random_engine randomGenerator;
        randomGenerator.seed(
            std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> random(0, 1);
        double num = random(randomGenerator) - 0.5;
        if (num > 0.5)
            throw std::runtime_error("bad num being generated");
        buffer->enqueue(num);
    }
}

void StringSound::tic() {
    double m1 = buffer->dequeue();
    double m2 = sample();
    buffer->enqueue(DECAY * (m1 + m2) / 2);
    mtime++;
}

sf::Int16 StringSound::sample() {
    return buffer->peek();
}

int StringSound::time() {
    return mtime;
}
