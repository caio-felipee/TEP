#include <bits/stdc++.h>

using namespace std;

const int oo { 2000000010 };

int solve(int N, const vector<int>& as)
{
    vector<int> lis(N + 1, oo);
    lis[0] = 0;
    auto ans = 0;

    for (int i = 0; i < N; ++i)
    {
        auto it = lower_bound(lis.begin(), lis.end(), as[i]);
        auto pos = (int) (it - lis.begin());

        ans = max(ans, pos);
        lis[pos] = min(as[i], lis[pos]);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    cout <<  solve(N, as) << '\n';

    return 0;
}
