#include <iostream>
#include <vector>
#include <limits> // cin temizliği için

class Person {
public:
    Person(const std::string& ad, int yas) : ad(ad), yas(yas) {}
    std::string GetAd() const { return ad; }
    int GetYas() const { return yas; }

    void SetYas(int yeniYas) { yas = yeniYas; } // Güncelleme için

private:
    std::string ad;
    int yas;
};

void KisileriListele(const std::vector<Person>& kisiler) {
    if (kisiler.empty()) {
        std::cout << "Listede kisi yok!\n";
        return;
    }
    std::cout << "Kisi Listesi:\n";
    for (size_t i = 0; i < kisiler.size(); ++i) {
        std::cout << i+1 << ". " << kisiler[i].GetAd() << " (" << kisiler[i].GetYas() << ")\n";
    }
}

void KisiEkle(std::vector<Person>& kisiler) {
    std::string ad;
    int yas;
    std::cout << "Kisinin adini girin: ";
    std::cin >> ad;
    std::cout << "Kisinin yasini girin: ";
    std::cin >> yas;
    kisiler.emplace_back(ad, yas);
    std::cout << "Kisi eklendi!\n";
}

void KisiSil(std::vector<Person>& kisiler) {
    if (kisiler.empty()) {
        std::cout << "Silinecek kisi yok!\n";
        return;
    }
    KisileriListele(kisiler);
    std::cout << "Silmek istediginiz kisinin numarasini girin: ";
    int index;
    std::cin >> index;
    if (index < 1 || index > kisiler.size()) {
        std::cout << "Gecersiz numara!\n";
        return;
    }
    kisiler.erase(kisiler.begin() + index - 1);
    std::cout << "Kisi silindi!\n";
}

void MenuGoster() {
    std::cout << "\n==== KISI REHBERI ====\n";
    std::cout << "1. Kisi Ekle\n";
    std::cout << "2. Kisileri Listele\n";
    std::cout << "3. Kisi Sil\n";
    std::cout << "4. Cikis\n";
    std::cout << "Seciminiz: ";
}

int main() {
    std::vector<Person> kisiler;
    int secim;

    while (true) {
        MenuGoster();
        std::cin >> secim;

        // Kullanıcı yanlış bir şey girerse cin'i temizle
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Gecersiz giris!\n";
            continue;
        }

        switch (secim) {
            case 1:
                KisiEkle(kisiler);
                break;
            case 2:
                KisileriListele(kisiler);
                break;
            case 3:
                KisiSil(kisiler);
                break;
            case 4:
                std::cout << "Programdan cikiliyor...\n";
                return 0;
            default:
                std::cout << "Gecersiz secim!\n";
        }
    }
}
