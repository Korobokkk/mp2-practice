#include <gtest.h>

int main(int argc, char **argv)
{
  //::testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleTest(&argc, argv);

    // Добавить фильтр программно (например, только тесты из TestSuiteName)
    ::testing::GTEST_FLAG(filter) = "test_list.*";
	return RUN_ALL_TESTS();
}
