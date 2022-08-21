#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "Vec2D.h"
#include "Collider.h"
#include "Subject.h"
#include "View.h"
#include "Camera.h"

namespace Logic
{
  class Moving
  {
    Vec2D velocity;
  public:
    Moving(const Vec2D& vel);
    Vec2D getVelocity() const;
    void setVelocity(const Vec2D& vel);
    void addVelocity(const Vec2D& vel);
  };

  class Jumpable
  {
  private:
    bool jumpedOn;
  public:
    Jumpable();
    bool hasBeenJumpedOn() const;
    virtual void jumpOn();
    void resetJumpedOn();
  };

  class Living
  {
    int hp;
  public:
    Living(const int points);
    int getHP() const;
    void setHP(const int points);
    void addHP(const int points);
    void kill();
    virtual void hit();
    bool isDead() const;
  };

  class Model : public Subject
  {
    int scoreDelta;
    Vec2D pixelPos;
  public:
    Vec2D pos;

    /* This should be some sort of static member,
     * but maybe it is desirable that every object can have a different collider.
     * Initializing static members from a derived class is probably bad code anyway
     */
    Collider col;

    std::shared_ptr<Representation::View> view;

    ~Model();
    virtual void update()=0;

    void setPosition(const double& x, const double& y);
    void setPosition(const Vec2D& newPos);
    Vec2D getPosition() const;

    int getScoreDelta() const;

    void move(const Vec2D& velocity);

    bool collidesWith(const Model& e);
    void moveOutOfBounds();

    // Subject code
    void registerObserver(std::shared_ptr<Representation::View> observer) override;
    void removeObserver(std::shared_ptr<Representation::View> observer) override;
    bool isInRange(const Vec2D& ePos, const int range) const;
    Vec2D pathToObject(const Vec2D& ePos) const;

    void setPixelPos(const Vec2D& pixelPos);

  protected:
    void notifyObservers() override;
    Model(const double& w, const double& h, const int scoreD);
    Model(const Vec2D& startPos, const double& w, const double& h, const int scoreD);
  };
}

#endif //MODEL_H
