#include "dialog.h"
#include <math.h>

int m_flag;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("房贷计算器");

    m_flag = 0;
    resize(400,400);

    QLabel* label1 = new QLabel("贷款类别");    //贷款类别label
    m_box1 = new QComboBox();        //贷款类别组合框
    m_box1->addItem("商业贷款");
    m_box1->addItem("公积金贷款");
    m_box1->addItem("组合型贷款");
    m_layout1 = new QHBoxLayout();
    m_layout1->addWidget(label1);
    m_layout1->addWidget(m_box1);

    m_label2 = new QLabel("计算方式");   //计算方式label
    m_box2 = new QComboBox();        //计算方式组合框
    m_box2->addItem("根据贷款总额计算");
    m_box2->addItem("根据面积,单价计算");
    m_layout2 = new QHBoxLayout();
    m_layout2->addWidget(m_label2);
    m_layout2->addWidget(m_box2);

    m_label3 = new QLabel("房屋单价(元/平米)");   //房屋单价label
    m_line1 = new QLineEdit();
    m_layout3 = new QHBoxLayout();
    m_layout3->addWidget(m_label3);
    m_layout3->addWidget(m_line1);
    m_label3->setVisible(0);
    m_line1->setVisible(0);
    m_line1->setPlaceholderText("请输入房屋单价");

    m_label4 = new QLabel("面积(平方米)");   //面积label
    m_line2 = new QLineEdit();
    m_layout4 = new QHBoxLayout();
    m_layout4->addWidget(m_label4);
    m_layout4->addWidget(m_line2);
    m_label4->setVisible(0);
    m_line2->setVisible(0);
    m_line2->setPlaceholderText("请输入房屋面积");

    m_label5 = new QLabel("贷款总额(万)");   //贷款总额label
    m_line3 = new QLineEdit();
    QHBoxLayout* layout5 = new QHBoxLayout();
    layout5->addWidget(m_label5);
    layout5->addWidget(m_line3);
    m_line3->setPlaceholderText("请输入贷款总额");

    m_box4 = new QComboBox();
    m_label8 = new QLabel("按揭成数(成)");
    m_box4->addItem("2");
    m_box4->addItem("2.5");
    m_box4->addItem("3");
    m_box4->addItem("3.5");
    m_box4->addItem("4");
    m_box4->addItem("4.5");
    m_box4->addItem("5");
    m_box4->addItem("5.5");
    m_box4->addItem("6");
    m_box4->addItem("6.5");
    m_box4->addItem("7");
    m_box4->addItem("7.5");
    m_box4->addItem("8");
    QHBoxLayout* layout9 = new QHBoxLayout();
    layout9->addWidget(m_label8);
    layout9->addWidget(m_box4);
    m_label8->setVisible(0);
    m_box4->setVisible(0);
    m_box4->setCurrentIndex(6);

    QLabel* label6 = new QLabel("按揭月数");   //按揭月数label
    m_box3 = new QComboBox();        //按揭月数组合框
    m_box3->addItem("12");
    m_box3->addItem("24");
    m_box3->addItem("36");
    m_box3->addItem("48");
    m_box3->addItem("60");
    m_box3->addItem("72");
    m_box3->addItem("84");
    m_box3->addItem("96");
    m_box3->addItem("108");
    m_box3->addItem("120");
    QHBoxLayout* layout6 = new QHBoxLayout();
    layout6->addWidget(label6);
    layout6->addWidget(m_box3);

    m_label7 = new QLabel("贷款利率(%)");   //贷款利率label
    m_line4 = new QLineEdit();
    QHBoxLayout* layout7 = new QHBoxLayout();
    layout7->addWidget(m_label7);
    layout7->addWidget(m_line4);
    m_line4->setText("4.75");

    m_radio1 = new QRadioButton("等额本息");
    m_radio2 = new QRadioButton("等额本金");
    QButtonGroup* group = new QButtonGroup();
    group->addButton(m_radio1);
    group->addButton(m_radio2);
    m_radio1->setChecked(1);
    QHBoxLayout* layout8 = new QHBoxLayout();
    layout8->addWidget(m_radio1);
    layout8->addWidget(m_radio2);


    m_label9 = new QLabel("商业贷款额(万)");
    m_line5 = new QLineEdit();
    m_label9->setVisible(0);
    m_line5->setVisible(0);
    QHBoxLayout* layout10 = new QHBoxLayout();
    layout10->addWidget(m_label9);
    layout10->addWidget(m_line5);

    m_label10 = new QLabel("公积金贷款额(万)");
    m_line6 = new QLineEdit();
    m_label10->setVisible(0);
    m_line6->setVisible(0);
    QHBoxLayout* layout11 = new QHBoxLayout();
    layout11->addWidget(m_label10);
    layout11->addWidget(m_line6);

    m_label11 = new QLabel("商贷利率");
    m_line7 = new QLineEdit();
    m_label11->setVisible(0);
    m_line7->setVisible(0);
    QHBoxLayout* layout12 = new QHBoxLayout();
    layout12->addWidget(m_label11);
    layout12->addWidget(m_line7);
    m_line7->setText("3.25");

    m_label12 = new QLabel("公积金利率");
    m_line8 = new QLineEdit();
    m_label12->setVisible(0);
    m_line8->setVisible(0);
    QHBoxLayout* layout13 = new QHBoxLayout();
    layout13->addWidget(m_label12);
    layout13->addWidget(m_line8);
    m_line8->setText("3.25");


    QPushButton* button = new QPushButton("开始计算",this);

    m_vlayout = new QVBoxLayout();
    m_vlayout->addLayout(m_layout1);
    m_vlayout->addLayout(m_layout2);
    m_vlayout->addLayout(m_layout3);
    m_vlayout->addLayout(m_layout4);

    m_vlayout->addLayout(layout10);
    m_vlayout->addLayout(layout12);
    m_vlayout->addLayout(layout11);
    m_vlayout->addLayout(layout13);

    m_vlayout->addLayout(layout5);
    m_vlayout->addLayout(layout9);
    m_vlayout->addLayout(layout6);
    m_vlayout->addLayout(layout7);
    m_vlayout->addLayout(layout8);
    m_vlayout->addWidget(button);

    setLayout(m_vlayout);
    connect(m_box2,SIGNAL(activated(int)),this,SLOT(box2Change(int)));

    connect(button,SIGNAL(clicked(bool)),this,SLOT(buttonClick(bool)));

    connect(m_box1,SIGNAL(activated(int)),this,SLOT(box1Change(int)));
}

