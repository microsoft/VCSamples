fnv1a.hpp

The internal hash function `std::_Hash_seq(const unsigned char *)`, used to implement `std::hash` on some string types, was visible in recent versions of the Standard Library is not anymore visible (VC2017 15.3)
  
To remove this dependency, add the header (fnv1a.hpp) to any affected code, and then find and replace `_Hash_seq` by `fnv1a_hash_bytes`. You'll get identical behavior to the internal implementation in `_Hash_seq`. 

This code can run also on previous version of VC.