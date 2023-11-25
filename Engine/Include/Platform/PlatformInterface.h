#pragma one

namespace Platform
{
	/// <summary>
	/// プラットフォームインターフェイス
	///	SDLなどプラットフォーム依存処理をラップして扱うためのインターフェイス
	/// </summary>
	class IInterface
	{
	public:
		/// <summary>
		/// Initializes this instance.
		/// </summary>
		/// <returns>
		/// 初期化に失敗したらfalse, 成功したらtrueを返す
		/// </returns>
		virtual bool Initialize() = 0;

		/// <summary>
		/// Shutdowns this instance.
		/// </summary>
		virtual void Shutdown() = 0;
	};
};
