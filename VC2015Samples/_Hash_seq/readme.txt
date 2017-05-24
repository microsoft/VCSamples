fnv1a.hpp

The internal hash function `std::_Hash_seq(const unsigned char *)`, used to implement `std::hash` on some string types, was visible in recent versions of the Standard Library. This function implemented an [FNV-1a hash]( https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) on a character sequence.  
  
To remove this dependency, you have a couple of options.  

Add the header (fnv1a.hpp) to any affected code, and then find and replace `_Hash_seq` by `fnv1a_hash_bytes`. You'll get identical behavior to the internal implementation in `_Hash_seq`. 
