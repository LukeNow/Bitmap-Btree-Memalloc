# Bitmap-Btree-Memalloc
A fast and atomic Bitmap Btree for memory alloctors operating on 64 bit integers

This was made for a memory allocator scheme for my custom OS. 

This data structure is mainly used for keeping track of memory spaces in 64-bit integers. The binary tree structure comes from higher parent nodes being marked as used when children are
allocated in the structure. The 64-bit integers make it possible for atomic allocations of the structure. This data structure doesent scale too well since active caching of free children must be done,
or recursive uses of this tree to keep track of other trees and their available nodes must be used.

I am posting this code for my own future reference along with some of the libraries I made to go along with it.
