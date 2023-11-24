#pragma once

#include <iostream>
#include <string>

class Horse {
  private:
    std::string name;
    std::string rider;
    int maxRunningDistancePerSecond;
    int distanceTraveled;
    int racesWon;

  public:
    Horse();
    void runASecond();
    void sendToGate();
    void displayHorse(int);

    /* --- Accessors --- */
    int getRacesWon();
    int getDistanceTraveled();
    std::string getHorseName();
    std::string getRiderName();

    /* --- Mutators --- */
    void setRacesWon();
    void setHorseName(std::string);
    void setRiderName(std::string);
    void setMaxRunningSpeed(int);
};