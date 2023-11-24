/* Sam Irvin
    CMP SCI 2250 - Project 3
*/

// This program allows the user to simulate horse races with user named horses

#include <iostream>
#include <random>
#include "Horse.h"

int main() {
  Horse* raceBracket = nullptr;
  int* podium = nullptr;

  bool isRacingAgain = true;
  bool hasWinner = false;
  int numberOfHorses;
  int podiumPosition = 0;
  int raceDistance;
  int furthestHorseDistance = 0;
  int totalRaces = 0;
  int horsesInFirstPlace = 0;
  char playerAnswer;

  std::cout << "How many horses are in the race?" << std::endl;
  std::cin >> numberOfHorses;

  while (numberOfHorses < 0) {
    std::cout << "Sorry, there must be at least one horse to have a race." << std::endl << std::endl;
    std::cout << "How many horses are in the race?" << std::endl;
    std::cin >> numberOfHorses;
  }

  raceBracket = new Horse[numberOfHorses];

  for (int unnamedHorse = 0; unnamedHorse < numberOfHorses; unnamedHorse++) {
    std::random_device myEngine;
    std::uniform_int_distribution<int> randomInt(0, 100);
    int randomDistance = randomInt(myEngine);
    std::string horseName;
    std::string riderName;

    std::cout << "Please enter the name of horse number " << unnamedHorse + 1 << std::endl;
    std::cin >> horseName;

    std::cout << "Please enter the rider of horse number " << unnamedHorse + 1 << std::endl;
    std::cin >> riderName;

    raceBracket[unnamedHorse].setHorseName(horseName);
    raceBracket[unnamedHorse].setRiderName(riderName);
    raceBracket[unnamedHorse].setMaxRunningSpeed(randomDistance);
  }

  std::cout << "Please enter the length of the race: " << std::endl;
  std::cin >> raceDistance;

  while (raceDistance < 100) {
    std::cout << "Sorry, these horses must run at least 100 meters, please pick a longer track." << std::endl;
    std::cin >> raceDistance;
  };

  while (raceDistance > 10000) {
    std::cout << "Sorry, these horses can't run that far, please pick a shorter track" << std::endl;;
    std::cin >> raceDistance;
  }

  while (isRacingAgain) {
    char keepRacing;
    podium = new int[numberOfHorses];

    totalRaces++;

    while (!hasWinner) {
      for (int currentHorse = 0; currentHorse < numberOfHorses; currentHorse++) {
        raceBracket[currentHorse].runASecond();

        if (raceBracket[currentHorse].getDistanceTraveled() > furthestHorseDistance) {
          furthestHorseDistance = raceBracket[currentHorse].getDistanceTraveled();
        }
      
        raceBracket[currentHorse].displayHorse(raceDistance);
      }

      if (furthestHorseDistance >= raceDistance) {
        hasWinner = true;
      }

      std::cout << std::endl;
      std::cout << "Would you like to continue watching this race? Y / N " << std::endl << std::endl;
      std::cout << std::endl;
      std::cin >> keepRacing;

      if (keepRacing == 121 || keepRacing == 89) {
        continue;
      } else {
        std::cout << std::endl << std::endl;
        std::cout << "Thanks for watching this race!" << std::endl;
        std::cout << std::endl << std::endl;
        break;
      }
    }

    for (int finishedHorse = 0; finishedHorse < numberOfHorses; finishedHorse++) {
      if (raceBracket[finishedHorse].getDistanceTraveled() == furthestHorseDistance) {
        horsesInFirstPlace++;
        podium[podiumPosition] = finishedHorse;
        podiumPosition++;
      };
    };

    if (horsesInFirstPlace > 1) {
      std::random_device myEngine;
      std::uniform_int_distribution<int> randomInt(0, horsesInFirstPlace);
      int randomWinner = randomInt(myEngine);

      std::cout << raceBracket[podium[randomWinner]].getHorseName() << " has won the race!" << std::endl;
      raceBracket[podium[randomWinner]].setRacesWon();
    }
    else {
      std::cout << std::endl << std::endl;
      std::cout << raceBracket[podium[0]].getHorseName() << " has won the race!" << std::endl;
      std::cout << std::endl << std::endl;
      raceBracket[podium[0]].setRacesWon();
    }

    delete[] podium;

    for (int horse = 0; horse < numberOfHorses; horse++) {
      std::cout << raceBracket[horse].getHorseName() << " has won " << raceBracket[horse].getRacesWon() << "/" << totalRaces << " races." << std::endl;
      raceBracket[horse].sendToGate();
    }

    std::cout << std::endl << "Would you like to race again? Y / N " << std::endl;
    std::cin >> playerAnswer;
    std::cout << std::endl;

    if (playerAnswer == 121 || playerAnswer == 89) {
      hasWinner = false;
    } else {
      std::cout << std::endl << std::endl;
      std::cout << "Thanks for coming to the races!" << std::endl;
      isRacingAgain = false;
    };
  }

  delete[] raceBracket;

  return 0;
}