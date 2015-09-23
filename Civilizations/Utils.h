#pragma once

#ifndef UTILS_H
#define UTILS_H

#define SATURATE(x, a, b) (x < a ? a : x > b ? b : x)
#define DIST(x, y) (((x) * (x)) + ((y) * (y)))
#define SQR(x) ((x) * (x))
#define RAND0(range) (xorshf96() % (range))
#define RAND0EQ0(range) ((xorshf96() % (range)) == 0)
#define RAND0NEQ0(range) ((xorshf96() % (range)) != 0)
#define RAND(range, minValue) ((xorshf96() % (range)) + minValue)
#define RANDEQ0(range, minValue) (((xorshf96() % (range)) + minValue) == 0)
#define RANDNEQ0(range, minValue) (((xorshf96() % (range)) + minValue) != 0)

#define AGE(ent) (WorldUpdater::currentTurn - (ent).creationTime)
#define WEEKSINMONTH 4
#define MONTHSINYEAR 12
#define WEEKSINYEAR (WEEKSINMONTH * MONTHSINYEAR)
#define WEEKSFROMMONTHS(x) ((x) * WEEKSINMONTH)
#define WEEKSFROMYEARS(x) ((x) * WEEKSINYEAR)


#define WORLD (Game::world)

#define WWIDTH (WORLD->width)
#define WHEIGHT (WORLD->height)

#define TILES (WORLD->tiles)
#define TILE(x, y) (&TILES[(x) + (y) * WWIDTH])
#define TILEP(i) (&TILES[i])

#define SURFS (WORLD->entities[lay_surf])
#define FLORAS (WORLD->entities[lay_flora])
#define SURF(pCell) (((pCell) < 0) ? nullptr : &SURFS[pCell])
#define FLORA(pCell) (((pCell) < 0) ? nullptr : &FLORAS[pCell])
#define SURFAT(x, y) SURF(TILE(x, y)->surfaceCell)
#define FLORAAT(x, y) FLORA(TILE(x, y)->floraCell)
#define SURFATP(i) SURF(TILEP(i)->surfaceCell)
#define FLORAATP(i) FLORA(TILEP(i)->floraCell)

#define RANDVECT(v) (((v).size() == 0) ? type_unknown : ((v).size() == 1) ? (v)[0] : (v)[RAND0((v).size())])

// Rand:
void initRand();
unsigned long xorshf96();

#endif // UTILS_H
