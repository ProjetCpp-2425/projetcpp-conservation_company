#include "arduino.h"
#include <QDebug>

Arduino::Arduino() : serial(new QSerialPort), isAvailable(false) {}

Arduino::~Arduino() {
    if (serial && serial->isOpen()) {
        serial->close();
    }
    delete serial;
}

int Arduino::connectToArduino() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {

        if (info.vendorIdentifier() == 0x2341 && info.productIdentifier() == 0x0043) {  // Vendor ID and Product ID for Arduino Uno
            portName = info.portName();
            serial->setPortName(portName);
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            if (serial->open(QIODevice::ReadWrite)) {
                isAvailable = true;
                qDebug() << "Connected to Arduino on port:" << portName;
                return 1;  // Successful connection
            } else {
                qDebug() << "Failed to open port:" << serial->errorString();
                return 0;  // Failed to open port
            }
        }
    }
    qDebug() << "No matching Arduino found.";
    return 0;  // No matching Arduino found
}

QByteArray Arduino::readFromArduino() {
    if (serial->canReadLine()) {
        return serial->readLine();  // Read a line of data
    }
    return QByteArray();  // Return empty if nothing to read
}

void Arduino::writeToArduino(const QByteArray &data) {
    if (serial->isWritable()) {
        serial->write(data);  // Send data to Arduino
        qDebug() << "Data written to Arduino:" << data;
    } else {
        qDebug() << "Cannot write to Arduino: port not writable";
    }
}

QSerialPort* Arduino::getSerial() const {
    return serial;
}
