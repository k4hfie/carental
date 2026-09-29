#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <string>

class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() = default;
};

class CreditCard : public Payment {
private:
    std::string cardNumber;
    int cvv;

public:
    CreditCard(std::string cn, int cv);
    void pay(double amount) override;
};

class BankTransfer : public Payment {
private:
    long bankAccount;

public:
    BankTransfer(long ba);
    void pay(double amount) override;
};

class EWallet : public Payment {
public:
    std::string phoneNumber;
    std::string pin;

public:
    EWallet(std::string pn, std::string pi);
    void pay(double amount) override;
};

#endif