
#include <QCoreApplication>
#include <observer.h>
#include <notifier.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Notifier notifire;
    Observer observer;
    QObject::connect(&observer,&Observer::print_files_info, &notifire,&Notifier::print_files_info);
    observer.add_file("C:\\TRPO\\lab1\\filess\\file1.txt");
    observer.add_file("C:\\TRPO\\lab1\\filess\\file2.txt");
    observer.add_file("C:\\TRPO\\lab1\\filess\\file3.txt");
    observer.files_info();
    return a.exec();
}
