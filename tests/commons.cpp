// https://github.com/MrFranQx/winblitz
//
// These are tests for "commons" submodule.

#include <CppUnitTest.h>
#include <cmath>
#include <sstream>
#include <random>

import mrfranqx.winblitz.commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Commons {
	TEST_CLASS(Constexpr_sqrt) {
	public:
		TEST_METHOD(constexpr_sqrt)
		{
			// create randomizer
			std::random_device r;
			std::uniform_real_distribution<double> d{ 0, 10000 };
			std::default_random_engine e{ r() };

			double n = d(e);

			// TODO: use std::format when it has better support
			std::ostringstream os;
			os << "Testing constexpr_sqrt. Chosen number: " << n;
			Logger::WriteMessage(os.str().c_str());

			// multiplying and dividing by 10000 is needed to get 4 decimal places precision
			double expected = std::round(std::sqrt(n) * 10000.0) / 10000.0;
			double actual = std::round(Winblitz::sqrt(n) * 10000.0) / 10000.0;
			Assert::AreEqual(expected,actual);
		}
	};
}