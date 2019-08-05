#ifndef __SWITCH_TORCH_TENSOR_H
#define __SWITCH_TORCH_TENSOR_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  // Attributes
  int64_t tensorDim(Tensor*);
  void tensorSizes(Tensor*, uint64_t* values);
  TensorOptions* tensorOptions(Tensor*);
  Dtype* tensorDtype(Tensor*);

  int tensorIsCuda(Tensor*);
  int tensorIsHip(Tensor*);
  int tensorIsSparse(Tensor*);
  int tensorIsMkldnn(Tensor*);
  int tensorIsQuantized(Tensor*);

  // Accessors
  Scalar* tensorItem(Tensor*);
  Tensor* tensorIndex(Tensor*, int64_t);
  Tensor* tensorSlice(Tensor* tensor, int64_t dim, int64_t start, int64_t end, int64_t step);
  Tensor* tensorOperatorSubscript(Tensor* tensor, int64_t index);
  int tensorIsSame(Tensor*, Tensor*);

  // Operator overloads
  Tensor* tensorAdd(Tensor*, Tensor*);
  Tensor* tensorEqual(Tensor*, Tensor*);

#ifdef __cplusplus
}
#endif

#endif
