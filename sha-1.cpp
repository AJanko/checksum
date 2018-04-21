#include <QFileDialog>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string.h>
#define rol(x,n) ((x << n) | (x >> (32-n)))

char SHA1_wynik[50];

extern QString tekst;


void MainWindow::block(unsigned char* str, unsigned long &b0, unsigned long &b1, //obliczenia na ka�dym bloku
            unsigned long &b2, unsigned long &b3, unsigned long &b4){
    unsigned long slowa[80], a, b, c, d, e, k, f, tmp; //zmienne
    for(int j = 0; j < 16; j++){
        slowa[j] = str[j*4 + 0] * 0x1000000 //ustawianie szesnastu 32-bitowych s��w
             + str[j*4 + 1] * 0x10000
             + str[j*4 + 2] * 0x100
             + str[j*4 + 3];
    }
        for(int j = 16; j < 80; j++){ //rozszerzanie szesnastu s��w do osiemdziesi�ciu
                slowa[j] = rol((slowa[j-3] ^ slowa[j-8] ^ slowa[j-14] ^ slowa[j-16]),1);
    }

        a = b0;  //inicjalizacja a,b,c,d,e
        b = b1;
        c = b2;
        d = b3;
        e = b4;

        for(int m=0;m<80;m++){  //dzia�ania...
            if(m <= 19){
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            } else if(m <= 39){
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } else if(m <= 59){
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            tmp = (rol(a,5) + f + e + k + slowa[m]) & 0xFFFFFFFF;
            e = d;
            d = c;
            c = rol(b,30);
            b = a;
            a = tmp;
        }

        b0 = b0 + a;  //przypis warto�ci b0..b4
        b1 = b1 + b;
        b2 = b2 + c;
        b3 = b3 + d;
        b4 = b4 + e;
}

void MainWindow::sha1file(char* filename){
        //otwieramy plik
        FILE *f;
        f = fopen(filename, "rb");
        if(f != NULL){
                //tworzymy zmienne
                char bufor[65];
                unsigned long b0, b1, b2, b3, b4;
                        b0 = 0x67452301;
                        b1 = 0xEFCDAB89;
                        b2 = 0x98BADCFE;
                        b3 = 0x10325476;
                        b4 = 0xC3D2E1F0;

                //uzyskujemy rozmiar pliku
                fseek(f, 0, SEEK_END);
                unsigned long filesize = ftell(f);
                //wracamy na pocz�tek pliku
                rewind(f);

                //uzyskujemy liczb� 64-bajtowych (512-bitowych) blok�w
                long blocks = filesize / 64;
                //uzyskujemy rozmiar ostatniego bloku
                long lastblock = filesize % 64;
                if(lastblock == 0){blocks--; lastblock = 64;}

                //przetwarzamy wszystkie bloki opr�cz ostatniego
                for(int i = 0; i < blocks; i++){
                        fread(bufor, 1, 64, f); //czytamy 64 bajty
                        bufor[64] = '\0'; //dodajemy ostatni
                        block((unsigned char*)bufor, b0, b1, b2, b3, b4); //uaktualniamy zmienne
                }

                /* Teraz dodajemy do ostatniego bufora bit o warto�ci 1, wype�niacz i
                rozmiar badanego pliku.
                Je�eli bufor < 56 znak�w, mo�emy do niego doda�
                bit o warto�ci 1, kt�ry z 7 bitami wype�niacza stworzy bajt o warto�ci 0x80.
                */

                if(lastblock < 56){ //je�eli ostatni blok ma mniej ni� 64 elementy
                        for(int i = 0; i < 64; i++) bufor[i] = 0;
                        fread(bufor, 1, lastblock, f); //to go czytamy do ko�ca
                        bufor[lastblock] = 0x80; //dodajemy bit o warto�ci 1 i siedem zer
                } else {
                        for(int i = 0; i < 64; i++) bufor[i] = 0;
                        fread(bufor, 1, lastblock, f); //czytamy go do ko�ca
                        if(lastblock < 64) bufor[lastblock] = 0x80;
                        bufor[64] = '\0';
                        block((unsigned char*)bufor, b0, b1, b2, b3, b4); //uaktualniamy hx
                        for(int i = 0; i < 64; i++) bufor[i] = 0; //zerujemy blok
                }
                //dodajemy d�ugo��
                if(lastblock == 64) bufor[0] = 0x80;  //je�eli ostatni blok by� pe�ny, musimy bajt 1 zapisa� do nast�pnego
                filesize *= 8; //potrzebna nam d�ugo�� pliku w bitach, nie bajtach

                /* Zapisujemy tylko 4 ostatnie znaki okre�laj�ce rozmiar; zak�adamy, �e
                plik nie ma wi�cej ni� 2^32-1 bit�w (ok. 0,5GB). */
                bufor[60] = filesize / 0x1000000;
                bufor[61] = filesize % 0x1000000 / 0x10000;
                bufor[62] = filesize % 0x10000 / 0x100;
                bufor[63] = filesize % 0x100;
                bufor[64] = '\0';
                block((unsigned char*)bufor, b0, b1, b2, b3, b4); //uaktualniamy hx
                sprintf(SHA1_wynik, "%08x%08x%08x%08x%08x", b0, b1, b2, b3, b4); //tworzymy wynik

                //zamykamy plik
                fclose(f);
        } else {
                SHA1_wynik[0] = '-'; //je�li wyst�pi� b��d, pierwszy znakiem jest kreska
        }
        //wynik jest w zmiennej globalnej SHA1_wynik
}

void MainWindow::sha1main()
{
        std::string filename_temp = tekst.toLocal8Bit().constData();
        char filename[256];
        strcpy(filename, filename_temp.c_str());            //^^operacje potrzebne do konwersji z QString na tablice char
        sha1file((char*)filename);     //obliczamy sum� kontroln� SHA-1
        if(SHA1_wynik[0] != '-'){      //je�eli funkcja zosta�a uko�czona poprawnie
            ui->SHA_wynik->setText(SHA1_wynik);
        } else {
               ui->SHA_wynik->setText("B��d"); //inaczej wypisz b��d
        }
}
