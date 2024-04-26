#ifndef OBSERVER_H
#define OBSERVER_H
#include <file.h>
#include <vector>
#include <QObject>
#include <QFileInfo>

class Observer:public QObject
{
    Q_OBJECT
private:
    std::vector<File> files; //определяем вектор файлов, за которыми мы будем следить
public:
    Observer();
    void add_file(std::string _path);
    void files_info();
    void monitor();
signals:
    void print_files_info(std::vector<std::string> &info); //определяем вектор типа данныз строка
    void fileExist(const std::string path, int size);
    void fileNotExist(const std::string path);
    void fileChanged(const std::string path, int size);
};

#endif // OBSERVER_H
