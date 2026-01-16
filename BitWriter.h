#ifndef BITWRITER_H
#define BITWRITER_H

#include <iostream>

class BitWriter {
private:
    unsigned char buffer;
    int nBits;
    std::ostream& out;

public:
    BitWriter(std::ostream& arquivoSaida);

    void writeBit(int bit);

    void writeSequence(std::string bits);

    void flush();
};

#endif
