#include<iostream>
using namespace std;
int n, dem, Cot[100], Trai[200], Phai[200];
void DemHau(int); 
int main() {
    cout << "Moi nhap so luong quan Hau: ";
    cin >> n;
    DemHau(1);
    cout << "\nSo cach xep Hau la : " << dem << '\n';
    return 0;
}
void DemHau(int x) 
{
    if (x > n)
    {
        ++dem;
    }
    else
    {
        for (int y = 1; y <= n; ++y) 
        {
            if ((!Trai[x + y]) && (!Phai[x - y + n]) && (!Cot[y]))
            {
                Trai[x + y] = 1; 
                Phai[x - y + n] = 1;
                Cot[y] = 1;            
                DemHau(x + 1); 
                                
                Trai[x + y] = 0;
                Phai[x - y + n] = 0;  
                Cot[y] = 0;
            }
        }
    }
}
