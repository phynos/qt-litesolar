LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := duktape
LOCAL_SRC_FILES := duktape.c
# LOCAL_LDLIBS    := -ld -lm
LOCAL_LDLIBS    := -lm

include $(BUILD_SHARED_LIBRARY)
