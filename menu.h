#pragma once
#include "my_lib.h"
#include "All_function.h"
#include "doc_ghi_file.h"
#include "DoHoa.h"
char menu[][50] =
{
	"QUAN LI DOC GIA            ",
	"QUAN LI DAU SACH                   ",
	"MUON SACH                  ",
	"TRA SACH                   ",
	"LAM MAT SACH               ",
	"TIM SACH DOC GIA DANG MUON ",
	"DANH SACH DOC GIA QUA HAN  ",
	"TOP 10 SACH MUON NHIEU NHAT",
	"THOAT  CHUONG TRINH        "
};
char menuDG[][50] =
{
	"Them doc gia            ",
	"Xuat danh sach doc gia  ",
	"Xoa doc gia             ",
	"Hieu chinh doc gia      ",
};
char menuDS[][50] =
{
	"Them dau sach           ",
	"Xuat danh sach dau sach ",
	"Xoa doc gia             ",
	"Hieu chinh doc gia      ",
};
//void menuDocGia(treeDG &t) {
//	ShowCur(0);
//	bool flagDG = true;
//	int chon, sum = 4;
//	while (flagDG) {
//		chon = MenuDong(menuDG, sum, 3, 40);
//		switch (chon) {
//		case 1: {
//			textcolor(3);
//			DG a;
//			ifstream inMaDG("MaDG.txt");
//			ofstream inTam("tam.txt");
//			inMaDG >> a.maThe;
//			cin >> a;
//			themDocGia(t, a);
//			int tam;
//			/*while (inMaDG >> tam) {
//				if (tam != a.maThe) {
//					inTam << tam << " ";
//				}
//			}*/
//			inMaDG.close();
//			inTam.close();
//			/*remove("MaDG.txt");
//			rename("tam.txt", "MaDG.txt");*/
//			system("cls");
//			break;
//		}
//		case 2: {
//			yXuat = 10;
//			SetBGColor(0);
//			system("cls");
//			BangDS_DocGia();
//			gotoXY(0, 0);
//			cout << "Nhap lua chon: ";
//			int c;
//			cin>>c;
//			if (c == 1) {
//				xuatDG_theoMa(t);
//			}
//			else
//			{
//				xuatDG_theoTen(t);
//			}
//			char x = _getch();
//			break;
//		}
//		case 3: {
//			SetBGColor(0);
//			system("cls");
//			cout << "Nhap ma the can xoa: ";
//			int n;
//			cin >> n;
//			//xoaDocGia(t, n);
//			cout << "Da xoa!!!";
//			system("pause");
//		}
//		case 4: {
//			SetBGColor(0);
//			system("cls");
//			cout << "Nhap ma the can thay doi: ";
//			int n;
//			cin >> n;
//			hieuchinhDG(t, n);
//			cout << "Da hieu chinh!!!";
//			system("pause");
//		}
//		default: break;
//		}
//	}
//}
void menuDocGia2(treeDG& t) {
	ShowCur(0);
	char check=NULL;
	bool flagDG = true; // bien dung de ngat vong while va quay ve menu chinh
	int chon, sum = 4;
	while (flagDG) {
		//chon = MenuDong(menuDG, sum, 3, 40);
		yXuat = 10;
		SetBGColor(0);
		system("cls");
		BangDS_DocGia();
		gotoXY(0, 0);
		xuatDG_theoMa(t,check);
		char k;
		if (check == NULL) {
			k=_getch();
		}
		else k = check;
		switch (k) {
		case PHIM1:{
			check = NULL;
			system("cls");
			xuatDG_theoTen(t,check);
			_getch();
			break;
		}
		case PHIM2:{
			check = NULL;
			textcolor(3);
			DG a;
			ifstream inMaDG("MaDG.txt");
			ofstream inTam("tam.txt");
			inMaDG >> a.maThe;
			cin >> a;
			themDocGia(t, a);
			int tam;
			while (inMaDG >> tam) {
				if (tam != a.maThe) {
					inTam << tam << " ";
				}
			}
			inMaDG.close();
			inTam.close();
			remove("MaDG.txt");
			rename("tam.txt", "MaDG.txt");
			ghi_file_tat_ca_doc_gia(t);
			system("cls");
			break;
		}
		case PHIM3: {
			check = NULL;
			ShowCur(1);
			textcolor(3);
			BangXoa();
			int x;
			gotoXY(182, 8);
			cin >> x;
			gotoXY(182, 10);
			cout << "CHAC CHAN (y/n)";
			char c;
			do {
				c = _getch();
				if (c == 'y') {
					int check = 0;
					xoaDocGia(t, x,check);
					ghi_file_tat_ca_doc_gia(t);
					gotoXY(182, 10);
					if (check == 1) {
						cout << "DA XOA!!!";
						ofstream out("MaDG.txt", ios_base::app);
						out << x<<" ";
						out.close();
					}
					else cout << "MA THE KHONG TON TAI";
				}
				else if (c == 'n') {
					gotoXY(182, 10);
					cout << "DA HUY";
					break;
				}
			} while (c != 'y');
			c = _getch();
			break;
		}
		case PHIM4: {
			check = NULL;
			ShowCur(1);
			textcolor(3);
			BangHieuChinh();
			int n;
			gotoXY(182, 8);
			cin >> n;
			xoaBangHieuChinh();
			hieuchinhDG(t, n);
			XoaBangNhapDG();
			BangHieuChinh();
			textcolor(6);
			gotoXY(182, 8);
			cout << n;
			gotoXY(182, 10);
			cout << "Da hieu chinh!!!";
			ghi_file_tat_ca_doc_gia(t);
			char c = _getch();
			break;
		}
		case ESC: {
			flagDG = false;
			break;
		}
		}
	}
}
void menuDauSach(listDauSach& ds) {
	ShowCur(0);
	char check = NULL;
	int chon, sum = 4;
	bool flagDS=true;
	while (flagDS) {
		SetBGColor(0);
		xuatDauSach(ds,check);
		if (check == ESC) return;
		char k=check;
		if (check == NULL) {
			k = _getch();
		}
		else k = check;
		switch (k)
		{
		case PHIM1: {
			nhapDS(ds);
			ghi_file_Dau_Sach(ds);
			break;
		}
		case PHIM2: {
			BangNhap("NHAP TEN SACH");
			string s = "";
			s = nhapChu(180,6,s);
			TIM_DS_THEO_TEN(ds,s);
			break;
		}
		case PHIM3: {
			themSach(ds);
			ghi_file_Dau_Sach(ds);
			break;
		}
		case ESC: {
			flagDS = false;
			break;
		}
		}
		_getch();
	}
}
void menuChinh() {
	treeDG t = NULL;
	listDauSach ds;
	ds.sl = 0;
	cout << "a";
	load_file_Dau_Sach(ds);
	cout << "a";
	load_file_Doc_Gia(t);
	cout << "a";

	ShowCur(0);
	int chon, sum = 9;
	while (1) {
		system("cls");
		chon = MenuDong(menu, sum,3,3);
		switch (chon) {
		case 1: {
			menuDocGia2(t);
			break;
		}
		case 2: {
			menuDauSach(ds);
			break;
		}
		case 3: {
			SetBGColor(0);
			exit(0);
		}
		}
	}
}

