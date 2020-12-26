
#ifndef ANDROID_ASTL_STRING__
#define ANDROID_ASTL_STRING__
#include <cstddef>


namespace std {
// Simple string implementation. Its purpose is to be able to compile code that
// uses the STL and requires std::string.
//
// IMPORTANT:
// . This class it is not fully STL compliant. Some constructors/methods maybe
// missing, they will be added on demand.
// . We don't provide a std::basic_string template that std::string extends
// because we use only char (wchar is not supported on Android).
// . The memory allocation scheme uses the heap. Since Android has the concept
// of SharedBuffer, we may, in the future, templatize this class and add an
// allocation parameter.
// . The implementation is not optimized in any way (no copy on write support),
// temporary instance may be expensive.
// . Currently there is no support for iterators.
//
class string
{
  public:
    typedef size_t size_type;
    typedef char   value_type;
    static const size_type npos = static_cast<size_type>(-1);
    // Constructors
    string();
    // Construct a string from a source's substring.
    // @param str The source string.
    // @param pos The index of the character to start the copy at.
    // @param n The number of characters to copy. Use string::npos for the
    // remainder.
    string(const string& str, size_t pos = 0, size_type n = npos);
    // Construct a string from a C string.
    // @param str The source string, must be '\0' terminated.
    string(const value_type *str);
    // Construct a string from a char array.
    // @param str The source C string. '\0' are ignored.
    // @param n The number of characters to copy.
    string(const value_type *str, size_type n);
    // Construct a string from a repetition of a character.
    // @param n The number of characters.
    // @param c The character to use.
    string(size_t n, char c);
    // Construct a string from a char array.
    // @param begin The start of the source C string. '\0' are ignored.
    // @param end The end of source C string. Points just pass the last
    // character.
    string(const value_type *begin, const value_type *end);
    ~string();
    // @return The number of characters in the string, not including any
    // null-termination.
    size_type length() const { return mLength; }
    size_type size() const { return mLength; }
    // @return A pointer to null-terminated contents.
    const value_type *c_str() const { return mData; }
    const value_type *data() const { return mData; }
    // Empty the string on return. Release the internal buffer. Length
    // and capacity are both 0 on return. If you want to keep the
    // internal buffer around for reuse, call 'erase' instead.
    void clear();
    // @return true if the string is empty.
    bool empty() const { return this->size() == 0; }
    // Remove 'len' characters from the string starting at 'pos'. The
    // string length is reduced by 'len'. If len is greater or equal
    // to the number of characters in the string, it is truncated at
    // 'pos'. If 'pos' is beyond the end of the string, 'erase' does
    // nothing. Note, regular STL implementations throw a out_of_range
    // exception in this case.
    // Internally, the capacity of the buffer remains unchanged. If
    // you wanted to recover the deleted chars' memory you should call
    // 'reserve' explicitly (see also 'clear').
    // @param pos Index of the first character to remove (default to 0)
    // @param n Number of characters to delete. (default to remainder)
    // @return a reference to this string.
    string& erase(size_type pos = 0, size_type n = npos);
    // @param str The string to be append.
    // @return A reference to this string.
    string& operator+=(const string& str) { return this->append(str); }
    // @param str The C string to be append.
    // @return A reference to this string.
    string& operator+=(const value_type *str) { return this->append(str); }
    // @param c A character to be append.
    // @return A reference to this string.
    string& operator+=(const char c) { this->push_back(c); return *this; }
    // @param c A character to be append.
    void push_back(const char c);
    // no-op if str is NULL.
    string& append(const value_type *str);
    // no-op if str is NULL. n must be >= 0.
    string& append(const value_type *str, size_type n);
    // no-op if str is NULL. pos and n must be >= 0.
    string& append(const value_type *str, size_type pos, size_type n);
    string& append(const string& str);
    // Comparison.
    // @return 0 if this==other, < 0 if this < other and > 0 if this > other.
    // Don't assume the values are -1, 0, 1
    int compare(const string& other) const;
    int compare(const value_type *other) const;
    friend bool operator==(const string& left, const string& right);
    friend bool operator==(const string& left, const value_type *right);
    friend bool operator==(const value_type *left, const string& right) { return right == left; }
    friend bool operator!=(const string& left, const string& right) { return !(left == right); }
    friend bool operator!=(const string& left, const char* right) { return !(left == right); }
    friend bool operator!=(const value_type *left, const string& right) { return !(left == right); }
    // @return Number of elements for which memory has been allocated. capacity >= size().
    size_type capacity() const { return mCapacity; }
    // Change the capacity to new_size. No effect if new_size < size().
    // 0 means Shrink to fit.
    // @param new_size number of character to be allocated.
    void reserve(size_type new_size = 0);
    // Exchange the content of this with the content of other.
    // @param other Instance to swap this one with.
    void swap(string& other);
    // Accessors.
    // @param pos of the char. No boundary, signed checks are done.
    // @return a const reference to the char.
    const char& operator[](const size_type pos) const;
    // @param pos of the char. No boundary, signed checks are done.
    // @return a reference to the char.
    char& operator[](const size_type pos);
    // Assignments.
    string& operator=(const string& str) { return assign(str); }
    string& operator=(const char* str) { return assign(str); }
    string& operator=(char c);
    string& assign(const string& str);
    // Assign a substring of the original.
    // @param str Original string.
    // @param pos Index of the start of the copy.
    // @param n Number of character to be copied.
    string& assign(const string& str, size_type pos, size_type n);
    string& assign(const value_type *str);
    // Assign a non-nul terminated array of chars.
    // @param array Of chars non-nul terminated.
    // @param len Length of the array.
    string& assign(const value_type *array, size_type len);
    // Concat. Prefer using += or append.
    // Uses unnamed object for return value optimization.
    friend string operator+(const string& left, const string& right) {
        return string(left).append(right);
    }
    friend string operator+(const string& left, const value_type *right) {
        return string(left).append(right);
    }
    friend string operator+(const value_type *left, const string& right) {
        return string(left).append(right);
    }
    friend string operator+(const string& left, char right) {
        return string(left).operator+=(right);
    }
    friend string operator+(char left, const string& right) {
        return string(&left, 1).append(right);
    }
    // Find the position of a sub-string. The empty string is always
    // found at the requested position except when it's beyond the
    // string's end.
    // @param str String to locate.
    // @param pos Index of the character to search from. Default to 0.
    // @return Index of start of the first occurrence of the
    // string. string::npos if no occurrence of str was found from the
    // starting position.
    size_type find(const string& str, size_type pos = 0) const {
        return find(str.mData, pos);
    }
    // Find the position of a C sub-string. The empty string is always
    // found at the requested position except when it's beyond the
    // string's end.
    // @param str C string to locate.
    // @param pos Index of the character to search from. Default to 0.
    // @return Index of start of the first occurrence of the
    // string. string::npos if no occurrence of str was found from the
    // starting position.
    size_type find(const value_type *str, size_type pos = 0) const;
    // @return a substring of this one.
    string substr(size_type pos = 0, size_type n = npos) const {
        return string(*this, pos, n);
    }
  private:
    bool SafeMalloc(size_type n);
    void SafeRealloc(size_type n);
    void SafeFree(value_type *str);
    void ResetTo(value_type *str);
    void ConstructEmptyString();
    void Constructor(const value_type *str, size_type n);
    void Constructor(const value_type *str, size_type pos, size_type n);
    void Constructor(size_type num, char c);
    void DeleteSafe();
    void Append(const value_type *str, size_type len);
    value_type *mData;  // pointer to the buffer
    size_type mCapacity;  // size of the buffer.
    size_type mLength;  // len of the string excl. null-terminator.
};
}  // namespace std
#endif  // ANDROID_ASTL_STRING__

