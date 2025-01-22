#include <iostream>
#include "Stack.h"

// push: Yýðýna eleman ekler.
// Parametre olarak alýnan deðeri yýðýnýn sonuna ekler ve bir bilgilendirme mesajý yazdýrýr.
void Stack::push(int value) {
    stack.push_back(value);
    std::cout << "Eleman yigina eklendi.\n";
}

// pop: Yýðýndan eleman çýkarýr.
// Yýðýn boþsa hata mesajý yazdýrýr. Aksi takdirde, yýðýnýn sonundaki elemaný çýkarýr ve bilgilendirme mesajý yazdýrýr.
void Stack::pop() {
    if (stack.empty()) {
        std::cout << "Yigin bos, cikarilacak eleman yok.\n";
    }
    else {
        stack.pop_back();
        std::cout << "Eleman yigindan cikarildi.\n";
    }
}

// clear: Yýðýný temizler.
// Yýðýndaki tüm elemanlarý çýkarýr ve yýðýn boþ hale gelir.
void Stack::clear() {
    stack.clear();
    std::cout << "Yigin temizlendi.\n";
}

// display: Yýðýndaki elemanlarý gösterir.
// Yýðýn boþsa bir mesaj yazdýrýr. Aksi takdirde, yýðýnýn tüm elemanlarýný ekrana yazdýrýr.
void Stack::display() const {
    if (stack.empty()) {
        std::cout << "Yigin bos.\n";
    }
    else {
        std::cout << "Yigindaki elemanlar: ";
        for (size_t i = 0; i < stack.size(); ++i) {
            std::cout << stack[i] << " ";
        }
        std::cout << "\n";
    }
}

// size: Yýðýndaki eleman sayýsýný döner.
// Yýðýnda kaç eleman olduðunu belirler ve bu deðeri döner.
int Stack::size() const {
    return stack.size();
}

// stackMenu: Yýðýn iþlemleri için bir menü saðlar.
// Kullanýcýdan bir seçenek girmesini ister ve ilgili iþlemi gerçekleþtirir.
void Stack::stackMenu() {
    int choice;
    int value;

    while (true) {
        std::cout << "\nYigin icin islem seciniz:\n";
        std::cout << "1- Yigina eleman ekle\n";
        std::cout << "2- Yigindan eleman cikar\n";
        std::cout << "3- Yigini temizle\n";
        std::cout << "4- Yigindaki elemanlari goster\n";
        std::cout << "5- Yigindaki eleman sayisini goster\n";
        std::cout << "6- Ana menuye geri don\n";
        std::cout << "Seciminiz (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Eklenecek elemani giriniz: ";
            std::cin >> value;
            push(value);  // Yýðýna eleman ekle
            break;
        case 2:
            pop();  // Yýðýndan eleman çýkar
            break;
        case 3:
            clear();  // Yýðýný temizle
            break;
        case 4:
            display();  // Yýðýndaki elemanlarý göster
            break;
        case 5:
            std::cout << "Yigindaki eleman sayisi: " << size() << "\n";  // Yýðýndaki eleman sayýsýný göster
            break;
        case 6:
            return;  // Ana menüye geri dön
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Geçersiz seçim için hata mesajý göster
        }
    }
}
