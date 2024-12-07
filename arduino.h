#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QString>

class Arduino {
public:
    Arduino();
    ~Arduino();

    bool connectToArduino();
    QString readData();
    void sendData(const QString &data);



    QSerialPort *serial;
};

#endif // ARDUINO_H
