//
// BankService.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Microservices/BankService.h"

double BankService::getBalance(size_t id) {
    std::cout << "Client's balance request was sent to the server" << std::endl;
    std::cout << "Client's balance was received" << std::endl;
    return 0;
}

void BankService::payment(size_t id, double amount) {
    std::cout << "Payment request was sent to the server" << std::endl;
}

void BankService::income(size_t id, double amount) {
    std::cout << "Income request was sent to the server" << std::endl;
}
