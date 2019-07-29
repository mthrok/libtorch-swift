import LibTorch


class TensorOptions {
    var _p: OpaquePointer

    init () {
        self._p = LibTorch.newTensorOptions()
    }

    deinit {
        LibTorch.deleteTensorOptions(self._p)
    }
}
