# lpc55-tiny
Sample project using [`tiny`](https://github.com/ryanplusplus/tiny) and [LPCXpresso55S16](https://www.nxp.com/design/development-boards/lpcxpresso-boards/lpcxpresso55s16-development-board:LPC55S16-EVK).

## Setup
- Install `gcc-arm-none-eabi`
- Install [J-Link](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)

## Use
### Compile
```shell
make -f <target>.mk
```

### Clean
```shell
make -f <target>.mk clean
```

### Erase via SWD
```shell
make -f <target>.mk erase
```

### Flash via SWD
```shell
make -f <target>.mk upload
```

## Resources
- [LPCXpresso55S16 User's Guide](https://www.nxp.com/docs/en/user-guide/UMLPCXPRESSO55S16.pdf)
- [LPC55S1x Datasheet](https://www.nxp.com/docs/en/nxp/data-sheets/LPC55S1x_PDS.pdf)
- [LPC55S1x Reference Manual](https://cache.nxp.com/secured/assets/documents/en/nxp/user-guides/UM11295.pdf?__gda__=1602814947_a1a9c409ff7ad0b353bffae742cf1662&fileExt=.pdf)
