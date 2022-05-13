#include <iostream>
#include <array>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::array;


// N���� �Է��� �޾� array�� ����
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

	// ���̽��� A, B, C, M = map(int, input().split())�� C++�� ����ϰ� �����غ�
	// �翬�� cin >> A >> B >> C >> M�� �ξ� ���� ��������� �̷� �͵� �����ϴٴ°� ���̱� ���� �ۼ�
	// structured binding ������ �����, cin���� ������ �Է¹޾� ���� array�� ���� ����.
	// �� ��� ũ�Ⱑ 4�� int�� array�� �����ؼ� A, B, C, M�� ���� ���� ����.
	auto [A, B, C, M] { inputs<int, 4>() };

	int fatigue{ }; // �Ƿε�
	int work{ }; // ��

	// �Ϸ�� 24�ð��̹Ƿ� 24�� �ݺ�
	for (int i{ }; i < 24; ++i)
		// ���� �Ƿε� + ���� �����ν� ���̴� �Ƿε��� M���� �۰ų� ���ٸ�
		if (fatigue + A <= M) {
			fatigue += A; // ���� �Ƿε��� ���� �ؼ� ���̴� �Ƿε� �߰�
			work += B; // ���ݱ��� ó���� ���� �翡 ó���� ���� �� �߰�
			// �� �ٽø��� ���� ���ش�.
		}
		// ���� ������ �Ƿε��� �Ѱ踦 ���� �� ���ٸ�,
		else {
			// �ѽð��� ��� �Ƿε��� �ٿ��ش�.
			fatigue -= C;

			// �̶� �Ƿε��� ������ �ȴٸ� �Ƿε��� 0���� ������ش�.
			if (fatigue < 0)
				fatigue = 0;
		}

	// ���������� ���� �� ���
	cout << work << endl;

	return 0;
}
