#include "Effect.h"

Logic::Effect::Effect() { }

std::shared_ptr<Representation::Effect> Logic::Effect::getView() const
{
  return view;
}

void Logic::Effect::registerView(std::shared_ptr<Representation::Effect> theView)
{
  view = theView;
}
