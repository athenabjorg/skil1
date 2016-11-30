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
    do
    {
        cout << "Select one of the following options: " << endl;
        cout << "Add - add a programmer/computer scientist" << endl;
        cout << "List - show a list of all programmer's/computer scientist's" << endl;
        cout << "Search - search the list of programmer's/computer scientist's" << endl;
        cout << "Sort - sort list by name, gender, age or year of death" << endl;
        cout << "Quit - end program" << endl;


        cin >> command;
        for(unsigned int i = 0; i < command.length(); i++) // to make all lowercase, taken from c++ site
        {
            command[i] = tolower(command[i]);
        }

        cout << endl;

        if(command == "add")
        {
           userMenuAdd();
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
        else if(command != "quit")
        {
            cout << "Invalid input" << endl;
        }
    }while(command != "quit");



}
void ConsoleUI::userMenuAdd()
{
    string name;
    char gender;
    int birthYear;
    int deathYear = 0;

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
                cout << "Invalid input" << endl;

            else
                break;
        }

        // Check year of birth
        while(true)
        {
            cout << "Enter the programmer's/computer scientist's year of birth: ";
            cin >> birthYear;
            if(birthYear < 2016) // Just in case we find a programmer of the univers
                break;

            else
                cout << "Invalid input" << endl;
        }

        // Check when year of death (if dead)
        while(true)
        {
            cout << "Enter the programmer's/computer scientist's year of death (type 0 if not applicable): ";
            cin >> deathYear;
            if (deathYear == 0)
                break;

            else if(deathYear >= birthYear)
                break;

            else
                cout << "Invalid input" << endl;
        }

        // Check if input is correct
        cout << "Name: " << name << " Gender: " << gender << " Born: " << birthYear;

        if(deathYear != 0)
            cout << " Died: " << deathYear << endl;
        else
            cout << endl;

       int a = userCheckInput();
        if (a == 0)
        {
            _service.addScientist(name, gender, birthYear, deathYear);
            break;
        }
        else if (a == 2)
            break;

    }

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




    if(command == "name") // findScientistByName
    {
        string userInputName;
        cout << "Enter the programmer's/computer scientist's name: ";
        cin.ignore();
        getline(cin, userInputName);

        vector<Scientist> scientist = _service.findScientistByName(userInputName);
        userMenuPrint(scientist);

    }
    else if(command == "birth")
    {

    }
    else if(command == "death")
    {

    }


}
void ConsoleUI::userMenuSort()
{
    int userInput;
    cout << "Sort list by name(1), gender(2), age(3) or year of death(4)" << endl;
    cin >> userInput;
     _service.scientistSort(userInput);
}
void ConsoleUI::userMenuPrint(vector<Scientist>scientist)
{
    cout << "Scientist name: \t" << "gender: \t" << "age: \t" << "died:" << endl;
    cout << "================================================================" << endl;
    for (size_t i = 0; i< scientist.size(); ++i)
    {
        cout << scientist[i].getName() << "\t\t"
             << scientist[i].getGender() << "\t\t"
             << scientist[i].getAge() << "\t"
             << scientist[i].getDeath() << endl;
    }
    cout << endl;
}

int ConsoleUI::userCheckInput()
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
            return 1;

        else if (answear == 'q')
            return 2;

        else
            cout << "Invalid input!";

        cout << endl;
    }
}
