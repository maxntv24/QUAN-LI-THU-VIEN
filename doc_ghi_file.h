#pragma once
#include "ctdl.h"
#include "string"
#include<fstream>
#include "All_function.h"

void load_file_Doc_Gia(treeDG& t)
{
	ifstream in("DocGia.txt");
	DocGia data;
	int tam;
	in.ignore();
	while (!in.eof()) {
		in >> data.maThe;
		in.ignore();
		getline(in, data.ho, ',');
		getline(in, data.ten, ',');
		getline(in, data.phai, ',');
		in >> data.trangThai;
		in.ignore();
		themDocGia(t, data);
	}
	in.close();
}
void ghi_file_Doc_Gia(DocGia a) {
	ofstream out("DocGia.txt", ios_base::app);
	out << endl;
	out << a.maThe << "," << a.ho << "," << a.ten << "," << a.phai << "," << a.trangThai;
	out.close();
}
void ghi_file_tat_ca_doc_gia(treeDG t) {
	nodeDG* p;
	ofstream out("DocGia.txt", ios_base::out);
	while (t) {
		if (t->pleft == NULL) {
			out << endl << t->data.maThe << "," << t->data.ho << "," << t->data.ten << "," << t->data.phai << "," << t->data.trangThai;
			t = t->pright;
		}
		else {
			p = t->pleft;
			while (p->pright && p->pright != t) {
				p = p->pright;
			}
			if (p->pright == NULL) {
				p->pright = t;
				out << endl << t->data.maThe << "," << t->data.ho << "," << t->data.ten << "," << t->data.phai << "," << t->data.trangThai;
				t = t->pleft;
			}
			else {
				p->pright = NULL;
				t = t->pright;
			}
		}
	}
	out.close();
}
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
}