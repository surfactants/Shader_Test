#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

const float light_factor = 0.75;
const float light_base = 1.0 - light_factor;

float rand(vec2 st) {
    return fract(sin(dot(st.xy,
                vec2(105.59 * fract(0.0000006 * u_time)
                , 643.233))) * 55555.55555);
}

void main()
{
    vec2 st = (gl_FragCoord.xy / u_resolution.xy);
    float light = rand(st);
    light *= light_factor;
    light += light_base;

    gl_FragColor = vec4(vec3(light), 1.0);
}

