//
//  TestApp.swift
//  Test
//
//  Created by 张木林 on 8/29/24.
//

import Foundation
import Metal
import MetalKit
import SwiftUI

// 创建一个MTKViewRepresentable，用于在SwiftUI中显示Metal渲染
struct MetalView: UIViewRepresentable {
    func makeUIView(context: Context) -> MTKView {
        let mtkView = MTKView()
        mtkView.device = MTLCreateSystemDefaultDevice()
        mtkView.clearColor = MTLClearColor(red: 0.0, green: 0.0, blue: 0.0, alpha: 1.0)
        
        // 设置委托用于渲染
        mtkView.delegate = context.coordinator
        
        return mtkView
    }

    func updateUIView(_ uiView: MTKView, context: Context) {
        // 在需要时更新视图
    }

    // 创建协调器
    func makeCoordinator() -> Coordinator {
        Coordinator(self)
    }

    class Coordinator: NSObject, MTKViewDelegate {
        var parent: MetalView

        init(_ parent: MetalView) {
            self.parent = parent
            super.init()
        }

        // 当MTKView需要重绘时调用
        func draw(in view: MTKView) {
            guard let drawable = view.currentDrawable,
                  let descriptor = view.currentRenderPassDescriptor else {
                return
            }

            let commandQueue = view.device?.makeCommandQueue()
            let commandBuffer = commandQueue?.makeCommandBuffer()

            let renderEncoder = commandBuffer?.makeRenderCommandEncoder(descriptor: descriptor)
            renderEncoder?.endEncoding()

            commandBuffer?.present(drawable)
            commandBuffer?.commit()
        }
    }
}


struct ContentView: View {
    var body: some View {
        VStack {
            MetalView()
                .frame(width: 300, height: 300)
            Text("Hello, Metal!")
                .padding()
        }
    }
}

@main
struct TestApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}
