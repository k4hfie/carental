#include "rental.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::vector<std::unique_ptr<Car>> cars;
    std::vector<std::unique_ptr<Car>> cart;

    cars.push_back(std::make_unique<ElectricCar>(
        1001, 2024, 5, "Tesla", 100, "Type 2", 6.0
    ));

    cars.push_back(std::make_unique<LuxuryCar>(
        1002, 2023, 4, "MercedesB", 200, true, true
    ));

    cars.push_back(std::make_unique<EconomyCar>(
        1003, 2022, 5, "Toyota Yaris", 40, "Automatic", 300
    ));

    Rental rental(cars, cart);
    int choice;

    do {
        std::cout << "\n CUSTOMER SYSTEM: \n";
        std::cout << "1. View all cars\n";
        std::cout << "2. Check availability and rent a car\n";
        std::cout << "3. View bill and pay\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) return 1;

        switch (choice) {
            case 1:
                for (int i = 0; i < cars.size(); ++i) {
                    if(cars[i] != nullptr) {
                        std::cout << "\nIndex: " << i << '\n';
                        cars[i]->displayData();
                    }
                }
                break;

            case 2: {
                int index;
                std::cout << "\nEnter car index: ";
                std::cin >> index;

                if (index >= cars.size() || cars[index] == nullptr || index < 0) {
                    std::cout << "Invalid selection.\n";
                    break;
                }

                rental.rentCar(cars[index]);
                break;
            }

            case 3:
                if (cart.empty()) {
                    std::cout << "Your cart is empty.\n";
                    break;
                }

                rental.processRental();
                break;

            case 0:
                std::cout << "Exiting customer system.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}