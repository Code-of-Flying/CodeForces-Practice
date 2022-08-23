## 主要是前4题 
==Talk is Cheap, Show Me The Code==
 
## A
> *考察点： 贪心（横竖），构造（如何计算），数学（最大值和最小值如何取）*
```cpp
#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    int n,m;
    while(t--) {
        cin >> n >> m;
        int n1 = min(n,m);
        int m1 = max(n,m);
        if(n==1 && m==1){ // 记得特判一下哦
            cout << 0 << endl;
            continue;
        }
        // 最小拼两次，同时去除重合的两个点。
        cout <<(m1 + 2*n1 -2) << endl;
    }
    return 0;
}
```


## B
>  *考察点： 其实跟第一题差不多，看你如何细分 k - 1 ， 同时如何特判 不存在的情况*
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long // 1e18 
int t;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    int n, k, b, s;
    while (t--)
    {
        cin >> n >> k >> b >> s;
        ////int temp = s / k - (n - 1);
        if (b * k > s) // 举不出反例，再加上b*k <= s ，那就大胆写吧
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            vector<int> a(n + 1, 0);
            a[0] = b * k;
            s -= b * k;
            for (int i = 0; i < n; i++)
            {
                if (s < k - 1)
                {
                    a[i] += s; // s 已经很小了，就不要强迫他了
                    s = 0;
                    break;
                }
                else
                {
                    a[i] += k - 1; // s还可以，那就继续以k-1补位
                    s -= (k - 1);
                }
            }
            if (s) // s太大了
            {
                cout << -1 << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << a[i] << " \n"[i == n - 1];
                }
            }
        }
    }
}
```

## C
>  *考察点： 归纳，累加，局部贡献如何求解*
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
map<int, int> mp;
void slove(vector<int> T)
{

    int ans = 0;
    int t;
    mp.clear();
    mp[0] = 0;
    // cout << T.size() << endl;
    for (int i = 1; i <= T.size(); i++)
    {
        if (i == 1)
        {
            t = T[1];
            ans++;
            mp[i] = mp[i - 1] + ans; //我这里主要是方便观察出 i 之前所有的awareneass值
        }
        else
        {
            if (T[i] == t)
            {
                ans++; // +1 很小了因为跟前面合在一起了 qwq 
                mp[i] = mp[i - 1] + ans; 
            }
            else
            {
                t = T[i];
                ans += i; // 不一样就可以加上自己了
                mp[i] = mp[i - 1] + ans;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> a;
    int temp;
    a.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    int index, x;
    slove(a);
    //cout << mp[n] << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> index >> x;

        if (a[index] == x)
        {
            cout << mp[n] << endl;
        }
        else
        {
            if (a[index - 1] == x && a[index - 1] != a[index]) // 左右比较，进行贡献计算
                mp[n] -= (n - index + 1) * (index - 1);
            if (a[index - 1] != x && a[index - 1] == a[index])
                mp[n] += (n - index + 1) * (index - 1);
            if (a[index + 1] == x && a[index + 1] != a[index])
                mp[n] -= (n - index) * index;
            if (a[index + 1] != x && a[index + 1] == a[index])
                mp[n] += (n - index) * index; // mp[n] 
            cout << mp[n] << endl;
        }
        a[index] = x; // 改变a
    }
}
```

## D
> * 考察点：*贪心（总是找0补充位），位运算（& ），枚举（枚举i位置，反向推演j位置是否合理）*
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define up(x, y) x | y
int n, q;
const int maxn = 1e5 + 10;

vector<array<int, 2>> Arr[maxn];

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    int i, j, x;

    for (int k = 1; k <= q; k++)
    {
        cin >> i >> j >> x;
        // a[i] | a[j] = x
        Arr[i].push_back({j, x});
        Arr[j].push_back({i, x});
    }
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        temp[i] = (1 << 31) - 1ll; // 凑30个1,因为 (x < 2 ^ 30)
        for (auto it : Arr[i])
        {
            temp[i] &= (int)it[1]; // w 的 1 都填充好，与 i 相关都 & 一遍
        }
        if (Arr[i].size() == 0) // 
        {
            temp[i] = 0; // greedy 直接取出0 sign
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            if (temp[i] >> j & 1)
            {
                bool flag = false;

                for (auto it : Arr[i])
                {
                    if (!(temp[it[0]] >> j & 1) || it[0] == i) // 或者是 前已经是 0 ，或者是本身 i和i，那我都可以直接赋值 
                    {
                        flag = true;                            // 因为 sign对此处已经置0。
                    }
                }
                if (!flag)
                {
                    temp[i] -= (1 << j); // 
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << temp[i] << " \n"[i == n];
}
```


