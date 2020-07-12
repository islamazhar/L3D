#include "lplus.h"
#include <fstream>
#include "R3Mesh.h"
#include <bits/stdc++.h>
using namespace std;
LPlusSystem::LPlusSystem(R3Mesh * m)
:LSystem(m),isPlus(false)
{
}

string LPlusSystem::generateFromFile(const char * filename,const int iterationsOverride )
{
	int l=strlen(filename);
	if (strcmp(filename+l-3,"l++")==0) //this is an l++
	{
		isPlus=true;
	}
	cout << "calling L-system from LPlus" << endl;
	return LSystem::generateFromFile(filename,iterationsOverride);
}

void LPlusSystem::run(const char command,const float param, bool drawALeaf=false)
{

    double rand_num;
	if (!isPlus)
		return LSystem::run(command,param, drawALeaf);
    //cout << "insde LPlusSystem" << endl;
	float co=defaultCoefficient;
	float num=param;
	if (num==1)
		num*=co;
	switch (command)
	{
		case '+':
		turtle.turnLeft(num);
		break;
		case '-':
		turtle.turnRight(num);
		break;
		case '&':
		turtle.pitchDown(num);
		break;
		case '^':
		turtle.pitchUp(num);
		break;
		case '<':
		turtle.thicken(num);
		break;
		case '\\':
		turtle.rollLeft(num);
		break;
		case '/':
		////////////////////////////////////////  L++ ////////////////////////////////////////////////
		turtle.rollRight(num);
		break;
		case '>':
		turtle.narrow(num);
		break;
		case '%':
		turtle.setReduction(param);
		break;
		case '=':
		turtle.setThickness(param);
		break;
		case '|':
		turtle.turn180(param);
		break;
		case '*':
		turtle.drawLeaf(1.5);
		break;
		case 'F':
		case 'f':
		//cout << rand_num << endl;
		rand_num = (double)rand() / RAND_MAX;
		//rand_num = 1;
		turtle.draw(rand_num);
		turtle.move(rand_num);
		// this can be used to change the branch heights...
		//turtle.draw(1);
		//turtle.move(1);
		//case 'G':
		//case 'g':
		//cout << param << endl;
		//turtle.move(1);
		break;
		case '[':
			turtle.save();
			// For branch height
			//turtle.move(-0.5);
			break;
		case ']':
		    if (drawALeaf) {
		        //turtle.move(0.5);
		        turtle.drawLeaf(0.3);
		    }
			turtle.restore();
			break;
		default:
		;
	}

}
