
#ifndef _XIMAGE_GIF_H_
#define _XIMAGE_GIF_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

struct TFrame    // structure that keeps a single frame info
{
	IPicture *m_pPicture;  // pointer to the interface used for drawing
	SIZE     m_frameSize;
	SIZE     m_frameOffset;
	UINT     m_nDelay;     // delay (in 1/100s of a second)
	UINT     m_nDisposal;  // disposal method
	};

class CxImageGif
{
public:

#pragma pack(1)   // turn byte alignment on

typedef enum GIFBlockTypesTag
{
	BLOCK_UNKNOWN,
	BLOCK_APPEXT,
	BLOCK_COMMEXT,
	BLOCK_CONTROLEXT,
	BLOCK_PLAINTEXT,
	BLOCK_IMAGE,
	BLOCK_TRAILER
}GIFBlockTypes;

typedef enum ControlExtValuesTag // graphic control extension packed field values
{
	GCX_PACKED_DISPOSAL,  // disposal method
	GCX_PACKED_USERINPUT,
	GCX_PACKED_TRANSPCOLOR
}ControlExtValues;

typedef enum LSDPackedValuesTag  // logical screen descriptor packed field values
{
	LSD_PACKED_GLOBALCT,
	LSD_PACKED_CRESOLUTION,
	LSD_PACKED_SORT,
	LSD_PACKED_GLOBALCTSIZE
}LSDPackedValues;

typedef enum IDPackedValuesTag   // image descriptor packed field values
{
	ID_PACKED_LOCALCT,
	ID_PACKED_INTERLACE,
	ID_PACKED_SORT,
	ID_PACKED_LOCALCTSIZE
}IDPackedValues;

typedef struct TGIFHeaderTag       // GIF header  
{
	char m_cSignature[3]; // Signature - Identifies the GIF Data Stream
						  // This field contains the fixed value 'GIF'
	char m_cVersion[3];	// Version number. May be one of the following:
						// "87a" or "89a"
}TGIFHeader;

typedef struct TGIFLSDescriptorTag // Logical Screen Descriptor
{
	WORD m_wWidth;	// 2 bytes. Logical screen width
	WORD m_wHeight; // 2 bytes. Logical screen height

	unsigned char m_cPacked;      // packed field	

	unsigned char m_cBkIndex;     // 1 byte. Background color index
	unsigned char m_cPixelAspect; // 1 byte. Pixel aspect ratio
	inline int GetPackedValue(LSDPackedValues Value);
}TGIFLSDescriptor;

typedef struct TGIFAppExtensionTag // application extension block
{
	unsigned char m_cExtIntroducer; // extension introducer (0x21)
	unsigned char m_cExtLabel; // app. extension label (0xFF)
	unsigned char m_cBlockSize; // fixed value of 11
	char m_cAppIdentifier[8];   // application identifier
	char m_cAppAuth[3];  // application authentication code
}TGIFAppExtension;

typedef struct TGIFControlExtTag // graphic control extension block
{
	unsigned char m_cExtIntroducer; // extension introducer (0x21)
	unsigned char m_cControlLabel;  // control extension label (0xF9)
	unsigned char m_cBlockSize; // fixed value of 4
	unsigned char m_cPacked;    // packed field
	WORD m_wDelayTime;	// delay time
	unsigned char m_cTColorIndex; // transparent color index
	unsigned char m_cBlockTerm;   // block terminator (0x00)
public:
	inline int GetPackedValue(ControlExtValues Value);
}TGIFControlExt;

typedef struct TGIFCommentExtTag  // comment extension block
{
	unsigned char m_cExtIntroducer; // extension introducer (0x21)
	unsigned char m_cCommentLabel;  // comment extension label (0xFE)
}TGIFCommentExt;

typedef struct TGIFPlainTextExtTag // plain text extension block
{
	unsigned char m_cExtIntroducer;  // extension introducer (0x21)
	unsigned char m_cPlainTextLabel; // text extension label (0x01)
	unsigned char m_cBlockSize; // fixed value of 12
	WORD m_wLeftPos;    // text grid left position
	WORD m_wTopPos;     // text grid top position
	WORD m_wGridWidth;  // text grid width
	WORD m_wGridHeight; // text grid height
	unsigned char m_cCellWidth;  // character cell width
	unsigned char m_cCellHeight; // character cell height
	unsigned char m_cFgColor; // text foreground color index
	unsigned char m_cBkColor; // text background color index
}TGIFPlainTextExt;

typedef struct TGIFImageDescriptorTag // image descriptor block
{
	unsigned char m_cImageSeparator; // image separator byte (0x2C)
	WORD m_wLeftPos; // image left position
	WORD m_wTopPos;  // image top position
	WORD m_wWidth;   // image width
	WORD m_wHeight;  // image height
	unsigned char m_cPacked; // packed field
	inline int GetPackedValue(IDPackedValues Value);
}TGIFImageDescriptor;

#pragma pack() // turn byte alignment off

public:
	CxImageGif();
	virtual ~CxImageGif();
	
	// loads a picture from a file
	// i.e. Load(_T("mypic.gif"));
	BOOL Load(LPCTSTR szFileName);
	
	// loads a picture from a global memory block (allocated by GlobalAlloc)
	// Warning: this function DOES NOT free the global memory, pointed to by hGlobal
	BOOL Load(HGLOBAL hGlobal, DWORD dwSize);
	
	// loads a picture from a program resource
	// i.e. Load(MAKEINTRESOURCE(IDR_MYPIC),_T("GIFTYPE"));
	BOOL Load(LPCTSTR szResourceName,LPCTSTR szResourceType);

	void UnLoad(); // stops animation plus releases all resources
	
	const TFrame* GetFrame(size_t nIndex) const;

	int GetFrameCount() const;
	
	SIZE GetSize() const;

	COLORREF GetBackGroundColor() const;

protected:
	COLORREF m_clrBackground;
	SIZE m_PictureSize;
	UINT m_nDataSize;
	UINT m_nCurrOffset;
	UINT m_nGlobalCTSize;
	TGIFHeader * m_pGIFHeader;
	unsigned char * m_pRawData;
	TGIFLSDescriptor * m_pGIFLSDescriptor;
	std::vector<TFrame> m_arrFrames;
//	TFrame m_arrFrames;

	int GetNextBlockLen() const;
	BOOL SkipNextBlock();
	BOOL SkipNextGraphicBlock();
	void ResetDataPointer();
	GIFBlockTypes GetNextBlock() const;
	UINT GetSubBlocksLen(UINT nStartingOffset) const;
	HGLOBAL GetNextGraphicBlock(UINT *pBlockLen, UINT *pDelay, 
		SIZE *pBlockSize, SIZE *pBlockOffset, UINT *pDisposal);
};

#endif // !defined(_XIMAGE_GIF_H_)
