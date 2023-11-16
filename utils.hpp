
#ifndef UTILS_HPP
#define UTILS_HPP

#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>

inline bool isLineEditNotEmpty(QLineEdit* lineEdit)
{
    QString trimmedText = lineEdit->text().trimmed();

    return !(lineEdit->text().isEmpty()) && !(trimmedText.isEmpty());
}

inline bool isListWidgetNotEmpty(QListWidget* listWidget)
{
    return listWidget->count() > 0;
}

inline bool isListWidgetItemSelected(QListWidget* listWidget)
{
    return !listWidget->selectedItems().isEmpty();
}

///////////////////////////////////////////////////////////////////////

inline void moveItemUp(QListWidget* listWidget)
{
    QListWidgetItem* currentItem = listWidget->currentItem();
    int currentIndex = listWidget->row(currentItem);

    QListWidgetItem* previous = listWidget->item(listWidget->row(currentItem) - 1);
    int previousIndex = listWidget->row(previous);

    QListWidgetItem* temp = listWidget->takeItem(previousIndex);
    listWidget->insertItem(currentIndex, temp);
    listWidget->insertItem(previousIndex, currentItem);
}

inline void moveItemDown(QListWidget* listWidget)
{
    QListWidgetItem* currentItem = listWidget->currentItem();
    int currentIndex = listWidget->row(currentItem);

    QListWidgetItem* next = listWidget->item(listWidget->row(currentItem) + 1);
    int nextIndex = listWidget->row(next);

    QListWidgetItem* temp = listWidget->takeItem(nextIndex);
    listWidget->insertItem(currentIndex, temp);
    listWidget->insertItem(nextIndex, currentItem);
}

////////////////////////////////////////////////////////////

inline void updateUpDownButtonsState(QPushButton* upButton, QPushButton* downButton, QListWidget* listWidget)
{
    bool upButtonEnabled = listWidget->currentRow() != 0 ? true : false;
    bool downButtonEnabled = listWidget->currentRow() != listWidget->count() - 1 ? true : false;

    upButton->setEnabled(upButtonEnabled);
    downButton->setEnabled(downButtonEnabled);
}

#endif // UTILS_HPP
