#include <iostream>
#include <vector>

using std::cin;
using std::cout;
constexpr auto endl{ '\n' };

using std::vector;


// ���� �̸��� �и� ���� ���������� ������ ���� ������ ������ ���� ������ swap Ƚ���� ���ϸ� ����ð��� �ʹ� �����ɸ���.
// ���� ������ ���� �޸� �����غ��� �ϴµ�, �츮�� �Ʒ��� ���̵� ����� �ڵ带 ������ ���̴�.
// 
// ���� ���� �������� �������� ������ ���� ������ swap Ƚ���� ����.
// �ش� ���̵� Ȱ���� �켱 ���� ������ �����ϰ�, �� �������� �������� �������� ī��Ʈ�� 1�� ������������.


// �ش� ������ ���� �Լ��� �����Ͽ� Ǫ�� ���� �������� ����.
// ���� Ŭ������ ����� �� �Լ��� �ϳ��� Ŭ������ ���,
// ���� ������ ����ϴ� ��� Ŭ������ �ʵ带 �� �޼��忡�� ������ �� �� �ֵ��� �ߴ�.
class Solve {
public:
	// �����ڿ����� �⺻���� �� �Է��� �޴´�.
	Solve(int n)
		// a�� b ��� nũ��� �ʱ�ȭ, ans�� 0���� �ʱ�ȭ
		: a(n), b(n), ans{ } {
		// a �迭�� �� �Է�
		for (auto& elem : a)
			cin >> elem;

		merge_sort(0, n);
	}

	void merge_sort(int start, int end) {
		// ���� ���� �� ����� (start + 1 >= end)�� ���,
		// �ش� ȣ�� ������ �� �������� �ʰ� �״�� ��ȯ
		if (start + 1 >= end)
			return;

		// ������ ���� mid ���� ����
		int mid{ (start + end) / 2 };

		// start �������� mid���� ����
		merge_sort(start, mid);
		// mid �������� end���� ����
		merge_sort(mid, end);

		// ������ ���� �� ��, ���� ����
		// �켱 ���� �� �κи��� b �迭�� �ű�
		for (int i{ start }; i < end; ++i)
			b[i] = a[i];

		// ������ ���� left �ε����� right �ε����� ����
		// �������� ������ �ؾ� �ϹǷ� �Ʒ��� ���� �ʱ�ȭ
		int left_i{ start };
		int right_i{ mid };

		// left �ε����� mid �ε������� �۰ų�,
		// right �ε����� end �ε��� ���� ���� ���������� �ݺ�
		while (left_i < mid or right_i < end) {
			// right �ε����� end���� �����鼭 left �ε����� mid���� ũ�ų� ���ٸ�,
			if (left_i >= mid)
				// a �迭�� start �ε��� ��ġ�� b �迭�� right �ε��� ���� �ְ�,
				// start �ε����� right �ε����� 1�� ������Ų��.
				a[start++] = b[right_i++];
			
			// left�ε����� mid���� �����鼭,
			// right �ε����� end���� ũ�ų� ���� ��,
			// �Ǵ� b �迭�� left �ε��� ���� b �迭�� right �ε��� ������ �۰ų� ���� ��,
			else if (right_i >= end or b[left_i] <= b[right_i])
				// a �迭�� start �ε��� ��ġ�� b �迭�� left �ε��� ���� �ְ�,
				// start �ε����� left �ε����� 1�� ������Ų��.
				a[start++] = b[left_i++];

			// left �ε����� right �ε����� ���� mid �ε���, end �ε��� ���� ���� ��,
			// �� �ٽø��� (left_i < mid and right_i < end) �� ���
			else {
				// a �迭�� start �ε��� ��ġ�� b �迭�� right �ε��� ���� �ְ�,
				// start �ε����� right �ε����� 1�� ������Ų��.
				a[start++] = b[right_i++];
				// �׸��� ���� ������ ���� mid �ε��� - left �ε��� �� ��ŭ ����
				ans += static_cast<long long>(mid) - left_i;
			}
		}
	}

	void answer() {
		cout << ans << endl;
	}

private:
	vector<int> a; // ���� �迭
	vector<int> b; // ���� �� �迭
	long long ans; // �������� ���� Ƚ��(== ���� ���Ŀ��� swap Ƚ��)
};


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n{ [&] { return cin >> n, n; }() };

	// ���ڰ����� n�� ������� Solve �͸�ü�� ����� �� ��ü�� answer�޼��� ȣ��
	Solve{ n }.answer();
}
