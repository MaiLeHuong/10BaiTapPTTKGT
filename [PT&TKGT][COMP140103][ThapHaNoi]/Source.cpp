#include<iostream>
using namespace std;
/******************************************************************************************
* Câu đố tháp Hà Nội là một câu đố vui và được giải bằng giải thuật đệ quy.
* Tuy nhiên vì độ phức tạp của bài toán rất lớn O(2^n) nên bài toán chỉ mang tính đố vui và
* ít có giá trị thực tiễn.
* Thuật giải của bài toán sẽ như sau :
* Khi cột A có n đĩa ta sẽ đưa tuần tự từ A -> C rồi A->B, nó giống như việc mượn C làm trung
* gian để di chuyển n-1 đĩa đến B, sau đó ta chuyển đĩa to nhất sang cột C.
* Từ đây bài toán lại trở về vạch xuất phát nhưng lần này B và A hoán đổi vai trò cho nhau.
* Có nghĩa là ta sẽ cố gắng chuyển n-2 đĩa sang cột A và đĩa to thứ 2 lại được chuyển sang C
* Cho nên đây là một bài toán rất phù hợp giải thuật đệ quy
********************************************************************************************/
void DeQuy(int n, char a, char b, char c) // Hàm liệt kê tất các các bước di chuyển đĩa từ các cột qua lại
{
	if (n == 1) // khi đã chuyển được n-1 đĩa sang cột B (hoặc A)
	{
		cout << "\n" << a << " => " << c << '\n';
		return;
	}
	DeQuy(n - 1, a, c, b); // hoán đổi vai trò c,b, mỗi bên đều là trung gian của nhau
	DeQuy(1, a, b, c); // xuất cách di chuyển còn thiếu
	DeQuy(n - 1, b, a, c); // hoán đổi vai trò a,b;
}
int main() {
	
	int n;
	cout << "Moi Nhap n: ";
	cin >> n;
	DeQuy(n, 'A', 'B', 'C');
}