# Arduino VSCode Extension

## Forberedelse

For at alle skal ha samme versjon (slik at vi kan garantere et fungerende øvingsopplegg), er det ønskelig å fjerne eksisterende installasjoner av Arduino IDE og Arduino CLI.

- Avinstaller alle installerte versjoner av Arduino IDE
- Avinstaller Arduino CLI

## Installer Arduino CLI

Arduino CLI er et kommandolinjeverktøy som bland annet analyserer koden din for feil, kompilerer/konverterer koden din til maskinkode og laster opp koden din til det fysiske brettet. Dere skal ikke bruke dette verktøyet direkte, men VSCode Arduino extension er avhengig av disse verktøyene for å fungere.

### Mac

- Åpne VSCode
- Åpne terminalen `(Terminal -> New Terminal)`
- Kjør disse kommandoene ved å lime de inn i terminalen som dukket opp nederst på skjermen ved å lime de inn og trykke enter:
  ```bash
  brew update
  brew install arduino-cli
  ```
