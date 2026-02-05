#ifndef RECIPE_H
#define RECIPE_H
#include "Ingredient.h"
#include <iostream>
#include <vector>
using namespace std;

class Recipe{
    string title; // recipe name
    string category; // type (Breakfast, Lunch, Dinner)
    int prepTime; // minutes
    int servings; // servings
    vector<Ingredient*> ingredients; // list of ingredients
    vector<string> instructions; // step-by-step instructions
    bool isFavorite; // favorite status

    public:
        Recipe(string title, string category, int prepTime, int servings, vector<Ingredient*> ingredients, vector<string> instructions, bool isFavorite);
        void addIngredient(Ingredient* i); 
        void addInstruction(string step); // adds ingredient to recipe
        void toggleFavorite(); // marks/unmarks as favorite
        void display();
        bool getIsFavorite();
        vector<Ingredient*> getIngredients();





};

#endif