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
//int Together(int curPattern, int nextPattern) { //�����ϴ� ������ �Ա� ������ �� �ִ��� �Ǻ��ϴ� �Լ�
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
//	int curPattern;				//	Ž���� ������ ������ ���� ����
//	int prevPattern;			//	curPattern������ ������ ���� ����
//	int high = numeric_limits<int>::lowest();	//	0���� �� ������ ������ Ž���ؼ� ���� �ְ����� ������ ����
//	int value;						//	0�� ������ �� ������ ���� Ž���ؼ� ���� ������, �ӽ÷� ������ ����
//	int maxPoint;					//	���������� ������ �ְ�������
//	//	0��° �������� �� ���ϵ��� ����� �� �� �ִ� �������� ���Ѵ�. �ʱ�ȭ �����̴�
//
//	
//	for (curPattern = 1; curPattern <= 4; curPattern++)
//		g_DT[0][curPattern] = PatternPoint(0, curPattern);
//
//	//	0��° �������� �� ���ϵ��� ������ �������Ƿ�, 1��° ������ Ž���� �����Ѵ�.
//	for (int i = 1; i < COLSIZE; i++){ //	Ž���� �� �ε����� Ž���� 0��° ������ ������ ��(WIDTH - 1)�̴�.
//		for (curPattern = 1; curPattern <= 4; curPattern++)	{
//			for (prevPattern = 1; prevPattern <= 4; prevPattern++) {
//				//	������ ������ curPattern�� �� ���� ������ prevPattern�� ���� �縳������ �����̸�
//				if (Together(curPattern, prevPattern) == true){
//					//	i��° �������� �ְ����� ������ ������ �� ������ ����� �ְ����� ���� ���̴�.
//					value = g_DT[i - 1][prevPattern] + PatternPoint(i, curPattern);
//
//					if (value > high)
//						high = value;
//				}
//			}
//			g_DT[i][curPattern] = high;	//	�ְ����� ����
//		}
//	}
//
//	//	4���� ���ϵ� �߿��� ���� ū ���� ���Ѵ�. �̴� �迭���� �ִ밪�� ���ϴ� ������ ����.
//	maxPoint = g_DT[COLSIZE - 1][1];	//	�ʱⰪ�� �迭�� 0��° ��ҷ� �ʱ�ȭ�� �� ���Ŀ� �ִ밪�� ���Ѵ�.
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
//	printf("���൹�� ���� �� �ִ� �ִ밪 : %d\n", res);
//	return 0;
//}