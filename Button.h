#ifndef BUTTON_HEADER_FILE
#define BUTTON_HEADER_FILE

#include <iostream>
#include "ObserverPatterh.h"
#include <string>

class Button:public Subject{
  public:
    Button(){}

    virtual ~Button(){}

    void feedPersonData(std::string iName, int iAge, float iWeight, float iHeight, float iWaist){
      this->name   = iName;
      this->age    = iAge;
      this->weight = iWeight;
      this->height = iHeight * 0.3048;//Change inch to meter
      this->waist  = iWaist;

      std::cout << "\n* Input data is feeded" << std::endl; 
      setUpdated();//set updated flag to true
    }

    void clickButton(){
      std::cout << "* input button is clicked, notifying all observers" << std::endl;
      //On click of button notify the observer of this class.
      notifyObservers();

      Subject::resetUpdated();//set updated flag to false;
    }

    //Inputs provided by GUI on click of button.
    std::string name;
    int age;
    float weight;
    float height; 
    float waist;
};

#endif
