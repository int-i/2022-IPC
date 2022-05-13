#include <iostream>
#include <string>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::string;
using std::stoi;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력받은 문자형 숫자 값을 int형 숫자로 바꿔주는 함수
	auto ctoi{ [](char c) { return int(c - 48); } };

	string str{ };
	cin >> str;

	// 입력받은 문자열의 1번 인덱스 값이 '0'이라면
	if (str.at(1) == '0')
		// 첫번째 입력값은 무조건 10이므로, 두번째 입력값만 int형으로 바꿔주면 됨.
		cout << 10 + stoi(str.substr(1)) << endl;
	else // 그렇지 않다면
		// 첫번째 입력값은 무조건 1의 자리수이고,
		// 두번째 입력값은 한자리수 혹은 두자리수 이기 때문에 stoi를 통해 int형으로 변환
		cout << ctoi(str.at(0)) + stoi(str.substr(1)) << endl;

	return 0;
}
