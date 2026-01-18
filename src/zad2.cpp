#include <iostream>   
#include <fstream>    
#include <string>    
#include <vector>     

//program do obliczania wyników gry kamien papier nozyce na podstawie pliku
//a,b,c kamien papier nozyce przeciwnika
//x,y,z kamien papier nozyce moje

int main() {
    std::ifstream file("input2.txt");

    int wynik_calkowity_1 = 0; 
    int wynik_calkowity_2 = 0;
    std::string linia;

    while (std::getline(file, linia)) {
        if (linia.length() < 3) continue;

        char ruch_przeciwnik = linia[0];
        char ruch_ja = linia[2];

        int wynik = 0;
        if (ruch_ja == 'X') wynik += 1;
        else if (ruch_ja == 'Y') wynik += 2;
        else if (ruch_ja == 'Z') wynik += 3; 

        //logika punktacji
        //remis
        if ((ruch_przeciwnik == 'A' && ruch_ja == 'X') || (ruch_przeciwnik == 'B' && ruch_ja == 'Y') || (ruch_przeciwnik == 'C' && ruch_ja == 'Z')) 
            wynik += 3;
        //wygrana
        else if ((ruch_przeciwnik == 'A' && ruch_ja == 'Y') || (ruch_przeciwnik == 'B' && ruch_ja == 'Z') || (ruch_przeciwnik == 'C' && ruch_ja == 'X'))
            wynik += 6;
        
        wynik_calkowity_1 += wynik;

        //czesc 2
        int wynik_2 = 0;
        char ruch_ja_2;

        //logika dla czesci 2
        if (ruch_ja == 'X') {     //musze przegrac
            wynik_2 += 0;
            if (ruch_przeciwnik == 'A')      ruch_ja_2 = 'Z'; //przeciw kamieniowi nozyce
            else if (ruch_przeciwnik == 'B') ruch_ja_2 = 'X'; //przeciw papierowi kamień
            else                             ruch_ja_2 = 'Y'; //przeciw nozycom papier
        } 
        else if (ruch_ja == 'Y') { //musi byc remis
            wynik_2 += 3;
            if (ruch_przeciwnik == 'A')      ruch_ja_2 = 'X'; //kamien na kamien
            else if (ruch_przeciwnik == 'B') ruch_ja_2 = 'Y'; //papier na papier
            else                             ruch_ja_2 = 'Z'; //nozyce na nozyce
        } 
        else {                     //musze wygrac
            wynik_2 += 6;
            if (ruch_przeciwnik == 'A')      ruch_ja_2 = 'Y'; //papier na kamien
            else if (ruch_przeciwnik == 'B') ruch_ja_2 = 'Z'; //nozyce na papier
            else                             ruch_ja_2 = 'X'; //kamień na nozyce
        }

        //punkty za wystawiony ksztalt
        if (ruch_ja_2 == 'X')      wynik_2 += 1;
        else if (ruch_ja_2 == 'Y') wynik_2 += 2;
        else if (ruch_ja_2 == 'Z') wynik_2 += 3;

        wynik_calkowity_2 += wynik_2;
    }

    file.close();

    std::cout << "wynik czesc 1: " << wynik_calkowity_1 << std::endl;
    std::cout << "wynik czesc 2: " << wynik_calkowity_2 << std::endl;

    return 0;
}