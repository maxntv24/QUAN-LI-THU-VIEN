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
		case LEN: {
			if (chon + 1 > 1)
			{
				Normal();
				gotoXY(cot, dong + chon);
				cout << td[chon];
				chon--;
				HighLight();
				gotoXY(cot, dong + chon);
				cout << td[chon];
			}
			
			break;
		}
		case XUONG: {
			if (chon + 1 < sum)
			{
				Normal();
				gotoXY(cot, dong + chon);
				cout << td[chon];
				chon++;
				HighLight();
				gotoXY(cot, dong + chon);
				cout << td[chon];
			}
			break;
		}
		case ENTER: return chon +1;
		case ESC: return ESC;
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
		case TRAI:
		{
			if (chon + 1 > 1)
			{
				Normal();
				gotoXY(cot + 5, dong);
				cout << td[1];
				chon--;
				HighLight();
				gotoXY(cot, dong);
				cout << td[0];
			}
			else if (chon + 1 == 1) {
				Normal();
				gotoXY(cot, dong);
				cout << td[0];
				chon++;
				HighLight();
				gotoXY(cot+5, dong);
				cout << td[1];
			}
			break;
		}
		case PHAI: {
			if (chon + 1 < sum)
			{
				Normal();
				gotoXY(cot, dong);
				cout << td[0];
				chon++;
				HighLight();
				gotoXY(cot + 5, dong);
				cout << td[1];
			}
			else if (chon + 1 == sum) {
				Normal();
				gotoXY(cot + 5, dong);
				cout << td[1];
				chon--;
				HighLight();
				gotoXY(cot, dong);
				cout << td[0];
			}
			break;
		}
		case LEN: {
			return LEN;
		}
		case ESC: {
			return ESC;
		}
		case 13: return chon + 1;
		}  // end switch
	}
}
// ============ Xu li doc gia===============
int nhapDG(DG& a)
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
	textcolor(3);
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
	else if (check == ESC) {
		return ESC;
	}
	//============ten=======
ten:
	check = nhapChu(177,13, a.ten);
	if (check == LEN) {
		goto ho;
	}
	else if (check == ESC) {
		return ESC;
	}
	//=============phai====
