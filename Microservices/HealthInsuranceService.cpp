//
// HealthInsuranceService.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Microservices/HealthInsuranceService.h"

std::shared_ptr<Policy> HealthInsuranceService::getPolicy(size_t id) {
    std::cout << "Person's policy request was sent to the server" << std::endl;
    std::cout << "Person's policy was received" << std::endl;
    return std::make_shared<Policy>();
}


const std::chrono::hours CachedHealthInsuranceService::updateInterval_ = std::chrono::hours(24);

void CachedHealthInsuranceService::reset() {
    policies_.clear();
    lastUpdate_ = std::chrono::steady_clock::now();
}

bool CachedHealthInsuranceService::needUpdate() const {
    auto upToDate = updateInterval_ + lastUpdate_;
    return std::chrono::steady_clock::now() > upToDate;
}

CachedHealthInsuranceService::CachedHealthInsuranceService() : service_(std::make_shared<HealthInsuranceService>()),
                                                               lastUpdate_(std::chrono::steady_clock::time_point()),
                                                               policies_(std::map<size_t, std::shared_ptr<Policy>>()) { }

std::shared_ptr<Policy> CachedHealthInsuranceService::getPolicy(size_t id) {
    if (needUpdate()) {
        reset();
    }
    if (policies_.find(id) == policies_.end()) {
        policies_[id] = service_->getPolicy(id);
    }
    return policies_[id];
}