#include <iostream>
#include "Button.h"
#include "ObserverClasses.h"

int main()
{
  Button dataFeedButton;

  /* Instantiate observer classes with subject instance variale to observe the changes */
  BmiCalculcator *bmiCalc = new BmiCalculcator(&dataFeedButton);
  WaistToHeightRatio *waistToHeightCalc = new WaistToHeightRatio(&dataFeedButton);  

  /*User enters name, age, weight, height and waist of person 
    "Ram" in the form and clicks the button
  */   
  dataFeedButton.feedPersonData("Ram", 35, 80, 5, 34);//name, age, weight, height, waist
  dataFeedButton.clickButton();

  std::cout << std::endl;

  /*User enters name, age, weight, height and waist of person 
    "Mohan" in the form and clicks the button
  */   
  dataFeedButton.feedPersonData("Mohan", 46, 90, 6, 36);
  dataFeedButton.clickButton();

  /* Remove observer */
  dataFeedButton.unregisterObserver(waistToHeightCalc);

  std::cout << std::endl; 
  
  /*User enters name, age, weight, height and waist of person 
    "Swati" in the form and clicks the button
  */
  dataFeedButton.feedPersonData("Swati", 31, 73, 5.3, 34);
  dataFeedButton.clickButton();

  /* Printing BMI data of all the persons */
  std::cout <<  "\nPrinting BMI data:" << std::endl;
  bmiCalc->printData();

  /* Printing waist to height ratio of all the persons */
  std::cout <<  "\nPrinting Waist to height ratio data:" << std::endl;
  waistToHeightCalc->printData();

  return 1;
}
