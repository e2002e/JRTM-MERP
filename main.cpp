#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QScreen>
#include <stdio.h>
QRect screenGeometry;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(QLocale(), QString("translations"), QString("_"), QString(":/languages"));
    a.installTranslator(&translator);
    MainWindow w;
    QSize size = qApp->screens()[0]->size();
    w.setGeometry(size.width(), size.height(), 1, 1);
    w.show();

    return a.exec();
}