phai:
	int chon = MenuDong2(phai, 2,17,177);
	if (chon == LEN) {
		textcolor(14);
		goto ten;
	}
	else if (chon == ESC) {
		return ESC;
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
	else if (chon == ESC) {
		return ESC;
	}
	else if (chon == 1) {
		a.trangThai=0;
	}
	else a.trangThai=1;
	return 1;
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
		xoaBangDG();
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
		else if (c >= '1' && c <= '9') {
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
int hieuchinhDG(treeDG &t, int x)
{
	if (t != NULL)
	{
		if (t->data.maThe == x)
		{
			int	check = nhapDG(t->data);
			return check;
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
	return -1;
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
		XoaBangDauSACH1();
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
		else if (c >= '1' && c <= '9') {
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
	}
}
int nhapDS(listDauSach l, dauSach a)
{
	a.soTrang = 0;
	a.namXuatBan = 0;
	int check;
	BangNhapDauSach();
ISBN:
	textcolor(14);
	check=nhapISBN(60,11,a.ISBN);
	if (check == LEN) {
		goto ISBN;
	}
	else if (check == ESC) {
		return ESC;
	}
	if (TIM_DS_THEO_MA(l, a.ISBN) != -1) {
		BangThongBao("ISBN da ton tai");
		goto ISBN;
	}
tenSach:
	XoaBangThongBao();
	textcolor(14);
	check = nhapChu(64, 13, a.tenSach);
	if (check == LEN) {
		goto ISBN;
	}
	else if (check == ESC) {
		return ESC;
	}
soTrang:
	check = nhapSo(64,15, a.soTrang);
	if (check == LEN) {
		goto tenSach;
	}
	else if (check == ESC) {
		return ESC;
	}
tacGia:
	check = nhapChu(63,17,a.tacGia);
	if (check == LEN) {
		goto soTrang;
	}
	else if (check == ESC) {
		return ESC;
	}
namXuatBan:
	check = nhapSo(68,19, a.namXuatBan);
	if (check == LEN) {
		goto tacGia;
	}
	else if (check == ESC) {
		return ESC;
	}
	check = nhapChu(64,21, a.theLoai);
	if (check == LEN) {
		goto namXuatBan;
	}
	else if (check == ESC) {
		return ESC;
	}
	return 1;
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
	int check = nhapDS(ds, a);
	if (check == ESC) {
		return;
	}
	else if (check == 1) {
		themDauSach(ds, a);
	}
}

void xuatThongTin_1_DS(dauSach a, int y) {
	yXuat = y;
	cout << a;
}
ostream& operator<<(ostream& out, DMS a) {
	gotoXY(7, yXuat);
	cout << a.maSach;
	gotoXY(26, yXuat);
	if (a.trangThai == 0) {
		textcolor(10);
		cout << "CHO MUON DUOC";
	}
	else if (a.trangThai == 1) {
		textcolor(12);
		cout << "DA CO NGUOI MUON";
	}
	else if (a.trangThai == 0) {
		textcolor(14);
		cout << "DA THANH LI";
	}
	textcolor(14);
	gotoXY(62, yXuat);
	cout << a.vitri;
	return out;
}
int TIM_DS_THEO_TEN(listDauSach l, string ten) {
	ShowCur(0);
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
		XoaBangThongBao();
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
				kt++;
				DS_timthay[j] = i;
				soluongsach[j] = tong_so_sach(*l.ds_DauSach[i]);
				j++;
				y++;
			}
		}
		if (kt != 0) {
			int k = 10;
			bool check = true;
			while (check) {
				gotoXY(0, 0); cout << k;
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
			if (soluongsach[k - 10] <= 0)
			{
				textcolor(14);
				BangThongBao("KHONG CO SACH");
				continue;
			}
			XoaBangDauSACH2();
			bangDMS();
			nodeDMS* p = l.ds_DauSach[DS_timthay[k - 10]]->dms.phead;
			yXuat = 10;
			for (p; p != NULL; p=p->pnext) {
				cout << p->data;
				yXuat++;
			}
			_getch();
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
	while (flag) {
		isbn = "";
		BangNhap("NHAP ISBN");
		kt = nhapISBN(180, 6, isbn);
		i = TIM_DS_THEO_MA(l, isbn);
		if (i == -1) {
			gotoXY(180, 8);
			cout << "MA KHONG TON TAI";
			char c = _getch();
		}
		else {
			l.ds_DauSach[i]->soLuongMuon = 0;
			XoaBang();
			BangNhap("SL CAN THEM");
			gotoXY(180, 8);
			cout << "MA TON TAI";
			kt = nhapSo(180, 6, n);
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
	for (int j = tam; j < n + tam; j++)
	{
		if (tam == 0)
			x.maSach = l.ds_DauSach[i]->ISBN + "-" + to_string(j + 1);
		else
			x.maSach = l.ds_DauSach[i]->ISBN + "-" + to_string(j + 1);
		gotoXY(180, 12);
		cout << x.maSach;
		gotoXY(180, 14);
		cout << vitri;
		check = nhapChuVaSo(180, 14, vitri);
		x.vitri = vitri;
		x.trangThai = 0; // mặc định sách có thể mượn được
		them_sach_vao_ds(l.ds_DauSach[i]->dms, khoitaoDMS(x));
	}
}
//============MUON TRA==============
ostream& operator<<(ostream& in, MuonTra a) {
	gotoXY(7, yXuat);
	cout << a.maSach;
	gotoXY(25, yXuat);
	cout << a.ngayMuon.ngay<<"/"<<a.ngayMuon.thang<<"/"<<a.ngayMuon.nam;
	gotoXY(42, yXuat);
	cout << a.ngayTra.ngay << "/" << a.ngayTra.thang << "/" << a.ngayTra.nam;
	gotoXY(62, yXuat);
	if (a.trangThai == 0) {
		cout << "DANG MUON";
	}
	else if (a.trangThai == 1) {
		cout << "DA TRA";
	}
	else {
		cout << "LAM MAT SACH";
	}
	return in;
}
void themMuonTra(listMT& l, nodeMT* p) {
	if (l.phead == NULL) {
		l.phead = l.ptail = p;
	}
	else {
		l.ptail->pnext = p;
		p->pprev = l.ptail;
		l.ptail = p;
	}
}
nodeMT* khoitaoMuonTra(MuonTra x) {
	nodeMT* p = new nodeMT;
	p->data = x;
	p->pprev = NULL;
	p->pnext = NULL;
	return p;
}
void xuatSachDaMuon(DG x, char& check) {
	ShowCur(0);
	int slSach = demSachDangMuon(x, 2);
	int tongSoTrang = (slSach - 1) / 30 + 1;
	int soTrang = 1;
	for (int i = 0; i < tongSoTrang; i++) {
		xoaBangMuonSach();
		BangMuonSach();
		yXuat = 10;
		for (nodeMT* p = x.mt.phead; p != NULL; p = p->pnext) {
			cout << p->data;
			yXuat++;
		}
		gotoXY(105, 42); cout << i + 1 << "/" << tongSoTrang;
		char c = _getch();
		if (c == -32) {
			c = _getch();
		}
		else if (c == ESC) {
			check = ESC;
			return;
		}
		else if (c >= '1' && c <= '9') {
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
void nhapMuonSACH(MuonTra& x) {
	lay_thoi_gian(x.ngayMuon);
	x.ngayTra.ngay = 0;
	x.ngayTra.thang = 0;
	x.ngayTra.nam = 0;
	x.trangThai = 0; // gan trang thai = 0, vi la dang muon sach
}
bool kt_sach_da_muon(nodeDG* p, string x)
{
	string s = tachISBN_tu_ma_sach(x);
	string tam;
	for (nodeMT* q = p->data.mt.phead; q != NULL; q = q->pnext)
	{
		if (q->data.trangThai == 0) // đang mượn sách
		{
			tam = tachISBN_tu_ma_sach(q->data.maSach);
			if (tam == s)
				return true;
		}
	}
	return false;
}
int muonSACH(nodeDG* &dg,listDS &l) {
	XoaBang();
	BangNhap("Nhap ma sach");
	string masach;
	int check=0;
	bool flag = true;
	while (flag) {
	masach:
		BangNhap("NHAP MA SACH");
		check = nhapMaSach(180, 6, masach);
		if (check == LEN) {
			goto masach;
		}
		else if (check == ESC) {
			return 1;
		}
		int i = 0;
		string ISBN;
		ISBN = tachISBN_tu_ma_sach(masach);
		
		i = TIM_DS_THEO_MA(l, ISBN);
		if (i == -1) // khoong tim thay
		{
			gotoXY(180, 8);
			cout << "MA KHONG DUNG";
			_getch();
			masach = "";
			XoaBang();
			continue;
		}
		else {
			if (kt_sach_da_muon(dg, masach) == true) // kt sach co thuoc đầu sách đã mượn
			{
				gotoXY(180, 8);
				cout << "SACH NAY DA MUON";
				_getch();
				XoaBang();
				masach = "";
				goto masach;
			}
			for (nodeDMS* k = l.ds_DauSach[i]->dms.phead; k != NULL; k = k->pnext)
			{
				if (k->data.maSach == masach)
				{
					if (k->data.trangThai == 0)
					{
						check = true; // danh dau tim thay sach
						k->data.trangThai = 1; // cap nhat sach co nguoi muon
						flag = false;
						gotoXY(180, 8);
						cout << ("DA MUON");
						break;
					}
					else if (k->data.trangThai == 1)
					{
						gotoXY(180, 8);
						cout << ("SACH DA CO NGUOI MUON");
						break;
					}
					else if (k->data.trangThai == 2)
					{
						gotoXY(180, 8);
						cout << ("SACH DA THANH LI");
						break;
					}
				}
			}
			if (flag == false)
			{
				// thêm vào danh sách mượn trả
				MuonTra x;
				x.maSach = masach;
				l.ds_DauSach[i]->soLuongMuon++; // tangsoluong
				nhapMuonSACH(x);
				themMuonTra(dg->data.mt, khoitaoMuonTra(x));
				return 1;
			}
		}
	}
	return 1;
}
void traSach(nodeDG* &p,listDS &l) {
	yXuat = 10;
	system("cls");
	bool flag = true;
	char check;
	string masach;
	int i;
	while (flag) {
		int n = demSachDangMuon(p->data, 2);
		MuonTra* a = new MuonTra[n];
		int j = 0;
		for (nodeMT* q = p->data.mt.phead; q != NULL; q = q->pnext)
		{
			if (q->data.trangThai == 0 || q->data.trangThai == 2)
			{
				nodeDMS* dms = timsach(l, q->data.maSach);
				string isbn = tachISBN_tu_ma_sach(dms->data.maSach);
				i = TIM_DS_THEO_MA(l, isbn);
				if (i != -1)
				{
					BangMuonSach();
					cout << q->data;
					a[j++] = q->data;
					yXuat++;
				}
			}
		}
		int k = 10;
		bool check = true;
		while (check)
		{
			ToMau(7, k, a[k - 10].maSach, 12);
			gotoXY(59, k);
			char c = _getch();
			ToMau(7, k, a[k - 10].maSach, 14);
			int tt = key(c);
			switch (tt)
			{
			case LEN:
			case TRAI:
			{
				if (k <= 10)
					k = k + j - 1;
				else
					k--;
				break;
			}
			case XUONG:
			case PHAI:
			{
				if (k >= j + 10 - 1)
					k = 10;
				else
					k++;
				break;
			}
			case ESC:
			{
				delete[] a;
				return;
			}
			case ENTER:
			{
				BangThongBao("XAC NHAN TRA SACH (Y/N)");
				char c;
				do {
					c = _getch();
				} while (c != 'n' && c != 'y');
				if (c == 'y') {
					check = false;
				}
				break;
			}
			}
		}
		int dem = 0; // bien kiem tra so sach doc gia da lam mat =0 mo the
		Date thoigian;
		lay_thoi_gian(thoigian);
		nodeDMS* dms1 = timsach(l, a[k - 10].maSach);
		for (nodeMT* mt = p->data.mt.phead; mt != NULL; mt = mt->pnext)
		{
			if (mt->data.maSach == dms1->data.maSach)
			{
				dms1->data.trangThai = 0; // cap nhat sach co the muon
				mt->data.trangThai = 1; // cap nhat lai doc gia da tra sach
				mt->data.ngayTra = thoigian;
			}
			if (mt->data.trangThai == 2) dem++;
		}
		if (dem != 0) // còn sách làm mất -> khóa thẻ
			p->data.trangThai = 0;
		else
			p->data.trangThai = 1; // mở thẻ
		BangThongBao("TRA SACH THANH CONG        ");
		l.ds_DauSach[i]->soLuongMuon--;
		flag = false;
		delete[] a;
	}
}
void lamMatSach(nodeDG*& p, listDS& l) {
	yXuat = 10;
	system("cls");
	bool flag = true;
	char check;
	string masach;
	int i;
	while (flag) {
		int n = demSachDangMuon(p->data, 2);
		MuonTra* a = new MuonTra[n];
		int j = 0;
		for (nodeMT* q = p->data.mt.phead; q != NULL; q = q->pnext)
		{
			if (q->data.trangThai == 0 || q->data.trangThai == 2)
			{
				nodeDMS* dms = timsach(l, q->data.maSach);
				string isbn = tachISBN_tu_ma_sach(dms->data.maSach);
				i = TIM_DS_THEO_MA(l, isbn);
				if (i != -1)
				{
					BangMuonSach();
					cout << q->data;
					a[j++] = q->data;
					yXuat++;
				}
			}
		}
		int k = 10;
		bool check = true;
		while (check)
		{
			ToMau(7, k, a[k - 10].maSach, 12);
			gotoXY(59, k);
			char c = _getch();
			ToMau(7, k, a[k - 10].maSach, 14);
			int tt = key(c);
			switch (tt)
			{
			case LEN:
			case TRAI:
			{
				if (k <= 10)
					k = k + j - 1;
				else
					k--;
				break;
			}
			case XUONG:
			case PHAI:
			{
				if (k >= j + 10 - 1)
					k = 10;
				else
					k++;
				break;
			}
			case ESC:
			{
				delete[] a;
				return;
			}
			case ENTER:
			{
				BangThongBao("XAC NHAN LAM MAT SACH (Y/N)");
				char c;
				do {
					c = _getch();
				} while (c != 'n' && c != 'y');
				if (c == 'y') {
					check = false;
				}
				break;
			}
			}
		}
		Date thoigian;
		lay_thoi_gian(thoigian);
		nodeDMS* dms1 = timsach(l, a[k - 10].maSach);
		for (nodeMT* mt = p->data.mt.phead; mt != NULL; mt = mt->pnext)
		{
			if (mt->data.maSach == dms1->data.maSach)
			{
				dms1->data.trangThai = 2; // cap nhat sach da thanh li
				mt->data.trangThai = 2; // cap nhap da lam mat sach
			}
		}
		p->data.trangThai = 0;
		BangThongBao("DA KHOA THE");
		delete[] a;
		flag = false;
	}
}
ostream& operator<<(ostream& in, quaHan a) {
	gotoXY(7, yXuat);
	cout << a.maDG;
	gotoXY(21, yXuat);
	cout << a.tenDG;
	gotoXY(52, yXuat);
	cout << a.tenSach;
	gotoXY(102, yXuat);
	cout << a.ngayMuon.ngay << "/" << a.ngayMuon.thang << "/" << a.ngayMuon.nam;
	gotoXY(120, yXuat);
	cout << a.soNgay;
	return in;
}
nodeQH* khoitaoQH(quaHan x) {
	nodeQH* p = new nodeQH;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void themQH(listQH& l, nodeQH* p) {
	if (l.phead == NULL) {
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}
void timQH(listDauSach ds , treeDG t, listQH &l, int &n) {
	if (t!=NULL)
	{
		timQH(ds,t->pleft, l, n);
		for (nodeMT* p = t->data.mt.phead; p != NULL; p = p->pnext)
		{
			if (p->data.trangThai == 0 || p->data.trangThai == 2)
			{
				int tam = tinhNgay(p->data.ngayMuon);
				if (tam > 7)
				{
					quaHan a;
					a.maDG = t->data.maThe;
					a.tenDG = t->data.ho +" "+ t->data.ten;
					a.tenSach = timTenSach(ds,tachISBN_tu_ma_sach(p->data.maSach));
					a.ngayMuon = p->data.ngayMuon;
					a.soNgay = tam;
					themQH(l, khoitaoQH(a));
					n++;
				}
			}
		}
		timQH(ds, t->pright, l, n);
	}
}
void dsQuaHan(listDS ds,treeDG t) {
	yXuat = 10;
	SetBGColor(0);
	system("cls");
	textcolor(14);
	listQH l;
	int n = 0;
	timQH(ds, t, l, n);
	for (nodeQH* p = l.phead; p->pnext != NULL; p = p->pnext) {
		for (nodeQH* q = p->pnext; q != NULL; q = q->pnext) {
			if (p->data.soNgay < q->data.soNgay) {
				quaHan tam = p->data;
				p->data = q->data;
				q->data = tam;
			}
		}
	}
	bangQuaHan();
	for (nodeQH* k = l.phead; k != NULL; k = k->pnext) {
		cout << k->data;
		yXuat++;

	}
	if (l.phead == NULL)
		BangThongBao("DANH SACH TRONG");
	else
		_getch();
}
void top10sach(listDauSach l)
{
	SetBGColor(0);
	system("cls");
	BangTop10();
	// có thể dùng heapsort lấy ra top 10 nhưng không thay đổi vị trí
	// hoặc dùng mảng temp chứa mã sách và số lượng mượn 
	// sắp xếp theo thứ tự giảm dần top 10 sách
	for (int i = 0; i < l.sl - 1; i++)
	{
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_DauSach[i]->soLuongMuon < l.ds_DauSach[j]->soLuongMuon)
			{
				dauSach* temp = l.ds_DauSach[i];
				l.ds_DauSach[i] = l.ds_DauSach[j];
				l.ds_DauSach[j] = temp;
			}

		}
	}
	yXuat = 10;
	int top = 0;
	for (int k = 0; k < l.sl && k < 10; k++)
	{
		gotoXY(168, yXuat);
		cout << ++top;
		gotoXY(152, yXuat);
		cout << l.ds_DauSach[k]->soLuongMuon;
		cout << *l.ds_DauSach[k];	
	}
}