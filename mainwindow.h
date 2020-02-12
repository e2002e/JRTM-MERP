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

    void on_pushButton_5_clicked();

    void on_checkBox_10_toggled(bool checked);

private:
    const char *tranchantes[5][23] = {{"M","0","0","0","0","0","0","0","7","9A","10A","11B","13C","15C","17D","19D","20D","21E","23E","25E","27E","28E","30E"},\
                                {"M","0","0","0","0","0","3","5","7A","9A","10B","12B","13B","14C","15C","17C","18D","19D","20D","22D","23E","24E","25E"},\
                                {"M","0","0","0","0","0","2","3","5","6","7A","9A","10B","11B","12B","13C","15C","16C","17D","18D","20D","21E","22E"},\
                                {"M","0","0","1","1","2","3","4","5","6","7","8","9","10A","11A","12B","13B","13C","14C","15C","16D","17D","18E"},\
                                {"M","0","1","1","2","2","3","3","4","5","5","6","6","7","8","8A","9A","9A","10B","11B","11C","12D","12E"}};
    const char *contendantes[5][25] = {{"M","0","0","0","0","0","0","0","0","0","0","6","8","9A","10B","12C","13C","14D","15D","17D","18E","19E","21E","22E","23E"},\
                                 {"M","0","0","0","0","0","0","0","3","5","6","7A","8A","9A","10B","11B","12B","13C","14C","15C","16D","17D","18E","19E","20E"},\
                                 {"M","0","0","0","0","0","0","0","2","3","4","6","7A","8A","9B","10B","11B","12C","13C","15C","16C","17D","18D","19E","20E"},\
                                 {"M","0","0","1","2","3","4","5","6","7","8","9","10","11","12A","13A","14B","15B","16C","17C","18C","19D","20D","21E","22E"},\
                                 {"M","0","1","1","2","3","3","4","5","5","6","7","8","8","9","10","10A","11A","12B","13B","13C","14C","15D","16D","16E"}};
    const char *deuxmain[5][21]   =   {{"M","0","0","0","0","0","0","10A","13B","16C","19D","22D","25D","28E","31E","33E","36E","39E","42E","45E","48E"},\
                                 {"M","0","0","0","8A","10A","13B","15B","17C","20C","22C","24C","27D","29D","31D","33E","36E","38E","40E","43E"},\
                                 {"M","0","0","0","0","2","4A","7A","9B","12B","14C","17C","19C","22C","24D","27D","29D","32E","34E","37E","40E"},\
                                 {"M","0","0","0","3","5","7","9","11","12A","14A","16B","18B","20C","22C","24C","26D","28D","29E","31E","33E"},\
                                 {"M","0","2","3","4","5","6","7","8","9","11","12A","13A","14B","15B","16C","17C","19D","20D","21E","22E"}};
    const char *projectiles[5][18] = {{"M","0","0","0","0","0","8A","10B","11C","13C","15C","16D","18D","20D","22E","23E","25E","27E"},\
                                {"M","0","0","4","6","8A","10A","12B","13B","14B","16C","17C","19D","20D","22D","23E","25E","26E"},\
                                {"M","0","0","0","3","5","7A","9A","10B","12B","13B","15C","17C","19D","21D","23D","25E","26E"},\
                                {"M","0","0","2","4","6","7","8A","10A","13B","14B","16B","17C","19C","20D","22D","23E","25E"},\
                                {"M","0","1","2","3","4","5","6","7","8A","9A","10A","11B","11B","12C","13C","14D","15E"}};
    const char *dynamiques[9][23] =   {{"E","10","30","50","70","80","90","100","100","100","100","100","110","110","120","120","130","130","140","140","150","150","160"},\
                                 {"E","E","10","30","50","60","70","80","90","100","100","100","100","110","110","120","120","130","130","140","140","150","150"},\
                                 {"E","E","E","10","30","50","60","70","80","90","100","100","100","100","110","110","120","120","130","130","140","140","150"},\
                                 {"E","E","E","E","5","10","20","30","40","50","60","70","80","90","100","100","110","110","120","120","130","130","140"},\
                                 {"E","E","E","E","E","5","10","20","30","40","50","60","70","80","90","100","100","110","110","120","120","130","130"},\
                                 {"E","E","E","E","E","E","5","10","20","30","40","50","60","70","80","90","100","100","110","110","120","120","130"},\
                                 {"E","E","E","E","E","E","E","5","10","20","30","40","50","60","70","80","90","100","100","110","110","120","120"},\
                                 {"E","E","E","E","E","E","E","E","E","5","10","20","25","30","40","50","60","70","80","90","100","100","110"},\
                                 {"E","E","E","E","E","E","E","E","E","E","E","5","10","20","30","40","50","60","70","80","90","100"}};
    const char *deplacement[6][6] =   {{"6","6","4.5","3","3","1.5"},\
                                 {"12","10.5","6","6","4.5","3"},\
                                 {"15","12","9","7.5","4.5","3"},\
                                 {"22.5","18","13.5","10.5","6","4.5"},\
                                 {"22.5","18","13.5","10.5","6","4.5"},\
                                 {"37.5","27","18","15","9","6"}};
    const char *rencontres[5][13] =   {{"v/-","r/-","r/-","r/-","r/-","r/-","h/v","h/h","a/-","a/a","a/a","-/a","p/p"},\
                                 {"-/-","v/-","v/-","r/-","r/v","r/v","r/r","r/v","h/h","a/-","a/a","a/a","p/p"},\
                                 {"-/-","-/v","v/v","v/v","v/v","r/v","r/v","r/h","h/h","h/h","a/h","a/a","p/p"},\
                                 {"-/-","-/v","-/v","-/v","-/v","-/v","-/h","v/h","r/h","r/h","h/a","a/a","p/p"},\
                                 {"-/-","-/-","-/-","-/v","-/v","-/h","-/h","-/h","v/a","r/a","h/a","a/p","p/p"}};
    const char *morsures[5][23] =     {{"E","0","1","2","4","5T","6T","8T","9A","10A","12A","13B","14B","15B","17C","19C","20D","26D","28E","30E","36E","38E","40E"},\
                                 {"E","0","0","0","1","2","4","5","7T","9T","10A","11A","12A","13B","15B","16C","17C","20C","23D","25D","30E","33E","36E"},\
                                 {"E","0","0","0","0","1","2","3","5","7T","8T","9A","10A","11A","12B","13B","14C","18C","20C","22D","26D","29E","39E"},\
                                 {"E","0","0","0","0","1","2","3","4","5","6T","7T","8A","9A","10A","11B","11B","15B","18C","20C","23D","25D","27E"},\
                                 {"E","0","0","0","1","1","2","3","4","5","6","6T","7T","7A","8A","9A","10B","14B","16B","18C","20C","22D","24E"}};
    const char *saisies[5][21] =      {{"E","0","0","1","1","2","4","5","7T","8T","10T","11A","14A","15A","16B","18B","20B","22C","28C","30C","33D"},\
                                 {"E","0","0","0","1","3","4T","6T","7T","8A","9A","10A","12B","13B","14C","16C","18C","20D","26D","28D","30E"},\
                                 {"E","0","0","0","0","1","2","4T","5T","6T","7A","8A","10A","11B","12B","14B","16C","18C","22C","25D","27E"},\
                                 {"E","0","0","0","1","2T","3T","4A","4A","5A","6A","7A","8B","9C","10C","11C","13D","15D","19D","21E","23E"},\
                                 {"E","0","1","1","2T","2A","3A","3A","4A","4A","5B","5B","6C","7C","8C","10D","11D","12D","14E","16E","18E"}};
    const char *sorts[3][27]  =       {{"E","E","+70","+65","+60","+50","+45","+35","+30","+20","+15","+5","0","0","-5","-10","-15","-20","-25","-30","-35","-40","-45","-50","-65","-90"},\
                                 {"E","E","E","E","+45","+40","+35","+30","+25","+20","+15","+10","+5","0","0","-5","-5","-10","-15","-20","-25","-30","-35","-40","-45","-65","-90"},\
                                 {"E","E","E","E","E","+45","+40","+35","+30","+25","+20","+15","+10","+5","0","0","-5","-5","-10","-25","-30","-35","-40","-45","-50","-65","-90"}};
    int JR[15][16]    =         {{55,50,45,40,35,30,27,24,21,18,15,13,11,9,7,5},\
                                 {60,55,50,45,40,35,32,29,26,23,20,18,16,14,12,10},\
                                 {65,60,55,50,45,40,37,34,31,28,25,23,21,19,17,15},\
                                 {70,65,60,55,50,45,42,39,36,33,30,28,26,24,22,20},\
                                 {75,70,65,60,55,50,47,44,41,38,35,33,31,29,27,25},\
                                 {78,73,68,63,58,53,50,47,44,41,38,36,34,32,30,28},\
                                 {81,76,71,66,61,56,53,50,47,44,41,39,37,35,33,31},\
                                 {84,79,74,69,64,59,56,53,50,47,44,42,40,38,36,34},\
                                 {87,82,77,72,67,62,59,56,53,50,47,45,43,41,39,37},\
                                 {90,85,80,75,70,65,62,59,56,53,50,48,46,44,42,40},\
                                 {92,87,82,77,72,67,64,61,58,55,52,50,48,46,44,42},\
                                 {94,89,84,79,74,69,66,63,60,57,54,52,50,48,46,44},\
                                 {96,91,86,81,76,71,68,65,62,59,56,54,52,50,48,46},\
                                 {98,93,88,83,78,73,70,67,64,61,58,56,54,52,50,48},\
                                 {100,95,90,85,80,75,72,69,66,63,60,58,56,54,52,50}};
    const char *boules[5][26]  =       {{"E","E","1","2","3","4","5A","6A","7A","8A","9A","10B","11B","12B","13B","14B","15C","16C","17C","18C","19C","20C","21C","22C","28D","34E"},\
                                 {"E","E","0","0","0","0","0","0","1","2","3","4","5","6A","7A","8A","9A","10A","10A","11B","11B","12B","12B","13C","16D","19E"},\
                                 {"E","E","0","0","0","0","1","2","3","4","5A","6A","7A","8A","9A","10B","10B","11B","11B","12B","12C","13C","13C","14C","17D","20E"},\
                                 {"E","E","0","0","0","1","2","3","4","5A","6A","7A","8A","9A","10B","11B","11B","12B","12B","13C","13C","14C","14C","15C","18D","21E"},\
                                 {"E","E","0","0","1","2","3","4","5A","6A","7A","8A","9A","10B","11B","12B","12B","13B","13C","14C","14C","15C","15C","16C","19D","22E"}};
    const char *eclairs[5][27]  =     {{"E","E","0","0","0","0","0","0","0","8A","10A","11B","12B","13B","14B","15C","16C","18C","20C","22D","24D","26E","28E","30E","32E","34E","36E"},\
                                 {"E","E","0","0","0","0","1","1","2","3","4A","5A","6B","7B","8B","10B","12C","14C","16C","18C","20D","22D","24E","26E","28E","30E","31E"},\
                                 {"E","E","0","0","0","0","0","1","2","4","5","6","7A","8A","9B","10B","11B","12C","13C","14C","15C","16D","17D","18E","19E","20E","22E"},\
                                 {"E","E","E","0","0","1","1","2","2","3","4","5A","6A","7A","8A","9A","10A","11A","12C","13C","14C","15C","16D","17D","18D","20E","22E"},\
                                 {"E","E","E","1","2","3","4","5","6","7A","7A","8A","8A","9A","9A","10A","10B","11B","12B","12C","13C","14C","15C","16D","17D","18E"}};
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
