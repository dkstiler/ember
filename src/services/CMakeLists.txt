add_library(services
        config/ConfigListener.cpp
        config/ConfigListenerContainer.cpp
        config/ConfigService.cpp
        config/ConfigConsoleCommands.cpp
        input/Input.cpp
        input/InputCommandMapper.cpp
        input/InputService.cpp
        input/EmberIcon.h
        input/IInputAdapter.h
        logging/ErisLogReciever.cpp
        logging/LoggingService.cpp
        metaserver/MetaserverService.cpp
        scripting/ScriptingService.cpp
        server/AccountAvailableState.cpp
        server/AvatarTransferInfo.cpp
        server/ConnectedState.cpp
        server/ConnectingState.cpp
        server/Connection.cpp
        server/EnteredWorldState.cpp
        server/LocalServerAdminCreator.cpp
        server/LoggedInState.cpp
        server/NonConnectedState.cpp
        server/OOGChat.cpp
        server/ServerService.cpp
        server/ServerServiceConnectionListener.cpp
        server/TransferInfoStringSerializer.cpp
        server/IConnectionListener.h
        server/IState.h
        server/ServerServiceSignals.h
        server/StateBase.h
        serversettings/ServerSettings.cpp
        serversettings/ServerSettingsCredentials.cpp
        sound/SoundBinding.cpp
        sound/SoundGeneral.cpp
        sound/SoundInstance.cpp
        sound/SoundSample.cpp
        sound/SoundService.cpp
        sound/SoundSource.cpp
        wfut/WfutService.cpp
        wfut/WfutSession.cpp
        EmberServices.cpp)


wf_generate_lua_bindings(bindings/lua/EmberServices)


