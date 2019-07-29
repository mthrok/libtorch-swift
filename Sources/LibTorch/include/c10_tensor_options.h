#ifndef __SWITCH_C10_TENSOR_OPTIONS_H
#define __SWITCH_C10_TENSOR_OPTIONS_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  TensorOptions* newTensorOptions();
  void deleteTensorOptions(TensorOptions*);

#ifdef __cplusplus
}
#endif

#endif
