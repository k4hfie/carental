#include "car.hpp"
#include <iostream>

Car::Car(
    int license,
    int yr,
    int caps,
    const std::string& n,
    int rate
) :
    license_plate(license),
    year(yr),
    available(true),
    name(n),
    capacity(caps),
    daily_rate(rate)
{
    if (isNegative(license, "Error!!!! License plate cannot be negative.")) {
        license_plate = 0;
    }

    if (isNegative(yr, "Error!!!! Year cannot be negative.")) {
        year = 0;
    }

    if (isNegative(caps, "Error!!!! Capacity cannot be negative.")) {
        capacity = 0;
    }

    if (isNegative(rate, "Error!!!! Daily rate cannot be negative.")) {
        daily_rate = 0;
    }
}

ElectricCar::ElectricCar(
    int license,
    int year,
    int caps,
    const std::string& name,
    int dailyrate,
    const std::string& plug_type,
    double charge
) :
    Car(license, year, caps, name, dailyrate),
    plug_type(plug_type),
    charging_time(charge)
{
    if (charge < 0) {
        std::cerr << "Error!!!! Charging time cannot be negative.\n";
        charging_time = 0.0;
    }
}

LuxuryCar::LuxuryCar(
    int license,
    int year,
    int caps,
    const std::string& name,
    int dailyrate,
    bool includes_driver,
    bool leather_interior
) :
    Car(license, year, caps, name, dailyrate),
    includes_driver(includes_driver),
    leather_interior(leather_interior)
{
}

EconomyCar::EconomyCar(
    int license,
    int year,
    int caps,
    const std::string& name,
    int dailyrate,
    const std::string& transmission_type,
    int trunk_capacity
) :
    Car(license, year, caps, name, dailyrate),
    transmission_type(transmission_type),
    trunk_cap(trunk_capacity)
{
    if (isNegative(trunk_capacity, "Error!!!! Trunk capacity cannot be negative.")) {
        trunk_cap = 0;
    }
}

bool Car::isNegative(int num, const std::string& message) const {
    if (num >= 0) {
        return false;
    }

    std::cerr << message << "\n";
    return true;
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
    if (isNegative(totaldays, "Error!!!! Total days cannot be negative.")) {
        return 0;
    }

    return totaldays * daily_rate;
}

void Car::changeRate(int new_rate) {
    if (isNegative(new_rate, "Error!!!! Daily rate cannot be negative.")) {
        return;
    }

    daily_rate = new_rate;
}

double ElectricCar::penalty(int extradays) const {
    if (isNegative(extradays, "Error!!!! Extra days cannot be negative.")) {
        return 0.0;
    }

    return extradays * getDailyRate() * 1.0;
}

double LuxuryCar::penalty(int extradays) const {
    if (isNegative(extradays, "Error!!!! Extra days cannot be negative.")) {
        return 0.0;
    }

    return extradays * getDailyRate() * 2.5;
}

double EconomyCar::penalty(int extradays) const {
    if (isNegative(extradays, "Error!!!! Extra days cannot be negative.")) {
        return 0.0;
    }

    return extradays * getDailyRate() * 0.5;
}

void ElectricCar::displayData() const {
    std::cout << "Electric Car: " << getName()
              << ", License Plate: " << getLicensePlate()
              << ", Year: " << getYear()
              << ", Daily Rate: $" << getDailyRate()
              << ", Plug Type: " << plug_type
              << ", Charging Time: " << charging_time
              << " hours\n";
}

void LuxuryCar::displayData() const {
    std::cout << "Luxury Car: " << getName()
              << ", License Plate: " << getLicensePlate()
              << ", Year: " << getYear()
              << ", Daily Rate: $" << getDailyRate()
              << ", Includes Driver: " << (includes_driver ? "Ya" : "Tidak")
              << ", Leather Interior: " << (leather_interior ? "Ya" : "Tidak")
              << "\n";
}

void EconomyCar::displayData() const {
    std::cout << "Economy Car: " << getName()
              << ", License Plate: " << getLicensePlate()
              << ", Year: " << getYear()
              << ", Daily Rate: $" << getDailyRate()
              << ", Transmission Type: " << transmission_type
              << ", Trunk Capacity: " << trunk_cap
              << " liters\n";
}