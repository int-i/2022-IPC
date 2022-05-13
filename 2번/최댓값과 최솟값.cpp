#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;

using std::distance;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] { return cin >> n, n; }() };

	// 입력 값의 범위가 1 ~ 100이기 때문에 min의 기본값을 입력 최대값인 100으로,
	// max의 기본값을 입력 최소값인 1로 넣어주었다.
	int min{ 100 };
	int max{ 1 };
	int minIdx{ };
	int maxIdx{ };

	// 입력받은 n 크기의 벡터를 선언
	vector<int> v(n);
	
	// v의 begin부터 end까지 반복하면서
	for (auto iter{ v.begin() }; iter != v.end(); ++iter) {
		// 이터레이터를 활용해 벡터 v 안에 값을 차례대로 입력해준다.
		cin >> *iter;

		// 만약 입력 받은 값이 min보다 작다면 
		if (min > *iter) {
			min = *iter; // min 값을 입력 받은 값으로 교체
			minIdx = distance(v.begin(), iter) + 1; // 현재 인덱스를 구하기 위해 distance 함수 사용
		}
		// 만약 입력 받은 값이 max보다 크다면
		if (max < *iter) {
			max = *iter; // max 값을 입력 받은 값으로 교체
			maxIdx = distance(v.begin(), iter) + 1;
		}
		// 위의 두 if문은 서로 독립적이기 때문에 else로 이어주지 않았다.
	}

	cout << max << ' ' << min << endl;
	cout << maxIdx << ' ' << minIdx << endl;

	return 0;
}