# SDAT(Stream Device AT set of C)

详细使用方法和同作者仓库[StreamDeviceAT]([https://github.com/nayooooo/arduino-at.git](https://github.com/nayooooo/StreamDeviceAT.git))下的README文档类似。

# 资源使用

此节讨论SDAT在不同设备上的资源需要。

## STM32F103

在给STM32F103单片机移植AT解析器时，我使用了USART1作为解析器的输入输出设备，为了研究解析器的资源使用情况，我将使用实际使用时产生的map作为分析依据，得出以下结论。

| 指令条数 | ROM(KB) | RAM(KB) |
| :-: | :-: | :-: |
| 2 | 2.80 | 0.28 |
| 3 | 3.02 | 0.29 |
