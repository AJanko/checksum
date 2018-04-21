#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString tekst = NULL;


void MainWindow::otworz_plik()
{
    // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
    // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
    QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/");

    tekst = fileName;
    Plik();
    //QFile plik(fileName);

    // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
    //if(!plik.open(QIODevice::ReadOnly ))
    //    return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku

    // czyścimy wcześniej zapełnioną zmienną tekstową
    //tekst.clear();

    //QDataStream stream(&plik);

    // czytamy wszystkie dane i przenosimy do zmiennej tekst
    //stream >> tekst;

    //plik.close();
}


void MainWindow::Plik()
{
    if(tekst.isNull())
    {
        ui->textBrowser->setText("ŻADEN PLIK NIE JEST OTWARTY");
    }
    else ui->textBrowser->setText("OTWARTY PLIK:   "+tekst);
}



void MainWindow::wczytaj_sumy()
{
    // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
    // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
    QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

    QFile plik(fileName);

    // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
    if(!plik.open(QIODevice::ReadOnly | QIODevice::Text))
        return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku


    QTextStream stream(&plik);

    QString SHA;
    QString MD5;
    QString CRC;

    SHA = stream.readLine();
    MD5 = stream.readLine();
    CRC = stream.readLine();

    // umieszczamy je wewnątrz text box'ów
    ui->SHA_porownaj2->setText(SHA);
    ui->MD5_porownaj_2->setText(MD5);
    ui->CRC32_porownaj_2->setText(CRC);

    plik.close();
}



void MainWindow::zapisz_sumy()
{
     QString fileName = QFileDialog::getSaveFileName
                (this,tr("Zapisz plik jako..."),tr("/home/"),tr("Pliki tekstowe (*.txt)"));

    if(fileName.isEmpty())
        return;

    QFile plik(fileName);
    plik.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    QTextStream stream(&plik);
    stream << ui->SHA_wynik->toPlainText() << "\n" << ui->MD5_wynik->toPlainText() << "\n" <<
              ui->CRC32_wynik->toPlainText();

    plik.close();
}

void MainWindow::on_actionZamknij_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionOtw_rz_triggered()
{
    otworz_plik();
}

void MainWindow::on_actionWczytaj_sumy_kontrolne_triggered()
{
    wczytaj_sumy();
}

void MainWindow::on_actionZapisz_sumy_kontrolne_triggered()
{
    zapisz_sumy();
}

void MainWindow::on_SHA_porownaj_clicked()
{
    if(ui->SHA_wynik->toPlainText() == ui->SHA_porownaj2->toPlainText())
        ui->SHA_wynik2->setText("Suma kontrolna zgadza się");
    else ui->SHA_wynik2->setText("Suma kontrolna nie zgadza się");
}

void MainWindow::on_MD5_porownaj_clicked()
{
    if(ui->MD5_wynik->toPlainText() == ui->MD5_porownaj_2->toPlainText())
        ui->MD5_wynik2->setText("Suma kontrolna zgadza się");
    else ui->MD5_wynik2->setText("Suma kontrolna nie zgadza się");
}

void MainWindow::on_CRC32_porownaj_clicked()
{
    if(ui->CRC32_wynik->toPlainText() == ui->CRC32_porownaj_2->toPlainText())
        ui->CRC32_wynik2->setText("Suma kontrolna zgadza się");
    else ui->CRC32_wynik2->setText("Suma kontrolna nie zgadza się");
}

void MainWindow::on_SHA_oblicz_clicked()
{
    sha1main();
}

void MainWindow::on_CRC32_oblicz_clicked()
{
    CRC32();
}

void MainWindow::on_MD5_oblicz_clicked()
{
    MD5Main();
}
