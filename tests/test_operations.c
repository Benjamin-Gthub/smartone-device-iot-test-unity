//
// Created by benjamin on 12/18/2024.
//

#include "unity.h"
#include "../src/operations.h"


// Configuración inicial antes de cada prueba
void setUp(void) {}

// Configuración final después de cada prueba
void tearDown(void) {}

void test_sum(){
    TEST_ASSERT_EQUAL(5, sum(2, 3));
    TEST_ASSERT_EQUAL(-1, sum(-2, 1));
}

void test_dif(){
    TEST_ASSERT_EQUAL(-1, dif(2, 3));
    TEST_ASSERT_EQUAL(-3, dif(-2, 1));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_sum);
    RUN_TEST(test_dif);
    return UNITY_END();
}