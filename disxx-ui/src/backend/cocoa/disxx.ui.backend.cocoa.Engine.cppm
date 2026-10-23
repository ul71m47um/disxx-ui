module;

#include <Backend-Swift.h>

export module disxx.ui.backend.cocoa.Engine;

import disxx.utility.pointer.NonNull;

import disxx.ui.engine.Engine;

export namespace disxx::ui::backend::cocoa
{
	class __attribute__((visibility("hidden"))) [[nodiscard]] Engine final : public engine::Engine<NativeEngine>
	{
	  private:
		static utility::NonNull s_pInstance{new Engine{}};

	  private:
		explicit Engine(void) noexcept = default;

	  public:
		static inline const utility::NonNull<Engine> &GetInstance(void) const noexcept;

	  public:
		virtual ~Engine(void) noexcept override;
		virtual void SetWindow(ir::Window) const noexcept override;
		virtual int Exec(void) const noexcept override;
	};

	inline const utility::NonNull<Engine> &Engine::GetInstance(void) const noexcept { return s_pInstance; }
} /* disxx::ui::backend::cocoa */
