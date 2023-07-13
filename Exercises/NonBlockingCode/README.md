[<- Tilbake](/README.md)

# NonBlockingCode

- [delay()](delay/delay.ino)
  - Du skal ikke endre koden i loop() eller updateLed(). Innleveringer som gjør dette blir ikke godkjent.
- [for()](ForAsWhile/ForAsWhile.ino)
  - Produser kode som har tilsvarende funksjonalitet, men bruker en while-løkke istedenfor en for-løkke.
- [while()](IfAsWhile/IfAsWhile.ino)
  - Produser kode som har tilsvarende funksjonalitet, men bruk if-setninger istedenfor while-løkker.

## Tilstandsmaskiner

### Kjør disse demoene og reflekter over hvordan de fungerer

- [Ingen](NoStateMachine/NoStateMachine.ino)
- [If](IfStateMachine/IfStateMachine.ino)
- [Switch](SwitchStateMachine/SwitchStateMachine.ino)
- [Inkrementerende](IncrementStateMachine/IncrementStateMachine.ino)

```
Refleksjon:
Denne typen tilstandsmaskin gjør det mulig å ...
```

### Sammenlign disse demoene

Reflekter over likheter og forskjeller. Hvorfor produserer de ikke samme resultat i seriemonitoren?

- [Betinget](LingeringStateMachine/LingeringStateMachine.ino)
- [Betinget Uten Tilstandsmaskin](BlockingLingeringStateMachine/BlockingLingeringStateMachine.ino)

```
Refleksjon:
Disse to sketchene er nermest funksjonelt like, med unntak av ...
```

### Løs problemstillingene
- [Tidsbasert](TimedStateMachine/TimedStateMachine.ino)
- [Tidsbasert Uten Tilstandsmaskin](BlockingTimedStateMachine/BlockingTimedStateMachine.ino)

```
Refleksjon:
Ved å bruke tilstandsmaskiner for å kjøre oppgaver som
må vente en gitt tid før de fortsetter, kan vi også ...
```