Dialog::~Dialog()
{

}

void Dialog::box2Change(int index)
{
    if(index == 0){
        m_label3->setVisible(0);
        m_line1->setVisible(0);
        m_label4->setVisible(0);
        m_line2->setVisible(0);

        m_label8->setVisible(0);
        m_box4->setVisible(0);

        m_label5->setVisible(1);
        m_line3->setVisible(1);

    }else if(index == 1){
        m_label3->setVisible(1);
        m_line1->setVisible(1);
        m_label4->setVisible(1);
        m_line2->setVisible(1);

        m_label8->setVisible(1);
        m_box4->setVisible(1);

        m_label5->setVisible(0);
        m_line3->setVisible(0);
    }
    else{
        qDebug("error\n");
    }
}

void Dialog::box1Change(int index)
{
if(index != 2){
     m_flag = 1;
        if(index == 0){
            m_line4->setText("4.75");
        }else{
            m_line4->setText("3.25");   //公积金贷款
        }


        m_label2->setVisible(1);

        m_box2->setVisible(1);

        m_label9->setVisible(0);
        m_line5->setVisible(0);

        m_label10->setVisible(0);
        m_line6->setVisible(0);

        m_label11->setVisible(0);
        m_line7->setVisible(0);

        m_label12->setVisible(0);
        m_line8->setVisible(0);


        m_label3->setVisible(0);
        m_line1->setVisible(0);

        m_label4->setVisible(0);
        m_line2->setVisible(0);

        m_label5->setVisible(0);
        m_line3->setVisible(0);


        m_line4->setVisible(1);

        m_label7->setVisible(1);

        if(m_box2->currentIndex() == 0){
            //qDebug("m_box2->currentIndex() == 0\n");

            m_label8->setVisible(0);
            m_box4->setVisible(0);

            m_label3->setVisible(0);
            m_line1->setVisible(0);

            m_label4->setVisible(0);
            m_line2->setVisible(0);
            m_label5->setVisible(1);
            m_line3->setVisible(1);
        }else{
            //qDebug("m_box2->currentIndex() != 0\n");
            m_label5->setVisible(0);
            m_line3->setVisible(0);

            m_label8->setVisible(1);
            m_box4->setVisible(1);

            m_label3->setVisible(1);
            m_line1->setVisible(1);

            m_label4->setVisible(1);
            m_line2->setVisible(1);
        }

    }else if(index == 2){   //组合型贷款

        m_flag = 3;
        m_box2->setVisible(0);

        m_label9->setVisible(1);
        m_line5->setVisible(1);

        m_label10->setVisible(1);
        m_line6->setVisible(1);

        m_label11->setVisible(1);
        m_line7->setVisible(1);

        m_label12->setVisible(1);
        m_line8->setVisible(1);

        m_label8->setVisible(0);
        m_box4->setVisible(0);

        m_label3->setVisible(0);
        m_line1->setVisible(0);

        m_label4->setVisible(0);
        m_line2->setVisible(0);

        m_label5->setVisible(0);
        m_line3->setVisible(0);


        m_line4->setVisible(0);

        m_label7->setVisible(0);

        m_label2->setVisible(0);

    }
}

