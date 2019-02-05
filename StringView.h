#ifndef _SELR_STRING_VIEW_H_
#define _SELR_STRING_VIEW_H_

#include <iterator>

namespace selr{
    template <class Iterator>
    class StringView{
    public:
        using value_type = typename std::iterator_traits<Iterator>::value_type;
        using pointer = typename std::iterator_traits<Iterator>::pointer;
        using const_pointer = typename std::iterator_traits<Iterator>::const_pointer;
        using reference = typename std::iterator_traits<Iterator>::reference;
        using const_reference = typename std::iterator_traits<Iterator>::const_reference;
        using size_type = typename std::iterator_traits<Iterator>::size_type;
        using difference_type = typename std::iterator_traits<Iterator>::difference_type;

        StringView();
        StringView(Iterator iter_begin,Iterator Iter
        StringView(const StringView &);
        StringView(StringView &&);
        ~StringView();

        StringView &operator=(StringType &);
        StringView &operator=(const StringView &);
        StringView &operator=(StringView &&);

        void remove_prefix(size_type size);
        void expand_prefix(size_type size);
        void remove_suffix(size_type size);
        void expand_suffix(size_type size);

        reference front()noexcept;
        const_reference front()const noexcept;
        reference back()noexcept;
        const_reference back()const noexcept;

        bool empty()const noexcept;

        size_type size()const noexcept;

        reference operator[](size_type index)noexcept;
        const_reference operator[](size_type index) const noexcept;

        pointer data()noexcept;
        const_pointer data()const noexcept;

        iterator begin()noexcept;
        iterator end()noexcept;
    protected:
    private:
        iterator m_begin;
        iterator m_end;
    };
}

#endif