/**/

#include "EPosix.h"

#include "EPosixClientSocket.h"
#include "EPosixClientSocketPlatform.h"

#include "Contract.h"
#include "Order.h"

///////////////////////////////////////////////////////////
// member funcs
EPosix::EPosix()
	: m_pClient(new EPosixClientSocket(this))
	, m_orderId(0)
{
}

EPosix::~EPosix()
{
}

bool EPosix::connect(const char *host, unsigned int port, int clientId)
{
	// trying to connect
	printf( "Connecting to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	bool bRes = m_pClient->eConnect( host, port, clientId, /* extraAuth */ false);

	if (bRes) {
		printf( "Connected to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);
	}
	else
		printf( "Cannot connect to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	return bRes;
}

void EPosix::disconnect() const
{
	m_pClient->eDisconnect();

	printf ( "Disconnected\n");
}

bool EPosix::isConnected() const
{
	return m_pClient->isConnected();
}


//////////////////////////////////////////////////////////////////
// methods
void EPosix::reqCurrentTime()
{

}

void EPosix::placeOrder()
{
	Contract contract;
	Order order;

	contract.symbol = "AAPL";
	contract.secType = "STK";
	contract.exchange = "SMART";
	contract.currency = "USD";
	contract.primaryExchange = "NASDAQ";

	order.action = "BUY";
	order.totalQuantity = 1000;
	order.orderType = "MKT";
	order.transmit = true;
//order.lmtPrice = 0.01;

	m_pClient->placeOrder( m_orderId, contract, order);
	
	printf( "Placing Order %ld: %s %ld %s\n", m_orderId, order.action.c_str(), order.totalQuantity, contract.symbol.c_str());
}

void EPosix::cancelOrder()
{
	printf( "Cancelling Order %ld\n", m_orderId);

	m_pClient->cancelOrder( m_orderId);
}

///////////////////////////////////////////////////////////////////
// events
void EPosix::orderStatus( OrderId orderId, const IBString &status, int filled,
	   int remaining, double avgFillPrice, int permId, int parentId,
	   double lastFillPrice, int clientId, const IBString& whyHeld)

{
	if( orderId == m_orderId) {

		printf( "Order: id=%ld, status=%s\n", orderId, status.c_str());
	}
}

void EPosix::nextValidId( OrderId orderId)
{
	m_orderId = orderId;

}

void EPosix::currentTime( long time)
{

}

void EPosix::error(const int id, const int errorCode, const IBString errorString)
{
//	printf( "Error id=%d, errorCode=%d, msg=%s\n", id, errorCode, errorString.c_str());

	if( id == -1 && errorCode == 1100) // if "Connectivity between IB and TWS has been lost"
		disconnect();
}

void EPosix::tickPrice( TickerId tickerId, TickType field, double price, int canAutoExecute) {}
void EPosix::tickSize( TickerId tickerId, TickType field, int size) {}
void EPosix::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
											 double optPrice, double pvDividend,
											 double gamma, double vega, double theta, double undPrice) {}
void EPosix::tickGeneric(TickerId tickerId, TickType tickType, double value) {}
void EPosix::tickString(TickerId tickerId, TickType tickType, const IBString& value) {}
void EPosix::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
							   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) {}
void EPosix::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState& ostate) {}
void EPosix::openOrderEnd() {}
void EPosix::winError( const IBString &str, int lastError) {}
void EPosix::connectionClosed() {}
void EPosix::updateAccountValue(const IBString& key, const IBString& val,
										  const IBString& currency, const IBString& accountName) 
										  {

										  
										  }
void EPosix::updatePortfolio(const Contract& contract, int position,
		double marketPrice, double marketValue, double averageCost,
		double unrealizedPNL, double realizedPNL, const IBString& accountName){}
void EPosix::updateAccountTime(const IBString& timeStamp) {}
void EPosix::accountDownloadEnd(const IBString& accountName) 
{

}
void EPosix::contractDetails( int reqId, const ContractDetails& contractDetails) {}
void EPosix::bondContractDetails( int reqId, const ContractDetails& contractDetails) {}
void EPosix::contractDetailsEnd( int reqId) {}
void EPosix::execDetails( int reqId, const Contract& contract, const Execution& execution) {}
void EPosix::execDetailsEnd( int reqId) {}

void EPosix::updateMktDepth(TickerId id, int position, int operation, int side,
									  double price, int size) {}
void EPosix::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
										int side, double price, int size) {}
void EPosix::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) {}
void EPosix::managedAccounts( const IBString& accountsList) {}
void EPosix::receiveFA(faDataType pFaDataType, const IBString& cxml) {}
void EPosix::historicalData(TickerId reqId, const IBString& date, double open, double high,
									  double low, double close, int volume, int barCount, double WAP, int hasGaps) {}
void EPosix::scannerParameters(const IBString &xml) {}
void EPosix::scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) {}
void EPosix::scannerDataEnd(int reqId) {}
void EPosix::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
								   long volume, double wap, int count) {}
void EPosix::fundamentalData(TickerId reqId, const IBString& data) {}
void EPosix::deltaNeutralValidation(int reqId, const UnderComp& underComp) {}
void EPosix::tickSnapshotEnd(int reqId) {}
void EPosix::marketDataType(TickerId reqId, int marketDataType) {}
void EPosix::commissionReport( const CommissionReport& commissionReport) {}
void EPosix::position( const IBString& account, const Contract& contract, int position, double avgCost) {}
void EPosix::positionEnd() {}
void EPosix::accountSummary( int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& curency) {}
void EPosix::accountSummaryEnd( int reqId) {}
void EPosix::verifyMessageAPI( const IBString& apiData) {}
void EPosix::verifyCompleted( bool isSuccessful, const IBString& errorText) {}
void EPosix::displayGroupList( int reqId, const IBString& groups) {}
void EPosix::displayGroupUpdated( int reqId, const IBString& contractInfo) {}
