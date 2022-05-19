//#include<iostream>
//
//using namespace std;
//
//#define	ROWSIZE	3
//#define	COLSIZE	3
//#define	PATTERN_COUNT 4
//
//int g_Table[ROWSIZE][COLSIZE] = {{2,7,8},{7,0,4},{6,4,0}};
//
//int g_DT[COLSIZE][PATTERN_COUNT + 1];
////int PebbleDT(void);
////int Together(int curPattern, int nextPattern);
////int PatternPoint(int i, int curPattern);
//
//int Together(int curPattern, int nextPattern) { //인접하는 패턴이 함깨 존재할 수 있는지 판별하는 함수
//	if (curPattern == 1 && (nextPattern == 2 || nextPattern == 3))								return true;
//	else if (curPattern == 2 && (nextPattern == 1 || nextPattern == 3 || nextPattern == 4))		return true;
//	else if (curPattern == 3 && (nextPattern == 1 || nextPattern == 2))							return true;
//	else if (curPattern == 4 && nextPattern == 2)												return true;
//	else																						return false;
//}
//
//
//int PatternPoint(int i, int curPattern) {
//	if (curPattern == 1) return g_Table[0][i];
//	else if (curPattern == 2) return g_Table[1][i];
//	else if (curPattern == 3) return g_Table[2][i];
//	else if (curPattern == 4) return g_Table[0][i] + g_Table[2][i];
//	return 0;
//}
//
//int PebbleDT(void){
//	int curPattern;				//	탐색을 시작할 현재의 패턴 유형
//	int prevPattern;			//	curPattern패턴의 이전의 패턴 유형
//	int high = numeric_limits<int>::lowest();	//	0에서 맨 마지막 열까지 탐색해서 얻은 최고점을 저장할 변수
//	int value;						//	0번 열에서 맨 마지막 열로 탐색해서 얻은 점수로, 임시로 저장할 변수
//	int maxPoint;					//	최종적으로 리턴할 최고점수값
//	//	0번째 열에서의 각 패턴들이 만들어 낼 수 있는 점수들을 구한다. 초기화 과정이다
//
//	
//	for (curPattern = 1; curPattern <= 4; curPattern++)
//		g_DT[0][curPattern] = PatternPoint(0, curPattern);
//
//	//	0번째 열에서의 각 패턴들의 점수를 구했으므로, 1번째 열부터 탐색을 시작한다.
//	for (int i = 1; i < COLSIZE; i++){ //	탐색할 열 인덱스로 탐색은 0번째 열부터 마지막 열(WIDTH - 1)이다.
//		for (curPattern = 1; curPattern <= 4; curPattern++)	{
//			for (prevPattern = 1; prevPattern <= 4; prevPattern++) {
//				//	현재의 패턴인 curPattern와 그 이전 패턴인 prevPattern가 서로 양립가능한 패턴이면
//				if (Together(curPattern, prevPattern) == true){
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
//	maxPoint = g_DT[COLSIZE - 1][1];	//	초기값을 배열의 0번째 요소로 초기화를 한 이후에 최대값을 구한다.
//	for (int col = 1; col <= 4; col++){
//		if (g_DT[COLSIZE - 1][col] > maxPoint)
//			maxPoint = g_DT[COLSIZE - 1][col];
//	}
//
//	return maxPoint;
//}
//
//
//
//
//int main(){
//	int res;
//	res = PebbleDT();
//	printf("조약돌을 놓을 수 있는 최대값 : %d\n", res);
//	return 0;
//}