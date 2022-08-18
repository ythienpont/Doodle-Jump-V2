#ifndef EFFECT_H
#define EFFECT_H

#include <memory>
#include "View.h"

/*
 * This class will not really do anything,
 * it just exists to follow the main structure
 * of the program. Not making this a Subject class
 * because the view will never have to be updated.
 * Just clearing the background with a white/red color
 * would be simpler, but this way is more universal.
 */

namespace Logic
{
  class Effect
  {
  private:
    std::shared_ptr<Representation::Effect> view;
  public:
    Effect();
    std::shared_ptr<Representation::Effect> getView() const;
    void registerView(std::shared_ptr<Representation::Effect> theView);
  };
}
#endif //EFFECT_H
