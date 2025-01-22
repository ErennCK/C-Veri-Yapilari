#include <iostream>
#include "Queue.h"

// enqueue: Kuyru�a eleman ekler.
// Parametre olarak al�nan de�eri kuyruk sonuna ekler ve bir bilgilendirme mesaj� yazd�r�r.
void Queue::enqueue(int value) {
    queue.push_back(value);
    std::cout << "Eleman kuyruga eklendi.\n";
}

// dequeue: Kuyruktan eleman ��kar�r.
// Kuyruk bo�sa hata mesaj� yazd�r�r. Aksi takdirde, kuyru�un �n�ndeki eleman� ��kar�r ve bilgilendirme mesaj� yazd�r�r.
void Queue::dequeue() {
    if (queue.empty()) {
        std::cout << "Kuyruk bos, cikarilacak eleman yok.\n";
    }
    else {
        queue.pop_front();
        std::cout << "Eleman kuyruktan cikarildi.\n";
    }
}

// clear: Kuyru�u temizler.
// Kuyruktaki t�m elemanlar� ��kar�r ve kuyruk bo� hale gelir.
void Queue::clear() {
    queue.clear();
    std::cout << "Kuyruk temizlendi.\n";
}

// display: Kuyruktaki elemanlar� g�sterir.
// Kuyruk bo�sa bir mesaj yazd�r�r. Aksi takdirde, kuyru�un t�m elemanlar�n� ekrana yazd�r�r.
void Queue::display() const {
    if (queue.empty()) {
        std::cout << "Kuyruk bos.\n";
    }
    else {
        std::cout << "Kuyruktaki elemanlar: ";
        for (size_t i = 0; i < queue.size(); ++i) {
            std::cout << queue[i] << " ";
        }
        std::cout << "\n";
    }
}

// size: Kuyruktaki eleman say�s�n� d�ner.
// Kuyrukta ka� eleman oldu�unu belirler ve bu de�eri d�ner.
int Queue::size() const {
    return queue.size();
}

// queueMenu: Kuyruk i�lemleri i�in bir men� sa�lar.
// Kullan�c�dan bir se�enek girmesini ister ve ilgili i�lemi ger�ekle�tirir.
void Queue::queueMenu() {
    int choice;
    int value;

    while (true) {
        std::cout << "\nKuyruk icin islem seciniz:\n";
        std::cout << "1- Kuyruga eleman ekle\n";
        std::cout << "2- Kuyruktan eleman cikar\n";
        std::cout << "3- Kuyrugu temizle\n";
        std::cout << "4- Kuyruktaki elemanlari goster\n";
        std::cout << "5- Kuyruktaki eleman sayisini goster\n";
        std::cout << "6- Ana menuye geri don\n";
        std::cout << "Seciminiz (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Eklenecek elemani giriniz: ";
            std::cin >> value;
            enqueue(value);  // Kuyru�a eleman ekle
            break;
        case 2:
            dequeue();  // Kuyruktan eleman ��kar
            break;
        case 3:
            clear();  // Kuyru�u temizle
            break;
        case 4:
            display();  // Kuyruktaki elemanlar� g�ster
            break;
        case 5:
            std::cout << "Kuyruktaki eleman sayisi: " << size() << "\n";  // Kuyruktaki eleman say�s�n� g�ster
            break;
        case 6:
            return;  // Ana men�ye geri d�n
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Ge�ersiz se�im i�in hata mesaj� g�ster
        }
    }
}
