#include "car.hpp"
#include "rental.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <limits>

int main() {
    std::vector<std::unique_ptr<Car>> cars;

    cars.push_back(std::make_unique<ElectricCar>(
        1001, 2024, 5, "Tesla Model 3", 100, "Type 2", 6.0
    ));

    cars.push_back(std::make_unique<LuxuryCar>(
        1002, 2023, 4, "Mercedes-Benz S-Class", 200, true, true
    ));

    cars.push_back(std::make_unique<EconomyCar>(
        1003, 2022, 5, "Toyota Yaris", 40, "Automatic", 300
    ));

    int choice;

    do {
        std::cout << "\n Retail System Menu: (Choose One Please)\n";
        std::cout << "1. Display inventory\n";
        std::cout << "2. Add electric car\n";
        std::cout << "3. Add luxury car\n";
        std::cout << "4. Add economy car\n";
        std::cout << "5. Change car daily rate\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < cars.size(); ++i) {
                    std::cout << "\nIndex: " << i << '\n';
                    if (cars[i] != nullptr) {
                        cars[i]->displayData();
                    } else {
                        std::cout << "Car pointer is null.\n";
                    }
                }
                break;

            case 2: {
                int plate, year, capacity, rate;
                std::string name, plug;
                double charge;

                std::cout << "License plate (Fully numerical): ";
                std::cin >> plate;
                std::cout << "Year, capacity, name, daily rate ($): ";
                std::cin >> year >> capacity >> name >> rate;
                std::cout << "Charging time (hours): ";
                std::cin >> charge;               
                std::cout << "Plug type: ";
                std::getline(std::cin >> std::ws, plug);

                cars.push_back(std::make_unique<ElectricCar>(
                    plate, year, capacity, name, rate, plug, charge
                ));
                break;
            }

            case 3: {
                int plate, year, capacity, rate;
                std::string name;
                bool driver, leather;

                std::cout << "License plate (Fully numerical): ";
                std::cin >> plate;
                std::cout << "Year, capacity, name, daily rate ($): ";
                std::cin >> year >> capacity >> name >> rate;
                std::cout << "Includes driver (0/1): ";
                std::cin >> driver;
                std::cout << "Leather interior (0/1): ";
                std::cin >> leather;

                cars.push_back(std::make_unique<LuxuryCar>(
                    plate, year, capacity, name, rate, driver, leather
                ));
                break;
            }

            case 4: {
                int plate, year, capacity, rate, trunk;
                std::string name, transmission;

                std::cout << "License plate (Fully numerical): ";
                std::cin >> plate;
                std::cout << "Year, capacity, name, daily rate ($): ";
                std::cin >> year >> capacity >> name >> rate;
                std::cout << "Trunk capacity (L): ";
                std::cin >> trunk;
                std::cout << "Transmission type: ";
                std::getline(std::cin >> std::ws, transmission);

                cars.push_back(std::make_unique<EconomyCar>(
                    plate, year, capacity, name, rate,
                    transmission, trunk
                ));
                break;
            }

            case 5: {
                int index;
                int newRate;

                for (int i = 0; i < cars.size(); ++i) {
                    std::cout << "\nIndex: " << i << '\n';
                    if (cars[i] != nullptr) {
                        cars[i]->displayData();
                    }
                }

                std::cout << "\nCar index: ";
                std::cin >> index;

                if (index >= cars.size() || cars[index] == nullptr || index < 0) {
                    std::cout << "Invalid car index.\n";
                    break;
                }

                std::cout << "New daily rate: ";
                std::cin >> newRate;

                cars[index]->changeRate(newRate);
                std::cout << "Rate updated\n";
                break;
            }

            case 0:
                std::cout << "Exiting retailer system.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}