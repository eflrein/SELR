#include "Find.h"

#include <array>
#include <iterator>
#include <type_traits>

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

    StringView find_boyermoore(StringView target,StringView pattern){
        ///preprocess
        std::array<StringView::difference_type,256> bad_char;
        for(auto &itr : bad_char)
            itr = pattern.size();
        std::vector<StringView::difference_type> good_suffix_offset;
        good_suffix_offset.resize(static_cast<unsigned long long int>(pattern.size() + 1));
        good_suffix_offset[pattern.size()] = 1;
        StringView::difference_type last_offset = 1 ;
        for(auto suffix_begin = pattern.end() - 1;suffix_begin >= pattern.begin();--suffix_begin){
            auto index = std::distance(pattern.begin(),suffix_begin);
            ///bad character
            if(bad_char[static_cast<unsigned char>(*suffix_begin)] == pattern.size()){
                bad_char[static_cast<unsigned char>(*suffix_begin)] = index;
            }
            ///good suffix
            bool find_success = false;
            good_suffix_offset[index] = pattern.size();
            for(auto remain_begin = suffix_begin - 1;remain_begin >= pattern.begin();--remain_begin){
                bool remain_success = true;
                for(auto suffix_itr = suffix_begin,
                         remain_itr = remain_begin;
                     suffix_itr < pattern.end();
                     ++suffix_itr,++remain_itr){
                    if(*suffix_itr != *remain_itr){
                        remain_success = false;
                        break;
                    }
                }
                if(remain_success){
                    find_success = true;
                    if(remain_begin != pattern.begin()){
                        ///rescan for prefix
                        bool prefix_success = true;
                        for(auto suffix_itr = suffix_begin,
                                 prefix_itr = pattern.begin();
                             suffix_itr != pattern.end();
                             ++suffix_itr,++prefix_itr){
                            if(*suffix_itr != *prefix_itr){
                                prefix_success = false;
                                break;
                            }
                        }
                        if(prefix_success){
                            last_offset = std::distance(pattern.begin(),suffix_begin);
                        }
                    }else{
                        last_offset = std::distance(remain_begin,suffix_begin);
                    }
                    good_suffix_offset[index] = std::distance(remain_begin,suffix_begin);
                    break;
                }
            }
            if(!find_success){
                good_suffix_offset[index] = last_offset;
            }
        }

        ///search
        StringView::difference_type offset = 1;
        for(auto target_begin = target.begin() + pattern.size() - 1;target_begin < target.end();target_begin += offset){
            bool success = true;
            for(auto target_itr = target_begin,
                     pattern_itr = pattern.end() - 1;
                 pattern_itr >= pattern.begin();
                 --pattern_itr,--target_itr){
                if(target_itr >= target.end()){
                    success = false;
                    break;
                }
                if(*pattern_itr != *target_itr){
                    success = false;
                    ///calculate offset
                    auto mismatch_index = std::distance(pattern.begin(),pattern_itr);
                    if(bad_char[static_cast<unsigned char>(*target_itr)] == pattern.size()){
                        //not including
                        offset = mismatch_index + 1;
                    }else{
                        //including
                        auto temp = mismatch_index - bad_char[static_cast<unsigned char>(*target_itr)];
                        offset = temp < 1 ? 1 : temp;
                    }
                    offset = std::max(good_suffix_offset[mismatch_index + 1],offset);
                    break;
                }
            }
            if(success){
                return StringView(target_begin - pattern.size() + 1,target_begin + 1);
            }
        }
        return StringView(target.begin(),target.begin());
    }
}