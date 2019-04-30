//
// PassportOfficeService.h
//
// Created by Роман Климовицкий on 06.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_PASSPORTOFFICESERVICE_H
#define CARD_SERVICE_SYSTEM_PASSPORTOFFICESERVICE_H

#include <string>
#include <iostream>
#include <memory>
#include <chrono>
#include <map>
#include "Utils/Date.h"
#include "Utils/Passport.h"


/**
 * @brief Passport office service interface
 */
class IPassportOfficeService {
public:
    /**
     * @brief Returns client's passport with specified id
     * @param[in] id Client's id
     * @return Client's passport
     */
    virtual std::shared_ptr<Passport> getPassport(size_t id) = 0;
};


/**
 * @brief Default passport office service implementation
 * @details Inherits from passport office service interface
 */
class PassportOfficeService : public IPassportOfficeService {
public:
    /**
     * @brief Returns client's passport with specified id
     * @details Sends request directly to the server
     * @param[in] id Client's id
     * @return Client's passport
     */
    virtual std::shared_ptr<Passport> getPassport(size_t id);
};


/**
 * @brief Cached passport office service implementation
 * @details Proxy for standard implementation.
 * Inherits from passport office service interface.
 * Contains pointer to standard service implementation,
 * last update time and map from passports.
 */
class CachedPassportOfficeService : public IPassportOfficeService {
private:
    std::shared_ptr<PassportOfficeService> service_;
    std::chrono::steady_clock::time_point lastUpdate_;
    std::map<size_t, std::shared_ptr<Passport>> passports_;

    static const std::chrono::hours updateInterval_;

    /**
     * @brief Data reset
     * @details Resets last update time and clear passports map
     */
    void reset();

    /**
     * @brief Up-to-date checker
     * @details Checks if it is time to update data
     * @return True if more than updateInterval_ time passed from the last update, false otherwise
     */
    bool needUpdate() const;

public:
    /**
     * @brief Cached passport office service constructor
     * @details Sets default fields
     */
    CachedPassportOfficeService();

    /**
     * @brief Returns client's passport with specified id
     * @details Sends request directly to the server if only it's needed
     * @param[in] id Client's id
     * @return Client's passport
     */
    virtual std::shared_ptr<Passport> getPassport(size_t id);
};


#endif //CARD_SERVICE_SYSTEM_PASSPORTOFFICESERVICE_H
