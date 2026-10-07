#include <iostream>
#include <string>
using namespace std;

// Câu 1: 
struct NhanVien
{
    int maNV;
    string hoTen;
    string ngaySinh;
    double luong;
};

// Câu 2: 
void nhap(NhanVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";

        cout << "Ma nhan vien: ";
        cin >> a[i].maNV;
        cin.ignore();

        cout << "Ho ten: ";
        getline(cin, a[i].hoTen);

        cout << "Ngay sinh (dd/mm/yyyy): ";
        getline(cin, a[i].ngaySinh);

        cout << "Luong (trieu dong): ";
        cin >> a[i].luong;
    }
}

// Câu 3: 
void xuat(NhanVien a[], int n)
{
    cout << "\n===== DANH SACH NHAN VIEN =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        cout << "Ma NV: " << a[i].maNV << endl;
        cout << "Ho ten: " << a[i].hoTen << endl;
        cout << "Ngay sinh: " << a[i].ngaySinh << endl;
        cout << "Luong: " << a[i].luong << " trieu dong" << endl;
    }
}

// Câu 4: 
void bubbleSort(NhanVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].luong > a[j + 1].luong)
            {
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Câu 5: 
void timKiemNhiPhan(NhanVien a[], int n, double X)
{
    int left = 0;
    int right = n - 1;
    bool timThay = false;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].luong == X)
        {
           
            int i = mid;

            while (i >= 0 && a[i].luong == X)
            {
                i--;
            }

            i++;

            cout << "\n===== NHAN VIEN CO LUONG = "
                 << X << " TRIEU =====\n";

            
            while (i < n && a[i].luong == X)
            {
                cout << "\nMa NV: " << a[i].maNV << endl;
                cout << "Ho ten: " << a[i].hoTen << endl;
                cout << "Ngay sinh: " << a[i].ngaySinh << endl;
                cout << "Luong: " << a[i].luong
                     << " trieu dong" << endl;

                timThay = true;
                i++;
            }

            break;
        }
        else if (a[mid].luong < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!timThay)
    {
        cout << "\nKhong tim thay nhan vien co luong = "
             << X << " trieu dong.\n";
    }
}

// Câu 6: Hàm main
int main()
{
    int n;
    NhanVien a[100];


    cout << "Nhap so luong nhan vien n = ";
    cin >> n;


    nhap(a, n);


    cout << "\n\nDANH SACH VUA NHAP:";
    xuat(a, n);


    bubbleSort(a, n);

    cout << "\n\nDANH SACH SAU KHI SAP XEP:";
    xuat(a, n);

    double X;
    cout << "\nNhap muc luong X can tim: ";
    cin >> X;


    timKiemNhiPhan(a, n, X);

    return 0;
}
