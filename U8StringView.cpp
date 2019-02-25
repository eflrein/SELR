#include "U8StringView.h"

namespace selr{

    U8StringView::iterator::iterator(U8StringView::_iterator itr)
        :m_itr(itr){}

    U8StringView::iterator::~iterator() = default;

    U8StringView::pointer U8StringView::iterator::data() noexcept{
        return &(*m_itr);
    }

    U8StringView::const_pointer U8StringView::iterator::data() const noexcept{
        return &(*m_itr);
    }

    U8StringView::reference U8StringView::iterator::operator[](U8StringView::size_type index) noexcept{
        return *(m_itr + index);
    }

    U8StringView::const_reference U8StringView::iterator::operator[](U8StringView::size_type index) const noexcept{
        return *(m_itr + index);
    }

    U8StringView::uint32 U8StringView::iterator::operator*() const noexcept{
        if((*m_itr & 0x80) == 0x00){
            return static_cast<uint32>(*m_itr);
        }else if((*m_itr & 0xE0) == 0xC0){
            return static_cast<uint32>(((*m_itr & 0x1F) << 6) | (m_itr[1] & 0x3F));
        }else if((*m_itr & 0xF0) == 0xE0){
            return static_cast<uint32>(((*m_itr & 0xF) << 12) | ((m_itr[1] & 0x3F) << 6) | (m_itr[2] & 0x3F));
        }else if((*m_itr & 0xF8) == 0xF0){
            return static_cast<uint32>(((*m_itr & 0x7) << 18) | ((m_itr[1] & 0x3F) << 12) | ((m_itr[2] & 0x3F) << 6) | (m_itr[3] & 0x3F));
        }else if((*m_itr & 0xFC) == 0xF8){
            return static_cast<uint32>(((*m_itr & 0x7) << 24) | ((m_itr[1] & 0x3F) << 18) | ((m_itr[2] & 0x3F) << 12) | ((m_itr[3] & 0x3F) << 6) | (m_itr[4] & 0x3F));
        }else if((*m_itr & 0xFE) == 0xFC){
            return static_cast<uint32>(((*m_itr & 0x7) << 30) | ((m_itr[1] & 0x3F) << 24) | ((m_itr[2] & 0x3F) << 18) | ((m_itr[3] & 0x3F) << 12) | ((m_itr[4] & 0x3F) << 6) | (m_itr[5] & 0x3F));
        }
        return 0;
    }

    U8StringView::iterator U8StringView::iterator::operator+(U8StringView::size_type offset)const noexcept{
        auto ans = iterator(m_itr);
        for(int i = 0;i < offset;++i)
            ++ans;
        return ans;
    }

    U8StringView::iterator &U8StringView::iterator::operator+=(U8StringView::size_type offset){
        for(int i = 0;i < offset;++i)
            ++(*this);
        return *this;
    }

    U8StringView::iterator U8StringView::iterator::operator-(U8StringView::size_type offset)const noexcept{
        auto ans = iterator(m_itr);
        for(int i = 0;i < offset;++i)
            --ans;
        return ans;
    }

    U8StringView::iterator &U8StringView::iterator::operator-=(U8StringView::size_type offset){
        for(int i = 0;i < offset;++i)
            --(*this);
        return *this;
    }

    U8StringView::iterator &U8StringView::iterator::operator++(){
        if((*m_itr & 0x80) == 0x00){
            ++m_itr;
        }else if((*m_itr & 0xE0) == 0xC0){
            m_itr += 2;
        }else if((*m_itr & 0xF0) == 0xE0){
            m_itr += 3;
        }else if((*m_itr & 0xF8) == 0xF0){
            m_itr += 4;
        }else if((*m_itr & 0xFC) == 0xF8){
            m_itr += 5;
        }else if((*m_itr & 0xFE) == 0xFC){
            m_itr += 6;
        }
        return *this;
    }

    const U8StringView::iterator U8StringView::iterator::operator++(int){
        return ++iterator(m_itr);
    }

    U8StringView::iterator &U8StringView::iterator::operator--(){
        for(--m_itr;(*m_itr & 0xC0) == 0x80; --m_itr)
            ;
        return *this;
    }

    const U8StringView::iterator U8StringView::iterator::operator--(int){
        return --iterator(m_itr);
    }

    bool U8StringView::iterator::operator==(const U8StringView::iterator &itr) const noexcept{
        return m_itr == itr.m_itr;
    }

    bool U8StringView::iterator::operator!=(const U8StringView::iterator &itr) const noexcept{
        return m_itr != itr.m_itr;
    }

    bool U8StringView::iterator::operator<(const U8StringView::iterator &itr) const noexcept{
        return m_itr < itr.m_itr;
    }

    bool U8StringView::iterator::operator>(const U8StringView::iterator &itr) const noexcept{
        return m_itr > itr.m_itr;
    }

    bool U8StringView::iterator::operator<=(const U8StringView::iterator &itr) const noexcept{
        return m_itr <= itr.m_itr;
    }

    bool U8StringView::iterator::operator>=(const U8StringView::iterator &itr) const noexcept{
        return m_itr >= itr.m_itr;
    }

    U8StringView::_iterator &U8StringView::iterator::raw() noexcept{
        return m_itr;
    }

    const U8StringView::_iterator &U8StringView::iterator::raw() const noexcept{
        return m_itr;
    }


    U8StringView::U8StringView(U8StringView::_iterator itr1,U8StringView::_iterator itr2)
        :m_begin(itr1),
         m_end(itr2){}

    bool U8StringView::empty() const noexcept{
        return size() == 0;
    }

    U8StringView::size_type U8StringView::size() const noexcept{
        return static_cast<size_type>(m_end.raw() - m_begin.raw());
    }

    U8StringView::size_type U8StringView::length() const noexcept{
        size_type count = 0;
        for(auto itr = m_begin;itr != m_end;++itr){
            ++count;
        }
        return count;
    }

    U8StringView::uint32 U8StringView::front() const noexcept{
        return *m_begin;
    }

    U8StringView::uint32 U8StringView::back() const noexcept{
        return *(m_end - 1);
    }

    U8StringView::pointer U8StringView::data() noexcept{
        return m_begin.data();
    }

    void U8StringView::expand_left(U8StringView::difference_type size) noexcept{
        --m_begin;
    }

    void U8StringView::remove_left(U8StringView::difference_type size) noexcept{
        ++m_begin;
    }

    void U8StringView::expand_right(U8StringView::difference_type size) noexcept{
        ++m_end;
    }

    void U8StringView::remove_right(U8StringView::difference_type size) noexcept{
        --m_end;
    }

    U8StringView::uint32 U8StringView::operator[](U8StringView::difference_type index)const noexcept{
        return *(m_begin + index);
    }

    U8StringView::~U8StringView() = default;
}