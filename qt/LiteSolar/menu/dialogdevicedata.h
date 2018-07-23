#ifndef DIALOGDEVICEDATA_H
#define DIALOGDEVICEDATA_H

#include <QDialog>

namespace Ui {
class DialogDeviceData;
}

class DialogDeviceData : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDeviceData(QWidget *parent = 0);
    ~DialogDeviceData();

private:
    Ui::DialogDeviceData *ui;
};

#endif // DIALOGDEVICEDATA_H
