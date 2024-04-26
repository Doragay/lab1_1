#include "file.h"
#include <QFileInfo>
#include <string>
#include <QString>

File::File(std::string _path)
{
    QFileInfo fileInfo(QString::fromStdString(_path));//создается объект, который обращается к реальному файлу
    path = _path;
    size = fileInfo.size();//получаем размер реального файла
    exist = fileInfo.exists();
}
float File::get_size()
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
void File::set_exist(const bool _exist)
{
    exist=_exist;
}
void File::set_size(float _size)
{
    size=_size;
}
