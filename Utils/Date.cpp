//
// Date.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Utils/Date.h"


Date::Date(size_t day, size_t month, int year) : day_(day), month_(month), year_(year) { }

Date::Date(const Date& date) : day_(date.day_), month_(date.month_), year_(date.year_) { }

Date& Date::operator=(const Date& date) {
    if (this == &date)
        return *this;
    day_ = date.day_;
    month_ = date.month_;
    year_ = date.year_;
    return *this;
}

size_t Date::getDay() const { return day_; }

size_t Date::getMonth() const { return month_; }

int Date::getYear() const { return year_; }

bool Date::operator==(const Date& date) const {
    return day_ == date.day_ &&
           month_ == date.month_ &&
           year_ == date.year_;
}

bool Date::operator!=(const Date& date) const { return !operator==(date); }