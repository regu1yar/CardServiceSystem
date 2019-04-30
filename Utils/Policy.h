//
// Policy.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_POLICY_H
#define CARD_SERVICE_SYSTEM_POLICY_H

#include <string>
#include "Utils/Date.h"


/**
 * @brief Policy class
 * @details Contains policy number,
 * insurance date
 * and name of the insurance company
 */
class Policy {
private:
    std::string number_;
    Date insuranceDate_;
    std::string insuranceCompany_;

public:
    /**
     * @brief Policy constructor
     * @details Constructs policy with specified values
     * @param[in] number Number
     * @param[in] insuranceDate Insurance date
     * @param[in] insuranceCompany Insurance company
     */
    explicit Policy(const std::string& number = "0000000000000000", const Date& insuranceDate = Date(),
                    const std::string& insuranceCompany = "Company");

    /**
     * @brief Policy copy constructor
     * @details Constructs a copy of the specified Policy
     * @param[in] policy Policy to copy
     */
    Policy(const Policy& policy);


    /**
     * @brief Policy operator =
     * @param[in] policy Policy to set
     * @return Reference to the Policy
     */
    Policy& operator=(const Policy& policy);


    /**
     * @brief Number getter
     * @return Number of the policy
     */
    std::string getNumber() const;

    /**
     * @brief Insurance date getter
     * @return Insurance date of the policy
     */
    Date getInsuranceDate() const;

    /**
     * @brief Insurance company getter
     * @return Name of the insurance company of the policy
     */
    std::string getInsuranceCompany() const;


    /**
     * @brief Comparing operator ==
     * @param[in] policy Policy to compare with
     * @return True if policies are the same, false otherwise
     */
    bool operator==(const Policy& policy) const;

    /**
     * @brief Comparing operator ==
     * @param[in] policy Policy to compare with
     * @return False if policies are the same, true otherwise
     */
    bool operator!=(const Policy& policy) const;
};


#endif //CARD_SERVICE_SYSTEM_POLICY_H
