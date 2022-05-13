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

// BFS를 통해 푸는 문제이다.
// 인접한 것들이 몇개인지를 찾아내기 위해 모든 노드를 탐색한다.

class Solve {
public:
	Solve(int n, int m)
		// 2차원 벡터를 초기화 할 때, 1~m, 1~n까지 값이 들어가게 하기 위해 m+1, n+1개의 공간을 할당
		: n{ n }, m{ m }, b(m + 1, vector<char>(n + 1)), visited(m + 1, vector<bool>(n + 1)) {
		for (int i{ 1 }; i <= m; ++i)
			for (int j{ 1 }; j <= n; ++j)
				cin >> b[i][j];

		for (int i{ 1 }; i <= m; ++i)
			for (int j{ 1 }; j <= n; ++j)
				// 해당 위치에 아직 방문하지 않았을 경우,
				// 해당 위치에 대해 bfs를 돌려준다.
				if (not visited[i][j])
					bfs(i, j, b[i][j]);
	}

	void bfs(int r, int c, char team) {
		// 우리팀과 적팀의 bfs를 동시에 탐색하기 위해 큐의 원소로 페어를 넣어줌
		queue<pair<int, int>> q{ };
		// pair<int, int> 객체를 생성해서 넣어줌
		q.push({ r, c });
		// 해당 위치는 방문했으므로 visited의 값을 false -> true로 바꿔줌
		visited[r][c] = true;

		int cnt{ };
		while (not q.empty()) {
			pair<int, int> now{ q.front() };
			q.pop();
			cnt++;

			// 상, 하, 좌, 우 총 4번 반복
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

		// 팀이 어디냐에 따라 N^2값을 각 팀의 위력에 더해줌
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
	int team_W{ }; // 우리 팀의 위력
	int team_B{ }; // 적 팀의 위력

	// 상, 하, 좌, 우 위치를 탐색하기 위한 배열
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
