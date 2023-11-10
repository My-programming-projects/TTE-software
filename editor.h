#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>

#include "usecaseeditor.h"

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

private slots:
    void addUseCase();

private:
    void setConnections();

    Ui::Editor *ui;
};

#endif // EDITOR_H
