#ifndef _GROUPDBMODIFY_H
#define _GROUPDBMODIFY_H

enum
{
	PART_DELETE = 1,
	PART_UPDATEDEF,
	PART_UPDATEMOVE,
	PART_ADD,
	PART_UNGROUP,
};

typedef struct
{
	Mat4	mat;
	GroupDef	*def;
} PartInfo;

extern GroupDef *protect_parent;

typedef struct TrackerHandle TrackerHandle;

typedef enum {
	UM_NORMAL,		// normal
	UM_ORIGINAL,	// edit_orig
	UM_LIBRARY,		// edit_lib
	UM_COUNT
} UpdateMode;

// Generated by mkproto
GroupDef *groupPartFind(DefTracker *ref,int depth,int *idxs,PartInfo *part_info);
int checkoutDefFile(GroupDef *def);
int checkoutDefFileByName(const char *dir,const char *name);
int checkoutMapFile(const char *fname);
void groupdbDirtyTracker(DefTracker * tracker);
void groupdbAddToGroup(GroupDef * parent,GroupDef * child,int index);
void groupdbMoveObject(DefTracker *tracker, const char *name, Mat4 mat);
DefTracker * groupdbPasteObject(DefTracker * parent,const char * defName,Mat4 mat, UpdateMode mode, bool isCopy);
void groupdbDeleteMyChild(DefTracker * tracker);
void groupdbQueueDeleteObject(DefTracker * tracker);
void groupdbDeleteObject(DefTracker * tracker);
void groupdbAttachObject(TrackerHandle * handle,DefTracker * parent, UpdateMode mode);
void groupdbUngroupObject(TrackerHandle * handle, UpdateMode mode);
void groupdbReactivateDirtyRefs();
void groupdbEditTransactionBegin(const char *cmd);
void groupdbEditTransactionEnd();
DefTracker* groupdbInstanceTracker(DefTracker *tracker, UpdateMode mode);
bool groupdbHideForGameplay(GroupDef *def, int value);
#endif