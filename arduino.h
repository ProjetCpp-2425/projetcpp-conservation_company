#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>

class Arduino {
public:
    Arduino();
    ~Arduino();
    int connectToArduino();
    QByteArray readFromArduino();
    void writeToArduino(const QByteArray &data);
    QSerialPort *getSerial() const;

private:
    QSerialPort *serial;
    QString portName;
    bool isAvailable;
};

#endif // ARDUINO_H
