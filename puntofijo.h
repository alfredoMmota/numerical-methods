#ifndef PUNTOFIJO_H
#define PUNTOFIJO_H

#include <QMainWindow>

namespace Ui {
class puntofijo;
}

class puntofijo : public QMainWindow
{
    Q_OBJECT

public:
    explicit puntofijo(QWidget *parent = 0);
    ~puntofijo();
    double funcion(double x);/*Se crea la variable funcion de tipo double*/
                             /*The double-type variable "funcion" is defined*/

private slots:
    void Metodo();/*Se crea el Slot para la elaboracion del metodo*/
                    /*The function "Metodo" is defined*/
    void Limpiar();/*Se crea el Slot para limpiar los valores que ingresa el usuario*/
                    /*The function "Limpiar" is defined*/
private:
    Ui::puntofijo *ui;
};

#endif // PUNTOFIJO_H
