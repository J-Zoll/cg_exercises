/* ------------------------------------------------------------------------- */

static PFNWGLGETEXTENSIONSSTRINGARBPROC _wglewGetExtensionsStringARB = NULL;
static PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglewGetExtensionsStringEXT = NULL;

GLboolean GLEWAPIENTRY wglewGetExtension (const char* name)
{    
  const GLubyte* start;
  const GLubyte* end;
  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      start = (const GLubyte*)_wglewGetExtensionsStringEXT();
  else
    start = (const GLubyte*)_wglewGetExtensionsStringARB(wglGetCurrentDC());
  if (start == 0)
    return GL_FALSE;
  end = start + _glewStrLen(start);
  return _glewSearchExtension(name, start, end);
}

#ifdef GLEW_MX
GLenum GLEWAPIENTRY wglewContextInit (WGLEW_CONTEXT_ARG_DEF_LIST)
#else
GLenum GLEWAPIENTRY wglewInit (WGLEW_CONTEXT_ARG_DEF_LIST)
#endif
{
  GLboolean crippled;
  const GLubyte* extStart;
  const GLubyte* extEnd;
  /* find wgl extension string query functions */
  _wglewGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringARB");
  _wglewGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringEXT");
  /* query wgl extension string */
  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      extStart = (const GLubyte*)"";
    else
      extStart = (const GLubyte*)_wglewGetExtensionsStringEXT();
  else
    extStart = (const GLubyte*)_wglewGetExtensionsStringARB(wglGetCurrentDC());
  extEnd = extStart + _glewStrLen(extStart);
  /* initialize extensions */
  crippled = _wglewGetExtensionsStringARB == NULL && _wglewGetExtensionsStringEXT == NULL;
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
