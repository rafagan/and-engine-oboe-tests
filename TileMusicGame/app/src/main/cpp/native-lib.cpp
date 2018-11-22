#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>

using namespace std;

class androidbuf : public std::streambuf {
public:
    enum { bufsize = 128 }; // ... or some other suitable buffer size
    androidbuf() { this->setp(buffer, buffer + bufsize - 1); }

private:
    int overflow(int c)
    {
        if (c == traits_type::eof()) {
            *this->pptr() = traits_type::to_char_type(c);
            this->sbumpc();
        }
        return this->sync()? traits_type::eof(): traits_type::not_eof(c);
    }

    int sync()
    {
        int rc = 0;
        if (this->pbase() != this->pptr()) {
            char writebuf[bufsize+1];
            memcpy(writebuf, this->pbase(), this->pptr() - this->pbase());
            writebuf[this->pptr() - this->pbase()] = '\0';

            rc = __android_log_write(ANDROID_LOG_INFO, "std", writebuf) > 0;
            this->setp(buffer, buffer + bufsize - 1);
        }
        return rc;
    }

    char buffer[bufsize];
};


extern "C" JNIEXPORT jstring JNICALL
Java_tilemusicgame_tutorial_rafagan_tilemusicgame_NativeCallsKt_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jint JNICALL
Java_tilemusicgame_tutorial_rafagan_tilemusicgame_NativeCallsKt_playSound(
        JNIEnv *env,
        jobject /* this */) {

    std::cout.rdbuf(new androidbuf);

    cout << "Testeeeeeeeeeeeeeeeeee" << endl;
    __android_log_print(ANDROID_LOG_INFO, "teste", "This is my first log in LogCat");

    delete std::cout.rdbuf(0);
    return 0;
}