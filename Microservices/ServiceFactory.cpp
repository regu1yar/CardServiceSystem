//
// ServiceFactory.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Microservices/ServiceFactory.h"


std::shared_ptr<IBankService> ServiceFactory::getBankService() const { return std::make_shared<BankService>(); }

std::shared_ptr<IHealthInsuranceService> ServiceFactory::getHealthInsuranceService() const {
    return std::make_shared<CachedHealthInsuranceService>();
}

std::shared_ptr<IPassportOfficeService> ServiceFactory::getPassportOfficeService() const {
    return std::make_shared<CachedPassportOfficeService>();
}