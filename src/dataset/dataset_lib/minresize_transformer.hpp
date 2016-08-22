#pragma once

#include "base_transformer.hpp"

// Ensures that input channel's smaller dimension is greater or equal to given one using resize.
class MinResizeTransformer : public BaseTransformer<MinResizeTransformer>
{
public:
  static const char* GetTypeString() { return "minresize"; }

  MinResizeTransformer(const TransformParameter& param);

  virtual void GetTransformedSizeImpl(int width, int height, int& new_width, int& new_height) override;

  virtual void TransformImpl(std::vector<TransformableChannelset*>& channelsets) override;

private:
  int min_resize_;
};