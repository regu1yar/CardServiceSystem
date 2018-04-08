//
// Terminal.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_TERMINAL_H
#define CARD_SERVICE_SYSTEM_TERMINAL_H

#include <memory>
#include "Card/Card.h"


/**
 * @brief Terminal implementation
 * @details Terminal for reading information from cards.
 * Contains pointer to the current card
 */
class Terminal {
private:
    std::shared_ptr<Card> card_;

    /**
     * @brief Card setter
     * @details Sets pointer to the current card
     * @param[in] card Card to set
     */
    void setCard(const std::shared_ptr<Card>& card);

public:
    /**
     * @brief Default terminal constructor
     * @details Sets nullptr value for card pointer
     */
    Terminal();

    /**
     * @brief Constructor with custom card
     * @param[in] card Start card value
     */
    explicit Terminal(const std::shared_ptr<Card>& card);

    /**
     * @brief Inserts card
     */
    void insertCard();

    /**
     * @brief Returns card
     */
    void returnCard();

    /**
     * @brief Comparing operator ==
     * @param[in] card Card to compare with
     * @return True if cards are the same, false otherwise
     */
    std::shared_ptr<Card> getCard() const;
};


#endif //CARD_SERVICE_SYSTEM_TERMINAL_H
