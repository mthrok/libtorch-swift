#ifndef __SWITCH_C10_TENSOR_OPTIONS_H
#define __SWITCH_C10_TENSOR_OPTIONS_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  TensorOptions* newTensorOptions();
  void deleteTensorOptions(TensorOptions*);

  TensorOptions* newTensorOptionsFromDtypeInt32();
  TensorOptions* newTensorOptionsFromDtypeInt64();
  TensorOptions* newTensorOptionsFromDtypeFloat();
  TensorOptions* newTensorOptionsFromDtypeDouble();

#ifdef __cplusplus
}
#endif

#endif
