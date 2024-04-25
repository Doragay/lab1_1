#ifndef NOTIFIER_H
#define NOTIFIER_H
#include <QObject>
#include <iostream>

class Notifier: public QObject
{
    Q_OBJECT
public:
    Notifier();
public slots:
    void print_files_info(std::vector<std::string> &info);
    void file_changed(const std::string path, int size); //слот оповещающий об изменении в файле
    void file_deleted(const std::string path); //слот оповещающий об удалении  файла
    void file_exist(const std::string path, int size); //слот оповещающий о существовании файле
};
#endif // NOTIFIER_H
