
#include "notifier.h"

Notifier::Notifier()
{}
void Notifier::print_files_info(std::vector<std::string> &info)//выводит данные
{
    for(int i=0;i<info.size();i++){
        std::cout <<info[i] <<std::endl; //вывод на консоль
    }
}
void Notifier::file_changed(const std::string path, int size)
{
    std::cout << "File path "<< path << " was changed " << std::to_string(size) << " bytes" <<std::endl;
}

void Notifier::file_exist(const std::string path, int size)
{
    std::cout << "File path "<< path << " is exist " << std::to_string(size) << " bytes" <<std::endl;
}

void Notifier::file_deleted(const std::string path)
{
    std::cout << "File path " << path << " is not exist " << std::endl;
}
