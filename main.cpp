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
    QScreen *screen = QGuiApplication::primaryScreen();
    screenGeometry = screen->geometry();
    w.setGeometry(screenGeometry);
    w.show();

    return a.exec();
}
