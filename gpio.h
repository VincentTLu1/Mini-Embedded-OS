#pragma once

//The different types of states that can be used
enum PinState {
    LOW = 0,
    HIGH = 1
};

// GPIO class to define the different types of pins available
class GPIO {
public:
    int id;
    PinState state;

    GPIO(int pin);

    void write(PinState s);
    void toggle();
};

// make these visible to other files
extern GPIO LED1;
extern GPIO LED2;