void Dialog::buttonClick(bool)
{
    double price = 0;       //总额
    double frist = 0;       //首付,只在房屋面积方式有效
    int a = m_box3->currentText().toInt();
    if(m_flag != 3){
    if(m_line3->isVisible() == 1){  //贷款总额方式
        if(m_line3->text() == "" || 0 ==  m_line3->text().toDouble()){
            QMessageBox::information(this,"提示","请先输入大于0的贷款总额");
            return;
        }
        price = m_line3->text().toDouble()*10000;   //单位万



    }else{      //房屋面积方式
        if(m_line1->text() == "" || 0 ==  m_line1->text().toDouble()){
            QMessageBox::information(this,"提示","请先输入大于0的房屋单价");
            return;
        }
        if(m_line2->text() == "" || 0 ==  m_line2->text().toDouble()){
            QMessageBox::information(this,"提示","请先输入大于0的面积");
            return;
        }
        price = m_line1->text().toDouble()*m_line2->text().toDouble();  //单位元

        frist = (10 - m_box4->currentText().toInt())*price/10; //首付

        price = price - frist;  //贷款总额 = 总额 - 首付
    }
    }else{
        if((m_line5->text() == "" || 0 ==  m_line5->text().toDouble()) || (m_line6->text() == "" || 0 ==  m_line6->text().toDouble())){
            QMessageBox::information(this,"提示","请先输入大于0的贷款额");
            return;
        }
        price = m_line5->text().toDouble()*10000+ m_line6->text().toDouble()*10000;
    }

    if(m_flag != 3){
    if(m_line4->text() == "" || 0 ==  m_line4->text().toDouble()){
        QMessageBox::information(this,"提示","请先输入大于0的贷款利率");
        return;
    }}


    double rate = m_line4->text().toDouble();

    double monthRate =  rate/12/100;    //月利率
    if(m_radio1->isChecked()){  //等额本息
        double b = price*monthRate*pow(1+monthRate,a)/(pow(1+monthRate,a)-1);   //每月月供
        double all = b*a;   //还款总额
        double c = all-price;
        if(0 == frist){

            QDialog f(this);
            f.setWindowTitle("计算结果");
            f.resize(270,270);
            QLabel e(&f);
            e.setFont(QFont("Timers" , 15 ,  QFont::Normal));
            e.setText(QString("每月月供: %1    元\n贷款总额: %2   元\n"
                              "支付利息: %3    元\n还款总额: %4   元\n还款月数: %5       个月")
                      .arg(QString::number((int)b),QString::number((int)price)
                           ,QString::number((int)c),QString::number((int)all)
                           ,QString::number((int)a)));
            f.exec();


        }else{
            QDialog f(this);
            f.setWindowTitle("计算结果");
            f.resize(270,270);
            QLabel e(&f);
            e.setFont(QFont("Timers" , 15 ,  QFont::Normal));
            e.setText(QString("首付:%1    元\n每月月供: %2    元\n贷款总额: %3   元\n"
                              "支付利息: %4    元\n还款总额: %5   元\n还款月数: %6       个月")
                      .arg(QString::number((int)frist),QString::number((int)b),QString::number((int)price)
                           ,QString::number((int)c),QString::number((int)all)
                           ,QString::number((int)a)));
            f.exec();

        }

    }else{      //等额本金

        double month1 = price/a;    //每月还款本金


        double month2 = price * monthRate;  //每月还款利息

        double month3 = month1+month2;  //每月还款额

        double all = 0; //总利息
        double b = 0;   //贷款本金余额

        double c1 = price*monthRate;    //首月月供
        double c2 = month1*monthRate;   //每月递减
        //贷款总额 price
        for(int i = 0; i< a;i++){
            b = price - month1*i;
            all += b*monthRate;
        }

        //支付利息 all  //还款月数  a

        double d = all+price;   //还款总额 =总利息+贷款总额

        if(0 == frist){

            QDialog f(this);
            f.setWindowTitle("计算结果");
            f.resize(270,270);
            QLabel e(&f);
            e.setFont(QFont("Timers" , 15 ,  QFont::Normal));
            e.setText(QString("首月月供: %1    元\n每月递减: %2     元\n贷款总额: %3   元\n"
                              "支付利息: %4    元\n还款总额: %5   元\n还款月数: %6       个月")
                      .arg(QString::number((int)c1),QString::number((int)c2)
                           ,QString::number((int)price),QString::number((int)all)
                           ,QString::number((int)d),QString::number((int)a)));
            f.exec();


        }else{
            QDialog f(this);
            f.setWindowTitle("计算结果");
            f.resize(270,270);
            QLabel e(&f);
            e.setFont(QFont("Timers" , 15 ,  QFont::Normal));
            e.setText(QString("首付:%1    元\n首月月供: %2    元\n每月递减: %3     元\n贷款总额: %4   元\n"
                              "支付利息: %5    元\n还款总额: %6   元\n还款月数: %7       个月")
                      .arg(QString::number((int)frist),QString::number((int)c1),QString::number((int)c2)
                           ,QString::number((int)price),QString::number((int)all)
                           ,QString::number((int)d),QString::number((int)a)));
            f.exec();

        }

    }
}













