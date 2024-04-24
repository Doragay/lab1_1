#ifndef FILE_H
#define FILE_H
#include <string>

class File
//путь, существоавание и размер
{
private:
    std::string path;
    float size;//разобраться с типом
    bool exist;

public:
    float get_size();//функция возвращает значения типа
    bool get_exist();
    std::string get_path();
    File(std::string _path);

    // с помощью этого мы будем изменять значения, потому что напрямую делать не можем. Ничего не возвращают, просто меняют
    void set_exist(const bool _exist); //нельзя менять
    void set_size(float _size);
};

#endif // FILE_H
