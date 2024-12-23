#pragma once

#include <code/code.h>
#include <inttypes.h>

namespace mstd {
    class wstring {
    public:
        wstring(const wchar_t* str) {
            code::Func<void, 0x020B08D4, wstring*, const wchar_t*>()(this, str);
        }

        wstring() = default;
        
        const wchar_t* c_str() const {
            return (length > 7) ? pointer : str;
        }

        const wstring& assign(const wstring& _str) {
			
			this->str[0] =  0;
			this->length2 = 7;
			this->length =  0;
            return code::Func<const mstd::wstring&, 0x02bb02c0, wstring*, const wstring&, int, int>()(this, _str, 0, 0xffffffff);
        }

        const wstring& assign(const wchar_t* _str, int _length) {
			
			this->str[0] =  0;
			this->length2 = 7;
			this->length =  0;
            return code::Func<const mstd::wstring&, 0x030E8BC4, wstring*, const wchar_t*, int>()(this, _str, _length);
        }
		
		const wstring& assign(const char* _str, int _length) {
			
			this->str[0] =  0;
			this->length2 = 7;
			this->length =  0;
            return code::Func<const mstd::wstring&, 0x02e33e08, wstring*, const char*, int>()(this, _str, _length);
        }
		
		const int compare(const wchar_t* _str, int _length) {
            return code::Func<const int, 0x03159BA0, wstring*, int, uint32_t, const wchar_t*, int>()(this, 0, this->length, _str, _length);
        }

        bool operator==(const wchar_t* _str) {
            const wchar_t* __str = c_str();
            return wcscmp(__str, _str);
        }

        uint32_t unk_0x0; // 0x00
        wchar_t str[8];   // 0x04
        wchar_t* pointer; // 0x14
        uint32_t length;  // 0x18
        uint32_t length2; // 0x1C
    };
}