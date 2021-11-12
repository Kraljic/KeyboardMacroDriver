#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "src/MacroKeyboard/AsciiToHidTranscoder/Test/ascii_to_hid_transcoder_test.h"
#include "src/MacroKeyboard/HidKeyboard/Test/hid_keyboard_test.h"
#include "src/MacroKeyboard/Macro/Test/macro_test.h"
#include "src/MacroKeyboard/Main/Test/main_test.h"
#include "src/MacroKeyboard/Memory/Test/memory_test.h"
#include "src/MacroKeyboard/Ps2Keyboard/Test/ps2_keyboard_test.h"
#include "src/MacroKeyboard/Ps2ToHidTranscoder/Test/ps2_to_hid_transcoder_test.h"
#include "src/MacroKeyboard/Timer/Test/timer_test.h"

using namespace std;
using namespace test;

#define ASSERT_RESULT(resutl, msg)                \
	if (!(result))                                \
		cout << "Finished: OK \t" << msg << endl; \
	else                                          \
		cout << "Finished: ERROR \t" << msg << endl;

int main()
{
	int result = 0;

	result = ps2_keyboard_reader_test();
	ASSERT_RESULT(result, "ps2_keyboard_reader_test")

	result = ps2_to_hid_transcoder_test();
	ASSERT_RESULT(result, "ps2_to_hid_transcoder_test")

	result = hid_keyboard_state_test();
	ASSERT_RESULT(result, "hid_keyboard_state_test")

	result = macro_command_handler_test();
	ASSERT_RESULT(result, "macro_command_handler_test")

	result = macro_finder_test();
	ASSERT_RESULT(result, "macro_finder_test")

	result = memory_reader_test();
	ASSERT_RESULT(result, "memory_reader_test")

	result = relative_memory_access_test();
	ASSERT_RESULT(result, "relative_memory_access_test")

	result = macro_executor_test();
	ASSERT_RESULT(result, "macro_executor_test")

	result = ascii_to_hid_test();
	ASSERT_RESULT(result, "ascii_to_hid_test")

	result = delay_util_test();
	ASSERT_RESULT(result, "delay_util_test")

	result = macro_util_test();
	ASSERT_RESULT(result, "macro_util_test")

	result = main_keyboard_test();
	ASSERT_RESULT(result, "main_keyboard_test")

	return 0;
}
