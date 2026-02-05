#include <iostream>
#include "Ingredient.h"

using namespace std;
class Ingredient{
    string name;
    double quantity;
    string unit; // measurement (unit, cups, grams)
    public:
        Ingredient(string name, double quantity, string unit){
            this->name = name;
            this->quantity = quantity;
            this->unit = unit;
        }
        void display(){
            cout << "This is the display method for ingredient" << endl;
        }
        
};