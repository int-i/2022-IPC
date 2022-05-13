#include <iostream>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

int main() {
	// 이 코드는 C와 C++의 표준 stream의 동기화를 끊는 역할을 한다.
	// cin과 cout의 속도가 C의 입출력 속도에 비해 떨어지기 때문에 저 코드를 사용해 속도를 높이는 기능으로 사용한다.
	// 하지만 동기화를 끊게되면 C의 입출력 함수를 더 이상 사용하지 못하는데
	// printf, scanf, getchar 등등 C의 입출력 함수를 사용한다면 해당 코드는 사용할 수 없다.
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N 변수를 만들고, cin을 통해 값을 입력해준다.
	// 람다를 사용해 초기화식 안에서 cin을 사용해 값을 입력받아 N을 초기화해주었다.
	// 이건 딱히 성능 때문은 아니고 최대한 파이써닉하게 코드를 구성해보고 싶어 이와 같이 코드를 짜보았다.
	int N{ [&] { return cin >> N, N; }() };

	cout << N - 2017 << endl;

	return 0;
}
