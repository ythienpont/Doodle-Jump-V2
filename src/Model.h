#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "Vec2D.h"
#include "Collider.h"
#include "Subject.h"
#include "View.h"
#include "Entity.h"
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

  class Model : public Subject, public Entity
  {
  public:
    Vec2D pos;
    Collider col;
    std::shared_ptr<Representation::View> view;

    Model(const double& w, const double& h);
    Model(const Vec2D& startPos, const double& w, const double& h);

    virtual void update()=0;

    void setPosition(const double& x, const double& y);
    void setPosition(const Vec2D& newPos);
    Vec2D getPosition() const;
    
    void move(const Vec2D& velocity);

    bool collidesWith(const Model& e);


    // Subject code
    void registerObserver(std::shared_ptr<Representation::View> observer) override;
    void removeObserver(std::shared_ptr<Representation::View> observer) override;
    void notifyObservers() override;
  };
}

#endif //MODEL_H
