//void heapify(vector<unsigned int>& a, int h, int m) {
//	unsigned int v = a[h];
//
//	int j = 2 * h;
//	for (int j = 2 * h; j <= m; j *= 2) {
//		if (j < m && a[j] < a[j + 1])
//			j++;
//		if (v >= a[j])
//			break;
//		else
//			a[j / 2] = a[j];
//	}
//	a[j / 2] = v;
//}

//void heapify(vector<unsigned int>& a, int h, int m)
//{
//	int v = 2 * h;
//
//	if (v < m && a[v] < a[v + 1]) v++;
//
//	if (a[h] < a[v])
//	{
//		swap(a[h], a[v]);
//		if (v <= m / 2) heapify(a, v, m);
//	}
//}
//
//void HeapSort(vector<unsigned int>& a) {
//	int n = a.size() - 1;
//
//	for (int i = n / 2; i >= 1; i--)
//		heapify(a, i, n);
//
//	for (int i = n - 1; i > 1; i--) {
//		swap(a[i], a[i + 1]);
//		heapify(a, 1, i);
//	}
//
//}