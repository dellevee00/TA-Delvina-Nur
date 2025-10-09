#include <iostream>
#include <string>
using namespace std;

int main() {
    const int n = 8;
    string drama[n] = {
        "Summer Strike",
        "My Liberation Notes",
        "Reply 1988",
        "Revenge of Others",
        "Hometown Cha-Cha-Cha",
        "Lovely Runner",
        "Move to Heaven",
        "Business Proposal"
    };

    string cari;
    int indeks = -1;

    cout << "Masukkan judul drama yang ingin dicari: ";
    getline(cin, cari);

    for (int i = 0; i < n; i++) {
        if (drama[i] == cari) {
            indeks = i;
            break;
        }
    }

    cout << "\n=== HASIL PENCARIAN ===\n";
    if (indeks != -1)
        cout << "Drama \"" << cari << "\" ditemukan di posisi ke-" << (indeks + 1) << endl;
    else
        cout << "Drama \"" << cari << "\" tidak ditemukan." << endl;

    return 0;
}