#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = (a); i < int(b); i++)
#define trav(x, a) for(auto& x : a)

int n;
vi a;

struct dp_n2_ds{
    map<int, pi> m;

    void add(int first, int second){
        auto ptr = m.lower_bound(first-second);
        if(ptr != m.begin()) ptr--;
        while(ptr != m.begin() && first <= ptr->second.first){
            auto x = ptr;
            x--;
            m.erase(ptr);
            ptr = x;
        }
        while(ptr != m.end() && second <= ptr->second.second){
            auto x = ptr;
            x++;
            m.erase(ptr);
            ptr = x;
        }
        m[first-second] = {first, second};
    }

    int query(int move){
        auto ptr = m.lower_bound(move);
        if(ptr == m.end()) ptr--;
        int r = ptr->second.first;
        if(ptr != m.begin()){
            ptr--;
            r = min(r, ptr->second.second+move);
        }
        return r;
    }
};
vvi dp_n2_vec;
dp_n2_ds _dp_n2_ds;
int dp_n2(){
    for(int i = 0; i < n; i++) a[i]++;
    dp_n2_vec = vvi(n+1, vi(n+1, inf));
    for(int i = 0; i <= n; i++)
        dp_n2_vec[0][i] = -inf;

    int ans = 0;
    for(int diag = 0; diag <= n-1; diag++){
        _dp_n2_ds = dp_n2_ds();
        _dp_n2_ds.add(0, dp_n2_vec[max(0, -diag)][n-max(0, diag)]);
        int addextra = 0;
        for(int j = 1; j <= n-abs(diag); j++){
            int pos = n - max(0, diag) - j;
            int answer = max(0, -diag) + j;

            int r = min(_dp_n2_ds.query(a[pos]) + addextra, dp_n2_vec[answer][pos+1] - a[pos]);

            addextra += a[pos];

            dp_n2_vec[answer][pos] = r;
            _dp_n2_ds.add(-addextra, r - addextra);
        }
        if(diag >= 0 && dp_n2_vec[n-diag][0] <= 0){
            ans = n-diag;
            break;
        }
    }

    for(int i = 0; i < n; i++) a[i]--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	a = vi(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = dp_n2();
	cout << ans << "\n";
}
