//
//  Shaders.metal
//  Triangle
//
//  Created by Ricardo Rachaus on 18/10/22.
//

#include <metal_stdlib>
using namespace metal;

vertex float4 vertex_main(constant float3 *vertices [[ buffer(0) ]],
                          uint vertexID [[ vertex_id ]]) {
    return float4(vertices[vertexID], 1);
}

fragment half4 fragment_main() {
    return half4(1);
}
