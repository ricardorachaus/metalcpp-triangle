//
//  main.cpp
//  Triangle
//
//  Created by Ricardo Rachaus on 18/10/22.
//

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#define MTK_PRIVATE_IMPLEMENTATION

#include "AppDelegate.hpp"

int main(int argc, const char * argv[]) {
    NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
    AppDelegate delegate;

    NS::Application* app = NS::Application::sharedApplication();
    app->setDelegate(&delegate);
    app->run();

    pool->release();

    return 0;
}
