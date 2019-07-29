#ifndef __SWITCH_TENSOR_FACTORY_H
#define __SWITCH_TENSOR_FACTORY_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  Tensor* ones(long* sizes, uint64_t length);
  Tensor* zeros(long* sizes, uint64_t length);
  Tensor* randn(long* sizes, uint64_t length);
  Tensor* randint(int64_t low, int64_t high, long*sizes, uint64_t length);

#ifdef __cplusplus
}
#endif

#endif
