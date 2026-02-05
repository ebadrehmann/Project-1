#include <iostream>
#include "Ingredient.h"
using namespace std;

Ingredient::Ingredient(string name, double quantity, string unit){
    this->name = name;
    this->quantity = quantity;
    this->unit = unit;
}

void Ingredient::display(){
    cout << name << " ";
}

string Ingredient::getName(){
    return name;
}