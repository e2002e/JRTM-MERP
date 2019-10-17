#include <stdio.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::flanked = false; MainWindow::reared = false; MainWindow::suprised = false; MainWindow::stunned = false;
    MainWindow::half = false; MainWindow::shield = false; MainWindow::switches = false;
    MainWindow::AttackIndex = 2;
    MainWindow::distance = 0;
    MainWindow::arme = 2;
    for(int i = 0; i<5;i++){
        for(int j = 0;j<23;j++)
            MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::tranchantes[i][j]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_result()
{
    int step, applieddice;
    step = 0;
    applieddice = (ui->spinBox->value() + ui->spinBox_2->value() - ui->spinBox_3->value());
    if(MainWindow::shield) applieddice -= 25;
    if(MainWindow::flanked) applieddice += 15;
    if(MainWindow::reared) applieddice += 20;
    if(MainWindow::suprised) applieddice += 20;
    if(MainWindow::stunned) applieddice += 20;
    if(MainWindow::switches) applieddice -= 30;
    if(MainWindow::half) applieddice -= 20;
    applieddice -= 10 * ui->spinBox_5->value();

    switch (ui->treeWidget->currentColumn()){
    case 0:
        switch (ui->treeWidget->currentIndex().row()){
        case 0:
            if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4)
                applieddice -= 5;
            else applieddice +=5;
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            break;
        case 1:
            applieddice -= 15;
            if(ui->spinBox->value() <= 1)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(15);
            break;
        case 2:
            if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4)
                applieddice -= 10;
            else applieddice +=10;
            if(ui->spinBox->value() <= 2)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(3);
            break;
        case 3:
            if(ui->spinBox->value() <= 3)
                step = 0;
            else
                step = 1;
            break;
        case 4:
            if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4)
                applieddice += 5;
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(15);
            break;
        case 5:
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            applieddice -= 10;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(30);
            break;
        case 6:
            if(ui->spinBox->value() <= 5)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(20);
            applieddice -= 5;
            break;
        default:
            break;
        }
        break;
    case 1:
        switch (ui->treeWidget->currentIndex().row()){
        case 0:
            if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4)
                applieddice += 15;
            else applieddice -=10;
            if(ui->spinBox->value() <= 6)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(10);
            break;
        case 1:
            applieddice -= 10;
            if(ui->spinBox->value() <= 6)
                step = 0;
            else
                step = 1;
            break;
        case 2:
            applieddice +=5;
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(10);
            break;
        case 3:
            if(ui->spinBox->value() <= 2)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(5);
            break;
        case 4:
            applieddice -= 10;
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            if(ui->checkBox->isChecked() == true)
                applieddice -= set_portee(2);
            break;
        case 5:
            applieddice += 10;
            if(ui->spinBox->value() <= 8)
                step = 0;
            else
                step = 1;
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (ui->treeWidget->currentIndex().row()){
        case 0:
            applieddice -=10;
            if(ui->spinBox->value() <= 3)
                step = 0;
            else
                step = 1;
            break;
        case 1:
            if(ui->spinBox->value() <= 5)
                step = 0;
            else
                step = 1;
            break;
        case 2:
            applieddice += 10;
            if(ui->spinBox->value() <= 8)
                step = 0;
            else
                step = 1;
            break;
        case 3:
            if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4)
                applieddice += 5;
            else applieddice -= 5;
            if(ui->spinBox->value() <= 5)
                step = 0;
            else
                step = 1;
            break;
        case 4:
            if(ui->spinBox->value() <= 7)
                step = 0;
            else
                step = 1;
            applieddice -= 5;
            break;
        case 5:
            applieddice += 15;
            if(ui->spinBox->value() <= 7)
                step = 0;
            else
                step = 1;
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (ui->treeWidget->currentIndex().row()){
        case 0:
            applieddice -=5;
            applieddice -= set_portee(40);
            if(ui->spinBox->value() <= 7)
                step = 0;
            else
                step = 1;
            break;
        case 1:
            applieddice -= set_portee(75);
            if(ui->checkBox_2->isChecked() == true)
                applieddice -= 25;
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            break;
        case 2:
            if(ui->spinBox_4->value() < 46)
                applieddice += 20;
            applieddice -= set_portee(90);
            if(ui->spinBox->value() <= 5)
                step = 0;
            else
                step = 1;
            break;
        case 3:
            if(ui->checkBox_2->isChecked() == true)
                applieddice -= 35;
            applieddice -= set_portee(100);
            if(ui->spinBox->value() <= 5)
                step = 0;
            else
                step = 1;
            break;
        case 4:
            if(ui->checkBox_2->isChecked() == true)
                applieddice -= 10;
            applieddice -= set_portee(60);
            if(ui->spinBox->value() <= 4)
                step = 0;
            else
                step = 1;
            break;
        case 5:
            applieddice -= set_portee(50);
            if(ui->spinBox->value() <= 6)
                step = 0;
            else
                step = 1;
            break;
        default:
            break;
        }
        break;
    case 4:
        if(ui->spinBox->value() < 3)
            step = 0;
        else step = 1;
        break;
    case 5:
        if(ui->spinBox->value() < 3)
            step = 0;
        else step = 1;
        break;
    case 6:
        applieddice = ui->spinBox->value() + ui->spinBox_2->value();
        switch(ui->comboBox_8->currentIndex()){
        case 0:
            applieddice -= 30;
            break;
        case 1:
            applieddice -= 15;
            break;
        case 3:
            applieddice += 10 ;
            break;
        case 4:
            applieddice += 20;
            break;
        default:
            break;
        }
        if(ui->spinBox_4->value() == 0)
            applieddice += 30;
        else if(ui->spinBox_4->value() > 0 &&  ui->spinBox_4->value() < 11)
            applieddice += 10;
        else if(ui->spinBox_4->value() > 50 && ui->spinBox_4->value() < 101)
            applieddice -= 10;
        else if(ui->spinBox_4->value() > 100 && ui->spinBox_4->value() < 301)
            applieddice -= 20;
        else if(ui->spinBox_4->value() > 300)
            applieddice -= 30;

        switch(ui->treeWidget->currentIndex().row()){
        case 0:
            if(ui->spinBox->value() < 3)
                step = 0;
            else step = 1;
            break;
        case 1:
            if(ui->spinBox->value() < 5)
              step = 0;
            else step = 1;
            break;
        case 2:
            if(ui->spinBox->value() < 3)
                step = 0;
            else step = 1;
            break;
        case 3:
            if(ui->spinBox->value() < 3)
                step = 0;
            else step = 1;
            break;
        case 4:
            if(ui->spinBox->value() < 3)
                step = 0;
            else step = 1;
            break;
        case 5:
            if(ui->spinBox->value() < 3)
                step = 0;
            else step = 1;
            break;
          default:
            break;
        }
    break;
    default:
        break;
    }

    int armor = ui->comboBox_2->currentIndex();

    if(step > 0)
    {
        if(applieddice > 8 && applieddice <= 35) step = 1;
        else if(applieddice > 35 && applieddice <= 40) step = 2;
        else if(applieddice > 40 && applieddice <= 45) step = 3;
        else if(applieddice > 45 && applieddice <= 50) step = 4;
        else if(applieddice > 50 && applieddice <= 55) step = 5;
        else if(applieddice > 55 && applieddice <= 60) step = 6;
        else if(applieddice > 60 && applieddice <= 65) step = 7;
        else if(applieddice > 65 && applieddice <= 70) step = 8;
        else if(applieddice > 70 && applieddice <= 75) step = 9;
        else if(applieddice > 75 && applieddice <= 80) step = 10;
        else if(applieddice > 80 && applieddice <= 85) step = 11;
        else if(applieddice > 85 && applieddice <= 90) step = 12;
        else if(applieddice > 90 && applieddice <= 95) step = 13;
        else if(applieddice > 95 && applieddice <= 100) step = 14;
        else if(applieddice > 100 && applieddice <= 105) step = 15;
        else if(applieddice > 105 && applieddice <= 110) step = 16;
        else if(applieddice > 110 && applieddice <= 115) step = 17;
        else if(applieddice > 115 && applieddice <= 120) step = 18;
        else if(applieddice > 120 && applieddice <= 125) step = 19;
        else if(applieddice > 125 && applieddice <= 130) step = 20;
        else if(applieddice > 130 && applieddice <= 135) step = 21;
        else if(applieddice > 135 && applieddice <= 140) step = 22;
        else if(applieddice > 140 && applieddice <= 145) step = 23;
        else if(applieddice > 145) step = 24;
        if(AttackIndex == 0)
        {
            if(step < 4)
                step = 1;
            else step -= 2;
        }
        if(AttackIndex == 2)
        {
            if(step < 6)
                step = 1;
            else step -= 4;
        }
        if(AttackIndex == 3)
        {
            if(step < 9)
                step = 1;
            else step -= 7;
        }
        if(AttackIndex == 4)
        {
            if(step < 4)
                step = 1;
            else step -= 2;
            switch (ui->comboBox_5->currentIndex()) {
            case 0:
                if(step > 9)
                    step = 9;
                    break;
            case 1:
                if(step > 13)
                    step = 13;
                    break;
            case 2:
                if(step > 16)
                    step = 16;
                    break;
            case 3:
                if(step > 19)
                    step = 19;
                    break;
            default:
                 break;
            }
        }
        if(AttackIndex == 5)
        {
            if(step < 6)
                step = 1;
            else step -= 4;
            switch (ui->comboBox_5->currentIndex())
            {
            case 0:
                if(step > 7)
                    step = 7;
                    break;
            case 1:
                if(step > 11)
                    step = 11;
                    break;
            case 2:
                if(step > 14)
                    step = 14;
                    break;
            case 3:
                if(step > 17)
                    step = 17;
                    break;
            default:
                break;
            }
        }
        if(AttackIndex == 6)
        {
            if(applieddice > 2 && applieddice <= 4) step = 1;
            else if(applieddice > 4 && applieddice <= 8) step = 2;
            else if(applieddice > 8 && applieddice <= 12) step = 3;
            else if(applieddice > 12 && applieddice <= 16) step = 4;
            else if(applieddice > 16 && applieddice <= 20) step = 5;
            else if(applieddice > 20 && applieddice <= 24) step = 6;
            else if(applieddice > 24 && applieddice <= 28) step = 7;
            else if(applieddice > 28 && applieddice <= 32) step = 8;
            else if(applieddice > 32 && applieddice <= 36) step = 9;
            else if(applieddice > 36 && applieddice <= 40) step = 10;
            else if(applieddice > 40 && applieddice <= 44) step = 11;
            else if(applieddice > 44 && applieddice <= 48) step = 12;
            else if(applieddice > 48 && applieddice <= 52) step = 13;
            else if(applieddice > 52 && applieddice <= 56) step = 14;
            else if(applieddice > 56 && applieddice <= 60) step = 15;
            else if(applieddice > 60 && applieddice <= 64) step = 16;
            else if(applieddice > 64 && applieddice <= 68) step = 17;
            else if(applieddice > 68 && applieddice <= 72) step = 18;
            else if(applieddice > 72 && applieddice <= 76) step = 19;
            else if(applieddice > 76 && applieddice <= 80) step = 20;
            else if(applieddice > 80 && applieddice <= 84) step = 21;
            else if(applieddice > 84 && applieddice <= 88) step = 22;
            else if(applieddice > 88 && applieddice <= 92) step = 23;
            else if(applieddice > 92 && applieddice <= 96) step = 24;
            else if(applieddice > 96 && applieddice <= 99) step = 25;
            else if(applieddice > 99) step = 26;

            if(ui->spinBox->value() > 96 && ui->spinBox->value() <= 99) step = 25;
            else if(ui->spinBox->value() > 99) step = 26;

            if(ui->comboBox_2->currentIndex() == 0)
              armor = 0;
            else if(ui->comboBox_2->currentIndex() == 1 || ui->comboBox_2->currentIndex() == 2)
              armor = 1;
            else if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4)
              armor = 2;
          }
        if(AttackIndex == 7)
          {
            if(applieddice < 9) step = 1;
            else if(applieddice < 13) step = 2;
            else if(applieddice < 17) step = 3;
            else if(applieddice < 21) step = 4;
            else if(applieddice < 25) step = 5;
            else if(applieddice < 29) step = 6;
            else if(applieddice < 33) step = 7;
            else if(applieddice < 37) step = 8;
            else if(applieddice < 41) step = 9;
            else if(applieddice < 45) step = 10;
            else if(applieddice < 49) step = 11;
            else if(applieddice < 53) step = 12;
            else if(applieddice < 57) step = 13;
            else if(applieddice < 61) step = 14;
            else if(applieddice < 65) step = 15;
            else if(applieddice < 69) step = 16;
            else if(applieddice < 73) step = 17;
            else if(applieddice < 77) step = 18;
            else if(applieddice < 81) step = 19;
            else if(applieddice < 85) step = 20;
            else if(applieddice < 89) step = 21;
            else if(applieddice < 93) step = 22;
            else if(applieddice < 97) step = 23;
            else if(applieddice < 99) step = 24;
            else if(applieddice > 99) step = 25;
            if(ui->spinBox->value() > 96 && ui->spinBox->value() < 100) step = 24;
            else if(ui->spinBox->value() > 99) step = 25;
          }
        if(AttackIndex == 8 || AttackIndex == 9 || AttackIndex == 10 || AttackIndex == 11)
        {
            if(applieddice > 20)
              step += 2;
            else if(applieddice > 10) step = 2;
            else if(applieddice > 2) step = 1;
            if(AttackIndex == 8) {if(step > 14) step = 14;}
            else if(AttackIndex == 9) {if(step > 18) step = 18;}
            else if(AttackIndex == 10) {if(step > 22) step = 22;}
        }
    }
    ui->result->setText(tableau[armor][step]);
}




