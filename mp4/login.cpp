#include "hashtbl.h"

//--------------------------------------------------------------------
//                         login.cpp
//
//  program that reads in username/login pairs and then
//  performs authentication of usernames.
//--------------------------------------------------------------------

//This will be the data stored in the HashTbl (class T)
struct Password
{
    string username, password;
        
    void setKey(string newKey) { username = newKey; }
    string getKey() const { return username; }
    string getValue() const { return password; };

    //this hash converts a string to an integer
    int hash(const string str) const
    {
        int val = 0;

        for (unsigned int i = 0; i<str.length(); i++)
            val += str[i];
        return val;
    }
};

int main()
{
    HashTbl<Password, string> passwords(10);
    Password tempPass;
    string name;      // user-supplied name
    string pass;      // user-supplied password
    bool userFound;   // is user in table?

        //*********************************************************
        // Step 1: Read in the password file
        //*********************************************************
    ifstream passFile("password.txt");

    if (!passFile)
    {
        cout << "Unable to open 'password.txt'!" << endl;
        exit(0);
    }
    while (!passFile.eof() && !passwords.isFull())
    {
        passFile >> tempPass.username >> tempPass.password;
        passwords.insert(tempPass);
    }

    cout << "Printing the hash table:..." << endl;
    passwords.showStructure();

    //*********************************************************
    // Step 2: Prompt for a Login and Password and check if valid
    //*********************************************************
    cout << "Login: ";
    while (cin >> name)  // to quit, type CTRL Z in Visual C++
    {
        userFound = passwords.retrieve(name, tempPass);
        if (userFound){
            cout << "Password: ";
            cin >> pass;
            
            if (pass == tempPass.getValue())
                cout << "Authentication Successful!" << endl;
            else
                cout << "Authentication unsuccessful!" << endl;
        }
        else
            cout << "User not found, please try again. " << endl;
        cout << "Login: ";
    }
    cout << endl;
}