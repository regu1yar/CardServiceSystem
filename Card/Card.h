//
// Card.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_CARD_H
#define CARD_SERVICE_SYSTEM_CARD_H

#include <cstdio>
#include <string>

/**
 * @brief Electron card class
 * @details Contains client's id, first name and last name
 */
class Card {
private:
    size_t id_;
    std::string firstName_;
    std::string lastName_;

public:
    /**
     * @brief Card constructor
     * @details Constructs electron card with custom parameters
     * @param[in] id
     * @param[in] firstName
     * @param[in] lastName
     */
    explicit Card(size_t id = 0, const std::string& firstName = "First Name",
                  const std::string& lastName = "Last Name");

    /**
     * @brief Returns client's id
     * @return Client's id
     */
    size_t getId() const;

    /**
     * @brief Returns client's first name
     * @return Client's first name
     */
    std::string getFirstName() const;

    /**
     * @brief Returns client's last name
     * @return Client's last name
     */
    std::string getLastName() const;

    /**
     * @brief Comparing operator ==
     * @param[in] card Card to compare with
     * @return True if cards are the same, false otherwise
     */
    bool operator==(const Card& card) const;

    /**
     * @brief Comparing operator !=
     * @param[in] card Card to compare with
     * @return False if cards are the same, true otherwise
     */
    bool operator!=(const Card& card) const;
};


#endif //CARD_SERVICE_SYSTEM_CARD_H
