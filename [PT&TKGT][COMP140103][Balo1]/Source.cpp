#include<iostream>
using namespace std;
int n, w;
int a[100], f[100][101]; 
int p[100], o = 0;
int main() {
    cout << "Moi nhap so luong mon do: ";
    cin >> n;
    cout << "Moi nhap khoi luong toi da cua balo: ";
    cin >> w;
    cout << "Moi nhap khoi luong tung mon do: ";
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i) 
    {
        for (int v = 1; v <= w; ++v) 
        {
            if (v >= a[i]) 
            {
                f[i][v] = max(f[i - 1][v - a[i]] + a[i], f[i - 1][v]); 
            }
            else f[i][v] = f[i - 1][v]; 
        }
    }

    cout <<"\nKhoi luong toi uu ma balo mang duoc: " << f[n][w] << '\n';
    cout << "Cac mon do duoc chon: ";
    for (int i = n; i >= 0; --i) 
    {
        if (f[i][w] != f[i - 1][w]) 
        {
            p[o++] = a[i];
            w -= a[i];
        }
    }
    for (int i = o - 1; i >= 0; --i)cout << p[i] << " ";
    cout << '\n';
    return 0;
}