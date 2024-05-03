#include "file.h"
#include <QFileInfo>
#include <string>
#include <QString>

File::File(std::string _path)
{
    QFileInfo fileInfo(QString::fromStdString(_path));//создается объект, который обращается к реальному файлу
    path = _path;
    size = fileInfo.size();//получаем размер реального файла.
    exist = fileInfo.exists();
}
float File::get_size(){

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
void File::update()
{
    QFileInfo fileInfo(QString::fromStdString(path));//обращаемся к реальному файлу и запрашиваем его размер и состояние
    size = fileInfo.size();
    exist = fileInfo.exists();
 }
