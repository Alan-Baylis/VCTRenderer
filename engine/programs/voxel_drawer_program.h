#pragma once
#include "../types/program_shader.h"

#include <oglplus/uniform.hpp>
#include <oglplus/interop/glm.hpp>

class VoxelDrawerProgram : public ProgramShader
{
    protected:
        struct UniformMatrices
        {
            oglplus::Uniform<glm::mat4> viewProjection;
        };
    public:
        UniformMatrices matrices;
        oglplus::Uniform<float> halfVoxelSize;
        oglplus::UniformSampler voxelAlbedo;

        void ExtractUniforms() override;

        VoxelDrawerProgram() = default;
        virtual ~VoxelDrawerProgram();
};
