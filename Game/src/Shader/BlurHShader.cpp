#ifndef BLUR_H_SHADER_CPP
#define BLUR_H_SHADER_CPP

#include <Resources/Shader.h>

class BlurHShader : public InstancedShader<BlurHShader>
{
public:
	std::string getFilePath() override
	{
		return std::string("./res/shaders/post-processing/blur-h");
	}

	void addUniforms() override
	{
		addUniform("offset");
		addTexture("renderTexture");
	}

	void addAttributes() override
	{
		addAttribut("position", Vertex::AttibLocation::POSITION);
	}
};

#endif // BLUR_H_SHADER_CPP