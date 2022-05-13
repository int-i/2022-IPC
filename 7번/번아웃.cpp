#include <iostream>
#include <array>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::array;


// N개의 입력을 받아 array에 삽입
template <typename T, size_t N>
auto inputs{ [] {
	array<T, N> arr{ };
	for (auto& elem : arr)
		cin >> elem;

	return arr;
} };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 파이썬의 A, B, C, M = map(int, input().split())를 C++로 비슷하게 구현해봄
	// 당연히 cin >> A >> B >> C >> M이 훨씬 나은 방법이지만 이런 것도 가능하다는걸 보이기 위해 작성
	// structured binding 문법을 사용해, cin으로 값들을 입력받아 만든 array를 언팩 해줌.
	// 이 경우 크기가 4인 int형 array를 언팩해서 A, B, C, M에 각각 대입 해줌.
	auto [A, B, C, M] { inputs<int, 4>() };

	int fatigue{ }; // 피로도
	int work{ }; // 일

	// 하루는 24시간이므로 24번 반복
	for (int i{ }; i < 24; ++i)
		// 현재 피로도 + 일을 함으로써 쌓이는 피로도가 M보다 작거나 같다면
		if (fatigue + A <= M) {
			fatigue += A; // 현재 피로도에 일을 해서 쌓이는 피로도 추가
			work += B; // 지금까지 처리한 일의 양에 처리할 일의 양 추가
			// 즉 다시말해 일을 해준다.
		}
		// 일을 했을때 피로도의 한계를 넘을 것 같다면,
		else {
			// 한시간을 쉬어서 피로도를 줄여준다.
			fatigue -= C;

			// 이때 피로도가 음수가 된다면 피로도를 0으로 만들어준다.
			if (fatigue < 0)
				fatigue = 0;
		}

	// 최종적으로 일한 양 출력
	cout << work << endl;

	return 0;
}
