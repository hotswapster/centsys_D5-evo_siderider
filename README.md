Installation# centsys_D5-evo_siderider
Monitor and control you Centsys D5-Evo gate controller

# Status

Work in progress

# Goals
- [ ] Open gate remotely
- [ ] Hold gate open at:
  - [ ] Current Position
  - [ ] Man gate
  - [ ] Full open
  - [ ] Lock Closed
- [ ] Emergency mode
- [ ] Doorbell mode

# Equipment
## List
- Centsys D5-evo
- Microcontroller
- Wifi comms
- Relays

## Existing Installation

Sliding gate with beam sensor on inside of gate. No other sensors present. Has GPRS modem installed which no longer works as there is no 2G in this area. Might be possible to use some of the existing 2G interface wiring as there is an antenna installed.

## Centsys D5-evo
### I/O on Controller
From Left/Right or Top/Bottom

| #   |      Description      | Type                     | Connector        | Group |
|:--- |:---------------------:|:------------------------ |:---------------- | ----- |
| 1   |         Light         | dry contact              | 2 pin green #1   | 1     |
| 2   |         Light         | dry contact              | 2 pin green #2   | 1     |
| 3   | Encoder/Origin switch | Multipin plug            | 6 pin white      | 2     |
| 4   |      Safe Common      | Common                   | 3 pin green #1   | 3     |
| 5   |      Aux 12V Out      | +12VDC                   | 3 pin green #2   | 3     |
| 6   |     Safety Close      | Input                    | 3 pin green #3   | 3     |
| 7   |      Safety Open      | Input                    | 10 pin green #1  | 3     |
| 8   |        Lck/Stp        | N/C Switch Input         | 10 pin green #2  | 4     |
| 9   |          Trg          | N/O Switch Input         | 10 pin green #3  | 4     |
| 10  |          Ped          | N/O Switch Input         | 10 pin green #4  | 4     |
| 11  |          Com          | Common for 8, 9, 10      | 10 pin green #5  | 4     |
| 12  |          FRX          | N/O switch               | 10 pin green #6  | 4     |
| 13  |          Aux          | N/O switch               | 10 pin green #7  | 4     |
| 14  |        Status         | LED OUtput               | 10 pin green #8  | 4     |
| 15  |          Com          | Common for 12, 13, 14    | 10 pin green #9  | 4     |
| 16  |        Aux I/O        | unknown                  | 10 pin green #10 | 4     |
| 17  |         Motor         | Power                    | 4 pin green #1   | 5     |
| 18  |         Motor         | Power                    | 4 pin green #2   | 5     |
| 19  | Battery 12V negative  | Battery Circuit negative | 4 pin green #3   | 5     |
| 20  |  Battery 1V positive  | Battery Circuit positive | 4 pin green #4   | 5     |
| 21  |        Charger        | Power supply             |                  |       |
|     |                       |                          |                  |       |
