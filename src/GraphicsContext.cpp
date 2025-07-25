#include "Core3D/Core3D.h"
#include "Core3D/GraphicsContext.h"

using namespace Core3D;

GraphicsContext::GraphicsContext(GraphicsBackend backend)
{
}

GraphicsContext::~GraphicsContext()
{
}

void GraphicsContext::Present()
{
}

GraphicsBackend GraphicsContext::GetCurrentBackend() const
{
    return GraphicsBackend::Null;
}

bool Core3D::IsBackendSupported(GraphicsBackend backend)
{
    return false;
}