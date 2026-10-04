#ifndef RENTAL_HPP
#define RENTAL_HPP

#include <car.hpp>
#include <payment.hpp>
#include <vector>
#include <memory>

class Rental {
private:
    std::vector<std::unique_ptr<Car>>& cars;
    std::vector<std::unique_ptr<Car>>& cart;

protected:    
    bool isCarAvaliable(std::unique_ptr<Car>& car);
    double calculateTotal();

public:
    Rental(std::vector<std::unique_ptr<Car>>& cs, std::vector<std::unique_ptr<Car>>& cr):
        cars(cs), cart(cr)
    {}

    void displayCars() const;
    void rentCar(std::unique_ptr<Car>& car);

    void processBill();
    void processPayment();
    void processRental();
};

#endif