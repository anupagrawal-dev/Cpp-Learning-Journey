#include "Log.h"

#define DEBUG    1
#define INFO     2
#define WARNING  3
#define	ERROR    4

class Logger{
	int m_logLevel;

	public:
    void setLogLevel(int x)
    {
        m_logLevel = x;
    }

	void debugLog(const char *data)
	{
        if(m_logLevel <= DEBUG)
		    cout<<"[DEBUG] "<<data<<endl;
	}
	void infoLog(const char *data)
	{
        if(m_logLevel <= INFO)
		    cout<<"[INFO] "<<data<<endl;
	}
	void warningLog(const char *data)
	{
        if(m_logLevel <= WARNING)
		    cout<<"[WARNING] "<<data<<endl;
	}
	void errorLog(const char *data)
	{
        if(m_logLevel <= ERROR)
		    cout<<"[ERROR] "<<data<<endl;
	}

    void test()
    {
        static int Mylevel = 5;

        cout<<"Level = "<<Mylevel<<endl;
        Mylevel++;
    }
};

int main()
{
	Logger log;

    log.test();
    log.test();
    log.test();

	log.setLogLevel(WARNING);

    log.infoLog("Hi");
    log.debugLog("Hello");
    log.warningLog("How r u");
    log.errorLog("Ok by");
}
