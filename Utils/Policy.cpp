//
// Policy.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Utils/Policy.h"


Policy::Policy(const std::string& number, const Date& insuranceDate, const std::string& insuranceCompany) :
        number_(number), insuranceDate_(insuranceDate), insuranceCompany_(insuranceCompany) { }

Policy::Policy(const Policy& policy) : number_(policy.number_), insuranceDate_(policy.insuranceDate_),
                                       insuranceCompany_(policy.insuranceCompany_) { }

Policy& Policy::operator=(const Policy& policy) {
    if (this == &policy)
        return *this;
    number_ = policy.number_;
    insuranceDate_ = policy.insuranceDate_;
    insuranceCompany_ = policy.insuranceCompany_;
    return *this;
}

std::string Policy::getNumber() const { return number_; }

Date Policy::getInsuranceDate() const { return insuranceDate_; }

std::string Policy::getInsuranceCompany() const { return insuranceCompany_; }

bool Policy::operator==(const Policy& policy) const {
    return number_ == policy.number_ &&
           insuranceDate_ == policy.insuranceDate_ &&
           insuranceCompany_ == policy.insuranceCompany_;
}

bool Policy::operator!=(const Policy& policy) const { return !operator==(policy); }