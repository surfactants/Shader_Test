#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;

void main()
{
    float g = 0.0;
    float b = 0.0;
    float r = 0.0;
    float a = 1.0;
    gl_FragColor = vec4(r, g, b, a);
}


