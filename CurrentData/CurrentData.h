#include <iostream>
class CurrentData
{
public:
    void setProtein(float newProtein);
    float getProtein() const;

    void setCalories(float newCalories);
    float getCalories() const;

    void setDate();
    std::string getDate() const;

private:
    std::string date = "";
    float protein = 0;
    float calories = 0;
};