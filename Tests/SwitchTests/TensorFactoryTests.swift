import XCTest
@testable import Switch


final class TensorFactoryTests: XCTestCase {
    func testOnes2D() {
        let tensor = ones(3, 4)
        XCTAssertEqual(tensor.dim(), 2)
        XCTAssertEqual(tensor.sizes(), [3, 4])
    }

    func testOnes3D() {
        let tensor = ones(3, 4, 5)
        XCTAssertEqual(tensor.dim(), 3)
        XCTAssertEqual(tensor.sizes(), [3, 4, 5])
    }

    func testZeros2D() {
        let tensor = zeros(3, 4)
        XCTAssertEqual(tensor.dim(), 2)
        XCTAssertEqual(tensor.sizes(), [3, 4])
    }

    func testZeros3D() {
        let tensor = zeros(3, 4, 5)
        XCTAssertEqual(tensor.dim(), 3)
        XCTAssertEqual(tensor.sizes(), [3, 4, 5])
    }

    func testRandn2D() {
        let tensor = randn(3, 4)
        XCTAssertEqual(tensor.dim(), 2)
        XCTAssertEqual(tensor.sizes(), [3, 4])
    }

    func testRandn3D() {
        let tensor = randn(3, 4, 5)
        XCTAssertEqual(tensor.dim(), 3)
        XCTAssertEqual(tensor.sizes(), [3, 4, 5])
    }

    func testRandInt2D() {
        let tensor = randint(0, 1, 3, 4)
        XCTAssertEqual(tensor.dim(), 2)
        XCTAssertEqual(tensor.sizes(), [3, 4])
    }

    func testRandInt3D() {
        let tensor = randint(0, 1, 3, 4, 5)
        XCTAssertEqual(tensor.dim(), 3)
        XCTAssertEqual(tensor.sizes(), [3, 4, 5])
    }

    func testTensorAdd() {
        let t1 = ones(2, 2)
        let t2 = ones(2, 2)
        let t3 = t1 + t2
        XCTAssertEqual(t3.dim(), 2)
        XCTAssertEqual(t3.sizes(), [2, 2])

        let val:Float = t3.slice(0, 0, 1).slice(1, 0, 1).item().to()
        XCTAssertEqual(val, 2)
    }

    static var allTests = [
        ("testOnes2D", testOnes2D),
        ("testOnes3D", testOnes3D),
        ("testZeros2D", testZeros2D),
        ("testZeros3D", testZeros3D),
        ("testRandn2D", testRandn2D),
        ("testRandn3D", testRandn3D),
        ("testRandnInt2D", testRandInt2D),
        ("testRandnInt3D", testRandInt3D),
        ("testTensorAdd", testTensorAdd),
    ]
}
