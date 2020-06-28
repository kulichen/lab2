/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "text.h"
#include "_text.h"
#include <assert.h>

/**
 * Загружает содержимое указанного файла
 */


static void save_line(int index, char *contents, int cursor, void *data);

int save(text txt, char *filename){
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 0;
    }
    FILE *f;
    f = fopen(filename, "w");
    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line, (void*)f);
    fclose(f);
    return 1;
}

static void save_line(int index, char *contents, int cursor, void *data)
{

  FILE* f = (FILE*)data;
 
  /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    /* Выводим строку на экран */
    fprintf(f, "%s", contents);
}

