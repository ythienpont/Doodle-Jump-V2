#include "../include/Subject.h"

void Logic::Subject::registerObserver(std::shared_ptr<Logic::Observer> observer)
{
  view = observer;
}

void Logic::Subject::removeObserver()
{
  view = nullptr;
}
