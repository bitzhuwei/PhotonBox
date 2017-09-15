#ifndef FORWARD_AMBIENT_LIGHT_SHADER_H
#define FORWARD_AMBIENT_LIGHT_SHADER_H

#include "Shader.h"
#include "../Components/LightEmitter.h"

class ForwardAmbientLightShader : public Shader {
public:
	ForwardAmbientLightShader(const std::string& fileName) { init(fileName); }

	void update(Matrix4f& matrix, LightEmitter& ambient) {
		glUniformMatrix4fv(uniforms["mvp"], 1, GL_FALSE, &(matrix(0, 0)));
		glUniform1f(uniforms["light.intensity"], ambient.intensity);
		glUniform3fv(uniforms["light.color"], 1, &(ambient.color.x()));
	}

	void addAttributes() override {
		addAttribut("position", Vertex::AttibLocation::POSITION);
		addAttribut("uv", Vertex::AttibLocation::TEXTURECOORD);
	}

	void addUniforms() override{
		addUniform("mvp");
		addUniform("light.intensity");
		addUniform("light.color");
	}
};

#endif /* defined(FORWARD_AMBIENT_LIGHT_SHADER_H) */