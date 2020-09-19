/*#include <iostream>

using namespace std;


int num;
int comparison(long a, long b)
{
	
	if (a >= b) {
		num = 0;
		return a;
	}
	else if (a < b) {
		num = 1;
		return b;
	}
}
int switching(long a)
{
	if (a == 1)
		return 0;
	else if (a == 0)
		return 1;
}
int main()
{
	int testcase;
	int rownum;
	int row[2][100000] = { 0 };
	int d[2][100000] = { 0 };
	int result;
	cin >> testcase;
	for (long i = 0; i < testcase; i++)
	{
		cin>>rownum;
		for (long j = 0; j < rownum; j++)
		{
			cin >> row[0][j];
		}
		for (long j = 0; j < rownum; j++)
		{
			cin >> row[1][j];
		}
		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = st[0][1] + dp[1][0];
		dp[1][1] = st[1][1] + dp[0][0];

		for (long j = 2; j < rownum; j++)
		{
			d[0][j] = comparison((d[0][j - 2] + row[switching(d[1][j - 2])][j]), (d[0][j - 1] + row[switching(d[1][j - 1])][j]));
			d[1][j] = num;
		}
		result = d[0][rownum - 1];
		cout << result << endl;
	}
	return 0;
}

*/

#include <iostream>
#include <algorithm>

using namespace std;

int st[2][100001] = { 0 };
int dp[2][100001] = { 0 };

int main()
{
	int t;
	int n;
	int max = 0;

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> st[0][i];

		for (int i = 0; i < n; i++)
			cin >> st[1][i];

		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = st[0][1] + dp[1][0];
		dp[1][1] = st[1][1] + dp[0][0];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = st[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = st[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		}


		cout << std::max(dp[0][n - 1], dp[1][n - 1]) << endl;

	}

}