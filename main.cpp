#include"cnn.h"
int main(int argc,char* argv[])//��һ������Ӧ���� train����test���ڶ�������Ӧ����solver.prototxt�������train�Ļ�����Ҫ������������Ӧ����һ��ͼƬȫ��
{
	if (strcmp(argv[1], "train") == 0)
	{
		parse(argv[2]);//������Ӧ���ǽ���solver.prototxt
		vector<Blob*> data;//����һ���������ݵı�����
		CNN cnn;
		cnn.train();
	}
	else if (strcmp(argv[1], "test") == 0)
	{
		parse(argv[2]);//������Ӧ���ǽ���solver.prototxt
		CNN cnn;
		cnn.test();
	}
}