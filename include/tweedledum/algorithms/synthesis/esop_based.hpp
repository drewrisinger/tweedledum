/*------------------------------------------------------------------------------
| This file is distributed under the MIT License.
| See accompanying file /LICENSE for details.
| Author(s): Mathias Soeken
|            Bruno Schmitt
*-----------------------------------------------------------------------------*/
#pragma once

#include "../../traits.hpp"
#include "../../networks/netlist.hpp"

#include <kitty/dynamic_truth_table.hpp>
#include <kitty/esop.hpp>

namespace tweedledum {

template<typename Network>
void esop_based_synthesis(Network& circ, kitty::dynamic_truth_table const& tt)
{
	// clang-format off
	static_assert(has_allocate_qubit_v<Network>, "Network must implement allocate_qubit");
	static_assert(has_add_multiple_controlled_target_gate_v<Network>, "Network must implement has_add_multiple_controlled_target_gate");
	// clang-format on

	const uint32_t num_qubits = tt.num_vars() + 1;
	for (auto i = 0u; i < num_qubits; ++i) {
		circ.allocate_qubit();
	}
	uint32_t target = 1 << tt.num_vars();
	for (const auto& cube : kitty::esop_from_pprm(tt)) {
		circ.add_multiple_controlled_target_gate(gate_kinds_t::mcx,
		                                         cube._bits, target);
	}
}

}; // namespace tweedledum
