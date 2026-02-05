#include <iostream>
#include "RecipeBox.h"
using namespace std;

RecipeBox::RecipeBox(){

}
void RecipeBox::addRecipe(){
    
}
void RecipeBox::displayAll(){
    for (Recipe *r: getRecipes()){
        r->display();
    }

}
void RecipeBox::displayByCategory(string category){

}
void RecipeBox::displayFavorites(){
    for(Recipe *r: getRecipes()){
        if(r->getIsFavorite()){
            r->display();
        }
    }
}
void RecipeBox::searchByIngredient(string ingredient){
    for(Recipe *r: getRecipes()){
        vector<Ingredient*> v = r->getIngredients();
        for (Ingredient* i:v){
            if(i->getName() == ingredient){
                r->display();
            }
        }
    }

}
void RecipeBox::deleteRecipe(int index){
    getRecipes()
}

void RecipeBox::saveToFile(string fileName){

}
void loadFromFile(string fileName){

}