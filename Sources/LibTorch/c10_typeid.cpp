#include "c10_typeid.h"
#include <c10/util/typeid.h>


void deleteDtype(Dtype* dtype) {
  auto *p = (caffe2::TypeMeta*)dtype;
  delete p;
}

const char* dtypeName(Dtype* dtype) {
  auto *p = (caffe2::TypeMeta*)dtype;
  return p->name();
}

int dtypeEqual(Dtype* dtype1, Dtype* dtype2) {
  auto p1 = *((caffe2::TypeMeta*)dtype1);
  auto p2 = *((caffe2::TypeMeta*)dtype2);
  return (int)(p1 == p2);
}
