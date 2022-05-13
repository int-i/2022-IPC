#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;

using std::queue;

using std::pair;

// BFS�� ���� Ǫ�� �����̴�.
// ������ �͵��� ������� ã�Ƴ��� ���� ��� ��带 Ž���Ѵ�.

class Solve {
public:
	Solve(int n, int m)
		// 2���� ���͸� �ʱ�ȭ �� ��, 1~m, 1~n���� ���� ���� �ϱ� ���� m+1, n+1���� ������ �Ҵ�
		: n{ n }, m{ m }, b(m + 1, vector<char>(n + 1)), visited(m + 1, vector<bool>(n + 1)) {
		for (int i{ 1 }; i <= m; ++i)
			for (int j{ 1 }; j <= n; ++j)
				cin >> b[i][j];

		for (int i{ 1 }; i <= m; ++i)
			for (int j{ 1 }; j <= n; ++j)
				// �ش� ��ġ�� ���� �湮���� �ʾ��� ���,
				// �ش� ��ġ�� ���� bfs�� �����ش�.
				if (not visited[i][j])
					bfs(i, j, b[i][j]);
	}

	void bfs(int r, int c, char team) {
		// �츮���� ������ bfs�� ���ÿ� Ž���ϱ� ���� ť�� ���ҷ� �� �־���
		queue<pair<int, int>> q{ };
		// pair<int, int> ��ü�� �����ؼ� �־���
		q.push({ r, c });
		// �ش� ��ġ�� �湮�����Ƿ� visited�� ���� false -> true�� �ٲ���
		visited[r][c] = true;

		int cnt{ };
		while (not q.empty()) {
			pair<int, int> now{ q.front() };
			q.pop();
			cnt++;

			// ��, ��, ��, �� �� 4�� �ݺ�
			for (int i{ }; i < 4; ++i) {
				int nr{ now.first + dir[i][0] };
				int nc{ now.second + dir[i][1] };

				if (nr >= 1 and
					nr <= m and
					nc >= 1 and
					nc <= n and
					not visited[nr][nc] and
					b[nr][nc] == team) {

					visited[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}

		// ���� ���Ŀ� ���� N^2���� �� ���� ���¿� ������
		if (team == 'W')
			team_W += cnt * cnt;
		else
			team_B += cnt * cnt;
	}

	void answer() {
		cout << team_W << ' ' << team_B << endl;
	}

private:
	vector<vector<char>> b;
	vector<vector<bool>> visited;

	int n;
	int m;
	int team_W{ }; // �츮 ���� ����
	int team_B{ }; // �� ���� ����

	// ��, ��, ��, �� ��ġ�� Ž���ϱ� ���� �迭
	const int dir[4][2]{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
};

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] { return cin >> n, n; }() };
	int m{ [&] { return cin >> m, m; }() };

	Solve{ n, m }.answer();

	return 0;
}
