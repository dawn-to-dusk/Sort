/*******************************************************************************
File name : main.cpp
Description : ������
********************************************************************************/
#include"sort.h"
#include<time.h>

int main()
{
	int op;
	int x[N + 1] = { 0,2,8,1,9,3 };
	time_t begin, end;//��¼ʱ��ı���
	Assignment(x);//�����ֵ

	WriteFile(x, 0);//д���ļ���Ϣ
	//ShellSort(x, N);//ʹ����

	while (1)
	{
		cout << "----------��ѡ��һ������ʽ----------" << endl;
		cout << "  ��1��ϣ������" << endl;
		cout << "  ��2����������" << endl;
		cout << "  ��3��������" << endl;
		cout << "  ��4���鲢����" << endl;
		cout << "  ��5���˳�" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			cout << "**** ϣ������ ****" << endl;
			begin = clock();
			ShellSort(x, N);//����Ϊ�����Ԫ�ظ���
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		case 2:
			cout << "**** �������� ****" << endl;
			begin = clock();
			QuickSort(x, 1, N);//����Ϊ�����Ԫ�ص�ʼ�����
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		case 3:
			cout << "**** ������ ****" << endl;
			begin = clock();
			HeapSort(x, N);//����Ϊ����ͼ�ȥ��λԪ�ص�Ԫ�ظ���
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		case 4:
		{
			cout << "**** �鲢���� ****" << endl;
			int x1[N + 1];
			begin = clock();
			MergeSort2(x, x1, 1, N);
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 5:
			return 0;
			break;
		default:
			cout << "�������" << endl;
			break;
		}
		WriteFile(x, op);//�洢��ǰ����������
		ReadFile(x, 0);//���¶�ȡ�ļ���Ϣ�Խ����ظ�����
	}
}