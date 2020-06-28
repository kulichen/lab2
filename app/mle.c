/**
 * mle.c -- 
 *
 * Copyright (c) 2017, Daniil Kulichenko <kulichen@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "text.h"
#include "_text.h"

static void prohod(int index, char *contents, int cursor, void *data);

int mle(text txt)
{
	/* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, prohod, txt);

    return 1;
}

static void prohod(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

	if(cursor != -1) {
		int i = 0;
		while(contents[i] != '\0') i++;	
		m(data, index, i);
		}
}
