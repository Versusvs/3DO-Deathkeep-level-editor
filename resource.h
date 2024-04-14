//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by app.rc
#include <vector>

using namespace std;

#define Swap4Bytes(val) val = ( (((val) >> 24) & 0x000000FF) | (((val) >> 8) & 0x0000FF00) | (((val) <<  8) & 0x00FF0000) | (((val) << 24) & 0xFF000000) )
#define Swap8Bytes(val) ( (((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | (((val) >> 24) & 0x0000000000FF0000) | (((val) >>  8) & 0x00000000FF000000) | (((val) <<  8) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | (((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000) )
#define Swap2Bytes(val) ( (((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00) )

extern struct voxel
{
    int x;
    int y;
	int z;
	unsigned long long value1;
	string coords;
//	unsigned long value2;
};

extern unsigned int voxelindex = 0;

//extern unsigned int levelEntryX, levelEntryY, levelEntryZ, levelExitX, levelExitY, levelExitZ = 0;

extern struct cubespecs
{
unsigned    char textureW;			// Byte 1 
bool			mirroredW;
unsigned	char textureS;			// Byte 2
bool			mirroredS;
unsigned	char textureE;			// Byte 3
bool			mirroredE;
unsigned	char textureN;			// Byte 4
bool			mirroredN;
unsigned	char textureNWfromN;	// Byte 5
bool			mirroredNWfromN;
unsigned	char textureNEfromS;	// Byte 6
bool			mirroredNEfromS;
unsigned	char textureNWfromS;	// Byte 7
bool			mirroredNWfromS;
unsigned	char textureNEfromN;	// Byte 8
bool			mirroredNEfromN;
unsigned	char textureFloor;		// Byte 9
//bool			textureFloorOrienttmp1;
//bool			textureFloorOrienttmp2;
unsigned	char textureFloorOrient;
unsigned	char textureCeiling;	// Byte 10
//bool			textureCeilingOrienttmp1;
//bool			textureCeilingOrienttmp2;
unsigned	char textureCeilingOrient;
unsigned	char unknown1;			// Byte 11
unsigned	char telep_rest_elev;	// Byte 12
unsigned	char unknown3;			// Byte 13
unsigned	char unknown4;			// Byte 14
unsigned	char unknown5;			// Byte 15. Additional collisions
unsigned	char unknown6;			// Byte 16
};


// Struct for cels. Store ID, collision type
extern struct cels
{
unsigned char id;
bool bytes8;// Collision present
//unsigned short int collisionType;
bool bit0;
bool bit1;
bool bit2;
bool bit3;
bool bit4;
bool bit5;
bool bit6;
bool bit7;
bool bit8;
bool bit9;
bool bit10;
bool bit11;
bool bit12;
bool bit13;
bool bit14;
bool bit15;
bool bit16;
bool bit17;
bool bit18;
bool bit19;
bool bit20;
bool bit21;
bool bit22;
bool bit23;
bool bit24;
bool bit25;
bool bit26;
bool bit27;
bool bit28;
bool bit29;
bool bit30;
bool bit31;
bool bit32;
bool bit33;
bool bit34;
bool bit35;
bool bit36;
bool bit37;
bool bit38;
bool bit39;
bool bit40;
bool bit41;
bool bit42;
bool bit43;
bool bit44;
bool bit45;
bool bit46;
bool bit47;
bool bit48;
bool bit49;
bool bit50;
bool bit51;
bool bit52;
bool bit53;
bool bit54;
bool bit55;
bool bit56;
bool bit57;
bool bit58;
bool bit59;
bool bit60;
bool bit61;
bool bit62;
bool bit63;
};


extern struct DKDataObj
	{
	unsigned char	headsize;	
	unsigned char	reftype;
	unsigned char	type;
	unsigned int	pos;			
	};


//#define ANIM_MULTI_CCB	0
//#define ANIM_SINGLE_CCB 1
extern unsigned int pos2AnimBack, pos2AnimObj, pos2AnimEnemies, pos2Objects = 0;
extern unsigned char defaultTexID = 0; // Default texture for stairs and (?)
extern bool notloaded = true;

extern struct LoopRec
	{
	unsigned int	loopStart;			/*	start frame for a loop in the animation */
	unsigned int	loopEnd;			/*	end frame for a loop in the animation */
	unsigned int	repeatCount;		/*	number of times to repeat the looped portion */
	unsigned int	repeatDelay;		/*	number of 1/60s of a sec to delay each time thru loop */
	};


extern struct anim
{
unsigned int animHeadersize;	
bool animType; /* 0 = multi-CCB ; 1 = single CCB */
unsigned int version; /* current version = 0 */
unsigned int numFrames; /* number of frames for this animation */
unsigned int frameRate; /* number of 1/60s of a sec to display each frame */
unsigned int startFrame; /* the first frame in the anim. Can be non zero */
unsigned int numLoops; /* number of loops in loop array. Loops are executed serially */
LoopRec loop[1]; /* array of loop info. see numLoops */

};


extern struct teleport
{
unsigned    char fromX;	
unsigned    char fromY;	
unsigned    char fromZ;	
unsigned    char NofExits;	
unsigned    char toX;	
unsigned    char toY;
unsigned    char toZ;	
};

extern anim *animChunk = new anim[];

extern cubespecs *specs = new cubespecs[0];
extern unsigned int numofEntries;
extern teleport *teleportArray = new teleport[];
extern cubespecs *specsArray = new cubespecs[16384];
extern cels *celsArray = new cels[];
//extern cubespecs *specsArray;
//extern cubespecs specsArray[numofEntries];
//extern cubespecs *specsArray;
extern unsigned int cubeNinDataFile = 0;
extern char entryX, entryY, entryZ, entryRotation, exitX, exitY, exitZ;
//extern unsigned int levelEntryX, levelEntryY, levelEntryZ, levelExitX, levelExitY, levelExitZ, levelEntryRotation = 0;
extern string FileNameString;
extern unsigned short defaultTextureID = 0;
extern unsigned char backgroundsArray[0x100];
extern unsigned char torchesArray[0x100];
extern unsigned int torchesblock2[0x100];
extern unsigned int block2Size;

extern voxel *voxelArray = new voxel[16384];

// Initializing graph for teleports on the level 11a
//vector < vector <int> > teleportgraph = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

//extern vector<int[12]> teleportgraph;
//extern vector<vector<int>>;
//extern vector<vector<int>> teleportgraph = {{1}, {2}};
//{
//	{4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1}, 
//	{4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1}
//};


//extern unsigned int test = 0;

int DecToHex(int p_intValue)
{
    char *l_pCharRes = new (char);
    sprintf(l_pCharRes, "%X", p_intValue);
    int l_intResult = stoi(l_pCharRes);
//    cout << l_intResult<< "\n";
    return l_intResult;
}