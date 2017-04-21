#include"neuron.h"
#include<vector>

class layer{
public:
	virtual void forward(vector<Blob*> input, vector<Blob*> output);
	virtual void backward(vector<Blob*> input, vector<Blob*> output);

	vector<neuron*> neuronsPtr;
};

void layer::forward(vector<Blob*> input, vector<Blob*> output) {


}

void layer::backward(vector<Blob*> input, vector<Blob*> output){


}