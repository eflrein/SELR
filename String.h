#ifndef _SELR_STRING_H_
#define _SELR_STRING_H_

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

#include "StringView.h"
#include "U8StringView.h"

namespace selr{
    class String{
    public:
        using size_type = std::vector<char>::size_type;
        using difference_Type = std::vector<char>::difference_type;
        using value_type = std::vector<char>::value_type;
        using reference = std::vector<char>::reference;
        using const_reference = std::vector<char>::const_reference;
        using pointer = std::vector<char>::pointer;
        using const_pointer = std::vector<char>::const_pointer;
        using iterator = std::vector<char>::iterator;
        using const_iterator = std::vector<char>::const_iterator;
        using reverse_iterator = std::vector<char>::reverse_iterator;
        using const_reverse_iterator = std::vector<char>::const_reverse_iterator;

        String();
        String(char ch,size_type size = 1);
        String(const char *str);
        String(const std::string &str);
        String(StringView view);
        String(const String &);
        String(String &&)noexcept;
        ~String();

        reference at(size_type pos);
        const_reference at(size_type pos)const;

        reference operator[](size_type pos)noexcept;
        const_reference operator[](size_type pos)const noexcept;

        reference front()noexcept;
        const_reference front()const noexcept;

        reference back()noexcept;
        const_reference back()const noexcept;

        pointer data()noexcept;
        const_pointer data()const noexcept;

        std::vector<char> &raw()noexcept;
        const std::vector<char> &raw()const noexcept;

        iterator begin()noexcept;
        iterator end()noexcept;
        const_iterator cbegin()const noexcept;
        const_iterator cend()const noexcept;
        reverse_iterator rbegin()noexcept;
        reverse_iterator rend()noexcept;
        const_reverse_iterator crbegin()const noexcept;
        const_reverse_iterator crend()const noexcept;

        bool empty()const noexcept;
        size_type size()const noexcept;
        size_type max_size()const noexcept;
        void reserve(size_type new_cap);
        size_type capacity()const noexcept;
        void shrink_to_fit();

        void clear()noexcept;
        iterator insert(const_iterator pos,const char& value);
        iterator insert(const_iterator pos,char&& value);
        iterator insert(const_iterator pos,size_type count,const char& value);
        template <class InputIt>
        iterator insert(const_iterator pos,InputIt first,InputIt last);
        iterator insert(const_iterator pos,std::initializer_list<char> ilist);
        template <class...Args>
        iterator emplace(const_iterator pos,Args&&...args);
        iterator erase(const_iterator pos);
        iterator erase(const_iterator first,const_iterator last);
        void push_back(const char &value);
        void push_back(char&& value);
        void pop_back();
        void resize(size_type count);
        void resize(size_type count,const value_type& value);

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
            return os<<str.data();
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
        std::vector<char> m_data;
    };

    template <class InputIt>
    String::iterator String::insert(String::const_iterator pos,InputIt first,InputIt last){
        return m_data.insert(pos,first,last);
    }

    template <class... Args>
    String::iterator String::emplace(String::const_iterator pos,Args &&... args){
        return m_data.emplace(pos,args...);
    }
}

#endif