#ifndef FORMDEVICE_H
#define FORMDEVICE_H

#include <QWidget>

namespace Ui {
class FormDevice;
}

class FormDevice : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormDevice(QWidget *parent = 0);
    ~FormDevice();
    
private:
    Ui::FormDevice *ui;
};

#endif // FORMDEVICE_H
