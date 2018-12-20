#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDir>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    QFile file(path);
    if(file.open(QIODevice::ReadWrite)) {
        QByteArray dataout("Hello World");
        file.write(dataout);
        file.flush();
        file.seek(0);

        qInfo() << file.readAll();
        file.close();
    } else {
        qInfo() << file.errorString();
    }


    return a.exec();
}
