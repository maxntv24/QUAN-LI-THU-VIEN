#pragma once
#include "ctdl.h"
#include "string"
#include <fstream>
#include "All_function.h"
//=======Doc gia===============
void load_file_Doc_Gia(treeDG& t)
{
	ifstream in("DocGia.txt");
	MuonTra x;
	DocGia data;
	int tam;
	int n;
	in >> n;
	for(int i=0;i<n;i++) {
		in >> data.maThe;
		in.ignore();
		getline(in, data.ho, ',');
		getline(in, data.ten, ',');
		getline(in, data.phai, ',');
		in >> data.trangThai;
		in.ignore();
		in >> tam;
		in.ignore();
		themDocGia(t, data);
		treeDG p = timDG_theo_ma(t, data.maThe);
		for (int i = 0; i < tam; i++)
		{
			getline(in, x.maSach, ',');
			in >> x.trangThai;      in.ignore();
			in >> x.ngayMuon.ngay;  in.ignore();
			in >> x.ngayMuon.thang; in.ignore();
			in >> x.ngayMuon.nam;   in.ignore();
			in >> x.ngayTra.ngay;   in.ignore();
			in >> x.ngayTra.thang;  in.ignore();
			in >> x.ngayTra.nam;    in.ignore();
			themMuonTra(p->data.mt, khoitaoMuonTra(x));
		}
	}
	in.close();
}
void ghi_file_Doc_Gia(treeDG a, ofstream& out) {
	if (a) {
		out << a->data.maThe << ',';
		out << a->data.ho << ',';
		out << a->data.ten << ',';
		out << a->data.phai << ',';
		out << a->data.trangThai << endl;
		out << so_sach_DG_muon(a->data) << endl;
		for (nodeMT* p = a->data.mt.phead; p != NULL; p = p->pnext)
		{
			out << p->data.maSach << ',';
			out << p->data.trangThai << ',';
			out << p->data.ngayMuon.ngay << '/';
			out << p->data.ngayMuon.thang << '/';
			out << p->data.ngayMuon.nam << ',';
			out << p->data.ngayTra.ngay << '/';
			out << p->data.ngayTra.thang << '/';
			out << p->data.ngayTra.nam << endl;
		}
		ghi_file_Doc_Gia(a->pleft, out);
		ghi_file_Doc_Gia(a->pright, out);
	}
}
void GHI_FILE_DS_DG(treeDG t)
{
	ofstream out("DOCGIA.txt");
	int n = DemSoDG(t);
	out << n << endl;
	ghi_file_Doc_Gia(t, out);
	out.close();
}
//void ghi_file_tat_ca_doc_gia(treeDG t) { // dùng khử đệ qui
//	nodeDG* p;
//	ofstream out("DocGia.txt", ios_base::out);
//	while (t) {
//		if (t->pleft == NULL) {
//			out << endl << t->data.maThe << "," << t->data.ho << "," << t->data.ten << "," << t->data.phai << "," << t->data.trangThai;
//			t = t->pright;
//		}
//		else {
//			p = t->pleft;
//			while (p->pright && p->pright != t) {
//				p = p->pright;
//			}
//			if (p->pright == NULL) {
//				p->pright = t;
//				out << endl << t->data.maThe << "," << t->data.ho << "," << t->data.ten << "," << t->data.phai << "," << t->data.trangThai;
//				t = t->pleft;
//			}
//			else {
//				p->pright = NULL;
//				t = t->pright;
//			}
//		}
//	}
//	out.close();
//}
//========Dau Sach=============
void load_file_Dau_Sach(listDauSach& DS)
{
	ifstream in("DAU_SACH.txt");
	dauSach data;
	DanhMucSach x;
	int slDS, slSach;
	in >> slDS;
	in.ignore();
	for (int i = 0; i < slDS; i++) {
		getline(in, data.ISBN, ',');
		getline(in, data.tenSach, ',');
		in >> data.soTrang;
		in.ignore();
		getline(in, data.tacGia, ',');
		in >> data.namXuatBan;
		in.ignore();
		getline(in, data.theLoai, ',');
		in >> data.soLuongMuon;
		themDauSach(DS, data);
		in >> slSach;
		in.ignore();
		int vitri = TIM_DS_THEO_MA(DS,data.ISBN);
		for (int i = 0; i < slSach; i++)
		{
			getline(in, x.maSach, ',');
			in >> x.trangThai;
			in.ignore();
			getline(in, x.vitri);
			themSach(DS.ds_DauSach[vitri]->dms, khoitaoDMS(x));
		}
	}
	in.close();
}
void ghi_file_Dau_Sach(listDauSach ds) {
	ofstream out("DAU_SACH.txt");
	out << ds.sl << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		out << ds.ds_DauSach[i]->ISBN << ',';
		out << ds.ds_DauSach[i]->tenSach << ',';
		out << ds.ds_DauSach[i]->soTrang << ',';
		out << ds.ds_DauSach[i]->tacGia << ',';
		out << ds.ds_DauSach[i]->namXuatBan << ',';
		out << ds.ds_DauSach[i]->theLoai << ',';
		out << ds.ds_DauSach[i]->soLuongMuon << endl;
		out << tong_so_sach(*ds.ds_DauSach[i]) << endl;
		for (nodeDMS* p = ds.ds_DauSach[i]->dms.phead; p != NULL; p = p->pnext)
		{
			out << p->data.maSach << ',';
			out << p->data.trangThai << ',';
			out << p->data.vitri << endl;
		}
	}
	out.close();
}
