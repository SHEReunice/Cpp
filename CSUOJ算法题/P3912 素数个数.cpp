#include <bits/stdc++.h>
#define MAX 1000002
using namespace std;

int sn, cnt;
long long a[MAX], s[MAX], n;
inline int id(long long a) {  //������������Ч 
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
            if (s[i]^s[i - 1]) { //��� 
                inv[i] = 1.0 / i;
                for (long long j = cnt, lim = 1ll * i * i; a[j] >= lim; j--) //��int���͵ı���ת��Ϊlong long��Ȼ���ٸ�ֵ��long long���͵ı���
                    s[j] = (s[j] - (s[id((long long)(a[j] * inv[i] + 1e-9))] - cntp));
                cntp ++;
            }
        cout<<s[cnt];
    }
}
