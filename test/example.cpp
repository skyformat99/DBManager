
#include "DBM.hpp"
#include "singleton.hpp"
#include <unistd.h>
int main()
{
    set_log_level(logger_iface::log_level::debug);

    RedisConnInfo info = RedisConnInfo("127.0.0.1", "6380", "");

    DBManager *dbm = Singleton<RedisManager>::Instance();

    int index = dbm->add(&info);
    if (!index)
    {
        __LOG(error, "add return fail!");
    }

    // do some work
    sleep(3);

    dbm->del(&info);

    Singleton<RedisManager>::DestroyInstance();
}
