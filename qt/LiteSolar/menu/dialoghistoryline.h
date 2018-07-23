#ifndef DIALOGHISTORYLINE_H
#define DIALOGHISTORYLINE_H

#include <QDialog>

namespace Ui {
class DialogHistoryLine;
}

class DialogHistoryLine : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogHistoryLine(QWidget *parent = 0);
    ~DialogHistoryLine();
    
private:
    Ui::DialogHistoryLine *ui;

    void setupView();
};

#endif // DIALOGHISTORYLINE_H
