#include <iostream>
#include <fstream>
#include "RecipeBox.h"
using namespace std;

RecipeBox::RecipeBox(){
    for (Recipe* r:recipes){
        delete r;
    }
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
vector<Recipe*> RecipeBox::getRecipes(){
    return recipes;
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

// write
void RecipeBox::saveToFile(string fileName){
    ofstream file(fileName);
    if (file.is_open()){
        for (Recipe* r:recipes){
                file << r->getTitle() << endl;
                file << r->getCategory() << endl;
                file << r->getPrepTime() << endl;
                file << r->getServings() << endl;
                file << r->getIsFavorite() << endl;
                vector<Ingredient*> ing = r->getIngredients();
                // print the # of ingredients
                file << ing.size() << endl;
                for (Ingredient* i:ing){
                    file << i->getName() << endl;
                    file << i->getUnit() << endl;
                    file << i->getQuantity() << endl;
                }
                vector<string> instructions = r->getInstructions();
                // print the # of instructions
                file << instructions.size() << endl;
                for (string instruction: instructions){
                    file << instruction << endl;
                }
            }
        file.close();
    }
    
}

// read
void RecipeBox::loadFromFile(string fileName){
    ifstream file(fileName);
    if (file.is_open()){
        string title, category;
        int prepTime, servings;
        bool isFavorite;
        getline(file, title);
        getline(file, category);
        file >> prepTime >> servings >> isFavorite;
        Recipe* r = new Recipe(title, category, prepTime, servings, isFavorite);
        int numIngredients;
        file >> numIngredients;
        file.ignore();
        for (int i = 0; i < numIngredients; i++){
            string name, unit;
            double quantity;
            getline(file, name);
            getline(file, unit);
            file >> quantity;
            r->addIngredient(new Ingredient(name, quantity, unit));
        }
        int numInstructions;
        file >> numInstructions;
        file.ignore();
        for (int i = 0; i < numInstructions; i++){
            string instruction;
            getline(file, instruction);
            r->addInstruction(instruction);
        }
        recipes.push_back(r);
        file.close();
    }
}