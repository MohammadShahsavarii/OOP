#include <iostream>

using namespace std;

int main()
{

    class door
    {
    private:
        bool isOpen;

    public:
        void open();
        void close();
        bool isOpen();
    };



    class lamp
    {
    private:
        int brithness;
        bool isOpen;

    public:
        void on();
        void off();
        void brightness(int brightness);
    };



    class HVAC
    {
    private:
        int temperature;
        bool isOn;

    public:
        void turnon();
        void turnoff();
        void settemperature(int temperature());
    };



    class tv
    {
    private:
        bool isOn;
        int channel;
        int volume;

    public:
        void turnon();
        void turnoff();
        void changechannel(int channel);
        void changevolume(int volume);
    };
}
