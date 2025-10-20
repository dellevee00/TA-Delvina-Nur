#include <iostream>
using namespace std;

struct Node {
    int berat;          
    Node* left;
    Node* right;
    Node(int b) : berat(b), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int berat) {
    if (!root) return new Node(berat);
    if (berat < root->berat)
        root->left = insertNode(root->left, berat);
    else if (berat > root->berat)
        root->right = insertNode(root->right, berat);
    return root;
}

bool searchNode(Node* root, int berat) {
    if (!root) return false;
    if (root->berat == berat) return true;
    if (berat < root->berat)
        return searchNode(root->left, berat);
    else
        return searchNode(root->right, berat);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->berat << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->berat << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->berat << " ";
}

int main() {
    Node* root = nullptr;
    int pilihan, berat;

    do {
        cout << "\n=== SISTEM DATA BERAT PAKET EKSPEDISI ===\n";
        cout << "1. Tambah data berat paket\n";
        cout << "2. Cari berat paket\n";
        cout << "3. Tampilkan traversal Inorder\n";
        cout << "4. Tampilkan traversal Preorder\n";
        cout << "5. Tampilkan traversal Postorder\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan berat paket (kg): ";
                cin >> berat;
                root = insertNode(root, berat);
                cout << "Data berat paket berhasil dimasukkan!\n";
                break;

            case 2:
                cout << "Masukkan berat paket yang ingin dicari: ";
                cin >> berat;
                if (searchNode(root, berat))
                    cout << "Paket dengan berat " << berat << " kg ditemukan.\n";
                else
                    cout << "Paket dengan berat " << berat << " kg tidak ditemukan.\n";
                break;

            case 3:
                cout << "\nTraversal Inorder (ringan ke berat): ";
                inorder(root);
                cout << "\n";
                break;

            case 4:
                cout << "\nTraversal Preorder: ";
                preorder(root);
                cout << "\n";
                break;

            case 5:
                cout << "\nTraversal Postorder: ";
                postorder(root);
                cout << "\n";
                break;

            case 6:
                cout << "Terima kasih, program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}