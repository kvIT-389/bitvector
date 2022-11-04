#include <iostream>
#include <stdexcept>
#include <vector>

#include "bitvector.hpp"


BitVector::BitVector(std::size_t size)
 : m_size(size),
   m_bytes((size + 0x07) >> 3)
{
}


std::size_t BitVector::size() const
{
    return m_size;
}

bool BitVector::at(std::size_t index) const
{
    if (index > size()) {
        throw std::range_error("Given index is out of range");
    }

    return (m_bytes[index >> 3] >> (index & 0x07)) & 1;
}

void BitVector::at(std::size_t index, bool value)
{
    if (index > size()) {
        throw std::range_error("Given index is out of range");
    }

    m_bytes[index >> 3] ^= (at(index) ^ (value)) << (index & 0x07);
}


std::ostream &operator<<(
    std::ostream &os, const BitVector &vector
)
{
    for (BitVector::Byte_t byte : vector.m_bytes) {
        for (std::uint8_t i = 0; i < 8; ++i) {
            os << (byte & 1);
            byte >>= 1;
        }
        os << ' ';
    }

    return os << '\b';
}
