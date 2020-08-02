#include <QDebug>
#include <windows.h>
#include <qstring.h>
/*��ȡIP��ַ*/
#include <QNetworkInterface>
#include <QList>
#include <QHostInfo>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*���캯��ʱ�͵���ShowipAndInterfaceName*/
    ShowipAndInterfaceName();
//    setWindowIcon(QIcon("ip.ico"));
    /*ui�����ϵĿؼ����ֺ���Ӧ�Ĳۺ������й���*/
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

/*���������void�����������void�����ܣ�����ȡ������ӿ����ֺ���Ӧ��ip��ʾ�ڲ�ͬ
 * ��button�Ͷ�Ӧ��lineedit��*/
void MainWindow::ShowipAndInterfaceName()
{
    /*��ȡ����ӿ���Ϣ*/
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    int i = 1;
    /*����ȡ������ӿ���Ϣת��QNetworkInterface*/
    foreach (QNetworkInterface netInterface,list) {
        /*button�ؼ��Ҿ�������4��������foreachִ��4�˾Ϳ�����*/
        if((!netInterface.isValid()) || (i >= 5)) {
            continue;
        }
        QNetworkInterface::InterfaceFlags flags = netInterface.flags();
        if (flags.testFlag(QNetworkInterface::IsRunning) &&
            !flags.testFlag(QNetworkInterface::IsLoopBack)) {
            /*Ѱ��button�ؼ�*/
            QPushButton *btn = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
            /*Ѱ��lineedit�ؼ�*/
            QLineEdit  *line_edit = findChild<QLineEdit *>(QString("lineEdit_%1").arg(i));
            /*���ҵ���button�ؼ�����ʾ��Ӧ���ַ���*/
            btn->setText(netInterface.humanReadableName());
            if (netInterface.humanReadableName() == NULL ||
                netInterface.humanReadableName() == "") {

            }
            /*��ȡ����ӿڵ�ַ��Ϣ*/
            QList<QNetworkAddressEntry> entryList = netInterface.addressEntries();
            /*����ȡ������ӿڵ�ַת��QNetworkAddressEntry*/
            foreach (QNetworkAddressEntry entry, entryList) {
                if (entry.ip().toIPv4Address()) {
                    /*���ҵ���lineedit��ʾ��Ӧ��ip��ַ*/
                    line_edit->setText(entry.ip().toString());
                }
            }
        } else {
            /*Ѱ��button�ؼ�*/
            QPushButton *btn = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
            /*Ѱ��lineedit�ؼ�*/
            QLineEdit  *line_edit = findChild<QLineEdit *>(QString("lineEdit_%1").arg(i));
            btn->setText(QString::fromLocal8Bit("���������е�����ӿڣ�"));
            /*ע��setText�������棬�������ʾʱ��������������*/
            line_edit->setText(QString::fromLocal8Bit("�����ڣ�"));
        }
        i++;
    }
}

/*pushButton_1д��IP�Ĳۺ���*/
void MainWindow::on_pushButton_set1_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_1->text();
    /*1."�е�"��Ҫ��ת���ַ�\��2.����������������� = ����Ҫ�ÿո�3.ȥ��>�����nul��
     * 4.��������3ʱ��ע��3֮ǰ�пո�
     * 5.system�������ܿ��Ʊ�����ʽ������sprint������ٴ����룻6.����ֱ���ûس�*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_1->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}
/*pushButton_2д��IP�Ĳۺ���*/
void MainWindow::on_pushButton_set2_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_2->text();
    /*1."�е�"��Ҫ��ת���ַ�\��2.����������������� = ����Ҫ�ÿո�3.ȥ��>�����nul��
     * 4.��������3ʱ��ע��3֮ǰ�пո�
     * 5.system�������ܿ��Ʊ�����ʽ������sprint������ٴ����룻6.����ֱ���ûس�*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_2->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}
/*pushButton_3д��IP�Ĳۺ���*/
void MainWindow::on_pushButton_set3_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_3->text();
    /*1."�е�"��Ҫ��ת���ַ�\��2.����������������� = ����Ҫ�ÿո�3.ȥ��>�����nul��
     * 4.��������3ʱ��ע��3֮ǰ�пո�
     * 5.system�������ܿ��Ʊ�����ʽ������sprint������ٴ����룻6.����ֱ���ûس�*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_3->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}
/*pushButton_4д��IP�Ĳۺ���*/
void MainWindow::on_pushButton_set4_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_4->text();
    /*1."�е�"��Ҫ��ת���ַ�\��2.����������������� = ����Ҫ�ÿո�3.ȥ��>�����nul��
     * 4.��������3ʱ��ע��3֮ǰ�пո�
     * 5.system�������ܿ��Ʊ�����ʽ������sprint������ٴ����룻6.����ֱ���ûس�*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"%s\" "
                       "source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"",
            qPrintable(ui->pushButton_4->text()), qPrintable(ip_addr));
    system(c_mip_cmd);
}

/*ˢ�£��������뱾����ǰ����ӿڵ����ֺ͵�ַ*/
void MainWindow::on_pushButton_refresh_clicked()
{
    ShowipAndInterfaceName();
}



