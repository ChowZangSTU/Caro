#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stack>
#define MAX 100
using namespace std;

void textcolor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

struct ToaDo
{
	int x, y;
};
typedef struct ToaDo toado;

char KiemTraHangNgang(char a[MAX][MAX], int n, int vitridong, int vitricot) {
	int dem = 1; //Tính luôn quân vừa đánh

	//Xét bên trái trước (Ngang trái)
	for (int j = vitricot - 1; j >= 0; --j) {
		if (a[vitridong][j] == a[vitridong][vitricot]) {
			dem++;
			if (dem == 5) {
				return a[vitridong][vitricot];
			}
		}
		else //Không còn tính liên tục => dừng quá trình lặp 
		{
			break;
		}
	}

	//Xét qua bên phải (ngang phải)
	for (int j = vitricot + 1; j < n; ++j) {
		if (a[vitridong][j] == a[vitridong][vitricot]) {
			dem++;
		}
		if (dem == 5) {
			return a[vitridong][vitricot];
		}
		else {
			break;
		}
	}

	return '.'; // Chưa thắng
}

char KiemTraHangDoc(char a[MAX][MAX], int n, int vitridong, int vitricot) {
	int dem = 1;
	for (int j = vitridong - 1; j >= 0; --j) {
		if (a[j][vitricot] == a[vitridong][vitricot]) {
			dem++;
			if (dem == 5) {
				return a[vitridong][vitricot];
			}
		}
		else {
			break;
		}
	}

	for (int j = vitridong + 1; j < n; ++j) {
		if (a[j][vitricot] == a[vitridong][vitricot]) {
			dem++;
			if (dem == 5) {
				return a[vitridong][vitricot];
			}
		}
		else {
			break;
		}
	}

	return '.';
}

char KiemTraHangCheoChinh(char a[MAX][MAX], int n, int m, int x, int y) {
	int dem = 1;

	//Kiểm tra chéo chính trên 
	int i = x - 1;
	int j = y - 1;
	while (true) {
		if (i < 0 || j < 0) {
			break;
		}

		if (a[i][j] == a[x][y]) {
			dem++;
			if (dem == 5) {
				return a[x][y];
			}
		}
		else {
			break;
		}

		i--;
		j--;
	}

	i = x + 1;
	j = y + 1;
	while (true) {
		if (i > n || j > m) {
			break;
		}

		if (a[j][i] == a[x][y]) {
			dem++;
			if (dem == 5) {
				return a[x][y];
			}
		}
		else {
			break;
		}
		i++;
		j++;
	}

	return '.';
}

char KiemTraCheoPhu(char a[MAX][MAX], int n, int m, int x, int y) {
	int dem = 1;
	int i = x - 1;
	int j = y + 1;

	while (true) {
		if (i < 0 || j == m) {
			break;
		}

		if (a[i][j] == a[x][y]) {
			dem++;
			if (dem == 5) {
				return a[x][y];
			}
		}
		else {
			break;
		}
		i--;
		j++;
	}

	i = x + 1;
	j = y - 1;
	while (true) {
		if (i == n || j < 0) {
			break;
		}

		if (a[i][j] == a[x][y]) {
			dem++;
			if (dem == 5) {
				return a[x][y];
			}
		}
		else {
			break;
		}
		i++;
		j--;
	}

	return '.';
}

