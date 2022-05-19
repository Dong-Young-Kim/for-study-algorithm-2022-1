#include<iostream>

#define NODENUM 5
#define INF std::numeric_limits<int>::max() / 10 //오버 플로우 방지 위한 /10

const int W[NODENUM][NODENUM] = { {0, 1, INF, 1, 5},
								  {9, 0, 3, 2, INF},
								  {INF, INF, 0, 4, INF},
								  {INF, INF, 2, 0, 3},
								  {3, INF, INF, INF, 0} };

int D[NODENUM][NODENUM];
int P[NODENUM][NODENUM];

void printMat(int matrix[NODENUM][NODENUM]) { //행렬 출력
	for (int i = 0; i < NODENUM; i++) {
		for (int j = 0; j < NODENUM; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void floyd() { //P, D 배열을 생성하는 floyd 함수
	//초기화
	for (int i = 0; i < NODENUM; i++) {
		for (int j = 0; j < NODENUM; j++) {
			P[i][j] = 0;
			D[i][j] = W[i][j];
		}
	}

	//각 정점간의 거리를 비교하여 D를 갱신
	for (int k = 0; k < NODENUM; k++) {
		for (int i = 0; i < NODENUM; i++) {
			for (int j = 0; j < NODENUM; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k + 1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void path(int q, int r){
	if (P[q-1][r-1] != 0){
		path(q, P[q-1][r-1]);
		printf("v%d -> ", P[q-1][r-1]);
		path(P[q-1][r-1], r);
	}
}

int main() {
	
	floyd();

	printf("D[i][j] is\n");
	printMat(D);
	printf("\nP[i][j] is\n");
	printMat(P);

	//출발 도착 노드에 대한 경로 생성
	int start = 2;
	int end = 5;
	printf("\nThe Shortest Path(%d, %d) is v%d -> ", start, end, start);
	path(start, end);
	printf("v%d\n", end);
}