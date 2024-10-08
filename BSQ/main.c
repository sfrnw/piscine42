/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:51:21 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/07 15:51:28 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 1000

typedef struct {
    int rows;
    int cols;
    char empty;
    char obstacle;
    char full;
    char map[MAX_SIZE][MAX_SIZE];
} Map;

int min(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

void find_biggest_square(Map *map) {
    int dp[MAX_SIZE][MAX_SIZE] = {0};
    int max_size = 0, max_i = 0, max_j = 0;

    // Initialize first row and column of dp
    for (int i = 0; i < map->rows; i++) {
        dp[i][0] = (map->map[i][0] == map->empty);
    }
    for (int j = 0; j < map->cols; j++) {
        dp[0][j] = (map->map[0][j] == map->empty);
    }

    // Fill dp table
    for (int i = 1; i < map->rows; i++) {
        for (int j = 1; j < map->cols; j++) {
            if (map->map[i][j] == map->empty) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }

    // Fill the biggest square
    for (int i = max_i; i > max_i - max_size; i--) {
        for (int j = max_j; j > max_j - max_size; j--) {
            map->map[i][j] = map->full;
        }
    }
}

int read_map(char *filename, Map *map) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) return 0;

    char buffer[MAX_SIZE];
    int bytes_read = read(fd, buffer, MAX_SIZE);
    if (bytes_read <= 0) {
        close(fd);
        return 0;
    }

    int i = 0;
    while (buffer[i] != '\n' && i < bytes_read) i++;
    if (i == bytes_read) {
        close(fd);
        return 0;
    }

    map->rows = atoi(buffer);
    map->empty = buffer[i-3];
    map->obstacle = buffer[i-2];
    map->full = buffer[i-1];

    int row = 0, col = 0;
    for (int j = i + 1; j < bytes_read; j++) {
        if (buffer[j] == '\n') {
            if (col == 0) map->cols = col;
            else if (col != map->cols) {
                close(fd);
                return 0;
            }
            row++;
            col = 0;
        } else {
            if (buffer[j] != map->empty && buffer[j] != map->obstacle) {
                close(fd);
                return 0;
            }
            map->map[row][col++] = buffer[j];
        }
    }

    close(fd);
    return (row == map->rows);
}

void print_map(Map *map) {
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            write(1, &map->map[i][j], 1);
        }
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(2, "Error: No input file\n", 21);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        Map map;
        if (!read_map(argv[i], &map)) {
            write(2, "map error\n", 10);
            continue;
        }

        find_biggest_square(&map);
        print_map(&map);

        if (i < argc - 1) write(1, "\n", 1);
    }

    return 0;
}
