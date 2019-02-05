#ifndef _SELR_STRING_H_
#define _SELR_STRING_H_

#include <vector>
#include <string>

namespace selr{
    class String : public std::vector<char>{
    public:
        String();
        String(char ch,size_type size = 1);
        String(const char *str);
        String(const std::string &str);
        String(const String &);
        String(String &&);
        ~String();

        String &operator=(char ch);
        String &operator=(const char *str);
        String &operator=(const std::string &str);
        String &operator=(const String &str);
        String &operator=(String &&);

        String &operator+=(char ch);
        String &operator+=(const char *str);
        String &operator+=(const std::string &str);
        String &operator+=(const String &str);
    protected:
    private:
    };
}

#endif