
//original kmp
//int KMP(string& p, string& t) {
//	int M = p.length(), N = t.length();
//	vector<int> next = initNext(p);
//	int i, j;
//	for (i = 0, j = 0; j < M && i < N; i++, j++) {
//		while ((j >= 0) && t[i] != p[j])
//			j = next[j];
//	}
//	if (j == M) return i - M; //pattern�� ã��
//	else return i;//pattern�� ã�� ����
//}