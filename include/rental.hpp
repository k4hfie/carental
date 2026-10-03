#ifndef RENTAL_HPP
#define RENTAL_HPP

#include <car.hpp>
#include <payment.hpp>
#include <vector>
#include <memory>

class Rental {
protected:    
    static bool isCarAvaliable(std::unique_ptr<Car>& cars);
    static double calculateTotal(std::vector<std::unique_ptr<Car>>& cart);

public:
    static void displayOptions(std::vector<std::unique_ptr<Car>>& cars);

    static void rentCar(std::vector<std::unique_ptr<Car>>& cart, std::unique_ptr<Car> car);
    static void displayCart(std::vector<std::unique_ptr<Car>>& cart);
    static void emptyCart(std::vector<std::unique_ptr<Car>>& cart);
    
    static void processBill(std::vector<std::unique_ptr<Car>>& cart);
    static void processPayment(std::vector<std::unique_ptr<Car>>& cart);
    static void processRental(std::vector<std::unique_ptr<Car>>& cart);
};

#endif