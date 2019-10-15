/**
  ******************************************************************************
  * @file    Morise/main.c 
  * @author  Mohamed Hssairi
  * @version V1.0.0
  * @date    17/04/2019
  * @brief   Main program body.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @addtogroup Examples
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;

/* Private function prototypes -----------------------------------------------*/
//void Delay(__IO uint32_t nCount);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
	volatile int32_t TimeDelay;
	void Delay(uint32_t ntime)
	{
		TimeDelay=ntime;
		while(TimeDelay !=0);
	}
	void init_LED()
	{

 /* GPIOC clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  

  /* set GPIO's peripheral registers to their reset values */
  GPIO_DeInit(GPIOC);
  /* Initialize Led LD4 mounted on STM32VLDISCOVERY board */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	}
	
	/* cette fonction permet d'envoyer un signal lumineux point
	en morse (allume et éteint) */
	void envoyer_signal_point(void)
	{
		/* Turn on LD4 */
    GPIO_SetBits(GPIOC, GPIO_Pin_8);
		/* Insert delay */
		Delay(500); //chaque demi second (1 unité de temps
		/* Turn OFF LED4 */
   GPIO_ResetBits(GPIOC, GPIO_Pin_8);
		/* Insert delay */
		Delay(500); //chaque (1 unités de temps)
	}
	/* cette fonction permet d'envoyer un signal lumineux tiret
	en morse (allume et éteint) */
	void envoyer_signal_tiret(void)
	{
		/* Turn on LD4 */
    GPIO_SetBits(GPIOC, GPIO_Pin_8);
		/* Insert delay */
		Delay(1500); //chaque (3 unités de temps)
		/* Turn OFF LED4 */
   GPIO_ResetBits(GPIOC, GPIO_Pin_8);
		/* Insert delay */
		Delay(500); //chaque (1 unités de temps)
	}
	/* cette fonction permet d'insere le delai entre 2 lettres */
	void envoyer_signal_pause_2_lettres(void)
	{
		/* Turn OFF LED4 */
   GPIO_ResetBits(GPIOC, GPIO_Pin_8);
		/* Insert delay */
		Delay(1500); //chaque (3 unités de temps)
	}
	/* cette fonction permet d'insere le delai entre 2 mots */
	void envoyer_signal_pause_2_mots(void)
	{
		/* Turn OFF LED4 */
   GPIO_ResetBits(GPIOC, GPIO_Pin_8);
		/* Insert delay */
		Delay(3500); //chaque (7 unités de temps)
	}
	void affiche_code(char* c)
	{
		int j;
	for (j = 0; j < strlen(c); j++)
{
	if(c[j]=='.')
	{
		envoyer_signal_point();
	}else
		envoyer_signal_tiret();}	
	}
int main(void){ 
char *morse[26] = {".-", "-...", "-.-.", "-..", ".","..-.", "--.", "....", "..",
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
"...-", ".--", "-..-", "-.--", "--.."};
static const char alph[] = {'a', 'b', 'c', 'd', 'e', 'f','g','h','i','j','k',
'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char* word;
char* wordmorse;
int i,j;
word="sos"; 
				init_LED();
		   SystemInit();
			 SystemCoreClockUpdate();
       SysTick_Config(SystemCoreClock/1000);
  while (1)
  {
		for (j = 0; j < strlen(word); j++)
    {
        for (i = 0; i < 26; i++)
        {
            if (alph[i] == word[j])
            {
                wordmorse=morse[i];
								affiche_code(wordmorse);
								envoyer_signal_pause_2_lettres();
            }else if (word[j] ==' ')
						{
							envoyer_signal_pause_2_mots();
						}
        }}
	}}


/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
/* void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} */

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
