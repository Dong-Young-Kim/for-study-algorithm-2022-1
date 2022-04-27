#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int fib(int);

int main() {

	clock_t start, end;
	float res;

	cout << "n^3(Cubic complexity) test algorithm" << endl;
	int test_n[] = { 10, 50, 100, 150, 200 };

	for (int T = 0; T < 5; T++) {
		int n = test_n[T];

		//2차원 행렬 제작
		int value = 0;
		vector<vector<int>> matrix_a;
		vector<vector<int>> matrix_b;
		vector<vector<int>> matrix_c;
		vector<vector<int>> matrix_res_abc(n, vector<int>(n, 0));
		vector<vector<int>> matrix_res_ab(n, vector<int>(n, 0));;


		for (int i = 0; i < n; i++, value++) {
			vector<int> tmp;
			for (int j = 0; j < n; j++, value++) {
				tmp.push_back(value);
			}
			matrix_a.push_back(tmp);
			matrix_b.push_back(tmp);
			matrix_c.push_back(tmp);
		}

		start = clock();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					matrix_res_ab[i][j] += matrix_a[i][k] * matrix_b[k][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					matrix_res_abc[i][j] += matrix_res_ab[i][k] * matrix_c[k][j];

		end = clock();

		res = (float)(end - start);
		cout << "n = " << n << "  ->  result = " << res << "ms\n";

	}


	cout << "\n2^n(Exponential complexity) test algorithm" << endl;
	test_n[0] = 10; test_n[1] = 20; test_n[2] = 30; test_n[3] = 40; test_n[4] = 43;

	for (int T = 0; T < 5; T++) {
		int n = test_n[T];	

		start = clock();
		fib(n);
		end = clock();

		res = (float)(end - start);
		cout << "n = " << n << "  ->  result = " << res << "ms\n";
	}
}

int fib(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fib(n - 1) + fib(n - 2);
}
