#include "DemoClientImp.h"

static int run(int argc, char **argv, const xic::EnginePtr& engine)
{
	std::string serverAddr = (argc > 1) ? argv[1] : "";
	int rc = demo_client_doit(engine, serverAddr);
	engine->shutdown();
	engine->waitForShutdown();
	return rc;
}

int main(int argc, char **argv)
{
	SettingPtr setting = newSetting();
	setting->insert("xic.rlimit.nofile", "64");
	return xic::start_xic_st(run, argc, argv, setting);
}

