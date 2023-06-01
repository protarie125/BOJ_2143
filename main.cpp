#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

ll t;
ll n;
vl a;
ll m;
vl b;
vl bsums;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> t;

	cin >> n;
	a = vl(n + 1, 0);
	for (auto i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	cin >> m;
	b = vl(m);
	for (auto i = 0; i < m; ++i) {
		cin >> b[i];
	}

	bsums = vl{};
	for (auto i = 0; i < m; ++i) {
		auto s = b[i];
		bsums.push_back(s);
		for (auto j = i + 1; j < m; ++j) {
			s += b[j];
			bsums.push_back(s);
		}
	}

	sort(bsums.begin(), bsums.end());

	auto ans = ll{ 0 };
	for (auto i = 0; i < n; ++i) {
		const auto al = a[i];
		for (auto j = i + 1; j <= n; ++j) {
			const auto ar = a[j];

			const auto asum = ar - al;
			const auto tt = t - asum;

			const auto lb = lower_bound(bsums.begin(), bsums.end(), tt);
			const auto ub = upper_bound(bsums.begin(), bsums.end(), tt);

			ans += distance(lb, ub);
		}
	}
	cout << ans;

	return 0;
}