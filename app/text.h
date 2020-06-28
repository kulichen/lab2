/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

#define UNUSED(x) (void)(x)

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;

text create_text();

void load(text txt, char *filename);

void remove_all(text txt);

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents);

/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

/**
 * Изменяет позицию курсора
 * @param txt текст
 */
int m(text txt, long cursor_line, long cursor_position);

/**
 * Изменяет позицию курсора
 * @param txt текст
 */
int mle(text txt);

/**
 * Сохраняет изменения текста
 * @param txt текст
 */
int save(text txt, char *filename);

/**
 * Удаляет первую непустую строку
 * @param txt текст
 */
int r1ne(text txt);

/**
 * Выводит текст с первыми заглавными
 * @param txt текст
 */
void showupfirst(text txt);

#endif
