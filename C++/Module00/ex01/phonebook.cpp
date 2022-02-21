#include <string.h>
#include "phonebook.class.hpp"

int main(int argc, char **argv)
{
    string  add = "ADD";
    string  search = "SEARCH";
    string  exit = "EXIT";
    string  input;
    Phonebook   obj;

    if (argc != 1)
        return 1;
    while (1) {
        cout << "TYPE YOUR COMMAND: ";
        cin >> input;
        if (!add.compare(input))
            obj.saveContact();
        else if (!search.compare(input)) {
            obj.showContact();
            obj.showInfo();
        }
        else if (!exit.compare(input))
            return 0;
    }
        return 0;
}