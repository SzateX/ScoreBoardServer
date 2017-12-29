#include "wsserver.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"

WSServer::WSServer(quint16 port, bool debug, QObject *parent) : QObject(parent), WebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"), QWebSocketServer::NonSecureMode, this)), m_debug(debug)
{
    if(WebSocketServer->listen(QHostAddress::Any, port))
    {
        if(m_debug)
            qDebug() << "Echoserver listening on port" << port;
        connect(WebSocketServer, &QWebSocketServer::newConnection, this, &WSServer::onNewConnection);
        connect(WebSocketServer, &QWebSocketServer::closed, this, &WSServer::closed);
    }
}

WSServer::~WSServer()
{
    WebSocketServer->close();
    qDeleteAll(clients.begin(), clients.end());
}

void WSServer::onNewConnection()
{
    QWebSocket *pSocket = WebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &WSServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &WSServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &WSServer::socketDisconnected);

    clients << pSocket;
}

void WSServer::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Message received:" << message;
    if (pClient) {
        pClient->sendTextMessage(message);
    }
}

void WSServer::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void WSServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
