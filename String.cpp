#include "String.h"

namespace selr{
    String::String() = default;

    String::String(char ch,String::size_type size){
        this->resize(size);
        for(size_type i = 0;i < size;++i){
            this->at(i) = ch;
        }
    }

    String::String(const char *str){
        for(size_type i = 0;str[i] != '\0';++i){
            this->push_back(str[i]);
        }
    }

    String::String(StringView view){
        for(auto ch:view){
            this->push_back(ch);
        }
    }

    String::String(const std::string &str){
        this->resize(str.size());
        for(size_type i = 0;i < str.size();++i){
            this->at(i) = str.at(i);
        }
    }

    String::String(const String &) = default;

    String::String(String &&) noexcept = default;

    String::~String() = default;

    String &String::operator=(char ch){
        this->clear();
        this->push_back(ch);
        return *this;
    }

    String &String::operator=(const char *str){
        this->clear();
        for(size_type i = 0;str[i] != '\0';++i){
            this->push_back(str[i]);
        }
        return *this;
    }

    String &String::operator=(const std::string &str){
        this->resize(str.size());
        for(size_type i = 0;i < str.size();++i){
            this->at(i) = str.at(i);
        }
        return *this;
    }

    String &String::operator=(const String &str) = default;

    String &String::operator=(String &&) noexcept = default;

    String &String::operator+=(char ch){
        this->push_back(ch);
        return *this;
    }

    String &String::operator+=(const char *str){
        for(size_type i = 0;str[i] != '\0';++i){
            this->push_back(str[i]);
        }
        return *this;
    }

    String &String::operator+=(const std::string &str){
        for(char ch:str){
            this->push_back(ch);
        }
        return *this;
    }

    String &String::operator+=(const String &str){
        for(char ch:str){
            this->push_back(ch);
        }
        return *this;
    }

    StringView String::get_view() noexcept{
        return StringView(begin(),end());
    }

    StringView String::get_view(String::size_type pos,String::size_type count) noexcept{
        return StringView(begin() + pos,begin() + pos + count);
    }

}