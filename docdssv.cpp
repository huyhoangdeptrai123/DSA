
#include<fstream>
#include <windows.h>
#include"mang.h"
#include"dslkdon.h"
#include"dslkdoi.h"
#include"dslkvong.h"
#include<string>
void clearScreen() {
	system("cls");
}
int menu() {
	cout << " ---------------------------------------------------------" << endl;
	cout << "|                     MENU                                |" << endl;
	cout << "|---------------------------------------------------------|" << endl;
	cout << "|             Chuc nang               |    Phim can go    |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "|       In danh sach sinh vien        |         1         |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "|          Them sinh vien             |         2         |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "|         Ket thuc chuon trinh        |         0         |" << endl;
	cout << " ---------------------------------------------------------" << endl;
	int chose;
	cin >> chose;
	return chose;
}
int main(){
	mangSv arr;
	node_dslk_don *dslk_don = NULL;
	node_dslk_kep *dslk_kep = NULL;
	node_dslk_vong *dslk_vong= NULL;
	cout << " ---------------------------------------------------------" << endl;
	cout << "|                     MENU                                |" << endl;
	cout << "|---------------------------------------------------------|" << endl;
	cout << "|          Kieu luu tru               |    Phim can go    |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "|        Luu tru bang mang            |         1         |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "| Luu tru bang danh sach lien ket don |         2         |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "| Luu tru bang danh sach lien ket doi |         3         |" << endl;
	cout << "|-------------------------------------|-------------------|" << endl;
	cout << "| Luu tru bang danh sach lien ket vong|         4         |" << endl;
	cout << " ---------------------------------------------------------" << endl;
	int ptlt = 0;
	cout << "Nhap phuong thuc luu tru: "; 
	cin >> ptlt;
	clearScreen();
	ifstream ip("D:\\DSSV.csv");
	if(!ip.is_open()) cout <<" Loi: Khong mo duoc file";
	string stt;
	string mssv;
	string holot;
	string ten;
	string malop;
	string diem;
	while(!ip.eof()){ //Kiem tra file co du lieu khong
		getline(ip,stt,',');
		while ((stt[0] < '0' || stt[0] > '9') && stt.length() != 0) stt.erase(0, 1); // xoa ki tu dau tien
		if (stt == "") continue; 
		getline(ip,mssv,',');
		getline(ip,holot,',');
		getline(ip,ten,',');
		getline(ip,malop,',');
		getline(ip,diem,'\n');
		
		if (ptlt == 1) {
			info sv;
			sv.setinfo(stt,mssv,holot,ten,malop,diem);
			arr.addDATA(sv);	
		}
		else if (ptlt == 2) { 
			Sinhvien_dslk_don sv_dslk_don;
			sv_dslk_don.setinfo(stt,mssv,holot,ten,malop,diem);
			themcuoi_dslk_don(dslk_don, sv_dslk_don);
		}
		else if(ptlt == 3){
			Sinhvien_dslk_kep sv_dslk_kep;
			sv_dslk_kep.setinfo(stt, mssv, holot, ten, malop, diem);
			themcuoi_dslk_kep(dslk_kep, sv_dslk_kep);
		}
		else if(ptlt ==4){
			Sinhvien_dslk_vong sv_dslk_vong;
		 	sv_dslk_vong.setinfo(stt, mssv, holot, ten, malop, diem);
			themcuoi_dslkv(dslk_vong,sv_dslk_vong);
		}
	}
	
	
	int choose = -1;
	while (choose != 0) {
		clearScreen();
		choose = menu();
		if (choose == 1) {
			while (choose != 9) {
				clearScreen();
				if (ptlt == 1) {
					arr.duyet_mang();	
				}     
				else if(ptlt == 2){
					duyet_dslk_don(dslk_don);
				}  
				else if (ptlt == 3){
					duyet_dslk_kep(dslk_kep);
				} 
				else if (ptlt ==4){
					duyet_dslk_vong(dslk_vong);
				}  
				cout << "Muon tro ve, nhan phim 9: ";
				cin >> choose;
			}
		}
	}
	ip.close();
	
}
