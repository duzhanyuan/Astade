#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>


#define ITEM_IS_FOLDER      0x000100
#define ITEM_IS_PUBLIC      0x000200
#define ITEM_IS_PROTECTED   0x000400
#define ITEM_IS_PRIVATE     0x000800

#define ITEM_IS_DEST        0x004000
#define ITEM_IS_NORMALOP    0x008000


#define ITEM_IS_MODEL           0x0100000
#define ITEM_IS_CLASS           0x0200000
#define ITEM_IS_COMPONENTS      0x0300000
#define ITEM_IS_COMPONENT       0x0400000
#define ITEM_IS_CONFIGURATION   0x0500000
#define ITEM_IS_DEPENDENCY      0x0600000
#define ITEM_IS_ATTRIBUTE       0x0700000
#define ITEM_IS_OPERATION       0x0800000
#define ITEM_IS_PACKAGE         0x0900000
#define ITEM_IS_TARGET          0x0A00000
#define ITEM_IS_ATTRIBUTES      0x0B00000
#define ITEM_IS_OPERATIONS      0x0C00000
#define ITEM_IS_PARAMETERS      0x0D00000
#define ITEM_IS_CLASSES         0x0E00000
#define ITEM_IS_PARAMETER       0x0F00000
#define ITEM_IS_RELATION        0x1000000
#define ITEM_IS_RELATIONS       0x1100000
#define ITEM_IS_INRELATION      0x1200000
#define ITEM_IS_FILES           0x1300000
#define ITEM_IS_HFILE           0x1400000
#define ITEM_IS_CPPFILE         0x1500000
#define ITEM_IS_FILE            0x1600000
#define ITEM_IS_TYPES           0x1700000
#define ITEM_IS_TYPE            0x1800000
