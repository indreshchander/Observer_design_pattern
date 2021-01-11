#ifndef OBSERVER_CLASSES_HEADER_FILE
#define OBSERVER_CLASSES_HEADER_FILE

#include <iostream>
#include "ObserverPatterh.h"
#include <unordered_map>

class BmiCalculcator:public Observer{
  public:
    BmiCalculcator(Subject *sub){
      subjct = sub;
  
      //Register for data change in subject
      subjct->registerObserver(this);
    }

    ~BmiCalculcator(){
      subjct->unregisterObserver(this);
    }

    void update(Subject *sub){
      if(typeid(*sub) == typeid(Button)){
        Button *data = (Button *)sub;
        std::string name = data->name;
        int bmi  = data->weight/(data->height * data->height);
        personData.insert({name, bmi});
        std::cout << " > Inside BmiCalculator update, name:" << name << ", bmi:" << bmi << std::endl;
      }
    }

    void printData(){
      for(auto itr=personData.begin(); itr!=personData.end(); itr++){
         std::cout << "    Name:" << itr->first << ", BMI:" << itr->second << std::endl;
      }   
    }

  private:
    Subject *subjct;
    std::unordered_map<std::string, int> personData; //Stores BMI of a person. <name, BMI>    
};

class WaistToHeightRatio:public Observer{
  public:
    WaistToHeightRatio(Subject *sub){
      subjct = sub;

      //Register for data change in subject
      sub->registerObserver(this);
    }

    ~WaistToHeightRatio(){
      subjct->unregisterObserver(this);
    }

    void update(Subject *sub){
      if(typeid(*sub) == typeid(Button)){
        Button *data = (Button *)sub;
        std::string name = data->name;
        int waistToHeight  = data->waist/data->height;
        personData.insert({name, waistToHeight});
        std::cout << " > Inside WaistToHeightRatio update, name:" << name << ", waistToHeight:" << waistToHeight << std::endl;
      }
    }

    void printData(){
      for(auto itr=personData.begin(); itr!=personData.end(); itr++){
         std::cout << "    Name:" << itr->first << ", Weight to height ratio:" << itr->second << std::endl;
      }   
    }

  private:
    Subject *subjct;
    std::unordered_map<std::string, int> personData; //Stores waist/height ratio of a person. <name, waist to height ratio>    
};

#endif
