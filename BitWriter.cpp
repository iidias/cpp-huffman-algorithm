#include "BitWriter.h"

using namespace std;

BitWriter::BitWriter(ostream& arquivoSaida) : out(arquivoSaida) {
    buffer = 0;
    nBits = 0;
}

void BitWriter::writeBit(int bit) {
    buffer = buffer << 1;
    if (bit) buffer |= 1;
    nBits++;

    if (nBits == 8) {
        out.put(buffer);
        buffer = 0;
        nBits = 0;
    }
}

void BitWriter::writeSequence(string bits) {
    for (char b : bits) {
        writeBit(b - '0');
    }
}

void BitWriter::flush() {
    if (nBits > 0) {
        buffer = buffer << (8 - nBits);
        out.put(buffer);
    }
}
