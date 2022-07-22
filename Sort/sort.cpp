/*******************************************************************************
File name : sort.cpp
Description : 具体排序算法
********************************************************************************/
#include"sort.h"

//希尔排序======================================================================
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

//快速排序======================================================================
int Partition(int  x[], int i, int j)
{
	int temp = x[i];
	while (i < j)
	{
		while (i < j && x[j] >= temp)//比较数从右往左遍历
			j--;
		if (i < j)
			x[i++] = x[j];
		while (i < j && x[i] <= temp)//比较数从左往右遍历
			i++;
		if (i < j)
			x[j--] = x[i];
	}

	x[i] = temp;
	return i;
}
void QuickSort(int  x[], int i, int j)
{
	int pivot;//枢纽
	if (i < j)
	{
		pivot = Partition(x, i, j);
		QuickSort(x, i, pivot - 1);
		QuickSort(x, pivot + 1, j);
	}
}

//堆排序========================================================================
void Sift(int  x[], int k, int m)
{
	int i = k;//要筛的结点
	int j = 2 * i;//i的左孩子
	while (j <= m)//筛选还没有进行到叶子
	{
		if (j < m && x[j] < x[j + 1])//i有右孩子并计较左右,j为较大者
			j++;
		if (x[i] > x[j])//根结点已经大于左右孩子中的较大者
			break;
		else
		{
			int temp = x[i];//将根结点与当前较大的孩子交换
			x[i] = x[j];
			x[j] = temp;

			i = j;//重置i和j，对已经筛选的孩子进行调整
			j = 2 * i;
		}
	}
}
void HeapSort(int x[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		Sift(x, i, n);//初始建堆，从最后一个非终端结点（分支结点)至根结点进行筛选
	for (i = 1; i < n; i++)//重复执行移走堆顶及重建堆的操作
	{
		// temp是当前最大值，最大值和队尾交换
		int temp = x[1];
		x[1] = x[n - i + 1];
		x[n - i + 1] = temp;

		// 重筛去掉队尾值（所以是n-i）的堆
		// 只需要重筛一次，因为只更新了堆顶值
		Sift(x, 1, n - i);
	}
}

//归并排序======================================================================
void Merge(int  x[], int x1[], int s, int m, int t)
{
	int i = s;//第一个子序列x[i]最大序号为m
	int j = m + 1;//第二个子序列x[j]最大序号为t
	int k = s;//一次归并后的新序列下x1[k]
	while (i <= m && j <= t)//取下x[i]和下x[j]中较小者放入x1[k]
		if (x[i] <= x[j])
			x1[k++] = x[i++];
		else
			x1[k++] = x[j++];
	if (i <= m)//若第一个子序列没有处理完，则进行收尾处理
		while (i <= m)
			x1[k++] = x[i++];
	else//若第二个子序列没有处理完，则进行收尾处理
		while (j <= t)
			x1[k++] = x[j++];
}
void MergePass(int  x[], int x1[], int n, int h)
{
	int i = 1;
	while (i <= n - 2 * h)
	{
		Merge(x, x1, i, i + h - 1, i + 2 * h - 1);//待归并记录至少有两个长度为h的子序列
		i += 2 * h;
	}
	if (i < n - h)
	{
		Merge(x, x1, i, i + h - 1, n);//待归并序列中有一个长度小于h
	}
	else
	{
		for (int k = i; k <= n; k++)
			x1[k] = x[k];//待归并序列中只剩一个子序列
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
		MergeSort2(x, x1, s, m);//归并排序前半部分
		MergeSort2(x, x1, m + 1, t);//归并排序后半部分
		Merge(x1, x, s, m, t);//将两个已排序的子序列归并
	}
}

//打印结果======================================================================
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

//赋值随机数====================================================================
void Assignment(int x[])
{
	srand((unsigned)time(0));
	for (int i = 1; i <= N; i++)
		x[i] = rand() % N;
}

//写入文件======================================================================
void WriteFile(int  x[], int op)
{
	ofstream out;
	switch (op)//选择文件
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
		cout << "类型选择错误！" << endl;
		break;
	}

	if (!out)//出错判断
	{
		cout << "无法打开文件！" << "\n|" << endl;
		exit(0);
	}

	int m = 10;//写入文件
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

//读取文件======================================================================
void ReadFile(int  x[], int op)
{
	ifstream in;
	switch (op)//选择文件
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
		cout << "类型选择错误！" << endl;
		break;
	}

	if (!in)//出错判断
	{
		cout << "无法打开文件！" << "\n|" << endl;
		exit(0);
	}

	string str;//定义输入文件流对象
	int count = 1;
	while (getline(in, str))//按行将文件信息读入到g_arry数组中
	{
		istringstream sin(str);
		while (sin >> x[count])
		{
			count++;
		}
	};
}