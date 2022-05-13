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

	// C++���� string ������ ���� ������ ������ ���� �Լ��� ������ش�.
	auto multi{ [](string str, int n) {
		// ���� ��͸� �̿��� ���� ���
		// ���ٸ� ���� ����� ������ ������ ����
		// ���ٷ� ���� �͸��Լ��� �ڷ����� function�� multiTail��� ������ ����־� �ش�.
		// �׸��� multiTail ������ ���� �ش� �͸��Լ��� ���ȣ�� ���ش�.
		// ���� ��ʹ� ��� ȣ���� �������� ���� �ѹ��� ��ȯ�ϴ� ����ȭ ����̴�.
		// �ݺ� Ƚ���� ����⸦ �Ű������� ����Ͽ� ���������� ���� ����⸦ �״�� ��ȯ.
		function<string(int, string)> multiTail { [&multiTail, str](int n, string acc) {
				return n == 0 ? acc : multiTail(n - 1, acc += str);
		} };
		// �ݺ� ��ų Ƚ���� 1 ���� �۴ٸ� "" ��ȯ, 1 ���� ũ�ų� ���ٸ� multiTail�� ��ȯ�� ��ȯ.
		return n < 1 ? "" : multiTail(n, "");
	} };

	// i�� n�� �ݺ��ϸ鼭 �� ���� ����Ѵ�.
	for (int i{ }, n{ [&] { return cin >> n, n; }() }; i < n; ++i)
		// ���� ���� n - i ���� ������ ��� ���� ��,
		// "* "�� i + 1 �� ����Ѵ�.
		cout << multi(" ", n - i) + multi("* ", i + 1) << endl;


	return 0;
}
