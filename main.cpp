#include <iostream>
#include <string>
#include "DataManager/DataManager.h"

using namespace std;

void addMeal(DataManager dataManager)
{
    system("cls");
    cout << "Adding meal...\n"
         << endl;
    cout << "Describe what did you eat: \n";

    string query;
    getline(cin, query);
    for (char &c : query)
    {
        if (c == ' ')
        {
            c = '+';
        }
    }
    dataManager.setQuery(query);
    dataManager.fetchData(query);
    dataManager.readApiData();
    dataManager.addData();
}

int main()
{
    int calorieGoal = 2300;
    int proteinGoal = 160;
    int eatenCalories = 2000;
    int eatenProtein = 140;

    int remainingCalories = calorieGoal - eatenCalories;
    int remainingProtein = proteinGoal - eatenProtein;

    cout << "\nToday's eaten macros:\n";
    cout << "Protein: " << eatenProtein << "g\n";
    cout << "Calories: " << eatenCalories << "\n\n";
    cout << remainingCalories << " calories left\n";
    cout << remainingProtein << "g of protein left\n\n";
    cout << "What would you like to do next?\n";
    cout << "1. Add a meal\n";
    cout << "2. View history\n";
    cout << "3. Exit\n\n";

    string option;
    getline(cin, option);
    DataManager dataManager;
    if (option == "1")
    {
        addMeal(dataManager);
    }
    else if (option == "2")
    {
        // ViewHistory();
    }
    else if (option == "3")
    {
        return 0;
    }
    else
    {
        cout << "Invalid option\n";
    }

    return 0;
}
