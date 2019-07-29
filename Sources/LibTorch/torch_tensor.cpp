#include <torch/torch.h>

#include "torch_tensor.h"

extern "C" {
int64_t tensorDim(Tensor* t) {
  torch::Tensor *tensor = (torch::Tensor*) t;
  return tensor->dim();
}

void tensorSizes(Tensor* tensor, uint64_t* values) {
  auto s = ((torch::Tensor*)tensor)->sizes();
  for (uint64_t i = 0; i < s.size(); i++) {
    values[i] = s[i];
  }
}

int tensorIsCuda(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_cuda();
}

int tensorIsHip(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_hip();
}

int tensorIsSparse(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_sparse();
}

int tensorIsMkldnn(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_mkldnn();
}

int tensorIsQuantized(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_quantized();
}

Scalar* tensorItem(Tensor* tensor) {
  auto val = ((torch::Tensor*) tensor)->item();
  c10::Scalar *p = new c10::Scalar();
  std::swap(val, *p);
  return (Scalar*) p;
}

Tensor* tensorIndex(Tensor* tensor, int64_t index) {
  auto t = (*((torch::Tensor*) tensor))[index];
  torch::Tensor *p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

Tensor* tensorSlice(Tensor* tensor, int64_t dim, int64_t start, int64_t end, int64_t step)  {
  auto t = ((torch::Tensor*) tensor)->slice(dim, start, end, step);
  torch::Tensor *p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

int tensorIsSame(Tensor* tensor1, Tensor* tensor2) {
  torch::Tensor *p1 = (torch::Tensor*) tensor1;
  torch::Tensor *p2 = (torch::Tensor*) tensor2;
  return (int)p1->is_same(*p2);
}

Tensor* tensorAdd(Tensor* tensor1, Tensor* tensor2) {
  torch::Tensor *p1 = (torch::Tensor*) tensor1;
  torch::Tensor *p2 = (torch::Tensor*) tensor2;

  auto t = (*p1) + (*p2);
  torch::Tensor *p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

Tensor* tensorEqual(Tensor* tensor1, Tensor* tensor2) {
  torch::Tensor *p1 = (torch::Tensor*) tensor1;
  torch::Tensor *p2 = (torch::Tensor*) tensor2;

  auto t = p1->eq(*p2);
  torch::Tensor *p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

}
