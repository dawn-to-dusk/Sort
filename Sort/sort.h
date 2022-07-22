/******************************************************************************
File name : sort.h
Description  : 排序算法的头文件
*******************************************************************************/
#ifndef SORT_H
#define SORT_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#include<iomanip>

#define N 100000

void ShellSort(int x[], int n);//希尔排序
int Partition(int x[], int i, int j);//快速排序的一次划分算法
void QuickSort(int x[], int i, int j);//快速排序
void Sift(int x[], int k, int m);//堆排序的筛选算法
void HeapSort(int x[], int n);//堆排序
void Merge(int x[], int x1[], int s, int m, int t);//一次归并算法
void MergePass(int x[], int x1[], int n, int h);//一趟归并算法
void MergeSort1(int x[], int x1[], int n);//归并排序（非递归算法）
void MergeSort2(int x[], int x1[], int s, int t);//归并排序（递归算法）
void Print(int x[], int n, int i);//打印结果
void Assignment(int x[]);//赋值随机数
void WriteFile(int  x[], int op);//写入文件
void ReadFile(int x[], int op);//读取文件信息


#endif // !SORT_H
