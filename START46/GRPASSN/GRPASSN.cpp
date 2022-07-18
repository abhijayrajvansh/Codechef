/*    यो न हृष्यति न द्वेष्टि न शोचति न काङ्क्षति। शुभाशुभपरित्यागी भक्तिमान्यः स मे प्रियः॥
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *    author:   abhijayrajvansh
 *    created:  19.07.2022 03:25:50
**/
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define tatakae() int tests = 1; if (TT) cin >> tests; for (int i = 1; i <= tests; i++) { run_case(i);} 

constexpr char nl = '\n'; 

template<class Fun> class rajvansh
{
    Fun fun_;
public:
    template<class T> 
    explicit rajvansh(T &&fun): 
    fun_(std::forward<T>(fun)) {}

    template<class ...Args> 
    decltype(auto) operator()(Args &&...args) 
    { 
        return fun_(std::ref(*this), std::forward<Args>(args)...); 
    }
};

template<class Fun> 
decltype(auto) y_combinator(Fun &&fun) 
{ 
    return rajvansh<std::decay_t<Fun>>(std::forward<Fun>(fun)); 
}

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) 
{ 
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename T_container, typename T = typename enable_if<!is_same

<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator<<(ostream &os, const T_container &v) 
{ 
    os << '{'; string sep; 

    for (const T &x : v) 
        os << sep << x, sep = ", "; 

    return os << '}'; 
}

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) 
{ 
    cerr << ' ' << H; dbg_out(T...); 
}

#ifdef ABHIJAY_DEBUG
#define deb(...) cerr << "["<< #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__);
#else
#define deb(...)
#endif

bool TT = true;

void run_case(int tc){
    int n;
    cin >> n;

    vector<int64_t> a(n);
    
    for (auto &each : a){
        cin >> each;
    }

    map<int, int> mp;

    
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }

    for (auto &a : mp){
        if(a.second % a.first != 0){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
#ifndef ABHIJAY_DEBUG
    cin.tie(nullptr);
    freopen("debug.err", "w", stderr);
#endif
    tatakae();
}