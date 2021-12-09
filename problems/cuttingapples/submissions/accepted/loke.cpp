#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    ll R, S; cin >> R >> S;
    ll loke = 2*M_PI*R*R*R/(3*S*S*S) + 0.5;

    ll base_exp = 1;
    while (((1 << base_exp) - 2)*S <= R) {
        base_exp++;
    }
    ll base_val = (1 << (base_exp - 1)) - 1;
    vi cubes(4);
    ll rlim = (R+3*S) / S;
    rep(x, 1, rlim) {
        rep(y, 1, rlim) {
            rep(z, 1, rlim) {
                if ((x*x + y*y + z*z)*S*S > R*R) {
                    break;
                }
                if (z > base_val) {
                    cubes[3] += 8;
                } else if (y > base_val) {
                    cubes[2] += 8;
                } else if (x > base_val) {
                    cubes[1] += 8;
                } else {
                    cubes[0] += 8;
                }
            }
        }
    }
    ll sum = 0;
    rep(i, 0, 4) {
        sum += cubes[i];
        if (sum >= loke) {
            cout << 3*base_exp + i << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}
