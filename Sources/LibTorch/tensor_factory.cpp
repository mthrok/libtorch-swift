#include <torch/torch.h>
#include "tensor_factory.h"

using std::swap;

Tensor* arange(long start, long end, long step, TensorOptions* opt) {
  auto c10opt = (c10::TensorOptions*) opt;
  auto t = torch::arange(start, end, step, *c10opt);
  torch::Tensor* p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

Tensor* zeros(long* sizes, uint64_t length, TensorOptions* opt) {
  auto c10opt = (c10::TensorOptions*) opt;
  auto t = torch::zeros(c10::IntArrayRef(sizes, length), *c10opt);
  torch::Tensor* p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

Tensor* ones(long* sizes, uint64_t length, TensorOptions* opt) {
  auto c10opt = (c10::TensorOptions*) opt;
  auto t = torch::ones(c10::IntArrayRef(sizes, length), *c10opt);
  torch::Tensor* p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

Tensor* randn(long* sizes, uint64_t length, TensorOptions* opt) {
  auto c10opt = (c10::TensorOptions*) opt;
  auto t = torch::randn(c10::IntArrayRef(sizes, length), *c10opt);
  torch::Tensor *p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

Tensor* randint(int64_t low, int64_t high, long* sizes, uint64_t length, TensorOptions* opt) {
  auto c10opt = (c10::TensorOptions*) opt;
  auto t = torch::randint(low, high, c10::IntArrayRef(sizes, length), *c10opt);
  torch::Tensor *p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}
