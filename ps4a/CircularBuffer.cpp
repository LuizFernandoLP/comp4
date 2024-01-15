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

CircularBuffer::CircularBuffer(size_t capacity) {
     if (capacity < 1)
          throw std::invalid_argument(
          "CircularBuffer constructor: capacity must be greater than zero.");
    m_capacity = capacity;
    front = -1;
    back = -1;
    arr = new int16_t[capacity];
}

size_t CircularBuffer::size() {
    if (isFull())
        return m_capacity;
    else if (isEmpty())
        return 0;
    else
        return back - front + 1;
}
bool CircularBuffer::isEmpty() {
    if (front == -1)
        return true;
    else
        return false;
}
bool CircularBuffer::isFull() {
    if ((back+1)%static_cast<int>(m_capacity) == front)
        return true;
    else
        return false;
}
void CircularBuffer::enqueue(int16_t x) {
        if (isFull())
            throw std::runtime_error("enqueue: can't enqueue to a full ring.");
        else if (isEmpty())
            front = front + 1;
        back = (back+1) % m_capacity;
        arr[back] = x;
}
int16_t CircularBuffer::dequeue() {
    if (isEmpty())
        throw std::runtime_error("dequeue: can't dequeue to an empty ring.");
    int16_t var = arr[front];
    if (front == back) {
        front = -1;
        back = -1;
    } else {
        front = (front+1)% m_capacity;
    }
    return var;
}
int16_t CircularBuffer::peek() {
    if (isEmpty())
        throw std::runtime_error("peek: can't peek to an empty ring.");
    return arr[front];
}
