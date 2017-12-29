#include <QCoreApplication>
#include <iostream>
#include "Server/wsserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<"Apka startuje"<<std::endl;

    bool debug = true;
    int port = 8000;

    WSServer *server = new WSServer(port, debug);
    QObject::connect(server, &WSServer::closed, &a, &QCoreApplication::quit);

    return a.exec();
}
