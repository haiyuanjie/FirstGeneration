#include <QDebug>
#include <windows.h>
#include <qstring.h>
/*获取IP地址*/
#include <QNetworkInterface>
#include <QList>
#include <QHostInfo>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*构造函数时就调用ShowipAndInterfaceName*/
    ShowipAndInterfaceName();
//    setWindowIcon(QIcon("ip.ico"));
    /*ui界面上的控件名字和相应的槽函数进行关联*/
    connect(ui->pushButton_set1,SIGNAL(clicked(bool)),this,
            SLOT(on_pushButton_set1_clicked()));
    connect(ui->pushButton_set2,SIGNAL(clicked(bool)),this,
            SLOT(on_pushButton_set2_clicked()));
    connect(ui->pushButton_set3,SIGNAL(clicked(bool)),this,
            SLOT(on_pushButton_set3_clicked()));
    connect(ui->pushButton_set4,SIGNAL(clicked(bool)),this,
            SLOT(on_pushButton_set4_clicked()));
    connect(ui->pushButton_refresh,SIGNAL(clicked(bool)),this,
            SLOT(on_pushButton_refresh_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*输入参数：void，输出参数：void；功能：将获取的网络接口名字和相应的ip显示在不同
 * 的button和对应的lineedit上*/
void MainWindow::ShowipAndInterfaceName()
{
    /*获取网络接口信息*/
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    int i = 1;
    /*将获取的网络接口信息转成QNetworkInterface*/
    foreach (QNetworkInterface netInterface,list) {
        /*button控件我就设置了4个，所以foreach执行4此就可以了*/
        if((!netInterface.isValid()) || (i >= 5)) {
            continue;
        }
        QNetworkInterface::InterfaceFlags flags = netInterface.flags();
        if (flags.testFlag(QNetworkInterface::IsRunning) &&
            !flags.testFlag(QNetworkInterface::IsLoopBack)) {
            /*寻找button控件*/
            QPushButton *btn = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
            /*寻找lineedit控件*/
            QLineEdit  *line_edit = findChild<QLineEdit *>(QString("lineEdit_%1").arg(i));
            /*在找到的button控件上显示对应的字符串*/
            btn->setText(netInterface.humanReadableName());
            if (netInterface.humanReadableName() == NULL ||
                netInterface.humanReadableName() == "") {

            }
            /*获取网络接口地址信息*/
            QList<QNetworkAddressEntry> entryList = netInterface.addressEntries();
            /*将获取的网络接口地址转成QNetworkAddressEntry*/
            foreach (QNetworkAddressEntry entry, entryList) {
                if (entry.ip().toIPv4Address()) {
                    /*在找到的lineedit显示对应的ip地址*/
                    line_edit->setText(entry.ip().toString());
                }
            }
        } else {
            /*寻找button控件*/
            QPushButton *btn = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
            /*寻找lineedit控件*/
            QLineEdit  *line_edit = findChild<QLineEdit *>(QString("lineEdit_%1").arg(i));
            btn->setText(QString::fromLocal8Bit("不存在运行的网络接口！"));
            /*注意setText函数里面，解决了显示时，中文乱码问题*/
            line_edit->setText(QString::fromLocal8Bit("不存在！"));
        }
        i++;
    }
}

/*pushButton_1写入IP的槽函数*/
void MainWindow::on_pushButton_set1_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_1->text();
    /*1."中的"，要用转义字符\；2.命令行里面网络控制 = 两边要敲空格；3.去掉>后面的nul；
     * 4.本地连接3时，注意3之前有空格；
     * 5.system函数不能控制变量格式，借用sprint处理后再船进入；6.换行直接敲回车*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_1->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}
/*pushButton_2写入IP的槽函数*/
void MainWindow::on_pushButton_set2_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_2->text();
    /*1."中的"，要用转义字符\；2.命令行里面网络控制 = 两边要敲空格；3.去掉>后面的nul；
     * 4.本地连接3时，注意3之前有空格；
     * 5.system函数不能控制变量格式，借用sprint处理后再船进入；6.换行直接敲回车*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_2->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}
/*pushButton_3写入IP的槽函数*/
void MainWindow::on_pushButton_set3_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_3->text();
    /*1."中的"，要用转义字符\；2.命令行里面网络控制 = 两边要敲空格；3.去掉>后面的nul；
     * 4.本地连接3时，注意3之前有空格；
     * 5.system函数不能控制变量格式，借用sprint处理后再船进入；6.换行直接敲回车*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_3->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}
/*pushButton_4写入IP的槽函数*/
void MainWindow::on_pushButton_set4_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_4->text();
    /*1."中的"，要用转义字符\；2.命令行里面网络控制 = 两边要敲空格；3.去掉>后面的nul；
     * 4.本地连接3时，注意3之前有空格；
     * 5.system函数不能控制变量格式，借用sprint处理后再船进入；6.换行直接敲回车*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_4->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}

/*刷新，重新载入本机当前网络接口的名字和地址*/
void MainWindow::on_pushButton_refresh_clicked()
{
    ShowipAndInterfaceName();
}



#if 0
/*本地连接写入IP的操作函数*/
void MainWindow::on_pushButton_local_set_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_local->text();
    //qDebug("ip %s\n", qPrintable(ip_addr));
    //QString path = "C:\\Windows\\System32\\cmd.exe";/*获取cmd路径*/
    //system("netsh interface ip set address name=\"本地连接\" source=\"static\" addr=\"192.168.2.3\" mask=\"255.255.255.0\"  >nul pause");
    //int a = WinExec(qPrintable(path),SW_SHOWNORMAL);/*调用cmd，注意QString使用时，需要转换！*/
    //int a = system("C:\\Windows\\System32\\cmd.exe");/*寻找打开相应的程序*/
    /*1."中的"，要用转义字符\；2.命令行里面网络控制 = 两边要敲空格；3.去掉>后面的nul；4.本地连接3时，注意3之前有空格；
     * 5.system函数不能控制变量格式，借用sprint处理后再船进入；6.换行直接敲回车*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"本地连接\" source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"", qPrintable(ip_addr));
    //system("netsh interface ip set address name = \"本地连接 3\" source = \"static\" addr = \"192.168.6.1\" mask= \"255.255.255.0\"");
    system(c_mip_cmd);
    ui->lineEdit_local->setText(getIP_local());
    //fopen();/*也可以通过fopen创建bat文件，通过运行bat批处理程序，来控制修改IP*/
}

/*本地连接3写入IP的操作函数*/
void MainWindow::on_pushButton_local3_set_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_local3->text();
    //qDebug("ip %s\n", qPrintable(ip_addr));
    //QString path = "C:\\Windows\\System32\\cmd.exe";/*获取cmd路径*/
    //system("netsh interface ip set address name=\"本地连接\" source=\"static\" addr=\"192.168.2.3\" mask=\"255.255.255.0\"  >nul pause");
    //int a = WinExec(qPrintable(path),SW_SHOWNORMAL);/*调用cmd，注意QString使用时，需要转换！*/
    //int a = system("C:\\Windows\\System32\\cmd.exe");/*寻找打开相应的程序*/
    /*1."中的"，要用转义字符\；2.命令行里面网络控制 = 两边要敲空格；3.去掉>后面的nul；4.本地连接3时，注意3之前有空格；
     * 5.system函数不能控制变量格式，借用sprint处理后再船进入；6.换行直接敲回车*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"本地连接 3\" source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"", qPrintable(ip_addr));
    //system("netsh interface ip set address name = \"本地连接 3\" source = \"static\" addr = \"192.168.6.1\" mask= \"255.255.255.0\"");
    system(c_mip_cmd);
    ui->lineEdit_local3->setText(getIP_local3());
    //fopen();/*也可以通过fopen创建bat文件，通过运行bat批处理程序，来控制修改IP*/
}

