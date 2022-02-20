// https://github.com/MrFranQx/winblitz
//
// These are tests for "utf8" submodule.

#include <CppUnitTest.h>
#include <string>

import mrfranqx.winblitz.utf8;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Utf8 {
	TEST_CLASS(Utf8_conversions) {
	public:
		TEST_METHOD(utf8_to_utf16_ascii) {
			std::string teststr = "The quick brown fox jumps over a lazy dog.";

			std::wstring expected = L"The quick brown fox jumps over a lazy dog.";
			std::wstring actual = Winblitz::utf8_to_utf16(teststr);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(utf16_to_utf8_ascii) {
			std::wstring teststr = L"The quick brown fox jumps over a lazy dog.";

			std::string expected = "The quick brown fox jumps over a lazy dog.";
			std::string actual = Winblitz::utf16_to_utf8(teststr);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(utf8_to_utf16_special) {

			// why this sentence? I (MrFranQx) am Polish
			// and this was the first thing with special characters that came into my mind
			
			std::string teststr = "Zażółć gęślą jaźń.";

			std::wstring expected = L"Zażółć gęślą jaźń.";
			std::wstring actual = Winblitz::utf8_to_utf16(teststr);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(utf16_to_utf8_special) {
			std::wstring teststr = L"Zażółć gęślą jaźń.";

			std::string expected = "Zażółć gęślą jaźń.";
			std::string actual = Winblitz::utf16_to_utf8(teststr);

			Assert::AreEqual(expected, actual);
		}
	};
}