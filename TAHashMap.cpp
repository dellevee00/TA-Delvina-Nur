#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node {
    int idTiket;
    string nama;
    Node* next;
};

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

int hashFunction(int idTiket) {
    return (idTiket % SIZE + SIZE) % SIZE;
}

void insert(Node* table[], int idTiket, const string& nama) {
    int index = hashFunction(idTiket);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->idTiket == idTiket) {
            cur->nama = nama;
            return;
        }
        cur = cur->next;
    }
    Node* baru = new Node;
    baru->idTiket = idTiket;
    baru->nama = nama;
    baru->next = table[index];
    table[index] = baru;
}

Node* search(Node* table[], int idTiket) {
    int index = hashFunction(idTiket);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->idTiket == idTiket) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void removeKey(Node* table[], int idTiket) {
    int index = hashFunction(idTiket);
    Node* cur = table[index];
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (cur->idTiket == idTiket) {
            if (prev == nullptr) {
                table[index] = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            cout << "Tiket ID " << idTiket << " berhasil dihapus.\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Tiket ID " << idTiket << " tidak ditemukan.\n";
}

void display(Node* table[]) {
    cout << "\nDaftar Tiket Konser Online:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Bucket " << i << ": ";
        Node* tmp = table[i];
        while (tmp != nullptr) {
            cout << "(" << tmp->idTiket << " : " << tmp->nama << ") -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Node* table[SIZE];
    initTable(table);

    insert(table, 101, "Jadin");
    insert(table, 111, "Aura");
    insert(table, 112, "Citra");
    insert(table, 102, "Aisha");
    insert(table, 125, "Amanda");
    insert(table, 121, "Nabilla");
    insert(table, 107, "Delvina");

    display(table);

    Node* hasil = search(table, 112);
    if (hasil != nullptr) {
        cout << "\nTiket ID 112 dimiliki oleh: " << hasil->nama << endl;
    } else {
        cout << "\nTiket ID 112 tidak ditemukan\n";
    }

    removeKey(table, 112);
    cout << "\nSetelah menghapus tiket ID 112:\n";
    display(table);

    return 0;
}