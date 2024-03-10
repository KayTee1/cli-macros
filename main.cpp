#include <iostream>
#include <string>
#include "DataManager/DataManager.h"
#include "CurrentData/CurrentData.h"

void addMeal()
{
    using std::cout, std::endl, std::cin, std::string, std::getline;

    DataManager dataManager;
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
    cout << "Fetching data...\n\n";
    dataManager.readApiData();
    dataManager.addData();
}

int main()
{
    using std::cout, std::cin, std::string, std::getline;

    CurrentData c;
    bool isRunning = true;
    int calorieGoal = 2300;
    int proteinGoal = 160;
    int eatenCalories = 2000;
    int eatenProtein = 140;

    int remainingCalories = calorieGoal - eatenCalories;
    int remainingProtein = proteinGoal - eatenProtein;
    do
    {
        cout << "Today's eaten macros:\n";
        cout << "Protein: " << c.getProtein() << "g\n";
        cout << "Calories: " << c.getCalories() << "\n\n";
        cout << c.getRemainingCalories() << " calories left\n";
        cout << c.getRemainingProtein() << "g of protein left\n\n";
        cout << "What would you like to do next?\n";
        cout << "1. Add a meal\n";
        cout << "2. View history\n";
        cout << "3. Exit\n\n";

        char option;
        cin >> option;
        switch (option)
        {
        case '1':
            addMeal();
            break;
        case '2':
            // ViewHistory();
            break;
        case '3':
            isRunning = false;
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
    } while (isRunning);

    return 0;
}
