#include "payment.hpp"

// CREDITCARD
CreditCard::CreditCard(std::string cn, int cv):
    cardNumber(cn), cvv(cv)
{}

void CreditCard::pay(double amount) {}


// BANK
BankTransfer::BankTransfer(long ba):
    bankAccount(ba)
{}

void BankTransfer::pay(double amount) {}


// EWALLET
EWallet::EWallet(std::string pn, std::string pi):
    phoneNumber(pn), pin(pi)
{}

void EWallet::pay(double amount) {}