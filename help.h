/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:06/07/2020
Deber:Ejercicio Salario
*/
#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;
};

#endif // HELP_H
