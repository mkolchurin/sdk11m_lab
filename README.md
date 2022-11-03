# Лабораторные работы SDK-1.1m

## Учебные материалы

1. [Учебное пособие и задания к лабораторным работам](https://disk.yandex.ru/i/mNxvWKNR1thdyA)
1. [Электрическая принципиальная схема и другие документы по SDK-1.1M](https://disk.yandex.ru/d/GucbJAt-4ZunLA)
1. [Примеры проектов для SDK-1.1M](https://github.com/lmtspbru/SDK-1.1M)

## Условия выполнения работ на 4

1. Выполнить в соответствии с указаниями учебного пособия

## Условия выполнения работ на 5 (дополнительно к условиям учебного пособия)

### Для лабораторной работы #1

1. Для создания проекта и настройки подсистемы тактирования разрешено использовать кодогенерацию STM32CubeIDE и CubeMX (т.е. все блоки относящиеся к RCC, включая тактирование периферии);
1. **Для управления периферийными блоками использовать операции записи и чтения регистров из памяти микроконтроллера**

```Пример базовой работы с регистрами представлен в /samples/HelloWorld_make/```

#### Допустимое использование библиотек STM32 HAL/LL

```C
// Допустимо:
// включение тактирования блока GPIOB
__HAL_RCC_GPIOB_CLK_ENABLE();
// Конфигурация системы тактирования
HAL_RCC_ClockConfig();
uint32_t HAL_GetTick(void);
//... 

// Недопустимо:
HAL_GPIO_WritePin(...);
// и подобные
```

### Для лабораторной работы 2-4

1. Использование библиотек STM32HAL/LL недопустимо

### Необходимая документация

1. [RM0090 Reference manual](https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
2. [PM0214 Programming manual](https://www.st.com/resource/en/programming_manual/pm0214-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf)

## Инструменты разработки и отладки

1. STM32CubeIDE

Ссылки на скачивание

[Windows](https://disk.yandex.ru/d/G94ssKUJKjApeQ)

Linux

[deb](https://disk.yandex.ru/d/whkflRO26zuxNg)

[rpm](https://disk.yandex.ru/d/UdT3zghFEq6LSg)

[sh](https://disk.yandex.ru/d/of-QI10rmBiABA)

macOS

[часть1](https://disk.yandex.ru/d/UQi6RtPGk5bG1Q)

[часть2](https://disk.yandex.ru/d/qF83EFucY-ZmIg)

2. STM32CubeMX + [VSCode](https://code.visualstudio.com/) + [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)

### STM32CubeIDE

Примеры выполнения работ можно найти в разделе [Учебные материалы](#учебные-материалы) п.3

### CubeMX + VSCode + Cortex-Debug

В данном репозитории расположен workspace для использования VSCode + Cortex-Debug. Для компиляции, загрузки и отладки проекта потребуется в PATH:

* [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm)
* [OpenOCD](https://openocd.org/)
* [Make](https://www.gnu.org/software/make/)

Для работы IntelliSense рекомендуется установить [набор расширений C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

## Рекомендуемая литература

1. [А.О. Ключев, Д.Р. Ковязина, П.В. Кустарев, А.Е. Платунов. Аппаратные и программные средства встраиваемых систем - Санкт-Петербург: Университет ИТМО, 2010. - 290 с. - 100 экз.](http://books.ifmo.ru/file/pdf/686.pdf)
2. [А.О. Ключев, П.В. Кустарев, Д.Р. Ковязина, Е.В. Петров. Программное обеспечение встроенных вычислительных систем - Санкт-Петербург: Университет ИТМО, 2009. - 212 с. - 100 экз.](http://books.ifmo.ru/file/pdf/499.pdf)
3. [Ключев А. О., Кустарев П. В., Платунов А. Е. Аппаратные средства информационно-управляющих систем. Учебное пособие - Санкт-Петербург: СПб: Университет ИТМО, 2015. - 65 с. - 100 экз.](http://books.ifmo.ru/file/pdf/1723.pdf)
4. [Ключев А. О., Кустарев П. В., Платунов А. Е. Распределенные информационно-управляющие системы. Учебное пособие. - Санкт-Петербург: СПб.: Университет ИТМО, 2015. - 58 с. - 100 экз.](http://books.ifmo.ru/file/pdf/1724.pdf)
5. [А.О. Ключев, Д.Р. Ковязина, Е.В. Петров, А.Е. Платунов. Интерфейсы периферийных устройств. - Санкт-Петербург: СПбГУ ИТМО, 2010. - 294 с. - 100 экз.](http://books.ifmo.ru/file/pdf/728.pdf)
