#include <iostream>
#include "LinkedList.h"

// Kurucu fonksiyon: Listeyi ba�lat�r.
// Listeyi bo� ba�lat�r ve liste boyutunu s�f�rlar.
LinkedList::LinkedList() : head(NULL), listSize(0) {}

// Y�k�c� fonksiyon: Listeyi temizler.
// Liste nesnesi yok edilirken bellekteki d���mleri serbest b�rak�r.
LinkedList::~LinkedList() {
    clear();
}

// insertAt: Belirtilen pozisyona bir eleman ekler.
// Pozisyon ge�ersizse bir hata mesaj� yazd�r�r. Ge�erli pozisyonda yeni bir d���m ekler.
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
// Yeni bir d���m olu�turur ve liste sonuna ekler.
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

// deleteAt: Belirtilen pozisyondaki eleman� siler.
// Pozisyon ge�ersizse veya liste bo�sa bir hata mesaj� yazd�r�r. Ge�erli pozisyondaki d���m� siler.
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

// deleteAtEnd: Listenin sonundaki eleman� siler.
// Liste bo�sa bir hata mesaj� yazd�r�r. Son d���m� siler.
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
// Listedeki t�m d���mleri siler ve listeyi bo� hale getirir.
void LinkedList::clear() {
    while (head != NULL) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    listSize = 0;
    std::cout << "Liste temizlendi.\n";
}

// display: Listedeki t�m elemanlar� g�sterir.
// Liste bo�sa bir mesaj yazd�r�r. Elemanlar� birer birer yazd�r�r.
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

// size: Listedeki eleman say�s�n� d�ner.
int LinkedList::size() const {
    return listSize;
}

// listMenu: Liste i�lemleri i�in bir men� sa�lar.
// Kullan�c�dan bir se�enek girmesini ister ve ilgili i�lemi ger�ekle�tirir.
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
            insertMenu();  // Eleman ekleme men�s�ne git
            break;
        case 2:
            deleteMenu();  // Eleman ��karma men�s�ne git
            break;
        case 3:
            clear();  // Listeyi temizle
            break;
        case 4:
            display();  // Listedeki elemanlar� g�ster
            break;
        case 5:
            std::cout << "Listedeki eleman sayisi: " << size() << "\n";  // Listedeki eleman say�s�n� g�ster
            break;
        case 6:
            return;  // Ana men�ye geri d�n
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Ge�ersiz se�im i�in hata mesaj� g�ster
        }
    }
}

// insertMenu: Eleman ekleme i�lemleri i�in bir men� sa�lar.
// Kullan�c�dan bir se�enek girmesini ister ve ilgili ekleme i�lemini ger�ekle�tirir.
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
            return;  // Liste i�lemleri men�s�ne geri d�n
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Ge�ersiz se�im i�in hata mesaj� g�ster
        }
    }
}

// deleteMenu: Eleman ��karma i�lemleri i�in bir men� sa�lar.
// Kullan�c�dan bir se�enek girmesini ister ve ilgili ��karma i�lemini ger�ekle�tirir.
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
            deleteAt(position);  // Belirtilen pozisyondan eleman ��kar
            break;
        case 2:
            deleteAtEnd();  // Listenin sonundaki eleman� ��kar
            break;
        case 3:
            return;  // Liste i�lemleri men�s�ne geri d�n
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Ge�ersiz se�im i�in hata mesaj� g�ster
        }
    }
}
