/*
Curso:Programacion Orientada a Objetos
Nombre: Juan Fernando Obando Castillo       <jobandoc3@est.ups.edu.ec>
Fecha:06/07/2020
Deber:Ejercicio Salario
*/
#include "principal.h"

#include <QApplication>
#include<QTranslator>
#include<QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     QTranslator traduccion;
     //Solicitando al usuario que seleccione un idioma
     QStringList idiomas;
     idiomas<<"Francés"<<"Italiano"<<"Español";
     QString idioma=QInputDialog::getItem(NULL,
                                          "Idioma",
                                          "Seleccione un idioma",
                                          idiomas);
     //Dependiendo del idioma seleccionado,carga el archivo de traduccion*/
    if(idioma=="Francés"){
         traduccion.load(":/Salario_fr_FR.qm");

     }else if(idioma=="Italiano"){
         traduccion.load(":/Salario_it.qm");
     }
     //Si es diferente de español se instala la traduccion en
     //toda la aplicacion
     if(idioma!="Español"){
         a.installTranslator(&traduccion);
     }

    Principal w;
    w.show();
    return a.exec();
}
