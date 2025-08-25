#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
const float base_light = 0.99;

// test with sf::VertexArray

void main()
{
    float light = base_light;
    float r = light;
    float b = light;
    float a = light;
    gl_FragColor = vec4(r, g, b, a);
}

