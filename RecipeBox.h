#ifndef RECIPEBOX_H
#define RECIPEBOX_H
#include <iostream>
#include <vector>
#include "Recipe.h"
using namespace std;

class RecipeBox{
    private:
    vector<Recipe*> recipes;
    public:
    RecipeBox();
    ~RecipeBox();
    void addRecipe();
    void displayAll();
    void displayByCategory(string category);
    void displayFavorites();
    void searchByIngredient(string ingredient);
    void deleteRecipe(int index);
    void saveToFile(string fileName);
    void loadFromFile(string fileName);
    vector<Recipe*> getRecipes(){
        return recipes;
    }
};



#endif