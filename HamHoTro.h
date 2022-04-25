#pragma once
#include "ctdl.h"
#include "All_function.h"
#include "string"
using namespace std;
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
		a[n] = &t->data;
		n++;
		caySangMang(t->pleft,a,n);
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
string nhap(int x,int y) {
	gotoXY(x, y);
	string s;
	char tam = ' ';
	while (true) {
		char c = _getch();
		if (c == ' ' && tam == ' ') continue;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') {
			gotoXY(x++, y);
			if (tam == ' '){
				cout << chuyenChuThuongThanhHoa(c);
				s = s + chuyenChuThuongThanhHoa(c);
			}
			else {
				cout << c;
				s = s + c;
			}
		}
		if (c == 13) break;
		if (c == 8) {
			gotoXY(--x, y);
			cout << ' ';
			gotoXY(x, y);
			s.pop_back();
		}
		tam = c;
	}
	while (s.back() == ' ') {
		s.pop_back();
	}
	return s;
}

