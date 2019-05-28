#include <erl_nif.h>
#include "../go-p2pd.h"

static ERL_NIF_TERM start_daemon_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    char buf[1024];
    if (enif_get_string(env, argv[0], buf, sizeof(buf), ERL_NIF_LATIN1) < 1)
    {
        return enif_make_badarg(env);
    }
    startDaemon(buf);
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM stop_daemon_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    stopDaemon();
    return enif_make_atom(env, "ok");
}

static ErlNifFunc nif_funcs[] = {
    {"start", 1, start_daemon_nif},
    {"stop", 0, stop_daemon_nif}};

ERL_NIF_INIT(p2pd, nif_funcs, NULL, NULL, NULL, NULL)