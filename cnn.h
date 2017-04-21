#include"layer.h"

class cnn {
public:
	void forward();
	void backward();
	void constructCNNFromPrototxt(FILE* prototxtFile);
	void train();
	void val();
	void saveModel(FILE* weightsFile);
	void readModel(FILE* prototxtFile,FILE* weightsFile);

	vector<layer*> layersPtr;
	int maxEpochsNum;
	int valInterval;
	int trainSamplesNum;
	int valSamplesNum;
	int batchSize;
	int batchSizeCount;
};

void cnn::forward()
{
	for (int i = 0; i < layersPtr.size(); i++)
	{
		layersPtr[i]->forward();
	}
}

void cnn::backward()
{
	for (int i = layersPtr.size(); i > 0; i--)
	{
		layersPtr[i]->backward();
	}
}

void cnn::constructCNNFromPrototxt(FILE* prototxtFile)
{
	
}

void cnn::train()
{
	batchSizeCount = 0;
	for (int i = 0; i < maxEpochsNum; i++)
	{
		for (int j = 0; j < maxEpochsNum / batchSize + 1; j++)
		{
			forward();
			backward();
			batchSizeCount++;
			if (batchSizeCount%valInterval == 0)
				val();
		}
	}
}

void cnn::val()
{
	for (int i = 0; i < valSamplesNum; i++)
	{
		forward();
	}
}