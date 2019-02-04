#include "String.h"

namespace selr{
    String::String() = default;

    String::String(char ch,size_type size){
        m_data.resize(size);
        for(int i = 0;i < size;++i){
            m_data[i] = ch;
        }
    }

    String::String(const char *ptr){
        for(size_type i = 0;ptr[i] != '\0';++i){
            m_data.push_back(ptr[i]);
        }
    }

    String::String(const std::string &str){
        m_data.resize(str.size());
        for(size_type i = 0;i < str.size();++i){
            m_data[i] = str[i];
        }
    }

    String::String(const String &) = default;

    String::String(String &&) = default;

    String::~String() = default;

    String &String::operator=(const std::string &str){
        m_data.resize(str.size());
        for(size_type i = 0;i < str.size();++i){
            m_data[i] = str[i];
        }
        return *this;
    }

    String &String::operator=(const char *ptr){
        m_data.clear();
        for(size_type i = 0;ptr[i] != '\0';++i){
            m_data.push_back(ptr[i]);
        }
        return *this;
    }

    String &String::operator=(const String &) = default;

    String &String::operator=(String &&) = default;

    String::reference String::front() noexcept{
        return m_data.front();
    }
    String::const_reference String::front() const noexcept{
        return m_data.front();
    }

    String::reference String::back() noexcept{
        return m_data.back();
    }
    String::const_reference String::back() const noexcept{
        return m_data.back();
    }

    void String::push_back(char ch){
        m_data.push_back(ch);
    }

    void String::pop_back(){
        m_data.pop_back();
    }

    void String::clear(){
        m_data.clear();
    }

    bool String::empty() const noexcept{
        return m_data.empty();
    }

    void String::resize(String::size_type size){
        m_data.resize(size);
    }

    String::iterator String::erase(String::iterator itr){
        return m_data.erase(itr);
    }

    String::iterator String::erase(String::const_iterator itr){
        return m_data.erase(itr);
    }

    String::iterator String::erase(String::iterator itrbeg,String::iterator itrend){
        return m_data.erase(itrbeg,itrend);
    }

    String::iterator String::erase(String::const_iterator itrbeg,String::const_iterator itrend){
        return m_data.erase(itrbeg,itrend);
    }

    String::iterator String::insert(String::iterator itr,char c){
        return m_data.insert(itr,c);
    }

    String::iterator String::insert(String::const_iterator itr,char c){
        return m_data.insert(itr,c);
    }

    String::size_type String::size() const noexcept{
        return m_data.size();
    }

    String::size_type String::max_size() const noexcept{
        return m_data.max_size();
    }

    void String::shrink_to_fit(){
        m_data.shrink_to_fit();
    }

    String::size_type String::capacity() const noexcept{
        return m_data.capacity();
    }

    void String::reserve(String::size_type new_cap){
        m_data.reserve(new_cap);
    }

    String::const_pointer String::data() const noexcept{
        return m_data.data();
    }

    String::pointer String::data() noexcept{
        return m_data.data();
    }

    String::const_reference String::operator[](String::size_type index) const noexcept{
        return m_data.at(index);
    }

    String::reference String::operator[](String::size_type index) noexcept{
        return m_data.at(index);
    }

    String::iterator String::begin() noexcept{
        return m_data.begin();
    }

    String::iterator String::end() noexcept{
        return m_data.end();
    }

    String::const_iterator String::cbegin() const noexcept{
        return m_data.cbegin();
    }

    String::const_iterator String::cend() const noexcept{
        return m_data.cend();
    }

    String::reverse_iterator String::rbegin() noexcept{
        return m_data.rbegin();
    }

    String::reverse_iterator String::rend() noexcept{
        return m_data.rend();
    }

    String::const_reverse_iterator String::crbegin() const noexcept{
        return m_data.crbegin();
    }

    String::const_reverse_iterator String::crend() const noexcept{
        return m_data,crend();
    }

    String &String::operator+=(char ch){
        m_data.push_back(ch);
        return *this;
    }

    String &String::operator+=(const char *str){
        for(size_type i = 0;str[i] != '\0';++i){
            m_data.push_back(str[i]);
        }
        return *this;
    }

    String &String::operator+=(const std::string &str){
        for(auto ch:str){
            m_data.push_back(ch);
        }
        return *this;
    }

    String &String::operator+=(const String &str){
        for(auto itr = str.cbegin();itr != str.cend();++itr){
            m_data.push_back(*itr);
        }
        return *this;
    }

}