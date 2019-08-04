import XCTest
@testable import Switch


final class DtypeTests: XCTestCase {
    static let intPatterns = [
      ("int", "int"),
      ("long", "long"),
      ("int32", "int"),
      ("int64", "long"),
    ]

    static let floatPatterns = [
      ("float", "float"),
      ("double", "double"),
    ]

    static let patterns = intPatterns + floatPatterns;

    func testOnes() {
        for (dtype, expected) in DtypeTests.patterns {
            let name = ones(3, 4, dtype:dtype).dtype().name()
            XCTAssertEqual(name, expected)
        }
    }

    func testZeros() {
        for (dtype, expected) in DtypeTests.patterns {
            let name = zeros(3, 4, dtype:dtype).dtype().name()
            XCTAssertEqual(name, expected)
        }
    }

    func testRandn() {
        for (dtype, expected) in DtypeTests.floatPatterns {
            let name = randn(3, 4, dtype:dtype).dtype().name()
            XCTAssertEqual(name, expected)
        }
    }

    func testRandint() {
        for (dtype, expected) in DtypeTests.patterns {
            let name = randint(0, 1, 3, 4, dtype:dtype).dtype().name()
            XCTAssertEqual(name, expected)
        }
    }

    func testEquality() {
        let int0 = zeros(3, 4, dtype:"int").dtype()
        let int1 = ones(3, 4, dtype:"int").dtype()
        let float0 = zeros(3, 4, dtype:"float").dtype()
        let float1 = ones(3, 4, dtype:"float").dtype()

        XCTAssertEqual(int0, int1)
        XCTAssertEqual(float0, float1)
        XCTAssertNotEqual(int0, float0)
        XCTAssertNotEqual(int1, float1)
    }

    static var allTests = [
      ("testOnes", testOnes),
      ("testZeros", testZeros),
      ("testRandn", testRandn),
      ("testRandint", testRandint),
      ("testEquality", testEquality),
    ]
}
