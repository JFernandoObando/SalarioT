/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:06/07/2020
Deber:Ejercicio Salario
*/
#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include<QtCore>
#include<QtGui>
#include<help.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

public slots:
    void calcular();
    void guardarComo();
    void guardar();
    void abrir();
    void nuevo();






private slots:
    void on_actionAcerca_de_triggered();

private:
    Ui::Principal *ui;
    void limpiar();
    QString archivoExistente;
};
#endif // PRINCIPAL_H
