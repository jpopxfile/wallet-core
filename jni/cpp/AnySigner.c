// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include "AnySigner.h"
#include "TWJNI.h"

jbyteArray JNICALL Java_wallet_core_java_AnySigner_nativeSign(JNIEnv *env, jclass thisClass, jbyteArray input, jint coin) {
    TWData *inputData = TWDataCreateWithJByteArray(env, input);
    TWData *outputData = TWAnySignerSign(inputData, coin);
    jbyteArray resultData = TWDataJByteArray(outputData, env);
    TWDataDelete(inputData);
    return resultData;
}

jstring JNICALL Java_wallet_core_java_AnySigner_signJSON(JNIEnv *env, jclass thisClass, jstring json, jbyteArray key, jint coin) {
    TWString *jsonString = TWStringCreateWithJString(env, json);
    TWData *keyData = TWDataCreateWithJByteArray(env, key);
    TWString *result = TWAnySignerSignJSON(jsonString, keyData, coin);
    TWDataDelete(keyData);
    TWStringDelete(jsonString);
    return TWStringJString(result, env);
}

jbyteArray JNICALL Java_wallet_core_java_AnySigner_nativePlan(JNIEnv *env, jclass thisClass, jbyteArray input, jint coin) {
    TWData *inputData = TWDataCreateWithJByteArray(env, input);
    TWData *outputData = TWAnySignerPlan(inputData, coin);
    jbyteArray resultData = TWDataJByteArray(outputData, env);
    TWDataDelete(inputData);
    return resultData;
}
