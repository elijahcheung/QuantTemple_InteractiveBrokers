#include "EPosixClientSocket.h"
#include "EPosix.h"
#include "QuantTrade.h"
#include <unistd.h>
#include <IBString.h>
#include <signal.h>
#include <exception>

EPosix m_ePosix;

//exception class
class InterruptException:public std::exception
{
public:
	InterruptException(int s):S(s)
	{
		std::cout<<"Closing Client Socket.\n"<<std::endl;
		m_ePosix.disconnect();
		
	}

private:
	int S;
};

void my_handler(int s)
{
	throw InterruptException(s);

}


int main(int argv,char** argc)
{

	//handler
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT,&sigIntHandler,NULL);
	sigaction(SIGTSTP,&sigIntHandler,NULL);


	const char* host = "127.0.0.1";
	int port = 4001;
	int clientId = 0;
	const IBString acctCode = "DU222124";

	try
	{
		m_ePosix.connect(host,port,clientId);
		if(m_ePosix.isConnected())
		{
//   		client.returnAccountData(acctCode);
			QuantTrade *m_quantTrade = new QuantTrade();
			printf("start QuantTrade Service.\n");
			for(;;)
			{
//				client.placeOrder();
				sleep(1);
			}
		}
	}catch(InterruptException& e)
	{
			
	}	
	return 0;
}