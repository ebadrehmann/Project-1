#include <iostream>
#include <vector>
#include "Recipe.h"
using namespace std;

Recipe::Recipe(string title, string category, int prepTime, int servings, bool isFavorite){
    this->title = title;
    this->category = category;
    this->prepTime = prepTime;
    this->servings = servings;
    this->isFavorite = isFavorite;

};
Recipe::~Recipe(){
    for(Ingredient* i: ingredients){
        delete i;
    }
}
void Recipe::addIngredient(Ingredient* i){ 
    ingredients.push_back(i);
}
void Recipe::addInstruction(string step){
    instructions.push_back(step);
}
void Recipe::toggleFavorite(){
    isFavorite = !isFavorite;
}
void Recipe::display(){
    cout << title << "This is the display() method for Recipe";
}
bool Recipe::getIsFavorite(){
    return isFavorite;
}
vector<Ingredient*> Recipe::getIngredients(){
    return ingredients;
}
string Recipe:: getCategory(){
    return category;
}