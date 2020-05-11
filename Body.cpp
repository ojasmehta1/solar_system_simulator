#include <iomanip>
#include "Body.hpp"
using namespace std;
Body::Body() {
  mass = 0;
  positionX = 0;
  positionY = 0;
  velocityX = 0;
  velocityY = 0;
}

Body::Body(int windowSizep, double SsystemSizep) 
{
  mass = 0;
  positionX = 0;
  positionY = 0;
  velocityX = 0;
  velocityY = 0;
  windowSize = windowSizep;
  SsystemSize = SsystemSizep;
}

void Body::setWindowSize(int sizep) 
{
  windowSize = sizep;
}

void Body::setUniverseSize(double sizep) 
{
  SsystemSize = sizep;
}

double Body::getPositionX() 
{
  return positionX;
}

double Body::getPositionY() 
{
  return positionY;
}

double Body::getMass() 
{
  return mass;
}

void Body::setVelocityX(double value) 
{
  velocityX -= value;
}

void Body::setVelocityY(double value) 
{
  velocityY -= value;
}

void Body::step(double time) 
{
  positionX = positionX - time * velocityX;
  positionY = positionY - time * velocityY;

}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
  sf::Sprite mySprite = sprite;  
  double ratio = (windowSize / 2) / SsystemSize;
  double movPositionX = positionX * ratio + (windowSize / 2);
  double movPositionY = positionY * ratio + (windowSize / 2);
  
  mySprite.setPosition(movPositionX, movPositionY);
  
  target.draw(mySprite);
}

istream &operator>>(istream &input, Body &arg) 
{
  input >> arg.positionX;
  input >> arg.positionY;
  input >> arg.velocityX;
  input >> arg.velocityY;
  input >> arg.mass;
  input >> arg.fileName;

  arg.texture.loadFromFile(arg.fileName);
  arg.sprite.setTexture(arg.texture);

  return input;
}

ostream &operator<<(ostream &output, Body &arg) 
{
  output << setw(14) << arg.positionX;
  output << setw(14) << arg.positionY;
  output << setw(14) << arg.velocityX;
  output << setw(14) << arg.velocityY;
  output << setw(14) << arg.mass;
  output << setw(14) << arg.fileName;

  return output;
}
