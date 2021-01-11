#ifndef OBSERVER_PATTERN_HEADER_FILE
#define OBSERVER_PATTERN_HEADER_FILE

#include <iostream>
#include <vector>

class Subject;

class Observer{
  public:
    Observer(){}
    virtual ~Observer(){}
    virtual void update(Subject *ptr) = 0;  
};

class Subject{
  public:
    Subject(){
      this->updated = false;    
    }

    virtual ~Subject(){}

    void registerObserver(Observer *newObserver){
       std::cout << "+ Registering " << typeid(*newObserver).name() << " for notifications" << std::endl;
       observerList.push_back(newObserver);
    }

    void unregisterObserver(Observer *observer){
       std::cout << "\n\n- un-registering " << typeid(*observer).name() << " for notifications" << std::endl;
       for(auto itr=observerList.begin(); itr!=observerList.end(); itr++){
           if(*itr == observer){
               observerList.erase(itr--);
           } 
       }
    }

  protected:
    void setUpdated(){
       updated = true; 
    }    

    void resetUpdated(){
       updated = false;
    }

    void notifyObservers(){
       if(updated == true){
         for(int i=0; i<observerList.size(); i++){
            observerList[i]->update(this);
         }
       }   
    }
  
  private:
    bool updated;
    std::vector<Observer *> observerList;
};


#endif
