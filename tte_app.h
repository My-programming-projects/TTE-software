
#ifndef TTE_APP_H
#define TTE_APP_H

#include <QMainWindow>

#include "editor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TTE_App; }
QT_END_NAMESPACE

class TTE_App : public QMainWindow

{
    Q_OBJECT

public:
    TTE_App(QWidget *parent = nullptr);
    ~TTE_App();

private slots:
    void openEditor();

private:
    void setConnections();

    Ui::TTE_App *ui;
};

#endif // TTE_APP_H
