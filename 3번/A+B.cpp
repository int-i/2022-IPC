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

	// �Է¹��� ������ ���� ���� int�� ���ڷ� �ٲ��ִ� �Լ�
	auto ctoi{ [](char c) { return int(c - 48); } };

	string str{ };
	cin >> str;

	// �Է¹��� ���ڿ��� 1�� �ε��� ���� '0'�̶��
	if (str.at(1) == '0')
		// ù��° �Է°��� ������ 10�̹Ƿ�, �ι�° �Է°��� int������ �ٲ��ָ� ��.
		cout << 10 + stoi(str.substr(1)) << endl;
	else // �׷��� �ʴٸ�
		// ù��° �Է°��� ������ 1�� �ڸ����̰�,
		// �ι�° �Է°��� ���ڸ��� Ȥ�� ���ڸ��� �̱� ������ stoi�� ���� int������ ��ȯ
		cout << ctoi(str.at(0)) + stoi(str.substr(1)) << endl;

	return 0;
}
