#include <string.h>
#include <stdio.h>
#include "Codegen.h"
#include "jni.h"
#include "com_pogoclass_finger_print_EchoPrintLib.h"
 
extern "C" 
{
    	//const char * getEchoPrint (float *data, int numSamples, int offset) 
	//{
    	// invoke the codegen
   	//Codegen c = Codegen(data, (unsigned int)numSamples, offset);
    	//const char *code = c.getCodeString().c_str();
        //return code;
	//}
	
	JNIEXPORT jstring JNICALL Java_com_pogoclass_finger_1print_EchoPrintLib_getEchoPrint (JNIEnv * env, jobject jo, jfloatArray floatArray, jint numSamples, jint off)
	{
  	// invoke the codegen
  	float * floatArrayPoint = (float *)(env)->GetFloatArrayElements(floatArray, NULL); 
   	Codegen c = Codegen(floatArrayPoint, (unsigned int)numSamples, off);
    	const char *code = c.getCodeString().c_str();
    	jstring rtn;  
 	rtn = (env)->NewStringUTF(code); 
 	(env)->ReleaseFloatArrayElements(floatArray, floatArrayPoint, 0);
	return rtn;  
  	}
}

 


