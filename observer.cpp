
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
void Observer::files_info()//собирает данные и отправляет в функцию
{
    std::vector<std::string> info;//складываем строки с полной информацией
    for (int i=0;i<files.size();i++) //проходимся по всем файлам
    {   //собираем данные для вывода
        std::string exist = files[i].get_exist() ? "exist" : "dosn't exist";//проверка на существование
        info.push_back("File path: " + files[i].get_path() +" exists. File size: " + std::to_string(files[i].get_size()) +" Exist:"+exist);//добавляем в вектор инфу
    }

   print_files_info(info);
}
void Observer::monitor()//оператор расширения видимости
{
   for(int i = 0;i<files.size();i++){
        QFileInfo checkFile(QString::fromStdString (files[i].get_path()));//обращется к реальному файлу

        //проверям изменился ли файл или изменилось ли его наличие
        if((files[i].get_exist()) && (!checkFile.exists())){ // если файл существовал, а потом перестал. сравниваем значения
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
