#pragma once
#include "my_lib.h"
#include "All_function.h"
#include "doc_ghi_file.h"
#include "DoHoa.h"
char menu[][50] =
{
	"QUAN LI DOC GIA            ",
	"QUAN LI DAU SACH           ",
	"QUAN LI MUON TRA           ",
	"DANH SACH DOC GIA QUA HAN  ",
	"TOP 10 SACH MUON NHIEU NHAT",
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
		huongDanDG();
		xuatDG_theoMa(t,check);
		char k;
		if (check == NULL) {
			k=_getch();
		}
		else k = check;
		switch (k) {
		case PHIM1:{  // xuat theo ten tang dan
			check = NULL;
			system("cls");
			xuatDG_theoTen(t,check);
			break;
		}
		case PHIM2:{  // them doc gia
			check = NULL;
			textcolor(3);
			DG a;
			ifstream inMaDG("MaDG.txt");
			ofstream inTam("tam.txt");
			inMaDG >> a.maThe;
			check=nhapDG(a);
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
			GHI_FILE_DS_DG(t);
			system("cls");
			break;
		}
		case PHIM3: {   // xoa doc gia
			check = NULL;
			ShowCur(1);
			textcolor(3);
			BangXoa();
			textcolor(14);
			int x=0;
			check = nhapSo(182, 8, x);
			if (check == ESC) break;
			gotoXY(182, 10);
			cout << "CHAC CHAN (y/n)";
			char c;
			do {
				c = _getch();
				if (c == 'y') {
					int check = 0;
					gotoXY(182, 10);
					xoaDocGia(t, x, check);
					if (check == 1) {
						GHI_FILE_DS_DG(t);
						cout << "DA XOA !!!     ";
						ofstream out("MaDG.txt", ios_base::app);
						out << x << " ";
						out.close();
					}
					else if (check==0) cout << "MA THE KHONG TON TAI";
				}
				else if (c == 'n') {
					gotoXY(182, 10);
					cout << "DA HUY !!!      ";
					break;
				}
			} while (c != 'y');
			c = _getch();
			check = NULL;
			break;
		}
		case PHIM4: {     // hieu chinh doc gia
			check = NULL;
			ShowCur(1);
			BangHieuChinh();
			int n=0;
			gotoXY(182, 8);
			check = nhapSo(182, 8, n);
			if (check == ESC) break;
			xoaBangHieuChinh();
			check=hieuchinhDG(t, n);
			XoaBangNhapDG();
			BangHieuChinh();
			textcolor(6);
			gotoXY(182, 8);
			cout << n;
			gotoXY(182, 10);
			if(check!=ESC){
				cout << "Da hieu chinh!!!";
				GHI_FILE_DS_DG(t);
				char c = _getch();
			}
			break;
		}
		case ESC: {  //thoat
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
		system("cls");
		SetBGColor(0);
		HuongDanDauSach();
		xuatDauSach(ds,check);
		char k;
		if (check == NULL) {
			k = _getch();
		}
		else k = check;
		switch (k){
		case PHIM1: {   // nhap dau sach
			check = NULL;
			nhapDS(ds);
			ghi_file_Dau_Sach(ds);
			break;
		}
		case PHIM2: {    //tim sach theo ten sach
			check = NULL;
			BangNhap("NHAP TEN SACH");
			string s = "";
			check = nhapChu(180,6,s);
			TIM_DS_THEO_TEN(ds,s);
			break;
		}
		case PHIM3: {  // them sach vao dau sach
			check = NULL;
			themSach(ds);
			ghi_file_Dau_Sach(ds);
			break;
		}
		case ESC: {
			flagDS = false;
			break;
		}
		}
	}
}
void menuMuonTra(treeDG& t,listDauSach& l) {
	ShowCur(0);
	char check = NULL;
	bool flagDG = true; // bien dung de ngat vong while va quay ve menu chinh
	int chon, sum = 4;
	while (flagDG) {
		SetBGColor(0);
		system("cls");
		SetBGColor(0);
		textcolor(14);
		HuongDanMuonTra();
		xuatDG_theoMa(t, check);
		if (check == ESC) {
			return;
		}
		BangNhap("NHAP MA THE");
		int mathe=0;
		char check = NULL;
		check = nhapSo(180, 6, mathe);
		treeDG p= timDG_theo_ma(t, mathe);
		if (p != NULL) {
			xoaBangDG();
		}
		else {
			gotoXY(180, 8);
			cout << "MA THE KHONG TON TAI";
			_getch();
			continue;
		}
		xuatSachDaMuon(p->data,check);
		char k;
		if (check == NULL) {
			k = _getch();
		}
		else k = check;
		switch (k) {
		case PHIM1: {    // muon sach
			check = NULL;
			if (demSachDangMuon(p->data,1) >= 3) {
				gotoXY(180, 8);
				cout << "KHONG THE MUON HON 3 CUON";
				check=_getch();
			}
			else if (ktQuaHan(p->data) == -1) {
				gotoXY(180, 8);
				cout << "CO SACH MUON QUA HAN";
				check = _getch();
			}
			else {
				check=muonSACH(p,l);
				ghi_file_Dau_Sach(l);
				GHI_FILE_DS_DG(t);
				check = _getch();
			}
			break;
		}
		case PHIM2: {   // tra sach
			check = NULL;
			if (demSachDangMuon(p->data, 1) == 0) {
				gotoXY(180, 8);
				cout << "CHUA MUON SACH NAO";
				check = _getch();
			}
			else {
				traSach(p, l);
				ghi_file_Dau_Sach(l);
				GHI_FILE_DS_DG(t);
				check = _getch();
			}
			break;
		}
		case PHIM3: {   // lam mat sach
			check = NULL;
			if (demSachDangMuon(p->data, 1) == 0) {
				gotoXY(180, 8);
				cout << "CHUA MUON SACH NAO";
				check = _getch();
			}
			else {
				lamMatSach(p, l);
				ghi_file_Dau_Sach(l);
				GHI_FILE_DS_DG(t);
				check = _getch();
			}
			break;
		}
		case ESC: {
			flagDG = false;
			break;
		}
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
	int chon;
	while (1) {
		ShowCur(0);
		system("cls");
		HuongDan(14, 5, 2, 13, 2, 7, 3, "ESC: Thoat");
		HuongDan(14, 175, 2, 15, 2, 177, 3, "Enter: Chon");
		chon = MenuDong(menu, 5,15,80);
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
			menuMuonTra(t, ds);
			break;
		}
		case 4: {
			dsQuaHan(ds,t);
			break;
		}
		case 5: {
			top10sach(ds);
			_getch();
			break;
		}
		case ESC: {
			exit(0);
		}
		}
	}
}

