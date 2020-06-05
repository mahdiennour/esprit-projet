#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include "zoom.h"
SDL_Surface *rotozoomSurface (SDL_Surface * src, double angle, double zoom, int smooth)
{
  SDL_Surface *rz_src;
  SDL_Surface *rz_dst;
  double zoominv;
  double radangle, sanglezoom, canglezoom, sanglezoominv, canglezoominv;
  int dstwidthhalf, dstwidth, dstheighthalf, dstheight;
  double x, y, cx, cy, sx, sy;
  int is32bit;
  int i, src_converted;

  /* Sanity check */
  if (src == NULL)
    return (NULL);

  /* Determine if source surface is 32bit or 8bit */
  is32bit = (src->format->BitsPerPixel == 32);
  if ((is32bit) || (src->format->BitsPerPixel == 8))
    {
      /* Use source surface 'as is' */
      rz_src = src;
      src_converted = 0;
    }
  else
    {
      /* New source surface is 32bit with a defined RGBA ordering */
      rz_src =
	SDL_CreateRGBSurface (SDL_SWSURFACE, src->w, src->h, 32, 0x000000ff,
			      0x0000ff00, 0x00ff0000, 0xff000000);
      SDL_BlitSurface (src, NULL, rz_src, NULL);
      src_converted = 1;
      is32bit = 1;
    }

  /* Sanity check zoom factor */
  if (zoom < VALUE_LIMIT)
    {
      zoom = VALUE_LIMIT;
    }
  zoominv = 65536.0 / zoom;

  /* Check if we have a rotozoom or just a zoom */
  if (fabs (angle) > VALUE_LIMIT)
    {

      /* Angle!=0: full rotozoom */
      /* ----------------------- */

      /* Calculate target factors from sin/cos and zoom */
      radangle = angle * (M_PI / 180.0);
      sanglezoom = sanglezoominv = sin (radangle);
      canglezoom = canglezoominv = cos (radangle);
      sanglezoom *= zoom;
      canglezoom *= zoom;
      sanglezoominv *= zoominv;
      canglezoominv *= zoominv;

      /* Determine destination width and height by rotating a centered source box */
      x = rz_src->w / 2;
      y = rz_src->h / 2;
      cx = canglezoom * x;
      cy = canglezoom * y;
      sx = sanglezoom * x;
      sy = sanglezoom * y;
      dstwidthhalf =
	MAX ((int)
	     ceil (MAX
		   (MAX
		    (MAX (fabs (cx + sy), fabs (cx - sy)), fabs (-cx + sy)),
		    fabs (-cx - sy))), 1);
      dstheighthalf =
	MAX ((int)
	     ceil (MAX
		   (MAX
		    (MAX (fabs (sx + cy), fabs (sx - cy)), fabs (-sx + cy)),
		    fabs (-sx - cy))), 1);
      dstwidth = 2 * dstwidthhalf;
      dstheight = 2 * dstheighthalf;

      /* Alloc space to completely contain the rotated surface */
      rz_dst = NULL;
      if (is32bit)
	{
	  /* Target surface is 32bit with source RGBA/ABGR ordering */
	  rz_dst =
	    SDL_CreateRGBSurface (SDL_SWSURFACE, dstwidth, dstheight, 32,
				  rz_src->format->Rmask,
				  rz_src->format->Gmask,
				  rz_src->format->Bmask,
				  rz_src->format->Amask);
	}
      else
	{
	  /* Target surface is 8bit */
	  rz_dst =
	    SDL_CreateRGBSurface (SDL_SWSURFACE, dstwidth, dstheight, 8, 0, 0,
				  0, 0);
	}

      /* Lock source surface */
      SDL_LockSurface (rz_src);
      /* Check which kind of surface we have */
      if (is32bit)
	{
	  /* Call the 32bit transformation routine to do the rotation (using alpha) */
	  transformSurfaceRGBA (rz_src, rz_dst, dstwidthhalf, dstheighthalf,
				(int) (sanglezoominv),
				(int) (canglezoominv), smooth);
	  /* Turn on source-alpha support */
	  SDL_SetAlpha (rz_dst, SDL_SRCALPHA, 255);
	}
      else
	{
	  /* Copy palette and colorkey info */
	  for (i = 0; i < rz_src->format->palette->ncolors; i++)
	    {
	      rz_dst->format->palette->colors[i] =
		rz_src->format->palette->colors[i];
	    }
	  rz_dst->format->palette->ncolors = rz_src->format->palette->ncolors;
	  /* Call the 8bit transformation routine to do the rotation */
	  transformSurfaceY (rz_src, rz_dst, dstwidthhalf, dstheighthalf,
			     (int) (sanglezoominv), (int) (canglezoominv));
	  SDL_SetColorKey (rz_dst, SDL_SRCCOLORKEY | SDL_RLEACCEL,
			   rz_src->format->colorkey);
	}
      /* Unlock source surface */
      SDL_UnlockSurface (rz_src);

    }
  else
    {

      /* Angle=0: Just a zoom */
      /* -------------------- */

      /* Calculate target size and set rect */
      dstwidth = (int) ((double) rz_src->w * zoom);
      dstheight = (int) ((double) rz_src->h * zoom);
      if (dstwidth < 1)
	{
	  dstwidth = 1;
	}
      if (dstheight < 1)
	{
	  dstheight = 1;
	}

      /* Alloc space to completely contain the zoomed surface */
      rz_dst = NULL;
      if (is32bit)
	{
	  /* Target surface is 32bit with source RGBA/ABGR ordering */
	  rz_dst =
	    SDL_CreateRGBSurface (SDL_SWSURFACE, dstwidth, dstheight, 32,
				  rz_src->format->Rmask,
				  rz_src->format->Gmask,
				  rz_src->format->Bmask,
				  rz_src->format->Amask);
	}
      else
	{
	  /* Target surface is 8bit */
	  rz_dst =
	    SDL_CreateRGBSurface (SDL_SWSURFACE, dstwidth, dstheight, 8, 0, 0,
				  0, 0);
	}

      /* Lock source surface */
      SDL_LockSurface (rz_src);
      /* Check which kind of surface we have */
      if (is32bit)
	{
	  /* Call the 32bit transformation routine to do the zooming (using alpha) */
	  zoomSurfaceRGBA (rz_src, rz_dst, smooth);
	  /* Turn on source-alpha support */
	  SDL_SetAlpha (rz_dst, SDL_SRCALPHA, 255);
	}
      else
	{
	  /* Copy palette and colorkey info */
	  for (i = 0; i < rz_src->format->palette->ncolors; i++)
	    {
	      rz_dst->format->palette->colors[i] =
		rz_src->format->palette->colors[i];
	    }
	  rz_dst->format->palette->ncolors = rz_src->format->palette->ncolors;
	  /* Call the 8bit transformation routine to do the zooming */
	  zoomSurfaceY (rz_src, rz_dst);
	  SDL_SetColorKey (rz_dst, SDL_SRCCOLORKEY | SDL_RLEACCEL,
			   rz_src->format->colorkey);
	}
      /* Unlock source surface */
      SDL_UnlockSurface (rz_src);
    }

  /* Cleanup temp surface */
  if (src_converted)
    {
      SDL_FreeSurface (rz_src);
    }

  /* Return destination surface */
  return (rz_dst);
}
}
