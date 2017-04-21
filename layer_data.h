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

void layer_data::backward(vector<Blob*> input, vector<Blob*> output)//只是为了层的统一，写这样一个函数，所以这个函数不需要做任何动作。
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

	for(int i=0;i<batchSize;i++)//?这个函数还存在的问题是：记录上一次读到的位置！！！！！这个必须得记录啊
	{
		if (fscanf(imgNameListFile,"%s %d\n",imgName.c_str()) == EOF)
		{
			batchSize = i;//如果一个batchSize还没有读完，图片就没有了，就更改这次训练的batchSize就为现在batch中的图片数。
			break;
		}
		else {
			Mat img = imread(imgName);
			(input[0]->data).push_back(img);
		}
	}
	//写完了，也就剩那一个打问号的问题了
}