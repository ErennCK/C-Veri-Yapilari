#include "BinaryTree.h"

// Kurucu fonksiyon: root d���m�n� NULL olarak ba�lat�r.
BinaryTree::BinaryTree() : root(NULL) {}

// insert: A�aca bir de�er ekler.
// Bu fonksiyon, insertRecursive fonksiyonunu kullanarak a�aca bir de�er ekler.
void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

// insertRecursive: A�aca de�er eklemeyi sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, a�ac�n k�k�nden ba�layarak uygun pozisyonu bulur ve yeni d���m� ekler.
BinaryTree::Node* BinaryTree::insertRecursive(Node* root, int value) {
    // E�er k�k NULL ise, yeni bir d���m olu�tur ve geri d�nd�r.
    if (root == NULL) {
        return new Node(value);
    }

    // E�er eklenen de�er k�k d���m�n de�erinden k���kse, sol alt a�a�ta ekle.
    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    }
    // E�er eklenen de�er k�k d���m�n de�erinden b�y�kse, sa� alt a�a�ta ekle.
    else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    // De�eri ekledikten sonra k�k� geri d�nd�r.
    return root;
}

// remove: A�a�tan bir de�eri ��kar�r.
// Bu fonksiyon, removeRecursive fonksiyonunu kullanarak a�actan bir de�eri ��kar�r.
void BinaryTree::remove(int value) {
    root = removeRecursive(root, value);
}

// removeRecursive: A�a�tan de�er ��karmay� sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, a�ac�n k�k�nden ba�layarak ��kar�lacak de�eri bulur ve ��kar�r.
BinaryTree::Node* BinaryTree::removeRecursive(Node* root, int value) {
    // E�er k�k NULL ise, do�rudan geri d�nd�r.
    if (root == NULL) {
        return root;
    }

    // E�er ��kar�lacak de�er k�k d���m�n de�erinden k���kse, sol alt a�a�ta ara.
    if (value < root->data) {
        root->left = removeRecursive(root->left, value);
    }
    // E�er ��kar�lacak de�er k�k d���m�n de�erinden b�y�kse, sa� alt a�a�ta ara.
    else if (value > root->data) {
        root->right = removeRecursive(root->right, value);
    }
    // E�er de�er k�k d���m�n de�erine e�itse, bu d���m� ��kar.
    else {
        // D���m�n bir ya da hi� �ocu�u yoksa.
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // D���m�n iki �ocu�u varsa, sa� alt a�ac�n en k���k d���m�n� bul ve k�k yap.
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeRecursive(root->right, temp->data);
    }

    return root;
}

// minValueNode: Sa� alt a�ac�n en k���k d���m�n� bulur.
// Bu fonksiyon, verilen d���mden ba�layarak en sol d���m� bulur.
BinaryTree::Node* BinaryTree::minValueNode(Node* node) {
    Node* current = node;
    // En sol d���me ula�ana kadar ilerle.
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// clear: A�ac� temizler.
// Bu fonksiyon, clearRecursive fonksiyonunu kullanarak a�ac�n t�m d���mlerini siler.
void BinaryTree::clear() {
    clearRecursive(root);
    root = NULL;
}

// clearRecursive: A�ac� temizlemeyi sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, a�ac�n t�m d���mlerini siler.
void BinaryTree::clearRecursive(Node* root) {
    if (root != NULL) {
        clearRecursive(root->left);
        clearRecursive(root->right);
        delete root;
    }
}

// size: A�ac�n toplam d���m say�s�n� d�ner.
// Bu fonksiyon, sizeRecursive fonksiyonunu kullanarak a�ac�n d���m say�s�n� hesaplar.
int BinaryTree::size() {
    return sizeRecursive(root);
}

// sizeRecursive: A�ac�n toplam d���m say�s�n� hesaplamay� sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, a�ac�n her d���m�n� sayarak toplam d���m say�s�n� d�ner.
int BinaryTree::sizeRecursive(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
}

// inorder: A�ac�n d���mlerini inorder (k�k ortada) s�rayla yazd�r�r.
// Bu fonksiyon, inorderRecursive fonksiyonunu kullanarak d���mleri yazd�r�r.
void BinaryTree::inorder() {
    inorderRecursive(root);
}

// inorderRecursive: A�ac�n d���mlerini inorder s�rayla yazd�rmay� sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, sol alt a�a� -> k�k -> sa� alt a�a� s�ras�n� izleyerek d���mleri yazd�r�r.
void BinaryTree::inorderRecursive(Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        std::cout << root->data << " ";
        inorderRecursive(root->right);
    }
}

// preorder: A�ac�n d���mlerini preorder (k�k ba�ta) s�rayla yazd�r�r.
// Bu fonksiyon, preorderRecursive fonksiyonunu kullanarak d���mleri yazd�r�r.
void BinaryTree::preorder() {
    preorderRecursive(root);
}

// preorderRecursive: A�ac�n d���mlerini preorder s�rayla yazd�rmay� sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, k�k -> sol alt a�a� -> sa� alt a�a� s�ras�n� izleyerek d���mleri yazd�r�r.
void BinaryTree::preorderRecursive(Node* root) {
    if (root != NULL) {
        std::cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

// postorder: A�ac�n d���mlerini postorder (k�k sonda) s�rayla yazd�r�r.
// Bu fonksiyon, postorderRecursive fonksiyonunu kullanarak d���mleri yazd�r�r.
void BinaryTree::postorder() {
    postorderRecursive(root);
}

// postorderRecursive: A�ac�n d���mlerini postorder s�rayla yazd�rmay� sa�layan yard�mc� fonksiyon.
// Bu fonksiyon, sol alt a�a� -> sa� alt a�a� -> k�k s�ras�n� izleyerek d���mleri yazd�r�r.
void BinaryTree::postorderRecursive(Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        std::cout << root->data << " ";
    }
}
