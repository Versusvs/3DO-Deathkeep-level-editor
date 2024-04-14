static FILE *inputfile, *VirtRdOBJ; // Файл трека
static char *infilename; // TRI filename
static char *famfilename; // Textures file
static char *FamFileName3DO; // 3DO famfile with textures

#define Swap4Bytes(val) val = ( (((val) >> 24) & 0x000000FF) | (((val) >> 8) & 0x0000FF00) | (((val) <<  8) & 0x00FF0000) | (((val) << 24) & 0xFF000000) )
#define Swap8Bytes(val) ( (((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | (((val) >> 24) & 0x0000000000FF0000) | (((val) >>  8) & 0x00000000FF000000) | (((val) <<  8) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | (((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000) )
#define Swap2Bytes(val) ( (((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00) )


// Virtual road flags:
// Unimplemented:
		const char LANE_SPLIT = 0;  // Used in Alpine, Coastal tracks when the road widens. vertices should be moved to the right. 
		const char LANE_REJOIN = 2;  //Used in Alpine, Coastal tracks when the road narrows. vertices should be moved to the right
// Implemented:
		// The next 3 properties are interesting!  If set, either the last terrain strip on the right or left is detached and 
		// placed between the specified points.  This is how the tunnels in Vertigo Ridge and Coastal (and Alpine 3) are constructed.
		// For the meaning of A2,A9 etc, refer to /NFSSpecs.txt
		const char RIGHT_TUNNEL = 7;
		const char LEFT_TUNNEL = 9;

const double pi = 3.1415926535897932384626433832795;
const int SCALE = 1000000; // Scale for the Object file
const int SCALETRACK = 10000; // Scale for the width of the track (Unused)
const int SCALETILT = 120; // Scale for the width of the track
const float SCALEOBJECT = 0.068; // Scale for the objects
const int SCALE3D = 235; // Scale for the 3D objects
const int SCALE3DObjUVMap = 75; // Scale for the 3D objects (UV mapping)
const float SCALEROTATEOBJECT = 10; // Scale for the object rotation
const int SCALEOBJ = 3800; // Scale for the object placement
const int numVirtRdIndexes = 2400; // Quantity of the Virtual Road records
const int numOBJIndexes = 1000; // Quantity of the Objects records
const float FENCEHEIGHT = 0.12; // Fence height (scenery block)

#define BUFFER_SIZE 0x400000UL
#define F_EPS 1e-4

typedef struct {// Struct for the 3Dobject 
	int size1;
	int size8;
	} Obj3Dparams_t;

static Obj3Dparams_t *Obj3Dparams;

//static int size13DObj;
//static int size83DObj;

#define degreesToRadians(angleDegrees) ((angleDegrees) * pi / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / pi)


#if 0;
/////// FOR checking intersections
class Vector3{
public:
  float x,y,z;
  Vector3(){}
  Vector3(float _x, float _y, float _z){x=_x; y=_y; z=_z;}
  float len2(){return x*x + y*y + z*z;}
  float len(){return sqrt(len2());}
  void normalize(){float l=sqrt(x*x+y*y+z*z); x/=l; y/=l; z/=l;}
  float operator * (Vector3 arg){return x*arg.x + y*arg.y + z*arg.z;}
  Vector3 operator = (Vector3 src){x=src.x; y=src.y; z=src.z; return *this;}
  Vector3 operator + (Vector3 arg){Vector3 tmp(x+arg.x, y+arg.y, z+arg.z); return tmp;}
  Vector3 operator - (Vector3 arg){Vector3 tmp(x-arg.x, y-arg.y, z-arg.z); return tmp;}
  Vector3 operator * (float l){Vector3 tmp(x*l, y*l, z*l); return tmp;} //scalar multiply
};
 
/*
 * ray_st, ray_dir - start point and direction of the ray
 * sp_cen, sp_rad - center point and radius of the sphere
 * res1, res2 - intersection points (if there is less than 2 intersections - no changes)
 * return value - number of intersections
 */


int find_intersection(Vector3 ray_st, Vector3 ray_dir, Vector3 sp_cen, float sp_rad, Vector3 &res1, Vector3 &res2){
  Vector3 middle; //middle point between intersections
  Vector3 dist; //vector from center of sphere to ray start
  Vector3 dpos; //vector from ray_st to sp_cen
  float len2; //square of distance from center of sphere to ray
  ray_dir.normalize();
  sp_rad *= sp_rad;
  
  dpos = sp_cen - ray_st;
  middle = ray_st + ray_dir*(ray_dir*dpos);
  len2 = (middle - sp_cen).len2();
  
  if(len2 > sp_rad)return 0;
  if(fabs( len2 - sp_rad )<F_EPS){
    res1 = middle;
    return 1;
  }
  len2 = sqrt(sp_rad - len2);
  //now len2 is distance, not its square
  res1 = middle - ray_dir*len2;
  res2 = middle + ray_dir*len2;
  return 2;
}
#endif;