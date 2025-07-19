#include <iostream>
#include <vector>

class Person {
public:
    // Constructor
    Person(const std::string& ad, int yas) : ad(ad), yas(yas) {}

    std::string GetAd() const { return ad; }
    int GetYas() const { return yas; }

private:
    std::string ad;
    int yas;
};

double OrtalamaYas(const std::vector<Person>& kisiler) {
    int toplam = 0;
    for (const Person& kisi : kisiler) {
        toplam += kisi.GetYas();
    }
    return static_cast<double>(toplam) / kisiler.size();
}

int main() {
    int adet;
    std::cout << "Kac kisi ekleyeceksiniz? ";
    std::cin >> adet;

    std::vector<Person> kisiler;
    for (int i = 0; i < adet; ++i) {
        std::string ad;
        int yas;
        std::cout << i+1 << ". kisinin adini girin: ";
        std::cin >> ad;
        std::cout << i+1 << ". kisinin yasini girin: ";
        std::cin >> yas;

        kisiler.emplace_back(ad, yas); // Kişi nesnesi ekleniyor
    }

    std::cout << "\nKisi Listesi:\n";
    for (const Person& kisi : kisiler) {
        std::cout << "- " << kisi.GetAd() << ", Yas: " << kisi.GetYas() << std::endl;
    }

    double ortalama = OrtalamaYas(kisiler);
    std::cout << "\nYas ortalamasi: " << ortalama << std::endl;

    return 0;
}
