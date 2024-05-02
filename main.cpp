
#include <QCoreApplication>
#include <observer.h>
#include <notifier.h>
#include <thread>
#include <chrono>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Notifier notifire;
    Observer observer;
    QObject::connect(&observer,&Observer::print_files_info, &notifire,&Notifier::print_files_info);
    QObject::connect(&observer,&Observer::fileExist, &notifire,&Notifier::file_exist);
    QObject::connect(&observer,&Observer::fileNotExist, &notifire,&Notifier::file_deleted);
    QObject::connect(&observer,&Observer::fileChanged, &notifire,&Notifier::file_changed);
    observer.add_file("C:\\TRPO\\lab1\\filess\\file1.txt");
    observer.add_file("C:\\TRPO\\lab1\\filess\\file2.txt");
    observer.add_file("C:\\TRPO\\lab1\\filess\\file3.txt");
    observer.add_file("C:\\TRPO\\lab1\\filess\\file4.txt");
    observer.files_info();

    std::cout << "Start to observe" << std::endl;
    while(true)//запускаем цикл, вызывающую  функцию монитор. Цикл с задержкой в 100 милисекунд
    {
        std::this_thread::sleep_for( std::chrono::milliseconds(100));
        observer.monitor();
    }
    return a.exec();
}
