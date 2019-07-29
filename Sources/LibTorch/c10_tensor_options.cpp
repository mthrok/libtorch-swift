#include <torch/torch.h>
#include "c10_tensor_options.h"


TensorOptions* newTensorOptions() {
  auto *p = new c10::TensorOptions();
  return (TensorOptions*) p;
}

void deleteTensorOptions(TensorOptions* opt) {
  auto* p = (c10::TensorOptions*) opt;
  delete p;
}
