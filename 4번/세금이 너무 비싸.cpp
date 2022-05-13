#include <iostream>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] { return cin >> n, n; }() };
	
	// 전체 상금 22퍼센트는 n * 0.78
	// 전체 상금 중 80퍼센트를 경비로 인정받음(n * 0.8)
	// 그리고 그 중 나머지(n * 0.2)의 22퍼센트(* 0.78)
	cout << static_cast<int>(n * 0.78) << " "
		<< static_cast<int>(n * 0.8 + n * 0.2 * 0.78);

	return 0;
}