//
//  MTKViewDelegate.hpp
//  Triangle
//
//  Created by Ricardo Rachaus on 18/10/22.
//

#ifndef MTKViewDelegate_hpp
#define MTKViewDelegate_hpp

#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>

class Renderer: public MTK::ViewDelegate {
public:
    Renderer(MTL::Device* device);
    ~Renderer();
    virtual void drawInMTKView(MTK::View* pView) override;

private:
    MTL::Device* m_Device;
    MTL::CommandQueue* m_Queue;
    MTL::RenderPipelineState* m_PipelineState;
    MTL::Buffer* m_VertexPositionBuffer;
//    MTL::Buffer* m_VertexColorBuffer;
};

#endif /* MTKViewDelegate_hpp */
