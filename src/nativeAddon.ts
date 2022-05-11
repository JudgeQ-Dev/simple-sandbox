import bindings from "bindings";

// The name of this binding needs to correspond to the project name in `CMakeLists.txt`
// eslint-disable-next-line @typescript-eslint/no-explicit-any
const sandboxAddon: any = bindings("simple-sandbox");

export default sandboxAddon;
