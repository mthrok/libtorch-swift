import LibTorch


class TensorOptions {
    var _p: OpaquePointer

    init () {
        self._p = LibTorch.newTensorOptions()
    }

    init (_ pointer:OpaquePointer) {
        self._p = pointer
    }

    deinit {
        LibTorch.deleteTensorOptions(self._p)
    }

    func dtype() -> Dtype {
        return Dtype(LibTorch.tensorOptionsDtype(self._p));
    }
}

func TensorOptionsFromDtypeInt32() -> TensorOptions {
    return TensorOptions(LibTorch.newTensorOptionsFromDtypeInt32());
}

func TensorOptionsFromDtypeInt64() -> TensorOptions {
    return TensorOptions(LibTorch.newTensorOptionsFromDtypeInt64());
}

func TensorOptionsFromDtypeFloat() -> TensorOptions {
    return TensorOptions(LibTorch.newTensorOptionsFromDtypeFloat());
}

func TensorOptionsFromDtypeDouble() -> TensorOptions {
    return TensorOptions(LibTorch.newTensorOptionsFromDtypeDouble());
}


func TensorOptionsFromDtype(_ dtype: String) -> TensorOptions {
    switch dtype.lowercased() {
    case "int32", "int": return TensorOptionsFromDtypeInt32();
    case "int64", "long": return TensorOptionsFromDtypeInt64();
    case "float": return TensorOptionsFromDtypeFloat();
    case "double": return TensorOptionsFromDtypeDouble();
    default: return TensorOptions();
    }
}
