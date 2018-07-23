#ifndef DIALOGDEVICEEVENTS_H
#define DIALOGDEVICEEVENTS_H

#include <QDialog>

namespace Ui {
class DialogDeviceEvents;
}

class DialogDeviceEvents : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDeviceEvents(QWidget *parent = 0);
    ~DialogDeviceEvents();
    
private:
    Ui::DialogDeviceEvents *ui;
};

#endif // DIALOGDEVICEEVENTS_H
