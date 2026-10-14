export module disxx.ui.Widget;

import disxx.ui.ir.Widget;

export namespace disxx::ui
{
	template <typename T>
	concept Widget = requires(T widget) { { widget.ProduceIntermidiateRepresentation() } -> std::same_as<ir::Widget> };
} /* disxx::ui */
