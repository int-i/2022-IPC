#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// T�� �Է¹ް� i�� 0���� T�̸����� �ݺ�
	for (int i{ }, T{ [&] { return cin >> T, T; }() }; i < T; ++i) {
		// �� �ݺ����� d�� �Է¹ް�,
		int d{ [&] { return cin >> d, d; }() };
		int t{ };

		// �־��� ���ǿ� ���� ��� ����
		// t�� ������ t�� ���� 1 ������ ���� �����ϰ�,
		// t + s �� d���� �۰ų� ���� ��츸 ������ �Ǳ� ������ �Ʒ��� ���� �ڵ� �ۼ�
		// s = t^2
		while ((t + 1) + pow((t + 1), 2) <= d)
			++t;

		cout << t << endl;
	}
	

	return 0;
}