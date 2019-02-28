#ifndef _SELR_U8STRING_VIEW_H_
#define _SELR_U8STRING_VIEW_H_

#include <vector>
#include <string>
#include <iterator>
#include <iostream>

namespace selr{
    class U8StringView{
    public:
        using uint32 = unsigned int;

        using _iterator = std::vector<char>::iterator;

        using value_type =  std::vector<char>::value_type;
        using size_type =   std::vector<char>::size_type;
        using difference_type =  std::vector<char>::difference_type;
        using reference =   std::vector<char>::reference;
        using const_reference =   std::vector<char>::const_reference;
        using pointer =   std::vector<char>::pointer;
        using const_pointer =   std::vector<char>::const_pointer;

        class iterator{
        public:
            explicit iterator(_iterator itr);
            ~iterator();

            _iterator &raw()noexcept;
            const _iterator &raw()const noexcept;

            pointer data()noexcept;
            const_pointer data()const noexcept;

            reference operator[](size_type index)noexcept;
            const_reference operator[](size_type index)const noexcept;

            unsigned int operator*()const noexcept;

            iterator operator+(size_type offset)const noexcept;
            iterator &operator+=(size_type offset);

            iterator operator-(size_type offset)const noexcept;
            iterator &operator-=(size_type offset);

            iterator &operator++();
            const iterator operator++(int);

            iterator &operator--();
            const iterator operator--(int);

            bool operator==(const iterator &itr)const noexcept;
            bool operator!=(const iterator &itr)const noexcept;
            bool operator<(const iterator &itr)const noexcept;
            bool operator>(const iterator &itr)const noexcept;
            bool operator<=(const iterator &itr)const noexcept;
            bool operator>=(const iterator &itr)const noexcept;
        protected:
        private:
            _iterator m_itr;
        };

        U8StringView() = default;
        U8StringView(_iterator itr1,_iterator itr2);
        ~U8StringView();

        bool empty()const noexcept;
        size_type size()const noexcept;
        size_type length()const noexcept;
        uint32 front()const noexcept;
        uint32 back()const noexcept;
        pointer data()noexcept;

        void expand_left(difference_type size = 1)noexcept;
        void remove_left(difference_type size = 1)noexcept;
        void expand_right(difference_type size = 1)noexcept;
        void remove_right(difference_type size = 1)noexcept;

        uint32 operator[](difference_type index)const noexcept;

        std::string to_std_string()const;
        std::wstring to_std_wstring()const;

        iterator begin()noexcept{
            return m_begin;
        }
        iterator end()noexcept{
            return m_end;
        }

        friend std::ostream &operator<<(std::ostream &os,U8StringView &u8str){
            return os<<u8str.data();
        }
    protected:
    private:
        iterator m_begin;
        iterator m_end;
    };
}

#endif //_SELR_U8STRING_VIEW_H_