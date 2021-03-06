#ifndef TURTLE_H
#define TURTLE_H
#include <stack>
#include "R2/R2.h"
#include "R3/R3.h"
#include "R3Mesh.h"
using namespace std;
class Turtle
{
public:
  R3Vector position;
  R3Vector direction;
  R3Vector right;
  float thickness;
  float reduction;
  Turtle();
  ~Turtle();
  void turnRight(float angle);
  void turnLeft(float angle);
  void pitchDown(float angle);
  void pitchUp(float angle);
  void rollLeft(float angle);
  void rollRight(float angle);
  void move(float distance);
  void turn180(float temp);
  void thicken(float param);
  void narrow(float param);
  void setThickness(float param);
  void setReduction(float param);
  FILE *fp = NULL;


};
class TurtleSystem: public Turtle 
{
public:
  stack<Turtle> state;
  R3Mesh *mesh;
  TurtleSystem(R3Mesh * m);
  void save();
  void restore();
  void draw(float param);
  void drawLeaf(float param);
  void drawSurface();  
};

#endif