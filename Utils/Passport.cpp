//
// Passport.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Utils/Passport.h"


Passport::Passport(const std::string& firstName, const std::string& lastName, const Date& birthDate) :
        firstName_(firstName), lastName_(lastName), birthDate_(birthDate) { }
Passport::Passport(const Passport& passport) : firstName_(passport.firstName_), lastName_(passport.lastName_),
                                               birthDate_(passport.birthDate_) { }

Passport& Passport::operator=(const Passport& passport) {
    if (this == &passport)
        return *this;
    firstName_ = passport.firstName_;
    lastName_ = passport.lastName_;
    birthDate_ = passport.birthDate_;
    return *this;
}

std::string Passport::getFirstName() const { return firstName_; }

std::string Passport::getLastName() const { return lastName_; }

Date Passport::getBirthDate() const { return birthDate_; }

bool Passport::operator==(const Passport& passport) const {
    return firstName_ == passport.firstName_ &&
           lastName_ == passport.lastName_ &&
           birthDate_ == passport.birthDate_;
}

bool Passport::operator!=(const Passport& passport) const { return !operator==(passport); }