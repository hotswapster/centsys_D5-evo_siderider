# centsys_D5-evo_siderider
Monitor and control you Centsys D5-Evo gate controller

# Status

Work in progress

# Goals
- [ ] Open gate remotely
- Hold gate open at:
  - [ ] Current Position
  - [ ] Man gate
  - [ ] Full open
  - [ ] Lock Closed
- [ ] Emergency mode
- [ ] Doorbell mode
- [ ] Install a light that comes on with gate operation

# Equipment
## List
- Centsys D5-evo
- Microcontroller
- Communications back to house
- Relays (if required
  )

## Existing Installation

Sliding gate with beam sensor on inside of gate. No other sensors present. Has GPRS modem installed which no longer works as there is no 2G in this area. Might be possible to use some of the existing 2G interface wiring as there is an antenna installed.

Pictures can be found in `/pictures`.

## Centsys D5-evo
### I/O on Controller
From Left/Right or Top/Bottom

| #   |          Description          | Type                         | Connector                  | Group |
|:--- |:-----------------------------:|:---------------------------- |:-------------------------- | ----- |
| 1   |             Light             | dry contact                  | 2 pin green #1             | 1     |
| 2   |             Light             | dry contact                  | 2 pin green #2             | 1     |
| 3   |     Encoder/Origin switch     | Multipin plug                | 6 pin white                | 2     |
| 4   |          Safe Common          | Common                       | 3 pin green #1             | 3     |
| 5   |          Aux 12V Out          | +12VDC                       | 3 pin green #2             | 3     |
| 6   | Safety Close (Safe to close)  | Input                        | 3 pin green #3             | 3     |
| 7   |   Safety Open (Lock Closed)   | Input                        | 10 pin green #1            | 3     |
| 8   |     Lck/Stp - Locks Gate      | N/C Switch Input             | 10 pin green #2            | 4     |
| 9   | Trg - Trigger - Activate gate | N/O Switch Input             | 10 pin green #3            | 4     |
| 10  |     Ped - Pedestrian open     | N/O Switch Input             | 10 pin green #4            | 4     |
| 11  |              Com              | Common for 8, 9, 10          | 10 pin green #5            | 4     |
| 12  |        FRX (Free exit)        | N/O switch Input             | 10 pin green #6            | 4     |
| 13  |              Aux              | N/O switch                   | 10 pin green #7            | 4     |
| 14  |            Status             | LED Output                   | 10 pin green #8            | 4     |
| 15  |              Com              | Common for 12, 13, 14        | 10 pin green #9            | 4     |
| 16  |            Aux I/O            | Input to trigger Light Relay | 10 pin green #10           | 4     |
| 17  |             Motor             | Power                        | 4 pin green #1             | 5     |
| 18  |             Motor             | Power                        | 4 pin green #2             | 5     |
| 19  |     Battery 12V negative      | Battery Circuit negative     | 4 pin green #3             | 5     |
| 20  |      Battery 1V positive      | Battery Circuit positive     | 4 pin green #4             | 5     |
| 21  |            Charger            | Power supply                 | 2 pin white                | 6     |
| 22  |          Serial port          | UART                         | Hidden under circuit board | -     |

![](/pictures/existing_controller.jpg)


### I/O on GPRS unit
From Left/Right

| #   | Description | Type             | Connector      | Group |
|:--- |:-----------:|:---------------- |:-------------- | ----- |
| 1   |   Relay 2   | dry contact  N/O | 3 pin white #1 | 1     |
| 2   |   Relay 2   | dry contact COM  | 3 pin white #2 | 1     |
| 3   |   Relay 2   | dry contact N    | 3 pin white #3 | 1     |
| 4   |   Relay 1   | dry contact  N/O | 3 pin white #1 | 2     |
| 5   |   Relay 1   | dry contact COM  | 3 pin white #2 | 2     |
| 6   |   Relay 1   | dry contact N    | 3 pin white #3 | 2     |
| 7   |    Power    | 230VAC Phase     | 2 pin white    | 3     |
| 8   |    Power    | 230VAC Neutral   | 2 pin white    | 3     |

![](/pictures/existing_GPRS.jpeg)

## Interfacing to gate controller

### Serial
There is a serial port underneath the circuit board however no investigation has been done with this yet. After standard wiring has been used for this automation, the serial port may be investigated further.
![UART](/pictures/existing_pcb_serial_port_crop.jpeg)


### Gate Status using LED

The gate status is indicated by an LED. This LED is also wired to output as the table above. Wiring this to a micro controller can decode the flashes into the sates shown in the table below:

| LED State                       |            Description             |
|:------------------------------- |:----------------------------------:|
| Off                             |           Gate is closed           |
| On                              |  Gate is partially or fully open  |
| Continuous slow flash           |          Gate is opening           |
| Continuous fast flash           |          Gate is closing           |
| One flash every two seconds     | Pillar light override is activated |
| Two flashes very two seconds    |          No mains present          |
| Three flashes every two seconds |       Battery voltage is low       |

### Controller IO
Inputs:   6
<br>Outputs:  4
<br>UART: 1

Consideration required for other input device such as keypad or fingerprint reader.

Communications to house required.

| Description     | In/Out | pin |
|:--------------- |:------:| --- |
| Beam block      | Input  |     |
| Gate closed     | Input  |     |
| Gate open       | Input  |     |
| Status Closed   | Input  |     |
| Doorbell - Ding | Input  |     |
| Doorbell - Door | Input  |     |
| TX              | UART1  |     |
| RX              | UART1  |     |
| Disable Inputs  | Output |     |
| Lock open       | Output |     |
| trigger         | Output |     |
| light           | Output |     |


# Communications
The gate is approx 10 metres from the house and has mains power available. Being the main entrance to the house, wifi is not the preferred communication as it is not deemed reliable in the event of an emergency. Two main alternatives are considered:
- Ethernet over Power line
- Serial over power line

## Ethernet over Power (Powerline adapter)
Ethernet over power is easy to achieve however te hardware is fairly bulky.

## Serial over Power (PLM/PLC)

Some available boards in the market:
- STEVAL-IHP005V1 at $AUD150 (and need one master plus one per node)
- NXP USA Inc. OM13313,598 but now obsolete
- Jarvie board are available at $65 Australian per [modem](https://www.tindie.com/products/jarvie/smart-home-power-line-modem-demo-board/)
- OR cheap and nasty...just the way I like it [KQ130F](https://www.aliexpress.com/item/1005001498852968.html?spm=a2g0s.9042311.0.0.4f0e4c4d9PnOt5) at $AUD13 each including shipping

KQ130F was chosen as I also have garden lights I'd like to control
