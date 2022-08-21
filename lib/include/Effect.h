#ifndef EFFECT_H
#define EFFECT_H

#include "Subject.h"

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
  class Effect : public Subject
  {
    void notifyObservers() override { }
  };
}
#endif //EFFECT_H
