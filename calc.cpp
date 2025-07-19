#include <iostream>
#include <vector>

double OrtalamaHesapla(const std::vector<int>& sayilar) {
    int toplam = 0;
    for (int sayi : sayilar) {
        toplam += sayi;
    }
    return static_cast<double>(toplam) / sayilar.size();
}

int main() {
    std::string isim;
    std::cout << "Isminizi girin: ";
    std::getline(std::cin, isim);

    std::cout << "Merhaba, " << isim << "!" << std::endl;

    int adet;
    std::cout << "Kac tane sayi gireceksiniz? ";
    std::cin >> adet;

    std::vector<int> sayilar(adet);
    for (int i = 0; i < adet; ++i) {
        std::cout << i+1 << ". sayiyi girin: ";
        std::cin >> sayilar[i];
    }

    double ortalama = OrtalamaHesapla(sayilar);
    std::cout << "Girdiginiz sayilarin ortalamasi: " << ortalama << std::endl;

    return 0;
}
