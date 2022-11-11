#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    char display[4];
    char *tableau[5][27];
    int arme, distance, AttackIndex;

    bool shield, flanked, reared, suprised, stunned, switches, half;
    void do_result();
    int set_portee(int portee);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_radioButton_6_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_7_toggled(bool checked);

    void on_radioButton_8_toggled(bool checked);

    void on_checkBox_9_toggled(bool checked);

    void on_pushButton_clicked();

    void on_treeWidget_clicked(const QModelIndex &index);

    void on_checkBox_toggled(bool checked);

    void on_spinBox_4_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_checkBox_10_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif //MAINWINDOW_H
