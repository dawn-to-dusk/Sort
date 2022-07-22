/******************************************************************************
File name : sort.h
Description  : �����㷨��ͷ�ļ�
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

void ShellSort(int x[], int n);//ϣ������
int Partition(int x[], int i, int j);//���������һ�λ����㷨
void QuickSort(int x[], int i, int j);//��������
void Sift(int x[], int k, int m);//�������ɸѡ�㷨
void HeapSort(int x[], int n);//������
void Merge(int x[], int x1[], int s, int m, int t);//һ�ι鲢�㷨
void MergePass(int x[], int x1[], int n, int h);//һ�˹鲢�㷨
void MergeSort1(int x[], int x1[], int n);//�鲢���򣨷ǵݹ��㷨��
void MergeSort2(int x[], int x1[], int s, int t);//�鲢���򣨵ݹ��㷨��
void Print(int x[], int n, int i);//��ӡ���
void Assignment(int x[]);//��ֵ�����
void WriteFile(int  x[], int op);//д���ļ�
void ReadFile(int x[], int op);//��ȡ�ļ���Ϣ


#endif // !SORT_H
