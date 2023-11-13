
#ifndef UTILS_HPP
#define UTILS_HPP

#include <QLineEdit>
#include <QListWidget>

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


#endif // UTILS_HPP
