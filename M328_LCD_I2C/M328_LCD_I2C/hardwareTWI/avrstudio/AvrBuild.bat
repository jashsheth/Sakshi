@ECHO OFF
"C:\Program Files\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "I:\LCD_I2C\dist\hardwareTWI\avrstudio\labels.tmp" -fI -W+ie -o "I:\LCD_I2C\dist\hardwareTWI\avrstudio\LCD_I2C.hex" -d "I:\LCD_I2C\dist\hardwareTWI\avrstudio\LCD_I2C.obj" -e "I:\LCD_I2C\dist\hardwareTWI\avrstudio\LCD_I2C.eep" -m "I:\LCD_I2C\dist\hardwareTWI\avrstudio\LCD_I2C.map" "I:\LCD_I2C\dist\hardwareTWI\avrstudio\LCD_I2C.asm"
