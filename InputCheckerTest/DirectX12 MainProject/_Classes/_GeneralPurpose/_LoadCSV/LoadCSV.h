/**
 * @file LoadCSC.h
 * @brief CSV�ǂݎ�菈��
 * @author �V���D�F
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include <string>
#include <map>

namespace CSV {
	void Schan(std::wstring fileName, const char* format, ...);
	void Schan(std::wstring fileName, std::map<std::string, float> maplist);
}