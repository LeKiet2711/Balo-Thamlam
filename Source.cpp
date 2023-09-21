//Bai toan BALO by Kiet Le
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctime>
#include<stdlib.h>

struct Balo {
	int TL, GT;
	float dongia;
};

typedef Balo bl;

void NhapBalo(bl a[], int& n) {
	printf("\nNhap so luong cac loai do vat:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("\nTrong luong cua vat %d: ", i);
		scanf("%d", &a[i].TL);
		printf("\nNhap Gia tri cua vat %d: ", i);
		scanf("%d", &a[i].GT);
	}
}



void XuatMang(bl a[], int n) {
	printf("\t%s\t\t %-25s %-15s %-15s\n ", "Loai do vat", "Trong luong", "Gia tri", "Don gia");
	for (int i = 0; i < n; i++) {
		a[i].dongia = (float)(a[i].GT / a[i].TL);
		printf("\t%d\t\t\t %-35d %-10d %-15.2f", i, a[i].TL, a[i].GT, a[i].dongia);
		printf("\n");
	}
}

void SapxepDongia(bl a[], int n) {
	bl b;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i].dongia < a[j].dongia) {
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
}

void BovaoBalo(bl a[], int n) {
	int kg, dem;
	printf("\nNhap khoi luong balo:");
	scanf("%d", &kg);

	for (int i = 0; i < n; i++) {
		dem = 0;
		if (a[i].TL < kg) {
			//Lấy số lượng cho phép kg/a[i].TL, lấy giá trị đầu tiên lớn nhất và thỏa mãn trọng lượng của balo
			/*VD: 3.4 = > 0.4 là phần dư còn lại của balo và 3 là số lượng cho phép để bỏ vào balo = > balo 17kg trọng lượng gói hàng 1 là 5kg thì j = 3(.4) với 0.4 là
			2kg còn lại của balo và 3 là số lượng có thể bỏ vào balo
			- Ngược lại với kg=2 và trọng lượng vật là 5 thì j=0.(..) => không thể bỏ vào balo*/
			for (int j = (kg / a[i].TL); j > 0; j--) {
				//Thay vì chạy từng trường hợp kiểm tra xem trọng lượng đủ để bỏ vào balo hay không thì kiểm tra từ trên xuống và lấy 1 lần
				if (j * a[i].TL <= kg) {
					//dem là số vật lấy được
					dem = j;
					kg -= j * a[i].TL;
					break;
				}

			}

		}
		printf("%d vat %d\n", dem, i);
	}
	printf("\nKhoi luong con lai cua balo la %d", kg);
}

int main() {
	bl a[100];
	int n;
	NhapBalo(a, n);
	//XuatMang(a, n);
	SapxepDongia(a, n);
	XuatMang(a, n);
	BovaoBalo(a, n);


	return 0;
}