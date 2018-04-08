//
// HealthInsuranceService.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_HEALTHINSURANCESERVICE_H
#define CARD_SERVICE_SYSTEM_HEALTHINSURANCESERVICE_H

#include <string>
#include <iostream>
#include <memory>
#include <chrono>
#include <map>
#include "Utils/Date.h"
#include "Utils/Policy.h"


/**
 * @brief Health insurance service interface
 */
class IHealthInsuranceService {
public:
    /**
     * @brief Returns client's policy with specified id
     * @param[in] id Client's id
     * @return Client's policy
     */
    virtual std::shared_ptr<Policy> getPolicy(size_t id) = 0;
};


/**
 * @brief Default health insurance service implementation
 * @details Inherits from health insurance service interface
 */
class HealthInsuranceService : public IHealthInsuranceService {
public:
    /**
     * @brief Returns client's policy with specified id
     * @details Sends request directly to the server
     * @param[in] id Client's id
     * @return Client's policy
     */
    virtual std::shared_ptr<Policy> getPolicy(size_t id);
};


/**
 * @brief Cached health insurance service implementation
 * @details Proxy for standard implementation.
 * Inherits from health insurance service interface.
 * Contains pointer to standard service implementation,
 * last update time and map from policies.
 */
class CachedHealthInsuranceService : public IHealthInsuranceService {
private:
    std::shared_ptr<HealthInsuranceService> service_;
    std::chrono::steady_clock::time_point lastUpdate_;
    std::map<size_t, std::shared_ptr<Policy>>  policies_;

    static const std::chrono::hours updateInterval_;

    /**
     * @brief Data reset
     * @details Resets last update time and clear policies map
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
     * @brief Cached health insurance service constructor
     * @details Sets default fields
     */
    CachedHealthInsuranceService();

    /**
     * @brief Returns client's policy with specified id
     * @details Sends request directly to the server if only it's needed
     * @param[in] id Client's id
     * @return Client's policy
     */
    virtual std::shared_ptr<Policy> getPolicy(size_t id);
};


#endif //CARD_SERVICE_SYSTEM_HEALTHINSURANCESERVICE_H
