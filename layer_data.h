#pragma once
#include"layer.h"

class layer_data : public layer
{
public:
	void forward(vector<Blob*> input, vector<Blob*> output);
	void backward(vector<Blob*> input, vector<Blob*> output);
	layer_data(vector<string> paraList);
	void readImgs(vector<Blob*> input, vector<Blob*> output);

	int batchSize;
	string imgNameListName;
};

void layer_data::forward(vector<Blob*> input, vector<Blob*> output)
{
	readImgs(input, output);
}

void layer_data::backward(vector<Blob*> input, vector<Blob*> output)//ֻ��Ϊ�˲��ͳһ��д����һ�����������������������Ҫ���κζ�����
{

}

layer_data::layer_data(vector<string> paraList)
{
	imgNameListName = paraList[0];
	batchSize = atoi(paraList[1].c_str());
}

void layer_data::readImgs(vector<Blob*> input, vector<Blob*> output)
{	
	FILE* imgNameListFile = fopen(imgNameListName.c_str(), "r");
	string imgName;

	for(int i=0;i<batchSize;i++)//?������������ڵ������ǣ���¼��һ�ζ�����λ�ã����������������ü�¼��
	{
		if (fscanf(imgNameListFile,"%s %d\n",imgName.c_str()) == EOF)
		{
			batchSize = i;//���һ��batchSize��û�ж��꣬ͼƬ��û���ˣ��͸������ѵ����batchSize��Ϊ����batch�е�ͼƬ����
			break;
		}
		else {
			Mat img = imread(imgName);
			(input[0]->data).push_back(img);
		}
	}
	//д���ˣ�Ҳ��ʣ��һ�����ʺŵ�������
}