//StringSound.h
#include"CircularBuffer.h"

class StringSound {
 public:
    explicit StringSound (double frequency);
    explicit StringSound (vector<sf::Int16> init);
    StringSound (const StringSound &obj) = delete; // no copy const
    ~StringSound();
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
 private:
    CircularBuffer * _cb;
    int _time;
};