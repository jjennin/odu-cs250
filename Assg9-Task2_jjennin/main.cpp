#include <iostream>
#include <iomanip>
#include "fractiontype.h"

using namespace std;

int main()
{
    /// ORIGINAL
    fractionType tomatoes(3,1);
    fractionType garlic(1,1);
    fractionType onions(2,1);
    fractionType butter(1,1);
    fractionType beef(2,1);
    fractionType beans(2,1);

    /// DISH 1
    fractionType tomatoesDish1(1,2);
    fractionType garlicDish1(3,4);
    fractionType onionsDish1(1,4);
    fractionType butterDish1(1,8);
    fractionType beefDish1(1,2);
    fractionType beansDish1(2,3);

    /// DISH 2
    fractionType tomatoesDish2(3,5);
    fractionType garlicDish2(1,5);
    fractionType onionsDish2(2,5);
    fractionType butterDish2(1,5);
    fractionType beefDish2(7,10);
    fractionType beansDish2(9,10);

    cout << fixed;                                  //Line 4
    cout << showpoint;                              //Line 5
    cout << setprecision(2);                        //Line 6

    cout << "============================================" << endl;
    cout << " Assignment 9 - Task 2" << endl;
    cout << " by Jason Jennings" << endl;
    cout << "============================================" << endl << endl;



    cout << "============================================" << endl;
    cout << "Current Ingredients: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Tomatoes: " << tomatoes << endl;
    cout << "Garlic: " << garlic << endl;
    cout << "Onions: " << onions << endl;
    cout << "Butter: " << butter << endl;
    cout << "Beef: " << beef << " lbs" << endl;
    cout << "Beans: " << beans << " lbs" << endl << endl;

    cout << "============================================" << endl;
    cout << "Dish 1 Ingredients: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Tomatoes: " << tomatoesDish1 << endl;
    cout << "Garlic: " << garlicDish1 << endl;
    cout << "Onions: " << onionsDish1 << endl;
    cout << "Butter: " << butterDish1 << endl;
    cout << "Beef: " << beefDish1 << " lbs" << endl;
    cout << "Beans: " << beansDish1 << " lbs" << endl << endl;

    cout << "============================================" << endl;
    cout << "Dish 2 Ingredients: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Tomatoes: " << tomatoesDish2 << endl;
    cout << "Garlic: " << garlicDish2 << endl;
    cout << "Onions: " << onionsDish2 << endl;
    cout << "Butter: " << butterDish2 << endl;
    cout << "Beef: " << beefDish2 << " lbs" << endl;
    cout << "Beans: " << beansDish2 << " lbs" << endl << endl;

    tomatoes = tomatoes - tomatoesDish1 - tomatoesDish2;
    garlic = garlic - garlicDish1 - garlicDish2;
    onions = onions - onionsDish1 - onionsDish2;
    butter = butter - butterDish1 - butterDish2;
    beef = beef - beefDish1 - beefDish2;
    beans = beans - beansDish1 - beansDish2;


    cout << "============================================" << endl;
    cout << "Left Over Ingredients: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Tomatoes: " << tomatoes << endl;
    cout << "Garlic: " << garlic << endl;
    cout << "Onions: " << onions << endl;
    cout << "Butter: " << butter << endl;
    cout << "Beef: " << beef << " lbs" << endl;
    cout << "Beans: " << beans << " lbs" << endl << endl;
    if((beefDish1 + beansDish1) == (beefDish2 + beansDish2)){
        cout << "Both Dish 1 and Dish 2 are equal in weight" << endl;
    }
    else if((beefDish1 + beansDish1) > (beefDish2 + beansDish2)){
        cout << "Dish 1 is more weight" << endl;
    }
    else {
        cout << "Dish 2 is more weight" << endl;
    }

	return 0;
}
