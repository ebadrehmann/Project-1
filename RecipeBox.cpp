#include <iostream>
#include "RecipeBox.h"
using namespace std;

RecipeBox::RecipeBox(){

}

RecipeBox::~RecipeBox(){
    for (Recipe* r: recipes){
        delete r;
    }
}
void RecipeBox::addRecipe(){
    string title, category;
    int prepTime, servings;
    bool isFavorite;

    cout << "What would you like your recipe name to be?" << endl;
    getline(cin, title);
    cout << "What is the time of day to eat this? (Breakfast, Lunch, Dinner)" << endl;
    getline(cin, category);
    cout << "How long does this recipe take to prep?" << endl;
    cin >> prepTime;
    cout << "How many servings is this recipe?" << endl;
    cin >> servings;
    cout << "Is this one of your favorite recipes? (true or false)" << endl;
    cin >> isFavorite;
    // when you type something in a terimnal and press enter it creates a new line char
    cin.ignore();

    Recipe* r = new Recipe(title, category, prepTime, servings, isFavorite);

    int num;
    cout << "How many ingredients does this recipe have?" << endl;
    cin >> num;
    cin.ignore();
    for (int i = 0; i < num; i++){
        string name, unit;
        int quantity;
        cout << "What is the ingredient name?" << endl;
        getline(cin, name);
        cout << "What is the ingredient unit?" << endl;
        getline(cin, unit);
        cout <<  "What is the ingredient quantity?" << endl;
        cin >> quantity;
        r->addIngredient(new Ingredient(name, quantity, unit));
    }
    int steps;
    cout << "How many steps are there in this recipe?" << endl;
    cin >> steps;
    for (int i = 0; i < steps; i++){
        string step;
        cout << "What is step # " << i + 1 << endl;
        cin >> step;
        r->addInstruction(step);
    }
    recipes.push_back(r);

}
void RecipeBox::displayAll(){
    for (Recipe *r: getRecipes()){
        r->display();
    }

}
void RecipeBox::displayByCategory(string category){
    for (Recipe* r: recipes){
        if (r->getCategory() == category){
            r->display();
        }
    }
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
    if (index >= 0 && index < recipes.size()){
        delete recipes[index];
        // GPT also includes another line here.
    }
}

void RecipeBox::saveToFile(string fileName){

}
void loadFromFile(string fileName){

}