#ifndef DIALOGEVENTS_H
#define DIALOGEVENTS_H

#include <QDialog>

namespace Ui {
class DialogEvents;
}

class DialogEvents : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogEvents(QWidget *parent = 0);
    ~DialogEvents();
    
private:
    Ui::DialogEvents *ui;
};

#endif // DIALOGEVENTS_H
