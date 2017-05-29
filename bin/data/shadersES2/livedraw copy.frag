#version 120

//uniform sampler2DRect tex0;
uniform sampler2D tex0;
//uniform sampler2DRect imageMask;

uniform float thresh;
uniform float softness;
uniform float invert;

varying vec2 texCoordVarying;

void main()
{

	
  
    //float  value, l1, l2;
    //vec4   calc;

    

    vec4 color = texture2D(tex0, texCoordVarying);

    /*
    //p = texture2D(tex0, gl_TexCoord[0].xy);
    //vec4 texel0 = texture2D(tex0, texCoordVarying);

    //vec4 texel0 = texture2DRect(tex0, texCoordVarying);
    vec4 texel0 = texture2D(tex0, gl_TexCoord[0].xy);

    value = texel0.r*0.29+texel0.g*0.6+texel0.b*0.11;
    l1 = thresh - softness * 0.5;
    l2 = l1 + softness; //thresh + softness * 0.5;
    value = smoothstep(max(l1,0.0), min(l2, 1.0), value);
    value = invert * (1.-value) + (1.-invert)*value;

    calc=vec4( value, value, value, value);
  
    //vec4 texel1 = texture2DRect(imageMask, texCoordVarying);
    //gl_FragColor = vec4(texel0.rgb, texel0.a * texel1.a);
  //gl_FragColor = vec4(calc.rgb, calc.a * texel1.a);

  //gl_FragColor = calc;

  */

  gl_FragColor = color;
}