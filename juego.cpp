#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,400);
    this->dibujar();
    ui->marco->setPixmap(lienzo);
    QPoint centro = ui->marco->geometry().center();
    m_circulo = new Circulo();
    m_circulo->setX(centro.x());
    m_circulo->setY(centro.y());
    if(ui->btnAbajo->isChecked()){
        on_btnAbajo_released();
    }
}

Juego::~Juego()
{
    delete ui;
}


void Juego::on_btnArriba_released()
{
    Configuracion a;
    QPainter painter(&lienzo);
    QPen pens;
    pens.setColor(a.color());
    pens.setWidth(450);
    painter.setPen(pens);
    painter.drawEllipse(m_circulo->x(),m_circulo->y()+7,m_circulo->x(),m_circulo->y()+7);
}


void Juego::on_btnAbajo_released()
{
    Configuracion a;
    QPainter painter(&lienzo);
    QPen pens;
    pens.setColor(a.color());
    pens.setWidth(350);
    painter.setPen(pens);
    painter.drawEllipse(50,50,50,50);
    update();
}

void Juego::on_btnIzqueirda_released()
{
    Configuracion a;
    QPainter painter(&lienzo);
    QPen pens;
    pens.setColor(a.color());
    pens.setWidth(350);
    painter.setPen(pens);
    painter.drawEllipse(50,50,50,50);
    update();
}

void Juego::on_btnDerecha_released()
{
    Configuracion a;
    QPainter painter(&lienzo);
    QPen pens;
    pens.setColor(a.color());
    pens.setWidth(350);
    painter.setPen(pens);
    painter.drawEllipse(50,50,50,50);
    update();
}

void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}

void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{
    Configuracion a;
    lienzo.fill(Qt::white);
    QPoint centro = ui->marco->geometry().center();
    m_circulo = new Circulo();
        m_circulo->setX(centro.x());
        m_circulo->setY(centro.y());
    QPainter painter(&lienzo);
    QPen pens;
    pens.setColor(a.color());
    pens.setWidth(340);
    painter.setPen(pens);
    painter.drawEllipse(m_circulo->x(),m_circulo->y(),m_circulo->x(),m_circulo->y());
}

