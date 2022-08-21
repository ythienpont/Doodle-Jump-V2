#ifndef SUBJECT_H
#define SUBJECT_H

#include <memory>
#include "Observer.h"

namespace Logic
{
  class Subject
  {
  public:
    Subject() { }
    std::shared_ptr<Observer> view;
    void registerObserver(std::shared_ptr<Observer> observer);
    void removeObserver();
    virtual void notifyObservers()= 0;
  };
}

#endif //SUBJECT_H
