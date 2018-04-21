#include <QFileDialog>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

extern QString tekst;

unsigned long int MainWindow::odwroc_bity(unsigned long int x, int nbits)
{
    unsigned long int ret = 0;
    int i = 0;

    for(i = 1; i <= nbits; i++)
    {
        if(x & 1)
        ret |= 1 << (nbits - i);
        x >>= 1;
    }
    return ret;
}

void MainWindow::stworz_tablice(unsigned long int* tab)					//Tworzenie tablicy ze sta�ymi
{
    unsigned long int ascii = 0;
    int i = 0, j = 0;
    for(i = 0; i < 256; i++)
    {
        ascii = odwroc_bity(i, 8) << 24;

        for(j = 0; j < 8; j++)
            ascii = ((ascii & 0x80000000) != 0) ? (ascii << 1) ^ 0x04c11db7 : ascii << 1;

        ascii = odwroc_bity(ascii, 32);
        tab[i] = ascii;
    }
}



void MainWindow::CRC32()
{
    std::string filename_temp = tekst.toLocal8Bit().constData();
    char filename[256];
    strcpy(filename, filename_temp.c_str());            //^^operacje potrzebne do konwersji z QString na tablice char
    FILE *f;
    char wynik[50];
    unsigned long filesize;
    f = fopen(filename, "rb");


    if(f != NULL)
    {
        fseek(f, 0, SEEK_END);                          //uzyskujemy rozmiar pliku
        filesize = ftell(f);
        rewind(f);                                      //wracamy na pocz�tek pliku
        char *bufor = new char[filesize];
        fread(bufor,1,filesize,f);
        unsigned long int tab[256];
        stworz_tablice(tab);
        unsigned long int crc32 = 0xffffffff;

        for(int i = 0; i < filesize; i++)
            crc32 = tab[(crc32 ^ bufor[i]) & 0xff] ^ (crc32 >> 8);

        crc32 ^= 0xffffffff;
        sprintf(wynik,"%lx", crc32);

        ui->CRC32_wynik->setText(wynik);
    }
    else
    {
        ui->CRC32_wynik->setText("B��d");
    }
}
