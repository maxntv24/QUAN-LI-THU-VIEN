#pragma once
#include "ctdl.h"
#include "All_function.h"
#include "string"
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
#define ESC 27
#define ENTER 13
#define PHIM1 49
#define PHIM2 50
#define PHIM3 51
#define PHIM4 52
#define PHIM5 53
#define PHIM6 54
#define PHIM7 55
#define PHIM8 56
#define PHIM9 57
using namespace std;
int TIM_DS_THEO_MA(listDauSach l, string ma);
//void themPhanTuVaoCayTam(treeDG& tam, DocGia a) 
//{
//	if (tam == NULL) {
//		nodeDG* p = khoitaoDG(a);
//		tam = p;
//	}
//	else {
//		if (tam->data.ten > a.ten || (tam->data.ten == a.ten && tam->data.ho > a.ho))
//		{
//			themPhanTuVaoCayTam(tam->pleft, a);
//		}
//		else {
//			themPhanTuVaoCayTam(tam->pright, a);
//		}
//	}
//}
//void taoCayTam(treeDG t, treeDG& tam) 
//{
//	if (t != NULL) {
//		themPhanTuVaoCayTam(tam, t->data);
//		taoCayTam(t->pleft, tam);
//		taoCayTam(t->pright, tam);
//	}
//}
int chuoi_so_sang_so(string s) {
	int a = 0;
	for (int i = 0; i < s.size(); i++) {
		a = a * 10 + (int(s[i]) - 48);
	}
	return a;
}
void swapSoNguyen(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
void taoMaDocGia() {
	srand(time(NULL));
	int a[10001];
	for (int i = 1; i <= 10000; i++) {
		a[i] = i;
	}
	for (int i = 1; i <= 10000; i++) {
		int j = rand() % 10000 + 1;
		swapSoNguyen(a[i], a[j]);
	}
	ofstream fileout("MaDG.txt");
	for (int i = 1; i <= 10000; i++) {
		fileout << a[i];
		if (i < 10000) fileout << " ";
	}
	fileout.close();
}
void caySangMang(treeDG t, DocGia *a[],int &n)
{
	if (t != NULL) {
		caySangMang(t->pleft, a, n);
		a[n] = &t->data;
		n++;
		caySangMang(t->pright, a,n);
	}
}
void swapDG(DocGia *&a,DocGia *&b) {
	DocGia *tam=a;
	a = b;
	b = tam;
}
void sapXepMangDG(DocGia *a[], int n)
{
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = i+1; j < n; j++) {
			string tami = a[i]->ten + a[i]->ho;
			string tamj = a[j]->ten + a[j]->ho;

			if (tami > tamj) { // neu ten khac nhau
				swapDG(a[i], a[j]);
			}
			//else if (a[i]->ten == a[j]->ten && a[i]->ho > a[i]->ho) { // nếu tên bằng nhau và họ khác nhau
			//	swapDG(a[i], a[j]);
			//}
		}
	}
}
char chuyenChuThuongThanhHoa(char c) {
	if (c >= 'a' && c <= 'z') {
		c = c - 32;
	}
	return c;
}
int nhapChu(int x,int y,string &s) {
	gotoXY(x, y);
	ShowCur(1);
	cout << s;
	x = x + s.size();
	gotoXY(x, y);
	char tam;
	if (s.size() > 0) {
		tam = s.back();
	}
	else tam = ' ';
	while (true) {
		char c = _getch();
		if (c == ESC) return ESC;
		if (c == LEN) return LEN;
		if (c == XUONG) return  XUONG;
		if ((c == ' ' && tam == ' ') || s.size() > 40  || (c == ' ' && s.size()<1)) continue;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' ) {
			gotoXY(x++, y);
			if (s.size()<1 || s[s.size()-1]==' ') {
				cout << chuyenChuThuongThanhHoa(c);
				s = s + chuyenChuThuongThanhHoa(c);
			}
			else {
				cout << c;
				s = s + c;
			}
		}
		if (c == ENTER) break;
		if (c == 8 && s.size() > 0) {
			gotoXY(--x, y);
			cout << ' ';
			gotoXY(x, y);
			s.pop_back();
		}
		tam = c;
	}
	if (s.size() > 0) {
		while (s.back() == ' ') {
			s.pop_back();
		}
	}
	return 1;
}
int nhapSo(int x, int y,int &a) {
	gotoXY(x, y);
	ShowCur(1);
	string s;
	if (a != 0) {
		s = to_string(a);
	}
	cout << s;
	x = x + s.size();
	gotoXY(x, y);
	while (true) {
		char c = _getch();
		if (c == ESC) return ESC;
		if (c == LEN) return LEN;
		if (c == XUONG) return  XUONG;
		if (c >= '0' && c <= '9') {
			gotoXY(x++, y);
			cout << c;
			s = s + c;

		}
		if (c == ENTER) break;
		if (c == 8  && s.size() >0 ) {
			gotoXY(--x, y);
			cout << ' ';
			gotoXY(x, y);
			s.pop_back();
		}
	}
	a = chuoi_so_sang_so(s);
	return 1;
}
int nhapISBN(int x, int y,string &s) {
	gotoXY(x, y);
	ShowCur(1);
	cout << s;
	x = x + s.size();
	gotoXY(x, y);
	while (true) {
		char c = _getch();
		if (c == ESC) return ESC;
		if (c == LEN) return  LEN;
		if (c == XUONG) return  XUONG;
		if (c >= '0' && c <= '9') {
			gotoXY(x++, y);
			cout << c;
			s = s + c;

		}
		if (c == ENTER) break;
		if (c == 8 && s.size() > 0) {
			gotoXY(--x, y);
			cout << ' ';
			gotoXY(x, y);
			s.pop_back();
		}
	}
	return 1;
}
int nhapChuVaSo(int x, int y, string& s) {
	gotoXY(x, y);
	ShowCur(1);
	cout << s;
	x = x + s.size();
	gotoXY(x, y);
	char tam;
	if (s.size() > 0) {
		tam = s.back();
	}
	else tam = ' ';
	while (true) {
		char c = _getch();
		if (c == ESC) return ESC;
		if (c == LEN) return ESC;
		if ((c == ' ' && tam == ' ') || s.size() > 40 || (c == ' ' && s.size() < 1)) continue;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || (c>='0' && c<='9')) {
			gotoXY(x++, y);
			if (s.size() < 1 || s[s.size() - 1] == ' ') {
				cout << chuyenChuThuongThanhHoa(c);
				s = s + chuyenChuThuongThanhHoa(c);
			}
			else {
				cout << c;
				s = s + c;
			}
		}
		if (c == ENTER) break;
		if (c == 8 && s.size() > 0) {
			gotoXY(--x, y);
			cout << ' ';
			gotoXY(x, y);
			s.pop_back();
		}
		tam = c;
	}
	if (s.size() > 0) {
		while (s.back() == ' ') {
			s.pop_back();
		}
	}
	return 1;
}
//dem so luong sach trong 1 dau sach
int tong_so_sach(dauSach x)
{
	int n = 0;
	for (nodeDMS* p = x.dms.phead; p != NULL; p = p->pnext)
		n++;
	return n;
}
//===Ham hoan doi dau sach====
void swapDS(dauSach& a,dauSach& b) {
	dauSach tam;
	tam = a;
	a = b;
	b = tam;
}
int DemSachConMuonDuoc(listDauSach l,string ISBN) {
	int i = TIM_DS_THEO_MA(l, ISBN);
	int n = 0;
	if (i != -1)
	{
		for (nodeDMS* p = l.ds_DauSach[i]->dms.phead; p != NULL; p = p->pnext)
			if (p->data.trangThai == 0)
				n++;
	}
	return n;
}
int tongsosach(dauSach x) {
	int n = 0;
	for (nodeDMS* p = x.dms.phead; p != NULL; p = p->pnext)
		n++;
	return n;
}

// hàm có chức năng bắt phim vừa nhập để điều khiển menu
int key(char c)
{
	if (c == 0)
		c = _getch();
	if (c == 72)
		return LEN;
	if (c == 80)
		return XUONG;
	if (c == 77)
		return PHAI;
	if (c == 75)
		return TRAI;
	if (c == 27)
		return ESC;
	if (c == 13)
		return ENTER;
}
void ToMau(int x, int y, string a, int color)
{
	textcolor(color);
	gotoXY(x, y);
	cout << a;
	textcolor(7);
}
int DemSoDG(treeDG t) {
	if (t == NULL)
		return 0;
	else
		return 1 + DemSoDG(t->pleft) + DemSoDG(t->pright);
}