#if 0
/*��������д��IP�Ĳ�������*/
void MainWindow::on_pushButton_local_set_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_local->text();
    //qDebug("ip %s\n", qPrintable(ip_addr));
    //QString path = "C:\\Windows\\System32\\cmd.exe";/*��ȡcmd·��*/
    //system("netsh interface ip set address name=\"��������\" source=\"static\" addr=\"192.168.2.3\" mask=\"255.255.255.0\"  >nul pause");
    //int a = WinExec(qPrintable(path),SW_SHOWNORMAL);/*����cmd��ע��QStringʹ��ʱ����Ҫת����*/
    //int a = system("C:\\Windows\\System32\\cmd.exe");/*Ѱ�Ҵ���Ӧ�ĳ���*/
    /*1."�е�"��Ҫ��ת���ַ�\��2.����������������� = ����Ҫ�ÿո�3.ȥ��>�����nul��4.��������3ʱ��ע��3֮ǰ�пո�
     * 5.system�������ܿ��Ʊ�����ʽ������sprint������ٴ����룻6.����ֱ���ûس�*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"��������\" source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"", qPrintable(ip_addr));
    //system("netsh interface ip set address name = \"�������� 3\" source = \"static\" addr = \"192.168.6.1\" mask= \"255.255.255.0\"");
    system(c_mip_cmd);
    ui->lineEdit_local->setText(getIP_local());
    //fopen();/*Ҳ����ͨ��fopen����bat�ļ���ͨ������bat����������������޸�IP*/
}

/*��������3д��IP�Ĳ�������*/
void MainWindow::on_pushButton_local3_set_clicked()
{
    char c_mip_cmd[255] = "";
    QString ip_addr = ui->lineEdit_local3->text();
    //qDebug("ip %s\n", qPrintable(ip_addr));
    //QString path = "C:\\Windows\\System32\\cmd.exe";/*��ȡcmd·��*/
    //system("netsh interface ip set address name=\"��������\" source=\"static\" addr=\"192.168.2.3\" mask=\"255.255.255.0\"  >nul pause");
    //int a = WinExec(qPrintable(path),SW_SHOWNORMAL);/*����cmd��ע��QStringʹ��ʱ����Ҫת����*/
    //int a = system("C:\\Windows\\System32\\cmd.exe");/*Ѱ�Ҵ���Ӧ�ĳ���*/
    /*1."�е�"��Ҫ��ת���ַ�\��2.����������������� = ����Ҫ�ÿո�3.ȥ��>�����nul��4.��������3ʱ��ע��3֮ǰ�пո�
     * 5.system�������ܿ��Ʊ�����ʽ������sprint������ٴ����룻6.����ֱ���ûس�*/
    sprintf(c_mip_cmd, "netsh interface ip set address name = \"�������� 3\" source = \"static\" addr = \"%s\" "
                       "mask= \"255.255.255.0\"", qPrintable(ip_addr));
    //system("netsh interface ip set address name = \"�������� 3\" source = \"static\" addr = \"192.168.6.1\" mask= \"255.255.255.0\"");
    system(c_mip_cmd);
    ui->lineEdit_local3->setText(getIP_local3());
    //fopen();/*Ҳ����ͨ��fopen����bat�ļ���ͨ������bat����������������޸�IP*/
}

/*��ȡ��ʾ����ip��ַ���������Ӷ�Ӧ����ipAdresseslist.at(3)*/
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
            qDebug()<<"interface name is  "<<netInterface.humanReadableName();/*��ȡ����ӿ���*/
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
//    QString strLocalHostName = QHostInfo::localHostName();/*��ȡ������*/
//    qDebug()<<"������������"<<strLocalHostName;
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

/*��ȡ��ʾ����ip��ַ����������3 ��Ӧ����ipAdresseslist.at(1)*/
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