void BanCo(int n, int m, int crdong, int cdcot, char c[][MAX]) {
	// Chú ý những ký tự sau âây:
	// i = 218 => i- : góc trên cùng bên trái
	// i = 191 => -i : góc trên cùng bên phải
	// i = 217 => _I : góc dưới cùng bên phải
	// i = 192 => |_ : góc duới cùng bên trái
	// i = 196 => _
	// i = 179 => |
	// i = 194 => T
	// i = 193 => T ngược
	// i = 195 => |-
	// i = 180 => -|
	// i = 197 => + lớn

	int kc = log10(crdong) + 1;
	cout << setw(crdong / 2 + 4);
	//cout << "\t" << setw(cddong / 2 + 1);
	for (int i = 0; i < m - 1 ; ++i) {
		cout << i;
		cout << setw(crdong + 1);
	}
	cout << m - 1 << endl;


	string a, b;
	for (int i = 0; i < crdong; ++i) {
		a += (char)196;
	}

	
	//for (int j = 0; j < socot; ++j) {
	//	b = b + (char)179 + "\n" + b;
	//}

	b = (char)179;

	//Hàng trên
	cout << setw(3) << (char)218;
	for (int i = 1; i < m; ++i) {
		cout << a << (char)194;

	}
	cout << a << (char)191;

	//Hàng giữa
	for (int i = 1; i < n; ++i) {
		int size = 3 - log10(i + 1);
		//Phần cột
		for (int cd = 0; cd < cdcot; ++cd) {
			cout << "\n";
			// Phần số
			if (cd == cdcot / 2) {
				cout << i << setw(size);
			}
			else {
				cout << setw(3);
			}
			for (int j = 0; j < m; ++j) {
				cout << b;
				for (int kc = 0; kc < crdong; ++kc) {
					if (kc != crdong / 2) {
						cout << " ";
					}
					else {
						if (c[i][j] == 'x' || c[i][j] == 'o') {
							c[i][j] == 'x' ? textcolor(13 + 32) : textcolor(14 + 32);
							cout << c[i][j];
							textcolor(7);
						}
						else {
							cout << " ";
						}
					}
				}
				
			}
			cout << b;
		}


		if (i == n - 1) {
			break;
		}

		//Phần dòng
		cout << "\n" << setw(3) << (char)195;
		for (int j = 1; j < m; ++j) {
			cout << a << (char)197;
		}
		cout << a << (char)180;
	}

	//Hàng dưới
	cout << "\n" << setw(3) << (char)192;
	for (int i = 1; i < m; ++i) {
		cout << a << (char)193;
	}
	cout << a << (char)217;
}

//=============== Đánh bằng tọa độ ==================
// ==================== Cách 1:
void ToaDoCanDanh(int &luotdi, char a[][MAX], int n, int m, int crdong, int cdcot) {
	int x, y;
	char quanco;
	quanco = luotdi == 0 ? 'x' : 'o';
	cout << "\nLuot di hien tai cua quan co: ";
	if (quanco == 'x') {
		textcolor(13);
		cout << quanco << endl;
		textcolor(7);
	}
	else {
		textcolor(14);
		cout << quanco << endl;
		textcolor(7);
	}
	cout << "\nNhap vao toa do [dong, cot] can danh: ";
	cin >> x >> y;


	if (a[x][y] != 'x' && a[x][y] != 'o') {
		a[x][y] = quanco;
	}
	else {
		cout << "\nDa co nguoi di nhap lai!";
		Sleep(500);
	}
	luotdi = luotdi == 0 ? 1 : 0;
}


void NhapToaDo_XoaManHinh(char a[][MAX], int n, int m, int crdong, int cdcot) {
	int luotdi = 0;
	while (true) {
		BanCo(n, m, crdong, cdcot, a);
		ToaDoCanDanh(luotdi, a, n, m, crdong, cdcot);
		system("cls");
	}
}

// =====================Cách 2: 
void ToaDoCanDanh_GotoXY(int &luotdi, char a[][MAX], int n, int m, int crdong, int cdcot) {
	//Nhập vào vị trí quân cờ
	int vitri_x = (log10(n + 1)) + 1, vitri_y = 3; // Vị trí ban đầu của góc trên cùng bên trái của bàn cờ
	int toado_dong = -1, toado_cot = -1; //Tạo độ vị trí người dùng muốn đánh cờ
	char quanco;
	quanco = luotdi == 0 ? 'x' : 'o';
	cout << "\nLuot di hien tai cua quan co: ";
	quanco == 'x' ? textcolor(13) : textcolor(14);
	cout << quanco;
	textcolor(7);

	do {
		cout << "\nNhap vao to do [dong, cot] can danh: ";
		cin >> toado_dong >> toado_cot;

		if (toado_dong < 0 || toado_dong >= n) {
			cout << "\nToa do dong khong hop le";
		}
		if (toado_cot < 0 || toado_cot >= m) {
			cout << "\nToa do cot khong hop le";
		}
	} while (toado_dong < 0 || toado_dong >= n || toado_cot < 0 || toado_cot >= m);
	a[toado_dong][toado_cot] = quanco;

	//Hiện quân cờ trên bàn
	//Công thức để nhảy đến 1 ô có vị trí tọa độ dòng, cột bất kỳ
	gotoxy(vitri_x + crdong / 2 + 1 + toado_dong * (crdong + 1), vitri_y + cdcot / 2 + 1 + toado_cot * (cdcot + 1));
	quanco == 'x' ? textcolor(13) : textcolor(14);
	cout << quanco;
	textcolor(7);
	luotdi = luotdi == 0 ? 1 : 0;
}

