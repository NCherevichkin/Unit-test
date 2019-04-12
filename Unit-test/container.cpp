#include "container.h"

namespace simple_shapes
{
	container::container() : index(0) {}

	void container::Clear()
	{
		for (int i = 0; i < index; i++)
			delete array[i];
		index = 0;
	}

	void container::In(ifstream &ifst)
	{
		int size;
		ifst >> size;
		if (size < 99)
			for (int i = 0; i < size; i++)
			{
				array[i] = shape::In(ifst);
				index++;
			}
	}

	void container::Out(ofstream &ofst)
	{
		ofst << "Container contents " << index << " elements." << endl;
		for (int i = 0; i < index; i++)
		{
			ofst << i << ": ";
			array[i]->Out(ofst);
		}
	}

	void container::Sort()
	{
		for (int i = 0; i < index - 1; i++)
			for (int j = i + 1; j < index; j++)
				if (array[i]->Compare(*array[j]))
				{
					shape *tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
	}

	void container::OutBalls(ofstream &ofst)
	{
		ofst << "Only balls." << endl;
		for (int i = 0; i < index; i++)
		{
			ofst << i << ": ";
			array[i]->OutBalls(ofst);
		}
	}

	shape* container::GetElement(int index)
	{
		return array[index];
	}

	void container::Add(shape* element)
	{
		if (index < 99)
		{
			array[index] = element;
			index++;
		}
	}
}