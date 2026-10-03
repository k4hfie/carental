#include "payment.hpp"
#include <iostream>

// CREDITCARD
CreditCard::CreditCard(std::string cn, int cv):
    cardNumber(cn), cvv(cv)
{}

void CreditCard::pay(double amount) {
    std::cout << "Payment of $" << amount;
    std::cout << " with Credit Card Succesfull!\n";
}


// BANK
BankTransfer::BankTransfer(int ba):
    bankNumber(ba)
{}

void BankTransfer::pay(double amount) {
    std::cout << "Payment of $" << amount;
    std::cout <<" with Bank Transfer Succesfull!\n";
}


// EWALLET
EWallet::EWallet(std::string pn, std::string pi):
    phoneNumber(pn), pin(pi)
{}

void EWallet::pay(double amount) {
    std::cout << "Payment of $" << amount;
    std::cout <<" with E-Wallet Succesfull!\n";
}