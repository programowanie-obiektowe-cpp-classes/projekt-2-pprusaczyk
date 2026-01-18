#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ranges>

int main() {
    std::ifstream file("input.txt");

    std::vector<int> suma;   //suma kazdego elfa
    std::string tekst;             
    int obecna_suma = 0;     

    while (std::getline(file, tekst)) {
        //jeśli linijka jest pusta, to koniec danego elfa
        if (tekst.empty()) {
            if (obecna_suma > 0) {
                suma.push_back(obecna_suma); //zapisanie wyniku do konca wektora
                obecna_suma = 0;
            }
        } else {
            obecna_suma += std::stoi(tekst);  //zmiana wczytanego tekstu na liczby
        }
    }

    //dodanie ostatniego elfa, plik input nie konczy sie pusta linijka
    if (obecna_suma > 0) {
        suma.push_back(obecna_suma);
    }

    file.close();

    //znalezienie elfa z największą liczbą kalorii.
    auto max_iterator = std::ranges::max_element(suma);
    int max_kalorii = *max_iterator;

    //sortowanie wektora malejaco 
    std::ranges::sort(suma, std::ranges::greater());
    auto top_3_view = suma | std::views::take(3);

    //sumowanie
    int top_3 = std::accumulate(top_3_view.begin(), top_3_view.end(), 0);   

    std::cout << "max kalorii: " << max_kalorii << std::endl;
    std::cout << "suma top 3: " << top_3 << std::endl;

    return 0;
}