void NhapToaDo_GotoXY(char a[][MAX], int n, int m, int crdong, int cdcot) {
	int luotdi = 0;
	BanCo(n, m, crdong, cdcot, a);

	while (true) {
		ToaDoCanDanh_GotoXY(luotdi, a, n, m, crdong, cdcot);
	}
}

void BanPhim(int i = 1) // ============== Bắt key từ bàn phím  - sử dụng getch() s4 nhạy hơn: 
{
	if (i == 0) {
		//Cách 1:
		while (true) {
			if (GetAsyncKeyState(VK_RIGHT)) {
				cout << "\nMui ten phai";
			}
			else if (GetAsyncKeyState(VK_LEFT)) {
				cout << "\nMui ten trai";
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				cout << "\nMui ten xuong";
			}
			else if (GetAsyncKeyState(VK_UP)) {
				cout << "\nMui ten len";
			}
			else if (GetAsyncKeyState(VK_SPACE)) {
				cout << "\nPhim Enter";
			}
			else if (GetAsyncKeyState(VK_RETURN)) {
				cout << "\nEnter";
				break;
			}
			Sleep(200);
		}
	}
	else {
		//Cách 2:
		//Đoạn code xử lý nhận diện tổng quát các phím trên bàn phím
		while (true) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 77) {
					cout << "\nBen phai";
				}
				else if (c == 75) {
					cout << "\nBen trai";
				}
				else if (c == 72) {
					cout << "\nLen tren";
				}
				else if (c == 80) {
					cout << "\nXuong duoi";
				}
				else if (c == 32) {
					cout << "\nSpace";
				}
				else if (c == 13) {
					break; // Phím enter
				}
				Sleep(200);
			}
			else {
				if (c == 'd' || c == 'D') {
					cout << "\nBen phai";
				}
				else if (c == 'a' || c == 'A') {
					cout << "\nBen trai";
				}
				else if (c == 'w' || c == 'W') {
					cout << "\nLen tren";
				}
				else if (c == 's' || c == 'S') {
					cout << "\nXuong duoi";
				}
				else if (c == 32) {
					cout << "\nSpace";
				}
				else if (c == 13) {
					break; // Phím enter
				}
				Sleep(200);
			}
		}
	}
}

