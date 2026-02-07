#include <iostream>
#include <fstream>
#include <map>
#include "User.h"
using namespace std;

User::User(string username = "", string dietaryPreference = ""){
    this->username = username;
    this->dietaryPreference = dietaryPreference;
}
void User::displayProfile(){
    cout << "Username: " << username << endl;
    cout << "Dietary Preference" << dietaryPreference << endl;
}

// write
void User::saveUserData(string filename){
    ofstream file(filename);
    if (file.is_open()){
        file << username << endl << dietaryPreference << endl;
        myRecipes.saveToFile(filename);
    }
    file.close();
}
//read
void User::loadUserData(string filename){
    ifstream file(filename);
      if (file.is_open()){
        getline(file, username);
        getline(file, dietaryPreference);
        myRecipes.loadFromFile(filename);
    }
    file.close();
}


void User::startSession(){
    
    int choice;

    do {
        cout << "===========================" << endl;
        cout << "RECIPE MANAGER" << endl;
        cout << "===========================" << endl;
        cout << "1. Add New Recipe" << endl;
        cout << "2. View All Recipes" << endl;
        cout << "3. View by Category" << endl;
        cout << "4. Search by Ingredient" << endl;
        cout << "5. View Favorites" << endl;
        cout << "6. Delete Recipe" << endl;
        cout << "7. Save" << endl;
        cout << "8. Load" << endl;
        cout << "9. View User Profile" << endl;
        cout << "10. Return to Main Menu" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                myRecipes.addRecipe();
                break;
            case 2:
                myRecipes.displayAll();
                break;
            case 3:
            {
                cout << "Enter the category please." << endl;
                string category;
                getline(cin, category);
                myRecipes.displayByCategory(category);
                break;
            }
                
            case 4:
                myRecipes.displayFavorites();
                break;
            case 5:
            {
                cout << "Which ingredient would you like to search with?" << endl;
                string ingredient;
                getline(cin, ingredient);
                myRecipes.searchByIngredient(ingredient);
                break;

            }
            case 6:
            {
                 cout << "Which index would you like to delete from?" << endl;
                int index;
                cin >> index;
                myRecipes.deleteRecipe(index);
                break;
            }
                
            case 7:
                saveUserData("savetest.txt");
                break;
            case 8:
                loadUserData("loadtest.txt");
                break;
            case 9:
                displayProfile();
                break;
            case 10:
                break;
            default:
                cout << "Please enter a valid value (1–10)." << endl;
        }

    } while (choice != 10);
}


void User::startSession(){
    cout << "===========================" << endl;
    cout << "RECIPE BOX MAIN MENU" << endl;
    cout << "===========================" << endl;
    cout << "1. Load User Profile" << endl;
    cout << "2. Create New User" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
        cout << "Sorry that is not an option";
        break;
    }

}