#include <bits/stdc++.h>
#define MAX 1000002
using namespace std;

int sn, cnt;
long long a[MAX], s[MAX], n;
inline int id(long long a) {  //内联函数更高效 
    return a <= sn ? a : cnt - (n / a) + 1;
}
double inv[MAX];

int main() {
    int T = 1;
    for (; T--;) {
        cin >> n;
        cnt = 0;
        sn = sqrt(n);
        for (long long i = 1; i <= n; i++)
            a[++cnt] = (i = n / (n / i)), s[cnt] = i - 1;
        int cntp = 0;
        for (int i = 2; i <= sn; i++)
            if (s[i]^s[i - 1]) { //异或 
                inv[i] = 1.0 / i;
                for (long long j = cnt, lim = 1ll * i * i; a[j] >= lim; j--) //把int类型的变量转化为long long，然后再赋值给long long类型的变量
                    s[j] = (s[j] - (s[id((long long)(a[j] * inv[i] + 1e-9))] - cntp));
                cntp ++;
            }
        cout<<s[cnt];
    }
}
