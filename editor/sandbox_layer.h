#pragma once

#include <poseidon/core.h>
#include <memory>

union SDL_Event;

namespace poseidon
{
	class ArrayBuffer;
	class IndexBuffer;
	class VertexArray;
	class Shader;
	class Texture;
}

namespace editor
{
	class SandboxLayer : public poseidon::Layer
	{
	public:
		SandboxLayer();
		virtual ~SandboxLayer() override;

		virtual void onStart() override;
		virtual void onUpdate() override;
		virtual bool onEvent(const SDL_Event& event) override;

	private:
		std::unique_ptr<poseidon::ArrayBuffer> cubeVbo_, quadVbo_;
		std::unique_ptr<poseidon::IndexBuffer> cubeIbo_, quadIbo_;
		std::unique_ptr<poseidon::VertexArray> cubeVao_, quadVao_;
		std::unique_ptr<poseidon::Shader> cubeShader_, quadShader_;
		std::unique_ptr<poseidon::Texture> quadTexture_;

		float angle_;
	};
}