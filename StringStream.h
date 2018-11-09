#ifndef INCLUDE_STRINGSTREAM_H
#define INCLUDE_STRINGSTREAM_H

#include <Arduino.h>
#include <Stream.h>

class StringStream : public Stream {
public:
    size_t write(uint8_t c) { buff += static_cast<char>(c); return 1; }
    int available() { return 0; }
    int read() { return EOF; }
    int peek() { return EOF; }
    void flush() {}
    StringStream& operator=(const String& other) { buff = other; return *this; }
    String str() { return buff; }

private:
    String buff;
};

#endif
