/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:06/07/2020
Deber:Ejercicio Salario
*/
#include "principal.h"
#include "ui_principal.h"
#include <QFileDialog>
#include<QDebug>
#include<QtGui>
#include<QtCore>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->pushBcalcular,SIGNAL(released()),
            this,SLOT(calcular()));
    connect(ui->mnuCalcular,SIGNAL(triggered(bool)),
            this,SLOT(calcular()));
    connect(ui->mnuSalir,SIGNAL(triggered(bool)),
            this,SLOT(close()));
    connect(ui->mnuGuardar_como,SIGNAL(triggered(bool)),
            this,SLOT(guardarComo()));
    connect(ui->mnuAbrir,SIGNAL(triggered(bool)),
            this,SLOT(abrir()));
    connect(ui->mnuNuevo,SIGNAL(triggered(bool)),
            this,SLOT(nuevo()));
    connect(ui->mnuGuardar,SIGNAL(triggered(bool)),
            this,SLOT(guardar()));


}

Principal::~Principal()
{
    delete ui;
}

void Principal::calcular()
{

    //obtener Datos;
    QString nombre=ui->linEdNombre->text();
    float const HoExtra=20.10;
    float horasTrabajadas=ui->spinBoxHoras->value();
    if(nombre==""||horasTrabajadas==0){

        ui->statusbar->showMessage("No se a ingresado datos a calcular",5000);
        return;
    }else{
        ui->statusbar->clearMessage();

    }
    //Calcular horas extra
    int extra=0;
    if(extra>40){

        extra=horasTrabajadas-40;
        horasTrabajadas=40;
    }
    //Calculo del salario
    float salario=0;
    if(ui->radButMatutina->isChecked()){
        salario=horasTrabajadas*5.15+extra*HoExtra;
    }else if(ui->radButVespertina->isChecked()){
        salario=horasTrabajadas*8.50+extra*HoExtra;
    }else if(ui->radButNocturna->isChecked()){
        salario=horasTrabajadas*12.65+extra*HoExtra;
    }
    //Calcular el descuento
    float descuento=salario*9.5/100;
    float salario_neto=salario-descuento;


    //Imprimir Resultado
    QString resultado ="\nObrero: "+nombre+"\n";
    resultado+="Salario $"+QString::number(salario)+"\n";
    resultado+="Descuento (9.5%): $"+QString::number(descuento)+"\n";
    resultado+="Salario neto $"+QString::number(salario_neto)+"\n";
    resultado+="---\n";

    ui->plainTextEdit->appendPlainText(resultado);
    limpiar();

}

void Principal::guardarComo()
{

    QString filename=QFileDialog::getSaveFileName(this,
    "Guardar datos",QDir::home().absolutePath(),"Archivo de texto (*.txt)");

    QFile data (filename);


    if(data.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream salida(&data);
        salida<<ui->plainTextEdit->toPlainText();
        ui->statusbar->showMessage("Datos almacenados en "+filename,5000);

    }
    data.close();
}

void Principal::guardar()
{

    QFile filename(archivoExistente);
    if(filename.open(QFile::WriteOnly)|QFile::Text){
        QTextStream salida(&filename);
        salida<<ui->plainTextEdit->toPlainText();
        ui->statusbar->showMessage("Archivo guardado");
        filename.flush();
        filename.close();

    }
}

void Principal::abrir()
{
    ui->mnuGuardar->setEnabled(true);
    archivoExistente=QFileDialog::getOpenFileName(this,
                                                  "Abrir un archivo");

    QFile dato(archivoExistente);


    if(!archivoExistente.isEmpty()){

        QFile file(archivoExistente);
        if(file.open(QFile::ReadOnly|QFile::Text)){
            QTextStream in(&file);
            QString   archivo=in.readAll();
            qDebug()<<archivo;
            file.close();
            ui->plainTextEdit->setPlainText(archivo);
        }
    }
}

void Principal::nuevo()
{

    archivoExistente="";
    ui->plainTextEdit->setPlainText("");
    ui->statusbar->showMessage("Archivo nuevo");
}


void Principal::limpiar()
{
    ui->linEdNombre->setText("");
    ui->spinBoxHoras->setValue(0);
    ui->radButMatutina->setChecked(true);
    ui->linEdNombre->setFocus();
}

void Principal::on_actionAcerca_de_triggered()
{
   Help *ventana=new Help;
   ventana->show();

}
