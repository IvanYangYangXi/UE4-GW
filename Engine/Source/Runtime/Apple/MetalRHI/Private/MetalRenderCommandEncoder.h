// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MetalDebugCommandEncoder.h"

NS_ASSUME_NONNULL_BEGIN

@class FMetalShaderPipeline;
@class FMetalDebugRenderCommandEncoder;

class FMetalRenderCommandEncoderDebugging : public FMetalCommandEncoderDebugging
{
	void InsertDebugDraw();
public:
	FMetalRenderCommandEncoderDebugging();
	FMetalRenderCommandEncoderDebugging(mtlpp::RenderCommandEncoder& Encoder, mtlpp::RenderPassDescriptor const& Desc, FMetalCommandBufferDebugging& Buffer);
	FMetalRenderCommandEncoderDebugging(FMetalDebugCommandEncoder* handle);
	
	static FMetalRenderCommandEncoderDebugging Get(mtlpp::RenderCommandEncoder& Buffer);
	
	void SetPipeline(FMetalShaderPipeline* Pipeline);
	
	void SetBytes(EMetalShaderFrequency Freq, const void * bytes, NSUInteger length, NSUInteger index);
	void SetBuffer(EMetalShaderFrequency Freq,  FMetalBuffer const& buffer, NSUInteger offset, NSUInteger index);
	void SetBufferOffset(EMetalShaderFrequency Freq, NSUInteger offset, NSUInteger index);
	void SetTexture(EMetalShaderFrequency Freq,  FMetalTexture const& texture, NSUInteger index);
	void SetSamplerState(EMetalShaderFrequency Freq,  mtlpp::SamplerState const& sampler, NSUInteger index);
	void SetSamplerState(EMetalShaderFrequency Freq,  mtlpp::SamplerState const& sampler, float lodMinClamp, float lodMaxClamp, NSUInteger index);
	void SetDepthStencilState( mtlpp::DepthStencilState const& depthStencilState);
	
	void Draw(mtlpp::PrimitiveType primitiveType, NSUInteger vertexStart, NSUInteger vertexCount, NSUInteger instanceCount);
	
	void Draw(mtlpp::PrimitiveType primitiveType, NSUInteger vertexStart, NSUInteger vertexCount);
	
	void DrawIndexed(mtlpp::PrimitiveType primitiveType, NSUInteger indexCount, mtlpp::IndexType indexType, FMetalBuffer const& indexBuffer, NSUInteger indexBufferOffset, NSUInteger instanceCount);
	
	void DrawIndexed(mtlpp::PrimitiveType primitiveType, NSUInteger indexCount, mtlpp::IndexType indexType, FMetalBuffer const& indexBuffer, NSUInteger indexBufferOffset);
	
	void Draw(mtlpp::PrimitiveType primitiveType, NSUInteger vertexStart, NSUInteger vertexCount, NSUInteger instanceCount, NSUInteger baseInstance);
	
	void DrawIndexed(mtlpp::PrimitiveType primitiveType, NSUInteger indexCount, mtlpp::IndexType indexType, FMetalBuffer const& indexBuffer, NSUInteger indexBufferOffset, NSUInteger instanceCount, NSInteger baseVertex, NSUInteger baseInstance);
	
	void Draw(mtlpp::PrimitiveType primitiveType, FMetalBuffer const& indirectBuffer, NSUInteger indirectBufferOffset);
	
	void DrawIndexed(mtlpp::PrimitiveType primitiveType, mtlpp::IndexType indexType, FMetalBuffer const& indexBuffer, NSUInteger indexBufferOffset, FMetalBuffer const& indirectBuffer, NSUInteger indirectBufferOffset);
	
	void SetTessellationFactorBuffer( FMetalBuffer const& buffer, NSUInteger offset, NSUInteger instanceStride);
	
	void DrawPatches(NSUInteger numberOfPatchControlPoints, NSUInteger patchStart, NSUInteger patchCount,  FMetalBuffer const& patchIndexBuffer, NSUInteger patchIndexBufferOffset, NSUInteger instanceCount, NSUInteger baseInstance);
	
	void DrawPatches(NSUInteger numberOfPatchControlPoints,  FMetalBuffer const& patchIndexBuffer, NSUInteger patchIndexBufferOffset, FMetalBuffer const& indirectBuffer, NSUInteger indirectBufferOffset);
	
	void DrawIndexedPatches(NSUInteger numberOfPatchControlPoints, NSUInteger patchStart, NSUInteger patchCount,  FMetalBuffer const& patchIndexBuffer, NSUInteger patchIndexBufferOffset, FMetalBuffer const& controlPointIndexBuffer, NSUInteger controlPointIndexBufferOffset, NSUInteger instanceCount, NSUInteger baseInstance);
	
	void DrawIndexedPatches(NSUInteger numberOfPatchControlPoints,  FMetalBuffer const& patchIndexBuffer, NSUInteger patchIndexBufferOffset, FMetalBuffer const& controlPointIndexBuffer, NSUInteger controlPointIndexBufferOffset, FMetalBuffer const& indirectBuffer, NSUInteger indirectBufferOffset);
	
	/** Validates the pipeline/binding state */
	bool ValidateFunctionBindings(EMetalShaderFrequency Frequency);
	void Validate();
	
	void InsertDebugSignpost(ns::String const& Label);
	void PushDebugGroup(ns::String const& Group);
	void PopDebugGroup();
	
	void EndEncoder();
};

NS_ASSUME_NONNULL_END

