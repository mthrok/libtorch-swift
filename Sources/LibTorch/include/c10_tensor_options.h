#ifndef __SWITCH_C10_TENSOR_OPTIONS_H
#define __SWITCH_C10_TENSOR_OPTIONS_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  // Create/Delete new TensorOption object
  TensorOptions* newTensorOptions();
  void deleteTensorOptions(TensorOptions*);

  //Accessor method
  Dtype* tensorOptionsDtype(TensorOptions*);

  // Factory functions
  TensorOptions* newTensorOptionsFromDtypeInt32();
  TensorOptions* newTensorOptionsFromDtypeInt64();
  TensorOptions* newTensorOptionsFromDtypeFloat();
  TensorOptions* newTensorOptionsFromDtypeDouble();

#ifdef __cplusplus
}
#endif

#endif
