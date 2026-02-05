#include <iostream>
#include <vector>
#include "Recipe.h"
using namespace std;

Recipe::Recipe(string title, string category, int prepTime, int servings, vector<Ingredient*> ingredients, vector<string> instructions, bool isFavorite){
    this->title = title;
    this->category = category;
    this->prepTime = prepTime;
    this->servings = servings;
    this->ingredients = ingredients;
    this->instructions = instructions;
    this->isFavorite = isFavorite;

};
void Recipe::addIngredient(Ingredient* i){ // I added an ingredient i paramter, I'm not sure yet how else this would work.
    ingredients.push_back(i);
}
void Recipe::addInstruction(string step){
    instructions.push_back(step);
}
void Recipe::toggleFavorite(){
    if (isFavorite){
        isFavorite = false;
    }
    else{
        isFavorite = true;
    }
}
void Recipe::display(){
    cout << title << " ";
}
bool Recipe::getIsFavorite(){
    return isFavorite;
}
vector<Ingredient*> Recipe::getIngredients(){
    return ingredients;
}