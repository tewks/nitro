#ifndef ERR_H
#define ERR_H

typedef enum {
    NITRO_ERR_NONE,
    NITRO_ERR_ERRNO,
    NITRO_ERR_ALREADY_RUNNING,
    NITRO_ERR_NOT_RUNNING,
    NITRO_ERR_TCP_LOC_NOCOLON,
    NITRO_ERR_TCP_LOC_BADPORT,
    NITRO_ERR_TCP_LOC_BADIPV4,
    NITRO_ERR_PARSE_BAD_TRANSPORT,
    NITRO_ERR_TCP_BAD_ANY,
    NITRO_ERR_EAGAIN,
    NITRO_ERR_NO_RECIPIENT,
    NITRO_ERR_ENCRYPT,
    NITRO_ERR_DECRYPT,
    NITRO_ERR_INVALID_CLEAR,
    NITRO_ERR_MAX_FRAME_EXCEEDED,
    NITRO_ERR_BAD_PROTOCOL_VERSION,
    NITRO_ERR_DOUBLE_HANDSHAKE,
    NITRO_ERR_NO_HANDSHAKE,
    NITRO_ERR_BAD_SUB,
    NITRO_ERR_BAD_HANDSHAKE,
    NITRO_ERR_INVALID_CERT,
    NITRO_ERR_BAD_INPROC_OPT,
    NITRO_ERR_BAD_SECURE,
    NITRO_ERR_INPROC_ALREADY_BOUND,
    NITRO_ERR_INPROC_NOT_BOUND,
    NITRO_ERR_INPROC_NO_CONNECTIONS,
    NITRO_ERR_SUB_ALREADY,
    NITRO_ERR_SUB_MISSING,
} NITRO_ERROR;

int nitro_set_error(NITRO_ERROR e);
char *nitro_errmsg(NITRO_ERROR error);
NITRO_ERROR nitro_error();
void nitro_clear_error();
int nitro_has_error();
void nitro_error_log_handler(int err, void *baton);
void nitro_err_start();
void nitro_err_stop();

#endif /* ERR_H */
