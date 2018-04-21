#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {



class MainWindow;
class MD5;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void otworz_plik();
    void zapisz_sumy();
    void wczytaj_sumy();
    void CRC();
    void sha1main();
    void sha1file(char* filename);
    void block(unsigned char* str, unsigned long &h0, unsigned long &h1,
                unsigned long &h2, unsigned long &h3, unsigned long &h4);
    void Plik();
    void CRC32();
    unsigned long int odwroc_bity(unsigned long int x, int nbits);
    void stworz_tablice(unsigned long int* tab);

    class MD5;
    void MD5Main();


private:
    Ui::MainWindow *ui;

private slots:
    void on_actionOtw_rz_triggered();
    void on_actionZapisz_sumy_kontrolne_triggered();
    void on_actionWczytaj_sumy_kontrolne_triggered();
    void on_actionZamknij_triggered();


    void on_SHA_porownaj_clicked();
    void on_MD5_porownaj_clicked();
    void on_CRC32_porownaj_clicked();
    void on_SHA_oblicz_clicked();
    void on_CRC32_oblicz_clicked();
    void on_MD5_oblicz_clicked();
};
#endif // MAINWINDOW_H
