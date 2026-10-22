export module disxx.ui.engine.Engine;

import disxx.ui.ir.Window;

export namespace disxx::ui::engine
{
	template <typename T>
	concept NativeEngine = requires(T &engine)
	{
		{ T{} } -> std::same_as<T>;

		{
			#ifdef __APPLE__
				engine.setWindow(bridge::Window{})
			#else
				engine.SetWindow(ir::Window{})
			#endif
		} -> std::same_as<void>;

		{
			#ifdef __APPLE__
				engine.exec()
			#else
				engine.Exec()
			#endif
		} -> std::same_as<int>;
	};

	template <NativeEngine T>
	class __attribute__((visibility("hidden"))) [[nodiscard]] Engine
	{
	  protected:
		T m_NativeEngine{};

	  public:
		explicit Engine(void) noexcept = default;

		Engine(const Engine &) noexcept = default;
		Engine &operator=(const Engine &) noexcept = default;

		virtual ~Engine(void) noexcept = 0;
		virtual void SetWindow(ir::Window) const noexcept = 0;
		virtual int Exec(void) const noexcept = 0;
	};
} /* disxx::ui::engine */
