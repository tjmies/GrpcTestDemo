QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    example.grpc.pb.cc \
    example.pb.cc \
    helloworld.grpc.pb.cc \
    helloworld.pb.cc \
    main.cpp \
    mainwindow.cpp \
    test.grpc.pb.cc \
    test.pb.cc

HEADERS += \
    example.grpc.pb.h \
    example.pb.h \
    helloworld.grpc.pb.h \
    helloworld.pb.h \
    mainwindow.h \
    test.grpc.pb.h \
    test.pb.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../下载/lib/grpc/lib/release/ -lgrpc++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../下载/lib/grpc/lib/debug/ -lgrpc++
else:unix: LIBS += -L$$PWD/../libs/grpc/lib -lgrpc++


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../下载/lib/grpc/lib/release/ -lgrpc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../下载/lib/grpc/lib/debug/ -lgrpc
else:unix: LIBS += -L$$PWD/../libs/grpc/lib -lgrpc

INCLUDEPATH += $$PWD/../libs/grpc/include
DEPENDPATH += $$PWD/../libs/grpc/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/grpc/lib/libgrpc++.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libgrpc++.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/grpc++.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/grpc++.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libs/grpc/lib/libgrpc++.a

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/libgpr.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libgpr.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/libgpr.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libgpr.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libs/grpc/lib/libgpr.a

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/libgrpc.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libgrpc.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/libgrpc.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libgrpc.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libs/grpc/lib/libgrpc.a

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/libupb.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libupb.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/release/libupb.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/grpc/lib/debug/libupb.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libs/grpc/lib/libupb.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../protobuf/lib/release/ -lprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../protobuf/lib/debug/ -lprotobuf
else:unix: LIBS += -L$$PWD/../protobuf/lib -lprotobuf

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../protobuf/lib/release/ -lprotoc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../protobuf/lib/debug/ -lprotoc
else:unix: LIBS += -L$$PWD/../protobuf/lib -lprotoc

INCLUDEPATH += $$PWD/../protobuf/include
DEPENDPATH += $$PWD/../protobuf/include

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../protobuf/lib/libprotobuf.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/debug/libprotobuf.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/release/protobuf.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/debug/protobuf.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/protobuf/lib/libprotobuf.a

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/release/libprotoc.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/debug/libprotoc.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/release/libprotoc.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../下载/lib/protobuf/lib/debug/libprotoc.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/protobuf/lib/libprotoc.a


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../下载/lib/opencv/lib/release/ -lopencv_world
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../下载/lib/opencv/lib/debug/ -lopencv_world
else:unix: LIBS += -L$$PWD/../libs/opencv/lib -lopencv_world
INCLUDEPATH += $$PWD/../libs/opencv/include
DEPENDPATH += $$PWD/../libs/opencv/include
