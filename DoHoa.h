#pragma once
#include <iostream>
#include "my_lib.h"
using namespace std;
void BangDS_DocGia() { // bang danh sach doc gia
	textcolor(9);
	for (int i = 5; i <= 150; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
		gotoXY(i, 41);
		cout << char(223);
	}
	for (int i = 8; i <= 40; i++) { // ve canh doc
		gotoXY(5, i);
		cout << char(219);
		gotoXY(20, i);
		cout << char(219);
		gotoXY(60, i);
		cout << char(219);
		gotoXY(80, i);
		cout << char(219);
		gotoXY(90, i);
		cout << char(219);
		gotoXY(150, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(10, 8);
	cout << "MA THE";
	gotoXY(34, 8);
	cout << "HO VA TEN DEM";
	gotoXY(69, 8);
	cout << "TEN";
	gotoXY(84, 8);
	cout << "PHAI";
	gotoXY(110, 8);
	cout << "TRANG THAI";
}
void BangNhapDG() {
	for (int i = 160; i <= 200; i++) {// ve canh ngang
		gotoXY(i, 5);
		cout << char(220);
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 11);
		cout << char(220);
		gotoXY(i, 15);
		cout << char(220);
		gotoXY(i, 19);
		cout << char(220);
		gotoXY(i, 21);
		cout << char(220);
	}
	for (int i = 6; i <= 21; i++) {// ve canh doc
		gotoXY(160, i);
		cout << char(219);
		gotoXY(175, i);
		cout << char(219);
		gotoXY(200, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(163, 6);
	cout << "MA THE";
	gotoXY(165, 9);
	cout << "HO";
	gotoXY(165, 13);
	cout << "TEN";
	gotoXY(165, 17);
	cout << "PHAI";
	gotoXY(163, 20);
	cout << "TRANG THAI";
}
void XoaBangNhapDG() {
	textcolor(0);
	for (int x = 160; x <= 200; x++) {// ve canh ngang
		for (int y = 5; y <= 21; y++) {
			gotoXY(x, y);
			cout << " ";
		}
	}
}
void BangXoa() {
	for (int i = 160; i <= 200; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
		gotoXY(i, 11);
		cout << char(220);
	}
	for (int i = 8; i <= 11; i++) { // ve canh doc
		gotoXY(160, i);
		cout << char(219);
		gotoXY(180, i);
		cout << char(219);
		gotoXY(200, i);
		cout << char(219);
	}
	gotoXY(162,8);
	cout << "NHAP MA DOC GIA";
	gotoXY(162, 10);
	cout << "THONG BAO";
}
void BangHieuChinh() {
	textcolor(3);
	for (int i = 160; i <= 200; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
		gotoXY(i, 11);
		cout << char(220);
	}
	for (int i = 8; i <= 11; i++) { // ve canh doc
		gotoXY(160, i);
		cout << char(219);
		gotoXY(180, i);
		cout << char(219);
		gotoXY(200, i);
		cout << char(219);
	}
	gotoXY(162, 8);
	cout << "NHAP MA DOC GIA";
	gotoXY(162, 10);
	cout << "THONG BAO";
}
void xoaBangHieuChinh() {
	for (int i = 160; i <= 200; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << " ";
		gotoXY(i, 9);
		cout << " ";
		gotoXY(i, 11);
		cout << " ";
	}
	for (int i = 8; i <= 11; i++) { // ve canh doc
		gotoXY(160, i);
		cout << " ";
		gotoXY(180, i);
		cout << " ";
		gotoXY(200, i);
		cout << " ";
	}
	gotoXY(162, 8);
	cout << "                   ";
	gotoXY(162, 10);
	cout << "                   ";
	gotoXY(182, 8);
	cout << "                   ";
}
void BangDauSACH1() { // bang danh sach doc gia
	textcolor(9);
	for (int i = 5; i <= 150; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
		gotoXY(i, 41);
		cout << char(223);
	}
	for (int i = 8; i <= 40; i++) { // ve canh doc
		gotoXY(5, i);
		cout << char(219);
		gotoXY(22, i);
		cout << char(219);
		gotoXY(60, i);
		cout << char(219);
		gotoXY(75, i);
		cout << char(219);
		gotoXY(100, i);
		cout << char(219);
		gotoXY(116, i);
		cout << char(219);
		gotoXY(150, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(10, 8);
	cout << "ISBN";
	gotoXY(34, 8);
	cout << "TEN SACH";
	gotoXY(64, 8);
	cout << "SO TRANG";
	gotoXY(84, 8);
	cout << "TAC GIA";
	gotoXY(102, 8);
	cout << "NAM XUAT BAN";
	gotoXY(130, 8);
	cout << "THE LOAI";
}
void BangNhapDauSach() {
	system("cls");
	textcolor(3);
	for (int i = 50; i <= 120; i++) {
		gotoXY(i, 10);
		cout << char(220);
		gotoXY(i, 22);
		cout << char(220);
	}
	for (int i = 11; i <= 22; i++) {
		gotoXY(50, i);
		cout << char(219);
		gotoXY(120, i);
		cout << char(219);
	}
	textcolor(12);
	gotoXY(52, 11);
	cout << "ISBN: ";
	gotoXY(52, 13);
	cout << "Ten Sach: ";
	gotoXY(52, 15);
	cout << "So Trang: ";
	gotoXY(52, 17);
	cout << "Tac Gia: ";
	gotoXY(52, 19);
	cout << "Nam Xuat Ban: ";
	gotoXY(52, 21);
	cout << "The Loai: ";
}
void BangDauSACH2() { // bang danh sach doc gia
	textcolor(9);
	for (int i = 5; i <= 190; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
		gotoXY(i, 41);
		cout << char(223);
	}
	for (int i = 8; i <= 40; i++) { // ve canh doc
		gotoXY(5, i);
		cout << char(219);
		gotoXY(22, i);
		cout << char(219);
		gotoXY(60, i);
		cout << char(219);
		gotoXY(75, i);
		cout << char(219);
		gotoXY(100, i);
		cout << char(219);
		gotoXY(116, i);
		cout << char(219);
		gotoXY(150, i);
		cout << char(219);
		gotoXY(166, i);
		cout << char(219);
		gotoXY(190, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(10, 8);
	cout << "ISBN";
	gotoXY(34, 8);
	cout << "TEN SACH";
	gotoXY(64, 8);
	cout << "SO TRANG";
	gotoXY(84, 8);
	cout << "TAC GIA";
	gotoXY(102, 8);
	cout << "NAM XUAT BAN";
	gotoXY(130, 8);
	cout << "THE LOAI";
	gotoXY(152, 8);
	cout << "SO LUONG CON";
	gotoXY(175, 8);
	cout << "MA SACH";
}
void BangNhap(string s) {
	textcolor(9);
	for (int i = 160; i <= 200; i++) {// ve canh ngang
		gotoXY(i, 5);
		cout << char(220);
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
	}
	for (int i = 6; i <= 9; i++) {// ve canh doc
		gotoXY(160, i);
		cout << char(219);
		gotoXY(178, i);
		cout << char(219);
		gotoXY(200, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(162, 6);
	cout << s;
	gotoXY(162, 8);
	cout << "TRANG THAI";
	
}
void XoaBang() {
	textcolor(0);
	for (int x = 160; x <= 200; x++) {// ve canh ngang
		for (int y = 5; y <= 21; y++) {
			gotoXY(x, y);
			cout << " ";
		}
	}
}
void BangNhapSACH() {
	textcolor(9);
	for (int i = 160; i <= 200; i++) {// ve canh ngang
		gotoXY(i, 11);
		cout << char(220);
		gotoXY(i, 13);
		cout << char(220);
		gotoXY(i, 15);
		cout << char(220);
	}
	for (int i = 12; i <= 15; i++) {// ve canh doc
		gotoXY(160, i);
		cout << char(219);
		gotoXY(178, i);
		cout << char(219);
		gotoXY(200, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(162, 12);
	cout << "MA SACH";
	gotoXY(162, 14);
	cout << "VI TRI";

}
void XoaBangSACH() {
	textcolor(0);
	for (int x = 160; x <= 200; x++) {// ve canh ngang
		for (int y = 11; y <= 15; y++) {
			gotoXY(x, y);
			cout << " ";
		}
	}
}