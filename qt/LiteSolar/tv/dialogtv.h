#ifndef DIALOGTV_H
#define DIALOGTV_H

#include <QDialog>

namespace Ui {
class DialogTV;
}

class DialogTV : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogTV(QWidget *parent = 0);
    ~DialogTV();

    void paintEvent(QPaintEvent *);
    
private:
    Ui::DialogTV *ui;
};

#endif // DIALOGTV_H
