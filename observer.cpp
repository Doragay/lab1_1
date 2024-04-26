
#include "observer.h"
#include "notifier.h"

Observer::Observer()
{
}

void Observer::add_file(std::string _path)
{
    File file(_path);//создали объект класса файл
        files.push_back(file);//добавили файл в наш вектор
}
void Observer::files_info()
{
    std::vector<std::string> info;//складываем строки с полной информацией
    for (int i=0;i<files.size();i++) //проходимся по всем файлам
    {   //собираем данные для вывода
        std::string exist = files[i].get_exist() ? "exist" : "dosn't exist";/
        info.push_back("File path: " + files[i].get_path() + " File size: " + std::to_string(files[i].get_size()) + "Exist:" + exist);//добавляем в вектор инфу
    }

   print_files_info(info);
}
void Observer::monitor()
{
   for(int i = 0;i<files.size();i++){
        QFileInfo checkFile(QString::fromStdString (files[i].get_path()));


        if((files[i].get_exist()) && (!checkFile.exists())){ // если файл существовал, а потом перестал
            files[i].set_exist(false);//обновляем данные
            files[i].set_size(0);

            emit fileNotExist(files[i].get_path()); //вызываем сигнал
        }
        else if((!files[i].get_exist()) && (checkFile.exists())){
            files[i].set_exist(true);
            files[i].set_size(checkFile.size());

            emit fileExist(files[i].get_path(), files[i].get_size());
        }
        else if(checkFile.size() != files[i].get_size()){
            files[i].set_size(checkFile.size());
            emit fileChanged(files[i].get_path(), files[i].get_size());
        }
   }
}
