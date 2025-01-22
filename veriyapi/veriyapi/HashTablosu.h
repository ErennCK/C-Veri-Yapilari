#ifndef HASHTABLOSU_H
#define HASHTABLOSU_H

#include <iostream>
#include <vector>

class HashTablosu {
private:
    std::vector<int> table;
    int capacity;
    int size;

    int hashFunction(int key);

public:
    HashTablosu(int capacity);
    void ekle(int key);
    void sil(int key);
    void temizle();
    int elemanSayisi();
    void elemanlariGoster();
};

#endif // HASHTABLOSU_H