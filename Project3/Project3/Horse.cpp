#include "Horse.h"
#include <iostream>
#include <string>
#include <random>

/* --- Constructor --- */
Horse::Horse() {
  name = "";
  rider = "";
  maxRunningDistancePerSecond = 0;
  distanceTraveled = 0;
  racesWon = 0;
}

void Horse::runASecond() {
  distanceTraveled = distanceTraveled + maxRunningDistancePerSecond;
};

void Horse::sendToGate() {
  distanceTraveled = 0;
};

void Horse::displayHorse(int goalLine) {
  int raceDistance;
  int horseDistance;
  char* horseLocation = nullptr;

  if (goalLine > 1000) {
    raceDistance = ( goalLine / 100 ) + 2;
    horseDistance = distanceTraveled / 100;
  };

  if (goalLine > 100) {
    raceDistance = ( goalLine / 10) + 2;
    horseDistance = distanceTraveled / 10;
  }

  horseLocation = new char[raceDistance];

  for (int trackSection = 0; trackSection < raceDistance; trackSection++) {
    horseLocation[trackSection] = ' ';
  }

  horseLocation[0] = '|';
  horseLocation[raceDistance - 1] = '|';

  if (horseDistance >= raceDistance - 1) {
    horseLocation[raceDistance] = '>';
  } else {
    horseLocation[horseDistance + 1] = '>';
  }

  for (int meter = 0; meter <= raceDistance; meter++) {
    std::cout << horseLocation[meter];
  }

  std::cout << "  " << name << ", ridden by " << rider << std::endl;
};

/* --- Accessors --- */
int Horse::getRacesWon() {
  return racesWon;
};

int Horse::getDistanceTraveled() {
  return distanceTraveled;
};

std::string Horse::getHorseName() {
  return name;
};

std::string Horse::getRiderName() {
  return rider;
}

/* --- Mutators --- */
void Horse::setRacesWon() {
  racesWon++;
};

void Horse::setHorseName(std::string horseName) {
  name = horseName;
};

void Horse::setRiderName(std::string riderName) {
  rider = riderName;
};

void Horse::setMaxRunningSpeed(int speed) {
  maxRunningDistancePerSecond = speed;
};