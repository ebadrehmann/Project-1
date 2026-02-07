#ifndef RECIPE_H
#define RECIPE_H
#include "Ingredient.h"
#include <iostream>
#include <vector>
using namespace std;

class Recipe{
    // attributes
    string title;
    string category; 
    int prepTime; 
    int servings; 
    bool isFavorite;
    vector<Ingredient*> ingredients; 
    vector<string> instructions;
    

    public:
        Recipe(string title, string category, int prepTime, int servings, bool isFavorite);
        ~Recipe();
        // methods
        void addIngredient(Ingredient* i); 
        void addInstruction(string step); // adds ingredient to recipe
        void toggleFavorite(); // marks/unmarks as favorite
        void display();

        // getters
        bool getIsFavorite();
        string getCategory();
        string getTitle();
        int getServings();
        int getPrepTime();
        vector<Ingredient*> getIngredients();
        vector<string> getInstructions();
        





};

#endif