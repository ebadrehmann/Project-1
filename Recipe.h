#ifndef RECIPE_H
#define RECIPE_H
#include "Ingredient.h"
#include <iostream>
#include <vector>
using namespace std;

class Recipe{
    string title;
    string category; 
    int prepTime; 
    int servings; 
    bool isFavorite;
    vector<Ingredient*> ingredients; 
    vector<string> instructions;
    

    public:
        Recipe(string title, string category, int prepTime, int servings, bool isFavorite);
        void addIngredient(Ingredient* i); 
        void addInstruction(string step); // adds ingredient to recipe
        void toggleFavorite(); // marks/unmarks as favorite
        void display();
        bool getIsFavorite();
        string getCategory();
        vector<Ingredient*> getIngredients();
        ~Recipe();





};

#endif