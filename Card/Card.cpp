//
// Card.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Card/Card.h"

Card::Card(size_t id, const std::string& firstName, const std::string& lastName) :
        id_(id), firstName_(firstName), lastName_(lastName) { }

size_t Card::getId() const { return id_; }

std::string Card::getFirstName() const { return firstName_; }

std::string Card::getLastName() const { return lastName_; }

bool Card::operator==(const Card& card) const {
    return id_ == card.id_ &&
           firstName_ == card.firstName_ &&
           lastName_ == card.lastName_;
}

bool Card::operator!=(const Card& card) const { return !operator==(card); }

