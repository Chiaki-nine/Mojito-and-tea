#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QRadioButton>
#include <QComboBox>
#include <QString>
#include <QButtonGroup>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void box2Change(int index);

    void box1Change(int index);

    void buttonClick(bool);

private:

    QVBoxLayout* m_vlayout;
    QHBoxLayout* m_layout1;
    QHBoxLayout* m_layout2;
    QHBoxLayout* m_layout3;
    QHBoxLayout* m_layout4;
    QHBoxLayout* m_layout5;
    QHBoxLayout* m_layout6;
    QHBoxLayout* m_layout7;
    QHBoxLayout* m_layout8;

    QComboBox* m_box1;

    QComboBox* m_box2;

    QComboBox* m_box3;

    QLabel* m_label8;
    QComboBox* m_box4;  //按揭成数

   QLabel* m_label2;

    QLabel* m_label3;
    QLineEdit* m_line1;

    QLabel* m_label4;
    QLineEdit* m_line2;

    QLabel* m_label5;
    QLineEdit* m_line3;

    QLabel* m_label7;
    QLineEdit* m_line4;

    QLabel* m_label9;
    QLineEdit* m_line5;

    QLabel* m_label10;
    QLineEdit* m_line6;

    QLabel* m_label11;
    QLineEdit* m_line7;

    QLabel* m_label12;
    QLineEdit* m_line8;

    QRadioButton* m_radio1;
    QRadioButton* m_radio2;

};

#endif // DIALOG_H
