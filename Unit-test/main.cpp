#include <iostream>
#include <fstream>

#include "container.h"

using namespace std;
using namespace simple_shapes;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream in;
	in.open("in.txt");
	if (!in.is_open())
	{
		cout << "Îרטבךא ס פאיכמל";
		return -1;
	}

	ofstream out;
	out.open("out.txt");
	if (!out.is_open())
	{
		cout << "Îרטבךא ס פאיכמל";
		return -1;
	}

	cout << "Start" << endl;

	container* begin = new container;
	begin->In(in);
	begin->Sort();
	begin->Out(out);
	begin->OutBalls(out);
	cout << "Stop" << endl;

	in.close();
	out.close();

	return 0;
}