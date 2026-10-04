#include "rental.hpp"
#include <iostream>

bool Rental::isCarAvaliable(std::unique_ptr<Car>& car){
    return car->getAvailability();
}

double Rental::calculateTotal(){
    double total = 0;
    for (auto& item : cart){
        total += item->calculatePrice();
    }
    return total;
}

void Rental::displayCars() const{
    std::cout << "\t\t CAR DISPLAY\n";
    std::cout << "--------------------------------------------\n";
    for (auto& item : cars){
        item->displayData();
        std::cout << "\n";
    }
}

void Rental::rentCar(std::unique_ptr<Car>& car){
    if (!isCarAvaliable(car)){
        std::cout << "error: Car not Avaliable!\n";
        return;
    }

    int days;
    std::cout << "Renting: " << car->getName() << "\n";
    std::cout << "Enter amount of days: "; std::cin >> days;
    car->setDay(days);

    // do not call displayOptions() after renting a car;
    // the original car pointer is set to null ptr;
    cart.push_back(std::move(car));
}

void Rental::processBill(){
    double total = calculateTotal();

    std::cout << "\t\t BILL\n";
    std::cout << "--------------------------------------------\n";
    for (auto& item : cart){
        std::cout << item->getName()<< "\t\t\t$" << item->calculatePrice() << "\n";
    }
    std::cout << "--------------------------------------------\n";
    std::cout << "Total:\t\t\t$" << total <<"\n";
}

void Rental::processPayment(){
    int choice;
    double amount = calculateTotal();
    std::unique_ptr<Payment> payment;

    std::cout << "\nWhich payment method would you like to use?\n";
    std::cout << "1. Credit Card, 2. Bank Transfer, 3. EWallet, 4. Exit First\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Enter: "; std::cin >> choice; std::cout << "\n";

    switch (choice) {
        case 1: {
            std::string cn; int cv;
            std::cout << "Please enter your credentials.\n";
            std::cout << "--------------------------------------------\n";
            std::cout << "Card Number: "; std::cin >> cn;
            std::cout << "CVV: "; std::cin >> cv;

            payment = std::make_unique<CreditCard>(cn, cv);
            break;
        }

        case 2: {
            long ba;
            std::cout << "Please enter your credentials.\n";
            std::cout << "Bank Number: "; std::cin >> ba;

            payment = std::make_unique<BankTransfer>(ba);
            break;
        }

        case 3: {
            std::string pn; std::string pi;
            std::cout << "Please enter your credentials.\n";
            std::cout << "Phone Number: "; std::cin >> pn;
            std::cout << "PIN: "; std::cin >> pi;

            payment = std::make_unique<EWallet>(pn, pi);
            break;
        }

        case 4:
            std::cout << "Exiting payment process.\n";
            return;

        default:
            std::cout << "error: Invalid payment option!\n";
    }

    std::cout << "\n";
    payment->pay(amount);
}

void Rental::processRental(){
    processBill();
    processPayment();
}
