#include<iostream>
#include<string.h>
using namespace std;
struct info{
	string stt;
	string mssv;
	string ho;
	string ten;
	string lop;
	string diem;
	void pr() {
		cout << this->stt << " " << this->mssv << " " << this->ho << " " << this->ten << " " << this->lop << " " << this->diem;
	}
	void setinfo(string stt,string mssv, string ho, string ten,string lop, string diem) {
		this->stt= stt;
		this->mssv=mssv;
		this->ho=ho;
		this->ten=ten;
		this->lop=lop;
		this->diem=diem;
	}
};

class mangSv{
	public:
		int numberOfSv;
		info *sv;
	public:
		mangSv() {
			this->numberOfSv = 0;
		}
		void addDATA(info sv) {
			this->numberOfSv = this->numberOfSv + 1;
			info *newArr = new info [this->numberOfSv];
			for (int i = 0; i < this->numberOfSv - 1; ++i) {
				newArr[i] = this->sv[i];
			}
			newArr[this->numberOfSv - 1] = sv;
			this->sv = newArr;
		};
		void duyet_mang() {
			for (int i = 0; i < this->numberOfSv; ++i) {
				this->sv[i].pr();
				cout << endl;
			}
		}
};
