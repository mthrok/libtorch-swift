#ifndef __SWITCH_TENSOR_FACTORY_H
#define __SWITCH_TENSOR_FACTORY_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  Tensor* ones(long* sizes, uint64_t length, TensorOptions* opt);
  Tensor* zeros(long* sizes, uint64_t length, TensorOptions* opt);
  Tensor* randn(long* sizes, uint64_t length, TensorOptions* opt);
  Tensor* randint(int64_t low, int64_t high, long*sizes, uint64_t length, TensorOptions* opt);

#ifdef __cplusplus
}
#endif

#endif
