#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <QtSql>

#include "scientist.h"

using namespace std;

class DataAccess
{
public:

    DataAccess();

    void saveScientist(Scientist newScientist);
        // Saves a scientist to the database.

    vector<Scientist> loadScientists();
    vector<Scientist> loadScientists(int loadType, string parameter);
    vector<Scientist> loadScientists(int loadType, string parameter1, string parameter2);
        // Loads scientists from a database, into a vector.

    void removeScientist(string inputName);
    void removeAllScientists();


    vector<Scientist> loadScientistByName(string name);
    vector<Scientist> loadScientistByGender(char inputGender);
    vector<Scientist> loadScientistByBirth(int inputBirth);
    vector<Scientist> loadScientistByBirthRange(int inputBirth1, int inputBirth2);
    vector<Scientist> loadScientistByDeath(int inputDeath);
    vector<Scientist> loadScientistByDeathRange(int inputDeath1, int inputDeath2);

private:

        QSqlDatabase db;

};

#endif // DATAACCESS_H
