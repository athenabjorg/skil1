#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

// Should not contain logic for individual commands, that should be in separate functions!
void ConsoleUI::run()
{
    string command;
    while(true)
    {
        cout << "Select one of the following options: " << endl;
        cout << "=====================================" << endl;
        cout << "Add - add a programmer/computer scientist" << endl;
        cout << "Remove - remove a programmer/computer scientist" << endl;
        cout << "List - show a list of all programmer's/computer scientist's" << endl;
        cout << "Search - search the list of programmer's/computer scientist's" << endl;
        cout << "Sort - sort list by name, gender, age or year of death" << endl;
        cout << "Quit - end program" << endl;


        cin >> command;
        for(unsigned int i = 0; i < command.length(); i++) // to make all lowercase, taken from c++ site
        {
            command[i] = tolower(command[i]);
        }


        if(command == "add")
        {
           userMenuAdd();
        }
        else if(command == "remove")
        {
           userMenuRemove();
        }
        else if(command == "list")
        {
           userMenuList();
        }
        else if(command == "search")
        {
           userMenuSearch();
        }
        else if(command == "sort")
        {
            userMenuSort();
        }
        else if(command == "quit")
        {
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }



}
void ConsoleUI::userMenuAdd()
{
    string name;
    char gender;
    int birthYear;
    int deathYear = 0;
    int age = 0;
    int a;

    while(true)
    {
        cout << "Enter the programmer's/computer scientist's name: ";
        cin.ignore();
        getline(cin, name);

        // Check for gender
        while(true)
        {
            cout << "Enter the programmer's/computer scientist's gender (m/f): ";
            cin >> gender;

            if((gender != 'm') && (gender != 'f'))
            {
                cout << "Invalid input" << endl;
            }
            else
            {
                break;
            }

        }

        // Check year of birth
        while(true)
        {
            cout << "Enter the programmer's/computer scientist's year of birth: ";
            cin >> birthYear;
            if(birthYear < 2016) // Just in case we find a programmer of the univers
            {
                break;
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }

        // Check when year of death (if dead)
        while(true)
        {
            cout << "Enter the programmer's/computer scientist's year of death (type 0 if not applicable): ";
            cin >> deathYear;
            if (deathYear == 0)
            {
                break;
            }
            else if(deathYear >= birthYear)
            {
                break;
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }


        // Check if input is correct
        cout << "Name: " << name << endl << "Gender: " << gender << endl << "Born: " << birthYear << endl;

        if(deathYear != 0)
        {
            cout << "Died: " << deathYear << endl;
        }
        else
        {
            cout << endl;
        }

        a = userCheckInput();
        if (a == 0)
        {
            _service.addScientist(name, gender, birthYear, deathYear, age);
            break;
        }
        else if (a == 2)
        {
            break;
        }

    }
    cout << endl;

}
void ConsoleUI::userMenuList()
{
    vector<Scientist> scientist = _service.getScientists();
    userMenuPrint(scientist);
}
void ConsoleUI::userMenuSearch()
{
    string command;
    cout << "Select a search option: " << endl;
    cout << "Name - Search by name" << endl;
    cout << "Gender - Search by gender" << endl;
    cout << "Age - Search by age" << endl;
    cout << "Death - search by year of death" << endl;
    cin >> command;
    cout << endl;

    for(unsigned int i = 0; i < command.length(); i++) // to make all lowercase, taken from c++ site
    {
        command[i] = tolower(command[i]);
    }


    if(command == "name")
    {
        string userInputName;
        cout << "Search by name: ";
        cin.ignore();
        getline(cin, userInputName);

        vector<Scientist> scientist = _service.findScientistByName(userInputName);
        userMenuPrint(scientist);

    }
    else if(command == "gender") // findScientistByGender
    {
        char userInputGender;
        cout << "Search by gender: ";
        cin >> userInputGender;

        vector<Scientist> scientist = _service.findScientistByGender(userInputGender);
        userMenuPrint(scientist);
    }
    else if(command == "age") // findScientistByGender
    {
        int userInputAge;
        cout << "Search by age: ";
        cin >> userInputAge;

        vector<Scientist> scientist = _service.findScientistByAge(userInputAge);
        userMenuPrint(scientist);
    }
    else if(command == "death")
    {
        int userInputDeath;
        cout << "Search by age: ";
        cin >> userInputDeath;

        vector<Scientist> scientist = _service.findScientistByDeath(userInputDeath);
        userMenuPrint(scientist);
    }
    cout << endl;

}
void ConsoleUI::userMenuSort()
{
    int userInput;
    cout << "Sort list by Name(1), Gender(2), Year of Birth(3), Year of Death(4) or Age (5)" << endl;
    cin >> userInput;
     _service.scientistSort(userInput);
     userMenuList();
}
void ConsoleUI::userMenuPrint(vector<Scientist>scientist)
{
    cout << endl;
    cout << "Scientist name:    gender:     born:   died:   age: " << endl;
    cout << "====================================================" << endl;
    for (size_t i = 0; i< scientist.size(); ++i)
    {
        cout << scientist[i].getName() << "\t"
             << scientist[i].getGender() << "\t"
             << scientist[i].getBirth() << "\t";


             if(scientist[i].getDeath() == 0)
             {
                 cout << "-" << "\t";
             }
             else
             {
                 cout << scientist[i].getDeath() << "\t";
             }
             cout << scientist[i].getAge() << endl;


    }
    cout << endl;
}
int  ConsoleUI::userCheckInput()
{
    // Check if all data is correct
    while(true)
    {
        char answear;
        cout << "Is this data correct? (input y/n) or press q to quit" << endl;
        cin >> answear;

        if(answear == 'y')
        {
            return 0;
        }
        else if (answear == 'n')
        {
            return 1;
        }
        else if (answear == 'q')
        {
            return 2;
        }
        else
        {
            cout << "Invalid input!";
        }

    }
}
void ConsoleUI::userMenuRemove()
{
    string userInputName;
    cout << "Remove a programmer/computer scientist: ";
    cin.ignore();
    getline(cin, userInputName);

    _service.removeScientist(userInputName);
}
