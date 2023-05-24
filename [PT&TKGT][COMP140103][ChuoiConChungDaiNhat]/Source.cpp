#include<iostream>
using namespace std;
/**************************************************************************************************************
* Bài toán chuỗi con chung dài nhất (tạm gọi chuỗi A và B) sử dụng kỹ thuật quy hoạch động
* Ta sẽ dùng một mảng hai chiều (F) để đánh dấu chuỗi con chung dài nhất của các chuỗi con từ 2 chuỗi ban đầu
* với F[i][j] là chiều dài chuỗi con chung lớn nhất của chuỗi con A tính từ phần tử số 0 cho đến phần tử thứ i
* và chuỗi con B tính từ phần tử thứ 0 cho đến phần tử thứ j.
***************************************************************************************************************/

int F[1000][1000];
int main()
{
	string A, B;
	cout << "Moi nhap chuoi thu nhat:\n";
	cin >> A;
	cout << "Moi nhap chuoi thu nhat:\n";
	cin >> B;
	/*****************************************************************************************
	* Ta dùng Mảng F dời lên 1 đơn vị để tránh các tình huống F[i-1][] hay F[][j-1] bị dính
	* trọng số âm khi i hoặc j = 0;
	* ví dụ nếu bình thường là F[i][j] thì bây giờ sẽ là F[i+1][j+1]
	* tất nhiên ta có thể setup trước cho việc i hoặc j = 0, tuy nhiên nó sẽ mất tính đồng bộ
	******************************************************************************************/
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			if (A[i] == B[j])
				F[i + 1][j + 1] = F[i][j] + 1;
			else
			{
				if (F[i][j + 1] > F[i + 1][j])
					F[i + 1][j + 1] = F[i][j + 1];
				else F[i + 1][j + 1] = F[i + 1][j];
			}
		}
	}
	cout << "Do dai chuoi con chung dai nhat la: \n" << F[A.size()][B.size()];
	cout << "\nChuoi con chung dai nhat la: \n";
	string C = "";
	int i = A.size() - 1, j = B.size() - 1;
	for (int k = 0; k < F[A.size()][B.size()]; ++k) //Hàm truy vết chuỗi con dài nhất
	{
		while (A[i] != B[j])
		{
			if (F[i + 1][j + 1] == F[i][j + 1])
				--i;
			else --j;
		}
		C = A[i] + C;
		--i;
		--j;
	}
	cout << C;

	return 0;
}