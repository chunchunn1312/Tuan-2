#include<iostream>
#include<fstream>
using namespace std;
typedef struct nhanvien NhanVien;
struct nhanvien
{
	string nhanVienId;
	string hoTen;
	int tuoi;
	int luong;	
};

NhanVien nv[100];

void menu();
void lcmenu (NhanVien nv[], int n);
void nhapNV (NhanVien nv[], int n);
void xoaNV (NhanVien nv[], int n);
void suaNV (NhanVien nv[], int n);
void timNV (NhanVien nv[], int n);
void inputNV (NhanVien nv[], int n);

//GIAO DIEN MENU
void menu()
{
	
	int lc;
	cout<<"--------------MENU--------------"<<endl;
	cout<<"1. Nhap thong tin nhan vien"<<endl;
	cout<<"2. Xoa nhan vien"<<endl;
	cout<<"3. Sua thong tin nhan vien"<<endl;
	cout<<"4. Tim thong tin nhan vien"<<endl;
	cout<<"5. In danh sach nhan vien"<<endl;
}

//Lua chon cua menu
void lcmenu(NhanVien nv[], int n)
{
	int lc;
	cout<<"\nNHAP LUA CHON: ";
	cin>>lc;
		switch (lc)
		{
			case 1:
				nhapNV(nv, n);
				lcmenu(nv, n);
				break;
			case 2:
				xoaNV(nv, n);
				lcmenu(nv, n);
				break;
			case 3:
				suaNV(nv, n);
				lcmenu(nv, n);
				break;
			case 4:
				timNV(nv, n);
				lcmenu(nv, n);
				break;	
			case 5:
				inputNV(nv, n);
				lcmenu(nv, n);
				break;
		}
}

//Nhap nhan vien
void nhapNV (NhanVien nv[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		cout<<"Nhap ma nhan vien: "<<endl;
		cin>>nv[i].nhanVienId;
		cout<<"Nhap ho ten nhan vien: "<<endl;
		cin>>nv[i].hoTen;
		cout<<"Nhap tuoi nhan vien: "<<endl;
		cin>>nv[i].tuoi;
		cout<<"Nhap tien luong nhan vien: "<<endl;
		cin>>nv[i].luong;
	}
}

//Xuat nhan vien
void xuatNV (NhanVien nv[], int ii )
{
	cout<<"Ma nhan vien: "<<nv[ii].nhanVienId<<endl;
	cout<<"Ho ten nhan vien: "<<nv[ii].hoTen<<endl;
	cout<<"Tuoi nhan vien: "<<nv[ii].tuoi<<endl;
	cout<<"Tien luong: "<<nv[ii].luong<<endl;	
}

//Xoa nhan vien
void xoaNV (NhanVien nv[], int n)
{
	string id;
	cout<<"Nhap ma nhan vien: ";
	cin.ignore(); //xoa bo nho dem
	getline(cin, id);
	for (int i=0;i<n;i++)
	{
		if (nv[i].nhanVienId==id)
		{
			for (int j=i; j<n; j++)
			{
				nv[j]=nv[j+1];
				cout<<"Da xoa thong tin nhan vien"<<endl;
			}
		}
	}
}

//Sua nhan vien
void suaNV (NhanVien nv[], int n)
{
	string id;
	cout<<"Nhap ma nhan vien: ";
	cin.ignore();
	getline(cin, id);
	for (int i=0;i<n;i++)
	{
		if (nv[i].nhanVienId==id)
		{
		cout<<"Nhap ho ten nhan vien: "<<endl;
		cin>>nv[i].hoTen;
		cout<<"Nhap tuoi nhan vien: "<<endl;
		cin>>nv[i].tuoi;
		cout<<"Nhap tien luong nhan vien: "<<endl;
		cin>>nv[i].luong;
		}
	}
}

//Tim thong tin nhan vien
void timNV (NhanVien nv[], int n)
{
	string id;
	int ii;
	cout << "Nhap ma nhan vien : ";
	cin >> id;
	for (int i = 0; i < n; i++)
	{
		if (id==nv[i].nhanVienId)
		{
			ii = i;
			xuatNV (nv, ii);
		}
	}
}

//In danh sach nhan vien
void inputNV (NhanVien nv[], int n)
{

	ofstream a("output1.dat",ios::out|ios::binary);
	for (int i=0; i<n; i++)
	{
		a<<nv[i].nhanVienId<<endl;
		a<<nv[i].hoTen<<endl;
		a<<nv[i].tuoi<<endl;
		a<<nv[i].luong<<endl;
	}
	a.close();
	cout<<"Da ghi danh sach nhan vien vao file "<<endl;
	
}

int main()
{
	int n;
	cout<<"Nhap so luong nhan vien: ";
	cin>>n;
	menu();
	lcmenu(nv,n);
	return 0;
}
