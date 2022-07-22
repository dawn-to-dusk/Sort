/*******************************************************************************
File name : main.cpp
Description : 主程序
********************************************************************************/
#include"sort.h"
#include<time.h>

int main()
{
	int op;
	int x[N + 1] = { 0,2,8,1,9,3 };
	time_t begin, end;//记录时间的变量
	Assignment(x);//随机赋值

	WriteFile(x, 0);//写入文件信息
	//ShellSort(x, N);//使有序

	while (1)
	{
		cout << "----------请选择一下排序方式----------" << endl;
		cout << "  【1】希尔排序" << endl;
		cout << "  【2】快速排序" << endl;
		cout << "  【3】堆排序" << endl;
		cout << "  【4】归并排序" << endl;
		cout << "  【5】退出" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			cout << "**** 希尔排序 ****" << endl;
			begin = clock();
			ShellSort(x, N);//参数为数组和元素个数
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		case 2:
			cout << "**** 快速排序 ****" << endl;
			begin = clock();
			QuickSort(x, 1, N);//参数为数组和元素的始终序号
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		case 3:
			cout << "**** 堆排序 ****" << endl;
			begin = clock();
			HeapSort(x, N);//参数为数组和减去首位元素的元素个数
			end = clock();
			cout << "runtime: " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
			break;
		case 4:
		{
			cout << "**** 归并排序 ****" << endl;
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
			cout << "输入错误！" << endl;
			break;
		}
		WriteFile(x, op);//存储当前排序后的数据
		ReadFile(x, 0);//重新读取文件信息以进行重复排序
	}
}