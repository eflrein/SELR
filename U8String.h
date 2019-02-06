#ifndef _SELR_U8STRING_H_
#define _SELR_U8STRING_H_

#include <vector>
#include <string>

namespace selr{
    class U8String{
    public:
        using value_type = std::vector<char>::value_type;
        using size_type = std::vector<char>::size_type;
        using reference = std::vector<char>::reference;
        using const_reference = std::vector<char>::const_reference;
        using pointer = std::vector<char>::pointer;
        using const_pointer = std::vector<char>::const_pointer;

        using _iterator = std::vector<char>::iterator;
        using _const_iterator = std::vector<char>::const_iterator;

        class iterator{
        public:
            iterator(_iterator itr);
            ~iterator();

            pointer data()noexcept;
            const_pointer data()const noexcept;

            reference operator[](size_type index)noexcept;
            const_reference operator[](size_type index)const noexcept;

            iterator operator+(size_type offset);
            iterator &operator+=(size_type offset);

            iterator operator++();
            iterator operator++(int);
        protected:
        private:
            _iterator m_itr;
        };

        U8String();
        U8String(const char *str);
        U8String(const std::string &str);
        U8String(const U8String &);
        U8String(U8String &&);
        ~U8String();

        U8String &operator=(const char *str);
        U8String &operator=(const std::string &str);
        U8String &operator=(const U8String &);
        U8String &operator=(U8String &&);


    protected:
    private:
        std::vector<char> m_data;
    };
}

#endif //_SELR_U8STRING_H_