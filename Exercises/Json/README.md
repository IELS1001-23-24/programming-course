[<- Tilbake](/README.md)

# Json

- [Dokumentasjon](/doc/json/README.md)
- [ArduinoJson](https://arduinojson.org/)

Denne oppgaven bruker en spesiallaget chip for wokwi skrevet i rust. De som er interesserte kan se kildekoden [her](https://github.com/IELS1001-23-24/wokwi-json-chip/blob/main/src/lib.rs).

## Send Json med ArduinoJson

Fullfør koden slik at den sender oppstartsmeldingen til chipen.

- [Kode](send/send.ino)

## Motta Json med ArduinoJson

Fullfør koden slik at den oppdaterer lysdioden med verdien fra feltet `"position"` mottatt i json format fra chipen.

- [Kode](receive/receive.ino)
