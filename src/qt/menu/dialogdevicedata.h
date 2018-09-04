#ifndef DIALOGDEVICEDATA_H
#define DIALOGDEVICEDATA_H

#include <QDialog>
#include <QTableWidget>

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


    void loadDataFromCode(QTableWidget *table);

    void loadDataFromModel(QTableWidget *table);

};

#endif // DIALOGDEVICEDATA_H
