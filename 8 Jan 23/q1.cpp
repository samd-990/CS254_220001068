#include<iostream>
#include<cmath>
using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		long long a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long num1 = max(a[0] , a[1]);
		long long num2 = min(a[0] , a[1]);

		for (int i = 2; i < n; i++) {
			if (a[i] >= num1) {
				num2 = num1;
				num1 = a[i];
			}
			else if (a[i] >= num2) {
				num2 = a[i];
			}
		}

		cout << num1 + num2 << '\n';
	}
}