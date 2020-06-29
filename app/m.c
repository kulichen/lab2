/**
 * m.c -- 
 * 
 * Copyright (c) 2020, Daniil Kulichenko <kulichen@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * 
 * @param txt текст
 * @returns none
 */
int m(text txt, long line, long position)
{    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

	/* Стартуем с начальной строки текста */
	node *current = txt->begin;
    long index = 0;
    long length = 0;

	/* К каждой строке текста применяем обработчик */
    if (line < 0) {
		txt->cursor->position = 1;
		txt->cursor->line = current;
        return -1;
	}
    if (line >= (long)txt->length) {
		txt->cursor->line = txt->end;
		txt->cursor->position = strlen(txt->end->contents);
        return 3;
	}
	while (current) {
        if (index == line) {
			txt->cursor->line = current;
			length = strlen(current->contents);
            if (position < 0) {
				txt->cursor->position = 1;
                return 1;
			}
            if (position >= length) {
				txt->cursor->position = length;
                return 2;
			}
            txt->cursor->position = position + 1;
            
		}	
		current = current->next;
		index++; 
    }
    return 0;
}



