function(request, plugin_cfg)
    local appid = plugin_cfg['appid']
    local appkey = plugin_cfg['appkey']
    local date = os.date("%Y-%m-%d %H:%M:%S")
    local nonce = request['request-id']
    if request['method'] == 'GET' then
        local req_param = request['param']
        local sgin_param = ''
        local sgin_str = ''

        local num = 0
        for i,v in pairs(request['param']) do
            sgin_param = sgin_param .. i .. ','
            sgin_str = sgin_str .. i .. '=' .. v .. '&'
            num = num + 1
            if num > 10 then
                break;
            end
        end
        if sgin_param ~= '' then
            sgin_param = string.sub(sgin_param, 1,-2)
            sgin_str = string.sub(sgin_str, 1,-2)
        else
            response.send(400, 'No parameter!')
        end

        req_param['appId'] = appid
        req_param['parameters'] = sgin_param
        req_param['timestamp'] = date
        req_param['signatureNonce'] = nonce
        signstr = sgin_str .. date .. nonce
        signature = hmac_sha256(appkey, signstr)
        req_param['signature'] = signature
    elseif request['method'] == 'POST' then
        local req_header = request['header']
        if not request['body'] or request['body'] == '' then
            response.send(400, "no request body!")
        end
        local data = request['body']
        local signstr = data..date..nonce
        signature = hmac_sha256(appkey, signstr)
        local header_info = {}
        header_info['appId'] = appid
        header_info['timestamp'] = date
        header_info['signatureNonce'] = nonce
        header_info['signature'] = signature
        for key, value in pairs(req_header) do
            local upperKey = string.upper(key);
            if 'APPID' == upperKey then
                req_header[key] = appid
                header_info['appId'] = nil
            end
            if 'TIMESTAMP' == upperKey then
                req_header[key] = date
                header_info['timestamp'] = nil
            end
            if 'SIGNATURENONCE' == upperKey then
                req_header[key] = nonce
                header_info['signatureNonce'] = nil
            end
            if 'SIGNATURE' == upperKey then
                req_header[key] = signature
                header_info['signature'] = nil
            end
        end
        req_header['Content-Type'] = 'application/json'
        for key, value in pairs(header_info) do
            req_header[key] = value
        end

    else
        response.send(400, "Invalid http method!")
    end
return request
