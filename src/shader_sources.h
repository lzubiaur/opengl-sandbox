#ifndef ENGINE_SHADERS_H
#define ENGINE_SHADERS_H

namespace Engine {

  const char *_default_vertex_source =
    "#version 330 core\n" \
    "layout (location = 0) in vec3 aPos;\n" \
    "void main() { \n" \
    "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" \
    "}\n\0";

  const char *_default_fragment_source =
    "#version 330 core\n" \
    "out vec4 FragColor;\n" \
    "void main() {\n" \
    "  FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" \
    "}\n\0";


} /* Engine */

#endif // ENGINE_SHADERS_H
