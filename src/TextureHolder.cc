#include "TextureHolder.h"

void TextureHolder::load(Textures::ID id, const std::string& fin)
{
  std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>(); 
  if (!texture->loadFromFile(fin))
  {
    throw std::runtime_error("TextureHolder::load - Failed to load " + fin);
  }

  auto inserted = textureMap.insert(std::make_pair(id, std::move(texture)));
  assert(inserted.second);
}

const sf::Texture& TextureHolder::get(Textures::ID id) const
{
  auto found = textureMap.find(id);

  assert(found != textureMap.end());

  return *found->second;
}
