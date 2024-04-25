
#include "notifier.h"

Notifier::Notifier()
{

}
void Notifier::print_files_info(std::vector<std::string> &info)
{
    for(int i=0;i<info.size();i++){
        std::cout <<info[i] <<std::endl;
    }
}
