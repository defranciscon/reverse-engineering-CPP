/*
 * This project contains C++ code reverse engineered from binary to assembly to C++
 * The code is comprised of a reverse engineered program that has some security vulnerabilities.
 * The purpose of this project is to demonstrate the reversing process of converting binary to readable assembly, and then
 * extracting the C++ code from the assembly to the best of my ability.
 *
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Hard coded password enables access to system regardless of username
const char* password[] = { "123" };

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

string* names = new string[5]{ name1, name2, name3, name4, name5 };
int* nums = new int[5] {num1, num2, num3, num4, num5};

int CheckUserPermissionAccess();        // function checks user permission access
void DisplayInfo();                     // function displays the list of client's and service choice when option 1 selected
void ChangeCustomerChoice();            // function allows user to change the service choice of a client. 
int choice;

int main()
{
    // Initial welcome message in console
    cout << "Created by: Nicolas W. DeFrancisco.\n" << endl;
    cout << "Hello! Welcome to our Investment Company" << endl;

    // calls permission access function to get username and password
    CheckUserPermissionAccess();

    while (true) {
        
        // Main menu options
        cout << "What would you like to do?" << endl;
        cout << "DISPLAY the client list (enter 1)" << endl;
        cout << "CHANGE a client's choice (enter 2)" << endl;
        cout << "Exit the program.. (enter 3)" << endl;
        cin >> choice;

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
}

int CheckUserPermissionAccess()
{
    string* answer = new string();
    string username;
    char input[16]{};

    // checks string length against size because string length should always less than the size of the input string.
    while (strlen(input) < sizeof(input)) {
        cout << "Enter Username:" << endl;
        getline(cin, username);
        cout << "Enter Password:\n";
        cin >> input;
        *answer = input;

        // compare strings to ensure matching sequence of characters '1' '2' '3'
        if (answer->compare(*password) == 0) {
            return answer->compare(*password);  // returns result if matches
        }
        else {
            cout << "Invalid Password. Please try again." << endl;
        }
    }
}

void ChangeCustomerChoice()
{
    int newservice;
    int changechoice;

    cout << "Enter the number of the client that you wish to change" << endl;

    // variable to hold the value of the selected client.
    cin >> changechoice;

    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;

    // variable to hold the value of the service choice (1 or 2)
    cin >> newservice;

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
}

// function to display list of clients using for loop to iterate through names and nums arrays
void DisplayInfo()
{
    cout << "  Client's Name    " << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << names[i] << " selected option " << nums[i] << endl;
    }
}
