import LibTorch


class Scalar {
    var _pointer:OpaquePointer? = nil
    init (_ pointer:OpaquePointer) {
        self._pointer = pointer
    }

    func isFloatingPoint() -> Bool {
        return LibTorch.scalarIsFloatingPoint(self._pointer) == 1
    }

    func isIntegral() -> Bool {
        return LibTorch.scalarIsIntegral(self._pointer) == 1
    }

    func isComplex() -> Bool {
        return LibTorch.scalarIsComplex(self._pointer) == 1
    }

    func to() -> Int32 {
        return LibTorch.scalarToInt32(self._pointer)
    }

    func to() -> Int64 {
        return LibTorch.scalarToInt64(self._pointer)
    }

    func to() -> Float {
        return LibTorch.scalarToFloat(self._pointer)
    }

    func to() -> Double {
        return LibTorch.scalarToDouble(self._pointer)
    }
}
