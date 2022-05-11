#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "my_lib.h"
#include "ctdl.h"
#include "HamHoTro.h"
#include "DoHoa.h"
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
void ghi_file_tat_ca_doc_gia(treeDG t);
int yXuat=10;
// =================menu==================
void Normal() {
	SetBGColor(0);
	SetColor(14);
}
void HighLight() {
	SetColor(1);
	SetBGColor(6);
}
int MenuDong(char td[][50], int sum,int dong,int cot) {
	Normal();
	int chon = 0;
	int i;
	for (i = 0; i < sum; i++)
	{
		gotoXY(cot, dong + i);
		cout << td[i];
	}
	HighLight();
	gotoXY(cot, dong + chon);
	cout << td[chon];
	char kytu;
	while (1) {
		char c = _getch();
		kytu = key(c);
		switch (kytu) {
		case LEN:if (chon + 1 > 1)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			chon--;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			break;
		}		
		case XUONG:if (chon + 1 < sum)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			chon++;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			break;
		}
		case 13: return chon + 1;
		}  // end switch
	}
}
int MenuDong2(char td[][50], int sum, int dong, int cot) {
	ShowCur(0);
	int chon = 0;
	int i;
	int tam = 0;
	HighLight();
	gotoXY(cot, dong);
	cout << td[0];
	Normal();
	gotoXY(cot + 5, dong);
	cout << td[1];
	char kytu;
	while (1) {
		kytu = _getch();
		if (kytu == 224) kytu = _getch();
		switch (kytu) {
		case TRAI:if (chon + 1 > 1)
		{
			Normal();
			gotoXY(cot + 5, dong);
			cout << td[1];
			chon--;
			HighLight();
			gotoXY(cot, dong);
			cout << td[0];
			break;
		}
		case PHAI:if (chon + 1 < sum)
		{
			Normal();
			gotoXY(cot, dong);
			cout << td[0];
			chon++;
			HighLight();
			gotoXY(cot + 5, dong);
			cout << td[1];
			break;
		}
		case LEN: {
			return LEN;
		}
				 break;
		case 13: return chon + 1;
		}  // end switch
	}
}
// ============ Xu li doc gia===============
istream& operator>>(istream& in, DG& a)
{
	int check;
	char phai[2][50] = {
		"Nam",
		"Nu",
	};
	char trangThai[2][50] ={
		"0",
		"1",
	};
	BangNhapDG();
	textcolor(14);
	ShowCur(1);
	//====ho===
	gotoXY(177, 6);
	cout << a.maThe;
	//============ho======
	ho:
	check = nhapChu(177,9,a.ho);
	if (check == LEN) {
		goto ho;
	}
	//============ten=======
	ten:
	check = nhapChu(177,13, a.ten);
	if (check == LEN) {
		goto ho;
	}
	//=============phai====
	phai:
	int chon = MenuDong2(phai, 2,17,177);
	if (chon == LEN) {
		textcolor(14);
		goto ten;
	}
	else if (chon == 1) {
		a.phai = "Nam";
	}
	else a.phai = "Nu";
	//=============trang thai=========
	chon = MenuDong2(trangThai, 2, 20, 180);
	if (chon == LEN) {
		textcolor(14);

		goto phai;
	}
	if (chon == 1) {
		a.trangThai=0;
	}
	else a.trangThai=1;
	return in;
}
ostream& operator<<(ostream& out, DG a) {
	gotoXY(7, yXuat);
	out << a.maThe;
	gotoXY(22, yXuat);
	out << a.ho;
	gotoXY(62, yXuat);
	out <<a.ten ;
	gotoXY(82, yXuat);
	out  << a.phai;
	gotoXY(92, yXuat);
	if (a.trangThai == 1) {
		out << "Dang hoat dong";
	}
	else out << "Bi khoa";
	yXuat++;
	return out;
}
void xuatDG_theoMa(treeDG t,char &check)  // ki thuat left-node-right  sẽ đi sâu xuống về bên trái nhất rồi xuất rồi sang phải
{							  // nên sẽ xuất ra danh sách theo key tăng dần  (key là mã độc giả)
	/*if (t != NULL) {
		xuatDG_theoMa(t->pleft);
		cout << t->data;
		xuatDG_theoMa(t->pright);
	}
	if ((yXuat - 10 + 1) % 30 == 0) {
		char c = _getch();
		yXuat = 10;
		system("cls");
		BangDS_DocGia();
	}*/
	int soDG = DemSoDG(t);
	int tongSoTrang = (soDG - 1) / 30 + 1;
	yXuat = 10;
	int n = 0;
	DocGia** a = new DocGia * [soDG];
	caySangMang(t, a, n);
	for (int i = 0; i < tongSoTrang; i++) {
		system("cls");
		textcolor(14);
		BangDS_DocGia();
		yXuat = 10;
		for (int j = 30 * i; j < (30 * i) + 30 && j < soDG; j++)
			cout << *a[j];
		gotoXY(105, 42); cout << i + 1 << "/" << tongSoTrang;
		char c = _getch();
		if (c == -32) {
			c = _getch();
		}
		else if (c == ESC) {
			check = ESC;
			break;
		}
		else if (c >= '1' && c  <= '9') {
			check = c;
			return;
		}
		if (c == PHAI)
		{
			if (i == tongSoTrang - 1)
				i = -1;
		}
		else if (c == TRAI)
		{
			if (i == 0)
				i = tongSoTrang - 2;
			else
			{
				i -= 2;
				continue;
			}
		}
		else {
			break;
		}
	}
	delete[] a;
}
void xuatDG_theoTen(treeDG t, char& check)
{
	int soDG = DemSoDG(t);
	int tongSoTrang = (soDG - 1) / 30 + 1;
	yXuat = 10;
	int n=0;
	DocGia** a=new DocGia*[soDG];
	caySangMang(t,a,n);
	sapXepMangDG(a, n);
	for (int i = 0; i < tongSoTrang; i++) {
		system("cls");
		textcolor(14);
		BangDS_DocGia();
		yXuat = 10;
		for (int j = 30 * i; j < (30 * i) + 30 && j < soDG; j++)
			cout << *a[j];
		gotoXY(105, 42); cout << i + 1 << "/" << tongSoTrang;
		char c = _getch();
		if (c == -32){
			c = _getch();
		}
		else if (c==ESC) {
			check = ESC;
			break;
		}
		else if (c > '1' && c < '9') {
			check = c;
			return;
		}
		if (c == PHAI)
		{
			if (i == tongSoTrang - 1)
				i = -1;
		}
		else if (c == TRAI)
		{
			if (i == 0)
				i = tongSoTrang - 2;
			else
			{
				i -= 2;
				continue;
			}
		}
		else {
			break;
		}
	}
	delete[] a;
}
nodeDG* khoitaoDG(DocGia x)
{
	nodeDG* p = new nodeDG;
	p->data = x;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
void themDocGia(treeDG& t, DocGia x)
{
	if (t == NULL)
	{
		nodeDG* p = khoitaoDG(x);
		t = p;
	}
	else
	{
		if (x.maThe > t->data.maThe)
		{
			themDocGia(t->pright, x);
		}
		else
		{
			themDocGia(t->pleft, x);
		}
	}
}
void nodeTheMang(treeDG& t, nodeDG*& k)
{
	if (k->pright == NULL) // quy tắc phải cùng cây con trái
	{
		t->data = k->data;
		nodeDG* tam = k;
		k = k->pleft;
		delete tam;
	}
	else
	{
		nodeTheMang(t, k->pright);
	}
}
void xoaDocGia(treeDG& t, int x, int &check)
{
	if (t != NULL)
	{
		if (t->data.maThe == x) {
			check = 1;
			if (t->pleft == NULL && t->pright == NULL)
			{
				nodeDG* tam = t;
				t = NULL;
				delete tam;
			}
			else if (t->pleft != NULL && t->pright == NULL) // node 1 con
			{
				nodeDG* tam = t;
				t = t->pleft;
				delete tam;
			}
			else if (t->pleft == NULL && t->pright != NULL) // node 1 con
			{
				nodeDG* tam = t;
				t = t->pright;
				delete tam;
			}
			else if (t->pleft != NULL && t->pright != NULL)    // node 2 con
			{
				nodeTheMang(t, t->pleft);
			}
		}
		else if (x > t->data.maThe) {
			xoaDocGia(t->pright, x, check);
		}
		else {
			xoaDocGia(t->pleft, x, check);
		}
	}
}
void hieuchinhDG(treeDG &t, int x)
{
	if (t != NULL)
	{
		if (t->data.maThe == x)
		{
			cin>> t->data;
			ghi_file_tat_ca_doc_gia(t);
		}
		else if (t->data.maThe < x)
		{
			hieuchinhDG(t->pright, x);
		}
		else
		{
			hieuchinhDG(t->pleft, x);
		}
	}
}

//============Xu li dau sach==============
ostream& operator<<(ostream& out, dauSach a) {
	textcolor(14);
	gotoXY(7, yXuat);
	cout << a.ISBN;
	gotoXY(24, yXuat);
	cout << a.tenSach;
	gotoXY(62, yXuat);
	cout << a.soTrang;
	gotoXY(78, yXuat);
	cout << a.tacGia;
	gotoXY(102, yXuat);
	cout << a.namXuatBan;
	gotoXY(118, yXuat);
	cout << a.theLoai;
	yXuat++;
	return out;
}
// hàm sắp xếp đầu sách theo thể loại, sau đó tên sách
void Sap_Xep_Dau_Sach(listDauSach& l) {
	for (int i = 0; i < l.sl - 1; i++) {
		for (int j = i + 1; j < l.sl; j++) {
			string tami = l.ds_DauSach[i]->theLoai + l.ds_DauSach[i]->tenSach;
			string tamj = l.ds_DauSach[j]->theLoai + l.ds_DauSach[j]->tenSach;
			if (tami > tamj) {
				swapDS(*l.ds_DauSach[i], *l.ds_DauSach[j]);
			}
		}
	}
}
void xuatDauSach(listDauSach ds,char& check) {
	int tongSoTrang = (ds.sl - 1) / 30 + 1;
	int soTrang = 1;
	yXuat = 10;
	Sap_Xep_Dau_Sach(ds);
	for (int i = 0; i < tongSoTrang; i++) {
		system("cls");
		textcolor(14);
		BangDauSACH1();
		yXuat = 10;
		for (int j = 30 * i; j < (30* i) + 30 && j < ds.sl; j++)
			cout << *ds.ds_DauSach[j];
		gotoXY(105, 42); cout << i + 1 << "/" << tongSoTrang;
		char c = _getch();
		if (c == -32) {
			c = _getch();
		}
		else if (c == ESC) {
			check = ESC;
			return;
		}
		else if (c > '1' && c < '9') {
			check = c;
			return;
		}
		if (c == 77)
		{
			if (i == tongSoTrang - 1)
				i = -1;
		}
		else if (c == 75)
		{
			if (i == 0)
				i = tongSoTrang - 2;
			else
			{
				i -= 2;
				continue;
			}
		}
	}
}
istream& operator>>(istream& in, dauSach& a)
{
	a.soTrang = 0;
	a.namXuatBan = 0;
	int check;
	BangNhapDauSach();
	textcolor(14);
	ISBN:
	check=nhapISBN(60,11,a.ISBN);
	tenSach:
	check = nhapChu(64, 13, a.tenSach);
	if (check == LEN) {
		goto ISBN;
	}
	soTrang:
	check = nhapSo(64,15, a.soTrang);
	if (check == LEN) {
		goto tenSach;
	}
	tacGia:
	check = nhapChu(63,17,a.tacGia);
	if (check == LEN) {
		goto soTrang;
	}
	namXuatBan:
	check = nhapSo(68,19, a.namXuatBan);
	if (check == LEN) {
		goto tacGia;
	}
	check = nhapChu(64,21, a.theLoai);
	if (check == LEN) {
		goto namXuatBan;
	}
	return in;
}
void themDauSach(listDauSach& ds, dauSach x) 
{
	if (ds.sl < MAX) {
		ds.ds_DauSach[ds.sl] = new dauSach;
		*ds.ds_DauSach[ds.sl] = x;
		ds.sl++;
	}
}
void nhapDS(listDauSach& ds)
{
	dauSach a;
	cin >> a;
	themDauSach(ds, a);
}
//--- ham tim kiem dau sach theo ISBN neu co tra ve vi tri khong thi tra ve <-1>
int TIM_DS_THEO_MA(listDauSach l, string ma)
{
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_DauSach[i]->ISBN == ma)
			return i;
	}
	return -1;
}
void xuatThongTin_1_DS(dauSach a, int y) {
	yXuat = y;
	cout << a;
}
int TIM_DS_THEO_TEN(listDauSach l, string ten) {
	system("cls");
	int kt;
	int j;
	int sl_sach;
	int vitri;
	int *DS_timthay = new int[l.sl]; // mang chua cac đầu sách được tìm thấy
	int* soluongsach = new int[l.sl];// chứa số lượng sách lưu số lượng các sách  của đầu sách tìm thấy;
	bool KT = false;
	int y;
	while (KT == false) {
		j = 0, kt = 0, vitri = 0, sl_sach = 0;
		y = 10;
		for (int i = 0; i < l.sl; i++) {
			vitri = l.ds_DauSach[i]->tenSach.find(ten);
			if (vitri != string::npos) {
				BangDauSACH2();
				xuatThongTin_1_DS(*l.ds_DauSach[i], y);
				sl_sach = DemSachConMuonDuoc(l, l.ds_DauSach[i]->ISBN);
				gotoXY(152, y);
				cout << sl_sach;
				if (sl_sach > 0) {
					gotoXY(168, y);
					if (sl_sach == 1) {
						cout << l.ds_DauSach[i]->ISBN << "-1";
					}
					cout << l.ds_DauSach[i]->ISBN << "-(1->"<<sl_sach<<")";
				}
				
				kt++;
				DS_timthay[j] = i;
				soluongsach[j] = tongsosach(*l.ds_DauSach[i]);
				j++;
				y++;
			}
		}
		if (kt != 0) {
			int k = 10;
			bool check = true;
			while (check) {
				gotoXY(24, k);
				ToMau(24, k, l.ds_DauSach[DS_timthay[k - 10]]->tenSach, 12);
				char c = _getch();
				ToMau(24, k, l.ds_DauSach[DS_timthay[k - 10]]->tenSach, 14);
				int tt = key(c);  // ham để bắt các phím trạng thái
				switch (tt)
				{
				case LEN:
				case TRAI:
				{
					if (k <= 10)
						k = k + j-1;
					else
						k--;
					break;
				}
				case XUONG:
				case PHAI:
				{
					if (k >= j + 10-1)
						k = 10;
					else
						k++;
					break;
				}
				case ESC:
				{
					delete[] DS_timthay;
					delete[] soluongsach;
					return -2;
				}
				case ENTER:
				{
					check = false;
					break;
				}
				}
			}
		}
		else
		{
			delete[] soluongsach;
			delete[] DS_timthay;
			return -1;
		}
	}
}

