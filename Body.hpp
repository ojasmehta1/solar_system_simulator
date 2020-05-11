#ifndef _BODY_HPP
#define _BODY_HPP

#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable {
private:

  int windowSize;
  double SsystemSize;
  double positionX, positionY;
  double velocityX, velocityY;
  double mass;
  
  std::string fileName;
  sf::Sprite sprite;
  sf::Texture texture;
  
public:
  Body();
  Body(int windowSizep, double SsystemSizep);
  
  void setWindowSize(int sizep);
  void setUniverseSize(double sizep);
  
  double getPositionX();
  double getPositionY();
  double getMass();
  
  void setVelocityX(double value);
  void setVelocityY(double value);
  
  void step(double time);
  
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  
  friend std::istream &operator>>(std::istream &input, Body &arg);
  friend std::ostream &operator<<(std::ostream &output, Body &arg);
};

#endif
