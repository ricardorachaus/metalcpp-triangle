//
//  AppDelegate.cpp
//  Triangle
//
//  Created by Ricardo Rachaus on 18/10/22.
//

#include "AppDelegate.hpp"

AppDelegate::~AppDelegate() {
    m_View->release();
    m_Device->release();
    m_Window->release();
    delete delegate;
}

void AppDelegate::applicationDidFinishLaunching(NS::Notification *pNotification) {
    CGRect frame = (CGRect){ {100, 100}, {512, 512} };
    m_Window = NS::Window::alloc()->init(frame,
                                         NS::WindowStyleMaskClosable|NS::WindowStyleMaskTitled,
                                         NS::BackingStoreBuffered,
                                         false);

    m_Device = MTL::CreateSystemDefaultDevice();
    m_View = MTK::View::alloc()->init(frame, m_Device);

    m_View->setColorPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);
    m_View->setClearColor(MTL::ClearColor(0.3, 0.3, 0.3, 1.0));

    delegate = new Renderer(m_Device);

    m_View->setDelegate(delegate);

    m_Window->setContentView(m_View);
    m_Window->makeKeyAndOrderFront(nullptr);
}
