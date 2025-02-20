#include  <stddef.h>
#include  <stdint.h>

extern int atomic_cmpxchg_64(uint64_t *ptr, uint64_t old_val, uint64_t new_val);

int atomic_cmpxchg_try_64(uint64_t * ptr, uint64_t old_val, uint64_t new_val, uint32_t tries)
{
	int ret;

	while (tries) {
		ret = atomic_cmpxchg_64(ptr, old_val, new_val);
		if (!ret)
			return ret;
		
		tries--;
	}

	return ret;
}

// For these atomic ops we can do how linux does it
// and dynamically pass instructions we want to be atomic
// since the pattern is the same for these simple ops

extern int atomic_fetch_add_64(uint64_t *ptr, uint64_t val);

extern int atomic_fetch_sub_64(uint64_t *ptr, uint64_t val);

extern int _atomic_fetch_or_64(uint64_t *ptr, uint64_t val);

extern uint32_t atomic_ld_32(uint32_t * ptr);

extern uint64_t atomic_ld_64(uint64_t * ptr);

extern int atomic_str_32(uint32_t * ptr, uint32_t val);

extern int atomic_str_64(uint64_t * ptr, uint64_t val);
