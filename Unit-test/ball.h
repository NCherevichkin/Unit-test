#ifndef BALL_H
#define BALL_H

#include "shape.h"

namespace simple_shapes
{
	class ball : public shape
	{
	public:
		int radius;
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutBalls(ofstream &ofst);
		string ToString();
		double V();
		ball() {};
		ball(int radius, int temperature);
		~ball() {};
	};
}
#endif