//
//  AppDelegate.hpp
//  Triangle
//
//  Created by Ricardo Rachaus on 18/10/22.
//

#ifndef AppDelegate_hpp
#define AppDelegate_hpp

#include <AppKit/AppKit.hpp>
#include <MetalKit/MetalKit.hpp>
#include "Renderer.hpp"

class AppDelegate: public NS::ApplicationDelegate {
public:
    virtual void applicationDidFinishLaunching(NS::Notification *pNotification) override;
    ~AppDelegate();
private:
    NS::Window* m_Window;
    MTL::Device* m_Device;
    MTK::View* m_View;
    Renderer* delegate;
};

#endif /* AppDelegate_hpp */
