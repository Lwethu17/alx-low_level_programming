#!/usr/bin/python3
"""Defines an island perimeter of a measuring function."""


def island_perimeter(grid):
    """Returns the perimeter of an island."""
    width = len(grid[0])
    height = len(grid)
    edges = 0
    perimeter = 0

    for x in range(height):
        for y in range(width):
            if grid[x][y] == 1:
                perimeter += 1
                if (y > 0 and grid[x][y - 1] == 1):
                    edges += 1
                if (x > 0 and grid[x - 1][y] == 1):
                    edges += 1
    return perimeter * 4 - edges * 2
