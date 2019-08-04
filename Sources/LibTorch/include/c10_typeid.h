#ifndef __SWITCH_CAFFE2_TYPEMETA_H
#define __SWITCH_CAFFE2_TYPEMETA_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

  void deleteDtype(Dtype*);
  const char* dtypeName(Dtype*);
  int dtypeEqual(Dtype*, Dtype*);

#ifdef __cplusplus
}
#endif

#endif
