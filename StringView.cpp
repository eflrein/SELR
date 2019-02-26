#include "StringView.h"

namespace selr{
    std::string StringView::to_std_string(){
        std::string tmp;
        for(auto &itr:*this){
            tmp.push_back(itr);
        }
        return tmp;
    }
}