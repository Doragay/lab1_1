#include "file.h"
#include <QFileInfo>
#include <string>
#include <QString>

File::File(std::string _path) //сигнатура создали путь
{
    QFileInfo fileInfo(QString::fromStdString(_path));//создается объект, который обращается к реальному файлу. вызвалии конструктор с параметром
    path = _path; //создаем файлы внутри пас, ложим то что извне задаем
    size = fileInfo.size();//функция, получаем размер реального пути
    exist = fileInfo.exists(); //будет лежать размер реального файла
}

float File::get_size() //определ функции именно из этого класса. Возвращает
{
    return size;
}
bool File::get_exist()
{
    return exist;
}
std::string File::get_path()
{
    return path;
}
void File::set_exist(const bool _exist) //нужно отправить изменения. Меняет
{
    exist=_exist;
}
void File::set_size(float _size)
{
    size=_size;
}
