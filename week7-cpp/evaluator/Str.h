/* Pim van Helvoirt
 * Leo Schreuders
 */

#ifndef STR_INCLUDED
#define STR_INCLUDED

#include <string>
#include <sstream>
#include <iostream>

class Str
{

private:
    std::string m_str;

public:

    Str() : m_str{""}{}
    Str(std::string string) {
      m_str = string;
    }

    std::string get_string() const                     { return m_str;}
    void set_string(std::string string) {m_str = string;}

    // give operator access to private variables
    friend std::istream& operator>>(std::istream& is,Str& string);

};


/*! Reads a Str 'string' from 'is' stream. */
std::istream& operator>>(std::istream& is,Str& string)
{

    std::string token;
    is >> token;


    string.set_string(token);

    return is; // to be completed
}

/*! Writes Str 'string' to 'os' stream. */
std::ostream& operator<<(std::ostream& os,const Str& string)
{

    os << string.get_string();

    return os;
}

/*! Returns a new Str that is the negation of 'string'. */
Str operator-(const Str& string)
{
    std::string new_string = "(-" + string.get_string() + ")";

    Str new_str(new_string);

    return new_str;
}

/*! Returns a new Str that is the transpose of 'string'. */
Str transpose(const Str& string)
{

    Str new_str(string.get_string());

    return new_str;
}

/*! Returns a new String that is equal to 'string1+string2'. */
Str operator+(const Str& string1,const Str& string2)
{
    std::string new_string = "(" + string1.get_string() + "+" +
                              string2.get_string() + ")";

    Str new_str(new_string);

    return new_str;
}

/*! Returns a new String that is equal to 'string1-string2'. */

Str operator-(const Str& string1,const Str& string2)
{
  std::string new_string = "(" + string1.get_string() + "-" +
                            string2.get_string() + ")";

  Str new_str(new_string);

  return new_str;
}

/*! Returns a new String that is equal to 'string1*string2'. */
Str operator*(const Str& string1,const Str& string2)
{
    std::string new_string = "(" + string1.get_string() + "*" +
                              string2.get_string() + ")";

    Str new_str(new_string);

    return new_str;
}
#endif
