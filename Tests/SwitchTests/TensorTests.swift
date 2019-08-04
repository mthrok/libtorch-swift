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
