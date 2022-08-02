#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <assert.h>

namespace Textures
{
  enum ID { Player, Background, Platform };
}

class TextureHolder
{
private:
  std::map<Textures::ID,
    std::unique_ptr<sf::Texture> > textureMap;
public:
  void load(Textures::ID id, const std::string& fin);
  const sf::Texture& get(Textures::ID id) const;
};

#endif //TEXTUREHOLDER_H
