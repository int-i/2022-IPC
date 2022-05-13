#include <iostream>
#include <vector>

using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;

using std::max;

// dp를 통해 푸는 문제이다.

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
				// 인사 가능
				if (j + Lost[i] < 100) {
					// max(인사 x,인사 o)
					// 현재 잃은 체력이 아직 포함되지 않은 이전 최대 기쁨[h+Lost[i]]에 현재 인사의 기쁨을 더해서 비교
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + Lost[i]] + Joy[i]);
				}
				// 인사 불가능
				else
					// 원래 값, 이전 값 중 큰 값을 대입
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