#include "BinaryTree.h"

// Kurucu fonksiyon: root düðümünü NULL olarak baþlatýr.
BinaryTree::BinaryTree() : root(NULL) {}

// insert: Aðaca bir deðer ekler.
// Bu fonksiyon, insertRecursive fonksiyonunu kullanarak aðaca bir deðer ekler.
void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

// insertRecursive: Aðaca deðer eklemeyi saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, aðacýn kökünden baþlayarak uygun pozisyonu bulur ve yeni düðümü ekler.
BinaryTree::Node* BinaryTree::insertRecursive(Node* root, int value) {
    // Eðer kök NULL ise, yeni bir düðüm oluþtur ve geri döndür.
    if (root == NULL) {
        return new Node(value);
    }

    // Eðer eklenen deðer kök düðümün deðerinden küçükse, sol alt aðaçta ekle.
    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    }
    // Eðer eklenen deðer kök düðümün deðerinden büyükse, sað alt aðaçta ekle.
    else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    // Deðeri ekledikten sonra kökü geri döndür.
    return root;
}

// remove: Aðaçtan bir deðeri çýkarýr.
// Bu fonksiyon, removeRecursive fonksiyonunu kullanarak aðactan bir deðeri çýkarýr.
void BinaryTree::remove(int value) {
    root = removeRecursive(root, value);
}

// removeRecursive: Aðaçtan deðer çýkarmayý saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, aðacýn kökünden baþlayarak çýkarýlacak deðeri bulur ve çýkarýr.
BinaryTree::Node* BinaryTree::removeRecursive(Node* root, int value) {
    // Eðer kök NULL ise, doðrudan geri döndür.
    if (root == NULL) {
        return root;
    }

    // Eðer çýkarýlacak deðer kök düðümün deðerinden küçükse, sol alt aðaçta ara.
    if (value < root->data) {
        root->left = removeRecursive(root->left, value);
    }
    // Eðer çýkarýlacak deðer kök düðümün deðerinden büyükse, sað alt aðaçta ara.
    else if (value > root->data) {
        root->right = removeRecursive(root->right, value);
    }
    // Eðer deðer kök düðümün deðerine eþitse, bu düðümü çýkar.
    else {
        // Düðümün bir ya da hiç çocuðu yoksa.
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

        // Düðümün iki çocuðu varsa, sað alt aðacýn en küçük düðümünü bul ve kök yap.
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeRecursive(root->right, temp->data);
    }

    return root;
}

// minValueNode: Sað alt aðacýn en küçük düðümünü bulur.
// Bu fonksiyon, verilen düðümden baþlayarak en sol düðümü bulur.
BinaryTree::Node* BinaryTree::minValueNode(Node* node) {
    Node* current = node;
    // En sol düðüme ulaþana kadar ilerle.
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// clear: Aðacý temizler.
// Bu fonksiyon, clearRecursive fonksiyonunu kullanarak aðacýn tüm düðümlerini siler.
void BinaryTree::clear() {
    clearRecursive(root);
    root = NULL;
}

// clearRecursive: Aðacý temizlemeyi saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, aðacýn tüm düðümlerini siler.
void BinaryTree::clearRecursive(Node* root) {
    if (root != NULL) {
        clearRecursive(root->left);
        clearRecursive(root->right);
        delete root;
    }
}

// size: Aðacýn toplam düðüm sayýsýný döner.
// Bu fonksiyon, sizeRecursive fonksiyonunu kullanarak aðacýn düðüm sayýsýný hesaplar.
int BinaryTree::size() {
    return sizeRecursive(root);
}

// sizeRecursive: Aðacýn toplam düðüm sayýsýný hesaplamayý saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, aðacýn her düðümünü sayarak toplam düðüm sayýsýný döner.
int BinaryTree::sizeRecursive(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
}

// inorder: Aðacýn düðümlerini inorder (kök ortada) sýrayla yazdýrýr.
// Bu fonksiyon, inorderRecursive fonksiyonunu kullanarak düðümleri yazdýrýr.
void BinaryTree::inorder() {
    inorderRecursive(root);
}

// inorderRecursive: Aðacýn düðümlerini inorder sýrayla yazdýrmayý saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, sol alt aðaç -> kök -> sað alt aðaç sýrasýný izleyerek düðümleri yazdýrýr.
void BinaryTree::inorderRecursive(Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        std::cout << root->data << " ";
        inorderRecursive(root->right);
    }
}

// preorder: Aðacýn düðümlerini preorder (kök baþta) sýrayla yazdýrýr.
// Bu fonksiyon, preorderRecursive fonksiyonunu kullanarak düðümleri yazdýrýr.
void BinaryTree::preorder() {
    preorderRecursive(root);
}

// preorderRecursive: Aðacýn düðümlerini preorder sýrayla yazdýrmayý saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, kök -> sol alt aðaç -> sað alt aðaç sýrasýný izleyerek düðümleri yazdýrýr.
void BinaryTree::preorderRecursive(Node* root) {
    if (root != NULL) {
        std::cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

// postorder: Aðacýn düðümlerini postorder (kök sonda) sýrayla yazdýrýr.
// Bu fonksiyon, postorderRecursive fonksiyonunu kullanarak düðümleri yazdýrýr.
void BinaryTree::postorder() {
    postorderRecursive(root);
}

// postorderRecursive: Aðacýn düðümlerini postorder sýrayla yazdýrmayý saðlayan yardýmcý fonksiyon.
// Bu fonksiyon, sol alt aðaç -> sað alt aðaç -> kök sýrasýný izleyerek düðümleri yazdýrýr.
void BinaryTree::postorderRecursive(Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        std::cout << root->data << " ";
    }
}
