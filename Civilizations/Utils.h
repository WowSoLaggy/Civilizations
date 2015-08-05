#pragma once

#ifndef UTILS_H
#define UTILS_H

#define SATURATE(x, a, b) (x < a ? a : x > b ? b : x)
#define DIST(x, y) (((x) * (x)) + ((y) * (y)))
#define SQR(x) ((x) * (x))
#define RAND0(range) ((rand() & (range)) == 0)
#define RAND(range, minValue) ((rand() % (range)) + minValue)

#define AGE(x) (WorldUpdater::currentTurn - (x).creationTime)

#define WWIDTH (Game::world->width)
#define WHEIGHT (Game::world->height)

#define TILE(x, y) (&Game::world->tiles[(x) + (y) * WWIDTH])
#define TILEP(i) (&Game::world->tiles[i])
#define SURF(pCell) (((pCell) < 0) ? nullptr : &Game::world->lsurfaces[pCell])
#define OBJ(pCell) (((pCell) < 0) ? nullptr : &Game::world->lobjects[pCell])
#define SURFAT(x, y) SURF(TILE(x, y)->surfaceCell)
#define OBJAT(x, y) OBJ(TILE(x, y)->objectCell)
#define SURFATP(i) SURF(TILEP(i)->surfaceCell)
#define OBJATP(i) OBJ(TILEP(i)->objectCell)

#endif // UTILS_H
