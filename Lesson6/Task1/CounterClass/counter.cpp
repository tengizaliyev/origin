#include "Counter.h"

Counter::Counter(int initial) : count(initial) {}

void Counter::increment() {
    count++;
}

void Counter::decrement() {
    count--;
}

int Counter::getValue() const {
    return count;
}