//=====Quan li danh muc sach===============
nodeDMS* khoitaoDMS(DMS x) {
	nodeDMS* p = new nodeDMS;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void themSach(listDanhMucSach &l, nodeDanhMucSach *p) {
	if (l.phead == NULL) {
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}
void them_sach_vao_ds(listDMS& l, nodeDMS* p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}
void themSach(listDS& l) {
	char check = NULL;
	int kt;
	int k = 0;
	string isbn;
	int i = 0;
	int n = 0;
	bool flag = true;
	while(flag) {
		xuatDauSach(l, check);
		isbn = "";
		BangNhap("NHAP ISBN");
		kt = nhapISBN(180, 6,isbn);
		i = TIM_DS_THEO_MA(l, isbn);
		if (i == -1) {
			gotoXY(180, 8);
			cout << "MA KHONG TON TAI";
			char c=_getch();
		}
		else {
			l.ds_DauSach[i]->soLuongMuon = 0;
			XoaBang();
			BangNhap("SL CAN THEM");
			gotoXY(180, 8);
			cout << "MA TON TAI";
			kt = nhapSo(180, 6,n);
			flag = false;
		}
	}
	string vitri = "";
	DMS x;
	int tam = 0;
	if (l.ds_DauSach[i]->dms.phead != NULL)
	{
		vitri = l.ds_DauSach[i]->dms.ptail->data.vitri; // Lấy vị trí cuối
		int pos = l.ds_DauSach[i]->dms.ptail->data.maSach.find("-"); // tìm vị trí của "-"
		string str = l.ds_DauSach[i]->dms.ptail->data.maSach.substr(pos + 1); // lấy chuỗi sau dấu "-"
		tam = chuoi_so_sang_so(str);
	}
	BangNhapSACH();
	gotoXY(0, 0);
	for (int j = tam; j < n+tam; j++)
	{
		if (tam == 0)
			x.maSach = l.ds_DauSach[i]->ISBN + "-" + to_string(j + 1);
		else
			x.maSach = l.ds_DauSach[i]->ISBN + "-" + to_string(j + 1);
		gotoXY(180,12);
		cout << x.maSach;
		gotoXY(180,14);
		cout << vitri;
		vitri = nhapChuVaSo(180, 14,vitri);
		x.vitri = vitri;
		x.trangThai = 0; // mặc định sách có thể mượn được
		them_sach_vao_ds(l.ds_DauSach[i]->dms, khoitaoDMS(x));
	}
}
