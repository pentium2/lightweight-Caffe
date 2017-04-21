#include"neuron.h"
#include<vector>

class layer{
public:
	void forward();
	void backward();

	vector<neuron*> neuronsPtr;
};

void layer::forward() {
	for (int i = 0; i < neuronsPtr.size(); i++)
	{

	}
}

void layer::backward(){
	for (int i = 0; i < neuronsPtr.size(); i++)
	{

	}
}