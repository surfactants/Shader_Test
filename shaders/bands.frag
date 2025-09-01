#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform float u_angle;
uniform float u_time;

void main()
{
    //u_angle += (radians(180) / 2.0);
    float rad = radians(u_angle + 90.0);
    vec2 st = gl_FragCoord.xy / u_resolution.xy;
    if (st.x > 0.5) {
        st *= -8.0;
    }
    else {
        st *= 8.0;
    }
    st.x *= sin(rad);
    st.y *= cos(rad);
    float a = 1.0;
    vec3 light = vec3(sin(10.0 * (st.x + st.y + (u_time * 1.0))));
    if (u_angle > 90.0) {
        light.g = 0.0;
        light.b = 0.0;
    }
    gl_FragColor = vec4(light, a);
}

