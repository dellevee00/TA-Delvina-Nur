#include <iostream>
#include <string>
using namespace std;

const int MAX = 12;  
string queueLagu[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear == MAX - 1);
}

void enqueue(string lagu) {
    if (isFull()) {
        cout << "Playlist penuh! Tidak bisa menambahkan lagu: " << lagu << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queueLagu[rear] = lagu;
    cout << "Lagu \"" << lagu << "\" berhasil ditambahkan ke playlist.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Playlist kosong! Tidak ada lagu untuk diputar.\n";
        return;
    }
    cout << "Memutar lagu: \"" << queueLagu[front] << "\" ...\n";
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void tampilkanPlaylist() {
    if (isEmpty()) {
        cout << "Playlist kosong.\n";
        return;
    }
    cout << "\nDaftar Lagu di Playlist:\n";
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". " << queueLagu[i] << endl;
    }
    cout << endl;
}

int main() {
    int pilihan;
    string lagu;

    do {
        cout << "\n=== MENU PLAYLIST MUSIK OFFLINE ===\n";
        cout << "1. Tambah Lagu ke Playlist\n";
        cout << "2. Putar Lagu Berikutnya\n";
        cout << "3. Lihat Playlist\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul lagu: ";
                getline(cin, lagu);
                enqueue(lagu);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilkanPlaylist();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan playlist offline!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    return 0;
}