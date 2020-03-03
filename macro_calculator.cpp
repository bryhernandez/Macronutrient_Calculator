#include <iostream>
using namespace std;

const double sedentary = 1.2;
const double lightly = 1.37;
const double moderate = 1.55;
const double very = 1.72;
const double extreme = 1.9;

double calc_male_bmr(double kg, double cm, double age){
  double bmr = 66.5 + (13.75 * kg) + (5.003 * cm) - (6.755 * age);

  return bmr;
}

double calc_female_bmr(double kg, double cm, double age){
  double bmr = 655.1 + (9.563 * kg) + (1.850 * cm) - (4.676 * age);

  return bmr;
}

int calc_cals(int activity, int bmr){
  if(activity == 1)
    return (int) (bmr * sedentary);
  else if(activity == 2)
    return (int) (bmr * lightly);
  else if(activity == 3)
    return (int) (bmr * moderate);
  else if(activity == 4)
    return (int) (bmr * very);
  else if(activity == 5)
    return (int) (bmr * extreme);

  return 0;
}

int calc_fat(double fat, int total_cal){
  double fat_macros;
  fat = fat/100;

  fat_macros = fat*total_cal;

  fat_macros = fat_macros/9;

  return (int) fat_macros;

}

int calc_fat_cals(double fat, int total_cals){
    return (int)((fat/100)*(total_cals));
}

int main() {
  double lbs;
  cout<< "Weight in lbs: ";
  cin >> lbs;

  double kg = lbs/2.20462;

  double inch;
  cout << "Height in inches: ";
  cin >> inch;

  double cm = inch*2.54;

  double age;
  cout << "What is your age: ";
  cin >> age;
  
  char m_or_f;
  cout << "Male or Female (M/F): ";
  cin >> m_or_f;

  int bmr;
  if(m_or_f == 'M')
    bmr = (int)calc_male_bmr(kg, cm, age);
  if(m_or_f == 'F')
    bmr = (int)calc_female_bmr(kg, cm, age);

  cout << endl << "Your BMR is " << bmr << endl;

  int activity;
  cout << endl << "What would you say that your activity level is? (1, 2, 3, 4, 5)" << endl;
  cout << "1. Sedentary (little to no exercise)" << endl
  << "2. Lightly Active (light exercise/sports 1-3 days/week)" << endl
  << "3. Moderately Active (moderate exercise/sports 3-5 days/week)" << endl 
  << "4. Very Active (hard exercise/sports 6-7 days/week)" << endl
  << "5. Extremely Active (very hard exercise /sports AND physical job)" << endl;

  cin >> activity;

  int cals_burned = calc_cals(activity , bmr);

  cout << endl << "You burn a total of " << cals_burned << " calories a day." << endl;

  cout << endl << "Now lets figure out your macros!" << endl << endl
  << "Usually protein should be set between " << endl << "0.8 and 1.2 grams per pound of body weight."
  << endl << "Leaner individuals can eat closer to the higher end of this range " << endl << "and if you􏰂re at a higher level of body fat; " << endl << "you can eat towards the lower end" << endl << endl << 
  "What would you like it to be? ";

  double protein;
  cin >> protein;

  cout << "Next we calculate fat. " << endl 
  << "Fat should be set between 20% and 30% of " 
  << endl << "your total calories." << endl << endl << 
  "What would you like it to be? ";

  double fat;
  cin >> fat;

  protein = protein*lbs;
  cout << endl << "Your total protein intake should be " << protein << " g" << endl;

  cout << "Your total fat intake should be " << calc_fat(fat, cals_burned) << " g" << endl;

  int carbs = (cals_burned) - ((protein*4) + calc_fat_cals(fat, cals_burned));
  carbs = carbs/4;

  cout << "Your total carbs intake should be " << carbs << " g" << endl;
}
