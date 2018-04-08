//
// Date.h
//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_DATE_H
#define CARD_SERVICE_SYSTEM_DATE_H

#include <cstdio>


/**
 * @brief Date class
 * @details Contains day, month and year
 */
class Date {
private:
    size_t day_;
    size_t month_;
    int year_;

public:
    /**
     * @brief Date constructor
     * @details Constructs date with specified values
     * @param[in] day Day
     * @param[in] month Month
     * @param[in] year Year
     */
    explicit Date(size_t day = 1, size_t month = 1, int year = 1970);

    /**
     * @brief Date copy constructor
     * @details Constructs a copy of the specified Date
     * @param[in] date Date to copy
     */
    Date(const Date& date);


    /**
     * @brief Date operator =
     * @param[in] date Date to set
     * @return Reference to the Date
     */
    Date& operator=(const Date& date);


    /**
     * @brief Day getter
     * @return Day of the date
     */
    size_t getDay() const;

    /**
     * @brief Month getter
     * @return Month of the date
     */
    size_t getMonth() const;

    /**
     * @brief Year getter
     * @return Year of the date
     */
    int getYear() const;


    /**
     * @brief Comparing operator ==
     * @param[in] date Date to compare with
     * @return True if dates are the same, false otherwise
     */
    bool operator==(const Date& date) const;

    /**
     * @brief Comparing operator ==
     * @param[in] date Date to compare with
     * @return False if dates are the same, true otherwise
     */
    bool operator!=(const Date& date) const;
};


#endif //CARD_SERVICE_SYSTEM_DATE_H
