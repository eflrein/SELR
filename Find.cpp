#include "Find.h"

#include <iostream>
using namespace std;

namespace selr{

    StringView find_bruteforce(StringView target,StringView pattern){
        StringView ans(target.begin(),target.begin());
        for(auto itr = target.begin();itr != target.end();++itr){
            StringView tmp(itr,itr);
            auto target_itr = itr,
                 pattern_itr = pattern.begin();
            for(;pattern_itr != pattern.end() && target_itr != target.end();
                 ++pattern_itr,++target_itr){
                if(*pattern_itr == *target_itr){
                    tmp.expand_right();
                }else{
                    if(tmp.size() > ans.size()){
                        ans = tmp;
                    }
                    break;
                }
            }
            if(pattern_itr == pattern.end() || target_itr == target.end()){
                if(tmp.size() > ans.size()){
                    ans = tmp;
                }
            }
        }
        return ans;
    }
}