//
// Passport.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_PASSPORT_H
#define CARD_SERVICE_SYSTEM_PASSPORT_H

#include <string>
#include "Utils/Date.h"


/**
 * @brief Passport class
 * @details Contains first name, last name and birth day
 */
class Passport {
private:
    std::string firstName_;
    std::string lastName_;
    Date birthDate_;

public:
    /**
     * @brief Passport constructor
     * @details Constructs passport with specified values
     * @param[in] firstName First name
     * @param[in] lastName Last name
     * @param[in] birthDate Birth date
     */
    explicit Passport(const std::string& firstName = "First Name", const std::string& lastName = "Last Name",
                      const Date& birthDate = Date());

    /**
     * @brief Passport copy constructor
     * @details Constructs a copy of the specified Passport
     * @param[in] passport Passport to copy
     */
    Passport(const Passport& passport);


    /**
     * @brief Passport operator =
     * @param[in] passport Passport to set
     * @return Reference to the Passport
     */
    Passport& operator=(const Passport& passport);


    /**
     * @brief First name getter
     * @return Person's first name
     */
    std::string getFirstName() const;

    /**
     * @brief Last name getter
     * @return Person's last name
     */
    std::string getLastName() const;

    /**
     * @brief Birth date getter
     * @return Person's birth date
     */
    Date getBirthDate() const;


    /**
     * @brief Comparing operator ==
     * @param[in] passport Passport to compare with
     * @return True if passports are the same, false otherwise
     */
    bool operator==(const Passport& passport) const;

    /**
     * @brief Comparing operator ==
     * @param[in] passport Passport to compare with
     * @return False if passports are the same, true otherwise
     */
    bool operator!=(const Passport& passport) const;
};


#endif //CARD_SERVICE_SYSTEM_PASSPORT_H
