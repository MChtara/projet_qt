#include "statespace.h"
#include "ui_statespace.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegExp>
#include <QString>
#include <QTextStream>
#include <QTextDocument>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPainter>
Statespace::Statespace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statespace)
{
    ui->setupUi(this);

}

Statespace::~Statespace()
{
    delete ui;
}

void Statespace::choix_bar()
{
QSqlQuery q1,q2,q3,q4;
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM CRUD");
q1.exec();

q2.prepare("SELECT * FROM CRUD WHERE COMBO='choix1'");
q2.exec();

q3.prepare("SELECT * FROM CRUD WHERE COMBO='choix2'");
q3.exec();

q4.prepare("SELECT * FROM CRUD WHERE COMBO='choix3' ");
q4.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}

c1=c1/tot;
c2=c2/tot;
c3=c3/tot;


// Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("choix 1");
        QBarSet *set1 = new QBarSet("choix 2");
        QBarSet *set2 = new QBarSet("choix 3");

        // Assign values for each bar
        *set0 << c1;
        *set1 << c2;
        *set2 << c3;



        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        series->append(set0);
        series->append(set1);
        series->append(set2);


        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);


        // Adds categories to the axes
       // QBarCategoryAxis *axis = new QBarCategoryAxis();



        // 1. Bar chart
       // chart->setAxisX(axis, series);

        // Used to change the palette
        QPalette pal = qApp->palette();

        // Change the color around the chart widget and text
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));

        // Apply palette changes to the application
        qApp->setPalette(pal);


// Used to display the chart
chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}
