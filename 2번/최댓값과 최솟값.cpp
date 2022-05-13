#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;

using std::distance;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] {return cin >> n, n; }() };

	// �Է� ���� ������ 1 ~ 100�̱� ������ min�� �⺻���� �Է� �ִ밪�� 100����,
	// max�� �⺻���� �Է� �ּҰ��� 1�� �־��־���.
	int min{ 100 };
	int max{ 1 };
	int minIdx{ };
	int maxIdx{ };

	// �Է¹��� n ũ���� ���͸� ����
	vector<int> v(n);
	
	// v�� begin���� end���� �ݺ��ϸ鼭
	for (auto iter{ v.begin() }; iter != v.end(); ++iter) {
		// ���ͷ����͸� Ȱ���� ���� v �ȿ� ���� ���ʴ�� �Է����ش�.
		cin >> *iter;

		// ���� �Է� ���� ���� min���� �۴ٸ� 
		if (min > *iter) {
			min = *iter; // min ���� �Է� ���� ������ ��ü
			minIdx = distance(v.begin(), iter) + 1; // ���� �ε����� ���ϱ� ���� distance �Լ� ���
		}
		// ���� �Է� ���� ���� max���� ũ�ٸ�
		if (max < *iter) {
			max = *iter; // max ���� �Է� ���� ������ ��ü
			maxIdx = distance(v.begin(), iter) + 1;
		}
		// ���� �� if���� ���� �������̱� ������ else�� �̾����� �ʾҴ�.
	}

	cout << max << ' ' << min << endl;
	cout << maxIdx << ' ' << minIdx << endl;

	return 0;
}