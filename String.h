#ifndef _SELR_STRING_H_
#define _SELR_STRING_H_

#include <iostream>
#include <vector>
#include <string>

#include "StringView.h"
#include "U8StringView.h"

namespace selr{
    class String : public std::vector<char>{
    public:
        String();
        String(char ch,size_type size = 1);
        String(const char *str);
        String(const std::string &str);
        String(StringView view);
        String(const String &);
        String(String &&)noexcept;
        ~String();

        String &operator=(char ch);
        String &operator=(const char *str);
        String &operator=(const std::string &str);
        String &operator=(const String &str);
        String &operator=(String &&) noexcept;

        String &operator+=(char ch);
        String &operator+=(const char *str);
        String &operator+=(const std::string &str);
        String &operator+=(const String &str);

        template <class TypeA,class TypeB>
        friend String operator+(TypeA &&strl,TypeB &&strr){
            String tmp = strl;
            return (tmp += strr);
        }

        ///just for debugging
        friend std::ostream &operator<<(std::ostream &os,const String &str){
            for(auto itr:str){
                os<<itr;
            }
            return os;
        }

        friend std::istream &operator>>(std::istream &is,String &str){
            std::string buffer;
            is>>buffer;
            str = buffer;
            return is;
        }

        std::string to_std_string()const;

        StringView get_view()noexcept;
        StringView get_view(size_type pos,size_type count)noexcept;

        U8StringView get_u8view()noexcept;
        U8StringView get_u8view(size_type pos,size_type count)noexcept;
    protected:
    private:
    };
}

#endif