#pragma once
#include "ctdl.h"
#include "All_function.h"
#include "string"
#include <windows.h>
#pragma warning(disable : 4996)
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
		if (c == LEN) return LEN;
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
int nhapMaSach(int x, int y, string& s) {
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
		if ((c == ' ' && tam == ' ') || s.size() > 40 || (c == ' ' && s.size() < 1)) continue;
		if ((c >= '0' && c <= '9')|| c=='-') {
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
//dem so luong sach trong 1 dau sach
int tong_so_sach(dauSach x)
{
	int n = 0;
	for (nodeDMS* p = x.dms.phead; p != NULL; p = p->pnext)
		n++;
	return n;
}
// số lượng sách độc giả mượn 
int so_sach_DG_muon(DG x)
{
	int n = 0;
	for (nodeMT* p = x.mt.phead; p != NULL; p = p->pnext)
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
treeDG timDG_theo_ma(treeDG t,int x) {
	if (t != NULL)
	{
		if (t->data.maThe == x)
		{
			return t;
		}
		else if (t->data.maThe < x)
		{
			timDG_theo_ma(t->pright, x);
		}
		else
		{
			timDG_theo_ma(t->pleft, x);
		}
	}
	else return NULL;
}
void lay_thoi_gian(Date& x) //ham lay thoi gian hiện tại
{
	time_t t = time(NULL);
	tm* now = localtime(&t);
	x.ngay = now->tm_mday;
	x.thang = now->tm_mon + 1;
	x.nam = now->tm_year + 1900;
}
// ham tim kiem dau sach theo ISBN neu co tra ve vi tri 
int TIM_DS_THEO_MA(listDauSach l, string ma)
{
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_DauSach[i]->ISBN == ma)
			return i;
	}
	return -1;
}
// neu check =1 tra ve sach dang muon, neu check =2 tra ve sach da va dang muon
int demSachDangMuon(DG x,int check) { 
	int dem2 = 0;
	int dem1 = 0;
	for (nodeMT* p = x.mt.phead; p != NULL; p = p->pnext) {
		if (p->data.trangThai == 0 || p->data.trangThai == 2) {
			dem1++;
		}
		dem2++;
	}
	if (check == 1) {
		return dem1;
	}
	else return dem2;
}
string tachISBN_tu_ma_sach(string a)
{
	string temp;
	int n = a.length();
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '-')
			dem = i;
	}
	temp = a.substr(0, dem);

	return temp;
}
void test(string s) {
	gotoXY(0, 0);
	cout << s;
	_getch();
}
void intro() {
	int mau = 0;
	int dong = 200;
	int cot = 49;
	int i = 0;
	int j = 2;
	while (i < dong)
	{
		gotoXY(i + 5, 1);
		SetColor(4);
		cout << char(205);
		i++;
	}
	gotoXY(205, 1);
	SetColor(4);
	cout << char(187);
	while (j < cot)
	{
		gotoXY(205, j);
		SetColor(4);
		cout << char(186);

		j++;
	}
	gotoXY(205, 48);
	SetColor(4);
	cout << char(188);
	int a = dong;
	while (a > 0)
	{
		gotoXY(a + 4, 48);
		SetColor(4);
		cout << char(205);

		a--;
	}
	gotoXY(4, 48);
	SetColor(11);
	cout << char(200);
	int b = cot;
	while (b > 3)
	{
		gotoXY(4, b - 2);
		SetColor(4);
		cout << char(186);

		b--;
	}
	gotoXY(4, 1);
	SetColor(4);
	cout << char(201);

	string str;
	ifstream file;
	SetColor(11);
	file.open("ctdl.txt", ios::in);
	int in = 10, lap = 0;
	while (!file.eof())
	{
		getline(file, str);
		gotoXY(50, in);
		cout << str;
		in++;
		lap++;
		Sleep(100);
	}
	for (int i = 10; i < lap + 10; i++)
	{
		gotoXY(50, i);
		cout << "                                                                          ";
		Sleep(100);
	}
	file.close();
	int cotgiua = 2;
	while (cotgiua < cot - 1)
	{
		gotoXY(150, cotgiua);
		SetColor(4);
		cout << char(186);
		Sleep(10);
		cotgiua++;
	}
	int nganggiua = 151;
	while (nganggiua < 205)
	{
		gotoXY(nganggiua, 25);
		SetColor(4);
		cout << char(205);
		Sleep(10);
		nganggiua++;
	}
	ifstream file1;
	file1.open("qltv.txt", ios::in);
	str = "";
	in = 15;
	SetColor(11);
	while (!file1.eof())
	{
		getline(file1, str);
		gotoXY(50, in);
		cout << str;
		in++;
		Sleep(100);
	}
	file1.close();
	gotoXY(55, 35);
	SetColor(2);
	cout << "NGUOI HUONG DAN : LUU NGUYEN KY THU ";
	Sleep(10);
	gotoXY(155, 5);
	SetColor(6);
	cout << "DAY LA DO AN KET THUC MON CAU TRUC DU LIEU VA";
	gotoXY(155, 6);
	SetColor(6);
	cout << "GIAI THUAT. DO AN VAN CON MOT SO";
	gotoXY(155, 7);
	SetColor(6);
	cout << "THIEU SOT, MONG THAY BO QUA";
	//IN RA TEN SINH VIEN
	gotoXY(155, 31);
	SetColor(2);
	cout << "SINH VIEN THAM GIA LAM DO AN" << endl;
	gotoXY(190, 31);
	cout << "MA SV";
	gotoXY(155, 35);
	cout << "NGUYEN TAN VU";
	gotoXY(190, 35);
	cout << "N20DCAT065";
	ShowCur(0);
	_getch();
}
// tim sach theo ma
nodeDMS* timsach(listDS l, string ma_sach)
{
	string isbn = tachISBN_tu_ma_sach(ma_sach);
	int i = TIM_DS_THEO_MA(l, isbn);
	if (i != -1)
		for (nodeDMS* p = l.ds_DauSach[i]->dms.phead; p != NULL; p = p->pnext)
		{
			if (p->data.maSach == ma_sach)
				return p;
		}
	return NULL;
}
int tinhNgay(Date t) {
	Date t_now;
	lay_thoi_gian(t_now);
	int dem = 0;
	while (t_now.nam >= t.nam)
	{
		if (t.nam == t_now.nam && t_now.thang == t.thang)
		{
			dem += t_now.ngay - t.ngay;
			break;
		}
		else
		{
			if (t.thang == 4 || t.thang == 6 || t.thang == 9 || t.thang == 11)
			{
				dem += 30 - t.ngay;
			}
			if (t.thang == 1 || t.thang == 3 || t.thang == 5 || t.thang == 7 || t.thang == 8 || t.thang == 10 || t.thang == 12)
			{
				dem += 31 - t.ngay;
			}
			if (t.thang == 2)
			{
				if (t.nam % 4 == 0 && t.nam % 100 != 0 || t.nam % 400 == 0)
				{
					dem += 29 - t.ngay;
				}
				else
					dem += 28 - t.ngay;
			}
			t.thang++; t.ngay = 0;
			if (t.thang == 13)
			{
				t.nam++;
				t.thang = 1;
			}
		}
	}
	return dem;
}
string timTenSach(listDauSach l,string s) {
	for (int i = 0; i < l.sl; i++) {
		if (l.ds_DauSach[i]->ISBN == s) {
			return l.ds_DauSach[i]->tenSach;
		}
	}
	return "-1";
}
int ktQuaHan(DocGia x) {
	Date t;
	lay_thoi_gian(t);
	for (nodeMT* p = x.mt.phead; p != NULL; p = p->pnext) {
		if (p->data.trangThai == 1) continue;
		if (tinhNgay(p->data.ngayMuon) > 7) return -1;
	}
	return 1;
}
