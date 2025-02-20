#ifndef __ATOMIC_H
#define __ATOMIC_H

#include <stdint.h>
#include <stddef.h>

#define ATOMIC_UINT64(X) __attribute__((aligned(8))) static uint64_t (X) = 0
#define ATOMIC_UINT32(X) __attribute__((aligned(4))) static uint32_t (X) = 0

typedef uint32_t atomic32_t;
typedef uint64_t atomic64_t;

int atomic_cmpxchg(uint64_t *ptr, uint64_t old_val, uint64_t new_val);
/* Try the cmpxchg a number of times. */
int atomic_cmpxchg_try(uint64_t * ptr, uint64_t old_val, uint64_t new_val, uint32_t tries);
int atomic_add(uint64_t *addr, uint64_t val);
int atomic_sub(uint64_t *addr, uint64_t val);
int atomic_or(uint64_t *addr, uint64_t val);

#endif