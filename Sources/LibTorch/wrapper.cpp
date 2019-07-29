#include <iostream>

#include <torch/torch.h>
#include "wrapper.h"


extern "C" {
  Tensor* newTensor() {
    torch::Tensor *tensor = new torch::Tensor();
    return (Tensor*) tensor;
  }

  void printTensor(Tensor* t) {
    torch::Tensor *tensor = (torch::Tensor*) t;
    std::cout << *tensor << std::endl;
  }

  void deleteTensor(Tensor* t) {
    torch::Tensor *tensor = (torch::Tensor*) t;
    delete tensor;
  }
}
