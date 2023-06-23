/*
 * This project contains modified C++ code from a C++ file reverse engineered from binary to assembly
 * The code in this file contains modifications to the VulnerableCode.cpp file 
 * The purpose of this file is to address some of the vulnerabilities found in the original CPP file.
 * The code in this file demonstrates how the reversing process can be used to reverse engineer legacy code, 
 * identify vulnerabilities, and rewrite it with modifications to address found vulnerabilities.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Store users in a nested two-dimensional vector
vector<vector<string>> users = {

    {"admin", "123"}
};

const string name1 = "Bob Jones";
const string name2 = "Sarah Davis";
const string name3 = "Amy Friendly";
const string name4 = "Johnny Smith";
const string name5 = "Carol Spears";

int num1 = 1;
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;

string* names = new string[5]{name1, name2, name3, name4, name5};
int* nums = new int[5]{num1, num2, num3, num4, num5};

bool CheckUserPermissionAccess();
void DisplayInfo();
void ChangeCustomerChoice();

int choice;

int main()
{
    cout << "Create by: Nicolas W. DeFrancisco.\n" << endl;
    cout << "Hello! Welcome to our Investment Company" << endl;

    // local variable to check user permission access validity
    bool verifyAccess = CheckUserPermissionAccess();
    
    // Program executes while access is true and only true
    while (verifyAccess == true) {

        cout << "           Menu Options           " << endl;
        cout << "----------------------------------" << endl;
        cout << "What would you like to do?" << endl;
        cout << "DISPLAY the client list (enter 1)" << endl;
        cout << "CHANGE a client's choice (enter 2)" << endl;
        cout << "Exit the program.. (enter 3)" << endl;
        
        try {
            
            cin >> choice;

            // check for input conversion failure; ensures user enters numeric values during option selection
            // print message upon failure 
            if (cin.fail()) {
                cerr << "Invalid Input: option choice must be 1, 2, or 3.\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            // range-check choice variable
            if (choice < 0 || choice > 3) {
                throw exception("Entry must be either 1, 2, or 3 only.");
            }

            switch (choice)
            {
            case 1:
                cout << "You chose " << choice << endl;
                DisplayInfo();
                break;

            case 2:
                cout << "You chose " << choice << endl;
                ChangeCustomerChoice();
                break;

            case 3:
                cout << "You chose " << choice << endl;
                exit(0);
                break;

            default:
                break;
            }
        } 
        catch (const exception& err) {              
            cout << "Range Error: " << err.what() << endl;
        }
    }
}

bool CheckUserPermissionAccess()
{
    string password;
    string username;
    char buff[16]{};    // input buffer
    
    while (users.at(0).at(0) != username || users.at(0).at(1) != password) {
        cout << "Enter Username:" << endl;
        cin >> username;

        // check input length against buffer size
        if (username.length() >= sizeof(buff)) {
            abort();
        }

        cout << "Enter Password:\n";
        cin >> password;

        // check input length against buffer size
        if (password.length() >= sizeof(buff)) {
            abort();
        }
        // return true if username and password matches
        if (users.at(0).at(0) == username && users.at(0).at(1) == password) {
            return true;
        }
        else {
            cout << "Username and password incorrect. Please try again." << endl;
        }
    }
}

void ChangeCustomerChoice()
{
    int newservice;
    int changechoice;
    int min = 0;    // define min + 1 limit for comparison
    int max = 6;    // define max + 1 limit for comparison

    cout << "Enter the number of the client that you wish to change" << endl;

    cin >> changechoice;

    // check input for type validation
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // range check changechoic variables
    if (changechoice <= min || changechoice >= max) {
        throw exception("Client choice must be between 1 and 5.");
    }

    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;

    cin >> newservice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // range check newservice input variable: can only be 0 or 1
    if (newservice < 1 || newservice > 2) {
        throw exception("Service option must be 1 or 2.");
    }

    // loop while variable input is a digit and is within acceptable numeric range
    while (isdigit(changechoice) && changechoice > min && changechoice < max) {

        try {
                switch (changechoice)
                {
                case 1:
                    nums[0] = newservice;
                    break;
                case 2:
                    nums[1] = newservice;
                    break;
                case 3:
                    nums[2] = newservice;
                    break;
                case 4:
                    nums[3] = newservice;
                    break;
                case 5:
                    nums[4] = newservice;
                    break;

                default:
                    break;
                }
                
        } catch(const exception& err) {  // catch error if found
            cerr << "Range Error: " << err.what() << endl;
        }
    }
}

void DisplayInfo()
{   
    cout << "  Client's Name    " << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << names[i] << " selected option " << nums[i] << endl;
    }
}




