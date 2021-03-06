#include <iostream>
#include <stack>
#include "R2/R2.h"
#include "R3/R3.h"
#include "turtle.h"
#include <string>
#include <stdlib.h>
#include <map>
using namespace std;
typedef map<string,vector<string> > AssociativeArray;
class LSystem 
{
public:
	
	R3Mesh * mesh;
	TurtleSystem turtle;
	void replaceAll(string& str, const string& from, const string& to) ;
    string produce(const string axiom, const AssociativeArray rules);
	virtual void run(const char command,const float param, bool drawALeaf);
	float defaultCoefficient;
public:
	LSystem(R3Mesh *m)
	:mesh(m),turtle(mesh)
	{
		srand(time(NULL));
	}
	string reproduce(const string axiom,const AssociativeArray rules, const int iterations=1);
	virtual string generateFromFile(const char * filename, const int iterations, const R3Vector origin);
	void draw(const string data);
};