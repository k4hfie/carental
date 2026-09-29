#include "car.hpp"
#include <iostream>

Car::Car(int license, int yr, int caps, const std::string& n, int rate):
    license_plate(license), year(yr), available(true), name(n), capacity(caps), daily_rate(rate)
{
    if (license < 0 || yr < 0 || caps < 0 || rate < 0) {
        license_plate = 0;
        year = 0;
        capacity = 0;
        daily_rate = 0;
    }
}

ElectricCar::ElectricCar(int license, int year,  int caps, const std::string& name, int dailyrate, const std::string& plug_type, double charge):
    Car(license, year, caps, name, dailyrate), plug_type(plug_type), charging_time(charge)
{
    if (charge < 0) {
        charging_time = 0.0;
    }
}

LuxuryCar::LuxuryCar(int license, int year, int caps, const std::string& name, int dailyrate, bool includes_driver, bool leather_interior):
    Car(license, year, caps, name, dailyrate), includes_driver(includes_driver), leather_interior(leather_interior)
{
}

EconomyCar::EconomyCar(int license, int year, int caps, const std::string& name, int dailyrate, const std::string& transmission_type, int trunk_capacity):
    Car(license, year, caps, name, dailyrate), transmission_type(transmission_type), trunk_cap(trunk_capacity)
{
    if (trunk_cap < 0) {
        trunk_cap = 0;
    }
}

Car::~Car() {}

int Car::getDailyRate() const {
    return daily_rate;
}

int Car::getCapacity() const {
    return capacity;
}

int Car::getLicensePlate() const {
    return license_plate;
}

int Car::getYear() const {
    return year;
}

std::string Car::getName() const {
    return name;
}

bool Car::getAvailability() const {
    return available;
}

void Car::setAvailability(bool avail) {
        available = avail;
}

int Car::calculateprice(int totaldays) const {
    if(totaldays < 0) {
        std::cerr << "Error!!!! Total days cannot be negative.\n";
        return 0;
    }
    return totaldays * daily_rate;
}

void Car::changeRate(int new_rate) {
    if (new_rate >= 0) {
        daily_rate = new_rate;
    } else {
        std::cerr << "Error!!!! Daily rate cannot be negative\n";
    }
}

double ElectricCar::penalty(int extradays) const {
    if(extradays < 0) {
        std::cerr << "Error!!!! Extra days cannot be negative.\n";
        return 0.0;
    }
    return extradays * getDailyRate() * 1.0;
}

double LuxuryCar::penalty(int extradays) const {
    if(extradays < 0) {
        std::cerr << "Error!!!! Extra days cannot be negative.\n";
        return 0.0;
    }
    return extradays * getDailyRate() * 2.5;
}

double EconomyCar::penalty(int extradays) const {
    if(extradays < 0) {
        std::cerr << "Error!!!! Extra days cannot be negative.\n";
        return 0.0;
    }
    return extradays * getDailyRate() * 0.5;
}

void ElectricCar::displayData() const {
    std::cout << "Electric Car: " << getName() << ", License Plate: " << getLicensePlate() 
              << ", Year: " << getYear() << ", Daily Rate: $" << getDailyRate() 
              << ", Plug Type: " << plug_type << ", Charging Time: " << charging_time << " hours\n";
}

void LuxuryCar::displayData() const {
    std::cout << "Luxury Car: " << getName() << ", License Plate: " << getLicensePlate() 
              << ", Year: " << getYear() << ", Daily Rate: $" << getDailyRate() 
              << ", Includes Driver: " << (includes_driver ? "Ya" : "Tidak") 
              << ", Leather Interior: " << (leather_interior ? "Ya" : "Tidak") << "\n";
}

void EconomyCar::displayData() const {
    std::cout << "Economy Car: " << getName() << ", License Plate: " << getLicensePlate() 
              << ", Year: " << getYear() << ", Daily Rate: $" << getDailyRate() 
              << ", Transmission Type: " << transmission_type
              << ", Trunk Capacity: " << trunk_cap << " liters\n";
}
