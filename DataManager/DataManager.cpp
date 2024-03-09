#include "DataManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

void DataManager::setQuery(std::string &query)
{
    using namespace std;
    this->query = query;
    ofstream outFile;
    outFile.open("./db/query.txt");
    if (outFile.is_open())
    {
        outFile << query;
        outFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

std::string DataManager::getQuery() const
{
    return query;
}

void DataManager::fetchData(std::string &query)
{
    std::string command = "node ../cli-macros/api/fetch.js " + query;
    std::cout << "Command: " << command << std::endl;
    system(command.c_str());
}

void DataManager::readApiData()
{
    using namespace std;
    ifstream inFile;
    inFile.open("./db/apiResult.json");
    if (!inFile.is_open())
    {
        cout << "Unable to open file" << endl;
        return;
    }
    string line;
    float totalProtein = 0;
    float totalCalories = 0;
    while (getline(inFile, line))
    {
        if (line.find("protein") != std::string::npos)
        {
            int start = line.find(":") + 1;
            int end = line.find(",");
            string protein = line.substr(start, end - start);
            totalProtein = totalProtein + stof(protein);
        }
        if (line.find("calories") != std::string::npos)
        {
            int start = line.find(":") + 1;
            int end = line.find(",");
            string calories = line.substr(start, end - start);
            totalCalories = totalCalories + stof(calories);
        }
    }
    inFile.close();

    currentData.setProtein(totalProtein);
    currentData.setCalories(totalCalories);
}

bool DataManager::isTodayLatest()
{
    using namespace std;
    ifstream inFile;
    inFile.open("./db/historical_data.csv");
    if (!inFile.is_open())
    {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    currentData.setDate();
    string line;
    while (getline(inFile, line))
    {
        if (line.find(currentData.getDate()) != std::string::npos)
        {
            return true;
        }
    }
    inFile.close();
    return false;
}

void DataManager::addData()
{
    using namespace std;
    ofstream outFile;
    string filename = "./db/historical_data.csv";
    if (!outFile)
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }
    cout << "This meal had: \n";
    cout << "Protein: " << currentData.getProtein() << "g\n";
    cout << "Calories: " << currentData.getCalories() << "kcal\n";
    bool isTodayLatest = this->isTodayLatest();
    if (!isTodayLatest)
    {
        // first entry for today
        outFile.open(filename, ios_base::app);
        stringstream newDataStream;
        newDataStream << "\n"
                      << currentData.getDate() << "," << fixed << setprecision(1) << currentData.getProtein() << "," << fixed << setprecision(1) << currentData.getCalories();
        string newData = newDataStream.str();

        outFile << newData;
    }
    else
    {
        outFile.open(filename);
        string line;

        // TODO  loop through the file and and find todays date
    }
    outFile.close();
}
