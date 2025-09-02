#ifdef GL_ES
precision mediump float;
#endif

// radial bands converging on u_pos
// looks really bad fullscreen
// and definitely dont do that if you're photoepileptic

uniform vec2 u_resolution;
uniform vec2 u_pos;
uniform float u_time;

// this is going to look really bad fullscreen
void main()
{
    // convert pos from SFML to GLSL
    u_mouse.y = u_resolution.y - u_pos.y;
    float d = distance(u_mouse, gl_FragCoord.xy);
    vec3 light = vec3(sin((0.1 * d) + (10.0 * u_time)));
    float a = 1.0;
    gl_FragColor = vec4(light, a);
}
