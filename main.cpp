#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QScreen>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(QLocale(), QString("translations"), QString("_"), QString(":/languages"));
    a.installTranslator(&translator);
    MainWindow w;
    QRect Geo = qApp->screens()[0]->geometry();
    w.setGeometry(Geo);
    w.show();
    return a.exec();
}
