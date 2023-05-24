#include<iostream>
using namespace std;
/*******************************************************************************************************************
* Chương trình tìm đường đi ngắn nhất bằng giải thuật Floy.
* Giải thuật này có độ phức tạp O(n^3) tuy nhiên lại rất tiện lợi trong các bài toán cần tìm đường đi ngắn nhất từ
* mọi đỉnh của đồ thị đến tất các các đỉnh còn lại
********************************************************************************************************************/
int m[100][100], n, d[100][100], x, y;
void dq(int i, int j) // Hàm đệ quy tiện lợi để xuất đường đi
{
    if (d[i][j] == 0)
        return;

    dq(i, d[i][j]);
    cout << d[i][j] << "->";
    dq(d[i][j], j);
}
int main()
{
    /******************************************************************
    * Ví dụ input : 
    * nếu ta nhập ma trận có 6 đỉnh
    * cần tìm đường đi ngắn nhất từ đỉnh 0 đến 5
    * Ta nhập như sau
    *   6 0 5              
        0 1 0 0 0 0     

        0 0 5 2 0 7

        0 0 0 0 0 1

        2 0 1 0 4 0

        0 0 0 3 0 0

        0 0 0 0 1 0
        ma trận bên dưới là ma trận trọng số cạnh
    *******************************************************************/
    cout << "Moi nhap so dinh cua do thi: \n";
    cin >> n;
    cout << "Moi nhap hai dinh can tim duong di ngan nhat: \n";
    cin >> x >> y;
    cout << "Moi nhap ma tran trong so canh: \n";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> m[i][j];
            if (m[i][j] == 0 && i != j)
                m[i][j] = 1000000;
        }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (m[j][k] > m[j][i] + m[i][k])
                {
                    m[j][k] = m[k][j] = m[j][i] + m[i][k];
                    d[j][k] = d[k][j] = i;
                }
            }
        }
    }
    cout << x << "->";
    dq(x, y);
    cout << y << '\n';

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << d[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}