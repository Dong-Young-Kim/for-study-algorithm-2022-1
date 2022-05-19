//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//#define		HEIGHT			3	//	테이블의 세로 길이
//#define		WIDTH			3	//	테이블의 가로 길이
//
//#define		TRUE			1
//#define		FALSE			0
//
//#define		PATTERN_COUNT	4
//
////	테이블을 나타내는 이차원 배열
//int g_Table[HEIGHT][WIDTH] =
//{
//	{2,7,8},
//	{7,0,4},
//	{6,4,0}
//};
//
///*
//	각 열에 따라 패턴의 유형의 최고점수를 기록할 배열
//	배열의 가로 길이가 5칸인 이유는 0번째 열은 쓰지 않을 것이다.
//	그 이유는 이차원 배열의 열의 인덱스가 패턴의 유형을 나타내기 때문이다. 패턴은 1에서 4사이의 값이다.
//	이 1에서 4사이의 값을 배열의 열 인덱스로 쓸 것 이다.
//	행은 돌을 둔 열의 인덱스를 의미한다. 이 이차원 배열의 정보는 곧, 돌을 둔 인덱스와 그 때의 패턴이다.
//	그리고 동적 테이블에 만약 g_DT[1][3]에 7이 저장되어 있다는 의미는
//	'0번 열 인덱스에 돌을 두었을 때의 최고점수와 현재의 1번 열 인덱스에 패턴3에 돌을 둔 점수의 합'이 7임을 의미한다.
//*/
//int g_DT[WIDTH][PATTERN_COUNT + 1];
//
///*
//	돌이 놓인 곳의 최고점을 구하는 함수로 탐색은 0열에서 (WIDTH - 1)번 열이다.
//*/
//int PebbleDT(void);
//
///*
//	매개변수로 받는 두 패턴이 서로 양립가능한지를 판단하는 함수로
//	리턴값이 1이면 양립 가능하고 0이면 양립 불가능하다.
//*/
//int Together(int curPattern, int nextPattern);
//
///*
//	탐색은 0번째 열부터 맨 마지막 열(WIDTH - 1)로 시작하면서 돌을 둔 최고점을 리턴하는 함수
//*/
//int PatternPoint(int i, int curPattern);
//
//
//
///*
//	탐색은 0번째 열부터 맨 마지막 열(WIDTH - 1)로 시작하면서 돌을 둔 최고점을 리턴하는 함수
//*/
//int PebbleDT(void)
//{
//	int curPattern;				//	탐색을 시작할 현재의 패턴 유형
//	int prevPattern;			//	curPattern패턴의 이전의 패턴 유형
//
//	int high = (-1) * _CRT_INT_MAX;	//	0에서 맨 마지막 열까지 탐색해서 얻은 최고점을 저장할 변수
//									//	변수의 초기화는 정수형의 가장 작은 값으로 초기화
//
//	int value;						//	0번 열에서 맨 마지막 열로 탐색해서 얻은 점수로, 임시로 저장할 변수
//
//	int i;							//	탐색할 열 인덱스로 탐색은 0번째 열부터 마지막 열(WIDTH - 1)이다.
//
//	int maxPoint;					//	최종적으로 리턴할 최고점수값
//
//	//	0번째 열에서의 각 패턴들이 만들어 낼 수 있는 점수들을 구한다. 초기화 과정이다.
//	for (curPattern = 1; curPattern <= 4; curPattern++)
//		g_DT[0][curPattern] = PatternPoint(0, curPattern);
//
//	//	0번째 열에서의 각 패턴들의 점수를 구했으므로, 1번째 열부터 탐색을 시작한다.
//	for (i = 1; i < WIDTH; i++)
//	{
//		for (curPattern = 1; curPattern <= 4; curPattern++)
//		{
//			for (prevPattern = 1; prevPattern <= 4; prevPattern++)
//			{
//				//	현재의 패턴인 curPattern와 그 이전 패턴인 prevPattern가 서로 양립가능한 패턴이면
//				if (Together(curPattern, prevPattern) == TRUE)
//				{
//					//	i번째 열에서의 최고점은 현재의 점수와 그 이전에 기록한 최고점을 더한 것이다.
//					value = g_DT[i - 1][prevPattern] + PatternPoint(i, curPattern);
//
//					if (value > high)
//						high = value;
//				}
//			}
//			g_DT[i][curPattern] = high;	//	최고점을 저장
//		}
//	}
//
//	//	4개의 패턴들 중에서 가장 큰 값을 구한다. 이는 배열에서 최대값을 구하는 문제와 같다.
//	maxPoint = g_DT[WIDTH - 1][1];	//	초기값을 배열의 0번째 요소로 초기화를 한 이후에 최대값을 구한다.
//	for (int col = 1; col <= 4; col++)
//	{
//		if (g_DT[WIDTH - 1][col] > maxPoint)
//			maxPoint = g_DT[WIDTH - 1][col];
//	}
//
//	return maxPoint;
//}
//
///*
//	매개변수로 받는 두 패턴이 서로 양립가능한지를 판단하는 함수로
//	리턴값이 1이면 양립 가능하고 0이면 양립 불가능하다.
//*/
//int Together(int curPattern, int nextPattern)
//{
//	//	두 패턴이 같으면 양립 불가능하다.
//	if (curPattern == nextPattern)
//		return FALSE;
//
//	if (curPattern == 4)
//	{
//		if (nextPattern == 2)
//			return TRUE;
//	}
//	else if (curPattern == 3)
//	{
//		if (nextPattern == 1 || nextPattern == 2)
//			return TRUE;
//	}
//	else if (curPattern == 2)
//	{
//		if (nextPattern != 2)
//			return TRUE;
//	}
//	else if (curPattern == 1)
//	{
//		if (nextPattern == 3 || nextPattern == 2)
//			return TRUE;
//	}
//
//	return FALSE;
//}
//
///*
//	i열이 curPattern패턴으로 놓일 때,
//	i열에 돌이 놓인 곳의 점수합을 반환하는 함수
//*/
//int PatternPoint(int i, int curPattern)
//{
//	if (curPattern == 1)
//		return g_Table[0][i];
//
//	else if (curPattern == 2)
//		return g_Table[1][i];
//
//	else if (curPattern == 3)
//		return g_Table[2][i];
//
//	else if (curPattern == 4)
//		return g_Table[0][i] + g_Table[2][i];
//
//	return 0;
//}
//
//int main(void)
//{
//	int res;
//
//	res = PebbleDT();
//
//	printf("조약돌을 놓을 수 있는 최대값 : %d\n", res);
//
//	return 0;
//}