//KSGuitarSim.cpp
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
using namespace std; //NOLINT

vector<sf::Int16> makeSamples(StringSound& gs) {  //NOLINT
    std::vector<sf::Int16> samples;

    gs.pluck();
    int duration = 8;  // seconds
    int i;
    for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
        gs.tic();
        samples.push_back(gs.sample());
    }

    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(
                300, 200), "SFML Plucked String Sound Lite");
    sf::Event event;
    double freq;
    vector<sf::Int16> samples;

    freq = CONCERT_A;
    StringSound gs1(freq);
    sf::Sound sound1;
    sf::SoundBuffer buf1;
    samples = makeSamples(gs1);
    cout << samples.size() << endl;
    if (!buf1.loadFromSamples(
                &samples[0], samples.size(), 2, SAMPLES_PER_SEC))
        throw std::runtime_error(
                "sf::SoundBuffer: failed to load from samples.");
    sound1.setBuffer(buf1);

    freq = CONCERT_A * pow(2, 3.0/12.0);
    StringSound gs2(freq);
    sf::Sound sound2;
    sf::SoundBuffer buf2;
    samples = makeSamples(gs2);
    cout << samples.size() << endl;
    if (!buf2.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
        throw std::runtime_error(
                "sf::SoundBuffer: failed to load from samples.");
    sound2.setBuffer(buf2);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::A:
                    sound1.play();
                    break;
                case sf::Keyboard::C:
                    sound2.play();
                    break;
                default:
                    break;
                }

            default:
                break;
            }

            window.clear();
            window.display();
        }
    }
    return 0;
}
