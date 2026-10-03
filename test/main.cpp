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
    

    Rental::displayOptions(cars);

    Rental::rentCar(shopping_cart, std::move(cars[0])); 
    std::cout << "\n";
    Rental::rentCar(shopping_cart, std::move(cars[2])); 
    std::cout << "\n";

    Rental::processBill(shopping_cart);
    Rental::processPayment(shopping_cart);
    return 0;
}