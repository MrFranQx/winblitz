module;

#include <type_traits>

export module mrfranqx.winblitz.commons:number_concept;

namespace Winblitz {
	export template <typename T>
	concept Number = std::is_arithmetic_v<T>;
}