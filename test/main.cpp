#include "car.hpp"
#include "payment.hpp"
#include "rental.hpp"

#include <iostream>

int main(){
    std::vector<std::unique_ptr<Car>> cars;
    std::vector<std::unique_ptr<Car>> shopping_cart;
    
    cars.push_back(std::make_unique<ElectricCar>(
        2222, 2023, 100, "Tesla", 50, 5, "Type b", 1.5
    ));

    cars.push_back(std::make_unique<LuxuryCar>(
        1111, 2015, 200, "BMW", 150, 5, true, true
    ));
    cars.push_back(std::make_unique<EconomyCar>(
        3333, 2022, 50, "Brio", 5, 10, "Automatic", 200
    ));
    

    auto rental = std::make_unique<Rental>(cars, shopping_cart);

    rental->displayCars();

    rental->rentCar(std::move(cars[0])); 
    std::cout << "\n";

    rental->rentCar(std::move(cars[2])); 
    std::cout << "\n";

    rental->processBill();
    rental->processPayment();
    return 0;
}