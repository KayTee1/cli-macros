#include <iostream>
#include "../CurrentData/CurrentData.h"
class DataManager
{
public:
      void setQuery(std::string &query);
      std::string getQuery() const;
      void fetchData(std::string &query);
      void readApiData();
      bool isTodayLatest();
      void addData();

private:
      std::string query = "";
      CurrentData currentData;
};