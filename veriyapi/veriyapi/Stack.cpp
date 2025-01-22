#include <iostream>
#include "Stack.h"

// push: Y���na eleman ekler.
// Parametre olarak al�nan de�eri y���n�n sonuna ekler ve bir bilgilendirme mesaj� yazd�r�r.
void Stack::push(int value) {
    stack.push_back(value);
    std::cout << "Eleman yigina eklendi.\n";
}

// pop: Y���ndan eleman ��kar�r.
// Y���n bo�sa hata mesaj� yazd�r�r. Aksi takdirde, y���n�n sonundaki eleman� ��kar�r ve bilgilendirme mesaj� yazd�r�r.
void Stack::pop() {
    if (stack.empty()) {
        std::cout << "Yigin bos, cikarilacak eleman yok.\n";
    }
    else {
        stack.pop_back();
        std::cout << "Eleman yigindan cikarildi.\n";
    }
}

// clear: Y���n� temizler.
// Y���ndaki t�m elemanlar� ��kar�r ve y���n bo� hale gelir.
void Stack::clear() {
    stack.clear();
    std::cout << "Yigin temizlendi.\n";
}

// display: Y���ndaki elemanlar� g�sterir.
// Y���n bo�sa bir mesaj yazd�r�r. Aksi takdirde, y���n�n t�m elemanlar�n� ekrana yazd�r�r.
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

// size: Y���ndaki eleman say�s�n� d�ner.
// Y���nda ka� eleman oldu�unu belirler ve bu de�eri d�ner.
int Stack::size() const {
    return stack.size();
}

// stackMenu: Y���n i�lemleri i�in bir men� sa�lar.
// Kullan�c�dan bir se�enek girmesini ister ve ilgili i�lemi ger�ekle�tirir.
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
            push(value);  // Y���na eleman ekle
            break;
        case 2:
            pop();  // Y���ndan eleman ��kar
            break;
        case 3:
            clear();  // Y���n� temizle
            break;
        case 4:
            display();  // Y���ndaki elemanlar� g�ster
            break;
        case 5:
            std::cout << "Yigindaki eleman sayisi: " << size() << "\n";  // Y���ndaki eleman say�s�n� g�ster
            break;
        case 6:
            return;  // Ana men�ye geri d�n
        default:
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";  // Ge�ersiz se�im i�in hata mesaj� g�ster
        }
    }
}
