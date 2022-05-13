#include <iostream>
#include <algorithm>
#include <functional>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::string;

using std::function;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// C++에는 string 곱셈이 없기 때문에 간단히 곱셈 함수를 만들어준다.
	auto multi{ [](string str, int n) {
		// 꼬리 재귀를 이용해 곱셈 계산
		// 람다를 통한 재귀의 구현은 다음과 같다
		// 람다로 만든 익명함수를 자료형이 function인 multiTail라는 변수에 집어넣어 준다.
		// 그리고 multiTail 변수를 통해 해당 익명함수를 재귀호출 해준다.
		// 꼬리 재귀는 재귀 호출의 마지막에 값을 한번에 반환하는 최적화 기법이다.
		// 반복 횟수와 누산기를 매개변수로 사용하여 최종적으로 나온 누산기를 그대로 반환.
		function<string(int, string)> multiTail { [&multiTail, str](int n, string acc) {
				return n == 0 ? acc : multiTail(n - 1, acc += str);
		} };
		// 반복 시킬 횟수가 1 보다 작다면 "" 반환, 1 보다 크거나 같다면 multiTail의 반환값 반환.
		return n < 1 ? "" : multiTail(n, "");
	} };

	// i는 n번 반복하면서 각 행을 출력한다.
	for (int i{ }, n{ [&] { return cin >> n, n; }() }; i < n; ++i)
		// 가장 먼저 n - i 개의 공백을 출력 해준 뒤,
		// "* "을 i + 1 번 출력한다.
		cout << multi(" ", n - i) + multi("* ", i + 1) << endl;


	return 0;
}
