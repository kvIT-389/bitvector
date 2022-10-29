#ifndef BITVECTOR_HPP_INCLUDED_
#define BITVECTOR_HPP_INCLUDED_ 1


#include <vector>


class BitVector
{
  public:
    using Byte_t = std::uint8_t;

    BitVector() = default;
    BitVector(const BitVector &) = default;
    BitVector(BitVector &&) = default;

    BitVector(std::size_t size);

    BitVector &operator=(const BitVector &) = default;
    BitVector &operator=(BitVector &&) = default;

    ~BitVector() = default;

    std::size_t size() const;

    bool at(std::size_t index) const;
    void at(std::size_t index, bool value);

  private:
    std::size_t m_size;
    std::vector<Byte_t> m_bytes;
};


#endif  // BITVECTOR_HPP_INCLUDED_ //
