// AccountDB.h: interface for the AccountDB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCOUNTDB_H__7725EE80_1062_4DB9_BAC2_C983075E98E1__INCLUDED_)
#define AFX_ACCOUNTDB_H__7725EE80_1062_4DB9_BAC2_C983075E98E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GlobalAuth.h"
#include "lock.h"
#include "IOSocket.h"

class AccountDB  
{
private:
	UserMap usermap;
	CLock	m_lock;

public:
	char AboutToPlay( int uid, char *account, int time_left, int loginflag, int warnflag, int md5key, CSocketServerEx *s , ServerId serverid, int stat, int queueLevel, int loyalty, int loyaltyLegacy);
	char CheckUserTime( int Uid, int *RemainTime );
	char CheckPersonalPayStat( CSocketServerEx *pSocket, LoginUser *lu, int uid );

	AccountDB();
	virtual ~AccountDB();
	
	bool KickAccount( int uid, char reason, bool sendmsg = true );
	bool RegAccount( LoginUser *loginuser, int uid, CSocketServerEx *sEx, int remainTime, int quotaTime );
	bool RegAccountByServer( LoginUser *loginuser, int uid, CSocketServer *s, int remainTime, int quotaTime );
	int checkInGame( int uid, int md5key );
	void FinishedQueue( int uid );
	bool logoutAccount( const char *name );
	bool logoutAccount( int uid, int md5key);
	bool logoutAccount( int uid ); // L2를 위해 임시로 만든 Function이다. 
	bool removeAccount( int uid , char *account);
	bool removeAccountPreLogIn( int uid, SOCKET s );
	bool recordGamePlayTime( int uid, ServerId serverid);
	bool quitGamePlay( int uid, int usetime, ServerId serverID);
	void transferPlayer(int uid, unsigned char shard);
	int UpdateSocket( int uid, SOCKET s, int md5key, ServerId serverid);
	void TimerCallback( int uid );
	SOCKET FindSocket( int uid , bool SetTimer = false);
	void RemoveAll(ServerId s);
	int GetUserNum( void )
	{
		int num=0;
		m_lock.Enter();
		num = (int) usermap.size();
		m_lock.Leave();

		return num;
	}
    bool FindAccount( int uid, char *account, ServerId & lastServer, int regions[MAX_REGIONS] );	
	bool FindAccount( int uid, char *account, int *loginflag, int *warnflag, int *pay_stat, int *md5key, int *queueLevel, int *loyalty, int *loyatyLegacy );
	bool WriteUserData( int uid );
	// Logout시에 기록을 남기는 Function이며 모든 로그 아웃시에는 이 Function이 불리도록 한다.

	//Adding in additional information so we can do more complete activity logging in the DB
	bool RecordLogout( char reasoncode, int uid, time_t loginTime, time_t enteredQueueTime, ServerId lastWorld, in_addr LastIP, int LastGame, const char *account, int stat, int ssn1, int ssn2, char gender, int age, int cdkind );
	
	
	// 정량제 체크로 로그인이 가능한지 확인한다. 
	char UserTimeLogin( int uid, LoginUser *lu, int *RemainTime );
	SOCKET FindSocket( int uid , ServerId serverid, bool SetTimer, ServerId *previousServer, char *account);
	// IP로그인시에 사용할 계정정보를 가져올 루틴을 따로 만든다. 
	bool GetAccountInfo( int uid, char *account, int *loginflag, int *warnflag, int *md5key,  SOCKET *s);
	// IPStop시에 계정 정보를 가져오도록 한다. 
	bool GetAccountInfoForIPStop( int uid, char *account, int *stat, in_addr *loginip, time_t *loginTime );
};

extern AccountDB accountdb;

#endif // !defined(AFX_ACCOUNTDB_H__7725EE80_1062_4DB9_BAC2_C983075E98E1__INCLUDED_)
