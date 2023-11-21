#include <code/code.h>

#include <code/tcpgecko.h>
#include <code/wups.h>

#include <exports/curl_functions.h>
#include <exports/socket_functions.h>
#include <exports/vpad_functions.h>
#include <exports/gx2_functions.h>
#include <exports/kernel.h>
#include <exports/os_functions.h>
#include <exports/memory.h>

#include <minecraft/mc.h>

#include <xf/String.h>

void init() {
    InitTCPGecko();
    InitWups();

    InitSocketFunctionPointers();
    InitKernelFunctionPointers();
    InitVPadFunctionPointers();
    InitMemoryFunctionPointers();
    InitOSFunctionPointers();
    InitGX2FunctionPointers();
    InitLibCurlFunctionPointers();

    memoryInitialize();
}

int WriteCallback(char* contents, int size, int nmemb, xf::String<char>* userp) {
    for (int i = 0; i < (size * nmemb); i++) {
        userp->operator+=(contents[i]);
    }
    return size*nmemb;
}

bool hasSentMessage = false;
DECL_HOOK(onFrameInGame, void) {
    if (!hasSentMessage) {
        void* curl = curl_easy_init();
        if (curl) {
            xf::String<char> str = "";
            curl_easy_setopt(curl, CURLOPT_URL, "http://david-xf.de/logs");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, (void*) WriteCallback);
            curl_easy_setopt(curl, CURLOPT_FILE, &str);
            int res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            mc_printf(L"Response: %d Content: %s", res, str.c_str());
            hasSentMessage = true;
        }
    }
}

int c_main(void*) {
    init();

    HOOK(0x02D9CAD0, onFrameInGame, 0);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}