#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<"Apka startuje"<<std::endl;
    return a.exec();
}
