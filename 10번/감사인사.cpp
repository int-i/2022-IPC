#include <iostream>
#include <vector>

using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;

using std::max;

// dp�� ���� Ǫ�� �����̴�.

class Solve {
public:
	Solve(int N)
		: N{ N }, Lost(N + 1), Joy(N + 1), dp(N + 1, vector<int>(101)) {
		for (int i{ 1 }; i <= N; ++i)
			cin >> Lost[i];

		for (int i{ 1 }; i <= N; ++i)
			cin >> Joy[i];

		greeting();
	}

	void greeting() {
		for (int i{ 1 }; i <= N; i++) {
			for (int j{ }; j <= 100; j++) {
				// �λ� ����
				if (j + Lost[i] < 100) {
					// max(�λ� x,�λ� o)
					// ���� ���� ü���� ���� ���Ե��� ���� ���� �ִ� ���[h+Lost[i]]�� ���� �λ��� ����� ���ؼ� ��
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + Lost[i]] + Joy[i]);
				}
				// �λ� �Ұ���
				else
					// ���� ��, ���� �� �� ū ���� ����
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);

				if (dp[i][j] > result)
					result = dp[i][j];
			}
		}
	}

	void answer() {
		cout << result << endl;
	}

private:
	const int N;

	vector<int> Lost;
	vector<int> Joy;

	vector<vector<int>> dp;

	int result{ };
};

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N{ [&] { return cin >> N, N; }() };

	Solve{ N }.answer();

	return 0;
}