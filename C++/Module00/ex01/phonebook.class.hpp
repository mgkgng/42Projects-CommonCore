#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class   Phonebook{
    
    public:
        string    contact[8][5];
        Phonebook(void);
        ~Phonebook(void);
        void    saveContact(void);
        void    showContact(void);
        void    showInfo(void);
    string tabSize(string s);

    private:
        int     _emptyTab(void);
        void    _updateContact(void);
        int     _contactSize(void);

};

#endif