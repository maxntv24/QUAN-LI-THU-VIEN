#pragma once
#include <iostream>
#define MAX 100
using namespace std;
//=========Danh muc sach ( Danh sach lien ket don )==============
typedef struct DanhMucSach
{
	string maSach; // ma sach
	int trangThai; // (=0 : cho muon duoc) ,( =1 : da co doc gia muon), (=2 : sach da thanh ly)
	string vitri;
};
typedef struct DanhMucSach DMS;
struct nodeDanhMucSach
{
	DMS data;
	nodeDanhMucSach* pnext;
};
typedef struct nodeDanhMucSach nodeDMS;
typedef struct listDanhMucSach {
	nodeDMS* phead = NULL;
	nodeDMS* ptail = NULL;
};
typedef struct listDanhMucSach listDMS;

//=========== Dau Sach ( Mang con tro ) ================
struct dauSach {
	string ISBN;
	string tenSach;
	int soTrang;
	string tacGia;
	int namXuatBan;
	string theLoai;
	int soLuongMuon;
	listDanhMucSach dms;
};
struct listDauSach {
	int sl;
	dauSach* ds_DauSach[MAX];
};
typedef struct listDauSach listDS;

//================Danh sach muon tra ( Danh sach lien ket kep )===========
struct Date {
	int ngay;
	int thang;
	int nam;
};
typedef struct MuonTra {
	string maSach;
	Date ngayMuon;
	Date ngayTra;
	int trangThai; //(= 0 : dang muon), (=1 : da tra), (=2 : lam mat)
};
struct nodeMuonTra {
	MuonTra data;
	nodeMuonTra* pprev;
	nodeMuonTra* pnext;
};
typedef struct nodeMuonTra nodeMT;
struct listMuonTra {
	nodeMT* phead = NULL;
	nodeMT* ptail = NULL;
};
typedef struct listMuonTra listMT;

//============The Doc gia ( Cay nhi phan tim kiem )==========
struct DocGia {
	int maThe;
	string ho;
	string ten;
	string phai;
	int trangThai; //(=0 : the bi khoa), (=1 : the dang hoat dong)
	listMT mt;
};
typedef struct DocGia DG;
struct nodeDocGia {
	DG data;
	nodeDocGia* pleft;
	nodeDocGia* pright;
};
typedef struct nodeDocGia nodeDG;
typedef struct nodeDocGia* treeDG;
// QUA HAN
struct quaHan
{
	int maDG;
	string tenDG;
	string tenSach;
	Date ngayMuon;
	int soNgay;
};
struct nodeQuaHan
{
	quaHan data;
	nodeQuaHan* pnext;
};
typedef struct nodeQuaHan nodeQH;
struct listQuaHan
{
	nodeQH* phead=NULL;
	nodeQH* ptail=NULL;
};
typedef struct listQuaHan listQH;






