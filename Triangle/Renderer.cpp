//
//  MTKViewDelegate.cpp
//  Triangle
//
//  Created by Ricardo Rachaus on 18/10/22.
//

#include "Renderer.hpp"

#include <simd/simd.h>

Renderer::Renderer(MTL::Device* device) : m_Device(device) {
    m_Queue = m_Device->newCommandQueue();

    MTL::Library* library = m_Device->newDefaultLibrary();
    MTL::Function* vertexFunction = library->newFunction(NS::String::string("vertex_main", NS::UTF8StringEncoding));
    MTL::Function* fragmentFunction = library->newFunction(NS::String::string("fragment_main", NS::UTF8StringEncoding));

    MTL::RenderPipelineDescriptor* descriptor = MTL::RenderPipelineDescriptor::alloc()->init();
    descriptor->colorAttachments()->object(0)->setPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);
    descriptor->setVertexFunction(vertexFunction);
    descriptor->setFragmentFunction(fragmentFunction);

    NS::Error* error = nullptr;
    m_PipelineState = m_Device->newRenderPipelineState(descriptor, &error);

    const simd::float3 positions[3] = {
        {0.0f, 0.5f, 0.0f},
        {-0.5f, -0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f}
    };

    const size_t positionSize = 3 * sizeof(simd::float3);
    NS::UInteger length = positionSize;
    m_VertexPositionBuffer = m_Device->newBuffer(&positions, length, MTL::ResourceStorageModeManaged);

    vertexFunction->release();
    fragmentFunction->release();
    descriptor->release();
    library->release();
}

Renderer::~Renderer() {
    m_Queue->release();
    m_PipelineState->release();
    m_VertexPositionBuffer->release();
}

void Renderer::drawInMTKView(MTK::View *pView) {
    NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();

    MTL::CommandBuffer* command = m_Queue->commandBuffer();
    MTL::RenderPassDescriptor* descriptor = pView->currentRenderPassDescriptor();
    MTL::RenderCommandEncoder* encoder = command->renderCommandEncoder(descriptor);

    encoder->setRenderPipelineState(m_PipelineState);
    encoder->setVertexBuffer(m_VertexPositionBuffer, 0, 0);
    encoder->drawPrimitives(MTL::PrimitiveType::PrimitiveTypeTriangle, NS::UInteger(0), NS::UInteger(3));

    encoder->endEncoding();
    command->presentDrawable(pView->currentDrawable());
    command->commit();

    pool->release();
}
