#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Appliance {
protected:
    string brand;
    bool isOn;

public:
    Appliance(string _brand) : brand(_brand), isOn(false) {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class SmartAppliance : public Appliance {
protected:
    string network;
    string protocol;

public:
    SmartAppliance(string _brand, string _network, string _protocol)
        : Appliance(_brand), network(_network), protocol(_protocol) {}
    virtual void connect(string ssid, string password) = 0;
};

class Lock : public Appliance {
protected:
    bool isLocked;

public:
    Lock(string _brand) : Appliance(_brand), isLocked(false) {}
    void turnOn() override { isLocked = true; }
    void turnOff() override { isLocked = false; }
    bool getIsLocked() const { return isLocked; }
    void lock() { turnOn(); }
    void unlock() { turnOff(); }
};

class Fridge : public SmartAppliance {
private:
    int temperature;
    int humidity;

public:
    Fridge(string _brand, string _network, string _protocol)
        : SmartAppliance(_brand, _network, _protocol), temperature(4), humidity(50) {}
    void turnOn() override { isOn = true; }
    void turnOff() override { isOn = false; }
    void setTemperature(int t) { temperature = t; }
    void setHumidity(int h) { humidity = h; }
    void connect(string ssid, string password) override {}
};

class TV : public SmartAppliance {
private:
    int channel;
    int volume;

public:
    TV(string _brand, string _network, string _protocol)
        : SmartAppliance(_brand, _network, _protocol), channel(1), volume(50) {}
    void turnOn() override { isOn = true; }
    void turnOff() override { isOn = false; }
    void changeChannel(int c) { channel = c; }
    void changeVolume(int v) { volume = v; }
    void connect(string ssid, string password) override {}
};

class HomeTheater : public SmartAppliance {
private:
    vector<Appliance*> components;

public:
    HomeTheater(string _brand, string _network, string _protocol)
        : SmartAppliance(_brand, _network, _protocol) {}
    void turnOn() override {
        for (auto component : components) {
            component->turnOn();
        }
        isOn = true;
    }
    void turnOff() override {
        for (auto component : components) {
            component->turnOff();
        }
        isOn = false;
    }
    void addComponent(Appliance* component) { components.push_back(component); }
    void connect(string ssid, string password) override {}
};
class ConnectionFailedException : public exception {
public:
    const char* what() const noexcept override {
        return "Connection failed!";
    }
};
void sendMessage(SmartAppliance* appliance, string message) {
    TV* tv = dynamic_cast<TV*>(appliance);
    if (tv == nullptr) {
        throw invalid_argument("sendMessage can only be used with TV objects.");
    }
    //simulate connection failure
    throw ConnectionFailedException();
}

int main() {
    Lock door("Kwikset");
    Fridge fridge("Samsung", "WiFi", "MQTT");
    TV tv("Sony", "WiFi", "UPnP");
    HomeTheater homeTheater("Sony", "WiFi", "UPnP");
    homeTheater.addComponent(&tv);
    homeTheater.turnOn();
    fridge.setTemperature(2);
    door.lock();

   try {
    tv.connect("MyWiFi", "1234");
} catch (const ConnectionFailedException& e) {
    cout << "Error: " << e.what() << endl;
}
