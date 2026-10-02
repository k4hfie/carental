#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car {
private:
    int license_plate;
    int year;
    bool available;
    std::string name;
    int capacity;
    int daily_rate;
protected:
    //helper functoin
    bool isNegative(int num, const std::string& type) const;

    //get functions
    int getCapacity() const;
    int getLicensePlate() const;
    int getYear() const;
    std::string getName() const;
    bool getAvailability() const;
    int getDailyRate() const;
    
public:
    Car(int license, int yr, int caps, const std::string& n, int rate);
    virtual ~Car();
    virtual void displayData() const = 0;
    void changeRate(int new_rate);
    void setAvailability(bool avail);
    double calculatePrice(int totaldays) const;
    virtual double penalty(int extradays) const = 0;
};

class ElectricCar : public Car {
private:
    std::string plug_type;
    double charging_time;

public:
    ElectricCar(
        int license_plate,
        int year,
        int caps,
        const std::string& name,
        int daily_rate,
        const std::string& plug_type,
        double charging_time
    );

    double penalty(int extradays) const override;
    void displayData() const override;
};

class LuxuryCar : public Car {
private:
    bool includes_driver;
    bool leather_interior;

public:
    LuxuryCar(
        int license_plate,
        int year,
        int caps,
        const std::string& name,
        int daily_rate,
        bool includes_driver,
        bool leather_interior
    );

    double penalty(int extradays) const override;
    void displayData() const override;
};

class EconomyCar : public Car {
private:
    std::string transmission_type;
    int trunk_cap;

public:
    EconomyCar(
        int license_plate,
        int year,
        int caps,
        const std::string& name,
        int daily_rate,
        const std::string& transmission_type,
        int trunk_capacity
    );

    double penalty(int extradays) const override;
    void displayData() const override;
};

#endif