#ifndef __WRAPPER_H
#define __WRAPPER_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  Tensor* newTensor();
  void printTensor(Tensor*);
  void deleteTensor(Tensor*);

#ifdef __cplusplus
}
#endif
#endif
