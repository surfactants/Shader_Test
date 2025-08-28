#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

const float base_light = 0.5;

// test with sf::VertexArray

float random (vec2 st) {
    return fract(sin(dot(st.xy, vec2(105.59 * fract(0.0000006 * u_time), 643.233))) * 55555.55555);
}

void main()
{
    vec2 st = (gl_FragCoord.xy / u_resolution.xy);
    float rnd = random(st);
    rnd *= 0.75;
    rnd += 0.25;

    gl_FragColor = vec4(vec3(rnd), 1.0);
}

