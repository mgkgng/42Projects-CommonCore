#include "phonebook.class.hpp"

Phonebook::Phonebook(void)
{
    return ;
}

Phonebook::~Phonebook(void)
{
    return ;
}

void    Phonebook::_updateContact(void){
    int i, j;

    for (i = 0; i < 7; i++)
        for (j = 0; j < 5; j++)
            this->contact[i][j] = this->contact[i + 1][j];
    for (i = 0; i < 5; i++)
        this->contact[7][i].clear();
}

int     Phonebook::_contactSize(void){
    int i = 0;

    while (!this->contact[i][0].empty() && i < 8)
        i++;
    return (i);
}

void    Phonebook::saveContact(void){
    int i;

    i = this->_emptyTab();
    if (i == -1) {
        this->_updateContact();
        i = 7;
    }
    cout << "First name : ";
    cin >> this->contact[i][0];
    cout << "Last name : ";
    cin >> this->contact[i][1];    
    cout << "Nickname : ";
    cin >> this->contact[i][2];    
    cout << "Phone number : ";
    cin >> this->contact[i][3];    
    cout << "The darkest secret : ";
    cin >> this->contact[i][4];
}

string Phonebook::tabSize(string s){
    string  result = s;

    if (result.length() <= 10)
        result.insert(0, 10 - result.length(), ' ');
    else {
        while(result.length() != 9)
            result.pop_back();
        result.append(".");
    }
    return result;
}

void    Phonebook::showContact(void){
    int i, j;
    
    cout << "     Index| FirstName|  LastName|  Nickname|" << endl;
    //cout << "__________|__________|__________|__________|" << endl;
    for (i = 0; !this->contact[i][0].empty() && i < 8; i++){
        cout << "         " << i << "|";
        for (j = 0; j < 3; j++)
            cout << this->tabSize(this->contact[i][j]) << "|";
        cout << endl;
        //cout << endl << "__________|__________|__________|__________|" << endl;
    }
}

void    Phonebook::showInfo(void)
{
    string  input;
    int     i;

    while (1) {
        cout << "TYPE THE INDEX TO SEE FURTHER INFORMATION : ";
        cin >> input;
        if (input.size() == 1 && isdigit(input[0]) 
        && stoi(input) >= 0 && stoi(input) < _contactSize())
        {
            cout << endl << "***" << this->contact[stoi(input)][0] << "'s Personal Information ***" << endl;
            cout << "First Name : " << this->contact[stoi(input)][0] << endl;
            cout << "Last Name : " << this->contact[stoi(input)][1] << endl;
            cout << "Nickname : " << this->contact[stoi(input)][2] << endl;
            cout << "Phone Number : " << this->contact[stoi(input)][3] << endl;
            cout << "Darkest secret : " << this->contact[stoi(input)][4] << endl << endl;
        }
        else
            cout << endl << "***INVALID INDEX***" << endl << endl;
        cout << "TYPE 'EXIT' IN ORDER TO QUIT :";
        cin >> input;
        if (!input.compare("EXIT"))
            break;
    }
}

int     Phonebook::_emptyTab(void){
    int i;

    for (i = 0; i < 8; i++)
        if (this->contact[i][0].empty())
            return i;
    return -1;
}

