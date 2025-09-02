#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

// gamer rgb light
void main()
{
    float r = sin(u_time);
    float g = sin(0.5 * u_time);
    float b = 0.5 * sin(u_time) + 0.5;
    float a = 1.0;
    gl_FragColor = vec4(r, g, b, a);
}

/* NOTE FROM SFML DOCS:
 * The GLSL compiler optimizes out unused variables
 * (here, "unused" means "not involved in the calculation of the final vertex/pixel").
 * So don't be surprised if you get error messages such as
 * "Failed to find variable "xxx" in shader" when you call setUniform during your tests.
 */
