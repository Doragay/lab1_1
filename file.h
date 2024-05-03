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
    File(std::string _path);
    float get_size();
    bool get_exist();
    std::string get_path();
    void update();
};

#endif // FILE_H
