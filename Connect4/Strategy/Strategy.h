/********************************************************
*	Strategy.h : ���Խӿ��ļ�                           *
*	������                                              *
*	zhangyf07@gmail.com                                 *
*	2010.8                                              *
*********************************************************/

#ifndef STRATEGY_H_
#define	STRATEGY_H_

#include "Point.h"
#include <ctime>

extern "C" __declspec(dllexport) Point* getPoint(const int M, const int N, const int* top, const int* _board, 
	const int lastX, const int lastY, const int noX, const int noY);

extern "C" __declspec(dllexport) void clearPoint(Point* p);

void clearArray(int M, int N, int** board);

int calculate(int **board,const int N,const int M,const int noX,const int noY,int color);

void boardhash(int **board,const int N,const int M,const int noX,const int noY);

int alphabeta(int **board,const int N,const int M,const int noX,const int noY,int depth,int color,int alpha,int beta);

/*
	������Լ��ĸ�������
*/


#endif