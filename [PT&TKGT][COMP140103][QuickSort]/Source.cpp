#include<iostream>
using namespace std;
/************************************************************************************
* Thuật toán Quick sort
* Sử dụng kỹ thuật đệ quy kết hợp chia để trị nhằm sắp xếp mảng.
*************************************************************************************/
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int x = a[(l + r) / 2]; // phần tử mốc được chọn ở giữa mảng
    int i = l, j = r;
    while (i < j)  // kỹ thuật dùng 2 con trỏ đưa các phần tử nhỏ hoặc lớn hơn phần tử chốt về 2 bên mảng
    {
        while (a[i] < x)  // dừng lại ở a[i] >= phần tử chốt
            ++i;                
        while (a[j] > x) // dừng lại ở a[j] <= phần tử chốt
            --j;
        if (i <= j)
        {
            swap(a[i], a[j]); // hoán đổi 2 phần tử cho nhau về 2 phía của mảng
            ++i;
            --j;
        }
    }
    // chia mảng thành 2 phần nhỏ hơn để tiếp tục sắp xếp
    quickSort(a, l, j);
    quickSort(a, i, r);
}
int main()
{
    while (true)
    {
        int n;
        cout << "Moi nhap so luong phan tu cua mang:\n";
        cin >> n;
        cout << "Moi nhap phan tu mang: \n";
        int a[1000];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        quickSort(a, 0, n - 1);
        cout << "Mang sau khi sap xep:\n";
        for (int i = 0; i < n; ++i)
            cout << a[i] << ' ';
        cout << "\nMoi nhap lua chon:\n1.tiep tuc\n0.thoat\n";
        cin >> n;
        if (n == 0)
            break;
    }
    return 0;
}