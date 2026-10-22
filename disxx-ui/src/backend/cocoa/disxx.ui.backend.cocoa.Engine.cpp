module;

#include "engine-Swift.h"
#include "bridge.hpp"

module disxx.ui.backend.cocoa.Engine;

namespace disxx::ui::backend::cocoa
{
	void Engine::SetWindow(ir::Window win) const noexcept
	{
		bridge::Window bridged{};
		bridged.SetSize(win.GetSize());
		bridged.SetTitle(win.GetTitle());
		for (const auto &widget : win.GetWidgets())
			bridged.AddWidget(widget);

		this->m_NativeEngine.SetWindow(bridged);
	}

	int Engine::Exec(void) const noexcept { this->m_NativeEngine.exec(); }
} /* disxx::ui::backend::cocoa */
