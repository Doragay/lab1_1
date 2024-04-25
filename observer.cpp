
#include "observer.h"
#include "notifier.h"

Observer::Observer()
{
    //connect(this, &Observer::print_files_info, &Notifier::print_files_info);
}

void Observer::add_file(std::string _path) //этафункция принадлежит этому классу. Определ для функции класса
{
    File file(_path);//создали объект класса файл
    files.push_back(file);//добавили файл в наш массив, вектор
}
void Observer::files_info()
{
    std::vector<std::string> info;//складываем строки с полной информацией
    for (int i=0;i<files.size();i++) //проходимся по всем файлам
    {   //собираем данные для вывода
        std::string exist = files[i].get_exist() ? "exist" : "dosn't exist";//проверка на существование
        info.push_back("File path: " + files[i].get_path() +" exists. File size: " + std::to_string(files[i].get_size()) +" Exist:"+exist);//добавляем в вектор инфу
    }

   print_files_info(info);
}
