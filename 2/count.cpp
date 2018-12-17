#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> regroup(const vector<vector<int>>& m, int n) {
	vector<vector<int>> result(m.size());
	if (m[0].size() % n != 0)
		throw exception();
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m[0].size()/n; ++j) {
			int sum = 0;
			for (int k = 0; k < n; ++k)
				sum += m[i][j*n + k];
			result[i].push_back(sum);
		}
	}
	return result;
}

int main() {
	// vector<vector<int>> m = {
	// 	{180, 80, 60, 20},
	// 	{90, 140, 80, 20},
	// 	{60, 140, 80, 50}, 
	// };

	vector<vector<int>> m = {
		{1, 4, 8, 18, 6, 7, 5, 14, 2, 6, 11, 9, 4, 4, 2, 2, 2, 1, 1, 4, 2, 1, 0, 0, 2, 1, 2, 2, 3, 1, 0, 1, 1, 1, 1, 2},
		{0, 4, 10, 10, 12, 12, 5, 13, 6, 7, 7, 4, 3, 1, 5, 2, 0, 0, 3, 1, 0, 0, 0, 2, 2, 2, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
	};

	m = regroup(m, 3);

	for (auto& i : m) {
		for (auto& j : i)
			cout << setw(3) << j;
		cout << endl;
	}

	vector<int> a(m.size()), b(m[0].size());
	for (int i = 0; i < a.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < b.size(); ++j)
			sum += m[i][j];
		a[i] = sum;
	}

	for (int i = 0; i < b.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < a.size(); ++j)
			sum += m[j][i];
		b[i] = sum;
	}

	int sum = 0;
	for (auto& i : a) sum += i;

	double res = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j)
			if (a[i] != 0 && b[j] != 0)
				res += double(m[i][j]*m[i][j])/(a[i]*b[j]);
	}
	res -= 1;
	res *= sum;

	cout << res;
}