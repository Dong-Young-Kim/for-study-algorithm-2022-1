//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//#define MAX_VALUE 987654321.0
//using namespace std;
//int n;
////��θ� ������ dp 
//int cache[17][65536], dist[17][17];
//int TSP(int cur, int visited) {
//    //���� 10�����, 100000000000-1 =011111111111;
//    if (visited == (1 << n) - 1)  return dist[cur][0];
//
//    int& ret = cache[cur][visited];
//    if (ret != 0) return ret;
//    ret = MAX_VALUE;
//    for (int next = 0; next <= n; next++) {
//        if (visited & (1 << next))continue;
//        if (dist[cur][next] == 0) continue;
//        ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
//    }
//    return ret;
//}
//
//void printPath(long double distance) {
//    int piv = 0, masking = 1;
//    //cache �迭�� Ž���ذ��� ���� ��θ� ã�´�. 
//    for (int j = 0; j <= n; j++) {
//        for (int k = 0; k <= n; k++) {
//            if (masking & (1 << k)) continue;
//            if (distance - dist[piv][k] == cache[k][masking + (1 << k)]) {
//                //���� ��� ���� 
//                path.push_back(k);
//                distance = cache[k][masking + (1 << k)];
//                piv = k; masking += (1 << k);
//            }
//        }
//    }
//    //��� ��� 
//    for (int i = 0; i < path.size(); i++)
//        printf("(%d)->", path[i]);
//    printf("(0)");
//}
//
//int main() {
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            scanf("%d", &dist[i][j]);
//        }
//    }
//    printf("%d", TSP(0, 1));
//}