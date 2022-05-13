#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// T를 입력받고 i를 0부터 T미만까지 반복
	for (int i{ }, T{ [&] { return cin >> T, T; }() }; i < T; ++i) {
		// 매 반복마다 d를 입력받고,
		int d{ [&] { return cin >> d, d; }() };
		int t{ };

		// 주어진 조건에 의해 계산 진행
		// t가 기존의 t에 비해 1 증가된 경우라 가정하고,
		// t + s 가 d보다 작거나 같은 경우만 성립이 되기 때문에 아래와 같이 코드 작성
		// s = t^2
		while ((t + 1) + pow((t + 1), 2) <= d)
			++t;

		cout << t << endl;
	}
	

	return 0;
}