QT -= gui

TEMPLATE = lib


CONFIG += c++11

#定义项目编译之后生成的结果文件的存放路径
DESTDIR = ../../

SOURCES += \
		Base64.c                           \
		Clients.c                          \
		Heap.c                             \
		LinkedList.c                       \
		Log.c                              \
		Messages.c                         \
		MQTTAsync.c                        \
		MQTTAsyncUtils.c                   \
		MQTTClient.c                       \
		MQTTPacket.c                       \
		MQTTPacketOut.c                    \
		MQTTPersistence.c                  \
		MQTTPersistenceDefault.c           \
		MQTTProperties.c                   \
		MQTTProtocolClient.c               \
		MQTTProtocolOut.c                  \
		MQTTReasonCodes.c                  \
		MQTTTime.c                         \
		MQTTVersion.c                      \
		OsWrapper.c                        \
		samples/MQTTAsync_publish.c        \
		samples/MQTTAsync_publish_time.c   \
		samples/MQTTAsync_subscribe.c      \
		samples/MQTTClient_publish.c       \
		samples/MQTTClient_publish_async.c \
		samples/MQTTClient_subscribe.c     \
		samples/paho_cs_pub.c              \
		samples/paho_cs_sub.c              \
		samples/paho_c_pub.c               \
		samples/paho_c_sub.c               \
		samples/pubsub_opts.c              \
		SHA1.c                             \
		Socket.c                           \
		SocketBuffer.c                     \
		SSLSocket.c                        \
		StackTrace.c                       \
		Thread.c                           \
		Tree.c                             \
		utf-8.c                            \
		WebSocket.c                        \

HEADERS += \
		Base64.h                 \
		Clients.h                \
		Heap.h                   \
		LinkedList.h             \
		Log.h                    \
		Messages.h               \
		MQTTAsync.h              \
		MQTTAsyncUtils.h         \
		MQTTClient.h             \
		MQTTClientPersistence.h  \
		MQTTExportDeclarations.h \
		MQTTPacket.h             \
		MQTTPacketOut.h          \
		MQTTPersistence.h        \
		MQTTPersistenceDefault.h \
		MQTTProperties.h         \
		MQTTProtocol.h           \
		MQTTProtocolClient.h     \
		MQTTProtocolOut.h        \
		MQTTReasonCodes.h        \
		MQTTSubscribeOpts.h      \
		MQTTTime.h               \
		mutex_type.h             \
		OsWrapper.h              \
		samples/pubsub_opts.h    \
		SHA1.h                   \
		Socket.h                 \
		SocketBuffer.h           \
		SSLSocket.h              \
		StackTrace.h             \
		Thread.h                 \
		Tree.h                   \
		utf-8.h                  \
		WebSocket.h              \

win32 {
    LIBS += \
        -lWs2_32 \
}
