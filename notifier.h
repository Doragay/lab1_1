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


};
#endif // NOTIFIER_H
