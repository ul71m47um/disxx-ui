import SwiftUI

import CxxStdlib
import Cxx

import IRBridge

extension disxx.ui.bridge.Window: @unchecked(Sendable) {}

private func main<T: Sendable>(_ body: @MainActor () -> T) -> T {
    if Thread.isMainThread {
        return MainActor.assumeIsolated(body)
    }
    
    return DispatchQueue.main.sync {
        MainActor.assumeIsolated(body)
    }
}

private struct WidgetWrapper: Identifiable {
    let id: UUID = UUID()
    let widget: disxx.ui.bridge.Widget
}

private struct TextView: View {
    private var text: AttributedString
    
    public var body: some View {
        Text(self.text)
    }
    
    public init(_ base: disxx.ui.bridge.`Property<_0>`) {
        self.text = AttributedString(String(base.GetText()))
        
        let arr: [CFloat] = Array(base.GetColor())
        self.text.foregroundColor = Color(
            .sRGB,
            red: Double(arr[0]),
            green: Double(arr[1]),
            blue: Double(arr[2]),
            opacity: Double(arr[3])
        )
    }
}

private struct ImageView: View {
    private let path: String
    
    public var body: some View {
        Group {
            if let image: NSImage = NSImage(contentsOfFile: self.path) {
                Image(nsImage: image)
                    .resizable()
                    .scaledToFit()
            } else {
                Text("disxx-ui: unable to load an image")
            }
        }
    }
    
    public init(_ base: disxx.ui.bridge.`Property<_1>`) {
        self.path = String(base.GetPath().string())
    }
}

private struct ButtonView: View {
    private enum ButtonProperty {
        case text(TextView)
        case image(ImageView)
    }
   
    private let property: ButtonProperty
    private let callback: () -> Void
    
    public var body: some View {
        Button {
            self.callback()
        } label: {
            switch self.property {
            case .text(let label):
                label
            
            case .image(let label):
                label
            }
        }
    }
    
    public init(_ base: disxx.ui.bridge.`Property<_2>`) {
        if let text: disxx.ui.bridge.`Property<_0>` = Optional(
            fromCxx: disxx
                .ui
                .bridge
                .mktxt(
                    base
                )
        ) {
            self.property = .text(TextView(text))
        } else {
            self.property = .image(
                ImageView(
                    Optional(
                        fromCxx: disxx
                            .ui
                            .bridge
                            .mkimg(
                                base
                            )
                    )!
                )
            )
        }
       
        self.callback = {
            base.GetCallback()()
        }
    }
}

private struct TextInputView: View {
    @State private var text: String
   
    private let promt: String
    private var callback: (std.string) -> Void
    
    public var body: some View {
        TextField(self.promt, text: self.$text)
            .onSubmit {
                self.callback(std.string(stringLiteral: self.text))
            }
    }
    
    public init(_ base: disxx.ui.bridge.`Property<_3>`) {
        self.text = String()
        self.promt = String(base.GetText())
        self.callback = { cstr in
            base.GetCallback()(cstr)
        }
    }
}

private final class Translator {
    @MainActor
    public static func mkview(_ widget: disxx.ui.bridge.Widget) -> any View {
        switch widget.GetType() {
        case .TYPE_TEXT:
            TextView(
                Optional(
                    fromCxx: disxx
                        .ui
                        .bridge
                        .mktxt(
                            Optional(
                                fromCxx: disxx
                                    .ui
                                    .bridge
                                    .mkprop(widget)
                            )!
                    )
                )!
            )
            
        case .TYPE_IMAGE:
            ImageView(
                Optional(
                    fromCxx: disxx
                        .ui
                        .bridge
                        .mkimg(
                            Optional(
                                fromCxx: disxx
                                    .ui
                                    .bridge
                                    .mkprop(widget)
                            )!
                        )
                )!
            )
            
        case .TYPE_BUTTON:
            ButtonView(
                Optional(
                    fromCxx: disxx
                        .ui
                        .bridge
                        .mkbtn(
                            Optional(
                                fromCxx: disxx
                                    .ui
                                    .bridge
                                    .mkprop(widget)
                            )!
                        )
                )!
            )
            
        case .TYPE_TEXTINPUT:
            TextInputView(
                Optional(
                    fromCxx: disxx
                        .ui
                        .bridge
                        .mktxtin(
                            Optional(
                                fromCxx: disxx
                                    .ui
                                    .bridge
                                    .mkprop(widget)
                            )!
                        )
                )!
            )
            
        case .TYPE_LIST:
            List {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
        
        case .TYPE_VSTACK:
            VStack {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
            
        case .TYPE_HSTACK:
            HStack {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
         
        case .TYPE_VSPLITVIEW:
            VSplitView {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
            
        case .TYPE_HSPLITVIEW:
            HSplitView {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
            
        case .TYPE_LAZYVSTACK:
            LazyVStack {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
            
        case .TYPE_LAZYHSTACK:
            LazyHStack {
                ForEach(Optional(fromCxx: disxx.ui.bridge.mkvec(widget))!.map { w in WidgetWrapper(widget: w) }) { widget in
                    AnyView(Self.mkview(widget.widget))
                }
            }
            
        default:
            EmptyView()
        }
    }
    
    @MainActor
    public static func mkwin(_ window: disxx.ui.bridge.Window) -> NSWindow? {
        let size: [CFloat] = Array(window.GetSize())
        
        let win: NSWindow = NSWindow(
            contentRect: NSRect(
                origin: CGPoint(),
                size: CGSize(
                    width: Int(size[0]),
                    height: Int(size[1])
                )
            ),
            styleMask: [.titled, .closable, .miniaturizable, .resizable],
            backing: .buffered,
            defer: false
        )
        
        win.title = String(window.GetTitle())
        win.center()
        
        return win
    }
}

@MainActor
private final class ApplicationDelegate: NSObject, NSApplicationDelegate, NSWindowDelegate {
    private var window: NSWindow? = nil
    private var widgets: [disxx.ui.bridge.Widget] = Array()

    public func setWindow(_ win: disxx.ui.bridge.Window) -> Void {
        self.widgets = Array(win.GetWidgets())
        self.window = Translator.mkwin(win)
        self.window?.isReleasedWhenClosed = false
        self.window?.delegate = self
        self.window?.contentView = NSHostingView(
            rootView: ForEach(
                self.widgets.map { w in WidgetWrapper(widget: w) }
            ) { widget in
                    AnyView(Translator.mkview(widget.widget))
                }
            )
    }
    
    public func exec() -> Void {
        let app: NSApplication = NSApplication.shared
        
        self.window?.makeKeyAndOrderFront(nil)
        
        app.activate()
        app.run()
        
        self.window?.close()
    }
}

@_expose(Cxx)
public final class NativeEngine: Sendable {
    private let appDelegate: ApplicationDelegate
  
    @_expose(Cxx)
    public func setWindow(_ window: disxx.ui.bridge.Window) -> Void {
        main { self.appDelegate.setWindow(window) }
    }
  
    @_expose(Cxx)
    public func exec() -> CInt {
        main { self.appDelegate.exec() }
        return 0
    }
    
    @_expose(Cxx)
    public init() {
        self.appDelegate = main {
            ApplicationDelegate()
        }
    }
}
