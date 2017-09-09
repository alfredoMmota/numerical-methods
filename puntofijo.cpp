#include "puntofijo.h"
#include "ui_puntofijo.h"
#include <cmath>
#include "QString"
#include "QDoubleSpinBox"
#include "QSpinBox"

puntofijo::puntofijo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::puntofijo)
{
    ui->setupUi(this);
    /*Se hacen las conexiones de los slot de la interfaz*/
    /*The interface connections to the program are created*/
    connect(ui->calcular,SIGNAL(clicked()),this,SLOT(Metodo()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(Limpiar()));
}

puntofijo::~puntofijo()
{
    delete ui;
}
    /*Se declara el valor de la funcion que se va a evaluar*/
    /*Enter the function to be evaluated*/
double puntofijo::funcion(double x){
        return (667.38*(1-exp(-0.146843*x)))/40;
}
    /*Se elabora el codigo para la resolucion del metodo*/
    /*The code for the solution of the method is elaborated */
void puntofijo::Metodo(){
    QString resultado,valor1,valor2,valor3;/*Se crean variables de tipo String*/
                                            /*String variables are created*/
    /*Se leen los valores que ingresa el usuario*/
    /*read the values entered by the user*/
    double X=ui->x->value();
    double error=ui->error->value();
    /*Se inicializan las variables utilizables en el metodo*/
    /*The variables are inicialized*/
    double ea=100.0;
    double Xr=0.0;
    int iteracion=1;
    /*Se crea el ciclo en donde se llevaran a cabo las iteraciones del metodo*/
    /*The cycle is created for the solution of the method*/
    while(ea>error){/*se establece la condicion para terminar el metodo*/
                    /*establishes the condition to finish the method*/
        Xr=funcion(X);/*Se evalua la funcion con el valor de X*/
                    /*the funtion is evaluated with the value of x*/
        ea=100*std::abs((Xr-X)/Xr);/*Se calcula el nuevo error*/
                                    /*the error is calculated*/
        X=Xr;/*Se cambia el valor de X=Xr*/
            /*change the value of X with the result of Xr*/
        iteracion=iteracion+1;/*Se van incrementando el # de iteraciones*/
                               /*the iteration number is increased*/
    }
    /*Se asigna el formato para el despliegue del resultado*/
    /*the result is generated as string*/
    resultado.append("Iter #").append(valor1.setNum(iteracion).append("\nValor de X: ").append(valor2.setNum(Xr)).append("\nError(%): ").append(valor3.setNum(ea)));
    ui->Resultado->setText(resultado);/*Se despliega el Resultado*/
                                       /*the result is displayed in the interface*/
}
    /*Se elabora la funcion de limpiar los datos ingresados por el usuario*/
    /*funtion "Limpiar" is defined to clean the interface */
void puntofijo::Limpiar(){
    ui->x->setValue(0.0);/*Se regresan los valores a 0*/
    ui->error->setValue(0.0);
                           /*cleaning the values in the interface*/
    ui->Resultado->clear();/*Se limpia la impresion del resultado*/
                            /*cleaning the result in screen*/
}
//code elaborated by Jose Alfredo Mendoza Mota,Gibran Omar Estrada Gomez,Antonio Herrera Diaz y Ana Karen Razo Francisco//
