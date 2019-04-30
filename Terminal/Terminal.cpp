//
// Terminal.cpp
//
// Created by Роман Климовицкий on 07.04.2018.
//

#include "Terminal/Terminal.h"


void Terminal::setCard(const std::shared_ptr<Card>& card) { card_ = card; }

Terminal::Terminal() : card_(nullptr) { }

Terminal::Terminal(const std::shared_ptr<Card>& card) : card_(card) { }

void Terminal::insertCard() { setCard(std::make_shared<Card>()); }

void Terminal::returnCard() { setCard(nullptr); }

std::shared_ptr<Card> Terminal::getCard() const { return card_; }