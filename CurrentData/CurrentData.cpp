#include "CurrentData.h"
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

void CurrentData::setProtein(float newProtein)
{
    this->protein = newProtein;
}

float CurrentData::getProtein() const
{
    return protein;
}

void CurrentData::setCalories(float newCalories)
{
    this->calories = newCalories;
}

float CurrentData::getCalories() const
{
    return calories;
}

void CurrentData::setDate()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm *currentDate = std::localtime(&currentTime);

    std::stringstream ss;
    ss << currentDate->tm_year + 1900 << '-';
    ss << std::setw(2) << std::setfill('0') << currentDate->tm_mon + 1 << '-';
    ss << std::setw(2) << std::setfill('0') << currentDate->tm_mday;

    // Assign the formatted date string to the date member variable
    this->date = ss.str();

    std::cout << "Today's date: " << this->date << "\n"; // Print the formatted date
}

std::string CurrentData::getDate() const
{
    return date;
}
