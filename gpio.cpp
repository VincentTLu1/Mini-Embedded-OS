#include "gpio.h"
#include <iostream>

//Set inital state to low similar to LED pin
GPIO::GPIO(int pin) : id(pin), state(LOW) {}

// Write the current state of the pin
void GPIO::write(PinState s) {
    state = s;
    std::cout << "[GPIO] Pin " << id << " -> " << (state == HIGH ? "HIGH" : "LOW") << "\n";
}

//Set the state of the LED pin to LOW or high depending on the previous state
void GPIO::toggle() {
    state = (state == HIGH) ? LOW : HIGH;
    std::cout << "[GPIO] Pin " << id << " toggled\n";
}

GPIO LED1(1);
GPIO LED2(2);