void MainWindow::on_radioButton_6_toggled(bool checked)
{
    MainWindow::shield = checked;
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    MainWindow::flanked = checked;
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    MainWindow::reared = checked;
}

void MainWindow::on_radioButton_7_toggled(bool checked)
{
    MainWindow::suprised = checked;
}

void MainWindow::on_radioButton_8_toggled(bool checked)
{
    MainWindow::stunned = checked;
}

void MainWindow::on_radioButton_9_toggled(bool checked)
{
    MainWindow::switches = checked;
}

void MainWindow::on_radioButton_10_toggled(bool checked)
{
    MainWindow::half = checked;
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::do_result();
}


void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    switch (index.column()) {
    case 0:
        ui->groupBox_6->setEnabled(true);
        ui->groupBox->setEnabled(true);
        ui->comboBox_5->setEnabled(false);
        ui->spinBox_5->setEnabled(true);
        ui->spinBox_5->setValue(0);
        ui->comboBox_8->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->spinBox_4->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        for(int i = 0; i<5;i++){
            for(int j = 0;j<23;j++)
                MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::tranchantes[i][j]);
        }
        MainWindow::AttackIndex = 0;
        switch (index.row()) {
        case 0:
            ui->label_5->setText("Taille M(B)");
            ui->checkBox->setEnabled(false);
            break;
        case 1:
            ui->label_5->setText("Perforation(C) M(B)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 0;
            break;
        case 2:
            ui->label_5->setText("Taille M(B)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 1;
            break;
        case 3:
            ui->label_5->setText("Taille M(B)");
            ui->checkBox->setEnabled(false);
            break;
        case 4:
            ui->label_5->setText("Taille M(B)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 2;
            break;
        case 5:
            ui->label_5->setText("Perforation M(C)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 3;
            break;
        case 6:
            ui->label_5->setText("Perforation Taille(A) M(C)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 4;
            break;
        default:
            break;
        }
        break;
    case 1:
        ui->groupBox_6->setEnabled(true);
        ui->groupBox->setEnabled(true);
        ui->comboBox_5->setEnabled(false);
        ui->spinBox_5->setEnabled(true);
        ui->spinBox_5->setValue(0);
        ui->comboBox_8->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->spinBox_4->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        for(int i = 0; i<5;i++){
            for(int j = 0;j<25;j++)
                MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::contendantes[i][j]);
        }
        MainWindow::AttackIndex = 1;
        switch (index.row()) {
        case 0:
            ui->label_5->setText("Saisie M(A)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 5;
            break;
        case 1:
            ui->label_5->setText("Saisie(C) Taille(A) M(A)");
            ui->checkBox->setEnabled(false);
            break;
        case 2:
            ui->label_5->setText("Contusion M(A)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 6;
            break;
        case 3:
            ui->label_5->setText("Contusion M(A)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 7;
            break;
        case 4:
            ui->label_5->setText("Contusion(D) M(A)");
            ui->checkBox->setEnabled(true);
            MainWindow::arme = 8;
            break;
        case 5:
            ui->label_5->setText("Contusion Perforation(A), M(Contusion(B))");
            ui->checkBox->setEnabled(false);
            break;
        default:
            break;
        }
        break;
    case 2:
        ui->groupBox_6->setEnabled(true);
        ui->groupBox->setEnabled(true);
        ui->comboBox_5->setEnabled(false);
        ui->spinBox_5->setEnabled(true);
        ui->spinBox_5->setValue(0);
        ui->comboBox_8->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->spinBox_4->setEnabled(false);

        for(int i = 0; i<5;i++){
            for(int j = 0;j<21;j++)
                MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::deuxmain[i][j]);
        }
        MainWindow::AttackIndex = 2;
        switch (index.row()) {
        case 0:
            ui->label_5->setText("Contusion M(C)");
            ui->checkBox->setEnabled(false);
            break;
        case 1:
            ui->label_5->setText("Taille Contusion M(C)");
            ui->checkBox->setEnabled(false);
            break;
        case 2:
            ui->label_5->setText("Contusion Perforation M(Contusion(C))");
            ui->checkBox->setEnabled(false);
            break;
        case 3:
            ui->label_5->setText("Taille Contusion M(C)");
            ui->checkBox->setEnabled(false);
            break;
        case 4:
            ui->label_5->setText("Taille Perforation M(D)");
            ui->checkBox->setEnabled(false);
            break;
        case 5:
            ui->label_5->setText("Perforation Déséquilibre M(E)");
            ui->checkBox->setEnabled(false);
            break;
        default:
            break;
        }
        break;
    case 3:
        ui->groupBox_6->setEnabled(true);
        ui->groupBox->setEnabled(true);
        ui->comboBox_5->setEnabled(false);
        ui->comboBox_8->setEnabled(false);
        ui->spinBox_4->setEnabled(true);
        for(int i = 0; i<5;i++){
            for(int j = 0;j<18;j++)
                MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::projectiles[i][j]);
        }
        MainWindow::AttackIndex = 3;
        ui->checkBox->setEnabled(false);
        switch (index.row()) {
        case 0:
            ui->label_5->setText("Saisie Contusion(A) M(Saisie(B))");
            ui->checkBox_2->setEnabled(false);
            ui->spinBox_5->setEnabled(true);
            ui->spinBox_5->setValue(0);
            if(ui->spinBox_4->value() < 8 || ui->spinBox_4->value() > 160)
                ui->pushButton->setEnabled(false);
            MainWindow::arme = 9;
            break;
        case 1:
            ui->label_5->setText("Perforation M(C)");
            ui->spinBox_5->setValue(0);
            ui->spinBox_5->setEnabled(false);
            ui->checkBox_2->setEnabled(true);
            if(ui->spinBox_4->value() < 11 || ui->spinBox_4->value() > 300)
                ui->pushButton->setEnabled(false);
            MainWindow::arme = 10;
            break;
        case 2:
            ui->label_5->setText("Perforation M(E)");
            ui->checkBox_2->setEnabled(false);
            ui->spinBox_5->setEnabled(true);
            ui->spinBox_5->setValue(0);
            if(ui->spinBox_4->value() < 12 || ui->spinBox_4->value() > 360)
                ui->pushButton->setEnabled(false);
            MainWindow::arme = 11;
            break;
        case 3:
            ui->label_5->setText("Perforation M(D)");
            ui->checkBox_2->setEnabled(true);
            ui->spinBox_5->setValue(0);
            ui->spinBox_5->setEnabled(false);
            if(ui->spinBox_4->value() < 12 || ui->spinBox_4->value() > 400)
                ui->pushButton->setEnabled(false);
            MainWindow::arme = 12;
            break;
        case 4:
            ui->label_5->setText("Perforation M(B)");
            ui->checkBox_2->setEnabled(true);
            ui->spinBox_5->setValue(0);
            ui->spinBox_5->setEnabled(false);
            if(ui->spinBox_4->value() < 10 || ui->spinBox_4->value() > 240)
                ui->pushButton->setEnabled(false);
            MainWindow::arme = 13;
            break;
        case 5:
            ui->label_5->setText("Contusion(D) M(A))");
            ui->checkBox_2->setEnabled(false);
            ui->spinBox_5->setValue(0);
            ui->spinBox_5->setEnabled(false);
            if(ui->spinBox_4->value() < 9 || ui->spinBox_4->value() > 200)
                ui->pushButton->setEnabled(false);
            MainWindow::arme = 14;
            break;
        default:
            break;
        }
        break;
    case 4:
        ui->groupBox_6->setEnabled(true);
        ui->groupBox->setEnabled(true);
        MainWindow::AttackIndex = 4;
        for(int i = 0; i<5;i++){
            for(int j = 0;j<23;j++)
                MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::morsures[i][j]);
        }
        ui->spinBox_5->setEnabled(true);
        ui->spinBox_5->setValue(0);
        ui->comboBox_8->setEnabled(false);
        ui->comboBox_5->setEnabled(true);
        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->spinBox_4->setEnabled(false);
        switch(index.row()){
        case 0:
            ui->label_5->setText("Taille Contusion(si grd ou énorme)");
            break;
        case 1:
            ui->label_5->setText("Perforation Taille(C)");
            break;
        case 2:
            ui->label_5->setText("Taille Perforation(B, si grd ou énorme)");
            break;
        case 3:
            ui->label_5->setText("Perforation Contusion(C, si grd ou énorme)");
            break;
        case 4:
            ui->label_5->setText("Taille(T)");
            break;
        case 5:
            ui->label_5->setText("Contusion Contusion(si grd ou énorme)");
            break;
        case 6:
            ui->label_5->setText("Contusion Contusion(si grd ou énorme)");
            break;
        case 7:
            ui->label_5->setText("Déséquilibre(A)");
            break;
        default:
            break;
        }
        break;
    case 5:
        ui->groupBox_6->setEnabled(true);
        ui->groupBox->setEnabled(true);
        MainWindow::AttackIndex = 5;
        for(int i = 0; i<5;i++){
            for(int j = 0;j<21;j++)
                MainWindow::tableau[i][j] = const_cast<char*>(MainWindow::saisies[i][j]);
        }
        ui->spinBox_5->setEnabled(true);
        ui->spinBox_5->setValue(0);
        ui->comboBox_8->setEnabled(false);
        ui->comboBox_5->setEnabled(true);
        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->spinBox_4->setEnabled(false);
        switch(index.row()){
        case 0:
            ui->label_5->setText("Saisie Déséquilibre(C)");
            break;
        case 1:
            ui->label_5->setText("Déséquilibre Contusion(C, si grd ou énorme)");
            break;
        case 2:
            ui->label_5->setText("Saisie(A)");
            break;
        default:
            break;
        }
        break;
    case 6:
        arme = 15;
        ui->groupBox_6->setEnabled(false);
        ui->groupBox->setEnabled(false);
        ui->spinBox_5->setEnabled(true);
        ui->spinBox_5->setValue(0);
        ui->comboBox_8->setEnabled(true);
        ui->comboBox_5->setEnabled(false);
        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->spinBox_4->setEnabled(true);
        switch(index.row()){
        case 0:
            ui->label_5->setText("+BO sort base.\nCible statique: +10.\nA couvert: -10 à -30");
            AttackIndex = 6;
            for(int i = 0; i<3; i++)
              for(int j = 0; j<27; j++)
                tableau[i][j] = const_cast<char*>(sorts[i][j]);
            break;
        case 1:
            ui->label_5->setText("+BO sort base -bonus ag cible.\nA couvert: -10 à -80\nCible au centre zone effet: +20");
            AttackIndex = 7;
            for(int i = 0; i<5; i++)
              for(int j=0; j<26; j++)
                tableau[i][j] = const_cast<char*>(boules[i][j]);
            break;
        case 2:
            ui->label_5->setText("+BO sort dirigés -bonus ag cible.\nA couvert: -10 à -60\nCible utilise son bouclier: -20");
            AttackIndex = 8;
            for(int i = 0; i<5; i++)
              for(int j=0; j<27; j++)
                tableau[i][j] = const_cast<char*>(eclairs[i][j]);
            break;
        case 3:
            ui->label_5->setText("+BO sort dirigés -bonus ag cible.\nA couvert: -10 à -60\nCible utilise son bouclier: -20");
            AttackIndex = 9;
            for(int i = 0; i<5; i++)
              for(int j=0; j<27; j++)
                tableau[i][j] = const_cast<char*>(eclairs[i][j]);
            break;
        case 4:
            ui->label_5->setText("+BO sort dirigés -bonus ag cible.\nA couvert: -10 à -60\nCible utilise son bouclier: -20");
            AttackIndex = 10;
            for(int i = 0; i<5; i++)
              for(int j=0; j<27; j++)
                tableau[i][j] = const_cast<char*>(eclairs[i][j]);
            break;
        case 5:
            ui->label_5->setText("+BO sort dirigés -bonus ag cible.\nA couvert: -10 à -60\nCible utilise son bouclier: -20");
            AttackIndex = 11;
            for(int i = 0; i<5; i++)
              for(int j=0; j<27; j++)
                tableau[i][j] = const_cast<char*>(eclairs[i][j]);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

int MainWindow::set_portee(int portee)
{
    if(portee == 2){
        if(ui->spinBox_4->value() > 0 && ui->spinBox_4->value() < 3 )
            return 0;
        else if(ui->spinBox_4->value() > 2 && ui->spinBox_4->value() < 5 )
            return 25;
        else if(ui->spinBox_4->value() > 4 && ui->spinBox_4->value() < 7 )
            return 50;
        else if(ui->spinBox_4->value() > 6 && ui->spinBox_4->value() < 9 )
            return 75;
    }
    else if(portee == 3){
        if(ui->spinBox_4->value() > 1 && ui->spinBox_4->value() < 4 )
            return 0;
        else if(ui->spinBox_4->value() > 3 && ui->spinBox_4->value() < 7 )
            return 25;
        else if(ui->spinBox_4->value() > 6 && ui->spinBox_4->value() < 10 )
            return 50;
        else if(ui->spinBox_4->value() > 9 && ui->spinBox_4->value() < 13 )
            return 75;
    }
    else if(portee == 5){
        if(ui->spinBox_4->value() > 2 && ui->spinBox_4->value() < 6 )
            return 0;
        else if(ui->spinBox_4->value() > 5 && ui->spinBox_4->value() < 11 )
            return 25;
        else if(ui->spinBox_4->value() > 10 && ui->spinBox_4->value() < 16 )
            return 50;
        else if(ui->spinBox_4->value() > 15 && ui->spinBox_4->value() < 21 )
            return 75;
    }
    else if(portee == 10){
        if(ui->spinBox_4->value() > 3 && ui->spinBox_4->value() < 11 )
            return 0;
        else if(ui->spinBox_4->value() > 10 && ui->spinBox_4->value() < 21 )
            return 25;
        else if(ui->spinBox_4->value() > 20 && ui->spinBox_4->value() < 31 )
            return 50;
        else if(ui->spinBox_4->value() > 30 && ui->spinBox_4->value() < 41 )
            return 75;
    }
    else if(portee == 15){
        if(ui->spinBox_4->value() > 4 && ui->spinBox_4->value() < 16 )
            return 0;
        else if(ui->spinBox_4->value() > 15 && ui->spinBox_4->value() < 31 )
            return 25;
        else if(ui->spinBox_4->value() > 30 && ui->spinBox_4->value() < 46 )
            return 50;
        else if(ui->spinBox_4->value() > 45 && ui->spinBox_4->value() < 61 )
            return 75;
    }
    else if(portee == 20){
        if(ui->spinBox_4->value() > 5 && ui->spinBox_4->value() < 21 )
            return 0;
        else if(ui->spinBox_4->value() > 20 && ui->spinBox_4->value() < 41 )
            return 25;
        else if(ui->spinBox_4->value() > 40 && ui->spinBox_4->value() < 61 )
            return 50;
        else if(ui->spinBox_4->value() > 60 && ui->spinBox_4->value() < 81 )
            return 75;
    }
    else if(portee == 30){
        if(ui->spinBox_4->value() > 6 && ui->spinBox_4->value() < 31 )
            return 0;
        else if(ui->spinBox_4->value() > 30 && ui->spinBox_4->value() < 61 )
            return 25;
        else if(ui->spinBox_4->value() > 60 && ui->spinBox_4->value() < 91 )
            return 50;
        else if(ui->spinBox_4->value() > 90 && ui->spinBox_4->value() < 121 )
            return 75;
    }
    else if(portee == 40){
        if(ui->spinBox_4->value() > 7 && ui->spinBox_4->value() < 41 )
            return 0;
        else if(ui->spinBox_4->value() > 40 && ui->spinBox_4->value() < 81 )
            return 25;
        else if(ui->spinBox_4->value() > 80 && ui->spinBox_4->value() < 121 )
            return 50;
        else if(ui->spinBox_4->value() > 120 && ui->spinBox_4->value() < 161 )
            return 75;
    }
    else if(portee == 50){
        if(ui->spinBox_4->value() > 8 && ui->spinBox_4->value() < 51 )
            return 0;
        else if(ui->spinBox_4->value() > 50 && ui->spinBox_4->value() < 101 )
            return 25;
        else if(ui->spinBox_4->value() > 100 && ui->spinBox_4->value() < 151 )
            return 50;
        else if(ui->spinBox_4->value() > 150 && ui->spinBox_4->value() < 201 )
            return 75;
    }
    else if(portee == 60){
        if(ui->spinBox_4->value() > 9 && ui->spinBox_4->value() < 61 )
            return 0;
        else if(ui->spinBox_4->value() > 60 && ui->spinBox_4->value() < 121 )
            return 25;
        else if(ui->spinBox_4->value() > 120 && ui->spinBox_4->value() < 181 )
            return 50;
        else if(ui->spinBox_4->value() > 180 && ui->spinBox_4->value() < 241 )
            return 75;
    }
    else if(portee == 75){
        if(ui->spinBox_4->value() > 10 && ui->spinBox_4->value() < 76 )
            return 0;
        else if(ui->spinBox_4->value() > 75 && ui->spinBox_4->value() < 151 )
            return 25;
        else if(ui->spinBox_4->value() > 150 && ui->spinBox_4->value() < 226 )
            return 50;
        else if(ui->spinBox_4->value() > 225 && ui->spinBox_4->value() < 301 )
            return 75;
    }
    else if(portee == 90){
        if(ui->spinBox_4->value() > 11 && ui->spinBox_4->value() < 91 )
            return 0;
        else if(ui->spinBox_4->value() > 90 && ui->spinBox_4->value() < 181 )
            return 25;
        else if(ui->spinBox_4->value() > 180 && ui->spinBox_4->value() < 271 )
            return 50;
        else if(ui->spinBox_4->value() > 270 && ui->spinBox_4->value() < 361 )
            return 75;
    }
    else if(portee == 100){
        if(ui->spinBox_4->value() > 12 && ui->spinBox_4->value() < 101 )
            return 0;
        else if(ui->spinBox_4->value() > 100 && ui->spinBox_4->value() < 201 )
            return 25;
        else if(ui->spinBox_4->value() > 200 && ui->spinBox_4->value() < 301 )
            return 50;
        else if(ui->spinBox_4->value() > 300 && ui->spinBox_4->value() < 401 )
            return 75;
    }
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked == true){
        ui->treeWidget->setEnabled(false);
        ui->spinBox_4->setEnabled(true);
        if(arme == 0 || arme == 2){
            if(ui->spinBox_4->value() < 5 || ui->spinBox_4->value() > 60)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 1){
            if(ui->spinBox_4->value() < 2 || ui->spinBox_4->value() > 12)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 5 || arme == 6){
            if(ui->spinBox_4->value() < 4 || ui->spinBox_4->value() > 40)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 7){
            if(ui->spinBox_4->value() < 3 || ui->spinBox_4->value() > 20)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 8){
            if(ui->spinBox_4->value() < 1 || ui->spinBox_4->value() > 8)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 3){
            if(ui->spinBox_4->value() < 7 || ui->spinBox_4->value() > 120)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 4){
            if(ui->spinBox_4->value() < 6 || ui->spinBox_4->value() > 80)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 9){
            if(ui->spinBox_4->value() < 8 || ui->spinBox_4->value() > 160)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 10){
            if(ui->spinBox_4->value() < 11 || ui->spinBox_4->value() > 300)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 11){
            if(ui->spinBox_4->value() < 12 || ui->spinBox_4->value() > 360)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 12){
            if(ui->spinBox_4->value() < 13 || ui->spinBox_4->value() > 400)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 13){
            if(ui->spinBox_4->value() < 10 || ui->spinBox_4->value() > 240)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
        else if(arme == 14){
            if(ui->spinBox_4->value() < 9 || ui->spinBox_4->value() > 200)
                ui->pushButton->setEnabled(false);
            else
                ui->pushButton->setEnabled(true);
        }
    }
    else {
        ui->pushButton->setEnabled(true);
        ui->treeWidget->setEnabled(true);
        ui->spinBox_4->setEnabled(false);
    }
}
void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
  if(ui->checkBox->isChecked() == true || arme == 9|| arme ==10|| arme ==11|| arme ==12|| arme ==13|| arme ==14 || arme == 15)
  {
    if(arme == 0 || arme == 2){
        if(arg1 < 5 || arg1 > 60)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 1){
        if(arg1 < 2 || arg1 > 12)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 5 || arme == 6){
        if(arg1 < 4 || arg1 > 40)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 7){
        if(arg1 < 3 || arg1 > 20)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 8){
        if(arg1 < 1 || arg1 > 8)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 3){
        if(arg1 < 7 || arg1 > 120)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 4){
        if(arg1 < 6 || arg1 > 80)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 9){
        if(arg1 < 8 || arg1 > 160)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 10){
        if(arg1 < 11 || arg1 > 300)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 11){
        if(arg1 < 12 || arg1 > 360)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 12){
        if(arg1 < 13 || arg1 > 400)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 13){
        if(arg1 < 10 || arg1 > 240)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 14){
        if(arg1 < 9 || arg1 > 200)
            ui->pushButton->setEnabled(false);
        else
            ui->pushButton->setEnabled(true);
    }
    else if(arme == 15) ui->pushButton->setEnabled(true);
  }
}

void MainWindow::on_pushButton_2_clicked()
{
    int result, step;
    step = 0;
    result = ui->spinBox_6->value() + ui->spinBox_7->value() + ui->spinBox_8->value();
    if(ui->checkBox_3->isChecked()) result -= 50;
    if(ui->checkBox_4->isChecked()) result -= 70;
    if(ui->checkBox_5->isChecked()) result -= 30;

    if(result < -150) step = 0;
    else if(result < -102) step = 1;
    else if(result < -52) step = 2;
    else if(result < -27) step = 3;
    else if(result < 1) step = 4;
    else if(result < 21) step = 5;
    else if(result < 41) step = 6;
    else if(result < 56) step = 7;
    else if(result < 66) step = 8;
    else if(result < 76) step = 9;
    else if(result < 86) step = 10;
    else if(result < 96) step = 11;
    else if(result < 106) step = 12;
    else if(result < 116) step = 13;
    else if(result < 126) step = 14;
    else if(result < 136) step = 15;
    else if(result < 146) step = 16;
    else if(result < 156) step = 17;
    else if(result < 166) step = 18;
    else if(result < 186) step = 19;
    else if(result < 226) step = 20;
    else if(result < 276) step = 21;
    else if(result > 275) step = 22;

    ui->Result->setText(MainWindow::dynamiques[ui->comboBox->currentIndex()][step]);
}

void MainWindow::on_pushButton_3_clicked()
{
    int dist, jetA, jetE, step; char kms[4];
    dist = atoi(MainWindow::deplacement[ui->comboBox_4->currentIndex()][ui->comboBox_3->currentIndex()]);
    MainWindow::distance += dist;
    sprintf(kms, "%d", MainWindow::distance);
    ui->dist->setText(kms);

    step = 0;
    int terrain[6] = {30,20,-10,-15,-30,-40};
    int deplacement[6] = {0,50,20,-10,-20,-40};
    int taille[8] = {50, 20, 0, -10, -20, -50, -75, -100};


    jetA = ui->spinBox_9->value();
    jetE = ui->spinBox_10->value();

    if(ui->groupBox_4->isChecked() == true){
      if(ui->checkBox_6->isChecked() == true ) jetA += 30;
      else if(ui->checkBox_7->isChecked() == true) jetA -= 30;
      }
    if(ui->radioButton_12->isChecked()) jetA += 25;
    if(ui->radioButton_13->isChecked()) jetA += 50;
    if(ui->radioButton_14->isChecked()) jetA += 100;
    jetA += terrain[ui->comboBox_3->currentIndex()];
    jetE += deplacement[ui->comboBox_4->currentIndex()];
    jetE += taille[ui->comboBox_6->currentIndex()];

    if(ui->groupBox_3->isChecked() == true){
      if(ui->radioButton->isChecked() == true) jetE -= 20;
      else if(ui->radioButton_4->isChecked() == true) jetE -= 40;
      }

    if(jetE > 0)
      jetA -= jetE;
    else
      jetA += jetE;

    if(jetA < 31) step = 0;
    else if(jetA < 51) step = 1;
    else if(jetA < 61) step = 2;
    else if(jetA < 71) step = 3;
    else if(jetA < 81) step = 4;
    else if(jetA < 91) step = 5;
    else if(jetA < 101) step = 6;
    else if(jetA < 121) step = 7;
    else if(jetA < 141) step = 8;
    else if(jetA < 161) step = 9;
    else if(jetA < 181) step = 10;
    else if(jetA < 201) step = 11;
    else if(jetA > 200) step = 12;

    ui->Rencontres->setText(MainWindow::rencontres[ui->comboBox_7->currentIndex()][step]);
}

void MainWindow::on_pushButton_4_clicked()
{
    MainWindow::distance = 0;
    char zero[2] = {"0"};
    ui->dist->setText(zero);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(JR[ui->spinBox_13->value()-1][ui->spinBox_12->value()] > ui->spinBox_11->value())
      ui->label_38->setText("Resiste pas");
    else
      ui->label_38->setText("Resiste");
}

