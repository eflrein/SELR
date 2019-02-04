#ifndef _SELR_STRING_H_
#define _SELR_STRING_H_

#include <vector>
#include <string>
#include <iostream>

namespace selr{
    class String{
    public:
        using size_type = std::vector<char>::size_type;
        using value_type = char;
        using allocator_type = std::vector<char>::allocator_type;
        using difference_type = std::vector<char>::difference_type;
        using reference = std::vector<char>::reference;
        using const_reference = std::vector<char>::const_reference;
        using pointer = std::vector<char>::pointer;
        using const_pointer = std::vector<char>::const_pointer;

        using iterator = std::vector<char>::iterator;
        using const_iterator = std::vector<char>::const_iterator;
        using reverse_iterator = std::vector<char>::reverse_iterator;
        using const_reverse_iterator = std::vector<char>::const_reverse_iterator;

        String();
        String(const std::string &);
        String(char ch,size_type size = 1);
        String(const char *);
        template <class InputIter>
        String(InputIter itr1,InputIter itr2);
        String(const String &);
        String(String &&);
        ~String();

        String &operator=(const char *);
        String &operator=(const std::string &);
        String &operator=(const String &);
        String &operator=(String &&);

        reference front()noexcept;
        const_reference front()const noexcept;
        reference back()noexcept;
        const_reference back()const noexcept;

        void push_back(char ch);
        void pop_back();

        void clear();
        bool empty()const noexcept;
        void resize(size_type size);
        iterator erase(iterator itr);
        iterator erase(const_iterator itr);
        iterator erase(iterator itrbeg,iterator itrend);
        iterator erase(const_iterator itrbeg,const_iterator itrend);
        iterator insert(iterator itr,char c);
        iterator insert(const_iterator itr,char c);
        template <class InputIter>
        iterator insert(iterator itr,InputIter itr1,InputIter itr2);

        size_type size()const noexcept;
        size_type max_size()const noexcept;
        void shrink_to_fit();
        size_type capacity()const noexcept;
        void reserve(size_type new_cap);

        const_pointer data()const noexcept;
        pointer data()noexcept;

        const_reference operator[](size_type index)const noexcept;
        reference operator[](size_type index)noexcept;

        iterator begin()noexcept;
        iterator end()noexcept;
        const_iterator cbegin()const noexcept;
        const_iterator cend()const noexcept;
        reverse_iterator rbegin()noexcept;
        reverse_iterator rend()noexcept;
        const_reverse_iterator crbegin()const noexcept;
        const_reverse_iterator crend()const noexcept;

        friend std::ostream &operator<<(std::ostream &os,String &str){
            for(char ch:str){
                os<<ch;
            }
            return os;
        }
        friend std::istream &operator>>(std::istream &is,String &str){
            std::string buffer;
            is>>buffer;
            str = buffer;
            return is;
        }

        String &operator+=(char ch);
        String &operator+=(const char *);
        String &operator+=(const std::string &);
        String &operator+=(const String &);

        template <class TypeA,class TypeB>
        friend String operator+(TypeA &&strl,TypeB &&strr){
            String tmp = strl;
            tmp += strr;
            return tmp;
        }
    protected:
    private:
        std::vector<char> m_data;
    };
}

#endif //_SELR_STRING_H_
