#include "../../minunit/minunit.h"
#include "../CasparCGclient-in-C-GTK/otherfunctions.h"

#define MINUNIT_EPSILON 1E-12

char play[] = "play 1-1 file\r\n";
char stop[] = "stop 1-1\r\n";
char pausestring[] = "pause 1-1\r\n";
char resume[] = "resume 1-1\r\n";
char clear[] = "clear 1\r\n";
char print[] = "print 1\r\n";
char cls[] = "cls\r\n";
char setlogo[] = "play 1-2 file\r\n";

char validFilename[] = "1";
char invalidFilename[] = "2";



MU_TEST(test_checkCommandFunctions) {
	mu_assert_string_eq(playCommand("file"), play);
	mu_assert_string_eq(stopCommand(), stop);
	mu_assert_string_eq(pauseCommand(), pausestring);
	mu_assert_string_eq(resumeCommand(), resume);
	mu_assert_string_eq(clearCommand("1"), clear);
	mu_assert_string_eq(printCommand("1"), print);
	mu_assert_string_eq(clsCommand(), cls);
	mu_assert_string_eq(setLogo("file"), setlogo);
	mu_assert_string_eq(readCommandsFromFile(validFilename), "play 1-1 amb\r\n");
    mu_assert_string_eq(readCommandsFromFile(invalidFilename), "0");



}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_checkCommandFunctions);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
