//
// BankService.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_BANKSERVICE_H
#define CARD_SERVICE_SYSTEM_BANKSERVICE_H

#include <string>
#include <iostream>
#include <memory>
#include <chrono>


/**
 * @brief Bank service interface
 */
class IBankService {
public:
    /**
     * @brief Returns client's balance with specified id
     * @param[in] id Client's id
     * @return Client's balance
     */
    virtual double getBalance(size_t id) = 0;

    /**
     * @brief Sends payment request to the client's account
     * with specified id
     * with specified amount
     * @param[in] id Client's id
     * @param[in] amount Payment amount
     */
    virtual void payment(size_t id, double amount) = 0;

    /**
     * @brief Sends income request to the client's account
     * with specified id
     * with specified amount
     * @param[in] id Client's id
     * @param[in] amount Income amount
     */
    virtual void income(size_t id, double amount) = 0;
};


/**
 * @brief Default bank service implementation
 * @details Inherits from bank service interface
 */
class BankService : public IBankService {
public:
    /**
     * @brief Returns client's balance with specified id
     * @details Sends request directly to the server
     * @param[in] id Client's id
     * @return Client's balance
     */
    virtual double getBalance(size_t id);

    /**
     * @brief Sends payment request to the client's account
     * with specified id
     * with specified amount
     * @details Sends request directly to the server
     * @param[in] id Client's id
     * @param[in] amount Payment amount
     */
    virtual void payment(size_t id, double amount);

    /**
     * @brief Sends income request to the client's account
     * with specified id
     * with specified amount
     * @details Sends request directly to the server
     * @param[in] id Client's id
     * @param[in] amount Income amount
     */
    virtual void income(size_t id, double amount);
};


#endif //CARD_SERVICE_SYSTEM_BANKSERVICE_H
