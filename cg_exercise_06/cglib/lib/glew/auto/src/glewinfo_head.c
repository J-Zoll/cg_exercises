#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#if defined(_WIN32)
#include <GL/wglew.h>
#elif !defined(__APPLE__) && !defined(__HAIKU__) || defined(GLEW_APPLE_GLX)
#include <GL/glxew.h>
#endif

#if defined(__APPLE__)
#include <AvailabilityMacros.h>
#endif

#ifdef GLEW_REGAL
#include <GL/Regal.h>
#endif

static FILE* f;

#ifdef GLEW_MX
GLEWContext _glewctx;
#define glewGetContext() (&_glewctx)
#ifdef _WIN32
WGLEWContext _wglewctx;
#define wglewGetContext() (&_wglewctx)
#elif !defined(__APPLE__) && !defined(__HAIKU__) || defined(GLEW_APPLE_GLX)
GLXEWContext _glxewctx;
#define glxewGetContext() (&_glxewctx)
#endif
#endif

/* Command-line parameters for GL context creation */

struct createParams
{
#if defined(_WIN32)
  int         pixelformat;
#elif !defined(__APPLE__) && !defined(__HAIKU__) || defined(GLEW_APPLE_GLX)
  const char* display;
  int         visual;
#endif
  int         major, minor;  /* GL context version number */

  /* https://www.opengl.org/registry/specs/ARB/glx_create_context.txt */
  int         profile;       /* core = 1, compatibility = 2 */
  int         flags;         /* debug = 1, forward compatible = 2 */
};

GLboolean glewCreateContext (struct createParams *params);

GLboolean glewParseArgs (int argc, char** argv, struct createParams *);

void glewDestroyContext ();

/* ------------------------------------------------------------------------- */

static void glewPrintExt (const char* name, GLboolean def1, GLboolean def2, GLboolean def3)
{
  unsigned int i;
  fprintf(f, "\n%s:", name);
  for (i=0; i<62-strlen(name); i++) fprintf(f, " ");
  fprintf(f, "%s ", def1 ? "OK" : "MISSING");
  if (def1 != def2)
    fprintf(f, "[%s] ", def2 ? "OK" : "MISSING");
  if (def1 != def3)
    fprintf(f, "[%s]\n", def3 ? "OK" : "MISSING");
  else
    fprintf(f, "\n");
  for (i=0; i<strlen(name)+1; i++) fprintf(f, "-");
  fprintf(f, "\n");
  fflush(f);
}

static void glewInfoFunc (const char* name, GLint undefined)
{
  unsigned int i;
  fprintf(f, "  %s:", name);
  for (i=0; i<60-strlen(name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", undefined ? "MISSING" : "OK");
  fflush(f);
}

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifdef GL_VERSION_1_1

static void _glewInfo_GL_VERSION_1_1 (void)
{
  glewPrintExt("GL_VERSION_1_1", GLEW_VERSION_1_1, GLEW_VERSION_1_1, GLEW_VERSION_1_1);
}

#endif /* GL_VERSION_1_1 */

// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
