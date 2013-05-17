
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_FOUNDATION_CORE_STRINGEXCEPTION_H
#define APPLESEED_FOUNDATION_CORE_STRINGEXCEPTION_H

// appleseed.foundation headers.
#include "foundation/core/exceptions/exception.h"

namespace foundation
{

//
// Like foundation::Exception but optionally carrying an additional string.
//

class StringException
  : public Exception
{
  public:
    // Constructors.
    StringException();
    explicit StringException(const char* what);
    StringException(const char* what, const char* s);

    // Return the additional string stored in the exception.
    const char* string() const;

  protected:
    void set_string(const char* s);

  private:
    char m_string[4096];
};


//
// String class implementation.
//

inline StringException::StringException()
{
    set_string("n/a");
}

inline StringException::StringException(const char* what)
  : Exception(what)
{
    set_string("n/a");
}

inline StringException::StringException(const char* what, const char* s)
  : Exception(what)
{
    set_string(s);
}

inline const char* StringException::string() const
{
    return m_string;
}

inline void StringException::set_string(const char* s)
{
    copy_string(m_string, s, sizeof(m_string));
}

}       // namespace foundation

#endif  // !APPLESEED_FOUNDATION_CORE_STRINGEXCEPTION_H
