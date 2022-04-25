#pragma once
#include "my_lib.h"
#include "All_function.h"
#include "load_file.h"
#include "DoHoa.h"
char menu[][50] =
{
	"QUAN LI DOC GIA            ",
	"DAU SACH                   ",
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
void menuDocGia(treeDG &t) {
	ShowCur(0);
	bool flagDG = true;
	int chon, sum = 4;
	while (flagDG) {
		chon = MenuDong(menuDG, sum, 3, 40);
		switch (chon) {
		case 1: {
			textcolor(3);
			DG a;
			ifstream inMaDG("MaDG.txt");
			ofstream inTam("tam.txt");
			inMaDG >> a.maThe;
			cin >> a;
			themDocGia(t, a);
			int tam;
			/*while (inMaDG >> tam) {
				if (tam != a.maThe) {
					inTam << tam << " ";
				}
			}*/
			inMaDG.close();
			inTam.close();
			/*remove("MaDG.txt");
			rename("tam.txt", "MaDG.txt");*/
			system("cls");
			break;
		}
		case 2: {
			yDG = 10;
			SetBGColor(0);
			system("cls");
			BangDS_DocGia();
			gotoXY(0, 0);
			cout << "Nhap lua chon: ";
			int c;
			cin>>c;
			if (c == 1) {
				xuatDG_theoMa(t);
			}
			else
			{
				xuatDG_theoTen(t);
			}
			char x = _getch();
			break;
		}
		case 3: {
			SetBGColor(0);
			system("cls");
			cout << "Nhap ma the can xoa: ";
			int n;
			cin >> n;
			//xoaDocGia(t, n);
			cout << "Da xoa!!!";
			system("pause");
		}
		case 4: {
			SetBGColor(0);
			system("cls");
			cout << "Nhap ma the can thay doi: ";
			int n;
			cin >> n;
			hieuchinhDG(t, n);
			cout << "Da hieu chinh!!!";
			system("pause");
		}
		default: break;
		}
	}
}
void menuDocGia2(treeDG& t) {
	ShowCur(0);
	bool flagDG = true; // bien dung de ngat vong while va quay ve menu chinh
	int chon, sum = 4;
	while (flagDG) {
		//chon = MenuDong(menuDG, sum, 3, 40);
		yDG = 10;
		SetBGColor(0);
		system("cls");
		BangDS_DocGia();
		gotoXY(0, 0);
		cout << "Nhap lua chon: ";
		int c;
		cin >> c;
		if (c == 1) {
			xuatDG_theoMa(t);
		}
		else
		{
			xuatDG_theoTen(t);
		}
		char k = _getch();
		switch (k) {
		case 49: {
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
		case 50: {
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
		case 51: {
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
		case 27: {
			flagDG = false;
			break;
		}
		}
	}
}
void menuDauSach(listDauSach& ds) {
	ShowCur(0);
	int chon, sum = 4;
	while (1) {
		chon = MenuDong(menuDS, sum, 3, 40);
		switch (chon) {
		case 1: {
			/*textcolor(3);
			DG a;
			cin >> a;
			themDocGia(t, a);
			system("cls");*/
			break;
		}
		case 2: {
			SetBGColor(0);
			system("cls");
			gotoXY(0, 0);
			textcolor(12);
			cout << "ISBN" << setw(30) << "Ten Sach" << setw(15) << "So trang" << setw(15) << "Tac gia" << setw(15) << "Nam Xuat Ban" << setw(15) << "The loai" << endl;
			textcolor(14);
			xuatDauSach(ds);
			system("pause");
			break;
		}
		
		default: break;
		}
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

