#include <iostream>
#include <vector>

using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;


// 문제 이름은 분명 버블 정렬이지만 실제로 버블 정렬을 진행해 버블 정렬의 swap 횟수를 구하면 수행시간이 너무 오래걸린다.
// 따라서 문제를 조금 달리 생각해봐야 하는데, 우리는 아래의 아이디어를 사용해 코드를 구성할 것이다.
// 
// 병합 정렬 과정에서 교차점의 개수와 버블 정렬의 swap 횟수는 같다.
// 해당 아이디어를 활용해 우선 병합 정렬을 구현하고, 그 과정에서 교차점의 개수마다 카운트를 1씩 증가시켜주자.


// 해당 문제는 여러 함수를 구성하여 푸는 것이 가독성에 좋다.
// 따라서 클래스를 만들어 각 함수를 하나의 클래스에 담고,
// 전역 변수를 사용하는 대신 클래스의 필드를 각 메서드에서 가져다 쓸 수 있도록 했다.
class Solve {
public:
	// 생성자에서는 기본적인 값 입력을 받는다.
	Solve(int n)
		// a와 b 모두 n크기로 초기화, ans는 0으로 초기화
		: a(n), b(n), ans{ } {
		// a 배열에 값 입력
		for (auto& elem : a)
			cin >> elem;

		merge_sort(0, n);
	}

	void merge_sort(int start, int end) {
		// 만약 분할 된 결과가 (start + 1 >= end)일 경우,
		// 해당 호출 스택은 더 진행하지 않고 그대로 반환
		if (start + 1 >= end)
			return;

		// 분할을 위해 mid 지점 선언
		int mid{ (start + end) / 2 };

		// start 지점부터 mid까지 분할
		merge_sort(start, mid);
		// mid 지점부터 end까지 분할
		merge_sort(mid, end);

		// 끝까지 분할 한 뒤, 정복 시작
		// 우선 정복 할 부분만을 b 배열에 옮김
		for (int i{ start }; i < end; ++i)
			b[i] = a[i];

		// 정복을 위한 left 인덱스와 right 인덱스를 선언
		// 오름차순 정렬을 해야 하므로 아래와 같이 초기화
		int left_i{ start };
		int right_i{ mid };

		// left 인덱스가 mid 인덱스보다 작거나,
		// right 인덱스가 end 인덱스 보다 작은 범위에서만 반복
		while (left_i < mid or right_i < end) {
			// right 인덱스가 end보다 작으면서 left 인덱스가 mid보다 크거나 같다면,
			if (left_i >= mid)
				// a 배열의 start 인덱스 위치에 b 배열의 right 인덱스 값을 넣고,
				// start 인덱스와 right 인덱스를 1씩 증가시킨다.
				a[start++] = b[right_i++];
			
			// left인덱스가 mid보다 작으면서,
			// right 인덱스가 end보다 크거나 같을 때,
			// 또는 b 배열의 left 인덱스 값이 b 배열의 right 인덱스 값보다 작거나 같을 때,
			else if (right_i >= end or b[left_i] <= b[right_i])
				// a 배열의 start 인덱스 위치에 b 배열의 left 인덱스 값을 넣고,
				// start 인덱스와 left 인덱스를 1씩 증가시킨다.
				a[start++] = b[left_i++];

			// left 인덱스와 right 인덱스가 각각 mid 인덱스, end 인덱스 보다 작을 때,
			// 즉 다시말해 (left_i < mid and right_i < end) 인 경우
			else {
				// a 배열의 start 인덱스 위치에 b 배열의 right 인덱스 값을 넣고,
				// start 인덱스와 right 인덱스를 1씩 증가시킨다.
				a[start++] = b[right_i++];
				// 그리고 정답 변수의 값에 mid 인덱스 - left 인덱스 값 만큼 증가
				ans += static_cast<long long>(mid) - left_i;
			}
		}
	}

	void answer() {
		cout << ans << endl;
	}

private:
	vector<int> a; // 원본 배열
	vector<int> b; // 정렬 된 배열
	long long ans; // 교차점을 지난 횟수(== 버블 정렬에서 swap 횟수)
};


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] { return cin >> n, n; }() };

	// 인자값으로 n을 집어넣은 Solve 익명객체를 만들고 그 객체의 answer메서드 호출
	Solve{ n }.answer();
}
