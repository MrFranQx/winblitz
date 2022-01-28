// https://github.com/MrFranQx/winblitz
//
// This file implements a constexpr version of sqrt().

module;

#include <limits>

export module mrfranqx.winblitz.commons:constexpr_sqrt;

namespace Winblitz {
	double constexpr sqrt_impl(double x, double curr, double prev)
	{
		return curr == prev
			? curr
			: sqrt_impl(x, 0.5 * (curr + x / curr), curr);
	}

	export double constexpr sqrt(double x)
	{
		return x >= 0 && x < std::numeric_limits<double>::infinity()
			? sqrt_impl(x, x, 0)
			: std::numeric_limits<double>::quiet_NaN();
	}
}