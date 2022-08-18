#ifndef SCORE_H
#define SCORE_H

#include <vector>

namespace Logic
{
  class Score
  {
  private:
    int amount;
  public:
    Score();
    void addDelta(const int delta);
    void addDelta(const std::vector<int> deltas);
    int getAmount() const;
  };
}

#endif //SCORE_H
