#ifndef _SELR_STRING_VIEW_H_
#define _SELR_STRING_VIEW_H_

#include <iostream>
#include "Range.hpp"

namespace selr{
    template <class Iterator>
    class StringView : public ContainerRange<Iterator>{
    public:
        StringView(Iterator iter1,Iterator iter2)
            :ContainerRange<Iterator>(iter1,iter2){}
        ~StringView() = default;

        friend std::ostream &operator<<(std::ostream &os,StringView &view){
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