#ifndef OBSERVER_H
#define OBSERVER_H
#include <file.h>
#include <vector>
#include <QObject>

class Observer:public QObject
{
    Q_OBJECT
private:
    std::vector<File> files; //создаем список этих объектов, массив файлов за которыми мы будем следить
public:
    Observer();
    void add_file(std::string _path);
    void files_info();//вызываей функцию когда хотим узнать инфо о файлах
signals:
    void print_files_info(std::vector<std::string> &info); //создаем веткор типа данныз строка.Амперсант не копировал, а на прямую предавало
};

#endif // OBSERVER_H
