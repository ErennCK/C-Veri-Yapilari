#include <iostream>
#include "LinkedList.h"

// Kurucu fonksiyon: Listeyi baþlatýr.
// Listeyi boþ baþlatýr ve liste boyutunu sýfýrlar.
LinkedList::LinkedList() : head(NULL), listSize(0) {}

// Yýkýcý fonksiyon: Listeyi temizler.
// Liste nesnesi yok edilirken bellekteki düðümleri serbest býrakýr.
LinkedList::~LinkedList() {
    clear();
}

// insertAt: Belirtilen pozisyona bir eleman ekler.
// Pozisyon geçersizse bir hata mesajý yazdýrýr. Geçerli pozisyonda yeni bir düðüm ekler.
void LinkedList::insertAt(int position, int value) {
    if (position < 0 || position > listSize) {
        std::cout << "Gecersiz pozisyon.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    listSize++;
    std::cout << "Eleman listeye eklendi.\n";
}

// insertAtEnd: Listenin sonuna bir eleman ekler.
// Yeni bir düðüm oluþturur ve liste sonuna ekler.
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    listSize++;
    std::cout << "Eleman sona eklendi.\n";
}

// deleteAt: Belirtilen pozisyondaki elemaný siler.
// Pozisyon geçersizse veya liste boþsa bir hata mesajý yazdýrýr. Geçerli pozisyondaki düðümü siler.
void LinkedList::deleteAt(int position) {
    if (position < 0 || position >= listSize || head == NULL) {
        std::cout << "Gecersiz pozisyon veya bos liste.\n";
        return;
    }

    Node* toDelete;

    if (position == 0) {
        toDelete = head;
        head = head->next;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }

    delete toDelete;
    listSize--;
    std::cout << "Eleman listeden cikarildi.\n";
}

// deleteAtEnd: Listenin sonundaki elemaný siler.
// Liste boþsa bir hata mesajý yazdýrýr. Son düðümü siler.
void LinkedList::deleteAtEnd() {
    if (head == NULL) {
        std::cout << "Bos liste.\n";
        return;
    }

    Node* toDelete;

    if (head->next == NULL) {
        toDelete = head;
        head = NULL;
    }
    else {
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = NULL;
    }

    delete toDelete;
    listSize--;
    std::cout << "Son eleman listeden cikarildi.\n";
}

// clear: Listeyi temizler.
// Listedeki tüm düðümleri siler ve listeyi boþ hale getirir.
void LinkedList::clear() {
    while (head != NULL) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    listSize = 0;
    std::cout << "Liste temizlendi.\n";
}

// display: Listedeki tüm elemanlarý gösterir.
// Liste boþsa bir mesaj yazdýrýr. Elemanlarý birer birer yazdýrýr.
void LinkedList::display() const {
    if (head == NULL) {
        std::cout << "Liste bos.\n";
    }
    else {
        Node* current = head;
        std::cout << "Listedeki elemanlar: ";
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
}

// size: Listedeki eleman sayýsýný döner.
int LinkedList::size() const {
    return listSize;
}

// listMenu: Liste iþlemleri için bir menü saðlar.
// Kullanýcýdan bir seçenek girmesini ister ve ilgili iþlemi gerçekleþtirir.
void LinkedList::listMenu() {
    int choice;
    while (true) {
        std::cout << "\nBagli Liste icin islem seciniz:\n";
        std::cout << "1- Listeye eleman ekle\n";
        std::cout << "2- Listeden eleman cikar\n";
        std::cout << "3- Listeyi temizle\n";
        std::cout << "4- Listedeki elemanlari goster\n";
        std::cout << "5- Listedeki eleman sayisini goster\n";
        std::cout << "6- Ana menuye geri don\n";
        std::cout << "Seciminiz (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            insertMenu();  // Eleman ekleme menüsüne git
            break;
        case 2:
            deleteMenu();  // Eleman çýkarma menüsüne git
            break;
        case 3:
            clear();  // Listeyi temizle
            break;
        case 4:
            display();  // Listedeki elemanlarý göster
            break;
        case 5:
            std::cout << "Listedeki eleman sayisi: " << size() << "\n";  // Listedeki eleman sayýsýný göster
            break;
        case 6:
            return;  // Ana menüye geri dön
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Geçersiz seçim için hata mesajý göster
        }
    }
}

// insertMenu: Eleman ekleme iþlemleri için bir menü saðlar.
// Kullanýcýdan bir seçenek girmesini ister ve ilgili ekleme iþlemini gerçekleþtirir.
void LinkedList::insertMenu() {
    int choice, value, position;

    while (true) {
        std::cout << "\nEkleme turunu seciniz:\n";
        std::cout << "1- Araya eleman ekle\n";
        std::cout << "2- Sona eleman ekle\n";
        std::cout << "3- Liste islemlerine geri don\n";
        std::cout << "Seciminiz (1-3): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Eklenecek pozisyonu giriniz: ";
            std::cin >> position;
            std::cout << "Eklenecek elemani giriniz: ";
            std::cin >> value;
            insertAt(position, value);  // Belirtilen pozisyona eleman ekle
            break;
        case 2:
            std::cout << "Eklenecek elemani giriniz: ";
            std::cin >> value;
            insertAtEnd(value);  // Listenin sonuna eleman ekle
            break;
        case 3:
            return;  // Liste iþlemleri menüsüne geri dön
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Geçersiz seçim için hata mesajý göster
        }
    }
}

// deleteMenu: Eleman çýkarma iþlemleri için bir menü saðlar.
// Kullanýcýdan bir seçenek girmesini ister ve ilgili çýkarma iþlemini gerçekleþtirir.
void LinkedList::deleteMenu() {
    int choice, position;

    while (true) {
        std::cout << "\nCikarma turunu seciniz:\n";
        std::cout << "1- Aradan eleman cikar\n";
        std::cout << "2- Sondan eleman cikar\n";
        std::cout << "3- Liste islemlerine geri don\n";
        std::cout << "Seciminiz (1-3): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Cikarilacak pozisyonu giriniz: ";
            std::cin >> position;
            deleteAt(position);  // Belirtilen pozisyondan eleman çýkar
            break;
        case 2:
            deleteAtEnd();  // Listenin sonundaki elemaný çýkar
            break;
        case 3:
            return;  // Liste iþlemleri menüsüne geri dön
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Geçersiz seçim için hata mesajý göster
        }
    }
}
