#include <iostream>
#include "Ingredient.h"
using namespace std;

Ingredient::Ingredient(string name, double quantity, string unit){
    this->name = name;
    this->quantity = quantity;
    this->unit = unit;
}

void Ingredient::display(){
    cout << name << "This is the diplay() method for ingredient";
}

string Ingredient::getName(){
    return name;
}