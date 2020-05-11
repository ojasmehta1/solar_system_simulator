#include <sstream>
#include <vector>
#include <cmath>
#include "Body.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;

int main(int argc, char* argv[]) 
{
  int n;
  int windowSize = 500;
  double G = 6.67e-11;
  double SsystemSize;
  string userInput;
  double totalTime = atof(argv[1]);
  double timeIncrement = atof(argv[2]);
  double passedTime = 0.0;
  sf::Font theFont;

  sf::Image backgroundI;
  backgroundI.loadFromFile("starfield.jpg");
  sf::Texture backgroundT;
  backgroundT.loadFromImage(backgroundI);
  sf::Sprite backgroundP(backgroundT);

  theFont.loadFromFile("timesRoman.ttf");
  sf::Text timeText("0.0", theFont);
  
  getline(cin, userInput);
  n = (atoi(userInput.c_str()));
  getline(cin, userInput);
  SsystemSize = (atof(userInput.c_str()));
  
  Body temp(windowSize, SsystemSize);
  vector<Body> Ssystem;
  
  for(int i = 0; i < n; i++)
    Ssystem.push_back(temp);
  
  for(int i = 0; i < n; i++) 
  {
    getline(cin, userInput);
    istringstream temp2(userInput);
    temp2 >> Ssystem[i];
  }

  sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "The Solar System");
  
  while(window.isOpen()) 
  {
    sf::Event event;
    while(window.pollEvent(event)) 
	{
      if(event.type == sf::Event::Closed)
	  {
		  window.close();
	  }
    }
    
    vector<double> forceX;
    vector<double> forceY;
    
    for(int i = 0; i < n; i++) 
	{
      forceX.push_back(0);
      forceY.push_back(0);
    }
    
    for(unsigned i = 0; i < Ssystem.size(); i++)
      for(unsigned j = 0; j < Ssystem.size(); j++) 
	{
		if(i == j) {
			forceX[i] += 0;
			forceY[i] += 0;
	}
	else 
	{
	  double changeInX = Ssystem[j].getPositionX() - Ssystem[i].getPositionX();
	  double changeInY = Ssystem[j].getPositionY() - Ssystem[i].getPositionY();
	  double r = sqrt(changeInX * changeInX + changeInY * changeInY);
	  double F = (G * Ssystem[i].getMass() * Ssystem[j].getMass()) / (r * r);
	  double Fx = F * (changeInX / r);
	  double Fy = F * (changeInY / r);
	  forceX[i] += Fx;
	  forceY[i] += Fy; 
	}
   }

    for(unsigned i = 0; i < Ssystem.size(); i++) 
	{
      double accelerationX = forceX[i] / Ssystem[i].getMass();
      double accelerationY = forceY[i] / Ssystem[i].getMass();
      
      Ssystem[i].setVelocityX(timeIncrement * accelerationX);
      Ssystem[i].setVelocityY(timeIncrement * accelerationY);

      Ssystem[i].step(timeIncrement);
    }
    
    window.clear();
    window.draw(backgroundP);
	
    for(unsigned i = 0; i < Ssystem.size(); i++)
      window.draw(Ssystem[i]);

    passedTime += timeIncrement;
    if(passedTime > totalTime) 
      window.close();
	
    stringstream ss;
    ss << passedTime;
    timeText.setString(ss.str());

    window.draw(timeText);
    
    window.display();
  } 

  for(unsigned i = 0; i < Ssystem.size(); i++)
    cout << Ssystem[i] << endl;
}
