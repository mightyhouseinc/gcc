/* { dg-do run { target { riscv_vector } } } */
/* { dg-additional-options "--param=riscv-autovec-preference=scalable" } */

#include "ternop-4.c"

#define TEST_LOOP(TYPE, NUM)                                                   \
  {                                                                            \
    TYPE array1_##NUM[NUM] = {};                                               \
    TYPE array2_##NUM[NUM] = {};                                               \
    TYPE array3_##NUM[NUM] = {};                                               \
    TYPE array4_##NUM[NUM] = {};                                               \
    for (int i = 0; i < NUM; ++i)                                              \
      {                                                                        \
 array1_##NUM[i] = (i & 1) + 5;                                         \
 array2_##NUM[i] = i - NUM / 3;                                         \
 array3_##NUM[i] = NUM - NUM / 3 - i;                                   \
 array4_##NUM[i] = NUM - NUM / 3 - i;                                   \
 asm volatile("" ::: "memory");                                         \
      }                                                                        \
    ternop_##TYPE (array3_##NUM, array1_##NUM, array2_##NUM, NUM);             \
    for (int i = 0; i < NUM; i++)                                              \
      if (array3_##NUM[i]                                                      \
   != (TYPE) (-(array1_##NUM[i] * array2_##NUM[i]) + array4_##NUM[i]))  \
 __builtin_abort ();                                                    \
  }

int __attribute__ ((optimize (0))) main ()
{
  TEST_LOOP (int8_t, 7)
  TEST_LOOP (uint8_t, 7)
  TEST_LOOP (int16_t, 7)
  TEST_LOOP (uint16_t, 7)
  TEST_LOOP (int32_t, 7)
  TEST_LOOP (uint32_t, 7)
  TEST_LOOP (int64_t, 7)
  TEST_LOOP (uint64_t, 7)

  TEST_LOOP (int8_t, 16)
  TEST_LOOP (uint8_t, 16)
  TEST_LOOP (int16_t, 16)
  TEST_LOOP (uint16_t, 16)
  TEST_LOOP (int32_t, 16)
  TEST_LOOP (uint32_t, 16)
  TEST_LOOP (int64_t, 16)
  TEST_LOOP (uint64_t, 16)

  TEST_LOOP (int8_t, 77)
  TEST_LOOP (uint8_t, 77)
  TEST_LOOP (int16_t, 77)
  TEST_LOOP (uint16_t, 77)
  TEST_LOOP (int32_t, 77)
  TEST_LOOP (uint32_t, 77)
  TEST_LOOP (int64_t, 77)
  TEST_LOOP (uint64_t, 77)
  
  TEST_LOOP (int8_t, 128)
  TEST_LOOP (uint8_t, 128)
  TEST_LOOP (int16_t, 128)
  TEST_LOOP (uint16_t, 128)
  TEST_LOOP (int32_t, 128)
  TEST_LOOP (uint32_t, 128)
  TEST_LOOP (int64_t, 128)
  TEST_LOOP (uint64_t, 128)

  TEST_LOOP (int8_t, 15641)
  TEST_LOOP (uint8_t, 15641)
  TEST_LOOP (int16_t, 15641)
  TEST_LOOP (uint16_t, 15641)
  TEST_LOOP (int32_t, 15641)
  TEST_LOOP (uint32_t, 15641)
  TEST_LOOP (int64_t, 15641)
  TEST_LOOP (uint64_t, 15641)
  
  TEST_LOOP (int8_t, 795)
  TEST_LOOP (uint8_t, 795)
  TEST_LOOP (int16_t, 795)
  TEST_LOOP (uint16_t, 795)
  TEST_LOOP (int32_t, 795)
  TEST_LOOP (uint32_t, 795)
  TEST_LOOP (int64_t, 795)
  TEST_LOOP (uint64_t, 795)

  return 0;
}
