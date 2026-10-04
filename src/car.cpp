#include "car.hpp"
#include <iostream>

// Helper functions
bool Car::isNegative(int num, const std::string& type) const {
    if (num >= 0) {
        return false;
    }

    std::cerr << "error: " << type << " cannot be negative\n";
    return true;
}

Car::Car(
    int license, int yr,
    int caps,
    const std::string& n,
    int rate
):
    license_plate(license),
    year(yr),
    available(true),
    name(n),
    capacity(caps),
    daily_rate(rate)
{
    // Checks for negative values;
    if (isNegative(license, "License plate")) {
        license_plate = 0;
    }

    if (isNegative(yr, "Year")) {
        year = 0;
    }

    if (isNegative(caps, "Capacity")) {
        capacity = 0;
    }

    if (isNegative(rate, "Daily rate")) {
        daily_rate = 0;
    }
}

Car::~Car() {}

// Get functions of parent class
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

void Car::setDay(int day) {
    total_days = day;
}

double Car::calculatePrice() const {
    return total_days * daily_rate;
}

void Car::changeRate(int new_rate) {
    if (isNegative(new_rate, "New rate")) {
        return;
    }

    daily_rate = new_rate;
}

// Constructors of child classes
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
    if(isNegative(charge, "Charge")){
        charging_time = 0;
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
{}

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
    if (isNegative(trunk_cap, "Trunk capacity")){
        trunk_cap = 0;
    }
}

void ElectricCar::displayData() const {
    std::cout << "\tELECTRIC CAR\n";
    std::cout << "Name:\t\t\t" << getName() << "\n";
    std::cout << "License Plate:\t\t" << getLicensePlate() << "\n";
    std::cout << "Year:\t\t\t" << getYear() << "\n";
    std::cout << "Daily Rate:\t\t$" << getDailyRate() << "\n";
    std::cout << "Plug Type:\t\t" << plug_type << "\n";
    std::cout << "Charging Time:\t\t" << charging_time << " Hours\n";
}

void LuxuryCar::displayData() const {
    std::cout << "\t LUXURY CAR\n";
    std::cout << "Name:\t\t\t" << getName() << "\n";
    std::cout << "License Plate:\t\t" << getLicensePlate() << "\n";
    std::cout << "Year:\t\t\t" << getYear() << "\n";
    std::cout << "Daily Rate:\t\t$" << getDailyRate() << "\n";
    std::cout << "Includes Driver:\t" << (includes_driver ? "Yes\n" : "No\n");
    std::cout << "Leather Interior:\t" << (leather_interior ? "Yes\n" : "No\n");
}

void EconomyCar::displayData() const {
    std::cout << "\t ECONOMY CAR\n";
    std::cout << "Name:\t\t\t" << getName() << "\n";
    std::cout << "License Plate:\t\t" << getLicensePlate() << "\n";
    std::cout << "Year:\t\t\t" << getYear() << "\n";
    std::cout << "Daily Rate:\t\t$" << getDailyRate() << "\n";
    std::cout << "Transmission Type:\t" << transmission_type << "\n";
    std::cout << "Trunk Capacity:\t\t" << trunk_cap << " L\n";
}