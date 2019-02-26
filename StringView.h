#ifndef _SELR_STRING_VIEW_H_
#define _SELR_STRING_VIEW_H_

#include <iostream>
#include <vector>
#include "XRange/Range.hpp"

namespace selr{
    class StringView : public xrange::ContainerRange<
            std::vector<char>::iterator
        >{
    public:
        StringView() = default;
        StringView(iterator iter1,iterator iter2)
            :ContainerRange<iterator>(iter1,iter2){}
        ~StringView() = default;

        std::string to_std_string();

        friend std::ostream &operator<<(std::ostream &os,StringView view){
            for(char ch:view){
                os<<ch;
            }
            return os;
        }
    protected:
    private:
    };
	//sdfdsf
}

#endif