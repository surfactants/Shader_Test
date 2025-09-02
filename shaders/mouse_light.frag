#ifdef GL_ES
precision mediump float;
#endif

// draws a pulsing circular light centered on the mouse

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;
const float radius = 1.0;

void main()
{
    u_mouse.y = u_resolution.y - u_mouse.y;
    float d = 1.0 - distance(u_mouse, gl_FragCoord.xy) / 100.0;
    if (d > radius) {
        discard;
    }
    float light = abs(0.3 * sin(1.75 * u_time)) + 0.7;
    light *= d;
    float r = light;
    float g = light;
    float b = light;
    float a = 1.0;
    gl_FragColor = vec4(r, g, b, a);
}