//Công thức để nhảy đến 1 ô có vị trí tọa độ dòng, cột bất kỳ
//gotoxy(x + crdong / 2 + 1 + toado_y * (crdong + 1), y + cdcot / 2 + 1 + toado_x * (cdcot + 1));
void XuLyGameTheoHuongDungPhim(int n, int m, int crdong, int cdcot, char a[][MAX], stack<toado> &stack_undo, stack<toado> &stack_redo, int time) {
	BanCo(n, m, crdong, cdcot, a);
	int toado_x = 0, toado_y = 0; //Đầu tiên con trỏ chuột sẽ nằmm ở ô này (0,0)
	int vitri_x =(log10(n + 1)) + 1, vitri_y = 1; // Vị trí ban đầu của góc trên cùng bên trái của bàn cờ
	
	int temp_x = -1 , temp_y = -1; //Vị trí quân cờ trước đó 

	char quanco, luotdi = 0;
	toado td;
	bool Play = true;

	int dem_Sleep = 0;
	quanco = luotdi == 0 ? 'x' : 'o';
	gotoxy(1, (cdcot + 1) * n + 2);
	cout << "Luot di hien tai cua quan co: ";
	quanco = luotdi == true ? 'x' : 'o';
	luotdi == true ? textcolor(14) : textcolor(12);
	cout << quanco;
	textcolor(7);	

	gotoxy(vitri_x + crdong / 2 + 1 + toado_y * (crdong + 1), vitri_y + cdcot / 2 + 2 + toado_x * (cdcot + 1));
	
	int demsoluongquanco = 0;
	while (true) //vòng lặp vô tận tạo diễn hoạt cho game
	{
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 77) { //phải
					if (toado_y < m - 1) {
						toado_y++;
					}
				}
				else if (c == 75) { //trái
					if (toado_y > 0) {
						toado_y--;

					}
				}
				else if (c == 80) { //lên
					if (toado_x < n - 1) {
						toado_x++;
					}
				}
				else if (c == 72) { //xuống
					if (toado_x > 0) {
						toado_x--;
					}
				}
			}
			else if (c == 32 || c == 13) { //Space và Enter
				time = 30;
				quanco = luotdi == true ? 'x' : 'o';
				luotdi == true ? textcolor(14) : textcolor(12);
				cout << quanco;
				textcolor(7);
				luotdi = luotdi == true ? 0 : 1;

				a[toado_x][toado_y] = quanco;

				//Lưu trữ quân cờ
				td.x = toado_x;
				td.y = toado_y;
				stack_undo.push(td);

				demsoluongquanco++;

				if (KiemTraHangNgang(a, n, toado_x, toado_y) != '.' || KiemTraHangDoc(a, m, toado_x, toado_y) != '.' || KiemTraHangCheoChinh(a, n, m, toado_x, toado_y) != '.' || KiemTraCheoPhu(a, n, m, toado_x, toado_y) != '.')
				{
					gotoxy(1, (cdcot + 1) * n + 4);
					cout << "Da chien thang";
					break;
				}

				if (demsoluongquanco == n * m) {
					cout << "\nHoa";
					break;
				}

				gotoxy(1, (cdcot + 1) * n + 2);
				cout << "Luot di hien tai cua quan co: ";
				quanco = luotdi == true ? 'x' : 'o';
				luotdi == true ? textcolor(14) : textcolor(12);
				cout << quanco;
				textcolor(7);
			}
			else if (c == 'p' || c == 'P') {
				Play = !Play;
				if (Play == false) {

					//Giam nó vào trong 1 luồng vòng lặp vô tận con khác nằm bên trong vòng lặp vô tận diễn hoạt game
					while (true) {
						if (_kbhit()) {
							char c1 = _getch();

							if (c1 == -32) {
								c1 = _getch();
							}
							else {
								if (c1 == 'p' || c1 == 'P') {
									Play = !Play;
									break;
								}
							}
						}
					}
				}
			}
			gotoxy(vitri_x + crdong / 2 + 1 + toado_y * (crdong + 1), vitri_y + cdcot / 2 + 2 + toado_x * (cdcot + 1));
		}

		if (time > 0) {
			dem_Sleep++;
			Sleep(1); 
			if (dem_Sleep == 100) {
				time--;
				gotoxy(1, (cdcot + 1) * n + 3);
				cout << "Thoi gian con lai la: ";
				textcolor(12);
				cout << time << " ";
				textcolor(7);
				dem_Sleep = 0;
				if (time == 0) {
					cout << "\nDa het thoi gian";
					break;
				}
			}
			gotoxy(vitri_x + crdong / 2 + 1 + toado_y * (crdong + 1), vitri_y + cdcot / 2 + 2 + toado_x * (cdcot + 1));
		}
	}
}

int main() {
	char luachon;
	int crdong = 3, cdcot = 1;
	int n = 10, m = 9;
	char a[MAX][MAX];
	stack<toado> stack_undo; //Ngăn xếp lưu trữ vị trí từng quân cờ đc đánh xuống bàn cờ
	stack<toado> stack_redo; //Ngăn xếp lưu trữ các quân cờ từ undo 
	int luotdi = 0;
	bool chedotinhthoigian = true; // chế độ tính thời gian cho mỗi nước đánh
	int thoigian = 30; //thời gian quy định tính theo giây (nếu con số là gt -1 thì nghĩa là tính năng này sẽ ko đc kích hoạt)

	do {
		//NhapToaDo_XoaManHinh(a, n, m, crdong, cdcot);
		//NhapToaDo_GotoXY(a, n, m, crdong, cdcot);
		//BanPhim();
		XuLyGameTheoHuongDungPhim(n, m, crdong, cdcot, a, stack_undo, stack_redo, thoigian);
		//Test(n, m, crdong, cdcot);

		cout << "\nBan muon choi lai tu dau khong? Y / N";
		luachon = _getch();
	} while (luachon == 'y' || luachon == 'Y');

	system("pause");
	return 0;
}