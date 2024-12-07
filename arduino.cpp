#include "arduino.h"

Arduino::Arduino() {
    serial = new QSerialPort();
    serial->setPortName("COM6");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

Arduino::~Arduino() {
    if (serial->isOpen()) {
        serial->close();
    }
    delete serial;
}

bool Arduino::connectToArduino() {
    if (!serial->isOpen()) {
        return serial->open(QIODevice::ReadWrite);
    }
    return true;
}

QString Arduino::readData() {
    if (serial->canReadLine()) {
        return QString(serial->readLine()).trimmed();
    }
    return "";
}

void Arduino::sendData(const QString &message) {
    QByteArray data = message.toUtf8();
    serial->write(data);
}

