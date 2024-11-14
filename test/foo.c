#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

int main(void)
{
    UNITY_BEGIN();
    TEST_ASSERT_TRUE(1);
    return UNITY_END();
}