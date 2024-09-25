::http::add-handler OPTIONS /app/client-closing {
    ::http::respond [::http::make-options-response {} 0 {} $request]
}

::http::add-handler POST /app/client-closing {
    # There probably should be some key generation and exchange between the
    # client and server so a request from a random HTTP client is rejected. For
    # now, just ack the req.
    ::http::respond [::http::make-bin-svc-response {} {} $request]
    # Assumption: the sole client closed, so it's time to shutdown the OpenOCD
    # server.  (Multiple clients would require tracking, or at least counting,
    # and shuting down the server when the last client closes.  Or maybe the
    # server should always stay up even when no client exist.  That, however, is
    # a problem for the future, if ever.  Right now, there's a 1-to-1
    # relationship between clients and servers, and each pair is tightly
    # coupled.)
    #
    # Calling OpenOCD's shutdown makes the http server emit an handled critical
    # error with an emtpy message.  But that's OK since the program exists with
    # 0 status.
    shutdown
}
