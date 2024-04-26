#ifndef FILE_H
#define FILE_H
#include <string>

class File
{
private:
    std::string path;
    float size;
    bool exist;

public:
    //геттеры применяются для чтения переменной
    float get_size();
    bool get_exist();
    std::string get_path();
    File(std::string _path);
//сеттеры для записи переменной
    void set_exist(bool _exist);
    void set_size(float _size);
};

#endif // FILE_H
