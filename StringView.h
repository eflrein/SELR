#ifndef _SELR_STRING_VIEW_H_
#define _SELR_STRING_VIEW_H_

#include <iostream>
#include "Range.hpp"

namespace selr{
    class StringView : public ContainerRange<
            std::vector<char>::iterator >{
    public:
        StringView() = default;
        StringView(iterator iter1,iterator iter2)
            :ContainerRange<iterator>(iter1,iter2){}
        ~StringView() = default;

        friend std::ostream &operator<<(std::ostream &os,StringView view){
            for(char ch:view){
                os<<ch;
            }
            return os;
        }
    protected:
    private:
    };
}

#endif