
#ifndef STRQUEUE_H
#define STRQUEUE_H


#include <cstdio>
#include <cstring>

template<size_t Capacity, size_t StringLen>
class strqueue {
private:
    char buffer[Capacity][StringLen];
    size_t head, tail, count;

public:
    strqueue() : head(0), tail(0), count(0) {}

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == Capacity; }

    bool push(const char* str) {
        if (isFull()) return false;
        strncpy(buffer[tail], str, StringLen - 1);
        buffer[tail][StringLen - 1] = '\0';
        tail = (tail + 1) % Capacity;
        count++;
        return true;
    }

    bool pop() {
        if (isEmpty()) return false;
        head = (head + 1) % Capacity;
        count--;
        return true;
    }

    const char* peek() const {
        return buffer[head];
    }
};

#endif
