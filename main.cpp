#include"cnn.h"
int main(int argc,char* argv[])//第一个参数应该是 train或者test，第二个参数应该是solver.prototxt，如果是train的话，需要第三个参数，应该是一个图片全名
{
	if (strcmp(argv[1], "train") == 0)
	{
		parse(argv[2]);//即首先应该是解析solver.prototxt
		vector<Blob*> data;//申请一个代表数据的变量。
		CNN cnn;
		cnn.train();
	}
	else if (strcmp(argv[1], "test") == 0)
	{
		parse(argv[2]);//即首先应该是解析solver.prototxt
		CNN cnn;
		cnn.test();
	}
}