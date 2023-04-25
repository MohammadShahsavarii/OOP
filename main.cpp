#include <iostream>
#include <string>
using namespace std;

class Door {
private:
    bool isOpen;

public:
    void open();
    void close();
    bool isOpened();
};

void Door::open() {
    isOpen = true;
}

void Door::close() {
    isOpen = false;
}

bool Door::isOpened() {
    return isOpen;
}

class Lamp {
private:
    int brightness;
    bool isOpen;

public:
    void on();
    void off();
    void setBrightness(int brightness);
};

void Lamp::on() {
    isOpen = true;
}

void Lamp::off() {
    isOpen = false;
}

void Lamp::setBrightness(int brightness) {
    this->brightness = brightness;
}

class HVAC {
private:
    int temperature;
    bool isOn;

public:
    void turnOn();
    void turnOff();
    void setTemperature(int temperature);
};

void HVAC::turnOn() {
    isOn = true;
}

void HVAC::turnOff() {
    isOn = false;
}

void HVAC::setTemperature(int temperature) {
    this->temperature = temperature;
}

class TV {
private:
    bool isOn;
    int channel;
    int volume;

public:
    void turnOn();
    void turnOff();
    void changeChannel(int channel);
    void changeVolume(int volume);
};

void TV::turnOn() {
    isOn = true;
}

void TV::turnOff() {
    isOn = false;
}

void TV::changeChannel(int channel) {
    this->channel = channel;
}

void TV::changeVolume(int volume) {
    this->volume = volume;
}

int main() {
    // your code here
    return 0;
}

