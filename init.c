#include "TH.h"
#include "luaT.h"
#include "omp.h"

#define torch_(NAME) TH_CONCAT_3(torch_, Real, NAME)
#define torch_string_(NAME) TH_CONCAT_STRING_3(torch., Real, NAME)
#define nn_(NAME) TH_CONCAT_3(nn_, Real, NAME)

static const void* torch_FloatTensor_id = NULL;
static const void* torch_DoubleTensor_id = NULL;

#include "generic/SpatialReSamplingEx.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialUpSampling.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialDownSampling.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialReSampling.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialMaxSampling.c"
#include "THGenerateFloatTypes.h"

#include "generic/DistMarginCriterion.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialGraph.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialMatching.c"
#include "THGenerateFloatTypes.h"

#include "generic/SpatialRadialMatching.c"
#include "THGenerateFloatTypes.h"

#include "generic/DataSetLabelMe.c"
#include "THGenerateFloatTypes.h"

DLL_EXPORT int luaopen_libnnx(lua_State *L)
{
  torch_FloatTensor_id = luaT_checktypename2id(L, "torch.FloatTensor");
  torch_DoubleTensor_id = luaT_checktypename2id(L, "torch.DoubleTensor");

  nn_FloatSpatialReSamplingEx_init(L);
  nn_FloatSpatialUpSampling_init(L);
  nn_FloatSpatialDownSampling_init(L);
  nn_FloatSpatialReSampling_init(L);
  nn_FloatSpatialMaxSampling_init(L);
  nn_FloatDistMarginCriterion_init(L);
  nn_FloatSpatialGraph_init(L);
  nn_FloatSpatialMatching_init(L);
  nn_FloatSpatialRadialMatching_init(L);
  nn_FloatDataSetLabelMe_init(L);

  nn_DoubleSpatialReSamplingEx_init(L);
  nn_DoubleSpatialUpSampling_init(L);
  nn_DoubleSpatialDownSampling_init(L);
  nn_DoubleSpatialReSampling_init(L);
  nn_DoubleSpatialMaxSampling_init(L);
  nn_DoubleDistMarginCriterion_init(L);
  nn_DoubleSpatialGraph_init(L);
  nn_DoubleSpatialMatching_init(L);
  nn_DoubleSpatialRadialMatching_init(L);
  nn_DoubleDataSetLabelMe_init(L);

  return 1;
}
