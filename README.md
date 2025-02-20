# Bitmap-Btree-Memalloc
A fast and atomic Bitmap Btree for memory alloctors operating on 64 bit integers

This was made for a memory allocator scheme for my custom OS. It is named arraylist_btree in the source as it is using an arraylist (the naming is not great its more of a bitmap), with an ordering of a btree for faster
accesses.

This data structure is mainly used for keeping track of memory spaces by using 64-bit integers as a bitmap. The binary tree structure comes from higher parent nodes being marked as used when children are
allocated in the structure. As well as child nodes being unavailable when higher order parent nodes are used.
The 64-bit integers make it possible for atomic allocations of the structure. This data structure doesent scale too well since active caching of free children must be done,
or recursive uses of this tree to keep track of other trees and their available nodes must be used.

I am posting this code for my own future reference along with some of the libraries I made, as well as an example of a pool allocator that allocates memory segments from a buffer using the Bitmap-btree allocator.

I didn't include a makefile, but feel free to take anything here that makes sense and use as you see fit. 
