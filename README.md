When setting up an MQTT connection, 

there will be an issue connecting to the mqqt. 

Go to command prompt and type :
netsh interface portproxy add v4tov4 listenaddress=192.168.66.164 listenport=1883 connectaddress=127.0.0.1 connectport=1883
