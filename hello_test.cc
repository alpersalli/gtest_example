// FILE: my_project/test_math_operations.c
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "math_operations.h"
#include <sys/socket.h>
// Mock class for testing socket-related functions
class MockSocketOperations {
public:
    MOCK_METHOD3(socket, int(int domain, int type, int protocol));  // Mock for socket creation
    MOCK_METHOD1(close, int(int fd));  // Mock for socket closing
};

// Global mock object
MockSocketOperations* mockSocketOps;

extern "C" {
    int socket(int domain, int type, int protocol) {
        return mockSocketOps->socket(domain, type, protocol);
    }

    int close(int fd) {
        return mockSocketOps->close(fd);
    }
}

// Test fixture to allow mocking the socket operations
class MultiplyTest : public ::testing::Test {
protected:
    void SetUp() override {
        mockSocketOps = new MockSocketOperations();
    }

    void TearDown() override {
        delete mockSocketOps;
    }
};

// Test for successful multiplication
TEST_F(MultiplyTest, Multiply_Success) {
    // Arrange: Mock the socket functions
    EXPECT_CALL(*mockSocketOps, socket(AF_INET, SOCK_STREAM, 0)).WillOnce(testing::Return(1));  // Success in creating socket
    EXPECT_CALL(*mockSocketOps, close(testing::_)).WillOnce(testing::Return(0));  // Success in closing socket

    // Act: Call multiply
    int result = multiply(7, 6);

    // Assert: Check multiplication result
    EXPECT_EQ(result, 42);  // 7 * 6 = 42
}

// Test for multiplying by zero
TEST_F(MultiplyTest, Multiply_ByZero) {
    // Arrange: Mock the socket functions
    EXPECT_CALL(*mockSocketOps, socket(AF_INET, SOCK_STREAM, 0)).WillOnce(testing::Return(1));  // Success in creating socket
    EXPECT_CALL(*mockSocketOps, close(testing::_)).WillOnce(testing::Return(0));  // Success in closing socket

    // Act: Call multiply
    int result = multiply(0, 5);

    // Assert: Check multiplication result
    EXPECT_EQ(result, 0);  // 0 * 5 = 0
}

// Test for multiplying negative numbers
TEST_F(MultiplyTest, Multiply_NegativeNumbers) {
    // Arrange: Mock the socket functions
    EXPECT_CALL(*mockSocketOps, socket(AF_INET, SOCK_STREAM, 0)).WillOnce(testing::Return(1));  // Success in creating socket
    EXPECT_CALL(*mockSocketOps, close(testing::_)).WillOnce(testing::Return(0));  // Success in closing socket

    // Act: Call multiply
    int result = multiply(-3, -4);

    // Assert: Check multiplication result
    EXPECT_EQ(result, 12);  // -3 * -4 = 12
}

// Test for multiplying positive and negative number
TEST_F(MultiplyTest, Multiply_PositiveAndNegative) {
    // Arrange: Mock the socket functions
    EXPECT_CALL(*mockSocketOps, socket(AF_INET, SOCK_STREAM, 0)).WillOnce(testing::Return(1));  // Success in creating socket
    EXPECT_CALL(*mockSocketOps, close(testing::_)).WillOnce(testing::Return(0));  // Success in closing socket

    // Act: Call multiply
    int result = multiply(-3, 4);

    // Assert: Check multiplication result
    EXPECT_EQ(result, -12);  // -3 * 4 = -12
}

// Test for socket creation failure
TEST_F(MultiplyTest, Multiply_SocketFailure) {
    // Arrange: Mock socket creation failure
    EXPECT_CALL(*mockSocketOps, socket(AF_INET, SOCK_STREAM, 0)).WillOnce(testing::Return(-1));  // Simulate socket creation failure

    // Act & Assert: Call multiply and check that it exits on failure
        int result = multiply(-3, 4);

    // Assert: Check multiplication result
    EXPECT_EQ(result, -12);  // -3 * 4 = -12
  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}