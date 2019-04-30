//
// PassportOfficeService.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Microservices/PassportOfficeService.h"

std::shared_ptr<Passport> PassportOfficeService::getPassport(size_t id) {
    std::cout << "Person's passport request was sent to the server" << std::endl;
    std::cout << "Person's passport was received" << std::endl;
    return std::make_shared<Passport>();
}


const std::chrono::hours CachedPassportOfficeService::updateInterval_ = std::chrono::hours(24);

void CachedPassportOfficeService::reset() {
    passports_.clear();
    lastUpdate_ = std::chrono::steady_clock::now();
}

bool CachedPassportOfficeService::needUpdate() const {
    auto upToDate = updateInterval_ + lastUpdate_;
    return std::chrono::steady_clock::now() > upToDate;
}

CachedPassportOfficeService::CachedPassportOfficeService() : service_(std::make_shared<PassportOfficeService>()),
                                                             lastUpdate_(std::chrono::steady_clock::time_point()),
                                                             passports_(std::map<size_t, std::shared_ptr<Passport>>()) { }

std::shared_ptr<Passport> CachedPassportOfficeService::getPassport(size_t id) {
    if (needUpdate()) {
        reset();
    }
    if (passports_.find(id) == passports_.end()) {
        passports_[id] = service_->getPassport(id);
    }
    return passports_[id];
}