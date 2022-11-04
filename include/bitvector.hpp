#ifndef BITVECTOR_HPP_INCLUDED_
#define BITVECTOR_HPP_INCLUDED_ 1


#include <iostream>
#include <vector>


class BitVector
{
  public:
    using Byte_t = std::uint8_t;

    BitVector() = default;
    BitVector(const BitVector &other) = default;
    BitVector(BitVector &&other) = default;

    BitVector(std::size_t size);

    BitVector &operator=(const BitVector &other) = default;
    BitVector &operator=(BitVector &&other) = default;

    ~BitVector() = default;

    std::size_t size() const;

    bool at(std::size_t index) const;
    void at(std::size_t index, bool value);

    friend std::ostream &operator<<(
      std::ostream &os, const BitVector &vector
    );

  private:
    std::size_t m_size;
    std::vector<Byte_t> m_bytes;
};


#endif  // BITVECTOR_HPP_INCLUDED_ //
