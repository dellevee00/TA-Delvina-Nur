#include <iostream>
using namespace std;

int main() {
    const int CABANG = 2;
    const int PRODUK = 6;
    int penjualan[CABANG][PRODUK];
    int total[PRODUK] = {0};

    for(int i = 0; i < CABANG; i++) {
        cout << "Masukkan jumlah penjualan untuk Cabang " << i+1 << ":\n";
        for(int j = 0; j < PRODUK; j++) {
            cout << "Produk " << j+1 << ": ";
            cin >> penjualan[i][j];
        }
        cout << endl;
    }

    for(int j = 0; j < PRODUK; j++) {
        for(int i = 0; i < CABANG; i++) {
            total[j] += penjualan[i][j];
        }
    }

    cout << "\nData penjualan tiap cabang:\n";
    for(int i = 0; i < CABANG; i++) {
        cout << "Cabang " << i+1 << ": ";
        for(int j = 0; j < PRODUK; j++) {
            cout << penjualan[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nTotal penjualan per produk di seluruh cabang:\n";
    for(int j = 0; j < PRODUK; j++) {
        cout << "Produk " << j+1 << ": " << total[j] << endl;
    }

    return 0;
}