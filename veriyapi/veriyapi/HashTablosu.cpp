#include "HashTablosu.h"

// Yap�c� fonksiyon: Hash tablosunu ba�lat�r.
// Kapasiteyi al�r ve tabloyu bu kapasiteyle -1 de�erleriyle ba�lat�r (bo� elemanlar� temsil etmek i�in).
HashTablosu::HashTablosu(int capacity) : capacity(capacity), size(0) {
    table.resize(capacity, -1); // Tabloyu -1 de�erleriyle ba�lat
}

// hashFunction: Anahtara g�re bir indeks d�ner.
// Anahtar� tablonun kapasitesine g�re mod alarak indeks hesaplar.
int HashTablosu::hashFunction(int key) {
    return key % capacity; // Basit bir hash fonksiyonu
}

// ekle: Anahtar� hash tablosuna ekler.
// Anahtar�n hash fonksiyonu ile bulunan indekse yerle�tirir ve boyutu bir art�r�r.
void HashTablosu::ekle(int key) {
    int index = hashFunction(key);
    table[index] = key;
    size++;
}

// sil: Hash tablosundan anahtar� siler.
// Anahtar�n hash fonksiyonu ile bulunan indekse giderek, e�er anahtar o indekste bulunuyorsa -1 ile i�aretler ve boyutu bir azalt�r.
void HashTablosu::sil(int key) {
    int index = hashFunction(key);
    if (table[index] == key) {
        table[index] = -1; // Eleman� -1 ile i�aretle (bo� eleman)
        size--;
    }
}

// temizle: Hash tablosunu temizler.
// Tabloyu bo�alt�r ve tekrar kapasite kadar -1 de�erleriyle ba�lat�r, boyutu s�f�rlar.
void HashTablosu::temizle() {
    table.clear();
    table.resize(capacity, -1); // Tabloyu temizle ve tekrar -1 de�erleriyle ba�lat
    size = 0;
}

// elemanSayisi: Hash tablosundaki eleman say�s�n� d�ner.
// Tabloda ka� eleman oldu�unu belirler ve bu de�eri d�ner.
int HashTablosu::elemanSayisi() {
    return size;
}

// elemanlariGoster: Hash tablosundaki elemanlar� ekrana yazd�r�r.
// Tabloyu dola��r ve bo� olmayan (de�eri -1 olmayan) elemanlar� ekrana yazd�r�r.
void HashTablosu::elemanlariGoster() {
    std::cout << "Tablodaki Elemanlar: ";
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != -1) {
            std::cout << table[i] << " ";
        }
    }
    std::cout << std::endl;
}
