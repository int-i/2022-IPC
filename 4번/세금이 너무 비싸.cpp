#include <iostream>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] { return cin >> n, n; }() };
	
	// ��ü ��� 22�ۼ�Ʈ�� n * 0.78
	// ��ü ��� �� 80�ۼ�Ʈ�� ���� ��������(n * 0.8)
	// �׸��� �� �� ������(n * 0.2)�� 22�ۼ�Ʈ(* 0.78)
	cout << static_cast<int>(n * 0.78) << " "
		<< static_cast<int>(n * 0.8 + n * 0.2 * 0.78);

	return 0;
}