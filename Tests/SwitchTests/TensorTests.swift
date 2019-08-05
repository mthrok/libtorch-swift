import XCTest
@testable import Switch

final class TensorClassTests: XCTestCase {
    func TensorEqVals() {
        let t1 = ones(1)
        let t2 = zeros(1)
        var val:Int32

        val = (t1 == t2).item().to()
        XCTAssertEqual(val, 0)
        val = (t2 == t1).item().to()
        XCTAssertEqual(val, 0)
        val = (t1 == t1).item().to()
        XCTAssertEqual(val, 1)
        val = (t2 == t2).item().to()
        XCTAssertEqual(val, 1)
    }

    func TensorIsSame() {
        let t1 = zeros(3, 4)
        let t2 = zeros(3, 4)

        XCTAssertTrue(t1.isSame(t1))
        XCTAssertTrue(t2.isSame(t2))

        XCTAssertFalse(t1.isSame(t2))
        XCTAssertFalse(t2.isSame(t1))
    }

    func TensorIsSparse() {
        let t = zeros(3, 4)
        XCTAssertFalse(t.isSparse())
    }

    static var allTests = [
      ("TensorEqVals", TensorEqVals),
      ("TensorIsSame", TensorIsSame),
      ("TensorIsSparse", TensorIsSparse),
    ]
}


final class TensorClassSliceTests: XCTestCase {
    func TensorSlice() {
        let tensor345 = zeros(3, 4, 5);
        let tensor343 = tensor345.slice(2, 0, 3, 1);
        let tensor333 = tensor343.slice(1, 0, 3, 1);

        XCTAssertEqual(tensor345.dim(), 3)
        XCTAssertEqual(tensor345.sizes(), [3, 4, 5])

        XCTAssertEqual(tensor343.dim(), 3)
        XCTAssertEqual(tensor343.sizes(), [3, 4, 3])

        XCTAssertEqual(tensor333.dim(), 3)
        XCTAssertEqual(tensor333.sizes(), [3, 3, 3])
    }

    func TensorIndex() {
        let t = zeros(3, 4, 5)
        let t2 = t.index(2)
        let t1 = t2.index(1)
        let t0 = t1.index(0)

        XCTAssertEqual(t2.dim(), 2)
        XCTAssertEqual(t2.sizes(), [4, 5])

        XCTAssertEqual(t1.dim(), 1)
        XCTAssertEqual(t1.sizes(), [5])

        XCTAssertEqual(t0.dim(), 0)
        XCTAssertEqual(t0.sizes(), [])
    }

    func TensorOperatorSubscript() {
        let t = zeros(3, 4, 5)
        let t2 = t[2]
        let t1 = t2[1]
        let t0 = t1[0]

        XCTAssertEqual(t2.dim(), 2)
        XCTAssertEqual(t2.sizes(), [4, 5])

        XCTAssertEqual(t1.dim(), 1)
        XCTAssertEqual(t1.sizes(), [5])

        XCTAssertEqual(t0.dim(), 0)
        XCTAssertEqual(t0.sizes(), [])
    }

    static var allTests = [
      ("TensorSlice", TensorSlice),
      ("TensorIndex", TensorIndex),
      ("TensorOperatorSubscript", TensorOperatorSubscript)
    ]
}
