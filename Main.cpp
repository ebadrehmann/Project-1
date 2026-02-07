#include <iostream>
#include "User.h"
using namespace std;

int main(){
    User user;
    int choice;

    do{
        cout << "===========================" << endl;
        cout << "RECIPE BOX MAIN MENU" << endl;
        cout << "===========================" << endl;
        cout << "1. Load User Profile" << endl;
        cout << "2. Create New User" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:
                user.loadUserData("user.txt");
                break;
            case 2:
            {
                cout << "What would you like your username to be?" << endl;
                string username;
                getline(cin, username);
                cout << "What is your dietary preference?";
                string dietaryPreference;
                getline(cin, dietaryPreference);
                user = User(username, dietaryPreference);
                break;
            }
            case 3:
                break;
            default:
                break;
        }
    } while (choice != 3);

    cout << "The program is complete" << endl;
    return 0;
}