#ifndef WSSERVER_H
#define WSSERVER_H

#include <QObject>

class QWebSocketServer;
class QWebSocket;
//QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
//QT_FORWARD_DECLARE_CLASS(QWebSocket)

class WSServer : public QObject
{
    Q_OBJECT
private:
    QWebSocketServer *WebSocketServer;
    QList<QWebSocket *> clients;
    bool m_debug;

public:
    explicit WSServer(quint16 port, bool debug = false, QObject *parent = nullptr);
    ~WSServer();
signals:
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

public slots:
};

#endif // WSSERVER_0H
