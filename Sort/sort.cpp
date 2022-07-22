/*******************************************************************************
File name : sort.cpp
Description : ���������㷨
********************************************************************************/
#include"sort.h"

//ϣ������======================================================================
void ShellSort(int x[], int n)
{
	for (int d = n / 2; d >= 1; d = d / 2)
	{
		int i, j;
		for (i = d; i <= n; i++)
		{
			int temp = x[i];
			for (j = i - d; j >= 1 && temp < x[j]; j = j - d)
				x[j + d] = x[j];
			x[j + d] = temp;
		}
	}
}

//��������======================================================================
int Partition(int  x[], int i, int j)
{
	int temp = x[i];
	while (i < j)
	{
		while (i < j && x[j] >= temp)//�Ƚ��������������
			j--;
		if (i < j)
			x[i++] = x[j];
		while (i < j && x[i] <= temp)//�Ƚ����������ұ���
			i++;
		if (i < j)
			x[j--] = x[i];
	}

	x[i] = temp;
	return i;
}
void QuickSort(int  x[], int i, int j)
{
	int pivot;//��Ŧ
	if (i < j)
	{
		pivot = Partition(x, i, j);
		QuickSort(x, i, pivot - 1);
		QuickSort(x, pivot + 1, j);
	}
}

//������========================================================================
void Sift(int  x[], int k, int m)
{
	int i = k;//Ҫɸ�Ľ��
	int j = 2 * i;//i������
	while (j <= m)//ɸѡ��û�н��е�Ҷ��
	{
		if (j < m && x[j] < x[j + 1])//i���Һ��Ӳ��ƽ�����,jΪ�ϴ���
			j++;
		if (x[i] > x[j])//������Ѿ��������Һ����еĽϴ���
			break;
		else
		{
			int temp = x[i];//��������뵱ǰ�ϴ�ĺ��ӽ���
			x[i] = x[j];
			x[j] = temp;

			i = j;//����i��j�����Ѿ�ɸѡ�ĺ��ӽ��е���
			j = 2 * i;
		}
	}
}
void HeapSort(int x[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		Sift(x, i, n);//��ʼ���ѣ������һ�����ն˽�㣨��֧���)����������ɸѡ
	for (i = 1; i < n; i++)//�ظ�ִ�����߶Ѷ����ؽ��ѵĲ���
	{
		// temp�ǵ�ǰ���ֵ�����ֵ�Ͷ�β����
		int temp = x[1];
		x[1] = x[n - i + 1];
		x[n - i + 1] = temp;

		// ��ɸȥ����βֵ��������n-i���Ķ�
		// ֻ��Ҫ��ɸһ�Σ���Ϊֻ�����˶Ѷ�ֵ
		Sift(x, 1, n - i);
	}
}

//�鲢����======================================================================
void Merge(int  x[], int x1[], int s, int m, int t)
{
	int i = s;//��һ��������x[i]������Ϊm
	int j = m + 1;//�ڶ���������x[j]������Ϊt
	int k = s;//һ�ι鲢�����������x1[k]
	while (i <= m && j <= t)//ȡ��x[i]����x[j]�н�С�߷���x1[k]
		if (x[i] <= x[j])
			x1[k++] = x[i++];
		else
			x1[k++] = x[j++];
	if (i <= m)//����һ��������û�д����꣬�������β����
		while (i <= m)
			x1[k++] = x[i++];
	else//���ڶ���������û�д����꣬�������β����
		while (j <= t)
			x1[k++] = x[j++];
}
void MergePass(int  x[], int x1[], int n, int h)
{
	int i = 1;
	while (i <= n - 2 * h)
	{
		Merge(x, x1, i, i + h - 1, i + 2 * h - 1);//���鲢��¼��������������Ϊh��������
		i += 2 * h;
	}
	if (i < n - h)
	{
		Merge(x, x1, i, i + h - 1, n);//���鲢��������һ������С��h
	}
	else
	{
		for (int k = i; k <= n; k++)
			x1[k] = x[k];//���鲢������ֻʣһ��������
	}

}
void MergeSort1(int  x[], int x1[], int n)
{
	int h = 1;
	while (h < n)
	{
		MergePass(x, x1, n, h);
		h = 2 * h;
		MergePass(x1, x, n, h);
		h = 2 * h;
	}
}
void MergeSort2(int  x[], int x1[], int s, int t)
{
	if (s == t)
		x1[s] = x[s];
	else
	{
		int m = (s + t) / 2;
		MergeSort2(x, x1, s, m);//�鲢����ǰ�벿��
		MergeSort2(x, x1, m + 1, t);//�鲢�����벿��
		Merge(x1, x, s, m, t);//������������������й鲢
	}
}

//��ӡ���======================================================================
void Print(int  x[], int n, int i)
{
	int m = 10;
	while (m <= n)
	{
		for (; i <= m; i++)
			cout << setw(10) << setiosflags(ios::left) << x[i];
		cout << endl;
		m += 10;
	}
	for (; i <= n; i++)
		cout << setw(10) << setiosflags(ios::left) << x[i];
	cout << endl;
}

//��ֵ�����====================================================================
void Assignment(int x[])
{
	srand((unsigned)time(0));
	for (int i = 1; i <= N; i++)
		x[i] = rand() % N;
}

//д���ļ�======================================================================
void WriteFile(int  x[], int op)
{
	ofstream out;
	switch (op)//ѡ���ļ�
	{
	case 0:
		out.open("Data.txt");
		break;
	case 1:
		out.open("ShellSortData.txt");
		break;
	case 2:
		out.open("QuickSortData.txt");
		break;
	case 3:
		out.open("HeapSortData.txt");
		break;
	case 4:
		out.open("MergeSortData.txt");
		break;
	default:
		cout << "����ѡ�����" << endl;
		break;
	}

	if (!out)//�����ж�
	{
		cout << "�޷����ļ���" << "\n|" << endl;
		exit(0);
	}

	int m = 10;//д���ļ�
	int i = 1;
	while (m <= N)
	{
		for (; i <= m; i++)
			out << setw(10) << setiosflags(ios::left) << x[i];
		out << endl;
		m += 10;
	}
	for (; i <= N; i++)
		out << setw(10) << setiosflags(ios::left) << x[i];
	out << endl;
}

//��ȡ�ļ�======================================================================
void ReadFile(int  x[], int op)
{
	ifstream in;
	switch (op)//ѡ���ļ�
	{
	case 0:
		in.open("Data.txt");
		break;
	case 1:
		in.open("ShellSortData.txt");
		break;
	case 3:
		in.open("HeapSortData.txt");
		break;
	case 4:
		in.open("MergeSortData.txt");
		break;
	default:
		cout << "����ѡ�����" << endl;
		break;
	}

	if (!in)//�����ж�
	{
		cout << "�޷����ļ���" << "\n|" << endl;
		exit(0);
	}

	string str;//���������ļ�������
	int count = 1;
	while (getline(in, str))//���н��ļ���Ϣ���뵽g_arry������
	{
		istringstream sin(str);
		while (sin >> x[count])
		{
			count++;
		}
	};
}