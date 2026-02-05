#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <iostream>
#include <string>

using namespace std;

class Ingredient{
    string name;
    double quantity;
    string unit;

    public:
        Ingredient(string name, double quantity, string unit);
        void display();
        string getName();
};

#endif