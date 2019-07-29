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
  TensorAccessor* tensorAccessorDouble1(Tensor*);
  TensorAccessor* tensorAccessorDouble2(Tensor*);
  TensorAccessor* tensorAccessorDouble3(Tensor*);
  TensorAccessor* tensorAccessorFloat1(Tensor*);
  TensorAccessor* tensorAccessorFloat2(Tensor*);
  TensorAccessor* tensorAccessorFloat3(Tensor*);
  Scalar* tensorItem(Tensor*);
  Tensor* tensorIndex(Tensor*, int64_t);
  Tensor* tensorSlice(Tensor* tensor, int64_t dim, int64_t start, int64_t end, int64_t step);
  int tensorIsSame(Tensor*, Tensor*);

  // Operator overloads
  Tensor* tensorAdd(Tensor*, Tensor*);
  Tensor* tensorEqual(Tensor*, Tensor*);

#ifdef __cplusplus
}
#endif

#endif
