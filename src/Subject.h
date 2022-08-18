#ifndef SUBJECT_H
#define SUBJECT_H

#include <memory>
#include "View.h"

class Subject
{
public:
  virtual void registerObserver(std::shared_ptr<Representation::View> observer) = 0;
  virtual void removeObserver(std::shared_ptr<Representation::View> observer) = 0;
  virtual void notifyObservers() = 0;
};

#endif //SUBJECT_H