/*获取显示本机ip地址，本地连接对应的是ipAdresseslist.at(3)*/
QString MainWindow::getIP_local()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface netInterface,list)
    {
        if(!netInterface.isValid())
        {
            continue;
        }
        QNetworkInterface::InterfaceFlags flags = netInterface.flags();
        //qDebug()<<"interface name is  " << netInterface.humanReadableName();
        if (flags.testFlag(QNetworkInterface::IsRunning) && !flags.testFlag(QNetworkInterface::IsLoopBack))
        {
            qDebug()<<"interface name is  "<<netInterface.humanReadableName();/*获取网络接口名*/
            QList<QNetworkAddressEntry> entryList = netInterface.addressEntries();
            foreach (QNetworkAddressEntry entry, entryList)
            {
                if (entry.ip().toIPv4Address())
                {
                    qDebug()<<"IP is  "<<entry.ip().toString();
                }
            }
        }
    }
//    QString strLocalHostName = QHostInfo::localHostName();/*获取主机名*/
//    qDebug()<<"本地主机名："<<strLocalHostName;
//    QString strIpAddress;
//    QList<QHostAddress> ipAdresseslist = QNetworkInterface::allAddresses();
//    foreach (QHostAddress address, ipAdresseslist) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol)
//        {
//            qDebug() << address.toString();
//        }
//    }
    return NULL;
}

/*获取显示本机ip地址，本地连接3 对应的是ipAdresseslist.at(1)*/
QString MainWindow::getIP_local3()
{
    QString strIpAddress;
    QList<QHostAddress> ipAdresseslist = QNetworkInterface::allAddresses();
    strIpAddress = ipAdresseslist.at(1).toString();
    if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return strIpAddress;
}
#endif


