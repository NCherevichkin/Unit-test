#ifndef CONTAINER_H
#define CONTAINER_H

#include "shape.h"

namespace simple_shapes
{
	class container
	{
	public:
		int index;
		shape *array[100];
		void In(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutBalls(ofstream &ofst);
		shape* GetElement(int index);
		void V(ofstream &ofst);
		void Sort();
		void Clear();
		void Add(shape* shap);
		container();
		~container() { Clear(); }
	};
}
#endif