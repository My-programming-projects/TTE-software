#ifndef PRECONDITIONSEDITOR_HPP
#define PRECONDITIONSEDITOR_HPP

#include <QDialog>

namespace Ui {
class PreconditionsEditor;
}

class PreconditionsEditor : public QDialog
{
    Q_OBJECT

public:
    explicit PreconditionsEditor(QWidget *parent = nullptr);
    ~PreconditionsEditor();

private:
    Ui::PreconditionsEditor *ui;
};

#endif // PRECONDITIONSEDITOR_HPP
