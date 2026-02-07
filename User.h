#ifndef USER_H
#define USER_H
#include <iostream>
#include "Recipebox.h"
using namespace std;

class User{
    string username;
    string dietaryPreference;
    RecipeBox myRecipes;
    public:
    User(string username = "", string dietaryPreference = "");
    void displayProfile();
    void saveUserData(string filename);
    void loadUserData(string filename);
    void startSession();
};



#endif