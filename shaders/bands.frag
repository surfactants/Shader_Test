#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

// this is going to look really bad fullscreen
void main()
{
    // convert mouse pos for use with sfml
    u_mouse.y = u_resolution.y - u_mouse.y;
    float d = distance(u_mouse, gl_FragCoord.xy);
    vec3 light = vec3(sin((0.1 * d) + (10.0 * u_time)));
    float a = 1.0;
    gl_FragColor = vec4(light, a);
}

