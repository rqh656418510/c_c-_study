#pragma once

#include "CEncDesProtocol.h"

// 思科的加密解密实现类
class CCiscoEncDec : public CEncDesProtocol {

public:
	// 编码数据
	virtual int EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryptlen);

	// 解码数据
	virtual int DecData(unsigned char* cryptdata, int cryptlen, unsigned char* plain, int* plainlen);

};