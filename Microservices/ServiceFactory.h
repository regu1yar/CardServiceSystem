//
// ServiceFactory.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_SERVICEFACTORY_H
#define CARD_SERVICE_SYSTEM_SERVICEFACTORY_H

#include <memory>
#include "Microservices/BankService.h"
#include "HealthInsuranceService.h"
#include "PassportOfficeService.h"


/**
 * @brief Service factory
 * @details Constructs services like bank service,
 * health insurance service
 * and passport office service
 */
class ServiceFactory {
public:
    /**
     * @brief Constructs bank service
     * @details Constructs default implementation
     * @return Pointer to IBankService
     */
    std::shared_ptr<IBankService> getBankService() const;

    /**
     * @brief Constructs health insurance service
     * @details Constructs cached implementation
     * @return Pointer to IHealthInsuranceService
     */
    std::shared_ptr<IHealthInsuranceService> getHealthInsuranceService() const;

    /**
     * @brief Constructs passport office service
     * @details Constructs cached implementation
     * @return Pointer to IPassportOfficeService
     */
    std::shared_ptr<IPassportOfficeService> getPassportOfficeService() const;
};


#endif //CARD_SERVICE_SYSTEM_SERVICEFACTORY_H
