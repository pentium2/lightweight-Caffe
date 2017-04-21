//���ƹ�lmdb��ֱ�Ӵ�ͼ�����ѵ����
#include"layer.h"

class CNN {
public:
	void forward();
	void backward();
	CNN(string solverFileName);
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
	vector<Blob*> dataBlock1;
	vector<Blob*> dataBlock2;
	vector<Blob*> tmp;
};

void CNN::forward()
{
	for (int i = 0; i < layersPtr.size(); i++)
	{
		layersPtr[i]->forward(dataBlock1, dataBlock2);
		tmp = dataBlock1; //�û�һ�£�ʹ���Ͼ����
		dataBlock1 = dataBlock2;
		dataBlock2 = tmp;
	}
}

void CNN::backward()
{
	for (int i = layersPtr.size(); i > 0; i--)
	{
		layersPtr[i]->backward(dataBlock1,dataBlock2);
		tmp = dataBlock1; //�û�һ�£�ʹ���Ͼ����
		dataBlock1 = dataBlock2;
		dataBlock2 = tmp;
	}
}

CNN::CNN(string solverFileName)//ͨ��slover�ļ�����CNN
{
	FILE* solverFile = fopen(solverFileName.c_str(), "r");
	//����д���⣬����д�ˣ�������д��
}

void CNN::constructCNNFromPrototxt(FILE* prototxtFile)
{
	
}

void CNN::train()
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

void CNN::val()
{
	for (int i = 0; i < valSamplesNum; i++)
	{
		forward();
	}
}