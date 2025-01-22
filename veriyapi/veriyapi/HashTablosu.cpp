#include "HashTablosu.h"

// Yapýcý fonksiyon: Hash tablosunu baþlatýr.
// Kapasiteyi alýr ve tabloyu bu kapasiteyle -1 deðerleriyle baþlatýr (boþ elemanlarý temsil etmek için).
HashTablosu::HashTablosu(int capacity) : capacity(capacity), size(0) {
    table.resize(capacity, -1); // Tabloyu -1 deðerleriyle baþlat
}

// hashFunction: Anahtara göre bir indeks döner.
// Anahtarý tablonun kapasitesine göre mod alarak indeks hesaplar.
int HashTablosu::hashFunction(int key) {
    return key % capacity; // Basit bir hash fonksiyonu
}

// ekle: Anahtarý hash tablosuna ekler.
// Anahtarýn hash fonksiyonu ile bulunan indekse yerleþtirir ve boyutu bir artýrýr.
void HashTablosu::ekle(int key) {
    int index = hashFunction(key);
    table[index] = key;
    size++;
}

// sil: Hash tablosundan anahtarý siler.
// Anahtarýn hash fonksiyonu ile bulunan indekse giderek, eðer anahtar o indekste bulunuyorsa -1 ile iþaretler ve boyutu bir azaltýr.
void HashTablosu::sil(int key) {
    int index = hashFunction(key);
    if (table[index] == key) {
        table[index] = -1; // Elemaný -1 ile iþaretle (boþ eleman)
        size--;
    }
}

// temizle: Hash tablosunu temizler.
// Tabloyu boþaltýr ve tekrar kapasite kadar -1 deðerleriyle baþlatýr, boyutu sýfýrlar.
void HashTablosu::temizle() {
    table.clear();
    table.resize(capacity, -1); // Tabloyu temizle ve tekrar -1 deðerleriyle baþlat
    size = 0;
}

// elemanSayisi: Hash tablosundaki eleman sayýsýný döner.
// Tabloda kaç eleman olduðunu belirler ve bu deðeri döner.
int HashTablosu::elemanSayisi() {
    return size;
}

// elemanlariGoster: Hash tablosundaki elemanlarý ekrana yazdýrýr.
// Tabloyu dolaþýr ve boþ olmayan (deðeri -1 olmayan) elemanlarý ekrana yazdýrýr.
void HashTablosu::elemanlariGoster() {
    std::cout << "Tablodaki Elemanlar: ";
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != -1) {
            std::cout << table[i] << " ";
        }
    }
    std::cout << std::endl;
}
