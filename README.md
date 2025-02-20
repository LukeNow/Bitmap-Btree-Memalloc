# Bitmap-Btree-Memalloc
A fast and atomic Bitmap Btree for memory alloctors operating on 64 bit integers

This was made for a memory allocator scheme for my custom OS. It is named arraylist_btree in the source as it is using an arraylist (the naming is not great its more of a bitmap), with an ordering of a btree for faster
accesses.

This data structure is mainly used for keeping track of memory spaces by using 64-bit integers as a bitmap. The binary tree structure comes from higher parent nodes being marked as used when children are
allocated in the structure. As well as child nodes being unavailable when higher order parent nodes are used.
The 64-bit integers make it possible for atomic allocations using the structure, and without the need for locking. When there is contention or data is stale, the operations are retried, but this should be okay since the
operations themselves are fast.
This data structure doesent scale too well since active caching of free children must be done, and many many trees must be used to do anything useful as it only contains 63 entries.
As well as recursive uses of this tree can be used to keep track of other trees and their available nodes.

I am posting this code for my own future reference along with some of the libraries I made, as well as an example of a pool allocator that allocates memory segments from a buffer using the Bitmap-btree allocator.

This data structure isn't particularly useful as there are other mechanisms for managing memory and bitmaps that are more useful and straightforward. This was a fun idea I had while making my custom OS and in designing
a memory allocator. Feel free to use whatever makes sense. 
