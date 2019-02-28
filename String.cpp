#include "String.h"

namespace selr{
    String::String() = default;

    String::String(char ch,String::size_type size){
        resize(size + 1);
        for(size_type i = 0;i < size;++i){
            at(i) = ch;
        }
        at(size) = '\0';
    }

    String::String(const char *str){
        for(size_type i = 0;str[i] != '\0';++i){
            push_back(str[i]);
        }
        push_back('\0');
    }

    String::String(StringView view){
        for(auto ch:view){
            push_back(ch);
        }
        push_back('\0');
    }

    String::String(const std::string &str){
        resize(str.size() + 1);
        for(size_type i = 0;i < str.size();++i){
            at(i) = str.at(i);
        }
        push_back('\0');
    }

    String::String(const String &) = default;

    String::String(String &&) noexcept = default;

    String::~String() = default;

    String &String::operator=(char ch){
        clear();
        push_back(ch);
        push_back('\0');
        return *this;
    }

    String &String::operator=(const char *str){
        clear();
        for(size_type i = 0;str[i] != '\0';++i){
            push_back(str[i]);
        }
        push_back('\0');
        return *this;
    }

    String &String::operator=(const std::string &str){
        resize(str.size() + 1);
        for(size_type i = 0;i < str.size();++i){
            at(i) = str.at(i);
        }
        at(str.size()) = '\0';
        return *this;
    }

    String &String::operator=(const String &str) = default;

    String &String::operator=(String &&) noexcept = default;

    String &String::operator+=(char ch){
        pop_back();
        push_back(ch);
        push_back('\0');
        return *this;
    }

    String &String::operator+=(const char *str){
        pop_back();
        for(size_type i = 0;str[i] != '\0';++i){
            push_back(str[i]);
        }
        push_back('\0');
        return *this;
    }

    String &String::operator+=(const std::string &str){
        pop_back();
        for(char ch:str){
            push_back(ch);
        }
        push_back('\0');
        return *this;
    }

    String &String::operator+=(const String &str){
        pop_back();
        for(auto itr = str.cbegin();itr != str.cend();++itr){
            this->push_back(*itr);
        }
        push_back('\0');
        return *this;
    }

    StringView String::get_view() noexcept{
        return StringView(begin(),end());
    }

    StringView String::get_view(String::size_type pos,String::size_type count) noexcept{
        return StringView(begin() + pos,begin() + pos + count);
    }

    U8StringView String::get_u8view() noexcept{
        return U8StringView(begin(),end());
    }

    U8StringView String::get_u8view(size_type pos,size_type count) noexcept{
        return U8StringView(begin() + pos,begin() + pos + count);
    }

    std::string String::to_std_string() const{
        return std::string(m_data.data());
    }

    char &String::front() noexcept{
        return m_data.front();
    }

    const char &String::front() const noexcept{
        return m_data.front();
    }

    char &String::back() noexcept{
        return m_data.back();
    }

    const char &String::back() const noexcept{
        return m_data.back();
    }

    String::pointer String::data() noexcept{
        return m_data.data();
    }

    String::const_pointer String::data() const noexcept{
        return m_data.data();
    }

    std::vector<char> &String::raw()noexcept{
        return m_data;
    }
    const std::vector<char> &String::raw()const noexcept{
        return m_data;
    }

    String::iterator String::begin() noexcept{
        return m_data.begin();
    }

    String::iterator String::end() noexcept{
        return m_data.end() - 1;
    }

    String::const_iterator String::cbegin() const noexcept{
        return m_data.cbegin();
    }

    String::const_iterator String::cend() const noexcept{
        return m_data.cend() - 1;
    }

    String::reverse_iterator String::rbegin() noexcept{
        return m_data.rbegin() + 1;
    }

    String::reverse_iterator String::rend() noexcept{
        return m_data.rend();
    }

    String::const_reverse_iterator String::crbegin() const noexcept{
        return m_data.crbegin() + 1;
    }

    String::const_reverse_iterator String::crend() const noexcept{
        return m_data.crend();
    }

    bool String::empty() const noexcept{
        return m_data.empty();
    }

    String::size_type String::size() const noexcept{
        return static_cast<size_type>(std::distance(cbegin(),cend()));
    }

    String::size_type String::max_size() const noexcept{
        return m_data.max_size();
    }

    void String::reserve(String::size_type new_cap){
        m_data.reserve(new_cap);
    }

    String::size_type String::capacity() const noexcept{
        return m_data.capacity();
    }

    void String::shrink_to_fit(){
        m_data.shrink_to_fit();
    }

    void String::clear() noexcept{
        m_data.clear();
    }

    String::iterator String::insert(String::const_iterator pos,const char &value){
        return m_data.insert(pos,value);
    }

    String::iterator String::insert(String::const_iterator pos,char &&value){
        return m_data.insert(pos,value);
    }

    String::iterator String::insert(String::const_iterator pos,String::size_type count,const char &value){
        return m_data.insert(pos,count,value);
    }

    String::iterator String::insert(String::const_iterator pos,std::initializer_list<char> ilist){
        return m_data.insert(pos,ilist);
    }

    String::iterator String::erase(String::const_iterator pos){
        return m_data.erase(pos);
    }

    String::iterator String::erase(String::const_iterator first,String::const_iterator last){
        return m_data.erase(first,last);
    }

    void String::push_back(const char &value){
        m_data.push_back(value);
    }

    void String::push_back(char &&value){
        m_data.push_back(value);
    }

    void String::pop_back(){
        m_data.pop_back();
    }

    void String::resize(String::size_type count){
        m_data.resize(count);
    }

    void String::resize(String::size_type count,const String::value_type &value){
        m_data.resize(count,value);
    }

    char &String::at(String::size_type pos){
        return m_data.at(pos);
    }

    const char &String::at(String::size_type pos) const{
        return m_data.at(pos);
    }

    char &String::operator[](String::size_type pos) noexcept{
        return m_data[pos];
    }

    const char &String::operator[](String::size_type pos) const noexcept{
        return m_data[pos];
    }

}