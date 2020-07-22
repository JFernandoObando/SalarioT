/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:06/07/2020
Deber:Ejercicio Salario
*/
#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
}

Help::~Help()
{
    delete ui;
}
