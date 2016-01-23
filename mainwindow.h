#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QEventLoop>
#include <QFontDatabase>
#include <QLabel>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "vue.h"

#define TAILLE 8

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sourisBougee(QPoint position);
    void on_sourisCliquee(int touche);
    void on_sourisRelachee();

private:
    Ui::MainWindow *ui;
    Vue *jeu;
    QGraphicsScene *sceneNiveaux,*sceneMenu,*sceneJeu,*sceneEditeur;
    QGraphicsRectItem *curseurMenu,*curseurJeu,*boutonMenu[2];
    QSqlDatabase db;

    //Jeu
    QGraphicsRectItem *cadreJeu;
    QGraphicsRectItem *cases[TAILLE][TAILLE];

    //Editeur
    QGraphicsRectItem *tableau[TAILLE][TAILLE];
    QGraphicsRectItem *indicDepart[TAILLE];
    QString base[TAILLE][TAILLE];
    short currentSelection,depart;
    QGraphicsRectItem *selection[6];
    QPen *pen;
};

#endif // MAINWINDOW_H
