#include<iostream>
#include<cmath>
using namespace std;
/*****************************************************************************************************
* Hàm xuất đa thức với mảng a chứa các hệ số của đa thức và n là bậc của đa thức.
******************************************************************************************************/
void xuatDT(int a[], int n)
{
    bool f = false;
    for (int i = 0; i <= n; ++i)
    {
        if (a[i] != 0)
        {
            if (abs(a[i]) == 1)
            {
                if (a[i] == 1)
                {
                    if (f)
                        cout << " + ";
                    if (i == n)
                        cout << a[i];
                }
                else
                {
                    if (i == n)
                        cout << " - "<< -a[i];
                    else cout << " - ";
                }
            }
            else
            {
                if (a[i] > 0)
                {
                    if (f)
                        cout << " + ";
                    cout << a[i];
                }
                else
                    cout << " - " << -a[i];
            }

            if (i < n - 1)
                cout << "x^" << n - i;
            if (i == n - 1)
                cout << 'x';

            f = true;
        }
    }
}
/*******************************************************************************************
Hàm chia đa thức theo luật Horner với:
Mảng a sẽ chứa hệ số hàm f(x)
Mảng b sẽ chứa các hệ số của đa thức g(x).
f(x) = g(x) * (x-anpha) + r;
với n là bậc của đa thức f(x)
*******************************************************************************************/
void chiaHorner(int a[], int b[], int n, int anpha)
{
    b[0] = a[0];
    for (int i = 1; i <= n; ++i)
    {
        b[i] = b[i - 1] * anpha + a[i];
    }
}

/****************************************************************************************
 Chương trình chia một đa thức bậc n cho một đa thức bậc nhất (x-anpha) theo luật Horner
 Đầu tiên ta nhập bậc của đa thức.
 Sau đó nhập đầy đủ hệ số của đa thức ban đầu, nếu hệ số đó bị khuyết thì ta cho bằng 0
 ví du:
 2x^4 + 3x^2 - 1
 ta nhập :
 4 (bậc đa thức)
 2 0 3 0 -1 (hệ số)
 Cuối cùng ta nhập số anpha cần chia
 ví dụ ta muốn chia cho (x-3)
 ta nhập 3.
*****************************************************************************************/
int main()
{
    while (true)
    {
        int n, a[100], b[100], anpha;
        cout << "Moi nhap bac cao nhat cua da thuc :\n";
        cin >> n;
        cout << "Moi nhap cac he so :\n";
        for (int i = 0; i <= n; ++i)
        {
            cin >> a[i];
        }
        cout << "Moi nhap so anpha can chia :\n";
        cin >> anpha;
        chiaHorner(a, b, n, anpha);
        cout << "f(x) = ";
        xuatDT(a, n);
        cout << "\ng(x) = ";
        xuatDT(b, n - 1);
        cout << "\nf(x) = (";
        xuatDT(b, n - 1);
        cout << ")(x ";
        if (anpha > 0)
        {
            cout << "- " << anpha << ")";
        }
        else if (anpha < 0)
            cout << "+ " << -anpha << ")";
        else cout << ")";
        if (b[n] != 0)
        {
            if (b[n] > 0)
                cout << " + " << b[n];
            else cout << " - " << -b[n];
        }
        cout << "\nBan co muon tiep tuc : \n 1. tiep tuc\n 0. thoat\n";
        cin >> n;
        if (n == 0)
            break;

    }
    return 0;
}