/*
 relay
*/
// © 2noodles llc
// minh@2noodles.com

#ifndef Relay_h
#define Relay_h

#include "Arduino.h"
#include "Device.h"

class Relay : public Device
{
  public:
    Relay(char *in_name, int in_pin, int in_dependent_device_id);
    ~Relay() {}; // destructor

    void loop(); // required
    void switchOn();
    void switchOff();
    void toggleState();
    
    void setEvent(char *in_string); // override
    void getEvent(char *string); // override
    
    int getDependentDevice(); // override
    void setDependentDevice(int id); // override
    
    int dependentDeviceId;
    Device *dependentDeviceObject;
    
    
  private:
    boolean isDay;
    uint8_t timedIndexCounter;
    int hour[5];
    int minute[5];
    int second[5];
    int hourDuration[5];
    int minuteDuration[5];
    int secondDuration[5];
    char dow[5][8];
    
};//need ; at the end of a class def

#endif