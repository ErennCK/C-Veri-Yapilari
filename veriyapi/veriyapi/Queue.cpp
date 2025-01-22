#include <iostream>
#include "Queue.h"

// enqueue: Kuyruða eleman ekler.
// Parametre olarak alýnan deðeri kuyruk sonuna ekler ve bir bilgilendirme mesajý yazdýrýr.
void Queue::enqueue(int value) {
    queue.push_back(value);
    std::cout << "Eleman kuyruga eklendi.\n";
}

// dequeue: Kuyruktan eleman çýkarýr.
// Kuyruk boþsa hata mesajý yazdýrýr. Aksi takdirde, kuyruðun önündeki elemaný çýkarýr ve bilgilendirme mesajý yazdýrýr.
void Queue::dequeue() {
    if (queue.empty()) {
        std::cout << "Kuyruk bos, cikarilacak eleman yok.\n";
    }
    else {
        queue.pop_front();
        std::cout << "Eleman kuyruktan cikarildi.\n";
    }
}

// clear: Kuyruðu temizler.
// Kuyruktaki tüm elemanlarý çýkarýr ve kuyruk boþ hale gelir.
void Queue::clear() {
    queue.clear();
    std::cout << "Kuyruk temizlendi.\n";
}

// display: Kuyruktaki elemanlarý gösterir.
// Kuyruk boþsa bir mesaj yazdýrýr. Aksi takdirde, kuyruðun tüm elemanlarýný ekrana yazdýrýr.
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

// size: Kuyruktaki eleman sayýsýný döner.
// Kuyrukta kaç eleman olduðunu belirler ve bu deðeri döner.
int Queue::size() const {
    return queue.size();
}

// queueMenu: Kuyruk iþlemleri için bir menü saðlar.
// Kullanýcýdan bir seçenek girmesini ister ve ilgili iþlemi gerçekleþtirir.
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
            enqueue(value);  // Kuyruða eleman ekle
            break;
        case 2:
            dequeue();  // Kuyruktan eleman çýkar
            break;
        case 3:
            clear();  // Kuyruðu temizle
            break;
        case 4:
            display();  // Kuyruktaki elemanlarý göster
            break;
        case 5:
            std::cout << "Kuyruktaki eleman sayisi: " << size() << "\n";  // Kuyruktaki eleman sayýsýný göster
            break;
        case 6:
            return;  // Ana menüye geri dön
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Geçersiz seçim için hata mesajý göster
        }
    }
}
