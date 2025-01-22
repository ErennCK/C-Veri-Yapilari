#include <iostream>
#include "MyClass.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "HashTablosu.h"

int main() {
    MyClass myClass;  // MyClass nesnesi oluşturulur
    Stack stack;  // Yığın (Stack) nesnesi oluşturulur
    Queue queue;  // Kuyruk (Queue) nesnesi oluşturulur
    LinkedList list;  // Bağlı Liste (LinkedList) nesnesi oluşturulur
    BinaryTree tree;  // İkili Ağaç (BinaryTree) nesnesi oluşturulur
    HashTablosu hashTable(0);  // Başlangıçta boş bir hash tablosu oluşturulur

    int capacity;  // Hash tablosu kapasitesi için değişken
    int choice;  // Kullanıcı seçimleri için değişken

    while (true) {
        myClass.menu();  // Menü gösterilir
        std::cout << "Seciminiz (1-6): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            stack.stackMenu();  // Yığın işlemleri menüsü
            break;
        case 2:
            queue.queueMenu();  // Kuyruk işlemleri menüsü
            break;
        case 3:
            list.listMenu();  // Bağlı liste işlemleri menüsü
            break;
        case 4:
            while (true) {
                // İkili ağaç işlemleri menüsü gösterilir
                std::cout << "\nIkili Agac icin islem seciniz:\n";
                std::cout << "1- Agaca Eleman Ekle\n";
                std::cout << "2- Agactan Eleman sil\n";
                std::cout << "3- Agaci Temizle\n";
                std::cout << "4- Agactaki Eleman Sayisini goster\n";
                std::cout << "5- Agaci InOrder dolasarak Elemanlari Goster\n";
                std::cout << "6- Agaci PreOrder dolasarak Elemanlari Goster\n";
                std::cout << "7- Agaci PostOrder dolasarak Elemanlari Goster\n";
                std::cout << "8- Ana menuye geri don\n";
                std::cout << "Seciminiz (1-8): ";
                std::cin >> choice;

                switch (choice) {
                case 1:
                    // İkili ağaca eleman ekleme
                    int value;
                    std::cout << "Eklenecek elemani giriniz: ";
                    std::cin >> value;
                    tree.insert(value);
                    break;
                case 2:
                    // İkili ağaçtan eleman silme
                    std::cout << "Silinecek elemani giriniz: ";
                    std::cin >> value;
                    tree.remove(value);
                    break;
                case 3:
                    // İkili ağacı temizleme
                    tree.clear();
                    std::cout << "Agac temizlendi.\n";
                    break;
                case 4:
                    // İkili ağaçtaki eleman sayısını gösterme
                    std::cout << "Agactaki Eleman Sayisi: " << tree.size() << std::endl;
                    break;
                case 5:
                    // İkili ağacı InOrder dolaşarak elemanları gösterme
                    std::cout << "Agaci InOrder dolasarak Elemanlari: ";
                    tree.inorder();
                    std::cout << std::endl;
                    break;
                case 6:
                    // İkili ağacı PreOrder dolaşarak elemanları gösterme
                    std::cout << "Agaci PreOrder dolasarak Elemanlari: ";
                    tree.preorder();
                    std::cout << std::endl;
                    break;
                case 7:
                    // İkili ağacı PostOrder dolaşarak elemanları gösterme
                    std::cout << "Agaci PostOrder dolasarak Elemanlari: ";
                    tree.postorder();
                    std::cout << std::endl;
                    break;
                case 8:
                    // Ana menüye dönüş
                    std::cout << "Ana menuye geri donuluyor...\n";
                    break;
                default:
                    // Geçersiz seçim
                    std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";
                }

                if (choice == 8) {
                    break;  // Ana menüye dön
                }
            }
            break;
        case 5:
            // Hash tablosu boyutu belirleme ve yeni hash tablosu oluşturma
            std::cout << "Hash tablosu boyutunu giriniz: ";
            std::cin >> capacity;
            hashTable = HashTablosu(capacity);

            while (true) {
                // Hash tablosu işlemleri menüsü gösterilir
                std::cout << "\nCirpilama (Hash Tablosu) icin islem seciniz:\n";
                std::cout << "1- Tabloya Eleman Ekle\n";
                std::cout << "2- Tablodan Eleman Sil\n";
                std::cout << "3- Tabloyu Temizle\n";
                std::cout << "4- Tablodaki eleman sayisini goster\n";
                std::cout << "5- Tablodaki elemanlari goster\n";
                std::cout << "6- Ana menuye geri don\n";
                std::cout << "Seciminiz (1-6): ";
                std::cin >> choice;

                switch (choice) {
                case 1:
                    // Hash tablosuna eleman ekleme
                    int value;
                    std::cout << "Eklemek istediginiz elemani giriniz: ";
                    std::cin >> value;
                    hashTable.ekle(value);
                    break;
                case 2:
                    // Hash tablosundan eleman silme
                    std::cout << "Silinecek elemani giriniz: ";
                    std::cin >> value;
                    hashTable.sil(value);
                    break;
                case 3:
                    // Hash tablosunu temizleme
                    hashTable.temizle();
                    std::cout << "Tablo temizlendi.\n";
                    break;
                case 4:
                    // Hash tablosundaki eleman sayısını gösterme
                    std::cout << "Tablodaki eleman sayisi: " << hashTable.elemanSayisi() << std::endl;
                    break;
                case 5:
                    // Hash tablosundaki elemanları gösterme
                    hashTable.elemanlariGoster();
                    break;
                case 6:
                    // Ana menüye dönüş
                    std::cout << "Ana menuye geri donuluyor...\n";
                    break;
                default:
                    // Geçersiz seçim
                    std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";
                    break;
                }

                if (choice == 6) {
                    break;  // Ana menüye dön
                }
            }
            break;
        case 6:
            // Programdan çıkış
            std::cout << "Programdan Cikis yapiliyor...\n";
            return 0;
        default:
            // Geçersiz seçim
            std::cout << "Gecersiz secim, lutfen tekrar deneyin.\n";
        }
    }

    return 0;
}
