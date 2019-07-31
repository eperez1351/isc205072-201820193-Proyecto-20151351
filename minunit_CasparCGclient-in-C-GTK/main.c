#include "../../minunit/minunit.h"
#include "../CasparCGclient-in-C-GTK/otherfunctions.h"

#define MINUNIT_EPSILON 1E-12

char play[]
char stop[]
char pause[]
char resume[]
char



MU_TEST(test_checkCommandFunctions) {
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);
	mu_assert_string_eq("Thisstring", foostring);


}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_checkCommandFunctions);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
