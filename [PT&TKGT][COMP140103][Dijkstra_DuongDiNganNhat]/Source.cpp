#include<iostream>
#include<fstream>
#include<algorithm>
#define Max 2147483640
#define MAX 100
using namespace std;


struct dothi
{
    int canh[MAX][MAX], n; // ma trận chứa thông số cạnh và số đỉnh
    int vet[MAX]; // lưu trữ đỉnh cha của đỉnh i
    void nhapfile(string tenfile) // Nhập các thông số từ file
    {
        ifstream in("tenfile");
        cout << "Moi ban nhap so dinh :\n";
        in >> n;
        cout << "Moi ban nhap ma tran canh: \n";
        for (int i = 0; i < n; ++n)
        {
           
            for (int j = 0; j < n; ++j)
            {
                in >> canh[i][j];
            }
        }
        
        in.close();
    }
    void nhap()// Nhập các thông số từ input
    {
        cout << "Moi ban nhap so dinh :\n";
        cin >> n;
        cout << "Moi ban nhap ma tran canh: \n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> canh[i][j];
            }
        }
    }
    
    
    void xuatdd(int N, int S)// Dùng đệ quy để xuất đường đi từ S đến N
    {
        if (vet[S] == N)
        {
            cout << N << " => " << S;
            return;
        }
        xuatdd(N, vet[S]);
        cout << " => " << S;
    }
   
    
    
    /************************************************************************
     * Kỹ thuật xóa phần tử khi mảng ko cần tính thứ tự
      Giả sử mảng A = {1,5,6,2,4} với trọng số quản lý mảng nA = 5
      ta muốn xóa số 6 khỏi A, ta chỉ cần swap 6 và phần tử cuối mảng (4)
      A = {1,5,4,2,6}
      sau đó ta giảm trọng số quản lý mảng --nA = 4
      thì A lúc đó sẽ chỉ còn A = {1,5,4,2}
      Vấn đề là ta cần tìm được vị trí của số 6 để dễ dàng swap. Do đó ta cần
      cài đặt một mảng định vị vị trí của phần tử x. Đó là lý do xuất hiện của
      mảng Vt, với giá trị phần tử Vt[i] chính là vị trí của i trong A;
      mảng Vt trong ví dụ trên sẽ như sau:
      A = {1,5,6,2,4}
      Vt= {-1,0,3,-1,4,1,2}
      Vt[0]  và Vt[3] = -1 vì 0 và 3 không có trong mảng A
    **************************************************************************/
    void xoax(int L[], int& nL, int Vt[], int x)// sử dụng kỹ thuật xóa phần tử mảng không thứ tự
    {
        --nL;
        Vt[L[nL]] = Vt[x]; // sau khi swap thì phần tử cuối sẽ thế chỗ cho vị trí của phần tử x
        swap(L[Vt[x]], L[nL]);
    }
    void Dijkstra(int N, int S)
    {
        while (N < 0 || N >= n || S < 0 || S >= n)
        {
            cout << "thông số không hợp lệ:\nMoi nhap lai:\n";
            cout << "Moi nhap dinh bat dau : ";
            cin >> N;
            cout << "Moi nhap dinh ket thuc: ";
            cin >> S;
        }
        for (int i = 0; i < n; ++i)// thiết lập tất cả các vết về -1
        {
            vet[i] = -1;
        }
        int L[MAX], nL = n; // mảng các đỉnh chưa được chọn
        int Vt[MAX];// Mảng chứa vị trí các đỉnh trong tập L
        // sở dĩ phải dùng 2 mảng dài dòng vì nó sẽ rút ngắn được các phương thức phức tạp khác

        int W[MAX]; // mảng chứa phần tử W[i] là khoảng cách từ đỉnh i đến N
        for (int i = 0; i < n; ++i)
        {
            L[i] = Vt[i] = i;// lưu trữ đỉnh và vị trí đỉnh // ban đầu sẽ giống nhau vì chưa có gì xáo trộn
            W[i] = Max; // cho tất cả khởi đầu bằng Max
        }

        W[N] = 0; // khoảng cách từ N đến N tất nhiên = 0
        int Min = Max;// đặt trước giá trị Min bằng với số lớn nhất
        int x = N; // đỉnh gần với N nhất trong lượt chọn thứ k
        vet[N] = N;
        xoax(L, nL, Vt, x);
        for (int k = 0; k < n - 1; ++k)
        {
            if (x == S)
                break;

            int vtM = -1;// biến tạm lưu trữ đỉnh có khoảng cách ngắn nhất thứ k của N
            for (int i = 0; i < nL; ++i)
            {
                if (canh[x][L[i]] != 0 && W[L[i]] > W[x] + canh[x][L[i]])
                {
                    W[L[i]] = W[x] + canh[x][L[i]];
                    vet[L[i]] = x;
                }
                if (Min > W[L[i]])
                {
                    Min = W[L[i]];
                    vtM = L[i];
                }
            }

            Min = Max; // phục hồi giá trị cho Min vào vòng lặp sau
            x = vtM;// cập nhật lại đỉnh x 
            xoax(L, nL, Vt, x);// xóa đỉnh x khỏi L
        }
        if (x == S)
            xuatdd(N, S);
        else
            cout << "Không có đường đi từ đỉnh " << N << " đến đỉnh " << S << " !";
    }
    
   
};
/**********************************************************************************************************
* chương trình tìm đường đi ngắn nhất trong đồ thị theo thuật toán Dijkstra
* Bạn cần nhập số đỉnh của đồ thị và ma trận trọng số cạnh và sau đó là hai đỉnh cần tìm đường đi ngắn nhất
* Lưu ý: Đỉnh của đồ thị bắt đầu từ 0
***********************************************************************************************************/
int main()
{
 /**********************************************************************************************************
ví dụ về input:
11
0 10 6 14 22 21 0 0 0 0 0
10 0 0 0 0 0 7 0 0 0 0
6 0 0 3 0 0 9 0 0 0 0
14 0 3 0 0 0 0 4 3 0 0
22 0 0 0 0 0 0 0 17 0 0
21 0 0 0 0 0 0 0 0 0 0
0 7 9 0 0 0 0 5 0 0 0
0 0 0 4 0 0 5 0 9 7 0
0 0 0 3 17 0 0 9 0 6 8
0 0 0 0 0 0 0 7 6 0 0
0 0 0 0 0 0 0 0 8 0 0
1 7
với 11 là số đỉnh
bên dưới là ma trận trọng số cạnh
1 7 là 2 đỉnh cần tìm đường đi ngắn nhất
***********************************************************************************************************/
    while (true)
    {
        dothi a;
        a.nhap();
        cout << "Moi ban nhap hai dinh can tim duong di ngan nhat cua do thi:\n";
        int N, S;
        cin >> N >> S;
        a.Dijkstra(N, S);
        cout << "\nMoi ban nhap lua chon :\n1.tiep tuc\n0.thoat\n";
        cin >> N;
        if (N == 0)
            break;
        system("cls");
    }
    return 0;
}