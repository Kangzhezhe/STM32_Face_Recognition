/**
  ******************************************************************************
  * @file    network_1.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jun 26 11:07:36 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network_1.h"
#include "network_1_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_1
 
#undef AI_NETWORK_1_MODEL_SIGNATURE
#define AI_NETWORK_1_MODEL_SIGNATURE     "743062d41dbb134cd1869ff5cdf5cac1"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jun 26 11:07:36 2024"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_1_N_BATCHES
#define AI_NETWORK_1_N_BATCHES         (1)

static ai_ptr g_network_1_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_1_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 512, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  input_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 32256, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 512, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  input_Transpose_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32256, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 172032, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 172032, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 512, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 344064, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4460, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 172032, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 172032, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 344064, AI_STATIC)
/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 172032, AI_STATIC)
/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)
/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)
/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)
/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_Add_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)
/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 128, AI_STATIC)
/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)
/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)
/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 64, AI_STATIC)
/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)
/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 64, AI_STATIC)
/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)
/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2816, AI_STATIC)
/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 172032, AI_STATIC)
/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)
/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)
/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)
/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)
/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 43008, AI_STATIC)
/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5632, AI_STATIC)
/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 86016, AI_STATIC)
/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18945, AI_STATIC)
/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)
/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)
/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5632, AI_STATIC)
/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21504, AI_STATIC)
/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 512, AI_STATIC)
/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 69633, AI_STATIC)
/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 512, AI_STATIC)
/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)
/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)
/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 512, AI_STATIC)
/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 512, AI_STATIC)
/* Array#262 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#263 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#264 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#265 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#266 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#267 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#268 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#269 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#270 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#271 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#272 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#273 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#274 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#275 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#276 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)
/* Array#277 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)
/* Array#278 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#279 */
AI_ARRAY_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv2_conv_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 512,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000913299445528537f, 0.00048295268788933754f, 0.0006047793431207538f, 0.0004768382932525128f, 0.0005475868238136172f, 0.0004510137077886611f, 0.0005922509590163827f, 0.0007197708473540843f, 0.0005635307170450687f, 0.0005048488965258002f, 0.0007212891359813511f, 0.0006007588817737997f, 0.0007070185383781791f, 0.0005187042988836765f, 0.0005886714207008481f, 0.0007542390376329422f, 0.0005976672400720417f, 0.0006161625497043133f, 0.0006343525019474328f, 0.0005365813267417252f, 0.0005244940984994173f, 0.0006032052915543318f, 0.0005527715547941625f, 0.0007656995439901948f, 0.0006249346188269556f, 0.0007979270885698497f, 0.0006312665063887835f, 0.0005516333039849997f, 0.0006116596632637084f, 0.00048026745207607746f, 0.0004972993629053235f, 0.0009761708206497133f, 0.0007368618971668184f, 0.0005304465885274112f, 0.0005480958498083055f, 0.0005196545389480889f, 0.0005193980759941041f, 0.0006551656406372786f, 0.0005450981552712619f, 0.0005343356751836836f, 0.0007877312018536031f, 0.0006091309478506446f, 0.000759345362894237f, 0.0006045101908966899f, 0.00042476016096770763f, 0.0006504415068775415f, 0.0004593954945448786f, 0.00051924551371485f, 0.0004949588910676539f, 0.0006192810251377523f, 0.000789368525147438f, 0.0005698943859897554f, 0.0005769871640950441f, 0.00044194809743203223f, 0.0004817376029677689f, 0.0004200924886390567f, 0.0005895278882235289f, 0.0005166105693206191f, 0.0004060271894559264f, 0.0005540458369068801f, 0.000607290945481509f, 0.0005166769260540605f, 0.0005016331560909748f, 0.0004725081962533295f, 0.0004521485243458301f, 0.0006557388696819544f, 0.0005433500627987087f, 0.0006067095091566443f, 0.0005085329175926745f, 0.0004967134445905685f, 0.0004162057884968817f, 0.0005368538550101221f, 0.0005941870040260255f, 0.0005418357905000448f, 0.0007432812708429992f, 0.0005384896066971123f, 0.0005301551427692175f, 0.0004498424241319299f, 0.0005250191898085177f, 0.0006630731513723731f, 0.0007137589855119586f, 0.0005841909442096949f, 0.0006356484955176711f, 0.0006589949480257928f, 0.00047795308637432754f, 0.0004180517280474305f, 0.0005217206780798733f, 0.0006603535148315132f, 0.0005027472507208586f, 0.0005826627602800727f, 0.0010764908511191607f, 0.0005008396110497415f, 0.0005991559592075646f, 0.00048161656013689935f, 0.0004587461589835584f, 0.0007929624989628792f, 0.0005443451227620244f, 0.000482116243802011f, 0.0004592286713887006f, 0.000557238410692662f, 0.0005805136170238256f, 0.0008022555848583579f, 0.0005234587006270885f, 0.0004831142141483724f, 0.0006175896269269288f, 0.00040658708894625306f, 0.0004433012509252876f, 0.0004294963728170842f, 0.00043300827383063734f, 0.0004537055210676044f, 0.0006056666607037187f, 0.0004460716445464641f, 0.0005083079449832439f, 0.0006714392802678049f, 0.0005209375522099435f, 0.0003944328345824033f, 0.0007209162577055395f, 0.0006603212095797062f, 0.0006227560224942863f, 0.0006171780987642705f, 0.0006899031577631831f, 0.0006151755806058645f, 0.0005699835601262748f, 0.0005467197042889893f, 0.000509705685544759f, 0.0004256516112945974f, 0.0005125697352923453f, 0.00041389965917915106f, 0.0006054401164874434f, 0.0006711802561767399f, 0.0007293536327779293f, 0.0007298356504179537f, 0.0006220502546057105f, 0.0006735328352078795f, 0.0006064966437406838f, 0.0005794956814497709f, 0.0007679666159674525f, 0.0004947737324982882f, 0.0005504388245753944f, 0.00038875953759998083f, 0.0004969488945789635f, 0.0006858054548501968f, 0.0009264915133826435f, 0.0005680376198142767f, 0.0003035076369997114f, 0.000549687014427036f, 0.00037598470225930214f, 0.0004520901129581034f, 0.0004886563983745873f, 0.0007330863736569881f, 0.0005917263915762305f, 0.00030024416628293693f, 0.0005236049182713032f, 0.0008699744357727468f, 0.0005471970653161407f, 0.0005647082580253482f, 0.0007915368187241256f, 0.0007581280078738928f, 0.0005505314329639077f, 0.00046488101361319423f, 0.00040427176281809807f, 0.0006856112158857286f, 0.0005301995552144945f, 0.0004454572917893529f, 0.0005956828244961798f, 0.0004480778006836772f, 0.0006347559974528849f, 0.0004445622325874865f, 0.0007009408436715603f, 0.0007703963783569634f, 0.000604212807957083f, 0.000623278901912272f, 0.0006697452627122402f, 0.0007115964544937015f, 0.000481569382827729f, 0.0004759635485243052f, 0.0009806716116145253f, 0.000232211546972394f, 0.0007584067061543465f, 0.0005300832563079894f, 0.0009775125654414296f, 0.0004081286315340549f, 0.00046626542462036014f, 0.0004476782341953367f, 0.0005984770250506699f, 0.000555751787032932f, 0.000673322647344321f, 0.0004419109027367085f, 0.0008466998115181923f, 0.00050581299001351f, 0.0005045487196184695f, 0.0005378145142458379f, 0.0007557252538390458f, 0.0005441089742816985f, 0.0006525777862407267f, 0.0004711841174867004f, 0.0006416370742954314f, 0.0004771898966282606f, 0.00038020970532670617f, 0.0006578065804205835f, 0.0006788098253309727f, 0.0005402785609476268f, 0.0004234587249811739f, 0.0008551828796043992f, 0.0005841054953634739f, 0.0007887030951678753f, 0.0005289117689244449f, 0.0007104952819645405f, 0.0005337615148164332f, 0.00048200340825133026f, 0.0004825880751013756f, 0.0005279806209728122f, 0.0005170157528482378f, 0.00047931328299455345f, 0.0007979901856742799f, 0.0004152556648477912f, 0.0006099243764765561f, 0.0005717268795706332f, 0.00043790575000457466f, 0.00040654430631548166f, 0.0004787056241184473f, 0.0006702584214508533f, 0.0006618097540922463f, 0.0006266327109187841f, 0.00048501850687898695f, 0.0005274570430628955f, 0.0006087393849156797f, 0.0006066348287276924f, 0.0004051414434798062f, 0.00046013257815502584f, 0.0006556776352226734f, 0.0005090952618047595f, 0.0004575741186272353f, 0.0007313383975997567f, 0.0006363905849866569f, 0.0005444291746243834f, 0.00080585025716573f, 0.0004682909930124879f, 0.000462774041807279f, 0.0007159227970987558f, 0.0008029788150452077f, 0.000533849059138447f, 0.0005675316206179559f, 0.0006157919415272772f, 0.0006965133943594992f, 0.0006864144816063344f, 0.0005250927060842514f, 0.0005195608246140182f, 0.0005193834658712149f, 0.0005506601301021874f, 0.0004649937036447227f, 0.000553147227037698f, 0.0006481563323177397f, 0.0004519617941696197f, 0.000606519402936101f, 0.0006300908862613142f, 0.0005603753961622715f, 0.0005912863998673856f, 0.0004529012367129326f, 0.0005953919608145952f, 0.0007574636838398874f, 0.0006490136147476733f, 0.00035437208134680986f, 0.001022701384499669f, 0.0004708114720415324f, 0.0005366794066503644f, 0.0005948226316832006f, 0.00042101400322280824f, 0.0009268093854188919f, 0.00037788681220263243f, 0.0006860712310299277f, 0.0004266361065674573f, 0.0008137489785440266f, 0.000559935113415122f, 0.00047857005847617984f, 0.0006327004521153867f, 0.0006400910206139088f, 0.0006150050321593881f, 0.0005161621375009418f, 0.0005960655980743468f, 0.0005693646962754428f, 0.0005415203049778938f, 0.0004403982893563807f, 0.00022986969270277768f, 0.0005650126840919256f, 0.0007259332342073321f, 0.000825225084554404f, 0.00048397676437161863f, 0.0003935144341085106f, 0.0006048069335520267f, 0.0006782142445445061f, 0.0005040040123276412f, 0.0006219266797415912f, 0.0005775713943876326f, 0.0005723030189983547f, 0.0005261604092083871f, 0.0004136777715757489f, 0.0006510016391985118f, 0.0003711477620527148f, 0.0008484430727548897f, 0.000565148948226124f, 0.0004996229545213282f, 0.0007047158433124423f, 0.0006371288909576833f, 0.0005164679605513811f, 0.0006602545618079603f, 0.00037408925709314644f, 0.0005857291398569942f, 0.0005448313895612955f, 0.0005528033943846822f, 0.0005670376704074442f, 0.0004908349947072566f, 0.0004384942294564098f, 0.00045059810508973897f, 0.0006743719568476081f, 0.00046945916255936027f, 0.0010637949453666806f, 0.0004952295566909015f, 0.0004933882737532258f, 0.0008839324000291526f, 0.0004121631500311196f, 0.0005552440416067839f, 0.0006818153196945786f, 0.0005573878879658878f, 0.0006659036735072732f, 0.0006622769287787378f, 0.0006855711108073592f, 0.000667881453409791f, 0.0006483459146693349f, 0.00046170735731720924f, 0.0006711999885737896f, 0.0004054119635839015f, 0.0006279230583459139f, 0.0004439270996954292f, 0.00041364392382092774f, 0.0005010237800888717f, 0.0006780484691262245f, 0.0006188699044287205f, 0.0007485618116334081f, 0.0007398664602078497f, 0.0007018427713774145f, 0.0005069919279776514f, 0.0006205677054822445f, 0.0007267296896316111f, 0.0006712608737871051f, 0.0004717762640211731f, 0.0006637844489887357f, 0.0006729860906489193f, 0.000549584103282541f, 0.0005533667863346636f, 0.000570906326174736f, 0.0004708911874331534f, 0.0005045246216468513f, 0.0006691744201816618f, 0.000796972366515547f, 0.0006743445992469788f, 0.000400680088205263f, 0.0007405646028928459f, 0.000577353872358799f, 0.0005285757943056524f, 0.0006453974056057632f, 0.0004967142012901604f, 0.00041080062510445714f, 0.0005332715227268636f, 0.0004044209490530193f, 0.0006919659790582955f, 0.0006787686143070459f, 0.0004279924905858934f, 0.0006097112200222909f, 0.0006166277453303337f, 0.0006970488466322422f, 0.0004134429036639631f, 0.0006861911388114095f, 0.00037972614518366754f, 0.000513223058078438f, 0.0004649190232157707f, 0.0006224289536476135f, 0.0007049845880828798f, 0.00040287672891281545f, 0.000431270309491083f, 0.00043705973075702786f, 0.0005947923054918647f, 0.0005209697992540896f, 0.0008989498019218445f, 0.0004067760892212391f, 0.00037049781531095505f, 0.0008637809660285711f, 0.0005535801756195724f, 0.0005330599960871041f, 0.0007126458222046494f, 0.0004882237990386784f, 0.0006008687778376043f, 0.000650025496724993f, 0.000785432115662843f, 0.00044977228390052915f, 0.0006601859931834042f, 0.0008786266553215683f, 0.0006620647036470473f, 0.0006080335006117821f, 0.0005379560170695186f, 0.000429415435064584f, 0.0005562296719290316f, 0.0004638301325030625f, 0.0006545720971189439f, 0.0006020191358402371f, 0.0006260231602936983f, 0.000468363898107782f, 0.0004756282432936132f, 0.0004839037428610027f, 0.0007043115328997374f, 0.0005083874566480517f, 0.0008198422729037702f, 0.00046083240886218846f, 0.0007704695453867316f, 0.0004530599107965827f, 0.000601749459747225f, 0.0005052391206845641f, 0.0007788226357661188f, 0.0004864257061854005f, 0.000480433227494359f, 0.0005069615435786545f, 0.0004512491577770561f, 0.0006299871602095664f, 0.0007896258030086756f, 0.0003906538477167487f, 0.0007962635136209428f, 0.0005985540337860584f, 0.0004459602350834757f, 0.0004928558482788503f, 0.0005721695488318801f, 0.0006672446033917367f, 0.0004558974760584533f, 0.0005886049475520849f, 0.0006204502424225211f, 0.0006039487780071795f, 0.0006834069499745965f, 0.000536528357770294f, 0.0008255020366050303f, 0.0005002862890250981f, 0.0005015269271098077f, 0.0005914335488341749f, 0.0007861224585212767f, 0.0005058750393800437f, 0.0003903163014911115f, 0.0007164971902966499f, 0.0005916034569963813f, 0.0006492554675787687f, 0.0008037681691348553f, 0.0005283579230308533f, 0.0006748143350705504f, 0.0005823648534715176f, 0.0005761878564953804f, 0.0004753933462779969f, 0.0006529414094984531f, 0.0006372389616444707f, 0.0005698950844816864f, 0.0005011139437556267f, 0.0006200018688105047f, 0.0006218416965566576f, 0.0006908390205353498f, 0.0005334216984920204f, 0.0006026449846103787f, 0.0006985227228142321f, 0.0003998901811428368f, 0.0005005571292713284f, 0.0004005089576821774f, 0.0008119525737129152f, 0.0013317482080310583f, 0.0004676131356973201f, 0.0006335980724543333f, 0.0007122614188119769f, 0.00043567881220951676f, 0.0005790254799649119f, 0.0005619325092993677f, 0.0006877916748635471f, 0.0004873564175795764f, 0.0006898775463923812f, 0.0005869339220225811f, 0.0007017986499704421f, 0.0005362573429010808f, 0.000608613423537463f, 0.0004813479899894446f, 0.0004632841155398637f, 0.00037498658639378846f, 0.0006895568803884089f, 0.0005551922949962318f, 0.0005489796167239547f, 0.0005269189132377505f, 0.0005143108428455889f, 0.0008225154015235603f, 0.0004442068748176098f, 0.0006282920367084444f, 0.000866090296767652f, 0.00058376305969432f, 0.0007578701479360461f, 0.0005917620146647096f, 0.0004314830293878913f, 0.0005332955624908209f, 0.0007171064498834312f, 0.000553410267457366f, 0.0004935736651532352f, 0.00038999842945486307f, 0.0006760499672964215f, 0.0005606008344329894f, 0.00048558201524429023f, 0.0004465843376237899f, 0.0006284861010499299f, 0.0007348969811573625f, 0.0006386864115484059f, 0.0005103306611999869f, 0.0006747471634298563f, 0.0008208916988223791f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0078125f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv2_conv_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02074100309982896f),
    AI_PACK_UINTQ_ZP(190)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_Transpose_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0078125f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_linear7_conv_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 512,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007083159871399403f, 0.008643724024295807f, 0.010898652486503124f, 0.005970798432826996f, 0.009436649270355701f, 0.006859839893877506f, 0.006454627029597759f, 0.010515215806663036f, 0.009747945703566074f, 0.016789713874459267f, 0.012799598276615143f, 0.009217415936291218f, 0.010030983947217464f, 0.0027116239070892334f, 0.006989110726863146f, 0.006205312442034483f, 0.011845974251627922f, 0.007943146862089634f, 0.003981759771704674f, 0.007416254375129938f, 0.005694819614291191f, 0.010045980103313923f, 0.008696951903402805f, 0.0031866617500782013f, 0.004562069661915302f, 0.0040807160548865795f, 0.005737207364290953f, 0.007875203154981136f, 0.004519264679402113f, 0.005934670567512512f, 0.01082952506840229f, 0.002948580076918006f, 0.004926105495542288f, 0.006124233361333609f, 0.009884592145681381f, 0.019668910652399063f, 0.006359380669891834f, 0.010596321895718575f, 0.005678670480847359f, 0.009307987056672573f, 0.0030496178660541773f, 0.007907487452030182f, 0.0066626365296542645f, 0.0036419143434613943f, 0.010507313534617424f, 0.009128548204898834f, 0.007388012483716011f, 0.005767669063061476f, 0.00753822410479188f, 0.002540060319006443f, 0.004908823873847723f, 0.006793072912842035f, 0.0050697289407253265f, 0.006997827906161547f, 0.015692660585045815f, 0.01011313870549202f, 0.007426505442708731f, 0.014413594268262386f, 0.014489722438156605f, 0.01004506554454565f, 0.00923067145049572f, 0.009700614959001541f, 0.008232812397181988f, 0.009962263517081738f, 0.010398397222161293f, 0.003907262813299894f, 0.012038461863994598f, 0.016232503578066826f, 0.007363016717135906f, 0.0077439118176698685f, 0.01765226386487484f, 0.01097122672945261f, 0.004290811251848936f, 0.006980014033615589f, 0.00847550481557846f, 0.00930494349449873f, 0.005873935297131538f, 0.009991141967475414f, 0.006722721736878157f, 0.00656470051035285f, 0.006562801543623209f, 0.010590537451207638f, 0.0071124425157904625f, 0.007817727513611317f, 0.009324481710791588f, 0.007812182419002056f, 0.0068755242973566055f, 0.004089802969247103f, 0.00818121898919344f, 0.009476860985159874f, 0.0023097367957234383f, 0.0082018431276083f, 0.007874391041696072f, 0.007105392403900623f, 0.007951471023261547f, 0.0019364970503374934f, 0.008207695558667183f, 0.009751001372933388f, 0.013113648630678654f, 0.005844606552273035f, 0.006209402810782194f, 0.01751227118074894f, 0.00805615447461605f, 0.010997800156474113f, 0.008356030099093914f, 0.007392682135105133f, 0.011667147278785706f, 0.01355140283703804f, 0.008344164118170738f, 0.00749215530231595f, 0.005557104013860226f, 0.017317334190011024f, 0.012938165105879307f, 0.007080570328980684f, 0.011451882310211658f, 0.007892223075032234f, 0.005345567595213652f, 0.008240388706326485f, 0.015555715188384056f, 0.006774675101041794f, 0.007943370379507542f, 0.010032317601144314f, 0.006302481982856989f, 0.01385581772774458f, 0.010006229393184185f, 0.00807201024144888f, 0.00730615621432662f, 0.010278167203068733f, 0.021060926839709282f, 0.004922824911773205f, 0.012157649733126163f, 0.008788594976067543f, 0.0039021095726639032f, 0.003117052372545004f, 0.005883535370230675f, 0.00918867439031601f, 0.00489164749160409f, 0.00974609050899744f, 0.004706925246864557f, 0.010719058103859425f, 0.005626465659588575f, 0.006210152991116047f, 0.001774160540662706f, 0.00847482681274414f, 0.013312128372490406f, 0.007847617380321026f, 0.007975262589752674f, 0.00905021745711565f, 0.005113834049552679f, 0.009340394288301468f, 0.010922635905444622f, 0.014642552472651005f, 0.008920981548726559f, 0.02506553754210472f, 0.006119709461927414f, 0.008785190992057323f, 0.011145510710775852f, 0.005132994148880243f, 0.011214089579880238f, 0.005944104865193367f, 0.020707441493868828f, 0.008903410285711288f, 0.013428114354610443f, 0.01060063112527132f, 0.004682582803070545f, 0.011408847756683826f, 0.007542105857282877f, 0.012722163461148739f, 0.0055581191554665565f, 0.0027552051469683647f, 0.02071264199912548f, 0.007290555164217949f, 0.005843754392117262f, 0.008454260416328907f, 0.006062688305974007f, 0.013232216238975525f, 0.005150953773409128f, 0.026023611426353455f, 0.010577122680842876f, 0.007222955580800772f, 0.0029781677294522524f, 0.008274511434137821f, 0.012584577314555645f, 0.010253150016069412f, 0.0038271057419478893f, 0.00605239812284708f, 0.0032228974159806967f, 0.007394698448479176f, 0.006562515627592802f, 0.01025427132844925f, 0.00951638724654913f, 0.012845183722674847f, 0.0045725079253315926f, 0.010513831861317158f, 0.008722003549337387f, 0.011889507062733173f, 0.005300833843648434f, 0.013232692144811153f, 0.011274023912847042f, 0.012535094283521175f, 0.004779622424393892f, 0.00919057335704565f, 0.005924014840275049f, 0.006806686520576477f, 0.004208763130009174f, 0.004248565528541803f, 0.005743647925555706f, 0.009763437323272228f, 0.009390478953719139f, 0.007183935027569532f, 0.009408901445567608f, 0.004140661098062992f, 0.007688380312174559f, 0.007099660113453865f, 0.003678048960864544f, 0.007236755918711424f, 0.01135459914803505f, 0.04548297077417374f, 0.006898950319737196f, 0.014326697215437889f, 0.005827079061418772f, 0.003914800938218832f, 0.011895493604242802f, 0.008110499009490013f, 0.009113123640418053f, 0.012798906303942204f, 0.00611074548214674f, 0.006913082208484411f, 0.02022547647356987f, 0.016170905902981758f, 0.012883677147328854f, 0.005677114240825176f, 0.008450456894934177f, 0.006367059424519539f, 0.006251819897443056f, 0.006941531784832478f, 0.010419575497508049f, 0.007638188078999519f, 0.011849181726574898f, 0.0045996601693332195f, 0.002578594721853733f, 0.014997603371739388f, 0.0126308249309659f, 0.00855023693293333f, 0.009862272068858147f, 0.0056876735761761665f, 0.009583655744791031f, 0.005791531875729561f, 0.008846230804920197f, 0.007834319956600666f, 0.008609987795352936f, 0.007947084493935108f, 0.0038415759336203337f, 0.01327925268560648f, 0.04024152085185051f, 0.007359229028224945f, 0.004005731549113989f, 0.012106209993362427f, 0.009861111640930176f, 0.006286660674959421f, 0.011471611447632313f, 0.010468585416674614f, 0.008039646781980991f, 0.001092586200684309f, 0.009405942633748055f, 0.0317135825753212f, 0.01004328764975071f, 0.05213390290737152f, 0.01563187688589096f, 0.008848357945680618f, 0.014969347044825554f, 0.01764783263206482f, 0.009350467473268509f, 0.005962777882814407f, 0.0081566721200943f, 0.007899202406406403f, 0.0030485703609883785f, 0.009034339338541031f, 0.006599758751690388f, 0.004187222570180893f, 0.006300903856754303f, 0.00894070602953434f, 0.01397308986634016f, 0.017246682196855545f, 0.0038732802495360374f, 0.0065381089225411415f, 0.008624213747680187f, 0.01232219859957695f, 0.0063370270654559135f, 0.009837904013693333f, 0.00623528566211462f, 0.01358040701597929f, 0.013113623484969139f, 0.01107498537749052f, 0.007046596147119999f, 0.008126355707645416f, 0.012901665642857552f, 0.006867673713713884f, 0.00929538905620575f, 0.0020239504519850016f, 0.013593037612736225f, 0.008122725412249565f, 0.006687679328024387f, 0.07687915116548538f, 0.006375383585691452f, 0.006996524054557085f, 0.011620943434536457f, 0.01115451566874981f, 0.004114992450922728f, 0.007505145389586687f, 0.008071818388998508f, 0.007178335450589657f, 0.01615782082080841f, 0.004886758513748646f, 0.007945876568555832f, 0.006709001027047634f, 0.003829788649454713f, 0.012717565521597862f, 0.010104058310389519f, 0.005835999269038439f, 0.010259500704705715f, 0.011514969170093536f, 0.008373863995075226f, 0.005700979847460985f, 0.006049403455108404f, 0.007776584941893816f, 0.005869453772902489f, 0.011271131224930286f, 0.007936558686196804f, 0.008430741727352142f, 0.010933412238955498f, 0.008963938802480698f, 0.0046167499385774136f, 0.012859738431870937f, 0.007740391418337822f, 0.01659947633743286f, 0.010115469805896282f, 0.008597574196755886f, 0.007167337462306023f, 0.027732565999031067f, 0.0030398163944482803f, 0.007976719178259373f, 0.012081753462553024f, 0.012952524237334728f, 0.006602144334465265f, 0.010546836070716381f, 0.0069049266166985035f, 0.004116895608603954f, 0.009910637512803078f, 0.006972102914005518f, 0.011074108071625233f, 0.012369257397949696f, 0.006437497679144144f, 0.006748452316969633f, 0.007666454650461674f, 0.007574325893074274f, 0.008634427562355995f, 0.008960321545600891f, 0.0106329545378685f, 0.057143375277519226f, 0.003213742282241583f, 0.012047969736158848f, 0.01280296966433525f, 0.009450254030525684f, 0.009022817946970463f, 0.005361216142773628f, 0.022387100383639336f, 0.007679850794374943f, 0.00881990697234869f, 0.012334955856204033f, 0.005497276782989502f, 0.007417725399136543f, 0.0032265183981508017f, 0.013867907226085663f, 0.008275649510324001f, 0.016665322706103325f, 0.011705797165632248f, 0.006077720317989588f, 0.006209657993167639f, 0.00585866067558527f, 0.008569933474063873f, 0.008442151360213757f, 0.026977216824889183f, 0.0021920332219451666f, 0.010284226387739182f, 0.009703501127660275f, 0.002141300356015563f, 0.0110798180103302f, 0.013004693202674389f, 0.010893666185438633f, 0.009238763712346554f, 0.011872682720422745f, 0.007690120488405228f, 0.003592204535380006f, 0.006507521495223045f, 0.013701441697776318f, 0.008403133600950241f, 0.004598896950483322f, 0.011360940523445606f, 0.00739640649408102f, 0.056525591760873795f, 0.010273396037518978f, 0.007105037569999695f, 0.004677160643041134f, 0.005873754154890776f, 0.007153092883527279f, 0.006777762435376644f, 0.0066827102564275265f, 0.005919838324189186f, 0.004369966685771942f, 0.011340660974383354f, 0.004516874440014362f, 0.009865213185548782f, 0.006517116911709309f, 0.008623768575489521f, 0.007936092093586922f, 0.00732157239690423f, 0.010717642493546009f, 0.013897720724344254f, 0.009241756983101368f, 0.03326742723584175f, 0.011341867037117481f, 0.005659947171807289f, 0.0048261419869959354f, 0.0088383499532938f, 0.0059588272124528885f, 0.017349159345030785f, 0.008872080594301224f, 0.005522271152585745f, 0.006941187661141157f, 0.012518673203885555f, 0.008085067383944988f, 0.0076675922609865665f, 0.013834405690431595f, 0.009548285976052284f, 0.005462671164423227f, 0.008445977233350277f, 0.006780172698199749f, 0.006095018703490496f, 0.006890380755066872f, 0.006795786786824465f, 0.0038818144239485264f, 0.008218727074563503f, 0.010334152728319168f, 0.006795381661504507f, 0.006074333097785711f, 0.006970326416194439f, 0.004943509120494127f, 0.0073708705604076385f, 0.006783520337194204f, 0.00388103979639709f, 0.007277330849319696f, 0.00809374451637268f, 0.00673507247120142f, 0.021206282079219818f, 0.006818351335823536f, 0.00881350040435791f, 0.004176403861492872f, 0.008108450099825859f, 0.00493775587528944f, 0.0106386449187994f, 0.006200050935149193f, 0.006160524673759937f, 0.008567269891500473f, 0.01329203974455595f, 0.015285950154066086f, 0.004997457843273878f, 0.0024495888501405716f, 0.006796630565077066f, 0.0037298770621418953f, 0.006036239210516214f, 0.0070258257910609245f, 0.006132867187261581f, 0.006959810387343168f, 0.006340859457850456f, 0.010181484743952751f, 0.0034880992025136948f, 0.01069493219256401f, 0.007275895215570927f, 0.019451003521680832f, 0.00542582618072629f, 0.015271156094968319f, 0.010570988990366459f, 0.008202243596315384f, 0.00561700901016593f, 0.0063524432480335236f, 0.010559138841927052f, 0.008556973189115524f, 0.007586043793708086f, 0.009360173717141151f, 0.008237805217504501f, 0.00394368264824152f, 0.0024086751509457827f, 0.024482371285557747f, 0.0046435086987912655f, 0.010481051169335842f, 0.008329147472977638f, 0.009627058170735836f, 0.008691203780472279f, 0.010129570960998535f, 0.006489673629403114f, 0.014012984931468964f, 0.00910496711730957f, 0.009710846468806267f, 0.0064161550253629684f, 0.009285978972911835f, 0.0042562480084598064f, 0.006545762997120619f, 0.0071251289919018745f, 0.006706103216856718f, 0.004565163515508175f, 0.0036519274581223726f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv1_conv_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1508830189704895f),
    AI_PACK_INTQ_ZP(-20)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_dw_conv1_conv_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16939862072467804f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12159738689661026f),
    AI_PACK_INTQ_ZP(-71)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_linear1_conv_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009591779671609402f, 0.0006765253492631018f, 0.0009434623643755913f, 0.0006761529366485775f, 0.0006208622944541276f, 0.0010389098897576332f, 0.0006188892293721437f, 0.0007068510167300701f, 0.000661620229948312f, 0.0006718059303238988f, 0.0005855587660335004f, 0.000716424488928169f, 0.0006421931320801377f, 0.000680710538290441f, 0.0006249292055144906f, 0.0007164700073190033f, 0.0006242793751880527f, 0.0006553142447955906f, 0.0006396588287316263f, 0.0006967777735553682f, 0.0008013769402168691f, 0.0005618377472274005f, 0.0008821228984743357f, 0.0006712808972224593f, 0.0005862255929969251f, 0.0008000080706551671f, 0.0006492366665042937f, 0.0007595205679535866f, 0.0007936126203276217f, 0.0007044496014714241f, 0.0008602901943959296f, 0.0005662580369971693f, 0.0006522410549223423f, 0.0007532720337621868f, 0.000731714244466275f, 0.0006679398939013481f, 0.000636078417301178f, 0.0005759826162829995f, 0.000641991151496768f, 0.0006069600931368768f, 0.0006616084137931466f, 0.0006648565758951008f, 0.0008283188799396157f, 0.0006158487522043288f, 0.0005760913481935859f, 0.0006893922109156847f, 0.0006278501241467893f, 0.0007682340801693499f, 0.0006885058828629553f, 0.000583326444029808f, 0.0007067691185511649f, 0.0007196789374575019f, 0.0005755855236202478f, 0.0005242508486844599f, 0.0008032284094952047f, 0.0006393215153366327f, 0.0005635682609863579f, 0.0005533956573344767f, 0.0007868136162869632f, 0.0005981180584058166f, 0.000793890212662518f, 0.0008630872471258044f, 0.000579517858568579f, 0.0006448696367442608f, 0.000624898006208241f, 0.0007029929547570646f, 0.0006592109566554427f, 0.0005844775005243719f, 0.0009051674860529602f, 0.0007193167693912983f, 0.000604775152169168f, 0.0006920467130839825f, 0.0006309722666628659f, 0.000601025705691427f, 0.0008299523615278304f, 0.0007114692707546055f, 0.0006811985513195395f, 0.0007624803693033755f, 0.0006968510570004582f, 0.0006728764856234193f, 0.0006129167741164565f, 0.000594549288507551f, 0.0006886320188641548f, 0.0007482718210667372f, 0.0007151135359890759f, 0.0008699637837707996f, 0.0006294878548942506f, 0.0005697952583432198f, 0.0008553117513656616f, 0.0008237710571847856f, 0.0006619890336878598f, 0.0007651714840903878f, 0.0007221890846267343f, 0.0006319023086689413f, 0.0005924442666582763f, 0.0007321159937418997f, 0.0007749591022729874f, 0.0007835887954570353f, 0.0006751801120117307f, 0.0006414044182747602f, 0.000554678903426975f, 0.0006519741145893931f, 0.000732510699890554f, 0.0007888437830843031f, 0.0007241701823659241f, 0.0006716457428410649f, 0.0005521720158867538f, 0.0006260382942855358f, 0.0007434767321683466f, 0.0007507948321290314f, 0.0007566338172182441f, 0.0007825536304153502f, 0.0006098986486904323f, 0.0005839575314894319f, 0.0006966572836972773f, 0.0007366416393779218f, 0.0007030914421193302f, 0.0006158605101518333f, 0.0006284986156970263f, 0.0007615372887812555f, 0.0006272829486988485f, 0.000683934660628438f, 0.0006251581362448633f, 0.0006131153204478323f, 0.0006296556675806642f, 0.0006027770577929914f, 0.000589894421864301f, 0.0007719093700870872f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11788618564605713f),
    AI_PACK_INTQ_ZP(-49)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10088550299406052f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.043991271406412125f),
    AI_PACK_INTQ_ZP(-19)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08606895059347153f),
    AI_PACK_INTQ_ZP(-60)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07330581545829773f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11397679895162582f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.054299015551805496f),
    AI_PACK_INTQ_ZP(-54)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv1_conv_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16613900661468506f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07075987756252289f),
    AI_PACK_INTQ_ZP(-48)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.059588294476270676f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.132045716047287f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03988639637827873f),
    AI_PACK_INTQ_ZP(-69)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08529189974069595f),
    AI_PACK_INTQ_ZP(-73)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_dw_conv1_conv_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1575961410999298f),
    AI_PACK_INTQ_ZP(-18)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10217314958572388f),
    AI_PACK_INTQ_ZP(-13)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12673810124397278f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03549494221806526f),
    AI_PACK_INTQ_ZP(-75)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0858696848154068f),
    AI_PACK_INTQ_ZP(-69)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11497931182384491f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18872316181659698f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16730229556560516f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.036582063883543015f),
    AI_PACK_INTQ_ZP(-58)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0692368596792221f),
    AI_PACK_INTQ_ZP(-36)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04626348242163658f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02375919558107853f),
    AI_PACK_INTQ_ZP(-50)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15128810703754425f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03733665868639946f),
    AI_PACK_INTQ_ZP(-54)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03381533920764923f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.053248632699251175f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020725782960653305f),
    AI_PACK_INTQ_ZP(-64)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.045156627893447876f),
    AI_PACK_INTQ_ZP(-67)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03361879289150238f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06095561012625694f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020244795829057693f),
    AI_PACK_INTQ_ZP(-49)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.056482650339603424f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05460644140839577f),
    AI_PACK_INTQ_ZP(-72)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04032561928033829f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07134588807821274f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02220654860138893f),
    AI_PACK_INTQ_ZP(-61)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05266261473298073f),
    AI_PACK_INTQ_ZP(-65)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11343992501497269f),
    AI_PACK_INTQ_ZP(-15)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04386978968977928f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08137936145067215f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02432679571211338f),
    AI_PACK_INTQ_ZP(-55)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05782321095466614f),
    AI_PACK_INTQ_ZP(-80)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06628520786762238f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10427979379892349f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02400214970111847f),
    AI_PACK_INTQ_ZP(-62)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04733855277299881f),
    AI_PACK_INTQ_ZP(-62)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07012676447629929f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06513601541519165f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12239539623260498f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02724667266011238f),
    AI_PACK_INTQ_ZP(-54)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0718289315700531f),
    AI_PACK_INTQ_ZP(-30)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05101560801267624f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09598348289728165f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027213115245103836f),
    AI_PACK_INTQ_ZP(-24)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05526849254965782f),
    AI_PACK_INTQ_ZP(-57)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05295760557055473f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06997472792863846f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_0_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.041827552020549774f),
    AI_PACK_INTQ_ZP(-44)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_3_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.052101925015449524f),
    AI_PACK_INTQ_ZP(-49)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_6_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06989625096321106f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_Add_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09449441730976105f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.056604329496622086f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv2_conv_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09796706587076187f),
    AI_PACK_INTQ_ZP(-104)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_linear7_conv_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06625164300203323f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_linear1_conv_Conv_output_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020104819908738136f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv1_conv_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00041333824628964067f, 0.0037673760671168566f, 0.004259074572473764f, 0.00029357674065977335f, 0.0006255278713069856f, 0.005665129516273737f, 0.0009210103889927268f, 0.0003004713507834822f, 0.003775752382352948f, 0.0018906412879005075f, 0.0010824629571288824f, 0.0017956909723579884f, 0.0016121752560138702f, 0.008760958909988403f, 0.0022990733850747347f, 0.0024444134905934334f, 0.00025628184084780514f, 0.001773583935573697f, 0.0006026046467013657f, 0.0004526883130893111f, 0.010968693532049656f, 0.0021577465813606977f, 0.0005009661545045674f, 0.0027320522349327803f, 0.0001765266788424924f, 0.002815949497744441f, 0.00048550614155828953f, 0.0007952385931275785f, 0.0016703230794519186f, 0.000663788290694356f, 0.00038215192034840584f, 0.0008679446764290333f, 0.02393983118236065f, 0.0012166798114776611f, 0.0005574910901486874f, 0.0020950918551534414f, 0.0003461087471805513f, 0.0019791547674685717f, 0.002764485077932477f, 0.005118651781231165f, 0.001971583580598235f, 0.0034894966520369053f, 0.005730027798563242f, 0.004008618649095297f, 0.006868122145533562f, 0.0025699047837406397f, 0.007612671237438917f, 0.004322770982980728f, 0.0016603999538347125f, 0.005675880238413811f, 0.0016511643771082163f, 0.0029086123686283827f, 0.0007697936380282044f, 0.00037486592191271484f, 0.005574732553213835f, 0.0015392693458124995f, 0.0002761450014077127f, 0.0023408427368849516f, 0.003756724065169692f, 0.00018058183195535094f, 0.0012111836113035679f, 0.0020034320186823606f, 0.002541889902204275f, 0.009330316446721554f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10586526244878769f),
    AI_PACK_INTQ_ZP(-34)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv1_conv_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012568425387144089f),
    AI_PACK_UINTQ_ZP(81)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_dw_conv1_conv_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011266174726188183f, 0.011468530632555485f, 0.005779133643954992f, 0.004938237834721804f, 0.016998881474137306f, 0.014193514361977577f, 0.006034226156771183f, 0.0042557320557534695f, 0.005558147095143795f, 0.004118470475077629f, 0.003762108040973544f, 0.047434259206056595f, 0.003717920044437051f, 0.005544410087168217f, 0.010707040317356586f, 0.047587741166353226f, 0.0031845332123339176f, 0.10055354982614517f, 0.005681499373167753f, 0.01429749745875597f, 0.01970859244465828f, 0.03419676795601845f, 0.0059950388967990875f, 0.03818640857934952f, 0.01247592456638813f, 0.012280530296266079f, 0.002448925282806158f, 0.00602103304117918f, 0.04101800173521042f, 0.019641928374767303f, 0.012987135909497738f, 0.0035020390059798956f, 0.002089590299874544f, 0.00459362892434001f, 0.002560356864705682f, 0.026259224861860275f, 0.02311035618185997f, 0.08027935028076172f, 0.01834748312830925f, 0.014003555290400982f, 0.009946277365088463f, 0.03704870492219925f, 0.018807634711265564f, 0.012212048284709454f, 0.0038537676446139812f, 0.11318378150463104f, 0.013743332587182522f, 0.02205345407128334f, 0.0055755930952727795f, 0.03284094110131264f, 0.0037318074610084295f, 0.0029819924384355545f, 0.012812597677111626f, 0.004539220128208399f, 0.011337773874402046f, 0.0504332110285759f, 0.012066733092069626f, 0.006538668647408485f, 0.015825074166059494f, 0.006652734242379665f, 0.009782500565052032f, 0.025621499866247177f, 0.002497268607839942f, 0.011815416626632214f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_dw_conv1_conv_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012844566255807877f),
    AI_PACK_UINTQ_ZP(88)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011264211498200893f, 0.005936732050031424f, 0.0027443498838692904f, 0.002491219900548458f, 0.0013649568427354097f, 0.0008953481446951628f, 0.001241084304638207f, 0.000693719310220331f, 0.001111741061322391f, 0.0008364060195162892f, 0.0009108705562539399f, 0.003478738944977522f, 0.00436298968270421f, 0.0016504174564033747f, 0.006641581188887358f, 0.001546843210235238f, 0.004429836757481098f, 0.0012335368664935231f, 0.0024941894225776196f, 0.003890488762408495f, 0.0005751509452238679f, 0.0006164613296277821f, 0.0029956859070807695f, 0.0009500467567704618f, 0.0010439722100272775f, 0.0033209447283297777f, 0.0016946960240602493f, 0.005405200645327568f, 0.0034114751033484936f, 0.0017653906252235174f, 0.0009590538684278727f, 0.001138469553552568f, 0.001795461867004633f, 0.0009873976232483983f, 0.002903394401073456f, 0.0017160506686195731f, 0.004382629878818989f, 0.007476290222257376f, 0.0007672827923670411f, 0.0011470759054645896f, 0.001218584948219359f, 0.0014889786252751946f, 0.002054426819086075f, 0.0007435049046762288f, 0.0010991814779117703f, 0.0015610879054293036f, 0.002260379958897829f, 0.002170727588236332f, 0.0012393887154757977f, 0.0013777740532532334f, 0.0053000543266534805f, 0.0017673958791419864f, 0.0007176366052590311f, 0.002866484224796295f, 0.0007255650125443935f, 0.001967615680769086f, 0.0014465407002717257f, 0.001876847818493843f, 0.0015730009181424975f, 0.0014664678601548076f, 0.002980508143082261f, 0.001542536192573607f, 0.0022463100031018257f, 0.0014695752179250121f, 0.0026517638470977545f, 0.0009825737215578556f, 0.0013335554394870996f, 0.004577654879540205f, 0.002572653815150261f, 0.0007234368240460753f, 0.004329349379986525f, 0.004254210274666548f, 0.0014594665262848139f, 0.004404444247484207f, 0.0017446547280997038f, 0.000625116634182632f, 0.0008444518316537142f, 0.002998056821525097f, 0.004407239146530628f, 0.004288536496460438f, 0.0009811429772526026f, 0.002758844057098031f, 0.0023687302600592375f, 0.002280239248648286f, 0.006931125186383724f, 0.003908409737050533f, 0.0015898589044809341f, 0.0017713222187012434f, 0.001335142645984888f, 0.0016367044299840927f, 0.0013905110536143184f, 0.0009422579896636307f, 0.0010658157989382744f, 0.001184695865958929f, 0.0026013932656496763f, 0.0021348244044929743f, 0.0010542802046984434f, 0.001037107314914465f, 0.002465172205120325f, 0.0020734097342938185f, 0.0017332606948912144f, 0.0015240111388266087f, 0.001809029490686953f, 0.0013980261282995343f, 0.0018590923864394426f, 0.0024721811059862375f, 0.0024964078329503536f, 0.0014502655249089003f, 0.0023558028042316437f, 0.003793673124164343f, 0.0025053590070456266f, 0.0019447279628366232f, 0.0018461483996361494f, 0.004143339116126299f, 0.002435772679746151f, 0.0049433098174631596f, 0.003994780592620373f, 0.0027913940139114857f, 0.0006212426233105361f, 0.0035395610611885786f, 0.0012538823066279292f, 0.0014022019458934665f, 0.0014416169142350554f, 0.001420547254383564f, 0.0013823669869452715f, 0.005824215244501829f, 0.0005507197347469628f, 0.0065268175676465034f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.050322744995355606f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013140951283276081f),
    AI_PACK_UINTQ_ZP(103)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002818467328324914f, 0.0017649938818067312f, 0.021340949460864067f, 0.004944884218275547f, 0.0037608982529491186f, 0.013060065917670727f, 0.0065626404248178005f, 0.012735340744256973f, 0.009861081838607788f, 0.004655522294342518f, 0.006009056698530912f, 0.00320462416857481f, 0.0025931752752512693f, 0.027236690744757652f, 0.001853583729825914f, 0.005469640716910362f, 0.002482955576851964f, 0.005599338095635176f, 0.006715371739119291f, 0.003674230771139264f, 0.00867953710258007f, 0.022119954228401184f, 0.0050207749009132385f, 0.004823749419301748f, 0.01038026250898838f, 0.003098516259342432f, 0.005043841432780027f, 0.006483298726379871f, 0.004930559545755386f, 0.007203763350844383f, 0.00966756884008646f, 0.0059980363585054874f, 0.005316928960382938f, 0.00560905272141099f, 0.0036027394235134125f, 0.0112481489777565f, 0.004085104446858168f, 0.0017341343918815255f, 0.009570157155394554f, 0.0064492314122617245f, 0.005017728079110384f, 0.0063167414627969265f, 0.0054861740209162235f, 0.00794570054858923f, 0.013590066693723202f, 0.006075908429920673f, 0.0071545857936143875f, 0.010659892112016678f, 0.006583798676729202f, 0.006884754169732332f, 0.003465015906840563f, 0.008020228706300259f, 0.0068288883194327354f, 0.002673571463674307f, 0.011145024560391903f, 0.02757500484585762f, 0.01284878421574831f, 0.01141416933387518f, 0.012143570929765701f, 0.008114728145301342f, 0.0049809543415904045f, 0.013864540494978428f, 0.007853703573346138f, 0.004371662624180317f, 0.003718822030350566f, 0.0069150920026004314f, 0.010965310968458652f, 0.004536808002740145f, 0.006615126971155405f, 0.016475077718496323f, 0.003982144873589277f, 0.014376268722116947f, 0.007038499694317579f, 0.003985362593084574f, 0.005219056271016598f, 0.009552753530442715f, 0.0075684404000639915f, 0.003554469905793667f, 0.002738479757681489f, 0.0018741498934105039f, 0.02217967063188553f, 0.002574654296040535f, 0.006159365177154541f, 0.005294653121381998f, 0.002405713079497218f, 0.002923486288636923f, 0.006109010428190231f, 0.007170302327722311f, 0.013633763417601585f, 0.007816539146006107f, 0.007189638447016478f, 0.009692086838185787f, 0.011472763493657112f, 0.004925830289721489f, 0.005825176369398832f, 0.007007368374615908f, 0.009443425573408604f, 0.015684735029935837f, 0.003996442537754774f, 0.0026410571299493313f, 0.005245320964604616f, 0.006840516813099384f, 0.006978985387831926f, 0.008525465615093708f, 0.012976479716598988f, 0.007915337570011616f, 0.007157521788030863f, 0.00612664083018899f, 0.0070250327698886395f, 0.0030072780791670084f, 0.009047575294971466f, 0.009345542639493942f, 0.004615637939423323f, 0.013213304802775383f, 0.0037712757475674152f, 0.0026608884800225496f, 0.0025579144712537527f, 0.010105506516993046f, 0.006825057324022055f, 0.015895504504442215f, 0.004612640477716923f, 0.007134660147130489f, 0.005497184116393328f, 0.004181294701993465f, 0.01433855202049017f, 0.010284106247127056f, 0.014258884824812412f, 0.002786303171887994f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12111538648605347f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010038123466074467f),
    AI_PACK_UINTQ_ZP(122)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018547421786934137f, 0.0016453268472105265f, 0.0017682325560599566f, 0.002387748332694173f, 0.00244269915856421f, 0.0029216150287538767f, 0.0021156705915927887f, 0.0018591014668345451f, 0.0019713155925273895f, 0.0015066125197336078f, 0.002317935461178422f, 0.0025697830133140087f, 0.0033552502281963825f, 0.0027675421442836523f, 0.0018633939325809479f, 0.0031376827973872423f, 0.0025027391966432333f, 0.002050472656264901f, 0.0019963188096880913f, 0.0012662458466365933f, 0.002350939204916358f, 0.0028476621955633163f, 0.002043516142293811f, 0.0032792461570352316f, 0.003007932100445032f, 0.0015881736762821674f, 0.002034510252997279f, 0.0018956284038722515f, 0.0017228135839104652f, 0.002130381064489484f, 0.002196180634200573f, 0.0017624346073716879f, 0.0021961431484669447f, 0.0020198614802211523f, 0.002857039449736476f, 0.002023485489189625f, 0.0028714581858366728f, 0.0021754412446171045f, 0.001752499956637621f, 0.0016474536387249827f, 0.002615216886624694f, 0.0020511243492364883f, 0.0024462658911943436f, 0.002418356016278267f, 0.0016547472914680839f, 0.0015873509692028165f, 0.001922497060149908f, 0.0021359960082918406f, 0.002424350706860423f, 0.0024401319678872824f, 0.0015639407793059945f, 0.0021271798759698868f, 0.0021315529011189938f, 0.0019758741836994886f, 0.002351075178012252f, 0.0018115013372153044f, 0.0020681668538600206f, 0.0022694452200084925f, 0.0019320098217576742f, 0.002212895080447197f, 0.0024048301856964827f, 0.002306113950908184f, 0.0030445237644016743f, 0.002050974639132619f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005790198920294642f, 0.0006494497647508979f, 0.0005700168549083173f, 0.0007091810693964362f, 0.0009214188903570175f, 0.0006106482469476759f, 0.0008510705083608627f, 0.0010967589914798737f, 0.000504512048792094f, 0.0006778089446015656f, 0.0006326225702650845f, 0.0007351497188210487f, 0.0005052743945270777f, 0.0008310489938594401f, 0.0005170122603885829f, 0.0009411264327354729f, 0.0005330473650246859f, 0.0012586313532665372f, 0.0008952425559982657f, 0.001014122273772955f, 0.0008730789995752275f, 0.0009708704310469329f, 0.00046843153540976346f, 0.0010491744615137577f, 0.0011594585375860333f, 0.000885983114130795f, 0.0005960063426755369f, 0.0013019584584981203f, 0.0009916096460074186f, 0.0007956464542075992f, 0.0006369181210175157f, 0.0009210730786435306f, 0.0007514015887863934f, 0.0006656062905676663f, 0.0008069148170761764f, 0.0007694231462664902f, 0.0009021285804919899f, 0.0004951129085384309f, 0.000735611654818058f, 0.0008448266889899969f, 0.000676230585668236f, 0.0004512885061558336f, 0.0005255513242445886f, 0.0009965371573343873f, 0.0007788802031427622f, 0.0006691055605188012f, 0.0005757203907705843f, 0.001539012766443193f, 0.0008197578717954457f, 0.001301880576647818f, 0.0008763590594753623f, 0.0005111831123940647f, 0.00040526629891246557f, 0.0006245037075132132f, 0.0005935673252679408f, 0.0004680310084950179f, 0.0006023119785822928f, 0.0012533150147646666f, 0.0009216380422003567f, 0.0006099989404901862f, 0.0005643026670441031f, 0.0008222571923397481f, 0.0005882602417841554f, 0.0007572364411316812f, 0.0006068369257263839f, 0.0007418700261041522f, 0.001059419591911137f, 0.0010699634440243244f, 0.00086665601702407f, 0.0008643788169138134f, 0.0008353166631422937f, 0.000883171334862709f, 0.0005130438366904855f, 0.0010300383437424898f, 0.0008907584706321359f, 0.0008020585519261658f, 0.001571979490108788f, 0.0005722562200389802f, 0.0012863765005022287f, 0.0004862136847805232f, 0.0008356171892955899f, 0.0008922109846025705f, 0.0009397136163897812f, 0.0006154717411845922f, 0.0008068794850260019f, 0.0004888742696493864f, 0.00053976388880983f, 0.0009424113086424768f, 0.0006692327442578971f, 0.0005639754817821085f, 0.0013950434513390064f, 0.0006729802116751671f, 0.0011748909018933773f, 0.0008482756093144417f, 0.0010043371003121138f, 0.00034983287332579494f, 0.0008036569342948496f, 0.0009720030939206481f, 0.0008688547532074153f, 0.00048059766413643956f, 0.0005176044069230556f, 0.000801278161816299f, 0.0006604991503991187f, 0.000607487338129431f, 0.0007935800822451711f, 0.0006887647905386984f, 0.0008378758211620152f, 0.0003972087288275361f, 0.0006386781460605562f, 0.0007021076744422317f, 0.00097865320276469f, 0.0006134724244475365f, 0.0006811129860579967f, 0.0009625253733247519f, 0.000874140823725611f, 0.002171236788854003f, 0.0007328965584747493f, 0.0004761753370985389f, 0.0010903631336987019f, 0.0006036596023477614f, 0.0012690112926065922f, 0.0006660627550445497f, 0.0006286284769885242f, 0.0007873961003497243f, 0.0004199367540422827f, 0.0008441499667242169f, 0.0007958859787322581f, 0.0005595047259703279f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05702216923236847f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011511729564517736f),
    AI_PACK_UINTQ_ZP(81)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00849695224314928f, 0.015108872205018997f, 0.01126350462436676f, 0.013991575688123703f, 0.014562119729816914f, 0.005737910978496075f, 0.015314984135329723f, 0.004472592379897833f, 0.021915532648563385f, 0.011595501564443111f, 0.014353829436004162f, 0.01401316188275814f, 0.015536392107605934f, 0.005886698141694069f, 0.01708880066871643f, 0.011592986062169075f, 0.014643141068518162f, 0.006355081684887409f, 0.01196056418120861f, 0.011576976627111435f, 0.011954700574278831f, 0.0201141107827425f, 0.014902160502970219f, 0.009969343431293964f, 0.013181230053305626f, 0.009405928663909435f, 0.015304502099752426f, 0.009007561020553112f, 0.006236339453607798f, 0.013253811746835709f, 0.01569453999400139f, 0.01160514261573553f, 0.025673698633909225f, 0.027792956680059433f, 0.012419995851814747f, 0.013231253251433372f, 0.01818322390317917f, 0.01767423003911972f, 0.011242851614952087f, 0.010990929789841175f, 0.014070186764001846f, 0.009544354863464832f, 0.013482814654707909f, 0.013176577165722847f, 0.018447766080498695f, 0.013959375210106373f, 0.01590464636683464f, 0.009515291079878807f, 0.00958988256752491f, 0.005523037165403366f, 0.0058731809258461f, 0.02240816131234169f, 0.01907481998205185f, 0.02433399297297001f, 0.018363362178206444f, 0.013564543798565865f, 0.020419884473085403f, 0.012263413518667221f, 0.018290629610419273f, 0.02145667001605034f, 0.022694075480103493f, 0.013174152933061123f, 0.030404752120375633f, 0.01540555153042078f, 0.016191750764846802f, 0.010230764746665955f, 0.008167722262442112f, 0.015135331079363823f, 0.00758114131167531f, 0.010052208788692951f, 0.005079008173197508f, 0.013372732326388359f, 0.016837432980537415f, 0.007627984043210745f, 0.010907785035669804f, 0.014999959617853165f, 0.012037797830998898f, 0.014501435682177544f, 0.009945305064320564f, 0.006110697519034147f, 0.008792329579591751f, 0.008586793206632137f, 0.004999639466404915f, 0.01728512905538082f, 0.017413632944226265f, 0.013044656254351139f, 0.017693236470222473f, 0.004868352320045233f, 0.032169241458177567f, 0.012953316792845726f, 0.005869859363883734f, 0.018230712041258812f, 0.006173773668706417f, 0.011673791334033012f, 0.01592157408595085f, 0.028806420043110847f, 0.016025202348828316f, 0.01476453710347414f, 0.01267439778894186f, 0.016531990841031075f, 0.012683716602623463f, 0.017527928575873375f, 0.01596514880657196f, 0.008807969279587269f, 0.015505630522966385f, 0.019352486357092857f, 0.012200512923300266f, 0.017016787081956863f, 0.02668805606663227f, 0.027599448338150978f, 0.009345263242721558f, 0.018578512594103813f, 0.012881487607955933f, 0.020619792863726616f, 0.013135584071278572f, 0.0017485326388850808f, 0.011129499413073063f, 0.01866181753575802f, 0.022049609571695328f, 0.008964664302766323f, 0.017763864248991013f, 0.015798445791006088f, 0.009164776653051376f, 0.020499318838119507f, 0.016039177775382996f, 0.008104681968688965f, 0.019191201776266098f, 0.017384396865963936f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07701300829648972f),
    AI_PACK_INTQ_ZP(-20)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009819204453378916f),
    AI_PACK_UINTQ_ZP(100)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037899657618254423f, 0.0029408540576696396f, 0.00292956386692822f, 0.002024298068135977f, 0.0037724715657532215f, 0.0019517653854563832f, 0.0027047113981097937f, 0.002211774932220578f, 0.0027127782814204693f, 0.0023039754014462233f, 0.002906768349930644f, 0.002164189936593175f, 0.002199011156335473f, 0.0027452900540083647f, 0.0021312551107257605f, 0.0020880091469734907f, 0.0015670605935156345f, 0.0023321821354329586f, 0.0032871058210730553f, 0.0032181809656322002f, 0.002676386618986726f, 0.0023739952594041824f, 0.002020579297095537f, 0.002511589089408517f, 0.0022944097872823477f, 0.003381563350558281f, 0.0018574645509943366f, 0.0026353427674621344f, 0.003324622754007578f, 0.0026106496807187796f, 0.002754902234300971f, 0.002260812558233738f, 0.003006331156939268f, 0.0022500641644001007f, 0.0022592637687921524f, 0.0014360002242028713f, 0.002287596929818392f, 0.0026401325594633818f, 0.0022923063952475786f, 0.0030155705753713846f, 0.0026089956518262625f, 0.0029928626026958227f, 0.0033714021556079388f, 0.0023215212859213352f, 0.0029045736882835627f, 0.0030136520508676767f, 0.0024070260114967823f, 0.0028129173442721367f, 0.0037704510614275932f, 0.0018316014902666211f, 0.0023709360975772142f, 0.002629486843943596f, 0.002448379062116146f, 0.002457538153976202f, 0.0017275180434808135f, 0.00325448764488101f, 0.0029376267921179533f, 0.001821766491048038f, 0.0026697481516748667f, 0.002346551977097988f, 0.0028593444731086493f, 0.0017632782692089677f, 0.002509763464331627f, 0.003067420795559883f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007950968574732542f, 0.0006701169186271727f, 0.0008816272020339966f, 0.0008272224804386497f, 0.00054827646818012f, 0.0006342085544019938f, 0.0006013702950440347f, 0.001381132984533906f, 0.0008035108330659568f, 0.0008469501626677811f, 0.0006906854687258601f, 0.0008958798134699464f, 0.00036331743467599154f, 0.0005190486554056406f, 0.0009026348125189543f, 0.0009055401897057891f, 0.0007579494849778712f, 0.0013949733693152666f, 0.0004963505198247731f, 0.0005722920759581029f, 0.0011808123672381043f, 0.0009532999247312546f, 0.0006249753059819341f, 0.0003917081339750439f, 0.0011427192948758602f, 0.0008743200451135635f, 0.0007680726703256369f, 0.0009559536701999605f, 0.0008609061478637159f, 0.0006252510938793421f, 0.0007588376756757498f, 0.00045895305811427534f, 0.0010981245432049036f, 0.0004478443297557533f, 0.001017558854073286f, 0.0009116792352870107f, 0.0006783900898881257f, 0.0007792867254465818f, 0.0005534700467251241f, 0.00150091212708503f, 0.0011531088966876268f, 0.0006281769019551575f, 0.0010147452121600509f, 0.0004735887050628662f, 0.000831309356726706f, 0.0008213985711336136f, 0.0005884864367544651f, 0.0005588034982793033f, 0.0004459030751604587f, 0.0011694171698763967f, 0.0007915765163488686f, 0.0020028487779200077f, 0.0007035440066829324f, 0.00044309213990345597f, 0.0007497383048757911f, 0.0008473266498185694f, 0.0005781413055956364f, 0.0011167852208018303f, 0.0010265290038660169f, 0.0010074974270537496f, 0.00045385817065835f, 0.0013352122623473406f, 0.0007300822762772441f, 0.0008167788619175553f, 0.0009642562363296747f, 0.0006864577881060541f, 0.000567268521990627f, 0.0008914821082726121f, 0.0012271866435185075f, 0.00047013041330501437f, 0.0008105107117444277f, 0.0007895604358054698f, 0.0008133124210871756f, 0.0007233936339616776f, 0.0005227431538514793f, 0.0008654962875880301f, 0.000625917746219784f, 0.0009443378658033907f, 0.00116526591591537f, 0.0007054307498037815f, 0.0005826026317663491f, 0.0005702798371203244f, 0.00037105835508555174f, 0.0008817820926196873f, 0.000698479067068547f, 0.0009296551579609513f, 0.0009869156638160348f, 0.0006581899942830205f, 0.0006006347830407321f, 0.0008114451775327325f, 0.0011557491961866617f, 0.0007829857058823109f, 0.00043792405631393194f, 0.0005788392154499888f, 0.0012096200371161103f, 0.0013110402505844831f, 0.001045084442012012f, 0.0007546102278865874f, 0.0011865239357575774f, 0.001325113233178854f, 0.0014491500332951546f, 0.0009136967710219324f, 0.0006923370528966188f, 0.0009113864507526159f, 0.0005535437958315015f, 0.0006520649185404181f, 0.0005231232498772442f, 0.0007063937955535948f, 0.0007319404976442456f, 0.0008129130001179874f, 0.0009576278971508145f, 0.0010431911796331406f, 0.0007022207719273865f, 0.0010049878619611263f, 0.0006640955689363182f, 0.0006288920994848013f, 0.0003484091139398515f, 0.00046124315122142434f, 0.0011533499928191304f, 0.0003723570262081921f, 0.000802457972895354f, 0.0004658202233258635f, 0.0008095071534626186f, 0.000968164240475744f, 0.0009897984564304352f, 0.0010276113171130419f, 0.0006274642655625939f, 0.001124178059399128f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.029608849436044693f),
    AI_PACK_INTQ_ZP(-15)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012368138413876295f),
    AI_PACK_UINTQ_ZP(92)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005181569140404463f, 0.012222700752317905f, 0.012235493399202824f, 0.006046863738447428f, 0.011175532825291157f, 0.00869244709610939f, 0.016023118048906326f, 0.0033018612302839756f, 0.014285656623542309f, 0.011762457899749279f, 0.02027752809226513f, 0.00435690488666296f, 0.02925178036093712f, 0.030242733657360077f, 0.011574608273804188f, 0.00931126531213522f, 0.02012360654771328f, 0.004906310699880123f, 0.008079367689788342f, 0.012750337831676006f, 0.011146501637995243f, 0.011584036983549595f, 0.008006547577679157f, 0.01958235539495945f, 0.014167307876050472f, 0.012148203328251839f, 0.014424401335418224f, 0.00576152466237545f, 0.016677774488925934f, 0.010900389403104782f, 0.021851778030395508f, 0.016409557312726974f, 0.0032779087778180838f, 0.026149414479732513f, 0.009830540046095848f, 0.009186944924294949f, 0.013043222948908806f, 0.011227812618017197f, 0.01041294913738966f, 0.004016455262899399f, 0.0037057383451610804f, 0.01061499584466219f, 0.006508215796202421f, 0.018827611580491066f, 0.0073864092119038105f, 0.01744101382791996f, 0.012899051420390606f, 0.017879795283079147f, 0.022609444335103035f, 0.004925674293190241f, 0.015421532094478607f, 0.0037132513243705034f, 0.016102319583296776f, 0.023354511708021164f, 0.0056787109933793545f, 0.004848401062190533f, 0.020436102524399757f, 0.0046821110881865025f, 0.019750025123357773f, 0.009167291224002838f, 0.024605469778180122f, 0.01747250184416771f, 0.01665619947016239f, 0.011220438405871391f, 0.02370634488761425f, 0.014322957023978233f, 0.010842131450772285f, 0.009245350025594234f, 0.008513694629073143f, 0.01666567102074623f, 0.014611863531172276f, 0.021370701491832733f, 0.013173933140933514f, 0.019106119871139526f, 0.010995224118232727f, 0.0039634727872908115f, 0.017998695373535156f, 0.006438202690333128f, 0.021244795992970467f, 0.011674805544316769f, 0.011560431681573391f, 0.015382328070700169f, 0.020359070971608162f, 0.016338640823960304f, 0.027814799919724464f, 0.007157099433243275f, 0.015497458167374134f, 0.022228267043828964f, 0.017544306814670563f, 0.009860869497060776f, 0.008551472797989845f, 0.014741231687366962f, 0.011606220155954361f, 0.014986560679972172f, 0.007415100000798702f, 0.011410064995288849f, 0.021331509575247765f, 0.01422152854502201f, 0.01087141502648592f, 0.005637885071337223f, 0.016591012477874756f, 0.014215231873095036f, 0.015342694707214832f, 0.009894180111587048f, 0.011192108504474163f, 0.010480278171598911f, 0.026570381596684456f, 0.010294283740222454f, 0.019469331949949265f, 0.013486177660524845f, 0.011145185679197311f, 0.006018451415002346f, 0.015951620414853096f, 0.008012980222702026f, 0.010916530154645443f, 0.010719647631049156f, 0.016852399334311485f, 0.01861204206943512f, 0.010805012658238411f, 0.031114084646105766f, 0.010715840384364128f, 0.014196094125509262f, 0.015811216086149216f, 0.01739909127354622f, 0.010570475831627846f, 0.013289622962474823f, 0.01884191296994686f, 0.011733093298971653f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04608122259378433f),
    AI_PACK_INTQ_ZP(-20)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00936398096382618f),
    AI_PACK_UINTQ_ZP(114)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0030362620018422604f, 0.002783099189400673f, 0.002421634504571557f, 0.003722216235473752f, 0.0030497529078274965f, 0.002355824923142791f, 0.0018943033646792173f, 0.0022710191551595926f, 0.0031397100538015366f, 0.002557276515290141f, 0.002328655682504177f, 0.002594543853774667f, 0.00230616913177073f, 0.004024318885058165f, 0.0028210273012518883f, 0.003598905401304364f, 0.00384431891143322f, 0.0029730505775660276f, 0.0025581957306712866f, 0.0029381923377513885f, 0.0034390855580568314f, 0.002880494575947523f, 0.002964583458378911f, 0.0028517814353108406f, 0.003809003159403801f, 0.0032017077319324017f, 0.0023475864436477423f, 0.002991701476275921f, 0.003162333508953452f, 0.002935810713097453f, 0.002644410589709878f, 0.003648450830951333f, 0.0028064195066690445f, 0.0028680393006652594f, 0.0029314591083675623f, 0.0022082864306867123f, 0.004106470849364996f, 0.002290750155225396f, 0.0030336808413267136f, 0.0031412725802510977f, 0.0029063918627798557f, 0.002485723700374365f, 0.0019018392777070403f, 0.00323023134842515f, 0.002908148104324937f, 0.003312489250674844f, 0.0025047888047993183f, 0.002450584666803479f, 0.0023273315746337175f, 0.002254426246508956f, 0.0035470128059387207f, 0.002409192267805338f, 0.002995448186993599f, 0.002605981659144163f, 0.0017723519122228026f, 0.0026816970203071833f, 0.0030865182634443045f, 0.0014169452479109168f, 0.0030069469939917326f, 0.003744314191862941f, 0.003639300586655736f, 0.0033492317888885736f, 0.003048212267458439f, 0.002557911444455385f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001030723680742085f, 0.0004629611794371158f, 0.0010116863995790482f, 0.00028103619115427136f, 0.0008884846465662122f, 0.0005089565529488027f, 0.0008456826326437294f, 0.0004998287768103182f, 0.0004255584208294749f, 0.0008079156978055835f, 0.00026611844077706337f, 0.0009791473858058453f, 0.0003226506232749671f, 0.0006021691369824111f, 0.0006362521671690047f, 0.0004959081416018307f, 0.0005613642861135304f, 0.0007676950772292912f, 0.0010804084595292807f, 0.0007746786577627063f, 0.000612662872299552f, 0.0006945102359168231f, 0.0006039965664967895f, 0.0004041063948534429f, 0.0006718477234244347f, 0.00041471360600553453f, 0.0007292145164683461f, 0.0002874795172829181f, 0.000648997665848583f, 0.0007356404676102102f, 0.0006487180362455547f, 0.0009273183532059193f, 0.0010334805119782686f, 0.0006296930368989706f, 0.0008344552479684353f, 0.0010820876341313124f, 0.0003990455879829824f, 0.0004546519194263965f, 0.00046920086606405675f, 0.0005337528418749571f, 0.000614182383287698f, 0.0010065787937492132f, 0.0002517460670787841f, 0.0004933716845698655f, 0.0007601863471791148f, 0.00048135529505088925f, 0.0006537201697938144f, 0.0013290992937982082f, 0.0006714744376949966f, 0.0005427133291959763f, 0.0015148500679060817f, 0.0010032549034804106f, 0.000551926379557699f, 0.0009194749291054904f, 0.0008446432184427977f, 0.00048098459956236184f, 0.0004888860275968909f, 0.0010097137419506907f, 0.0009452153462916613f, 0.0008082286803983152f, 0.000519619497936219f, 0.0003829557099379599f, 0.0005156219122000039f, 0.0011232757242396474f, 0.0005529756308533251f, 0.0003936831490136683f, 0.001037089852616191f, 0.00047503376845270395f, 0.0004984053084626794f, 0.0008649532101117074f, 0.0005434096092358232f, 0.00048411835450679064f, 0.0009750864701345563f, 0.0006408179760910571f, 0.0008650177041999996f, 0.000453938206192106f, 0.0007537154015153646f, 0.00029536819783970714f, 0.0010779135627672076f, 0.0006579773034900427f, 0.0009907251223921776f, 0.0009431514190509915f, 0.0009323787526227534f, 0.0004347414942458272f, 0.0005701480549760163f, 0.0007239204715006053f, 0.0012823244323953986f, 0.0007276498363353312f, 0.0006889435462653637f, 0.0007633748464286327f, 0.001411883276887238f, 0.0006606673123314977f, 0.0003381294081918895f, 0.0007664342992939055f, 0.0005083868745714426f, 0.0007086719269864261f, 0.0007108867284841835f, 0.00027151446556672454f, 0.0008225726196542382f, 0.0007335501722991467f, 0.0008242075564339757f, 0.00035774821299128234f, 0.000579331477638334f, 0.0007171990582719445f, 0.0005662698531523347f, 0.00036943372106179595f, 0.0004583625996019691f, 0.0007856403244659305f, 0.0008757592877373099f, 0.001164123765192926f, 0.0005820924998261034f, 0.0006321212858892977f, 0.0013268936891108751f, 0.0007714241510257125f, 0.0005697018932551146f, 0.0004377408477012068f, 0.0007558566285297275f, 0.000946042884606868f, 0.0007540691876783967f, 0.00038609476177953184f, 0.0011655517155304551f, 0.0006195743335410953f, 0.0009732475155033171f, 0.0008384126704186201f, 0.0006811025668866932f, 0.0008162616868503392f, 0.0008462207624688745f, 0.0007128759752959013f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010090300347656012f),
    AI_PACK_UINTQ_ZP(108)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02908223867416382f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008479620330035686f, 0.007430311292409897f, 0.00992428045719862f, 0.018062809482216835f, 0.015397325158119202f, 0.01809092052280903f, 0.00791140552610159f, 0.008764299564063549f, 0.00997451227158308f, 0.007682421710342169f, 0.036828406155109406f, 0.011958643794059753f, 0.017135294154286385f, 0.00756095489487052f, 0.010732962749898434f, 0.012331485748291016f, 0.01622711308300495f, 0.004429654683917761f, 0.011263024993240833f, 0.010192534886300564f, 0.006808996666222811f, 0.008623464033007622f, 0.027237247675657272f, 0.028558503836393356f, 0.012634584680199623f, 0.0222203116863966f, 0.012027090415358543f, 0.026323912665247917f, 0.0102846072986722f, 0.013480504043400288f, 0.011307814158499241f, 0.01146144699305296f, 0.00401384849101305f, 0.004854578524827957f, 0.010201038792729378f, 0.004867809358984232f, 0.013241179287433624f, 0.02124561183154583f, 0.013099165633320808f, 0.023188132792711258f, 0.011557616293430328f, 0.017303451895713806f, 0.02013406902551651f, 0.015245581045746803f, 0.007825864478945732f, 0.009840195998549461f, 0.006628396455198526f, 0.03324127197265625f, 0.0073948632925748825f, 0.013671950437128544f, 0.02155117876827717f, 0.005636297632008791f, 0.017495259642601013f, 0.011168030090630054f, 0.009148627519607544f, 0.01733817718923092f, 0.013399719260632992f, 0.01474898774176836f, 0.011831546202301979f, 0.014007247984409332f, 0.013261358253657818f, 0.015324810519814491f, 0.02011820860207081f, 0.014696743339300156f, 0.015764111652970314f, 0.019878773018717766f, 0.00686699477955699f, 0.00997840240597725f, 0.013587933033704758f, 0.010928458534181118f, 0.01324128732085228f, 0.012164486572146416f, 0.013785288669168949f, 0.005762211512774229f, 0.017630675807595253f, 0.027864376083016396f, 0.007081665098667145f, 0.016215257346630096f, 0.011727945879101753f, 0.011572634801268578f, 0.0026164446026086807f, 0.008266919292509556f, 0.011050086468458176f, 0.021635310724377632f, 0.012293477542698383f, 0.005980063229799271f, 0.0034554169978946447f, 0.010474546812474728f, 0.011254874058067799f, 0.009586730040609837f, 0.0032818419858813286f, 0.013429212383925915f, 0.02319403365254402f, 0.004267155658453703f, 0.016009604558348656f, 0.0051803989335894585f, 0.01465071365237236f, 0.01857597380876541f, 0.004010926466435194f, 0.014713143929839134f, 0.011868509463965893f, 0.022752197459340096f, 0.01096938457340002f, 0.0107973488047719f, 0.01323081273585558f, 0.018357323482632637f, 0.013581527397036552f, 0.008265979588031769f, 0.004344360902905464f, 0.008054283447563648f, 0.010260005481541157f, 0.004157563205808401f, 0.01400339137762785f, 0.01255964394658804f, 0.018035873770713806f, 0.021087996661663055f, 0.016184723004698753f, 0.01310912985354662f, 0.013698374852538109f, 0.025103969499468803f, 0.003425048664212227f, 0.012124467641115189f, 0.017848065122961998f, 0.003357815556228161f, 0.010229638777673244f, 0.006617805454879999f, 0.012014443054795265f, 0.008978860452771187f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009668180719017982f),
    AI_PACK_UINTQ_ZP(138)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.056043222546577454f),
    AI_PACK_INTQ_ZP(-30)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035395538434386253f, 0.0035813862923532724f, 0.0029272695537656546f, 0.003180800238624215f, 0.003045592224225402f, 0.003739091334864497f, 0.0022353085223585367f, 0.0043307519517838955f, 0.004537298809736967f, 0.002098456956446171f, 0.003338683396577835f, 0.004214901942759752f, 0.004272612743079662f, 0.003578854026272893f, 0.0035727089270949364f, 0.002934680785983801f, 0.0024215136654675007f, 0.003924690652638674f, 0.0028923326171934605f, 0.0036091224756091833f, 0.003488446120172739f, 0.0028344853781163692f, 0.0026232413947582245f, 0.003035331843420863f, 0.003303147153928876f, 0.0028035317081958055f, 0.0026051599998027086f, 0.0035602417774498463f, 0.003130195429548621f, 0.0034115721937268972f, 0.0034723742865025997f, 0.004715898539870977f, 0.0017909654416143894f, 0.004174135159701109f, 0.004501991905272007f, 0.0029141067061573267f, 0.004758329130709171f, 0.004633514676243067f, 0.004690852947533131f, 0.006274363026022911f, 0.003109605982899666f, 0.003604243276640773f, 0.003078328212723136f, 0.003758864477276802f, 0.004157828167080879f, 0.0029263938777148724f, 0.003658947302028537f, 0.0036307331174612045f, 0.004796170629560947f, 0.0022008453961461782f, 0.003494555363431573f, 0.003524661296978593f, 0.003862974001094699f, 0.0030463680159300566f, 0.00187281658872962f, 0.0028258736710995436f, 0.003213838441297412f, 0.0033036202657967806f, 0.0035701668821275234f, 0.0033020437695086002f, 0.004696022719144821f, 0.0020817508921027184f, 0.0031879039015620947f, 0.0037814679089933634f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00048250710824504495f, 0.0008744967053644359f, 0.0007972927996888757f, 0.0007227009045891464f, 0.0007802866748534143f, 0.0006930556264705956f, 0.0004643249558284879f, 0.000994534813798964f, 0.0004136112693231553f, 0.000416670081904158f, 0.0009424001327715814f, 0.00025867586373351514f, 0.000324441323755309f, 0.00030145482742227614f, 0.0007917290204204619f, 0.0003838542615994811f, 0.00039261323399841785f, 0.0006497104768641293f, 0.00022653673659078777f, 0.0005559477722272277f, 0.0005618055001832545f, 0.00038453523302450776f, 0.0012926757335662842f, 0.00032935815397650003f, 0.0008592666126787663f, 0.0004909317358396947f, 0.0010871987324208021f, 0.00035622884752228856f, 0.0005089232581667602f, 0.0005716155283153057f, 0.0006832696963101625f, 0.000469396123662591f, 0.0005805045948363841f, 0.0009712803293950856f, 0.0008077690727077425f, 0.0005732484860345721f, 0.000565770547837019f, 0.00037455742130987346f, 0.00037541266647167504f, 0.0006697609205730259f, 0.0007110268343240023f, 0.0005044993013143539f, 0.00048582686576992273f, 0.0004997642245143652f, 0.0002810454461723566f, 0.00039371641469188035f, 0.000581833824981004f, 0.00042580344597809017f, 0.0006123375496827066f, 0.000410950044170022f, 0.000493485014885664f, 0.0003968402452301234f, 0.0005544699961319566f, 0.0007206860464066267f, 0.0008018253138288856f, 0.00029628886841237545f, 0.0008320736815221608f, 0.00042766841943375766f, 0.0003250243025831878f, 0.0005391595186665654f, 0.0005243233754299581f, 0.0007321961456909776f, 0.00041424529626965523f, 0.00025899126194417477f, 0.000691724824719131f, 0.0006408414337784052f, 0.00041361356852576137f, 0.00042408754234202206f, 0.001120063941925764f, 0.00024273827148135751f, 0.0005587429623119533f, 0.0005949507467448711f, 0.0008245799108408391f, 0.0010314843384549022f, 0.00040994814480654895f, 0.0005831900052726269f, 0.0005374479223974049f, 0.0007300526485778391f, 0.0005434957565739751f, 0.00032521688262932f, 0.000339442805852741f, 0.0006959312595427036f, 0.0004464067460503429f, 0.00038352160481736064f, 0.0005346261314116418f, 0.0008710328838787973f, 0.0006612195866182446f, 0.00043824891326949f, 0.0007554270559921861f, 0.0008306148811243474f, 0.0006711257738061249f, 0.0007296940893866122f, 0.0007375133573077619f, 0.0005976983229629695f, 0.0003445053880568594f, 0.0004796181747224182f, 0.0008356397738680243f, 0.00036512321094051003f, 0.0006431041401810944f, 0.0005918907700106502f, 0.0007186805014498532f, 0.0006785283330827951f, 0.00033934350358322263f, 0.0004621381522156298f, 0.0007777627906762064f, 0.0006381070124916732f, 0.0003893209504894912f, 0.0005217322614043951f, 0.0009416125249117613f, 0.0006114026182331145f, 0.0008492784691043198f, 0.0003330710460431874f, 0.0006492215907201171f, 0.00040114184957928956f, 0.0003388177719898522f, 0.0005184793844819069f, 0.00041687817429192364f, 0.0004442821373231709f, 0.0004143619735259563f, 0.0004127343709114939f, 0.0006328750750981271f, 0.0008423983817920089f, 0.0002937004610430449f, 0.0005412928876467049f, 0.0004670446505770087f, 0.00047230010386556387f, 0.0005380392540246248f, 0.00038601233973167837f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008830939419567585f),
    AI_PACK_UINTQ_ZP(122)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02881496213376522f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012429402209818363f, 0.0025728666223585606f, 0.004893811419606209f, 0.009470240212976933f, 0.009977072477340698f, 0.0076464940793812275f, 0.023264426738023758f, 0.009377861395478249f, 0.018732424825429916f, 0.013673646375536919f, 0.017305564135313034f, 0.022800395265221596f, 0.014206703752279282f, 0.01164000853896141f, 0.008523681201040745f, 0.014211582951247692f, 0.016423378139734268f, 0.022793501615524292f, 0.024377798661589622f, 0.017624106258153915f, 0.008920579217374325f, 0.01278985757380724f, 0.0037480138707906008f, 0.02304706536233425f, 0.004661176819354296f, 0.011250089854001999f, 0.006956229917705059f, 0.01654946617782116f, 0.015778882429003716f, 0.009307867847383022f, 0.025269804522395134f, 0.013000310398638248f, 0.011496012099087238f, 0.008061353117227554f, 0.01344310026615858f, 0.016694922000169754f, 0.014814975671470165f, 0.016022929921746254f, 0.00977057870477438f, 0.005338060203939676f, 0.019844328984618187f, 0.011809415183961391f, 0.010008982382714748f, 0.007488874718546867f, 0.012302697636187077f, 0.028325850144028664f, 0.021974194794893265f, 0.012994356453418732f, 0.011788109317421913f, 0.014773329719901085f, 0.006731386762112379f, 0.015296299941837788f, 0.010397268459200859f, 0.008662733249366283f, 0.004820013884454966f, 0.008086484856903553f, 0.011003999039530754f, 0.016529984772205353f, 0.01727963052690029f, 0.01088640745729208f, 0.020629532635211945f, 0.0033787614665925503f, 0.015393976122140884f, 0.029305141419172287f, 0.012871178798377514f, 0.006667050067335367f, 0.017709506675601006f, 0.017858881503343582f, 0.010647439397871494f, 0.021279605105519295f, 0.012602061033248901f, 0.014356190338730812f, 0.012247774749994278f, 0.005000145640224218f, 0.019307883456349373f, 0.011495465412735939f, 0.008527296595275402f, 0.010013111867010593f, 0.005070385057479143f, 0.014633153565227985f, 0.01611190289258957f, 0.017297288402915f, 0.018763739615678787f, 0.014218387193977833f, 0.009041856043040752f, 0.003974579740315676f, 0.009419168345630169f, 0.02258172258734703f, 0.00501949992030859f, 0.013713881373405457f, 0.004899417981505394f, 0.013117038644850254f, 0.010735675692558289f, 0.011906427331268787f, 0.010735505260527134f, 0.014584708958864212f, 0.0065003130584955215f, 0.02485988661646843f, 0.018997060135006905f, 0.004764022305607796f, 0.009598542004823685f, 0.009338408708572388f, 0.012538147158920765f, 0.0051492806524038315f, 0.004778631497174501f, 0.011405599303543568f, 0.018337471410632133f, 0.01620832271873951f, 0.004987642168998718f, 0.018550176173448563f, 0.01647871732711792f, 0.016213851049542427f, 0.02455093525350094f, 0.01792851835489273f, 0.01195900235325098f, 0.009586776606738567f, 0.00827514287084341f, 0.029412470757961273f, 0.01174196321517229f, 0.009334550239145756f, 0.015317698009312153f, 0.00653271796181798f, 0.016685977578163147f, 0.005569279659539461f, 0.017751501873135567f, 0.008094907738268375f, 0.0039149075746536255f, 0.00797805655747652f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010570879559963942f),
    AI_PACK_UINTQ_ZP(132)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005386644974350929f, 0.005638387985527515f, 0.0035398253239691257f, 0.005174167454242706f, 0.003284079022705555f, 0.0032172028440982103f, 0.0016483020735904574f, 0.004092076327651739f, 0.004954791162163019f, 0.0022668386809527874f, 0.005071752704679966f, 0.0028486978262662888f, 0.004513791296631098f, 0.0033245885279029608f, 0.0038264677859842777f, 0.005157901905477047f, 0.0026490665040910244f, 0.004117191303521395f, 0.004306122660636902f, 0.0046021235175430775f, 0.004551890771836042f, 0.004513933788985014f, 0.004025125410407782f, 0.0038971153553575277f, 0.0045331502333283424f, 0.004972384311258793f, 0.003593807341530919f, 0.004366699140518904f, 0.004473768174648285f, 0.004118211567401886f, 0.00437573716044426f, 0.004292050376534462f, 0.0027100732550024986f, 0.004045787267386913f, 0.005129225552082062f, 0.0023161182180047035f, 0.005212117452174425f, 0.004490502644330263f, 0.0031197364442050457f, 0.006248957477509975f, 0.00639641098678112f, 0.003725980641320348f, 0.004395873751491308f, 0.003799053840339184f, 0.00362755311653018f, 0.00388719467446208f, 0.004118036478757858f, 0.004999612923711538f, 0.003074224339798093f, 0.004080059472471476f, 0.0030594044364988804f, 0.004480719566345215f, 0.005009844899177551f, 0.004066725727170706f, 0.003574497764930129f, 0.003588450141251087f, 0.003904836717993021f, 0.0033426103182137012f, 0.0038671072106808424f, 0.0051012844778597355f, 0.004726024344563484f, 0.0035576033405959606f, 0.005408340133726597f, 0.003934216219931841f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0670747384428978f),
    AI_PACK_INTQ_ZP(-35)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006237850175239146f, 0.0008475934155285358f, 0.000608521222602576f, 0.0007218169048428535f, 0.0002838649961631745f, 0.0003278320364188403f, 0.00038634726661257446f, 0.0007875540759414434f, 0.00033146733767353f, 0.00047220877604559064f, 0.0004466527025215328f, 0.0006207608385011554f, 0.0005860697710886598f, 0.0008807950653135777f, 0.0007485588430427015f, 0.00026714600971899927f, 0.000578184612095356f, 0.00041321691242046654f, 0.00039379886584356427f, 0.0008894190541468561f, 0.00045480261906050146f, 0.0007176700164563954f, 0.0008378491620533168f, 0.0007576683419756591f, 0.0006580452900379896f, 0.000381515797926113f, 0.00033651560079306364f, 0.0007376568391919136f, 0.00033517793053761125f, 0.0004629754985217005f, 0.00033181405160576105f, 0.0006057785358279943f, 0.00023057774524204433f, 0.0007833610288798809f, 0.0003259071090724319f, 0.0003164905065204948f, 0.0008710771799087524f, 0.0009086632053367794f, 0.0005364317330531776f, 0.00041946672718040645f, 0.00036179577000439167f, 0.0007371112587861717f, 0.000256452796747908f, 0.0006298720836639404f, 0.0007002641796134412f, 0.00044806007645092905f, 0.0005073482170701027f, 0.0008475885260850191f, 0.00043993504368700087f, 0.000816561805550009f, 0.00038919190410524607f, 0.0006006192415952682f, 0.0008980696438811719f, 0.0006865154136903584f, 0.0010797601426020265f, 0.0002116241812473163f, 0.000736803631298244f, 0.0007734044338576496f, 0.0005935573135502636f, 0.0002572688099462539f, 0.0004243271250743419f, 0.00016878405585885048f, 0.00027631563716568053f, 0.0007524669636040926f, 0.0006288734148256481f, 0.0007039605407044291f, 0.0009496029815636575f, 0.0006065219058655202f, 0.0003835969546344131f, 0.0006624755915254354f, 0.00040490980609320104f, 0.0006447311607189476f, 0.00035665908944793046f, 0.0004096546908840537f, 0.0004369664238765836f, 0.0008126332540996373f, 0.0006417258409783244f, 0.0005405633710324764f, 0.0006560117471963167f, 0.000788204837590456f, 0.0005039142561145127f, 0.0008756107999943197f, 0.0007280352292582393f, 0.0003885560145135969f, 0.00029168344917707145f, 0.0005510030314326286f, 0.0007465885719284415f, 0.0007369039813056588f, 0.0006640729261562228f, 0.0008208067738451064f, 0.0009208843694068491f, 0.0009410641505382955f, 0.00035728636430576444f, 0.00023052333563100547f, 0.0007316647097468376f, 0.00034122413489967585f, 0.00048122002044692636f, 0.000471927021862939f, 0.0009714639745652676f, 0.0003376669774297625f, 0.0004556262865662575f, 0.00048306206008419394f, 0.00039056589594110847f, 0.0006827093893662095f, 0.0004012426652479917f, 0.000617699814029038f, 0.0008210214436985552f, 0.00042049287003464997f, 0.000444681296357885f, 0.000763176882173866f, 0.0005384174874052405f, 0.0004918902995996177f, 0.0008231471874751151f, 0.0007202436099760234f, 0.0004442344361450523f, 0.00036836290382780135f, 0.000673554081004113f, 0.0006039164727553725f, 0.00045899287215434015f, 0.0008344492525793612f, 0.0008487402810715139f, 0.0004708393826149404f, 0.0004619417304638773f, 0.0009719157824292779f, 0.000946531945373863f, 0.0008793587912805378f, 0.0007404849748127162f, 0.0009247397538274527f, 0.0002788700512610376f, 0.00046112490235827863f, 0.0003517168515827507f, 0.0003164929512422532f, 0.0005901154363527894f, 0.00038487365236505866f, 0.0005639888695441186f, 0.0006689002038910985f, 0.0005509862094186246f, 0.00031349810888059437f, 0.0006230134749785066f, 0.0008868580916896462f, 0.0007783400360494852f, 0.0007301458972506225f, 0.0006337583181448281f, 0.0007054790621623397f, 0.0006287450669333339f, 0.00031899884925223887f, 0.0007384908385574818f, 0.000638195953797549f, 0.00037057240842841566f, 0.00064755545463413f, 0.0003046964411623776f, 0.0009663536911830306f, 0.0005495320656336844f, 0.0011576698161661625f, 0.000522166898008436f, 0.0010828070808202028f, 0.0003828608605545014f, 0.00042770805885083973f, 0.0004794707929249853f, 0.0003154129663016647f, 0.0006297287764027715f, 0.00042028602911159396f, 0.0005710141849704087f, 0.000586837122682482f, 0.0003602904034778476f, 0.00038833694998174906f, 0.00040462228935211897f, 0.0006437680567614734f, 0.0004835977451875806f, 0.0006613400764763355f, 0.0002582265587989241f, 0.0003985979419667274f, 0.0004531790327746421f, 0.0008446299470961094f, 0.001255231094546616f, 0.0006923690671101213f, 0.00037097182939760387f, 0.0005312953144311905f, 0.0005216197459958494f, 0.0004748861538246274f, 0.0009003348532132804f, 0.00045221796608529985f, 0.0006128498935140669f, 0.0005590250948444009f, 0.0005666310316883028f, 0.0005558467237278819f, 0.0007717587286606431f, 0.0005368514684960246f, 0.0006319109816104174f, 0.00040287565207108855f, 0.0007017240859568119f, 0.0005437075742520392f, 0.0004224067088216543f, 0.000368369510397315f, 0.00033316007466055453f, 0.00047980211093090475f, 0.0006487807841040194f, 0.0008462666301056743f, 0.00027271040016785264f, 0.0004480619099922478f, 0.0006734855123795569f, 0.000791045546066016f, 0.0006336810765787959f, 0.00024096143897622824f, 0.0006260243244469166f, 0.0005466180737130344f, 0.0009590786066837609f, 0.000868523376993835f, 0.0006483625038526952f, 0.0003151508863084018f, 0.0005857803043909371f, 0.0005893565830774605f, 0.00038310495438054204f, 0.0003643931995611638f, 0.0006096786237321794f, 0.0004658249963540584f, 0.0007008310058154166f, 0.0003565532388165593f, 0.0003857071278616786f, 0.0006743294070474803f, 0.00045110221253708005f, 0.0002744181838352233f, 0.0005541528807953f, 0.0007580218953080475f, 0.0005717911990359426f, 0.0006519588641822338f, 0.00030653763678856194f, 0.00042049153125844896f, 0.0004293584206607193f, 0.0004186370351817459f, 0.00022516211902257055f, 0.0003613624139688909f, 0.0006501853931695223f, 0.00031897021108306944f, 0.0008225208148360252f, 0.00035204854793846607f, 0.0003674417093861848f, 0.0007845287909731269f, 0.00046479416778311133f, 0.0008892134064808488f, 0.0002335416793357581f, 0.00027372001204639673f, 0.0004759735893458128f, 0.0004479843482840806f, 0.0008880458190105855f, 0.0003985248040407896f, 0.0002334955643163994f, 0.0009307893342338502f, 0.0004962540697306395f, 0.00036963465390726924f, 0.0005990398349240422f, 0.00046786345774307847f, 0.00045292091090232134f, 0.0007097916677594185f, 0.0005526976892724633f, 0.0007991986931301653f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011646952480077744f),
    AI_PACK_UINTQ_ZP(95)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0074719456024467945f, 0.0041138846427202225f, 0.005988390184938908f, 0.005309442523866892f, 0.014005657285451889f, 0.0056511759757995605f, 0.004039270803332329f, 0.007466139737516642f, 0.009147251956164837f, 0.009204676374793053f, 0.00806646328419447f, 0.004858571570366621f, 0.0054685091599822044f, 0.004957611206918955f, 0.005703201983124018f, 0.008154102601110935f, 0.0061131068505346775f, 0.009393230080604553f, 0.004129637964069843f, 0.004388489760458469f, 0.005108293611556292f, 0.0028528159018605947f, 0.00603265268728137f, 0.008154553361237049f, 0.007696773391216993f, 0.009354534558951855f, 0.010823894292116165f, 0.0035992590710520744f, 0.009134923107922077f, 0.008097842335700989f, 0.008248385973274708f, 0.007739989552646875f, 0.007347951643168926f, 0.004789747763425112f, 0.012281329371035099f, 0.010356266051530838f, 0.005398628301918507f, 0.004941414576023817f, 0.008320209570229053f, 0.008333672769367695f, 0.007421183865517378f, 0.00593081209808588f, 0.01094876416027546f, 0.006841457448899746f, 0.0055417935363948345f, 0.012524133548140526f, 0.011159585788846016f, 0.00834997184574604f, 0.007874717935919762f, 0.0038777622394263744f, 0.0063604917377233505f, 0.0059525868855416775f, 0.0032283731270581484f, 0.006965444423258305f, 0.003953296225517988f, 0.009604834951460361f, 0.005297021474689245f, 0.005148905795067549f, 0.003571663983166218f, 0.011048895306885242f, 0.006229134276509285f, 0.022728227078914642f, 0.009165242314338684f, 0.00593904173001647f, 0.005271548870950937f, 0.005423584952950478f, 0.004184394143521786f, 0.007128293626010418f, 0.008809981867671013f, 0.005823713261634111f, 0.013464061543345451f, 0.006738480646163225f, 0.00851303432136774f, 0.006864449940621853f, 0.01074592862278223f, 0.006731232162564993f, 0.004648881498724222f, 0.007089241873472929f, 0.009082958102226257f, 0.0060750218108296394f, 0.007714469451457262f, 0.0049771154299378395f, 0.004783165641129017f, 0.009393149055540562f, 0.011806693859398365f, 0.009012890048325062f, 0.006263632792979479f, 0.004723353311419487f, 0.005304079037159681f, 0.0059975082986056805f, 0.004896844271570444f, 0.0048995050601661205f, 0.009524120949208736f, 0.01546839252114296f, 0.005092342849820852f, 0.013841638341546059f, 0.007978018373250961f, 0.01318675372749567f, 0.003781199688091874f, 0.013467706739902496f, 0.009258446283638477f, 0.007952718064188957f, 0.012837185524404049f, 0.007460976019501686f, 0.01411070954054594f, 0.007097880821675062f, 0.005750543437898159f, 0.0061540561728179455f, 0.0066765714436769485f, 0.006013026461005211f, 0.0068671745248138905f, 0.008649700321257114f, 0.003116140142083168f, 0.005715848412364721f, 0.012313694693148136f, 0.010471601970493793f, 0.004393840674310923f, 0.005707033444195986f, 0.0066820778883993626f, 0.0029498175717890263f, 0.003768700873479247f, 0.010553079657256603f, 0.006840264890342951f, 0.004634215962141752f, 0.005014254245907068f, 0.004379148129373789f, 0.006841321941465139f, 0.005465859081596136f, 0.01622532680630684f, 0.006753233727067709f, 0.005758504383265972f, 0.007477636449038982f, 0.006370940245687962f, 0.010788610205054283f, 0.005177519749850035f, 0.006345306523144245f, 0.0051195682026445866f, 0.014154752716422081f, 0.0051698279567062855f, 0.003481638617813587f, 0.003614091780036688f, 0.0053751603700220585f, 0.005402442533522844f, 0.006247929763048887f, 0.004620842635631561f, 0.012661168351769447f, 0.004336414393037558f, 0.013844271190464497f, 0.004256166983395815f, 0.005575134418904781f, 0.010120600461959839f, 0.004899205174297094f, 0.007757831364870071f, 0.0035449888091534376f, 0.005568399094045162f, 0.0055921911261975765f, 0.00859666708856821f, 0.006445405073463917f, 0.008355681784451008f, 0.01012186985462904f, 0.004900595638900995f, 0.00575680797919631f, 0.007584012113511562f, 0.005993337836116552f, 0.007375854067504406f, 0.008822893723845482f, 0.01241487730294466f, 0.006958686280995607f, 0.007564397994428873f, 0.005071735475212336f, 0.011841562576591969f, 0.005927829071879387f, 0.008698651567101479f, 0.005295300390571356f, 0.005127504467964172f, 0.006715699564665556f, 0.009960092604160309f, 0.006800992414355278f, 0.00545428367331624f, 0.014256734400987625f, 0.006916295737028122f, 0.005104443058371544f, 0.0063441162928938866f, 0.008907323703169823f, 0.004683880601078272f, 0.0061815413646399975f, 0.005988590884953737f, 0.004233981017023325f, 0.0057058027014136314f, 0.005253576673567295f, 0.006546766497194767f, 0.007085097953677177f, 0.0059362477622926235f, 0.011262336745858192f, 0.01307903416454792f, 0.0057342867366969585f, 0.00736435130238533f, 0.003927961923182011f, 0.008528109639883041f, 0.009643164463341236f, 0.004601005464792252f, 0.004915402736514807f, 0.006950929295271635f, 0.016582123935222626f, 0.009609872475266457f, 0.00754125090315938f, 0.005677618086338043f, 0.006258273497223854f, 0.006424672435969114f, 0.00813782773911953f, 0.0063168988563120365f, 0.00634047482162714f, 0.010032049380242825f, 0.00973130576312542f, 0.00567900575697422f, 0.011849986389279366f, 0.004918248392641544f, 0.00876135379076004f, 0.008214830420911312f, 0.004753799643367529f, 0.010876281186938286f, 0.013482563197612762f, 0.005506556015461683f, 0.006567981094121933f, 0.006240830756723881f, 0.0053519983775913715f, 0.006947856862097979f, 0.007574806921184063f, 0.004604610614478588f, 0.009225204586982727f, 0.014310621656477451f, 0.00816123466938734f, 0.005354737397283316f, 0.016768116503953934f, 0.0034872868563979864f, 0.007996621541678905f, 0.004759524948894978f, 0.005622241646051407f, 0.009087233804166317f, 0.004171790089458227f, 0.006698480807244778f, 0.015075618401169777f, 0.007157954387366772f, 0.005019667092710733f, 0.004779027309268713f, 0.006177364382892847f, 0.008919035084545612f, 0.006628864910453558f, 0.007665175944566727f, 0.013412891887128353f, 0.005237895995378494f, 0.009126415476202965f, 0.00918487273156643f, 0.0042069414630532265f, 0.005319769028574228f, 0.005037111230194569f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0336112454533577f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009432359132915735f),
    AI_PACK_UINTQ_ZP(111)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013645136496052146f, 0.0013387853978201747f, 0.0011563742300495505f, 0.0014199415454640985f, 0.0015510414959862828f, 0.0018135997233912349f, 0.0014694473939016461f, 0.0013779436703771353f, 0.001446426846086979f, 0.001213887706398964f, 0.0015054747927933931f, 0.0017558172112330794f, 0.001437184284441173f, 0.0017962416168302298f, 0.0014457468641921878f, 0.0014978342223912477f, 0.001384670496918261f, 0.0015369737520813942f, 0.0014001157833263278f, 0.0013621781254187226f, 0.001449302420951426f, 0.001337674679234624f, 0.0013290991773828864f, 0.0014542856952175498f, 0.0013684302102774382f, 0.0011512476485222578f, 0.001182882348075509f, 0.0015858248807489872f, 0.001270910957828164f, 0.001623357180505991f, 0.0015084096230566502f, 0.0012309204321354628f, 0.0015523701440542936f, 0.001672473386861384f, 0.0014003943651914597f, 0.0016697573009878397f, 0.0019913522992283106f, 0.0016313499072566628f, 0.0015036077238619328f, 0.0015401546843349934f, 0.0014408341376110911f, 0.0015448229387402534f, 0.0015196583699434996f, 0.0013240519911050797f, 0.0013172361068427563f, 0.0015044091269373894f, 0.0016495379386469722f, 0.0014465480344370008f, 0.0018036635592579842f, 0.0014162772567942739f, 0.001111379242502153f, 0.001652093487791717f, 0.0015421782154589891f, 0.0013342718593776226f, 0.0015576159348711371f, 0.0013833483681082726f, 0.001687553827650845f, 0.0013525148387998343f, 0.002015220234170556f, 0.0012296217028051615f, 0.0016750971553847194f, 0.0015751386526972055f, 0.001514120725914836f, 0.0015864147571846843f, 0.0015268190763890743f, 0.0013312390074133873f, 0.0013373015681281686f, 0.001872766762971878f, 0.0013298143167048693f, 0.0015515758423134685f, 0.0016536855837330222f, 0.0012512304820120335f, 0.0013556575868278742f, 0.0012131609255447984f, 0.0013177249347791076f, 0.001625174772925675f, 0.0013020375045016408f, 0.0012972012627869844f, 0.0012639412889257073f, 0.0015856134705245495f, 0.0010402308544144034f, 0.001592048560269177f, 0.0015892955707386136f, 0.0013983995886519551f, 0.0014361341018229723f, 0.0012906530173495412f, 0.0012977422447875142f, 0.0013572927564382553f, 0.0014119116822257638f, 0.0014353918377310038f, 0.00186837837100029f, 0.001508639077655971f, 0.0013164689298719168f, 0.0016217574011534452f, 0.0011919548269361258f, 0.0017337165772914886f, 0.001238435972481966f, 0.0019233714556321502f, 0.001926202792674303f, 0.0015714539913460612f, 0.0012182679492980242f, 0.001397692714817822f, 0.0016737646656110883f, 0.001473581651225686f, 0.0012768429005518556f, 0.0012014925014227629f, 0.0017225921619683504f, 0.0015869296621531248f, 0.0015431421343237162f, 0.001390026300214231f, 0.0014971336349844933f, 0.001636237371712923f, 0.001380086992867291f, 0.0018901024013757706f, 0.0011691178660839796f, 0.0015904344618320465f, 0.0015794053906574845f, 0.0012333623599261045f, 0.0013440941693261266f, 0.001462285639718175f, 0.0014065896393731236f, 0.0013136654160916805f, 0.0014766085660085082f, 0.00145042990334332f, 0.0015905475011095405f, 0.0013744938187301159f, 0.0013880443293601274f, 0.0019299609120935202f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.061893582344055176f),
    AI_PACK_INTQ_ZP(-36)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006432876689359546f, 0.000807304575573653f, 0.0004928592825308442f, 0.0004628257011063397f, 0.00043747713789343834f, 0.0006571118137799203f, 0.0007321168086491525f, 0.0008749462431296706f, 0.000498708279337734f, 0.0006556492298841476f, 0.000612424744758755f, 0.000722041295375675f, 0.0005920910043641925f, 0.000581677071750164f, 0.0007042990764603019f, 0.0006038980791345239f, 0.0005973759107291698f, 0.0006787496968172491f, 0.000683263991959393f, 0.000615740311332047f, 0.0006443717866204679f, 0.0005625934572890401f, 0.0006155416485853493f, 0.0005323451478034258f, 0.00041165290167555213f, 0.0007199792307801545f, 0.0007917588809505105f, 0.0005130612989887595f, 0.0005949718761257827f, 0.0007846078951843083f, 0.000810700876172632f, 0.0010388677474111319f, 0.0005064987344667315f, 0.0006322503322735429f, 0.0008415671763941646f, 0.0007106877164915204f, 0.0006804880686104298f, 0.0006720267701894045f, 0.0008871121681295335f, 0.0006115030264481902f, 0.0007340583833865821f, 0.0005825658445246518f, 0.0005530132330022752f, 0.0006091332179494202f, 0.000545915390830487f, 0.0005596146220341325f, 0.000582287844736129f, 0.0005205023335292935f, 0.0009444687166251242f, 0.0006025853799656034f, 0.0005285533261485398f, 0.00039524107705801725f, 0.0008396249613724649f, 0.0005322962533682585f, 0.0007232971838675439f, 0.0006449974607676268f, 0.0009667134145274758f, 0.0005746596725657582f, 0.0005649585509672761f, 0.0009439985151402652f, 0.0005526855238713324f, 0.0007455622544512153f, 0.0006078286678530276f, 0.0004988429718650877f, 0.0006123169441707432f, 0.0006394232623279095f, 0.0008286125375889242f, 0.0006905306945554912f, 0.0008242478361353278f, 0.0007585105486214161f, 0.0005170524236746132f, 0.0005890147876925766f, 0.0006434709066525102f, 0.0006069185910746455f, 0.00043827207991853356f, 0.0007035330636426806f, 0.0005831820308230817f, 0.000764919794164598f, 0.0003664827672764659f, 0.0007066517719067633f, 0.0006218375638127327f, 0.0004838003951590508f, 0.0006187408580444753f, 0.0005059579270891845f, 0.000741216994356364f, 0.0004761835443787277f, 0.0006449973443523049f, 0.0006071049137972295f, 0.0006486225756816566f, 0.0006478042341768742f, 0.0008732415153644979f, 0.00045550696086138487f, 0.0005677097360603511f, 0.0007951197330839932f, 0.0006816689856350422f, 0.0006707188440486789f, 0.00047928624553605914f, 0.0009607207030057907f, 0.000861288164742291f, 0.0004591145261656493f, 0.0007339478470385075f, 0.0008467963198199868f, 0.0006218564230948687f, 0.0006953701376914978f, 0.0006507136858999729f, 0.0005705835646949708f, 0.0005344048258848488f, 0.0008534626103937626f, 0.0004492497828323394f, 0.0006680095684714615f, 0.0005467912997119129f, 0.0005050666513852775f, 0.0004227330209687352f, 0.0005100903799757361f, 0.0004474155430216342f, 0.0005428104195743799f, 0.0010496678296476603f, 0.0007262562867254019f, 0.000655367795843631f, 0.00048039303510449827f, 0.0006128217210061848f, 0.0007409527315758169f, 0.00044672010699287057f, 0.00048506728489883244f, 0.00047703160089440644f, 0.0010234087239950895f, 0.0006040418520569801f, 0.0006908861687406898f, 0.0007815532735548913f, 0.0005481878179125488f, 0.0007540356018580496f, 0.0005937829846516252f, 0.0005986196338199079f, 0.0006772822816856205f, 0.0006023359019309282f, 0.0006223443197086453f, 0.0005932477652095258f, 0.0005119534325785935f, 0.0007469866541214287f, 0.00043287788867019117f, 0.0008292635320685804f, 0.000587659771554172f, 0.0006008102791383862f, 0.0004764356417581439f, 0.0007517010089941323f, 0.00047915917821228504f, 0.0008843502728268504f, 0.0006098143057897687f, 0.0008075450896285474f, 0.0005057264352217317f, 0.0007760655134916306f, 0.0006550406105816364f, 0.00043468124931678176f, 0.0007526070112362504f, 0.0008250666433013976f, 0.0007296910625882447f, 0.0008098558173514903f, 0.0008589873905293643f, 0.000592836644500494f, 0.0010314910905435681f, 0.0007212692289613187f, 0.0005001639947295189f, 0.0005663043120875955f, 0.0006129587418399751f, 0.0005882770055904984f, 0.0005954147200100124f, 0.0008529328042641282f, 0.0007644484867341816f, 0.0004918664344586432f, 0.0007534094620496035f, 0.000539064290933311f, 0.0007068731938488781f, 0.0005823102546855807f, 0.0007837535231374204f, 0.0005811771843582392f, 0.0004014114092569798f, 0.00038286324706859887f, 0.0006866137264296412f, 0.0006110887625254691f, 0.000549543125089258f, 0.0006937834550626576f, 0.00042097544064745307f, 0.00041539425728842616f, 0.0004661650746129453f, 0.0006236895569600165f, 0.0011004566913470626f, 0.0005838172510266304f, 0.0008574515813961625f, 0.00031329551711678505f, 0.0006542981136590242f, 0.0007850302499718964f, 0.0008165082545019686f, 0.0005145321483723819f, 0.0006878987769596279f, 0.0006412951042875648f, 0.0010608588345348835f, 0.00048362952657043934f, 0.0009538099402561784f, 0.0008188934880308807f, 0.0006397356046363711f, 0.0009236116893589497f, 0.000779525435063988f, 0.0006325400318019092f, 0.0005215369747020304f, 0.0005717790336348116f, 0.0010046401293948293f, 0.00045749550918117166f, 0.000637639663182199f, 0.00060436618514359f, 0.0006321020773611963f, 0.0005961016868241131f, 0.0005696059088222682f, 0.0006637634360231459f, 0.00043736636871472f, 0.0005071480991318822f, 0.0005671911058016121f, 0.0007342328899540007f, 0.001118857180699706f, 0.0005407920107245445f, 0.0006413066876120865f, 0.0008018887601792812f, 0.000933628820348531f, 0.0005440125241875648f, 0.0008329397533088923f, 0.00044776330469176173f, 0.0010709590278565884f, 0.0009653189335949719f, 0.0005184906767681241f, 0.0005227272631600499f, 0.0009250161238014698f, 0.00046736488002352417f, 0.0007807616493664682f, 0.0006393336807377636f, 0.000542162568308413f, 0.000695885973982513f, 0.0005600933218374848f, 0.000799480068963021f, 0.0006156731978990138f, 0.0005481447442434728f, 0.0007137556094676256f, 0.0005585363833233714f, 0.0007070061401464045f, 0.0005359559436328709f, 0.0009394458611495793f, 0.0005470311734825373f, 0.0004075253673363477f, 0.0006864193710498512f, 0.0005849965964443982f, 0.0008532896754331887f, 0.001277186325751245f, 0.0004979944205842912f, 0.0006680760998278856f, 0.00042871208279393613f, 0.0004972267197445035f, 0.0006847644690424204f, 0.0005848027649335563f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007794357370585203f),
    AI_PACK_UINTQ_ZP(106)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008705907501280308f, 0.015680525451898575f, 0.014832960441708565f, 0.012189446948468685f, 0.01202219258993864f, 0.012342679314315319f, 0.007879297249019146f, 0.014924399554729462f, 0.009693668223917484f, 0.011724930256605148f, 0.007259688340127468f, 0.008213210850954056f, 0.010262989439070225f, 0.02011898346245289f, 0.010280106216669083f, 0.013321448117494583f, 0.009368082508444786f, 0.008765195496380329f, 0.008389744907617569f, 0.017886251211166382f, 0.013667905703186989f, 0.011427239514887333f, 0.012645327486097813f, 0.013924778439104557f, 0.011382171884179115f, 0.010072536766529083f, 0.0061843134462833405f, 0.011719860136508942f, 0.016050968319177628f, 0.022928103804588318f, 0.007789923343807459f, 0.005321998614817858f, 0.014397911727428436f, 0.005674607586115599f, 0.011985170654952526f, 0.011685500852763653f, 0.008533547632396221f, 0.013596927747130394f, 0.01253039762377739f, 0.014579090289771557f, 0.008541781455278397f, 0.010578726418316364f, 0.01142814476042986f, 0.012989943847060204f, 0.011996916495263577f, 0.01766708493232727f, 0.010096735320985317f, 0.013871300965547562f, 0.0066674514673650265f, 0.009910045191645622f, 0.012974942103028297f, 0.010660860687494278f, 0.011708835139870644f, 0.021131742745637894f, 0.004727997351437807f, 0.018198758363723755f, 0.006534994579851627f, 0.006816125940531492f, 0.013211584649980068f, 0.005332730244845152f, 0.011578194797039032f, 0.010927749797701836f, 0.014933951199054718f, 0.014257989823818207f, 0.014331497251987457f, 0.010022145695984364f, 0.007107361685484648f, 0.021850254386663437f, 0.02243802510201931f, 0.009496491402387619f, 0.014986305497586727f, 0.013071284629404545f, 0.007352063897997141f, 0.017968788743019104f, 0.02260787971317768f, 0.012494043447077274f, 0.0169967208057642f, 0.014858230948448181f, 0.0076036411337554455f, 0.018410546705126762f, 0.011058749631047249f, 0.0122230788692832f, 0.015030541457235813f, 0.013141405768692493f, 0.010699411854147911f, 0.006493917666375637f, 0.010245196521282196f, 0.011662510223686695f, 0.007466207258403301f, 0.007078843656927347f, 0.007125824224203825f, 0.009236195124685764f, 0.01061423309147358f, 0.012685851193964481f, 0.007485846523195505f, 0.013675661757588387f, 0.011048979125916958f, 0.007191668264567852f, 0.006076530087739229f, 0.021082796156406403f, 0.010631673969328403f, 0.006666922010481358f, 0.013137906789779663f, 0.010213754139840603f, 0.009659258648753166f, 0.008418948389589787f, 0.011963632889091969f, 0.010119603946805f, 0.007718222681432962f, 0.0074708773754537106f, 0.0134555259719491f, 0.018378017470240593f, 0.016465529799461365f, 0.011707913130521774f, 0.010188277810811996f, 0.007373404689133167f, 0.013369143940508366f, 0.007515228819102049f, 0.009138624183833599f, 0.009049462154507637f, 0.009195601567626f, 0.012568086385726929f, 0.0071811010129749775f, 0.01659916527569294f, 0.018121769651770592f, 0.005835006944835186f, 0.01028145756572485f, 0.009602515958249569f, 0.01384870707988739f, 0.0123243797570467f, 0.00935452338308096f, 0.015224630944430828f, 0.01394339744001627f, 0.014654761180281639f, 0.01183340884745121f, 0.014825914986431599f, 0.00795567687600851f, 0.007869798690080643f, 0.006898270454257727f, 0.007066047750413418f, 0.01754457876086235f, 0.011556684039533138f, 0.007845071144402027f, 0.014633385464549065f, 0.0123549560084939f, 0.008950822986662388f, 0.011995570734143257f, 0.016957398504018784f, 0.010215851478278637f, 0.020537085831165314f, 0.00973080936819315f, 0.017273079603910446f, 0.01404199842363596f, 0.00739172613248229f, 0.00708754314109683f, 0.012661806307733059f, 0.010773236863315105f, 0.012104403227567673f, 0.009707409888505936f, 0.01158872153609991f, 0.012632645666599274f, 0.005637067835777998f, 0.01152007281780243f, 0.014638020657002926f, 0.011779907159507275f, 0.01110786572098732f, 0.014575324021279812f, 0.011097240261733532f, 0.009520096704363823f, 0.006616777274757624f, 0.009862218983471394f, 0.013521500863134861f, 0.008187130093574524f, 0.010389011353254318f, 0.018556389957666397f, 0.010354690253734589f, 0.019318243488669395f, 0.011726927012205124f, 0.01074314210563898f, 0.012444202788174152f, 0.009712712839245796f, 0.014697106555104256f, 0.012229517102241516f, 0.02196454629302025f, 0.015206986106932163f, 0.0038372159469872713f, 0.009100828319787979f, 0.009181753732264042f, 0.018547886982560158f, 0.013241535052657127f, 0.01421611849218607f, 0.015841344371438026f, 0.009433675557374954f, 0.004821703303605318f, 0.007072736043483019f, 0.016965074464678764f, 0.011999648995697498f, 0.009385964833199978f, 0.014547588303685188f, 0.009506653994321823f, 0.011136511340737343f, 0.012164682149887085f, 0.009606292471289635f, 0.010128920897841454f, 0.01779228262603283f, 0.0043105012737214565f, 0.012483182363212109f, 0.019539479166269302f, 0.0172580536454916f, 0.01163011509925127f, 0.015316073782742023f, 0.010203827172517776f, 0.007046143524348736f, 0.009396948851644993f, 0.009706891141831875f, 0.00812764186412096f, 0.015676427632570267f, 0.004353670869022608f, 0.014348777942359447f, 0.00700561935082078f, 0.012193496339023113f, 0.009623835794627666f, 0.009469222277402878f, 0.008467803709208965f, 0.01904124580323696f, 0.015413348563015461f, 0.007416430860757828f, 0.011699537746608257f, 0.016224386170506477f, 0.0127773592248559f, 0.008324387483298779f, 0.00577905960381031f, 0.010363688692450523f, 0.014758438803255558f, 0.015642749145627022f, 0.014060442335903645f, 0.010553346015512943f, 0.011430500075221062f, 0.008725326508283615f, 0.012858486734330654f, 0.017037639394402504f, 0.009391512721776962f, 0.011312914080917835f, 0.008003323338925838f, 0.016166292130947113f, 0.009517144411802292f, 0.013365269638597965f, 0.014137818478047848f, 0.010169821791350842f, 0.0052056703716516495f, 0.009891419671475887f, 0.012146239168941975f, 0.022403649985790253f, 0.011918549425899982f, 0.012665052898228168f, 0.007157959043979645f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03437094762921333f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00851659500040114f),
    AI_PACK_UINTQ_ZP(147)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018426321912556887f, 0.0016396341379731894f, 0.0017016498604789376f, 0.001472572679631412f, 0.001463741180486977f, 0.0015688183484598994f, 0.0018669384298846126f, 0.0015432778745889664f, 0.0013835536083206534f, 0.001755452249199152f, 0.001778051140718162f, 0.0015919782454147935f, 0.0015598947647958994f, 0.0016587527934461832f, 0.0017165185417979956f, 0.0017470906022936106f, 0.0016974080353975296f, 0.0021434666123241186f, 0.0018538330914452672f, 0.0019398594740778208f, 0.0015113608678802848f, 0.001617599744349718f, 0.0013820665189996362f, 0.0017053628107532859f, 0.001649685436859727f, 0.0019609974697232246f, 0.0015779652167111635f, 0.0015714993933215737f, 0.0015611291164532304f, 0.0015808520838618279f, 0.0014642360620200634f, 0.0016704595182090998f, 0.001514336676336825f, 0.0022338281851261854f, 0.0010537857888266444f, 0.0015232143923640251f, 0.0015345705905929208f, 0.002233023289591074f, 0.0014323386130854487f, 0.0015786029398441315f, 0.001383349415846169f, 0.001866280334070325f, 0.0012469501234591007f, 0.0021431343629956245f, 0.002215427113696933f, 0.0013177006039768457f, 0.002201510826125741f, 0.001274320064112544f, 0.0015865392051637173f, 0.001598596223630011f, 0.001604763325303793f, 0.0013941786019131541f, 0.0014373083831742406f, 0.0022140254732221365f, 0.0017385445535182953f, 0.0014959486434236169f, 0.001765996334142983f, 0.0013971272855997086f, 0.0015853409422561526f, 0.0017264513298869133f, 0.0019620750099420547f, 0.0016501911450177431f, 0.0010950596770271659f, 0.0019084021914750338f, 0.0019341108854860067f, 0.0016762212617322803f, 0.001807680120691657f, 0.0013377695577219129f, 0.0017163821030408144f, 0.0015495105180889368f, 0.002083578146994114f, 0.0016217725351452827f, 0.0011100581614300609f, 0.001793640898540616f, 0.001809108885936439f, 0.0015616955934092402f, 0.0017221891321241856f, 0.0018765993881970644f, 0.0017967917956411839f, 0.001432401710189879f, 0.002448438201099634f, 0.0016399157466366887f, 0.0014025138225406408f, 0.0013807411305606365f, 0.0014585278695449233f, 0.0014063759008422494f, 0.001687612384557724f, 0.0015896514523774385f, 0.0015183931682258844f, 0.0022040330804884434f, 0.0014056684449315071f, 0.0020039065275341272f, 0.0015097642317414284f, 0.001631497754715383f, 0.0017459362279623747f, 0.0015679833013564348f, 0.0015263839159160852f, 0.0016844727797433734f, 0.001432267832569778f, 0.002769231563434005f, 0.001713919802568853f, 0.0023850619327276945f, 0.0014543973375111818f, 0.0012174301082268357f, 0.0017731465632095933f, 0.001386827090755105f, 0.0012068243231624365f, 0.0019179414957761765f, 0.0017319208709523082f, 0.00165299151558429f, 0.0018001244170591235f, 0.001753714052028954f, 0.0017861161613836884f, 0.002074018819257617f, 0.0017839199863374233f, 0.0018251030705869198f, 0.0016175474738702178f, 0.0011960339033976197f, 0.002069005509838462f, 0.001415103324688971f, 0.0016518370248377323f, 0.0018438707338646054f, 0.0016123426612466574f, 0.0018128392985090613f, 0.0018768073059618473f, 0.002145865699276328f, 0.0008538213442079723f, 0.0017629581270739436f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07184860855340958f),
    AI_PACK_INTQ_ZP(-40)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005497739184647799f, 0.0007510956493206322f, 0.0005608531064353883f, 0.0006142407655715942f, 0.00044268788769841194f, 0.0007875800365582108f, 0.000595410296227783f, 0.0005687780794687569f, 0.0004939434002153575f, 0.0005729630356654525f, 0.0008079403196461499f, 0.0004991142777726054f, 0.0006825669552199543f, 0.0006164807709865272f, 0.0003031811793334782f, 0.0005220780149102211f, 0.0010388785740360618f, 0.0005931741325184703f, 0.0007476121536456048f, 0.00048280003829859197f, 0.0007533510797657073f, 0.0006693806499242783f, 0.0005694874562323093f, 0.0004913032171316445f, 0.0007241037092171609f, 0.0005549893830902874f, 0.0012265922268852592f, 0.0005742958164773881f, 0.0006252300809137523f, 0.0005917986272834241f, 0.0005396983469836414f, 0.0009456551633775234f, 0.0006775302463211119f, 0.0006401969003491104f, 0.0006924332119524479f, 0.0007168779848143458f, 0.0005753097939305007f, 0.0006413103546947241f, 0.0007091268780641258f, 0.0006708292057737708f, 0.0007400172180496156f, 0.0006792708882130682f, 0.0007810499519109726f, 0.0007739177090115845f, 0.000620163104031235f, 0.0011095503577962518f, 0.000616692763287574f, 0.0005646346835419536f, 0.0006911795353516936f, 0.0007412733975797892f, 0.0013326522894203663f, 0.0005957585526630282f, 0.0005868359003216028f, 0.0006971078109927475f, 0.0005255327560007572f, 0.0005766043905168772f, 0.0005190394003875554f, 0.0005748433759436011f, 0.0006812551873736084f, 0.0007330810185521841f, 0.0003935875720344484f, 0.0007858556928113103f, 0.0004718101117759943f, 0.0010053022997453809f, 0.0005957273533567786f, 0.0007455841405317187f, 0.0006951150135137141f, 0.00045177849824540317f, 0.0004840154724661261f, 0.0006717455107718706f, 0.0007453728467226028f, 0.000532357080373913f, 0.000554393045604229f, 0.0008732390124350786f, 0.0007072360604070127f, 0.0006750961765646935f, 0.0006832668441347778f, 0.0005690837278962135f, 0.0007395869470201433f, 0.00063981773564592f, 0.0008522180141881108f, 0.0007693120860494673f, 0.0004681284772232175f, 0.0009010739158838987f, 0.0007239991682581604f, 0.0007679240079596639f, 0.0008918577223084867f, 0.0005310415872372687f, 0.0008057415834628046f, 0.0006261763628572226f, 0.0004997911164537072f, 0.0010407088557258248f, 0.0004947002162225544f, 0.0007415188592858613f, 0.00048610157682560384f, 0.0007354131666943431f, 0.0006108953966759145f, 0.0008293958380818367f, 0.0007456057937815785f, 0.0005486837471835315f, 0.0005548748304136097f, 0.0004128763685002923f, 0.00034088906249962747f, 0.0005107170436531305f, 0.0007096033659763634f, 0.0005461134715005755f, 0.0008463652920909226f, 0.0005378969945013523f, 0.0009375927620567381f, 0.0005095870001241565f, 0.0007238766993395984f, 0.0008215031120926142f, 0.0007371163228526711f, 0.0006024708272889256f, 0.0005439699743874371f, 0.000621434417553246f, 0.0003628712729550898f, 0.0006588030373677611f, 0.0005330564454197884f, 0.0009280595695599914f, 0.0006775991059839725f, 0.0004417923337314278f, 0.0007077246555127203f, 0.0004539117799140513f, 0.0006264068651944399f, 0.0009598722099326551f, 0.0005636108107864857f, 0.0004404630162753165f, 0.0006023798487149179f, 0.0006438508862629533f, 0.0008635996491648257f, 0.001008994528092444f, 0.00111751863732934f, 0.000755913439206779f, 0.0006899854633957148f, 0.0004536123888101429f, 0.0005551411304622889f, 0.0006452033994719386f, 0.0005203269538469613f, 0.0007066820398904383f, 0.0008570632780902088f, 0.0007035054150037467f, 0.0008598921122029424f, 0.0005171329830773175f, 0.0007214311044663191f, 0.0005896344664506614f, 0.0005137178814038634f, 0.0005860452074557543f, 0.0005192923708818853f, 0.0007341489545069635f, 0.0004709733184427023f, 0.0007079555653035641f, 0.001121743582189083f, 0.0005923209246248007f, 0.0005933716893196106f, 0.00047372348490171134f, 0.0005933570791967213f, 0.00047061097575351596f, 0.00048067347961477935f, 0.0005295081646181643f, 0.0007739321445114911f, 0.0006345075671561062f, 0.0013050537090748549f, 0.0006862027803435922f, 0.0007097752531990409f, 0.0006002798327244818f, 0.0009412305080331862f, 0.0005918956594541669f, 0.0005317964241839945f, 0.00036233090213499963f, 0.0008100000559352338f, 0.00045896461233496666f, 0.0004753864777740091f, 0.0007939531933516264f, 0.0005488499882631004f, 0.0005557580152526498f, 0.0007102576782926917f, 0.0005399471265263855f, 0.001045640092343092f, 0.0006061401800252497f, 0.0007411378901451826f, 0.0006069396622478962f, 0.0007161327521316707f, 0.000521844020113349f, 0.0005443284753710032f, 0.0006923067849129438f, 0.0006088819936849177f, 0.0008134738891385496f, 0.0007975173648446798f, 0.00044135298230685294f, 0.0004908094997517765f, 0.0007252117502503097f, 0.0004993531038053334f, 0.00044487594277597964f, 0.0005190498195588589f, 0.0006484747864305973f, 0.0004979935474693775f, 0.0006384364096447825f, 0.0006105435313656926f, 0.0004775082634296268f, 0.0004998714430257678f, 0.0005247346707619727f, 0.0006216405308805406f, 0.0006577309686690569f, 0.0005985848256386817f, 0.0005545116728171706f, 0.0005472092889249325f, 0.000561371969524771f, 0.00047814392019063234f, 0.0008219479932449758f, 0.000589044182561338f, 0.0005228545051068068f, 0.000554362777620554f, 0.0005288004176691175f, 0.0004808772646356374f, 0.0008644104818813503f, 0.0005924683646298945f, 0.0007203646237030625f, 0.0005169797223061323f, 0.0004568722506519407f, 0.0007644706056453288f, 0.0010737684788182378f, 0.0007809504168108106f, 0.0006357040256261826f, 0.0004596875805873424f, 0.00043103916686959565f, 0.0005677822628058493f, 0.0006527281948365271f, 0.0007469997508451343f, 0.0010925119277089834f, 0.000547799572814256f, 0.0009390559862367809f, 0.0007130296435207129f, 0.0005128029151819646f, 0.0006229481659829617f, 0.0005245311767794192f, 0.0005519711412489414f, 0.0007346409256570041f, 0.0004893979639746249f, 0.0007757838466204703f, 0.0006484369514510036f, 0.0007548004505224526f, 0.0009775500511750579f, 0.0005413441685959697f, 0.0005996295949444175f, 0.0005566815962083638f, 0.0004471445572562516f, 0.000427780207246542f, 0.0004987000720575452f, 0.0006168977706693113f, 0.0003974570136051625f, 0.0007494505844078958f, 0.0008354266756214201f, 0.0006315790233202279f, 0.00042035995284095407f, 0.0008129286579787731f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0070402652490884066f),
    AI_PACK_UINTQ_ZP(114)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014888630248606205f, 0.005868302658200264f, 0.013154051266610622f, 0.014433152042329311f, 0.011552996933460236f, 0.00763581320643425f, 0.00924475397914648f, 0.011269091628491879f, 0.018510378897190094f, 0.006432912312448025f, 0.017150478437542915f, 0.013331129215657711f, 0.014482886530458927f, 0.008882840164005756f, 0.04035446420311928f, 0.01222464069724083f, 0.014113543555140495f, 0.011393431574106216f, 0.008622578345239162f, 0.021038945764303207f, 0.008381376974284649f, 0.011420543305575848f, 0.017568763345479965f, 0.019030587747693062f, 0.0108551736921072f, 0.010184024460613728f, 0.009146465919911861f, 0.00802200473845005f, 0.011186273768544197f, 0.01293336320668459f, 0.013249463401734829f, 0.01408443320542574f, 0.012256190180778503f, 0.014263694174587727f, 0.01051401812583208f, 0.014361830428242683f, 0.015592102892696857f, 0.011829030700027943f, 0.015878397971391678f, 0.018494825810194016f, 0.005834126379340887f, 0.013294687494635582f, 0.010817471891641617f, 0.011089528910815716f, 0.008177273906767368f, 0.010288944467902184f, 0.021183067932724953f, 0.013379626907408237f, 0.010661840438842773f, 0.018740467727184296f, 0.011320129968225956f, 0.014796759933233261f, 0.013165599666535854f, 0.016414998099207878f, 0.015842026099562645f, 0.01764054037630558f, 0.018254702910780907f, 0.01327988039702177f, 0.007258214987814426f, 0.004373492673039436f, 0.015043821185827255f, 0.0032941701356321573f, 0.016923636198043823f, 0.008686311542987823f, 0.018504081293940544f, 0.01235558744519949f, 0.010464987717568874f, 0.019298860803246498f, 0.009957537986338139f, 0.00823698379099369f, 0.012527198530733585f, 0.010309407487511635f, 0.018632560968399048f, 0.014960519969463348f, 0.008904589340090752f, 0.00904441624879837f, 0.013169742189347744f, 0.01788702793419361f, 0.012674502097070217f, 0.010039227083325386f, 0.0080235805362463f, 0.01095170434564352f, 0.007357888389378786f, 0.014241003431379795f, 0.013947632163763046f, 0.008457531221210957f, 0.004000316374003887f, 0.00952925719320774f, 0.004038223996758461f, 0.0145862502977252f, 0.010645188391208649f, 0.016721855849027634f, 0.011637013405561447f, 0.014587079174816608f, 0.011325494386255741f, 0.01032178569585085f, 0.006705301348119974f, 0.0175465177744627f, 0.006663909647613764f, 0.013626230880618095f, 0.010794585570693016f, 0.013849371112883091f, 0.02540457621216774f, 0.01492265798151493f, 0.01990475319325924f, 0.01063611637800932f, 0.004310826770961285f, 0.01413300633430481f, 0.016699427738785744f, 0.010271221399307251f, 0.009240659885108471f, 0.010466235689818859f, 0.013992339372634888f, 0.014649671502411366f, 0.02049742080271244f, 0.010068266652524471f, 0.019659629091620445f, 0.014951772056519985f, 0.01089890394359827f, 0.01676340028643608f, 0.014764782972633839f, 0.017680607736110687f, 0.014093989506363869f, 0.009039840660989285f, 0.007125798147171736f, 0.004604191519320011f, 0.013508851639926434f, 0.010159221477806568f, 0.020547714084386826f, 0.02091621421277523f, 0.003977630287408829f, 0.004786303732544184f, 0.01781628094613552f, 0.011766470968723297f, 0.01421052310615778f, 0.013522773049771786f, 0.01870987005531788f, 0.01233952771872282f, 0.013631665147840977f, 0.010914183221757412f, 0.00933493860065937f, 0.008580190129578114f, 0.017673932015895844f, 0.00871269404888153f, 0.01196182332932949f, 0.0057764360681176186f, 0.007615196984261274f, 0.013729281723499298f, 0.017483528703451157f, 0.008945288136601448f, 0.005352683365345001f, 0.013207653537392616f, 0.006651356350630522f, 0.012186700478196144f, 0.017906637862324715f, 0.014267989434301853f, 0.014680784195661545f, 0.013516578823328018f, 0.009499499574303627f, 0.015567874535918236f, 0.013273308984935284f, 0.009700671769678593f, 0.01239835750311613f, 0.008777856826782227f, 0.007283830549567938f, 0.020265603438019753f, 0.01145216729491949f, 0.018495619297027588f, 0.007310938090085983f, 0.013916070573031902f, 0.009072577580809593f, 0.014727676287293434f, 0.03329947963356972f, 0.0075518288649618626f, 0.01189512200653553f, 0.02242719754576683f, 0.013391577638685703f, 0.014414029195904732f, 0.0037632437888532877f, 0.006580152083188295f, 0.01945425383746624f, 0.010516260750591755f, 0.01422777958214283f, 0.011026137508451939f, 0.023414837196469307f, 0.007509481627494097f, 0.008468108251690865f, 0.013005614280700684f, 0.005601918324828148f, 0.00923983659595251f, 0.01052928902208805f, 0.019916711375117302f, 0.00816869642585516f, 0.017067406326532364f, 0.007731047458946705f, 0.007118630222976208f, 0.010074886493384838f, 0.013110561296343803f, 0.011613317765295506f, 0.017539670690894127f, 0.01374488789588213f, 0.013556808233261108f, 0.015761999413371086f, 0.015135876834392548f, 0.016495434567332268f, 0.013444899581372738f, 0.012838933616876602f, 0.013805613853037357f, 0.008454529568552971f, 0.018230248242616653f, 0.03424101322889328f, 0.01099148578941822f, 0.007561353035271168f, 0.01048596017062664f, 0.01157978642731905f, 0.0035094893537461758f, 0.013169226236641407f, 0.015040560625493526f, 0.006506418809294701f, 0.010600495152175426f, 0.013148555532097816f, 0.007579135708510876f, 0.0075118956156075f, 0.012678625993430614f, 0.009925056248903275f, 0.01079585775732994f, 0.012245126068592072f, 0.013153750449419022f, 0.008075978606939316f, 0.012856738641858101f, 0.01124553382396698f, 0.008752179332077503f, 0.009144756011664867f, 0.00531731965020299f, 0.007642601151019335f, 0.012049999088048935f, 0.010890142060816288f, 0.014750771224498749f, 0.012003165669739246f, 0.0111521165817976f, 0.010405528359115124f, 0.013226069509983063f, 0.010859745554625988f, 0.013090445660054684f, 0.01067798025906086f, 0.007316296920180321f, 0.016427112743258476f, 0.01242853794246912f, 0.009124532341957092f, 0.013557001017034054f, 0.008184662088751793f, 0.010014480911195278f, 0.004145732149481773f, 0.012441836297512054f, 0.011950033716857433f, 0.004897776525467634f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0339556522667408f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006590798031538725f),
    AI_PACK_UINTQ_ZP(143)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017528245225548744f, 0.0016620431561022997f, 0.0015502710593864322f, 0.001884209574200213f, 0.0014927112497389317f, 0.0024190174881368876f, 0.0015043196035549045f, 0.002341225976124406f, 0.0016848909435793757f, 0.00217899470590055f, 0.002078751800581813f, 0.0022002130281180143f, 0.0017831290606409311f, 0.0016666020965203643f, 0.001886630547232926f, 0.0018440269632264972f, 0.002174158813431859f, 0.0016458859900012612f, 0.002291548764333129f, 0.001764038228429854f, 0.0018344676354900002f, 0.0017140340059995651f, 0.0022130392026156187f, 0.0012947801733389497f, 0.00207499205134809f, 0.00151708850171417f, 0.0013410586398094893f, 0.001916019944474101f, 0.0023015227634459734f, 0.0017955750226974487f, 0.0015548159135505557f, 0.0019008324015885592f, 0.002100196201354265f, 0.002225046744570136f, 0.0016213107155635953f, 0.0017688616644591093f, 0.002141576260328293f, 0.0016754354583099484f, 0.0019083237275481224f, 0.0017529948381707072f, 0.002191470470279455f, 0.0015156845329329371f, 0.002016782993450761f, 0.0022578316275030375f, 0.0025160633958876133f, 0.001903944998048246f, 0.001964211231097579f, 0.0014820449287071824f, 0.0019192288164049387f, 0.0017042701365426183f, 0.001852322486229241f, 0.0017983766738325357f, 0.0017614050302654505f, 0.0018851442728191614f, 0.0019886575173586607f, 0.0019930775742977858f, 0.0018052528612315655f, 0.0017547761090099812f, 0.00197986070998013f, 0.0016777641139924526f, 0.0016204742714762688f, 0.001839337171986699f, 0.002036052057519555f, 0.0019033463904634118f, 0.0016267370665445924f, 0.0017499057576060295f, 0.0021192850545048714f, 0.0015593450516462326f, 0.00263797165825963f, 0.0019318462582305074f, 0.0025196040514856577f, 0.0021338691003620625f, 0.001552310772240162f, 0.0018851731438189745f, 0.0019099726341664791f, 0.0019533021841198206f, 0.0022651846520602703f, 0.001748323324136436f, 0.0019533117301762104f, 0.0011614763643592596f, 0.0022096331231296062f, 0.0016182229155674577f, 0.0020978839602321386f, 0.0017351617570966482f, 0.001753430929966271f, 0.0018385914154350758f, 0.001918135560117662f, 0.00178063556086272f, 0.0020716912113130093f, 0.0021562324836850166f, 0.001727410010062158f, 0.002245304174721241f, 0.0018127750372514129f, 0.0017329963156953454f, 0.001659858739003539f, 0.001905166544020176f, 0.0016385045601055026f, 0.001772484160028398f, 0.0016493621515110135f, 0.0021168221719563007f, 0.002391473390161991f, 0.002276585204526782f, 0.0016948399133980274f, 0.0017799984198063612f, 0.0019459383329376578f, 0.002066054381430149f, 0.0016432154225185513f, 0.002142671961337328f, 0.0016495735617354512f, 0.0019941595382988453f, 0.0018087774515151978f, 0.0015320349484682083f, 0.0022046787198632956f, 0.0020259812008589506f, 0.0020961007103323936f, 0.0016688116593286395f, 0.002345168963074684f, 0.001921386574395001f, 0.0015110992826521397f, 0.0023300577886402607f, 0.0014624553732573986f, 0.0019187646685168147f, 0.001860641990788281f, 0.002166386926546693f, 0.0021020357962697744f, 0.001572989160194993f, 0.0017208707286044955f, 0.0016777768032625318f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00043578800978139043f, 0.00046590197598561645f, 0.0007773631950840354f, 0.0003977773303631693f, 0.0008156788535416126f, 0.0005664849886670709f, 0.00042108161142095923f, 0.000547044794075191f, 0.0003890708612743765f, 0.00043601958896033466f, 0.0006538110319525003f, 0.0004746753547806293f, 0.0005391209851950407f, 0.0006061678286641836f, 0.0005120566347613931f, 0.0007010228000581264f, 0.0005103336879983544f, 0.0005151483928784728f, 0.0005357566406019032f, 0.000725416699424386f, 0.00066218595020473f, 0.0005502248532138765f, 0.0005702033522538841f, 0.0005718127358704805f, 0.0008549543563276529f, 0.000431759690400213f, 0.0006001393194310367f, 0.00045478076208382845f, 0.0009203208610415459f, 0.000564372690860182f, 0.00041711548692546785f, 0.000485345401102677f, 0.0006971568800508976f, 0.0007236113888211548f, 0.0006266319542191923f, 0.000531537109054625f, 0.0006120748585090041f, 0.0007206621812656522f, 0.00041896034963428974f, 0.00038430976564995944f, 0.00038229150231927633f, 0.0004143602563999593f, 0.0004962540115229785f, 0.0008832705789245665f, 0.0003914817643817514f, 0.0004121981328353286f, 0.0005763391964137554f, 0.0006372135248966515f, 0.0007832387927919626f, 0.0004550431331153959f, 0.0007652742206119001f, 0.0007395143038593233f, 0.0005180607549846172f, 0.0009849207708612084f, 0.0005348746199160814f, 0.0005135330720804632f, 0.000552082434296608f, 0.0004803367774002254f, 0.0005338137852959335f, 0.00044077623169869184f, 0.001009277650155127f, 0.0006658160127699375f, 0.0005376526387408376f, 0.00029778562020510435f, 0.0007723196176812053f, 0.0005367696285247803f, 0.0006774137145839632f, 0.0004220602859277278f, 0.00042121761362068355f, 0.00049271882744506f, 0.0005388020654208958f, 0.00038488241261802614f, 0.0007265256717801094f, 0.0006384542211890221f, 0.0003927150391973555f, 0.0005610462394542992f, 0.0005605791811831295f, 0.0005334212328307331f, 0.00045792519813403487f, 0.0005910727777518332f, 0.000563775422051549f, 0.0007238808902911842f, 0.00040880462620407343f, 0.0006489462684839964f, 0.00047436775639653206f, 0.0004421519406605512f, 0.0007953246240504086f, 0.00046125962398946285f, 0.00048021614202298224f, 0.0006506956997327507f, 0.00047784156049601734f, 0.0005848641158081591f, 0.0003634151944424957f, 0.0006221997318789363f, 0.0005749415722675622f, 0.0005560584249906242f, 0.0007062067161314189f, 0.0005465529393404722f, 0.0005354533204808831f, 0.0007415261352434754f, 0.0004940638318657875f, 0.0005969966878183186f, 0.0006978483870625496f, 0.0007733933161944151f, 0.0006140343029983342f, 0.00044528499711304903f, 0.0006538335583172739f, 0.00035639095585793257f, 0.0006072510150261223f, 0.0005499750841408968f, 0.0005728237447328866f, 0.0004892320721410215f, 0.000624465465079993f, 0.0004900380736216903f, 0.0004623339045792818f, 0.000430168496677652f, 0.0006198936025612056f, 0.0003761167754419148f, 0.00045005400897935033f, 0.0003413943632040173f, 0.00044998552766628563f, 0.0005386568373069167f, 0.0006005072500556707f, 0.00036128718056716025f, 0.0006665711989626288f, 0.0006048462237231433f, 0.0005368849379010499f, 0.0004636081284843385f, 0.0011222240282222629f, 0.00048035712097771466f, 0.00032892997842282057f, 0.0006188420229591429f, 0.000762182055041194f, 0.0005567609332501888f, 0.0005498675745911896f, 0.0004915762110613286f, 0.0006528431549668312f, 0.0006020278087817132f, 0.0006163804209791124f, 0.0007056525209918618f, 0.0008534920634701848f, 0.000519982713740319f, 0.000585009518545121f, 0.0009943521581590176f, 0.0005047852173447609f, 0.0006847332697361708f, 0.0006656944169662893f, 0.0005128371994942427f, 0.0003760008548852056f, 0.0010807807557284832f, 0.0004134773917030543f, 0.0004822088230866939f, 0.0005329137202352285f, 0.0005720754852518439f, 0.0005071273189969361f, 0.0005944145959801972f, 0.0005411701276898384f, 0.0005024590063840151f, 0.000704701931681484f, 0.0005991006619296968f, 0.0004945546970702708f, 0.0005287830135785043f, 0.0003381847345735878f, 0.0005149623611941934f, 0.0005696703447028995f, 0.000573603087104857f, 0.0005921599804423749f, 0.0005446075228974223f, 0.0003762355772778392f, 0.0006965040811337531f, 0.00037930323742330074f, 0.0007449908298440278f, 0.0005001671961508691f, 0.0004551649617496878f, 0.0006656473851762712f, 0.0005806955159641802f, 0.0005963761359453201f, 0.0006891307421028614f, 0.0005206570494920015f, 0.000496520719025284f, 0.00042992629460059106f, 0.0008539182017557323f, 0.00034815105027519166f, 0.0007571479654870927f, 0.0005577967967838049f, 0.00037104490911588073f, 0.0005573279340751469f, 0.0005048453458584845f, 0.0005626396159641445f, 0.0007414669962599874f, 0.0005736968014389277f, 0.0005142829613760114f, 0.0004424711805768311f, 0.0009512865799479187f, 0.0004748945648316294f, 0.00047893699957057834f, 0.0008946724119596183f, 0.00043591883149929345f, 0.000657364318612963f, 0.0008021271205507219f, 0.00035554368514567614f, 0.0006078260485082865f, 0.0007499890634790063f, 0.000516443804372102f, 0.0005373547319322824f, 0.000622327032033354f, 0.0004586589348036796f, 0.0005706989322789013f, 0.0005675900029018521f, 0.0005753193399868906f, 0.000718320719897747f, 0.0006515575805678964f, 0.0007359824376180768f, 0.00037505969521589577f, 0.0006720093660987914f, 0.00036995240952819586f, 0.0007411330589093268f, 0.0004111538582947105f, 0.00048403895925730467f, 0.0007190454052761197f, 0.0006884080357849598f, 0.0005577132687903941f, 0.0010282559087499976f, 0.000390621367841959f, 0.0006485386984422803f, 0.0008736248128116131f, 0.0006804636213928461f, 0.00045686960220336914f, 0.0005215645651333034f, 0.000707058934494853f, 0.000606635760050267f, 0.00035287850187160075f, 0.0005307144019752741f, 0.0004681390128098428f, 0.0005497057572938502f, 0.0006252756575122476f, 0.0006810277700424194f, 0.0007406200165860355f, 0.000516570988111198f, 0.000406357430620119f, 0.0006894333055242896f, 0.0004973681061528623f, 0.0005964446463622153f, 0.0005507323076017201f, 0.0008469102904200554f, 0.0006122204358689487f, 0.0005878986557945609f, 0.00047513158642686903f, 0.0005906380829401314f, 0.00046330661280080676f, 0.0005381365772336721f, 0.0005915914662182331f, 0.000839597312733531f, 0.0004854130675084889f, 0.0007109654252417386f, 0.00042667202069424093f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06149633228778839f),
    AI_PACK_INTQ_ZP(-18)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009079972747713327f),
    AI_PACK_UINTQ_ZP(121)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016826320439577103f, 0.016392679885029793f, 0.009637223556637764f, 0.018628694117069244f, 0.009957977570593357f, 0.011078912764787674f, 0.01815136894583702f, 0.007989570498466492f, 0.014912915416061878f, 0.020681561902165413f, 0.00891199428588152f, 0.011356530711054802f, 0.01164516992866993f, 0.011687597259879112f, 0.011203108355402946f, 0.005301870405673981f, 0.0096023203805089f, 0.0115229906514287f, 0.023111121729016304f, 0.011139655485749245f, 0.007285634521394968f, 0.013155026361346245f, 0.015699448063969612f, 0.012082915753126144f, 0.019704721868038177f, 0.009037469513714314f, 0.00448666512966156f, 0.018763793632388115f, 0.012145107612013817f, 0.014332548715174198f, 0.012497495859861374f, 0.026777610182762146f, 0.006196633912622929f, 0.011513955891132355f, 0.01493750512599945f, 0.005528828129172325f, 0.011359364725649357f, 0.010810649953782558f, 0.019943421706557274f, 0.015157585963606834f, 0.008975616656243801f, 0.016196537762880325f, 0.010589678771793842f, 0.014707564376294613f, 0.01697794906795025f, 0.013582934625446796f, 0.009491421282291412f, 0.019130975008010864f, 0.005464650224894285f, 0.015259004198014736f, 0.011920807883143425f, 0.012658258900046349f, 0.019389737397432327f, 0.007498711813241243f, 0.010438972152769566f, 0.01036916021257639f, 0.016623497009277344f, 0.015058000572025776f, 0.027984408661723137f, 0.01397891715168953f, 0.004645514767616987f, 0.005681783892214298f, 0.013409877195954323f, 0.016118314117193222f, 0.004575377330183983f, 0.012750140391290188f, 0.00836953241378069f, 0.013673927634954453f, 0.013888654299080372f, 0.008435931988060474f, 0.017084037885069847f, 0.010560466907918453f, 0.02281836047768593f, 0.013637940399348736f, 0.016488278284668922f, 0.013749723322689533f, 0.00634978199377656f, 0.008211515843868256f, 0.01320547517389059f, 0.015468033030629158f, 0.016688823699951172f, 0.017571192234754562f, 0.00857123639434576f, 0.015187312848865986f, 0.012400302104651928f, 0.008817696943879128f, 0.004632316064089537f, 0.020910892635583878f, 0.009813308715820312f, 0.01252836361527443f, 0.00909969862550497f, 0.012126198038458824f, 0.02075846865773201f, 0.008823082782328129f, 0.007239361293613911f, 0.011051558889448643f, 0.018811965361237526f, 0.011513548903167248f, 0.013911311514675617f, 0.0064322189427912235f, 0.0076073212549090385f, 0.009957117959856987f, 0.008608246222138405f, 0.005494537763297558f, 0.012791396118700504f, 0.014737019315361977f, 0.016337981447577477f, 0.016267502680420876f, 0.007566855289041996f, 0.013454372994601727f, 0.01294791791588068f, 0.019347643479704857f, 0.011805862188339233f, 0.019703948870301247f, 0.013784379698336124f, 0.019047154113650322f, 0.0053430525586009026f, 0.009377695620059967f, 0.015201933681964874f, 0.00833004992455244f, 0.009982246905565262f, 0.01020507700741291f, 0.01710122637450695f, 0.0083592114970088f, 0.016362497583031654f, 0.01001033652573824f, 0.014465928077697754f, 0.007552952039986849f, 0.005223926156759262f, 0.01772088184952736f, 0.012814078480005264f, 0.010631506331264973f, 0.008971208706498146f, 0.006071552634239197f, 0.021928520873188972f, 0.015419200994074345f, 0.012944943271577358f, 0.01205152366310358f, 0.013681799173355103f, 0.013889340683817863f, 0.012614766135811806f, 0.01348196156322956f, 0.014510495588183403f, 0.008249249309301376f, 0.010091200470924377f, 0.008005693554878235f, 0.011203321628272533f, 0.017422137781977654f, 0.008184792473912239f, 0.010758246295154095f, 0.020274529233574867f, 0.023423627018928528f, 0.016616204753518105f, 0.012786968611180782f, 0.006907334551215172f, 0.016816139221191406f, 0.007387964054942131f, 0.015377869829535484f, 0.012663752771914005f, 0.01142122782766819f, 0.010976417921483517f, 0.012153137475252151f, 0.01281554251909256f, 0.017611505463719368f, 0.013265609741210938f, 0.011079474352300167f, 0.013717776164412498f, 0.01269408967345953f, 0.018114902079105377f, 0.01655145362019539f, 0.013474687933921814f, 0.012661207467317581f, 0.014554115943610668f, 0.01365636195987463f, 0.015593213960528374f, 0.010552876628935337f, 0.006834136787801981f, 0.006775412242859602f, 0.008377964608371258f, 0.014415969140827656f, 0.011284626089036465f, 0.007105821277946234f, 0.019586186856031418f, 0.006322598550468683f, 0.01151046808809042f, 0.0153789222240448f, 0.011365728452801704f, 0.017531046643853188f, 0.018266821280121803f, 0.008930970914661884f, 0.013377957046031952f, 0.012336746789515018f, 0.014555126428604126f, 0.013977265916764736f, 0.0070032356306910515f, 0.008384090848267078f, 0.014474596828222275f, 0.008311008103191853f, 0.014698813669383526f, 0.015391798689961433f, 0.0191528107970953f, 0.005634021013975143f, 0.006862067151814699f, 0.009280540980398655f, 0.010961064137518406f, 0.007748541422188282f, 0.010500804521143436f, 0.01902236044406891f, 0.013452641665935516f, 0.015521752648055553f, 0.015387768857181072f, 0.01231966633349657f, 0.008063878864049911f, 0.013819389045238495f, 0.011719472706317902f, 0.010042466223239899f, 0.021594898775219917f, 0.014541867189109325f, 0.011305782943964005f, 0.010058137588202953f, 0.010425832122564316f, 0.013551216572523117f, 0.011161654256284237f, 0.017954383045434952f, 0.0091848811134696f, 0.011588501743972301f, 0.006590916309505701f, 0.012988056056201458f, 0.008779744617640972f, 0.011115740053355694f, 0.009769183583557606f, 0.013933638110756874f, 0.006827412638813257f, 0.013129591941833496f, 0.013331395573914051f, 0.010256145149469376f, 0.009509704075753689f, 0.008471008390188217f, 0.013888397254049778f, 0.01818208023905754f, 0.010647241026163101f, 0.016212329268455505f, 0.008613090962171555f, 0.012386891059577465f, 0.008508451282978058f, 0.012552318163216114f, 0.02002045139670372f, 0.007016010116785765f, 0.012916765175759792f, 0.015432598069310188f, 0.01256808266043663f, 0.017253153026103973f, 0.01011881697922945f, 0.01444297842681408f, 0.016063233837485313f, 0.00816043745726347f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007699284935370088f),
    AI_PACK_UINTQ_ZP(137)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.037620820105075836f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017743598436936736f, 0.002087788423523307f, 0.0023628398776054382f, 0.0019848241936415434f, 0.002069686073809862f, 0.0020109915640205145f, 0.001931237056851387f, 0.002251738216727972f, 0.002321542240679264f, 0.002367231994867325f, 0.002047172514721751f, 0.0021554662380367517f, 0.0018305537523701787f, 0.00224800081923604f, 0.0019390793750062585f, 0.0015175184234976768f, 0.0021385126747190952f, 0.0028142856899648905f, 0.002285611815750599f, 0.0029622737783938646f, 0.0018360827816650271f, 0.0022060598712414503f, 0.0017827763222157955f, 0.0017878147773444653f, 0.0024309309665113688f, 0.0023024417459964752f, 0.0020058222580701113f, 0.0022296125534921885f, 0.0024522312451153994f, 0.0017858837964013219f, 0.002081249374896288f, 0.002278706757351756f, 0.002265669172629714f, 0.0023468248546123505f, 0.002288443734869361f, 0.002114253118634224f, 0.0022497661411762238f, 0.0024654585868120193f, 0.0023638715501874685f, 0.0018289693398401141f, 0.0021579761523753405f, 0.001875000656582415f, 0.001985084032639861f, 0.0022126513067632914f, 0.002174776280298829f, 0.0021538434084504843f, 0.001974890474230051f, 0.0024026648607105017f, 0.001829832443036139f, 0.0027980711311101913f, 0.0019775216933339834f, 0.0019383891485631466f, 0.002263579284772277f, 0.002221976174041629f, 0.002408487256616354f, 0.0017228953074663877f, 0.0023574603255838156f, 0.0023192763328552246f, 0.0029943024273961782f, 0.0024220726918429136f, 0.002409539185464382f, 0.002260912675410509f, 0.002010138239711523f, 0.00191067426931113f, 0.0016621333779767156f, 0.0020205473992973566f, 0.002155718393623829f, 0.0016938381595537066f, 0.00257444498129189f, 0.0021125641651451588f, 0.00231186649762094f, 0.002289349678903818f, 0.002080159494653344f, 0.0019854833371937275f, 0.0021806196309626102f, 0.0020663479808717966f, 0.002148951403796673f, 0.001973841805011034f, 0.0016392115503549576f, 0.001977324951440096f, 0.0020915092900395393f, 0.0022401956375688314f, 0.0020668990910053253f, 0.002178437542170286f, 0.0024028157349675894f, 0.0015954349655658007f, 0.0030279431957751513f, 0.002048241440206766f, 0.0021260923240333796f, 0.0017735244473442435f, 0.002777018118649721f, 0.0022097723558545113f, 0.00210329657420516f, 0.0019662315025925636f, 0.0023206265177577734f, 0.0018829562468454242f, 0.0025251484476029873f, 0.0025448640808463097f, 0.0021327862050384283f, 0.002249753335490823f, 0.0019030484836548567f, 0.002409597160294652f, 0.0025192999746650457f, 0.002232821425423026f, 0.0020048916339874268f, 0.001950689242221415f, 0.0019963246304541826f, 0.0021013712976127863f, 0.0025530459824949503f, 0.002405141480267048f, 0.0017973646754398942f, 0.0017229850636795163f, 0.0029300013557076454f, 0.002609609393402934f, 0.002213310683146119f, 0.00206038192845881f, 0.0021034409292042255f, 0.0023896298371255398f, 0.001943708397448063f, 0.002474600914865732f, 0.0017483572009950876f, 0.0017255659913644195f, 0.002250134479254484f, 0.002135998336598277f, 0.002529941964894533f, 0.002142279176041484f, 0.0018748705042526126f, 0.0015497255371883512f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007015680894255638f, 0.0005196508718654513f, 0.0004019975021947175f, 0.0004278683627489954f, 0.0007741631125099957f, 0.0004746095510199666f, 0.0006204067030921578f, 0.00039386123535223305f, 0.0005573260132223368f, 0.0007526162080466747f, 0.0004155363130848855f, 0.0005010541644878685f, 0.0005868503940291703f, 0.0005081401905044913f, 0.0006382850115187466f, 0.00044874718878418207f, 0.0006560013862326741f, 0.0010195416398346424f, 0.0006100227474234998f, 0.0005258153541944921f, 0.0005435242201201618f, 0.0005067005404271185f, 0.0004921577055938542f, 0.0007392163970507681f, 0.0004210523620713502f, 0.0006886359769850969f, 0.000446063291747123f, 0.00034954067086800933f, 0.0006838745903223753f, 0.0007704207673668861f, 0.0007286902982741594f, 0.000819088367279619f, 0.00043586036190390587f, 0.0007103479583747685f, 0.0006318201776593924f, 0.0005727432435378432f, 0.0005804116372019053f, 0.00037030820385552943f, 0.00034659061930142343f, 0.0008081385749392211f, 0.00030643580248579383f, 0.00035770353861153126f, 0.0004409216344356537f, 0.0005037073860876262f, 0.00041362832416780293f, 0.00032417778857052326f, 0.0007287723710760474f, 0.00035237573320046067f, 0.0004961996455676854f, 0.00048127208719961345f, 0.00044224108569324017f, 0.0006394109223037958f, 0.0003779494727496058f, 0.0005399644142016768f, 0.0005136830150149763f, 0.0005986398900859058f, 0.0005371300503611565f, 0.0005193577380850911f, 0.0003100858011748642f, 0.0005236492143012583f, 0.0004915991448797286f, 0.0008693366544321179f, 0.000335881719365716f, 0.000626514432951808f, 0.0005839215591549873f, 0.000524030183441937f, 0.0005671562976203859f, 0.00040015834383666515f, 0.0006956299766898155f, 0.0004641650593839586f, 0.0004838627064600587f, 0.0005852676695212722f, 0.000512223516125232f, 0.0005258325254544616f, 0.00037795116077177227f, 0.000620395177975297f, 0.00041467210394330323f, 0.00039095766260288656f, 0.0004339074366725981f, 0.00034027290530502796f, 0.00046656859922222793f, 0.0008246885263361037f, 0.0004889623378403485f, 0.0006050989613868296f, 0.0005383479292504489f, 0.0004918534541502595f, 0.0004594700876623392f, 0.0006447534542530775f, 0.0005568652995862067f, 0.0003931658575311303f, 0.0004553814942482859f, 0.0005789147107861936f, 0.0005222802283242345f, 0.0005071937921456993f, 0.0008587389020249248f, 0.0005279662436805665f, 0.0004265012394171208f, 0.0006142535130493343f, 0.00037241948302835226f, 0.0006364330765791237f, 0.000597195525187999f, 0.000447372964117676f, 0.0004174323985353112f, 0.0007174733909778297f, 0.0007301685982383788f, 0.0005569073837250471f, 0.0005792781594209373f, 0.0007395182037726045f, 0.0004208615282550454f, 0.0008375034667551517f, 0.0004771669628098607f, 0.0005659787566401064f, 0.0008170083747245371f, 0.0005377513007260859f, 0.000785631185863167f, 0.0005709757679142058f, 0.0003723840636666864f, 0.0005387284327298403f, 0.00045977503759786487f, 0.0008882185793481767f, 0.00044933389290235937f, 0.0005420178640633821f, 0.0003844453312922269f, 0.000514947110787034f, 0.0003201085200998932f, 0.0005527924513444304f, 0.0004935609758831561f, 0.0005800637300126255f, 0.0003361167327966541f, 0.00047320197336375713f, 0.000618268153630197f, 0.00034344886080361903f, 0.0006261387025006115f, 0.0006319269305095077f, 0.0008689897949807346f, 0.0007211675983853638f, 0.0005924068973399699f, 0.0006624434026889503f, 0.0007031430141068995f, 0.0007611308828927577f, 0.0003166822425555438f, 0.00036761819501407444f, 0.0005905949510633945f, 0.0006655430770479143f, 0.0006081770989112556f, 0.0003852584050036967f, 0.00042621366446837783f, 0.0004885388188995421f, 0.0006900778971612453f, 0.0002997694828081876f, 0.00045531257637776434f, 0.00048511376371607184f, 0.0005290184053592384f, 0.000808760232757777f, 0.0005142373847775161f, 0.0005279568140394986f, 0.0005874480120837688f, 0.0006704283296130598f, 0.0007270529749803245f, 0.0006801850395277143f, 0.0007925870595499873f, 0.0006864286260679364f, 0.00042106196633540094f, 0.0003937452856916934f, 0.000386425934266299f, 0.0005551819340325892f, 0.0005123857990838587f, 0.00045506173046305776f, 0.000725672987755388f, 0.00033966079354286194f, 0.00041939716902561486f, 0.0004549565492197871f, 0.000528707925695926f, 0.0004428694082889706f, 0.0004899518098682165f, 0.0006818078691139817f, 0.0006022293237037957f, 0.00041344284545630217f, 0.00042111717630177736f, 0.0006008448544889688f, 0.00033349759178236127f, 0.000607463822234422f, 0.0003467537753749639f, 0.0004497401532717049f, 0.0005588876083493233f, 0.0004971551825292408f, 0.0005084110307507217f, 0.0005431145546026528f, 0.0007888099644333124f, 0.00045580827281810343f, 0.0005315570742823184f, 0.0006095513817854226f, 0.0004894183366559446f, 0.0005612695822492242f, 0.0008645887137390673f, 0.00046533477143384516f, 0.0008050079341046512f, 0.0004993422771804035f, 0.0005262621561996639f, 0.000650749949272722f, 0.0005375130567699671f, 0.0005684257484972477f, 0.0005077447276562452f, 0.00048231679829768836f, 0.0005961621063761413f, 0.0006418406846933067f, 0.0005432296311482787f, 0.0003713953192345798f, 0.00039326181286014616f, 0.00040281101246364415f, 0.0007789205410517752f, 0.0005114491796121001f, 0.0004396410076878965f, 0.0008586636395193636f, 0.0006192400469444692f, 0.0005712683778256178f, 0.0005265108775347471f, 0.00044139925739727914f, 0.00045679035247303545f, 0.00037553388392552733f, 0.0007110206643119454f, 0.00041259091813117266f, 0.0003960373578593135f, 0.0003751121403183788f, 0.0007641077972948551f, 0.0005776610923931003f, 0.00041043467354029417f, 0.000656772346701473f, 0.0005596000119112432f, 0.0004231341590639204f, 0.0004283511661924422f, 0.0010579210938885808f, 0.0003683627292048186f, 0.0004056602774653584f, 0.0006289070006459951f, 0.0004418246680870652f, 0.0004912158474326134f, 0.0005778149934485555f, 0.0004133592010475695f, 0.00041553538176231086f, 0.0003330099571030587f, 0.00042051455238834023f, 0.0006632613949477673f, 0.0006206075777299702f, 0.0006100119790062308f, 0.0004934340831823647f, 0.000528923177625984f, 0.0003821783175226301f, 0.0004918563063256443f, 0.0002755777968559414f, 0.0007582700927741826f, 0.00035265955375507474f, 0.0005958629189990461f, 0.000431980675784871f, 0.0006230830913409591f, 0.0005378550849854946f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07536022365093231f),
    AI_PACK_INTQ_ZP(-23)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007844835752621293f),
    AI_PACK_UINTQ_ZP(111)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015528683550655842f, 0.012662702240049839f, 0.022303510457277298f, 0.018006524071097374f, 0.006613288540393114f, 0.007176179438829422f, 0.013148823752999306f, 0.015017510391771793f, 0.0071566966362297535f, 0.01795950159430504f, 0.01091623492538929f, 0.018352370709180832f, 0.018504222854971886f, 0.013375957496464252f, 0.014420508407056332f, 0.02077575959265232f, 0.013143758289515972f, 0.006502761505544186f, 0.012898489832878113f, 0.017044292762875557f, 0.005886781495064497f, 0.015591845847666264f, 0.011824299581348896f, 0.003702278947457671f, 0.01168946921825409f, 0.012240482494235039f, 0.013930946588516235f, 0.01184488832950592f, 0.010182349942624569f, 0.006313649471849203f, 0.007673424202948809f, 0.010058487765491009f, 0.008756178431212902f, 0.005745881237089634f, 0.011296196840703487f, 0.011137454770505428f, 0.011231955140829086f, 0.027743715792894363f, 0.021079521626234055f, 0.016338162124156952f, 0.012095678597688675f, 0.01196813490241766f, 0.011420780792832375f, 0.012310615740716457f, 0.017978524789214134f, 0.020221510902047157f, 0.003928872290998697f, 0.011892682872712612f, 0.013010150752961636f, 0.013904872350394726f, 0.009420991875231266f, 0.01513579860329628f, 0.022594735026359558f, 0.017018044367432594f, 0.010125330649316311f, 0.008219324983656406f, 0.018452949821949005f, 0.02064570225775242f, 0.014201135374605656f, 0.021654201671481133f, 0.02533384971320629f, 0.0042527904734015465f, 0.01762700267136097f, 0.006055944133549929f, 0.010202359408140182f, 0.023730916902422905f, 0.0098612941801548f, 0.008764802478253841f, 0.009458073414862156f, 0.023451054468750954f, 0.019145851954817772f, 0.017398184165358543f, 0.014298574067652225f, 0.011341315694153309f, 0.013604511506855488f, 0.006199512630701065f, 0.024894338101148605f, 0.013859517872333527f, 0.01134063396602869f, 0.013531130738556385f, 0.011152838356792927f, 0.011476226150989532f, 0.016112420707941055f, 0.01368793100118637f, 0.01918366365134716f, 0.01134217344224453f, 0.008091645315289497f, 0.005871667061001062f, 0.007844318635761738f, 0.020226988941431046f, 0.012293575331568718f, 0.013461465016007423f, 0.008410935290157795f, 0.011220567859709263f, 0.008383684791624546f, 0.012347676791250706f, 0.007116513326764107f, 0.011398373171687126f, 0.020157188177108765f, 0.01132985856384039f, 0.0062146373093128204f, 0.011902721598744392f, 0.018281826749444008f, 0.009319823235273361f, 0.007367623504251242f, 0.00813553761690855f, 0.007522366475313902f, 0.01096116192638874f, 0.021271206438541412f, 0.003674193751066923f, 0.008931129239499569f, 0.013751755468547344f, 0.013915813528001308f, 0.0156403798609972f, 0.013004088774323463f, 0.01494382694363594f, 0.013682711869478226f, 0.023722471669316292f, 0.011100219562649727f, 0.004551108926534653f, 0.016095105558633804f, 0.01111963763833046f, 0.011660913936793804f, 0.011641188524663448f, 0.010274435393512249f, 0.00725981779396534f, 0.009473352693021297f, 0.00857850443571806f, 0.009843128733336926f, 0.013954044319689274f, 0.011859744787216187f, 0.014871040359139442f, 0.005642575677484274f, 0.017277570441365242f, 0.005866299849003553f, 0.004772007931023836f, 0.01138239074498415f, 0.01383175328373909f, 0.018741169944405556f, 0.00999390333890915f, 0.01239453349262476f, 0.025922752916812897f, 0.012866746634244919f, 0.007320985198020935f, 0.019727511331439018f, 0.009706090204417706f, 0.013346648775041103f, 0.01105647161602974f, 0.013809962198138237f, 0.015154357068240643f, 0.008097170852124691f, 0.020054256543517113f, 0.020043224096298218f, 0.004272468853741884f, 0.012821833603084087f, 0.01441472489386797f, 0.010183747857809067f, 0.008442684076726437f, 0.012528528459370136f, 0.01684694178402424f, 0.009151753969490528f, 0.007738114334642887f, 0.019592365249991417f, 0.019316771999001503f, 0.013000313192605972f, 0.0054398938082158566f, 0.010404195636510849f, 0.009390552528202534f, 0.005574410315603018f, 0.017064550891518593f, 0.00764090521261096f, 0.01351432129740715f, 0.0175411868840456f, 0.007905849255621433f, 0.011646403931081295f, 0.006678691599518061f, 0.01197933591902256f, 0.010928339324891567f, 0.022528020665049553f, 0.009640909731388092f, 0.010663595050573349f, 0.007608490530401468f, 0.010326031595468521f, 0.011916832998394966f, 0.01032834779471159f, 0.007192142307758331f, 0.00867084227502346f, 0.01062261313199997f, 0.007187080103904009f, 0.008148771710693836f, 0.027680272236466408f, 0.012580106034874916f, 0.01966317556798458f, 0.006541700568050146f, 0.013851565308868885f, 0.013535507954657078f, 0.004152587149292231f, 0.010493344627320766f, 0.010690036229789257f, 0.019210169091820717f, 0.00575812254101038f, 0.010330958291888237f, 0.007878300733864307f, 0.02110612578690052f, 0.011360639706254005f, 0.004735276568681002f, 0.012814735062420368f, 0.012832633219659328f, 0.00788864679634571f, 0.013787341304123402f, 0.012146536260843277f, 0.013598977588117123f, 0.006896715145558119f, 0.009233575314283371f, 0.006039933301508427f, 0.015064689330756664f, 0.01187787763774395f, 0.017690112814307213f, 0.014930184930562973f, 0.012756929732859135f, 0.011059089563786983f, 0.008664241060614586f, 0.011808959767222404f, 0.013392125256359577f, 0.006117599084973335f, 0.009959840215742588f, 0.013043579645454884f, 0.010054760612547398f, 0.01491472776979208f, 0.01806594803929329f, 0.010190781205892563f, 0.0074114263989031315f, 0.012193826027214527f, 0.012659595347940922f, 0.01000302191823721f, 0.011696253903210163f, 0.0070926956832408905f, 0.013897132128477097f, 0.02005624957382679f, 0.0103101572021842f, 0.010161110199987888f, 0.00836384017020464f, 0.005258825141936541f, 0.014272646978497505f, 0.016322126612067223f, 0.009969172067940235f, 0.017905814573168755f, 0.009679251350462437f, 0.024924268946051598f, 0.013671018183231354f, 0.01044697966426611f, 0.017791135236620903f, 0.010494144633412361f, 0.017610421404242516f, 0.011174038052558899f, 0.012408878654241562f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008875324157997966f),
    AI_PACK_UINTQ_ZP(105)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002247558906674385f, 0.002679482800886035f, 0.0027540819719433784f, 0.0025597051717340946f, 0.002535052364692092f, 0.002572959288954735f, 0.0021750088781118393f, 0.0021658437326550484f, 0.002317625330761075f, 0.0028095366433262825f, 0.0029219575226306915f, 0.0019604128319770098f, 0.0025857288856059313f, 0.0024775774218142033f, 0.0029652700759470463f, 0.0024181120097637177f, 0.002421826124191284f, 0.002145608188584447f, 0.002512894803658128f, 0.0019133620662614703f, 0.0023188695777207613f, 0.0030076357070356607f, 0.0026491147000342607f, 0.0020324415527284145f, 0.00236178794875741f, 0.0020878389477729797f, 0.0016714201774448156f, 0.002279756823554635f, 0.002688947133719921f, 0.002238924615085125f, 0.001647861790843308f, 0.0034341304562985897f, 0.00296276924200356f, 0.0028097277972847223f, 0.0020779171027243137f, 0.0021052767988294363f, 0.002654941752552986f, 0.0027081514708697796f, 0.0022730170749127865f, 0.002528024837374687f, 0.0019024390494450927f, 0.0022796306293457747f, 0.0026116592343896627f, 0.002641482511535287f, 0.0022944114170968533f, 0.002241318579763174f, 0.0024907118640840054f, 0.002375122858211398f, 0.002968242857605219f, 0.0021607433445751667f, 0.002699865959584713f, 0.002542380942031741f, 0.00299008097499609f, 0.002219532383605838f, 0.002274000784382224f, 0.0020398611668497324f, 0.003198620630428195f, 0.0027513005770742893f, 0.002448718762025237f, 0.0021957745775580406f, 0.002510202582925558f, 0.0032194305676966906f, 0.0019560488872230053f, 0.0025372605305165052f, 0.002779739210382104f, 0.0023401244543492794f, 0.0024576042778789997f, 0.0019997768104076385f, 0.0025941035710275173f, 0.0029957096558064222f, 0.0026816141325980425f, 0.0030379018280655146f, 0.0025356123223900795f, 0.002647737041115761f, 0.0019526585238054395f, 0.002945916960015893f, 0.002071949653327465f, 0.0024558587465435266f, 0.002202861476689577f, 0.002021949039772153f, 0.002292698947712779f, 0.002343000378459692f, 0.003079372690990567f, 0.0023445419501513243f, 0.0024469776544719934f, 0.0024208880495280027f, 0.0020672273822128773f, 0.0029120424296706915f, 0.002490569604560733f, 0.002306664129719138f, 0.003241295926272869f, 0.002503467258065939f, 0.0029319096356630325f, 0.0023751684930175543f, 0.0024202177301049232f, 0.00199891347438097f, 0.0024600171018391848f, 0.0023088224697858095f, 0.003077699802815914f, 0.0025623010005801916f, 0.0022308947518467903f, 0.002000994049012661f, 0.0021072544623166323f, 0.0022581794764846563f, 0.002712109824642539f, 0.0021838031243532896f, 0.002488453406840563f, 0.002463610377162695f, 0.003627995029091835f, 0.002703110221773386f, 0.002800123766064644f, 0.0021987284999340773f, 0.00238946545869112f, 0.0024347424041479826f, 0.0031320389825850725f, 0.0023725773207843304f, 0.0020080888643860817f, 0.0027382459957152605f, 0.002755698747932911f, 0.0025511402636766434f, 0.0027570503298193216f, 0.0025683457497507334f, 0.0034893574193120003f, 0.0034449314698576927f, 0.002762844320386648f, 0.0030539107974618673f, 0.00215604598633945f, 0.0017660438315942883f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030308496206998825f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00032887348788790405f, 0.00048406748101115227f, 0.00037268258165568113f, 0.0006097181467339396f, 0.0003356878296472132f, 0.0003165373345836997f, 0.0002216286229668185f, 0.000329325906932354f, 0.00037020930903963745f, 0.0005289284163154662f, 0.0005218900623731315f, 0.0006986865773797035f, 0.000501965289004147f, 0.0004401300975587219f, 0.0008695166907273233f, 0.0007736157276667655f, 0.00022277917014434934f, 0.00029207233455963433f, 0.00042940679122693837f, 0.000296522252028808f, 0.00036074177478440106f, 0.00047887262189760804f, 0.0007341965683735907f, 0.00039887905586510897f, 0.0004744321631733328f, 0.0003421301080379635f, 0.0003753489290829748f, 0.00031062756897881627f, 0.0004060267237946391f, 0.0003520296304486692f, 0.0003084026393480599f, 0.0006153855356387794f, 0.00041735381819307804f, 0.00030320981750264764f, 0.0003958950692322105f, 0.00038149103056639433f, 0.00028368787025101483f, 0.0006668898276984692f, 0.0005367143894545734f, 0.0003918315633200109f, 0.0003115608124062419f, 0.0003054122207686305f, 0.00048473753849975765f, 0.0005828635767102242f, 0.00040228385478258133f, 0.00040882910252548754f, 0.0003527227963786572f, 0.0006028332281857729f, 0.0006049876683391631f, 0.00044123432599008083f, 0.00036939195706509054f, 0.0003415152314119041f, 0.0005929991020821035f, 0.0005925521836616099f, 0.0004156182112637907f, 0.0004877805768046528f, 0.0004575637576635927f, 0.0007564466795884073f, 0.00036834104685112834f, 0.00046340786502696574f, 0.0006986203952692449f, 0.0004532929742708802f, 0.0006341351545415819f, 0.0004346172499936074f, 0.0006247074925340712f, 0.00039632292464375496f, 0.0003754634817596525f, 0.0004008646646980196f, 0.0005783824599348009f, 0.0005182526656426489f, 0.00029845040990039706f, 0.00046479361481033266f, 0.0007179348613135517f, 0.0004116332856938243f, 0.00036319001810625196f, 0.00048040904221124947f, 0.0003008076164405793f, 0.00035419364576227963f, 0.0005033134948462248f, 0.00029698762227781117f, 0.0004976175259798765f, 0.00027777213836088777f, 0.00034164698445238173f, 0.0004508935671765357f, 0.000346457032719627f, 0.0006870246143080294f, 0.0005096550448797643f, 0.00047016789903864264f, 0.0003933994739782065f, 0.00036310445284470916f, 0.0003959031018894166f, 0.0003550102992448956f, 0.0003133895806968212f, 0.0005340781062841415f, 0.00046249193837866187f, 0.00046149097033776343f, 0.00047372039989568293f, 0.00041095519554801285f, 0.0003952115075662732f, 0.000612778530921787f, 0.0005756616592407227f, 0.000533633807208389f, 0.00032329201349057257f, 0.0005918784299865365f, 0.00032204424496740103f, 0.0007089016726240516f, 0.00040530928527005017f, 0.0006193629233166575f, 0.0002952380746137351f, 0.0004940633662045002f, 0.0007741216686554253f, 0.0004240270936861634f, 0.00038449789281003177f, 0.0006386599270626903f, 0.00036086660111323f, 0.00038227837649174035f, 0.0007084535318426788f, 0.0003053238906431943f, 0.0005678582820110023f, 0.000511451973579824f, 0.0006511933170258999f, 0.00034861068706959486f, 0.000319653277983889f, 0.0006324414280243218f, 0.0002116412069881335f, 0.0004987119464203715f, 0.00030014209914952517f, 0.00044483249075710773f, 0.0004566529532894492f, 0.00036949620698578656f, 0.00032735851709730923f, 0.0006909067742526531f, 0.0005374529864639044f, 0.00043937101145274937f, 0.00032390846172347665f, 0.0006504981429316103f, 0.0003943787596654147f, 0.00046390166971832514f, 0.0005910689942538738f, 0.0004444857477210462f, 0.0007659313851036131f, 0.0005718368920497596f, 0.0004620444087777287f, 0.0005168949137441814f, 0.00022371318482328206f, 0.0004618826787918806f, 0.00040130133857019246f, 0.0005033137276768684f, 0.0005013158661313355f, 0.0002759219496510923f, 0.00032752001425251365f, 0.0006051964592188597f, 0.0007040731143206358f, 0.0003371778002474457f, 0.00042210903484374285f, 0.0004483907832764089f, 0.00046018659486435354f, 0.0004656969686038792f, 0.0004226437595207244f, 0.0007104004034772515f, 0.0004478642367757857f, 0.0005319486372172832f, 0.00032495331834070385f, 0.000447162106866017f, 0.00047106179408729076f, 0.00029998531681485474f, 0.00037825023173354566f, 0.00030493218218907714f, 0.00044188997708261013f, 0.00029449601424857974f, 0.00040621342486701906f, 0.0004898119368590415f, 0.0006875810213387012f, 0.0005185352056287229f, 0.00042782980017364025f, 0.0004884109366685152f, 0.000563977228011936f, 0.0005878804950043559f, 0.0003053878026548773f, 0.0003802261489909142f, 0.000397805473767221f, 0.00045571691589429975f, 0.0003930003149434924f, 0.000495346961542964f, 0.000582680047955364f, 0.0006610137643292546f, 0.0007276259129866958f, 0.0003759280953090638f, 0.00029758852906525135f, 0.00043842190643772483f, 0.00034025483182631433f, 0.00018532441754359752f, 0.0004181052790954709f, 0.00031290887272916734f, 0.0003579856420401484f, 0.0003876563278026879f, 0.0006190026178956032f, 0.0005034230998717248f, 0.00038188189500942826f, 0.00046749229659326375f, 0.000352442788425833f, 0.0007205306319519877f, 0.0003083055780734867f, 0.0005846178974024951f, 0.00046657840721309185f, 0.0004356538993306458f, 0.0008186868508346379f, 0.0005529783084057271f, 0.0005325849633663893f, 0.0003419938439037651f, 0.00036551791708916426f, 0.0002878923260141164f, 0.0003776400990318507f, 0.00041711688390932977f, 0.00040280562825500965f, 0.00038346604560501873f, 0.0004386953660286963f, 0.00035281231976114213f, 0.0007344058831222355f, 0.000355360156390816f, 0.00032761256443336606f, 0.0006686915876343846f, 0.000642533355858177f, 0.00040199520299211144f, 0.0003085588105022907f, 0.00036584242479875684f, 0.0005566863110288978f, 0.0005166532937437296f, 0.0003573447756934911f, 0.00041205587331205606f, 0.0004903609515167773f, 0.0006128061795607209f, 0.00039342482341453433f, 0.0006363713764585555f, 0.0004573514452204108f, 0.0003555009316187352f, 0.00040251610334962606f, 0.0007062836666591465f, 0.0006152931600809097f, 0.0005105611053295434f, 0.00034609404974617064f, 0.0005861158715561032f, 0.0005011173197999597f, 0.0004962863749824464f, 0.0003693292092066258f, 0.0003300691023468971f, 0.0006315638311207294f, 0.00040572366560809314f, 0.0005615813424810767f, 0.0007682690629735589f, 0.0006168698891997337f, 0.000452100153779611f, 0.0003439798892941326f, 0.0002912904310505837f, 0.0004397669981699437f, 0.0005976269021630287f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0635455846786499f),
    AI_PACK_INTQ_ZP(-33)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00847718515433371f),
    AI_PACK_UINTQ_ZP(109)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012799675576388836f, 0.014638371765613556f, 0.014826505444943905f, 0.008741713128983974f, 0.01156359538435936f, 0.008001850917935371f, 0.024543723091483116f, 0.01357944868505001f, 0.01465954165905714f, 0.016398511826992035f, 0.011488653719425201f, 0.022363871335983276f, 0.009763102978467941f, 0.006193053442984819f, 0.006573972292244434f, 0.008581148460507393f, 0.009363257326185703f, 0.01493450440466404f, 0.014737616293132305f, 0.01756412535905838f, 0.008023732341825962f, 0.01712031476199627f, 0.011189782060682774f, 0.017494957894086838f, 0.014898685738444328f, 0.018267206847667694f, 0.016019340604543686f, 0.008616604842245579f, 0.010801889933645725f, 0.015346123836934566f, 0.02469687908887863f, 0.01530687790364027f, 0.011970466934144497f, 0.015557056292891502f, 0.02793966978788376f, 0.02455509640276432f, 0.01194798294454813f, 0.018066493794322014f, 0.014936292544007301f, 0.015229590237140656f, 0.02054787240922451f, 0.026750439777970314f, 0.007422895636409521f, 0.0088485237210989f, 0.015570458956062794f, 0.01249502319842577f, 0.03273603320121765f, 0.013390216045081615f, 0.0206967294216156f, 0.008318176493048668f, 0.009601760655641556f, 0.018491556867957115f, 0.004674116149544716f, 0.0067377290688455105f, 0.01071025338023901f, 0.004483973141759634f, 0.008475407026708126f, 0.010120064951479435f, 0.019327955320477486f, 0.015174021013081074f, 0.0026760068722069263f, 0.01872679963707924f, 0.013842703774571419f, 0.014266430400311947f, 0.010258637368679047f, 0.014555029571056366f, 0.0076919542625546455f, 0.012411924079060555f, 0.008573915809392929f, 0.00642305938526988f, 0.010000769048929214f, 0.012027260847389698f, 0.004820911679416895f, 0.012236583046615124f, 0.007792412769049406f, 0.010191976092755795f, 0.015054430812597275f, 0.022774523124098778f, 0.014456705190241337f, 0.019702276214957237f, 0.008542350493371487f, 0.010158402845263481f, 0.0120910769328475f, 0.022738488391041756f, 0.013769153505563736f, 0.010336481034755707f, 0.01167304627597332f, 0.020038915798068047f, 0.02754049189388752f, 0.01491756271570921f, 0.012621341273188591f, 0.015058383345603943f, 0.014076542109251022f, 0.009010314010083675f, 0.010275428183376789f, 0.022875739261507988f, 0.01025600079447031f, 0.013077819719910622f, 0.013727182522416115f, 0.015740904957056046f, 0.012449320405721664f, 0.014641834422945976f, 0.018274571746587753f, 0.010623164474964142f, 0.009275761432945728f, 0.010537226684391499f, 0.008469541557133198f, 0.012991410680115223f, 0.019140418618917465f, 0.017909739166498184f, 0.014403452165424824f, 0.018586603924632072f, 0.01587899960577488f, 0.010211776942014694f, 0.012999932281672955f, 0.009668937884271145f, 0.0147774713113904f, 0.014118073508143425f, 0.008401300758123398f, 0.008937949314713478f, 0.004806934390217066f, 0.006582362111657858f, 0.022148743271827698f, 0.023007843643426895f, 0.007593583315610886f, 0.015998538583517075f, 0.023411095142364502f, 0.010941085405647755f, 0.009929844178259373f, 0.013730762526392937f, 0.00967997033149004f, 0.011649109423160553f, 0.006292852107435465f, 0.014333472587168217f, 0.008514630608260632f, 0.005983495153486729f, 0.013781838119029999f, 0.009529603645205498f, 0.01049361377954483f, 0.01974393241107464f, 0.004377416335046291f, 0.0182602871209383f, 0.0112610450014472f, 0.013792973943054676f, 0.02442755177617073f, 0.008140582591295242f, 0.01040367316454649f, 0.009884033352136612f, 0.009535355493426323f, 0.02063874341547489f, 0.009896905161440372f, 0.0132741779088974f, 0.006258913315832615f, 0.013034573756158352f, 0.012313506565988064f, 0.011918038129806519f, 0.010926878079771996f, 0.009174798615276814f, 0.015421019867062569f, 0.00460463110357523f, 0.018679391592741013f, 0.014367984607815742f, 0.015125475823879242f, 0.012636878527700901f, 0.011491543613374233f, 0.01765669696033001f, 0.009616373106837273f, 0.011763566173613071f, 0.009345795027911663f, 0.013792545534670353f, 0.013885930180549622f, 0.005821723025292158f, 0.01150821428745985f, 0.008194825612008572f, 0.022311124950647354f, 0.006656629964709282f, 0.013172629289329052f, 0.006590934004634619f, 0.012156996876001358f, 0.00993263442069292f, 0.013741244561970234f, 0.005891895852982998f, 0.007729359436780214f, 0.019608059898018837f, 0.005424185656011105f, 0.007169270887970924f, 0.0064664618112146854f, 0.011014419607818127f, 0.016738422214984894f, 0.00800997857004404f, 0.006400000769644976f, 0.019679289311170578f, 0.011381465941667557f, 0.011052502319216728f, 0.013522648252546787f, 0.007423499599099159f, 0.004854121711105108f, 0.005236706230789423f, 0.02003403753042221f, 0.006353042554110289f, 0.017698442563414574f, 0.011586734093725681f, 0.015230493620038033f, 0.005841836333274841f, 0.011263536289334297f, 0.02012147381901741f, 0.010877999477088451f, 0.007684203330427408f, 0.01740063540637493f, 0.009003319777548313f, 0.010327067226171494f, 0.009121882729232311f, 0.02767287939786911f, 0.01665256917476654f, 0.0075705647468566895f, 0.01444655004888773f, 0.007241077721118927f, 0.016775142401456833f, 0.009996110573410988f, 0.01496340986341238f, 0.013949571177363396f, 0.010617027059197426f, 0.014073184691369534f, 0.009653563611209393f, 0.0180108230561018f, 0.023917822167277336f, 0.0146181033924222f, 0.012638148851692677f, 0.014615068212151527f, 0.023098943755030632f, 0.012788290157914162f, 0.004070541821420193f, 0.011793060228228569f, 0.00891204085201025f, 0.014717175625264645f, 0.01912086457014084f, 0.020952651277184486f, 0.00563826272264123f, 0.00450971769168973f, 0.015374542213976383f, 0.011136421002447605f, 0.010474509559571743f, 0.017486175522208214f, 0.010853865183889866f, 0.006480589509010315f, 0.01809604838490486f, 0.0049172695726156235f, 0.01975165121257305f, 0.007101899478584528f, 0.009792327880859375f, 0.0063143540173769f, 0.014423951506614685f, 0.03117634356021881f, 0.016107281669974327f, 0.012102789245545864f, 0.008723546750843525f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0078027513809502125f),
    AI_PACK_UINTQ_ZP(124)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029568157624453306f, 0.00211150455288589f, 0.002951664151623845f, 0.0031641286332160234f, 0.0029115090146660805f, 0.003284904407337308f, 0.0034803315065801144f, 0.003648991696536541f, 0.00336631597019732f, 0.002827503252774477f, 0.0031945209484547377f, 0.0028626963030546904f, 0.0028173578903079033f, 0.003209213027730584f, 0.0034224737901240587f, 0.0033146869391202927f, 0.0036477770190685987f, 0.0032698705326765776f, 0.0029200201388448477f, 0.0035895544569939375f, 0.002424592152237892f, 0.00585789792239666f, 0.0030436136294156313f, 0.003476120997220278f, 0.003663822775706649f, 0.003031211206689477f, 0.002485799603164196f, 0.003611222608014941f, 0.0031805550679564476f, 0.0024973745457828045f, 0.00263024540618062f, 0.003334813518449664f, 0.0028835879638791084f, 0.002983401296660304f, 0.0028479313477873802f, 0.003277447074651718f, 0.004056209698319435f, 0.003659188747406006f, 0.0026656200643628836f, 0.003116692416369915f, 0.0027258647605776787f, 0.0030774979386478662f, 0.002728504128754139f, 0.003275214694440365f, 0.0027524030301719904f, 0.0034638824872672558f, 0.0029302441980689764f, 0.0025436789728701115f, 0.0027625791262835264f, 0.0029802292119711637f, 0.002970159286633134f, 0.0029052153695374727f, 0.002781412098556757f, 0.00254201702773571f, 0.0036548732314258814f, 0.003441841574385762f, 0.003603886580094695f, 0.0026810134295374155f, 0.002995383460074663f, 0.002391327638179064f, 0.0028304283041507006f, 0.004455059301108122f, 0.0024862319696694613f, 0.003682611510157585f, 0.004124276805669069f, 0.00274202530272305f, 0.003599639981985092f, 0.0038337938021868467f, 0.0034581045620143414f, 0.0027926245238631964f, 0.0034423707984387875f, 0.0024094772525131702f, 0.003119162516668439f, 0.002550207544118166f, 0.0024808053858578205f, 0.0026514846831560135f, 0.003465356770902872f, 0.0033989031799137592f, 0.0033302661031484604f, 0.0024083061143755913f, 0.0037441749591380358f, 0.00331027340143919f, 0.0036465334706008434f, 0.0023162004072219133f, 0.00333853205665946f, 0.002498824382200837f, 0.0027487471234053373f, 0.0029595540836453438f, 0.0025354300159960985f, 0.002854498801752925f, 0.003775306511670351f, 0.00272277626208961f, 0.003056794172152877f, 0.0031359142158180475f, 0.0027939698193222284f, 0.002576466416940093f, 0.004519535694271326f, 0.002770290244370699f, 0.0030252919532358646f, 0.0033557177521288395f, 0.0029602302238345146f, 0.003882981138303876f, 0.002839070977643132f, 0.004395355004817247f, 0.003200891660526395f, 0.0036597345024347305f, 0.0033149560913443565f, 0.003340606577694416f, 0.0030533261597156525f, 0.0029430168215185404f, 0.0023395842872560024f, 0.0034563420340418816f, 0.0031798994168639183f, 0.0028259234968572855f, 0.0027019050903618336f, 0.002224172232672572f, 0.0028510105330497026f, 0.0028475469443947077f, 0.0025900471955537796f, 0.0028544149827212095f, 0.0029056991916149855f, 0.0034067227970808744f, 0.0035569635219872f, 0.003432548837736249f, 0.0028487867675721645f, 0.004028972238302231f, 0.0022854208946228027f, 0.002625486347824335f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.049198344349861145f),
    AI_PACK_INTQ_ZP(-19)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00043017847929149866f, 0.00036894268123432994f, 0.00037706844159401953f, 0.0005508525064215064f, 0.0002804226242005825f, 0.00039220182225108147f, 0.0005479843239299953f, 0.00033006424200721085f, 0.000407236599130556f, 0.00031494940049014986f, 0.00046527929953299463f, 0.000451125466497615f, 0.00034924535430036485f, 0.0006044605979695916f, 0.0004138118529226631f, 0.00038611763739027083f, 0.00044177277595736086f, 0.0001681141002336517f, 0.0003983662754762918f, 0.000532299920450896f, 0.00035259046126157045f, 0.0003978269814979285f, 0.00043264427222311497f, 0.0003858903073705733f, 0.00028486407245509326f, 0.00030720443464815617f, 0.0003208070120308548f, 0.0005501639097929001f, 0.0005092174396850169f, 0.00033174085547216237f, 0.00043115855078212917f, 0.00037252152105793357f, 0.00033709057606756687f, 0.0003365139418747276f, 0.00039884456782601774f, 0.0004785458731930703f, 0.00044025451643392444f, 0.0003986340307164937f, 0.00027455377858132124f, 0.00031570144346915185f, 0.0003851549990940839f, 0.0002930531045421958f, 0.0002496085944585502f, 0.0005534364026971161f, 0.0005013358895666897f, 0.0003501577884890139f, 0.0002758473274298012f, 0.00047025331878103316f, 0.0005120408022776246f, 0.0003017245326191187f, 0.0002801304799504578f, 0.000391454785130918f, 0.0003553396090865135f, 0.0002597329730633646f, 0.0003549812245182693f, 0.000528270669747144f, 0.0002920471306424588f, 0.0005065028090029955f, 0.0002444796555209905f, 0.0003163024375680834f, 0.00047085387632250786f, 0.00029787400853820145f, 0.0003092630358878523f, 0.0004908042610622942f, 0.00027773980400525033f, 0.0004293419769965112f, 0.0002954403462354094f, 0.0005793852033093572f, 0.0003387032193131745f, 0.0003938501758966595f, 0.00031236198265105486f, 0.00028688108432106674f, 0.00027131312526762486f, 0.0003064639458898455f, 0.0005427048890851438f, 0.0002832919708453119f, 0.0004934014286845922f, 0.0005287157837301493f, 0.0002511854690965265f, 0.0003911414241883904f, 0.0003561026824172586f, 0.00027605099603533745f, 0.00040591598371975124f, 0.000369847024558112f, 0.00030132499523460865f, 0.0003095153660979122f, 0.00045779047650285065f, 0.0005570824141614139f, 0.00025683915009722114f, 0.0002042031119344756f, 0.000359261961420998f, 0.00025961155188269913f, 0.00040958117460832f, 0.00048370708827860653f, 0.00026525065186433494f, 0.0003033023967873305f, 0.0001973278704099357f, 0.0004692969669122249f, 0.00029498065123334527f, 0.00036947859916836023f, 0.0004916188772767782f, 0.000334439508151263f, 0.00028055233997292817f, 0.0003902131284121424f, 0.0005259496974758804f, 0.0003773664648178965f, 0.0005199029692448676f, 0.0003614961460698396f, 0.0003461941087152809f, 0.0002800320798996836f, 0.0003294917696621269f, 0.00037323046126402915f, 0.0003390268830116838f, 0.0002861122484318912f, 0.00028128729900345206f, 0.0005156666156835854f, 0.00042463140562176704f, 0.00039490548078902066f, 0.0004557515785563737f, 0.0003921588067896664f, 0.0003469234216026962f, 0.0004535960906650871f, 0.00037206560955382884f, 0.0002480714174453169f, 0.00034216645872220397f, 0.0003047260397579521f, 0.000348324712831527f, 0.00033927688491530716f, 0.0004084418178535998f, 0.00029270100640133023f, 0.0003815328818745911f, 0.00042798364302143455f, 0.0002957833930850029f, 0.00026923028053715825f, 0.00027403864078223705f, 0.0002916989615187049f, 0.00027772272005677223f, 0.0004944694810546935f, 0.0003728774609044194f, 0.00032024350366555154f, 0.0004953459720127285f, 0.0003272781614214182f, 0.0002723800716921687f, 0.000375171861378476f, 0.00043208463466726243f, 0.00029040907975286245f, 0.000467110046884045f, 0.0003678420325741172f, 0.0007330981898121536f, 0.0003049499646294862f, 0.0003100352478213608f, 0.00040389320929534733f, 0.0003509419912006706f, 0.00028811278752982616f, 0.0003632926964201033f, 0.00040689134038984776f, 0.00043609581189230084f, 0.0003581597120501101f, 0.00044537795474752784f, 0.0006705778068862855f, 0.00034730095649138093f, 0.0004267178301233798f, 0.0003290702879894525f, 0.0003944917698390782f, 0.0002756759349722415f, 0.0002808054268825799f, 0.0006549829267896712f, 0.0002264155336888507f, 0.0005365400575101376f, 0.0003690372977871448f, 0.00032558367820456624f, 0.00027850858168676496f, 0.00026750785764306784f, 0.00036763082607649267f, 0.00020017584029119462f, 0.0003640635695774108f, 0.0004534649779088795f, 0.0005248308298178017f, 0.00025215308414772153f, 0.0005084985750727355f, 0.0003115803701803088f, 0.0002938671095762402f, 0.00044036752660758793f, 0.0002813316823448986f, 0.0004224691947456449f, 0.00024550524540245533f, 0.0003192941367160529f, 0.0005685900687240064f, 0.0003846772015094757f, 0.0005961348069831729f, 0.00026338640600442886f, 0.000505824398715049f, 0.00031653931364417076f, 0.000343647669069469f, 0.00021895594545640051f, 0.0004701006691902876f, 0.00028951396234333515f, 0.0005917183007113636f, 0.0005727507523261011f, 0.00044842928764410317f, 0.00029240173171274364f, 0.0006044725887477398f, 0.00039632502011954784f, 0.0003563912760000676f, 0.0003107067313976586f, 0.0002781844523269683f, 0.00046551466220989823f, 0.00024831551127135754f, 0.0003339280956424773f, 0.0006198919145390391f, 0.00023791662533767521f, 0.00036452870699577034f, 0.000517276581376791f, 0.00044637173414230347f, 0.00038311845855787396f, 0.0002324546076124534f, 0.0005188653594814241f, 0.0004417583404574543f, 0.0003097726439591497f, 0.00027326447889208794f, 0.00027367001166567206f, 0.0003336999216116965f, 0.0004028152907267213f, 0.0005802132072858512f, 0.00028836127603426576f, 0.00030683173099532723f, 0.00029601057758554816f, 0.0003814975207205862f, 0.0003374780062586069f, 0.00039938915870152414f, 0.00036012206692248583f, 0.00028123834636062384f, 0.00032928146538324654f, 0.00034532276913523674f, 0.0005619956064037979f, 0.0005173005047254264f, 0.0003539755998644978f, 0.00025363246095366776f, 0.0002537689288146794f, 0.0004684677696786821f, 0.0002756260510068387f, 0.0006009991047903895f, 0.0002856604114640504f, 0.0004036894824821502f, 0.0005056674708612263f, 0.00031375529943034053f, 0.00040310455369763076f, 0.0005834250478073955f, 0.000521251349709928f, 0.0003790214250329882f, 0.0005203564651310444f, 0.00024700950598344207f, 0.0003455726255197078f, 0.00031206445419229567f, 0.0003044357872568071f, 0.0004172503831796348f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007879598066210747f),
    AI_PACK_UINTQ_ZP(107)))

/* Int quant #160 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07356163114309311f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #161 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013798752799630165f, 0.007830105721950531f, 0.007905465550720692f, 0.005836958065629005f, 0.008859890513122082f, 0.007821924053132534f, 0.004818866029381752f, 0.021572427824139595f, 0.008735695853829384f, 0.01520537305623293f, 0.012028099037706852f, 0.004019012674689293f, 0.01631198264658451f, 0.01011753361672163f, 0.013219734653830528f, 0.012539727613329887f, 0.015990911051630974f, 0.018144944682717323f, 0.012422614730894566f, 0.008142192848026752f, 0.007392850238829851f, 0.013011095114052296f, 0.010065881535410881f, 0.008313261903822422f, 0.018963085487484932f, 0.03702457249164581f, 0.008244527503848076f, 0.02217913046479225f, 0.01862494833767414f, 0.008716344833374023f, 0.02491689845919609f, 0.013751384802162647f, 0.005328175611793995f, 0.011682623997330666f, 0.009781097993254662f, 0.009727363474667072f, 0.012869005091488361f, 0.012087998911738396f, 0.019317209720611572f, 0.01606689766049385f, 0.01630987599492073f, 0.006796443834900856f, 0.021995453163981438f, 0.012522845529019833f, 0.01737348735332489f, 0.0073297289200127125f, 0.014367257244884968f, 0.012698504142463207f, 0.01660395972430706f, 0.00732504203915596f, 0.00839091558009386f, 0.016381897032260895f, 0.015776190906763077f, 0.016893591731786728f, 0.009725285694003105f, 0.018302051350474358f, 0.015223322436213493f, 0.007421898655593395f, 0.015004240907728672f, 0.022121397778391838f, 0.00394582049921155f, 0.03854670748114586f, 0.02700883522629738f, 0.006646729540079832f, 0.008452477864921093f, 0.018915265798568726f, 0.025878479704260826f, 0.005214679054915905f, 0.008745861239731312f, 0.00842228438705206f, 0.010744040831923485f, 0.019878597930073738f, 0.022197041660547256f, 0.0130649134516716f, 0.009520924650132656f, 0.016119154170155525f, 0.004484676755964756f, 0.012552962638437748f, 0.012478669174015522f, 0.015228237956762314f, 0.017739539965987206f, 0.009175474755465984f, 0.018278395757079124f, 0.012507930397987366f, 0.011715083383023739f, 0.007700878661125898f, 0.016368405893445015f, 0.006190144456923008f, 0.01941557787358761f, 0.021471776068210602f, 0.0049301572144031525f, 0.012076669372618198f, 0.006414803210645914f, 0.00916996132582426f, 0.006593675818294287f, 0.007998798042535782f, 0.019048886373639107f, 0.005965498276054859f, 0.006910570897161961f, 0.014345403760671616f, 0.014454114250838757f, 0.017249509692192078f, 0.008730906061828136f, 0.011277678422629833f, 0.010962269268929958f, 0.005611808504909277f, 0.00454333471134305f, 0.010429484769701958f, 0.02012675255537033f, 0.015455427579581738f, 0.01050699781626463f, 0.01082618348300457f, 0.013324649073183537f, 0.014870679005980492f, 0.011078656651079655f, 0.012736971490085125f, 0.01639217883348465f, 0.00906028226017952f, 0.007603679317981005f, 0.008785228244960308f, 0.01899510808289051f, 0.009538211859762669f, 0.020830463618040085f, 0.021301940083503723f, 0.019094135612249374f, 0.01897517777979374f, 0.00916536245495081f, 0.011560576967895031f, 0.006047609727829695f, 0.011764051392674446f, 0.01587732695043087f, 0.006966253276914358f, 0.025181151926517487f, 0.01650053821504116f, 0.014816944487392902f, 0.01538027636706829f, 0.013813909143209457f, 0.006370720453560352f, 0.01386845763772726f, 0.014186627231538296f, 0.015753798186779022f, 0.01918427273631096f, 0.02613525465130806f, 0.011434445157647133f, 0.012358828447759151f, 0.013067835941910744f, 0.010700967162847519f, 0.004514503292739391f, 0.01307812798768282f, 0.019837817177176476f, 0.012612265534698963f, 0.01564691588282585f, 0.020942753180861473f, 0.01904365047812462f, 0.009119536727666855f, 0.013366129249334335f, 0.004187330137938261f, 0.012640666216611862f, 0.0054532187059521675f, 0.01018095575273037f, 0.023645278066396713f, 0.009978540241718292f, 0.013712813146412373f, 0.007701659109443426f, 0.019123220816254616f, 0.006348655559122562f, 0.009093886241316795f, 0.01267690397799015f, 0.0034822451416403055f, 0.00952010229229927f, 0.0064680613577365875f, 0.017555419355630875f, 0.015058053657412529f, 0.015846554189920425f, 0.013651812449097633f, 0.00833147019147873f, 0.006301561836153269f, 0.011572083458304405f, 0.01623213104903698f, 0.014994975179433823f, 0.013894765637814999f, 0.0062667992897331715f, 0.006128910928964615f, 0.010036582127213478f, 0.01435368787497282f, 0.01500422228127718f, 0.012158063240349293f, 0.008361782878637314f, 0.008231617510318756f, 0.011439087800681591f, 0.028176214545965195f, 0.00901984702795744f, 0.03324020281434059f, 0.014458447694778442f, 0.012125006876885891f, 0.02293778955936432f, 0.012894541956484318f, 0.0076406775042414665f, 0.005558469332754612f, 0.012143220752477646f, 0.009576426818966866f, 0.005921888165175915f, 0.011581582017242908f, 0.012931495904922485f, 0.011847718618810177f, 0.010676738806068897f, 0.01045654434710741f, 0.01387115940451622f, 0.01350470632314682f, 0.007462237495929003f, 0.02578205242753029f, 0.019761046394705772f, 0.00747422082349658f, 0.013484778814017773f, 0.019418086856603622f, 0.0212082676589489f, 0.011298531666398048f, 0.01275787316262722f, 0.01415814459323883f, 0.025697017088532448f, 0.007233428303152323f, 0.01650015078485012f, 0.016314474865794182f, 0.014709335751831532f, 0.008667318150401115f, 0.01803572289645672f, 0.010950947180390358f, 0.0075209420174360275f, 0.008352112956345081f, 0.007398700807243586f, 0.022163400426506996f, 0.023699790239334106f, 0.01972835324704647f, 0.012002894654870033f, 0.006793670356273651f, 0.0061481306329369545f, 0.019689032807946205f, 0.01322883553802967f, 0.019592484459280968f, 0.020620252937078476f, 0.011636422015726566f, 0.00857336726039648f, 0.0140574024990201f, 0.012789455242455006f, 0.006058668252080679f, 0.020787561312317848f, 0.015169994905591011f, 0.01457867119461298f, 0.0171782448887825f, 0.017528625205159187f, 0.009579331614077091f, 0.011373156681656837f, 0.01198570802807808f, 0.009966504760086536f, 0.019005311653017998f, 0.007650523446500301f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #162 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007761023472994566f),
    AI_PACK_UINTQ_ZP(114)))

/* Int quant #163 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035505134146660566f, 0.0037136105820536613f, 0.0035289544612169266f, 0.0028193043544888496f, 0.003210794646292925f, 0.0033421979751437902f, 0.00475710816681385f, 0.0042694141156971455f, 0.003292153123766184f, 0.003561408957466483f, 0.004356527701020241f, 0.00444606551900506f, 0.004749865271151066f, 0.004478720016777515f, 0.0034067342057824135f, 0.00383363151922822f, 0.0035082767717540264f, 0.004438810981810093f, 0.00321199675090611f, 0.003182237735018134f, 0.003464544890448451f, 0.004910130053758621f, 0.00308962631970644f, 0.005493371281772852f, 0.004114472772926092f, 0.00384794594720006f, 0.0038652364164590836f, 0.00583151588216424f, 0.003544334787875414f, 0.003506892593577504f, 0.0027384553104639053f, 0.0033580895978957415f, 0.003427567658945918f, 0.002958172233775258f, 0.0032311268150806427f, 0.004473079461604357f, 0.003596547292545438f, 0.003922892734408379f, 0.003827402601018548f, 0.0034221771638840437f, 0.003325431142002344f, 0.00257882010191679f, 0.004382960963994265f, 0.004612540360540152f, 0.003710945136845112f, 0.004750958178192377f, 0.004596017301082611f, 0.003430538810789585f, 0.004213524516671896f, 0.0051839216612279415f, 0.0035568412858992815f, 0.003913049586117268f, 0.0032851891592144966f, 0.003458493622019887f, 0.0037414017133414745f, 0.0034282428678125143f, 0.0029463893733918667f, 0.0039840685203671455f, 0.0047433278523385525f, 0.003607461927458644f, 0.004284787457436323f, 0.0058844671584665775f, 0.003032726002857089f, 0.004609157331287861f, 0.004732243716716766f, 0.00333316414617002f, 0.003259020857512951f, 0.003272345056757331f, 0.0034689081367105246f, 0.0034697295632213354f, 0.0037065159995108843f, 0.0037950247060507536f, 0.003413441125303507f, 0.004438789561390877f, 0.0037933005951344967f, 0.003614198649302125f, 0.004782239906489849f, 0.003525426145642996f, 0.004104065243154764f, 0.0038229210767894983f, 0.0037167267873883247f, 0.003664810676127672f, 0.003106278833001852f, 0.0027602706104516983f, 0.004287681542336941f, 0.0034752627834677696f, 0.0037341492716223f, 0.003619082737714052f, 0.0037907937075942755f, 0.0030573487747460604f, 0.004730673506855965f, 0.003802268533036113f, 0.0034453682601451874f, 0.003456375328823924f, 0.00333016412332654f, 0.004205201752483845f, 0.0033952263183891773f, 0.00408098055049777f, 0.003294607624411583f, 0.003197157522663474f, 0.0048566958867013454f, 0.0034580205101519823f, 0.003907405771315098f, 0.0033737155608832836f, 0.0035788225941359997f, 0.004398437216877937f, 0.003389862598851323f, 0.003736122976988554f, 0.004708065651357174f, 0.005121028050780296f, 0.004184019286185503f, 0.0033786494750529528f, 0.004108379129320383f, 0.003337680362164974f, 0.004468170460313559f, 0.00414914870634675f, 0.00367787410505116f, 0.003745528170838952f, 0.003124827053397894f, 0.003958902321755886f, 0.004373346921056509f, 0.004270770121365786f, 0.0034831734374165535f, 0.0036963277962058783f, 0.0035861481446772814f, 0.0040853992104530334f, 0.002278582425788045f, 0.0029972391203045845f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #164 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_conv2_conv_Conv_output_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06409502774477005f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #165 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 512,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005043248529545963f, 0.00026589896879158914f, 0.00042028044117614627f, 0.00039797037607058883f, 0.0002622453903313726f, 0.00034547748509794474f, 0.0003467591595835984f, 0.0004619826504494995f, 0.00020583606965374202f, 0.0003128841344732791f, 0.0004420398036018014f, 0.0003698243817780167f, 0.0003311895707156509f, 0.0002213302068412304f, 0.00019343318126630038f, 0.0003509591333568096f, 0.0003892614913638681f, 0.0002596589911263436f, 0.0004368714289739728f, 0.00029607187025249004f, 0.00023412334849126637f, 0.0003258773067500442f, 0.0002552929217927158f, 0.00046376194222830236f, 0.00020378919725771993f, 0.0002073446084978059f, 0.00023195309040602297f, 0.00033441686537116766f, 0.000526708026882261f, 0.00042665432556532323f, 0.00025936373276636004f, 0.0003212815208826214f, 0.00036602155887521803f, 0.00034446961944922805f, 0.00035043462412431836f, 0.0003425401810090989f, 0.000522148737218231f, 0.0003788718313444406f, 0.0003974598948843777f, 0.0002274703438160941f, 0.00033509513013996184f, 0.0005591986118815839f, 0.00027346203569322824f, 0.0005153301754035056f, 0.0005893826019018888f, 0.0003793525684159249f, 0.0004338406433816999f, 0.0003298679366707802f, 0.00046907595242373645f, 0.00038719127769581974f, 0.00025731028290465474f, 0.0003140385961160064f, 0.0003796903183683753f, 0.00028154425672255456f, 0.0005569779896177351f, 0.0004005278169643134f, 0.000318944628816098f, 0.00045927613973617554f, 0.0002001825050683692f, 0.00017311002011410892f, 0.00040422871825285256f, 0.0004156412906013429f, 0.0003366532037034631f, 0.00044804223580285907f, 0.0002337134792469442f, 0.00039261713391169906f, 0.0005685948999598622f, 0.0005289341206662357f, 0.00019037890888284892f, 0.0005597613053396344f, 0.00019761579460464418f, 0.0002906781155616045f, 0.00037444086046889424f, 0.00024695173487998545f, 0.0006538995075970888f, 0.0002361801452934742f, 0.00021437906252685934f, 0.00024224114895332605f, 0.0003207578556612134f, 0.0005446220166049898f, 0.00024507034686394036f, 0.00034194334875792265f, 0.0004662121064029634f, 0.0003719694504979998f, 0.00045684206997975707f, 0.00034881499595940113f, 0.0004286573675926775f, 0.0004384645726531744f, 0.00028215721249580383f, 0.00044883787631988525f, 0.0003077994042541832f, 0.0003048318612854928f, 0.0004844432114623487f, 0.0002848597941920161f, 0.00035163501161150634f, 0.0002583056048024446f, 0.00030684639932587743f, 0.0003673569590318948f, 0.0004331960517447442f, 0.00038972104084677994f, 0.0004582811670843512f, 0.00032908059074543417f, 0.00028522612410597503f, 0.0005129472119733691f, 0.00022723058646079153f, 0.0002449280000291765f, 0.0004679052799474448f, 0.00028769957134500146f, 0.0005768275586888194f, 0.00019379620789550245f, 0.0003982112684752792f, 0.0005484758294187486f, 0.0003549021785147488f, 0.00041079448419623077f, 0.00038140849210321903f, 0.0004367016954347491f, 0.0004685982421506196f, 0.00021862580615561455f, 0.00041996731306426227f, 0.00035940625821240246f, 0.00024042173754423857f, 0.0003151021956000477f, 0.00040330240153707564f, 0.00048294843873009086f, 0.0003573592402972281f, 0.00020158504776190966f, 0.00040560198249295354f, 0.0004463086661417037f, 0.00029916042694821954f, 0.00038191769272089005f, 0.00043655416811816394f, 0.0003209489514119923f, 0.00035315126297064126f, 0.00041296693962067366f, 0.00043467702926136553f, 0.00040889630327001214f, 0.0003096472064498812f, 0.0003358525864314288f, 0.0004301846493035555f, 0.0004746003251057118f, 0.00021455287060234696f, 0.0003817969118244946f, 0.00039347560959868133f, 0.0006451213266700506f, 0.0005347617552615702f, 0.000506530690472573f, 0.0003320629184599966f, 0.0002848537696991116f, 0.0004041664651595056f, 0.0002345469401916489f, 0.0002639393205754459f, 0.000293968478217721f, 0.0003289337910246104f, 0.00037010907544754446f, 0.00022906392405275255f, 0.0004477398470044136f, 0.00035483998362906277f, 0.00038072827737778425f, 0.0005014470661990345f, 0.000458176014944911f, 0.00047250158968381584f, 0.0003137935418635607f, 0.00039675168227404356f, 0.0003610198909882456f, 0.00027472199872136116f, 0.0004674822266679257f, 0.0004542520910035819f, 0.0004691486246883869f, 0.0003376042586751282f, 0.00028925176593475044f, 0.0004220818227622658f, 0.00027882997528649867f, 0.00048267198144458234f, 0.0005485063302330673f, 0.00046361578279174864f, 0.00029380593332462013f, 0.0004846424562856555f, 0.00022480568441096693f, 0.0005063624703325331f, 0.00028447931981645525f, 0.0004233716463204473f, 0.00037371995858848095f, 0.00029497899231500924f, 0.00024244152882602066f, 0.00034200388472527266f, 0.00023369993141386658f, 0.00038532892358489335f, 0.00032177349203266203f, 0.00028359342832118273f, 0.0004373256815597415f, 0.0005096476525068283f, 0.00045726296957582235f, 0.00022455865109805018f, 0.00038427533581852913f, 0.000186441233381629f, 0.0003513957199174911f, 0.0003579875046852976f, 0.0003022491291631013f, 0.0004924879176542163f, 0.0005580687429755926f, 0.0005627716891467571f, 0.0003062060277443379f, 0.00027392731863074005f, 0.000528150238096714f, 0.0003363117575645447f, 0.0002173957764171064f, 0.00048486219020560384f, 0.0002787951671052724f, 0.0004669019836001098f, 0.0004216675879433751f, 0.0004108659632038325f, 0.000484543590573594f, 0.00039788917638361454f, 0.00022910497500561178f, 0.0003395998210180551f, 0.00034989957930520177f, 0.00034284216235391796f, 0.0004419691686052829f, 0.0004829771351069212f, 0.0005416388157755136f, 0.0003722586843650788f, 0.00043108544196002185f, 0.0004076175100635737f, 0.00045304352534003556f, 0.00023681882885284722f, 0.00034433187101967633f, 0.000527984113432467f, 0.0005913475761190057f, 0.0004050237184856087f, 0.0002934529329650104f, 0.0002943319850601256f, 0.0003503001935314387f, 0.00028202973771840334f, 0.0005484175635501742f, 0.00041835481533780694f, 0.0004084001120645553f, 0.0005353402229957283f, 0.0003893844841513783f, 0.00031856162240728736f, 0.0004904957604594529f, 0.0004431947018019855f, 0.0003266987332608551f, 0.0002309827832505107f, 0.00038117007352411747f, 0.00033335090847685933f, 0.0004754793189931661f, 0.0004792494291905314f, 0.0003398566332180053f, 0.00040043654735200107f, 0.00034185967524535954f, 0.0003771423944272101f, 0.0002870983153115958f, 0.00020635534019675106f, 0.0005102755967527628f, 0.0003821537538897246f, 0.0003638328635133803f, 0.0004444678488653153f, 0.00024976086569949985f, 0.000472921907203272f, 0.00042616119026206434f, 0.0005810054135508835f, 0.0004419407341629267f, 0.00029916834319010377f, 0.0004247830365784466f, 0.0005068291211500764f, 0.00042589096119627357f, 0.00030848581809550524f, 0.00046438927529379725f, 0.0003574976581148803f, 0.0003940238675568253f, 0.00023770402185618877f, 0.00041242584120482206f, 0.00044761522440239787f, 0.00026028952561318874f, 0.00021727960847783834f, 0.00036261198692955077f, 0.0003643242234829813f, 0.0006216338369995356f, 0.00036077783443033695f, 0.0003516015422064811f, 0.0003459762374404818f, 0.0002489520120434463f, 0.0004207670863252133f, 0.0003426323819439858f, 0.00030576655990444124f, 0.00042019912507385015f, 0.0003813200746662915f, 0.000461768067907542f, 0.0005091180210001767f, 0.0004573391343001276f, 0.0003168381517753005f, 0.0002486658631823957f, 0.0002702930069062859f, 0.00025309986085630953f, 0.0002097335091093555f, 0.00022615279885940254f, 0.000421784701757133f, 0.0002661770849954337f, 0.0003013030509464443f, 0.0005179467261768878f, 0.0004159761592745781f, 0.00042159639997407794f, 0.00032027793349698186f, 0.0004523860407061875f, 0.00035678769927471876f, 0.0002793262538034469f, 0.0005098091205582023f, 0.0003019564028363675f, 0.00047235481906682253f, 0.0002061533014057204f, 0.0002828043361660093f, 0.0005369580467231572f, 0.0002747778198681772f, 0.00036605651257559657f, 0.0005050781765021384f, 0.00036898889811709523f, 0.0004703662416432053f, 0.0003895980480592698f, 0.0003841318830382079f, 0.0005286922096274793f, 0.0004412551934365183f, 0.0002656028082128614f, 0.00038245724863372743f, 0.0002953741932287812f, 0.0003398402768652886f, 0.00031611492158845067f, 0.00031450833193957806f, 0.0003006605838891119f, 0.00048660836182534695f, 0.00035922613460570574f, 0.0003994647122453898f, 0.00044525059638544917f, 0.0004098628705833107f, 0.0003161199565511197f, 0.00027349029551260173f, 0.00043591755093075335f, 0.0003440206637606025f, 0.0003708364674821496f, 0.0003289037849754095f, 0.00020874547772109509f, 0.0003317437367513776f, 0.0003060247399844229f, 0.000503586488775909f, 0.0004902069340460002f, 0.00038792449049651623f, 0.0003928553487639874f, 0.0003170845448039472f, 0.0005106791504658759f, 0.00037638438516296446f, 0.0002093012008117512f, 0.00036606917274184525f, 0.000381816818844527f, 0.00040651520248502493f, 0.00028195345657877624f, 0.00023862872330937535f, 0.0002047312300419435f, 0.00028993934392929077f, 0.0004051737196277827f, 0.000518816988915205f, 0.00038644412416033447f, 0.00039963863673619926f, 0.00041841130587272346f, 0.00045323718222789466f, 0.0005254737916402519f, 0.00046079236199148f, 0.00029351506964303553f, 0.0005854814080521464f, 0.0003384232986718416f, 0.000362493097782135f, 0.00020658422727137804f, 0.00022116038599051535f, 0.0005615144036710262f, 0.00043168841511942446f, 0.00024693412706255913f, 0.00034489596146158874f, 0.00034086857340298593f, 0.000292110227746889f, 0.0006736963405273855f, 0.0003521937760524452f, 0.00027481711003929377f, 0.0002680528268683702f, 0.00037097386666573584f, 0.00020768787362612784f, 0.0004277254338376224f, 0.0005050741601735353f, 0.00039543499588035047f, 0.0004318075079936534f, 0.00039924654993228614f, 0.0004757591232191771f, 0.0004309127980377525f, 0.00026412264560349286f, 0.0003161159693263471f, 0.0004969626315869391f, 0.0005192205426283181f, 0.000496328342705965f, 0.0004554590559564531f, 0.0004173424676991999f, 0.00028147402917966247f, 0.00038133718771860003f, 0.0003690972225740552f, 0.000416518741985783f, 0.0005282458732835948f, 0.00035884152748622f, 0.00021466350881382823f, 0.0005418746150098741f, 0.000555475358851254f, 0.0001889223203761503f, 0.00031789703643880785f, 0.0003793133073486388f, 0.00032159165129996836f, 0.0004212212807033211f, 0.00044859491754323244f, 0.0004177645605523139f, 0.0002878077211789787f, 0.0004514450265560299f, 0.000346568034728989f, 0.0003708127769641578f, 0.0002487500896677375f, 0.0004891342832706869f, 0.0002684216306079179f, 0.00048569144564680755f, 0.0003837188705801964f, 0.0002684787614271045f, 0.0004353217373136431f, 0.00028158226632513106f, 0.00041857745964080095f, 0.0003762610722333193f, 0.00026957469526678324f, 0.0003833660448435694f, 0.00021945075422991067f, 0.0002679648750927299f, 0.00030305268592201173f, 0.0003177175822202116f, 0.00026532431365922093f, 0.0005391162703745067f, 0.00025064017972908914f, 0.0002897050289902836f, 0.00031451150425709784f, 0.00045757455518469214f, 0.000336827477440238f, 0.0007165608112700284f, 0.0004300774889998138f, 0.00045008747838437557f, 0.00039143074536696076f, 0.0002563865855336189f, 0.00026111569604836404f, 0.00031911858241073787f, 0.0004282428417354822f, 0.0004378611920401454f, 0.0004358537553343922f, 0.0004249869380146265f, 0.00019290987984277308f, 0.00020143554138485342f, 0.0004884858499281108f, 0.0003366673190612346f, 0.000314250064548105f, 0.0003208574780728668f, 0.00023816528846509755f, 0.0003261940728407353f, 0.00035364716313779354f, 0.0002670215617399663f, 0.00022590719163417816f, 0.000323648244375363f, 0.0004886027309112251f, 0.0002370361180510372f, 0.0004476072499528527f, 0.00038573896745219827f, 0.00040820747381076217f, 0.00045227460213936865f, 0.0004099041107110679f, 0.0002937790413852781f, 0.00035236525582149625f, 0.00025373350945301354f, 0.00027136586140841246f, 0.0005263774073682725f, 0.00041756933205761015f, 0.00018870166968554258f, 0.00034803678863681853f, 0.00039773614844307303f, 0.00020540585683193058f, 0.00020057923393324018f, 0.00040569042903371155f, 0.00019338053243700415f, 0.0002460727118887007f, 0.0003873399109579623f, 0.00035508067230693996f, 0.00048442918341606855f, 0.0005853902548551559f, 0.0003888604696840048f, 0.00015775459178257734f, 0.0004762054595630616f, 0.0004255644744262099f, 0.0004424242360983044f, 0.000358719436917454f, 0.0002599981380626559f, 0.00035312335239723325f, 0.0006619716295972466f, 0.0003514010168146342f, 0.0006158594042062759f, 0.000363282160833478f, 0.0004149838350713253f, 0.00028489792020991445f, 0.0004453201836440712f, 0.0005019114469178021f, 0.0003907389473170042f, 0.0002575952676124871f, 0.0002360018261242658f, 0.0005415229243226349f, 0.0002959633129648864f, 0.0003501789760775864f, 0.0002429266896797344f, 0.0002977022377308458f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #166 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008688063826411963f),
    AI_PACK_UINTQ_ZP(110)))

/* Int quant #167 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 512,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008340520784258842f, 0.008945859968662262f, 0.008147897198796272f, 0.008357405662536621f, 0.0070806159637868404f, 0.00596463680267334f, 0.014849871397018433f, 0.014068574644625187f, 0.007939142175018787f, 0.009346884675323963f, 0.01143345795571804f, 0.007259085774421692f, 0.01360470149666071f, 0.021672436967492104f, 0.00987375807017088f, 0.00662200665101409f, 0.011380919255316257f, 0.013619368895888329f, 0.010623438283801079f, 0.014675354585051537f, 0.01952764019370079f, 0.008915496058762074f, 0.007531612180173397f, 0.00865505076944828f, 0.011077262461185455f, 0.015037395060062408f, 0.02189650572836399f, 0.021874001249670982f, 0.007824728265404701f, 0.007693483028560877f, 0.01137236412614584f, 0.013497795909643173f, 0.008717712946236134f, 0.00589413708075881f, 0.007175106555223465f, 0.010077524930238724f, 0.0048672910779714584f, 0.012180130928754807f, 0.008939515799283981f, 0.01652640290558338f, 0.007585955783724785f, 0.005279507488012314f, 0.01317998580634594f, 0.005763666704297066f, 0.005856591742485762f, 0.006526242010295391f, 0.011454620398581028f, 0.013509073294699192f, 0.006560310255736113f, 0.006300223991274834f, 0.01824912615120411f, 0.011829537339508533f, 0.006940584164112806f, 0.013851958326995373f, 0.009896986186504364f, 0.0059819468297064304f, 0.008469339460134506f, 0.006624951958656311f, 0.008309704251587391f, 0.013944191858172417f, 0.0060449326410889626f, 0.011867204681038857f, 0.025905245915055275f, 0.010268033482134342f, 0.019440121948719025f, 0.007327720522880554f, 0.004585898946970701f, 0.006484643556177616f, 0.022378435358405113f, 0.008322286419570446f, 0.010103403590619564f, 0.013976090587675571f, 0.008468300104141235f, 0.008641596883535385f, 0.006529351230710745f, 0.014787892811000347f, 0.014014525339007378f, 0.011590705253183842f, 0.0069620078429579735f, 0.0116184763610363f, 0.009615146555006504f, 0.013789409771561623f, 0.004767123609781265f, 0.006458839401602745f, 0.0074845366179943085f, 0.006992029026150703f, 0.005147657822817564f, 0.007691503968089819f, 0.010354282334446907f, 0.007862886413931847f, 0.006743698380887508f, 0.007255605421960354f, 0.006320560351014137f, 0.01688086800277233f, 0.007186825852841139f, 0.016802778467535973f, 0.008133859373629093f, 0.008314245380461216f, 0.007903073914349079f, 0.005022928584367037f, 0.010376712307333946f, 0.006651632487773895f, 0.011128468438982964f, 0.007234413176774979f, 0.014231693930923939f, 0.0141294589266181f, 0.005966269411146641f, 0.030470075085759163f, 0.007567211054265499f, 0.011404000222682953f, 0.006811224855482578f, 0.00515312235802412f, 0.00961737334728241f, 0.008036594837903976f, 0.007669635582715273f, 0.005299487616866827f, 0.00862580630928278f, 0.014822287485003471f, 0.00711174588650465f, 0.011906190775334835f, 0.012879312969744205f, 0.005536020267754793f, 0.005970504600554705f, 0.007251992356032133f, 0.01367113646119833f, 0.007998955436050892f, 0.006665739696472883f, 0.008261851966381073f, 0.013937342911958694f, 0.007587681524455547f, 0.007763055618852377f, 0.012033761478960514f, 0.00750575540587306f, 0.009613564237952232f, 0.006415740121155977f, 0.009266095235943794f, 0.007754949852824211f, 0.010447490029036999f, 0.012101476080715656f, 0.007934381254017353f, 0.011023394763469696f, 0.012359470129013062f, 0.012526225298643112f, 0.007003613747656345f, 0.007326847407966852f, 0.005412123631685972f, 0.010186045430600643f, 0.01022624596953392f, 0.013003984466195107f, 0.0065732491202652454f, 0.015379241667687893f, 0.008755169808864594f, 0.010123714804649353f, 0.0062540192157030106f, 0.014076324179768562f, 0.004629088100045919f, 0.008799311704933643f, 0.005438549909740686f, 0.008009152486920357f, 0.0038399328477680683f, 0.006255560554563999f, 0.007714582607150078f, 0.006609938573092222f, 0.008866693824529648f, 0.012067022733390331f, 0.007397742010653019f, 0.022421235218644142f, 0.004959749523550272f, 0.010654488578438759f, 0.012222970835864544f, 0.0071321637369692326f, 0.006377742625772953f, 0.005748277995735407f, 0.006956488359719515f, 0.008825479075312614f, 0.010638211853802204f, 0.005072535946965218f, 0.01783440075814724f, 0.0047633764334023f, 0.025467045605182648f, 0.01019203756004572f, 0.01154241431504488f, 0.014527348801493645f, 0.014138691127300262f, 0.007684804033488035f, 0.014909359626471996f, 0.00866270437836647f, 0.010568934492766857f, 0.012412428855895996f, 0.007152028847485781f, 0.0072667463682591915f, 0.007008274085819721f, 0.020068775862455368f, 0.00755347078666091f, 0.025439351797103882f, 0.011531629599630833f, 0.007109290920197964f, 0.005850540939718485f, 0.006112573202699423f, 0.007205624133348465f, 0.0041891708970069885f, 0.011360634118318558f, 0.012423168867826462f, 0.0064348927699029446f, 0.005964912474155426f, 0.011556139215826988f, 0.0072980839759111404f, 0.010120806284248829f, 0.005780535284429789f, 0.009406549856066704f, 0.012267524376511574f, 0.0068449592217803f, 0.005318803712725639f, 0.007047480903565884f, 0.010207310318946838f, 0.014192594215273857f, 0.015994396060705185f, 0.005837148986756802f, 0.008085987530648708f, 0.00613803556188941f, 0.010783890262246132f, 0.004767183214426041f, 0.005520414095371962f, 0.006376814562827349f, 0.007843748666346073f, 0.005217864643782377f, 0.008665448985993862f, 0.006350210402160883f, 0.008294261991977692f, 0.00863243080675602f, 0.009201456792652607f, 0.007625884842127562f, 0.010756516829133034f, 0.004347431939095259f, 0.008303745649755001f, 0.007440491113811731f, 0.006404374726116657f, 0.008132520131766796f, 0.014631147496402264f, 0.006988845765590668f, 0.00882430374622345f, 0.008559308014810085f, 0.01376523170620203f, 0.013944375328719616f, 0.011656885966658592f, 0.005354308523237705f, 0.008865932933986187f, 0.01136890146881342f, 0.0059942519292235374f, 0.007722142618149519f, 0.006394270807504654f, 0.011721518822014332f, 0.016373611986637115f, 0.00813734158873558f, 0.0061878361739218235f, 0.008634108118712902f, 0.005056394729763269f, 0.011790771968662739f, 0.006837853696197271f, 0.007351569831371307f, 0.007520187180489302f, 0.015862414613366127f, 0.017377717420458794f, 0.006407060194760561f, 0.011444423347711563f, 0.006506173871457577f, 0.011955606751143932f, 0.008747460320591927f, 0.011040725745260715f, 0.009716748259961605f, 0.016726115718483925f, 0.010058436542749405f, 0.005120800342410803f, 0.015622692182660103f, 0.011811010539531708f, 0.005954698659479618f, 0.007673746906220913f, 0.004854566417634487f, 0.012998636811971664f, 0.010584904812276363f, 0.010897008702158928f, 0.010674085468053818f, 0.010005110874772072f, 0.007054731249809265f, 0.019562480971217155f, 0.005535294767469168f, 0.007175485137850046f, 0.008588100783526897f, 0.010474419221282005f, 0.009727654978632927f, 0.005440842360258102f, 0.015791332349181175f, 0.017481358721852303f, 0.012929262593388557f, 0.014945942908525467f, 0.011556506156921387f, 0.01028277538716793f, 0.009846278466284275f, 0.008662506937980652f, 0.006164995487779379f, 0.006871672812849283f, 0.013676721602678299f, 0.008428001776337624f, 0.019524740055203438f, 0.007123476825654507f, 0.017258349806070328f, 0.009181453846395016f, 0.013739614747464657f, 0.0041843983344733715f, 0.008384465239942074f, 0.007812272757291794f, 0.007539677433669567f, 0.016674162819981575f, 0.00843039620667696f, 0.009270437061786652f, 0.017307940870523453f, 0.008728749118745327f, 0.005637234542518854f, 0.00478815333917737f, 0.007357501890510321f, 0.0062551419250667095f, 0.013309402391314507f, 0.009462402202188969f, 0.010169081389904022f, 0.012096963822841644f, 0.009053790010511875f, 0.006141615100204945f, 0.009496646001935005f, 0.0028723611030727625f, 0.011781097389757633f, 0.009595115669071674f, 0.008297150954604149f, 0.007473873905837536f, 0.014295435510575771f, 0.013212279416620731f, 0.010121148079633713f, 0.008672034367918968f, 0.00879677850753069f, 0.010799558833241463f, 0.022060180082917213f, 0.012675898149609566f, 0.01202697679400444f, 0.00878113228827715f, 0.008838576264679432f, 0.014999862760305405f, 0.008498470298945904f, 0.00759110227227211f, 0.007040840107947588f, 0.013003932312130928f, 0.010037008672952652f, 0.007895794697105885f, 0.010061785578727722f, 0.003595146117731929f, 0.011927870102226734f, 0.0206183809787035f, 0.01238342933356762f, 0.012651671655476093f, 0.007892552763223648f, 0.005980304442346096f, 0.00813264213502407f, 0.007742509711533785f, 0.009621279314160347f, 0.007424520328640938f, 0.011793557554483414f, 0.011331908404827118f, 0.011385070160031319f, 0.009234190918505192f, 0.012162385508418083f, 0.005606908351182938f, 0.008718620985746384f, 0.013286822475492954f, 0.017400983721017838f, 0.00711111631244421f, 0.010217138566076756f, 0.013648082502186298f, 0.006406962871551514f, 0.008636286482214928f, 0.00400041276589036f, 0.0067059556022286415f, 0.008073103614151478f, 0.008251594379544258f, 0.009991412982344627f, 0.011357280425727367f, 0.008479044772684574f, 0.006217238958925009f, 0.00956451054662466f, 0.005257030483335257f, 0.006367100868374109f, 0.01086318027228117f, 0.007428828626871109f, 0.010949578136205673f, 0.013507295399904251f, 0.00781856756657362f, 0.010995570570230484f, 0.006803424563258886f, 0.010176553390920162f, 0.005636985879391432f, 0.010602446272969246f, 0.005928891245275736f, 0.00875517912209034f, 0.005783796776086092f, 0.0067333257757127285f, 0.00962358433753252f, 0.008995835669338703f, 0.0055068060755729675f, 0.006858790758997202f, 0.014648240059614182f, 0.01929606683552265f, 0.005812495481222868f, 0.011220565997064114f, 0.005234000273048878f, 0.00818628165870905f, 0.006723854690790176f, 0.013820675201714039f, 0.01046057604253292f, 0.01244048960506916f, 0.01564847305417061f, 0.01828336901962757f, 0.003851736895740032f, 0.012361657805740833f, 0.004705378785729408f, 0.005717024672776461f, 0.010334783233702183f, 0.007631965447217226f, 0.016627170145511627f, 0.0069377971813082695f, 0.00811809953302145f, 0.00972655788064003f, 0.005979248322546482f, 0.011160027235746384f, 0.01727955788373947f, 0.006998674012720585f, 0.01439905259758234f, 0.008915319107472897f, 0.00872676819562912f, 0.01189530547708273f, 0.00683577312156558f, 0.010836401022970676f, 0.007192870136350393f, 0.008061002939939499f, 0.004508000332862139f, 0.008240741677582264f, 0.010806120000779629f, 0.007699450943619013f, 0.013437691144645214f, 0.006832011975347996f, 0.018139895051717758f, 0.007523738779127598f, 0.00771370017901063f, 0.014310229569673538f, 0.011833431199193f, 0.013496090658009052f, 0.013409991748631f, 0.00994028802961111f, 0.01041701715439558f, 0.0253461766988039f, 0.011858104728162289f, 0.023949526250362396f, 0.009850802831351757f, 0.010454460047185421f, 0.018581660464406013f, 0.013191252015531063f, 0.014000190421938896f, 0.008213303051888943f, 0.011352727189660072f, 0.01100427657365799f, 0.005985219031572342f, 0.008895917795598507f, 0.006235229317098856f, 0.005331723019480705f, 0.008897832594811916f, 0.013419258408248425f, 0.02058519423007965f, 0.017329318448901176f, 0.009033705107867718f, 0.010866876691579819f, 0.009999126195907593f, 0.009990566410124302f, 0.007457790430635214f, 0.009784704074263573f, 0.022751154378056526f, 0.008920440450310707f, 0.013749904930591583f, 0.007760506588965654f, 0.006750285625457764f, 0.013586725108325481f, 0.006673122756183147f, 0.0073583852499723434f, 0.006041777320206165f, 0.023157967254519463f, 0.008278697729110718f, 0.022488243877887726f, 0.0075336419977247715f, 0.01070291269570589f, 0.015301629900932312f, 0.013618912547826767f, 0.005928701721131802f, 0.006953491363674402f, 0.007258449215441942f, 0.009561805054545403f, 0.00458233617246151f, 0.008062821812927723f, 0.007621719967573881f, 0.012214642018079758f, 0.007487452123314142f, 0.012831143103539944f, 0.016594821587204933f, 0.007175130769610405f, 0.012368698604404926f, 0.009167366661131382f, 0.011847958900034428f, 0.018191862851381302f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #168 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012477488722652197f),
    AI_PACK_UINTQ_ZP(118)))

/* Int quant #169 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001517732278443873f, 0.0014819457428529859f, 0.0016084595117717981f, 0.0016291161300614476f, 0.0016838070005178452f, 0.0016340783331543207f, 0.0012977978913113475f, 0.001377307460643351f, 0.0019777589477598667f, 0.0014693890698254108f, 0.0018448769114911556f, 0.0016341285081580281f, 0.001646577613428235f, 0.0012490443186834455f, 0.0015647074906155467f, 0.001421856926754117f, 0.0013011816190555692f, 0.0016410343814641237f, 0.001460614032112062f, 0.0015464703319594264f, 0.0016076266765594482f, 0.001512838527560234f, 0.0014154489617794752f, 0.001325439428910613f, 0.0017433136235922575f, 0.0014977635582908988f, 0.0014312898274511099f, 0.0016056777676567435f, 0.0016955005703493953f, 0.0013567872811108828f, 0.001366203068755567f, 0.0014224896440282464f, 0.001599928829818964f, 0.0017555152298882604f, 0.0017020482337102294f, 0.0013809246011078358f, 0.0016674393555149436f, 0.0018103825859725475f, 0.0015432614600285888f, 0.0015480845468118787f, 0.001487157540395856f, 0.0014964548172429204f, 0.001561730750836432f, 0.0012979692546650767f, 0.0017423586687073112f, 0.0015458528650924563f, 0.0012443562736734748f, 0.0015897535486146808f, 0.0014462528051808476f, 0.0013676834059879184f, 0.0015536847058683634f, 0.0013448528479784727f, 0.002108860295265913f, 0.0014676253776997328f, 0.0016125516267493367f, 0.001454425510019064f, 0.0014339627232402563f, 0.001460983301512897f, 0.0015249863499775529f, 0.001412589568644762f, 0.0016859358875080943f, 0.0017352354479953647f, 0.0015672898152843118f, 0.0015643208753317595f, 0.0014674874255433679f, 0.001268757856450975f, 0.001723996945656836f, 0.0012515047565102577f, 0.001369091565720737f, 0.0020400919020175934f, 0.0016156903002411127f, 0.0015805130824446678f, 0.0014320621266961098f, 0.001536382595077157f, 0.0013478765031322837f, 0.0024284247774630785f, 0.0013534300960600376f, 0.001489885849878192f, 0.0017720890464261174f, 0.0017498896922916174f, 0.0014828804414719343f, 0.0013416532892733812f, 0.0013656076043844223f, 0.0011915999930351973f, 0.0013933811569586396f, 0.0016351033700630069f, 0.0017901257378980517f, 0.0015465860487893224f, 0.00166138110216707f, 0.0014596461551263928f, 0.0012049127835780382f, 0.0012368544703349471f, 0.001472645322792232f, 0.0013292215298861265f, 0.001711186720058322f, 0.002002447610720992f, 0.001284840633161366f, 0.0018165145302191377f, 0.001608162885531783f, 0.0012076606508344412f, 0.0014236338902264833f, 0.0014187936903908849f, 0.0017256018472835422f, 0.0017446971032768488f, 0.0016929787816479802f, 0.0017157683614641428f, 0.0018298771465197206f, 0.0018043341115117073f, 0.0017102793790400028f, 0.0015322852414101362f, 0.0018475684337317944f, 0.0019102704245597124f, 0.0015000319108366966f, 0.0015990217216312885f, 0.0015806255396455526f, 0.001505003310739994f, 0.0016300459392368793f, 0.0018313491018489003f, 0.0012161345221102238f, 0.0013077500043436885f, 0.0019428441300988197f, 0.0013013415737077594f, 0.0014140965649858117f, 0.0015930139925330877f, 0.0014311608392745256f, 0.0015906045446172357f, 0.0017376623582094908f, 0.0014604947064071894f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #170 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005913240020163357f, 0.0006078665610402822f, 0.000565494759939611f, 0.0007001040503382683f, 0.0011245209025219083f, 0.0009195648017339408f, 0.0007356458809226751f, 0.0006645807879976928f, 0.0009517602156847715f, 0.0007907357648946345f, 0.0007554855546914041f, 0.0007840237813070416f, 0.0008731217822059989f, 0.0007531860610470176f, 0.0005982553702779114f, 0.0009050741791725159f, 0.0006946662906557322f, 0.0006901840679347515f, 0.000878566992469132f, 0.0006035062833689153f, 0.0009242297965101898f, 0.0006908829673193395f, 0.0006960641476325691f, 0.0006676232442259789f, 0.0007837766315788031f, 0.0012516173301264644f, 0.0007309329812414944f, 0.0008938383543863893f, 0.000805305375251919f, 0.0007194451172836125f, 0.0006340186228044331f, 0.0009966077050194144f, 0.0010584553238004446f, 0.0008318765321746469f, 0.0007183743291534483f, 0.0005189114599488676f, 0.0007436374435201287f, 0.0008945713634602726f, 0.0012373048812150955f, 0.0010209738975390792f, 0.0010423650965094566f, 0.0008368101553060114f, 0.0007644343422725797f, 0.0008205870981328189f, 0.0006852969527244568f, 0.0008571211365051568f, 0.0008545530727133155f, 0.0006760878604836762f, 0.0007210588082671165f, 0.0009731156751513481f, 0.0008858059882186353f, 0.0010091066360473633f, 0.0004789028607774526f, 0.0006480193114839494f, 0.0007189489551819861f, 0.0005489622708410025f, 0.0010208424646407366f, 0.0006930211093276739f, 0.0008067302987910807f, 0.0008210429223254323f, 0.0008033657795749605f, 0.0010872313287109137f, 0.0006491904496215284f, 0.0008853527251631021f, 0.0009464195463806391f, 0.0008528300677426159f, 0.000778130313847214f, 0.0006294542690739036f, 0.0006164985825307667f, 0.0007132591563276947f, 0.000778925430495292f, 0.0010750106303021312f, 0.001135638915002346f, 0.001385401701554656f, 0.0007558693760074675f, 0.0006054301629774272f, 0.0012926268391311169f, 0.001086741336621344f, 0.0007992892642505467f, 0.0008060572436079383f, 0.0006967507069930434f, 0.0006703414837829769f, 0.0007553864852525294f, 0.0007763320463709533f, 0.0007495052996091545f, 0.0006347497692331672f, 0.0006749994936399162f, 0.0009995658183470368f, 0.0007263642037287354f, 0.000683003047015518f, 0.0007642696727998555f, 0.0007542899111285806f, 0.0006785928271710873f, 0.0006248728604987264f, 0.0006458616117015481f, 0.0008175265393219888f, 0.0008072454365901649f, 0.0007371143437922001f, 0.0011339392513036728f, 0.0008901505498215556f, 0.0008723404607735574f, 0.0005130627541802824f, 0.000999680021777749f, 0.0007844006177037954f, 0.0007488009287044406f, 0.0010096217738464475f, 0.0007953052408993244f, 0.0006268909201025963f, 0.0007090612198226154f, 0.0010955182369798422f, 0.0007996247732080519f, 0.0007932505686767399f, 0.001098720938898623f, 0.0006041969172656536f, 0.0005299585172906518f, 0.0008870928431861103f, 0.0005753423902206123f, 0.0007497264305129647f, 0.0008476470247842371f, 0.0007659175316803157f, 0.0008879431989043951f, 0.0006848159828223288f, 0.0007777076098136604f, 0.0008390024886466563f, 0.0006169276894070208f, 0.0006387287867255509f, 0.0008339868509210646f, 0.0006285061244852841f, 0.0007686731405556202f, 0.0006087825750000775f, 0.000793815532233566f, 0.0005641721072606742f, 0.0007986660348251462f, 0.0007451724377460778f, 0.0008349868003278971f, 0.0010933468583971262f, 0.0007896373863331974f, 0.0008148140041157603f, 0.0008843214600346982f, 0.0008359821513295174f, 0.0006811298662796617f, 0.000638890138361603f, 0.0007614996284246445f, 0.0007301779114641249f, 0.0008144978201016784f, 0.0007538018398918211f, 0.000937050674110651f, 0.0007963882526382804f, 0.0005950072081759572f, 0.0007176583749242127f, 0.000547303119674325f, 0.0008580969297327101f, 0.0006748208543285728f, 0.0007150774472393095f, 0.0007886553066782653f, 0.000584032793994993f, 0.0007693798979744315f, 0.0006289840093813837f, 0.0007042584475129843f, 0.0009516081772744656f, 0.0007057870388962328f, 0.0008586818003095686f, 0.0008183860336430371f, 0.0007984995027072728f, 0.0009141491609625518f, 0.0006461524753831327f, 0.00066177430562675f, 0.0006167941610328853f, 0.0007092675077728927f, 0.0005787511472590268f, 0.0008397946367040277f, 0.0005020479438826442f, 0.0008538854890502989f, 0.0005803382373414934f, 0.0008558693807572126f, 0.001000047312118113f, 0.00079132872633636f, 0.0009075574344024062f, 0.0006523006013594568f, 0.0008636760758236051f, 0.000715944217517972f, 0.0006605929811485112f, 0.0007745464681647718f, 0.0007173616322688758f, 0.0008325151284225285f, 0.0007847824017517269f, 0.0005998839624226093f, 0.0007086031837388873f, 0.0005236555589362979f, 0.0008960600243881345f, 0.0010608682641759515f, 0.0007928619743324816f, 0.0010000411421060562f, 0.0009022364974953234f, 0.0010444957297295332f, 0.0008236638968810439f, 0.0006765300640836358f, 0.0004905200330540538f, 0.0006893304525874555f, 0.0010222409619018435f, 0.0008736298186704516f, 0.0005017385701648891f, 0.0006597083411179483f, 0.0009684360702522099f, 0.0008110030903480947f, 0.0005023820558562875f, 0.0009516712743788958f, 0.000827898969873786f, 0.0009472365491092205f, 0.0008335066959261894f, 0.0009048979845829308f, 0.0006017950945533812f, 0.0007003905484452844f, 0.0005907515878789127f, 0.0006647171685472131f, 0.000509167555719614f, 0.0007148510776460171f, 0.0006393173825927079f, 0.0008205556077882648f, 0.0012588959652930498f, 0.000829556433018297f, 0.0008721843478269875f, 0.0007151705794967711f, 0.0008471178007312119f, 0.0009078133152797818f, 0.0008628420764580369f, 0.0005287076346576214f, 0.0007622202974744141f, 0.0007430230034515262f, 0.000789094134233892f, 0.000852380006108433f, 0.0007525577093474567f, 0.0007368603837676346f, 0.00042360773659311235f, 0.0007397950976155698f, 0.000988717540167272f, 0.0007821699255146086f, 0.0008209293591789901f, 0.0007448072428815067f, 0.0007524224929511547f, 0.0006601884961128235f, 0.0009280039230361581f, 0.0008665743516758084f, 0.0007928729173727334f, 0.0007611992186866701f, 0.000739836657885462f, 0.0008302122005261481f, 0.0008180710719898343f, 0.0007643710705451667f, 0.0005915186484344304f, 0.0009089523227885365f, 0.0006822502473369241f, 0.0007415568106807768f, 0.0008669548551551998f, 0.0010159725788980722f, 0.0008120437269099057f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00761667313054204f),
    AI_PACK_UINTQ_ZP(95)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021012721583247185f, 0.021649450063705444f, 0.011274856515228748f, 0.01793842762708664f, 0.013750188052654266f, 0.009123928844928741f, 0.008363677188754082f, 0.012918058782815933f, 0.009653789922595024f, 0.006456782575696707f, 0.0070272646844387054f, 0.006185914855450392f, 0.015388676896691322f, 0.010474861599504948f, 0.009045815095305443f, 0.00613755127415061f, 0.010245343670248985f, 0.008712577633559704f, 0.007254830561578274f, 0.01657046005129814f, 0.014403851702809334f, 0.00777467293664813f, 0.013818285427987576f, 0.015195325948297977f, 0.013721299357712269f, 0.010596934705972672f, 0.009471315890550613f, 0.012784824706614017f, 0.008919925428926945f, 0.016974736005067825f, 0.007151484023779631f, 0.009380913339555264f, 0.007789228111505508f, 0.013706726022064686f, 0.007662177085876465f, 0.011243081651628017f, 0.006235129199922085f, 0.011317811906337738f, 0.01531933806836605f, 0.011253014206886292f, 0.006894831545650959f, 0.008790114894509315f, 0.012133118696510792f, 0.01287887617945671f, 0.012129784561693668f, 0.010671917349100113f, 0.010714031755924225f, 0.012410853058099747f, 0.010392825119197369f, 0.01177942007780075f, 0.008472797460854053f, 0.0073481458239257336f, 0.020675141364336014f, 0.019579123705625534f, 0.01926582120358944f, 0.017147256061434746f, 0.0070595210418105125f, 0.014597874134778976f, 0.007346965838223696f, 0.008572380058467388f, 0.008431527763605118f, 0.00840973574668169f, 0.013712534680962563f, 0.0100700743496418f, 0.009466789662837982f, 0.008953113108873367f, 0.015669003129005432f, 0.008866007439792156f, 0.009510066360235214f, 0.013736460357904434f, 0.013483799993991852f, 0.008052068762481213f, 0.004527947399765253f, 0.004509012680500746f, 0.01144638005644083f, 0.014917091466486454f, 0.0075888726860284805f, 0.008526287972927094f, 0.012840691022574902f, 0.010231642983853817f, 0.009333130903542042f, 0.015399893745779991f, 0.008524065837264061f, 0.016691269353032112f, 0.016864778473973274f, 0.016683369874954224f, 0.009391511790454388f, 0.007570558227598667f, 0.02038540504872799f, 0.009598853066563606f, 0.025374792516231537f, 0.008952992968261242f, 0.010282532311975956f, 0.012031113728880882f, 0.009442240931093693f, 0.006582490634173155f, 0.0064400979317724705f, 0.007179423701018095f, 0.01612015999853611f, 0.008127493783831596f, 0.007563685066998005f, 0.023811860010027885f, 0.01871708407998085f, 0.01033127959817648f, 0.011235990561544895f, 0.006217770278453827f, 0.014637122862040997f, 0.0056774732656776905f, 0.009381299838423729f, 0.012723744846880436f, 0.006558020133525133f, 0.010260903276503086f, 0.011929185129702091f, 0.014079858548939228f, 0.008676636964082718f, 0.01410741824656725f, 0.0112905977293849f, 0.007339518517255783f, 0.013283721171319485f, 0.009666070342063904f, 0.007668514735996723f, 0.00881891418248415f, 0.013700269162654877f, 0.012267312966287136f, 0.012732386589050293f, 0.013255625031888485f, 0.02018534392118454f, 0.009978595189750195f, 0.015033519826829433f, 0.01563430391252041f, 0.013189241290092468f, 0.018307242542505264f, 0.009102331474423409f, 0.011010349728167057f, 0.011121702380478382f, 0.008530565537512302f, 0.020937584340572357f, 0.01429794728755951f, 0.00984999630600214f, 0.009761260822415352f, 0.010615017265081406f, 0.01946091093122959f, 0.009900512173771858f, 0.014135375618934631f, 0.010053725913167f, 0.010955411940813065f, 0.007261139340698719f, 0.006933235097676516f, 0.015262652188539505f, 0.013415910303592682f, 0.006499785464257002f, 0.011259072460234165f, 0.014056835323572159f, 0.01703951321542263f, 0.005717333406209946f, 0.0060447813011705875f, 0.006439543794840574f, 0.02270861715078354f, 0.009389828890562057f, 0.014378807507455349f, 0.012801021337509155f, 0.019367901608347893f, 0.011653023771941662f, 0.007019036449491978f, 0.006275217980146408f, 0.013218443840742111f, 0.01827431470155716f, 0.005833701230585575f, 0.007078756112605333f, 0.016639836132526398f, 0.011979139409959316f, 0.015479356981813908f, 0.01088065654039383f, 0.010205939412117004f, 0.009391779080033302f, 0.006304538808763027f, 0.0090790418908f, 0.010990842245519161f, 0.018715914338827133f, 0.00730237876996398f, 0.012364932335913181f, 0.02207782305777073f, 0.008894368074834347f, 0.009484920650720596f, 0.008837597444653511f, 0.012127207592129707f, 0.025248035788536072f, 0.01561006996780634f, 0.009870502166450024f, 0.0100244777277112f, 0.014482627622783184f, 0.012218335643410683f, 0.01661164127290249f, 0.010357595980167389f, 0.008865181356668472f, 0.007641488686203957f, 0.018737763166427612f, 0.01531784888356924f, 0.011320051737129688f, 0.007486515678465366f, 0.009220979176461697f, 0.02853820100426674f, 0.02151009999215603f, 0.0066035836935043335f, 0.01250139158219099f, 0.02140616811811924f, 0.01547148171812296f, 0.014758018776774406f, 0.00578764034435153f, 0.014061778783798218f, 0.006772386841475964f, 0.012998657301068306f, 0.009148480370640755f, 0.012291619554162025f, 0.009906825609505177f, 0.014371446333825588f, 0.016883445903658867f, 0.014042765833437443f, 0.008435179479420185f, 0.008875340223312378f, 0.011679618619382381f, 0.007338651455938816f, 0.009568929672241211f, 0.01013874914497137f, 0.01192987896502018f, 0.00698228320106864f, 0.01626426912844181f, 0.012575527653098106f, 0.008224237710237503f, 0.013262197375297546f, 0.004070553928613663f, 0.015398170799016953f, 0.014280238188803196f, 0.014758974313735962f, 0.020830057561397552f, 0.00946572795510292f, 0.013173636980354786f, 0.008307146839797497f, 0.011237784288823605f, 0.010177794843912125f, 0.009215034544467926f, 0.014124010689556599f, 0.009735689498484135f, 0.007257451768964529f, 0.009954001754522324f, 0.009626202285289764f, 0.016595015302300453f, 0.009806957095861435f, 0.0066147795878350735f, 0.010094399563968182f, 0.007784019690006971f, 0.011213895864784718f, 0.007079115137457848f, 0.008796878159046173f, 0.00579294515773654f, 0.014422106556594372f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008316493593156338f),
    AI_PACK_UINTQ_ZP(124)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0025813644751906395f, 0.0026041341479867697f, 0.0025724167935550213f, 0.002352222567424178f, 0.002354111522436142f, 0.001778248930349946f, 0.0020555045921355486f, 0.0030071495566517115f, 0.002533507766202092f, 0.003250040113925934f, 0.001775658456608653f, 0.002432268112897873f, 0.0015013955999165773f, 0.002446947619318962f, 0.0020357312168926f, 0.002479827729985118f, 0.002435101894661784f, 0.002596144564449787f, 0.002416075672954321f, 0.0023142967838793993f, 0.00232519768178463f, 0.0029605457093566656f, 0.0017618988640606403f, 0.002119201235473156f, 0.0022759446874260902f, 0.0024959752336144447f, 0.002324814209714532f, 0.0023153426591306925f, 0.00224843411706388f, 0.002241609850898385f, 0.0020456525962799788f, 0.002625376218929887f, 0.002430511871352792f, 0.0021480158902704716f, 0.002223371062427759f, 0.0021623624488711357f, 0.001889871316961944f, 0.002175489440560341f, 0.002003368455916643f, 0.0019491453422233462f, 0.002331299241632223f, 0.0026575163938105106f, 0.002716902643442154f, 0.002267624484375119f, 0.002432485343888402f, 0.0019104793900623918f, 0.0023954904172569513f, 0.0020037766080349684f, 0.0021811265032738447f, 0.0025734533555805683f, 0.0024570520035922527f, 0.002113787457346916f, 0.0027503250166773796f, 0.0022301531862467527f, 0.002418787684291601f, 0.002508987206965685f, 0.0020601870492100716f, 0.002313398290425539f, 0.002645852044224739f, 0.002300914842635393f, 0.0024293598253279924f, 0.0018357180524617434f, 0.00268986402079463f, 0.0022572604939341545f, 0.0027014396619051695f, 0.0022532190196216106f, 0.0018462876323610544f, 0.0025679192040115595f, 0.0027795261703431606f, 0.001896178931929171f, 0.0018117218278348446f, 0.0022352684754878283f, 0.002369281370192766f, 0.0020100201945751905f, 0.0019512104336172342f, 0.001986698480322957f, 0.0017782809445634484f, 0.002278474625200033f, 0.0023130225017666817f, 0.0023926920257508755f, 0.0023345947265625f, 0.002301720902323723f, 0.002023854525759816f, 0.004414916038513184f, 0.002610571915283799f, 0.0023073856718838215f, 0.002400290919467807f, 0.0025998365599662066f, 0.002754274057224393f, 0.0015031942166388035f, 0.0023399197962135077f, 0.0028359026182442904f, 0.002949655055999756f, 0.002373668598011136f, 0.0027500002179294825f, 0.0017715016147121787f, 0.0022661807015538216f, 0.002568555762991309f, 0.002259105909615755f, 0.0027536144480109215f, 0.001933864550665021f, 0.0022224162239581347f, 0.0019635658245533705f, 0.002398323966190219f, 0.0019260916160419583f, 0.0018152134725823998f, 0.001867488375864923f, 0.001694545499049127f, 0.002284218091517687f, 0.003730809548869729f, 0.0020392078440636396f, 0.002030471106991172f, 0.0022060007322579622f, 0.001884155673906207f, 0.00225500063970685f, 0.002437408547848463f, 0.0026760182809084654f, 0.0023569567129015923f, 0.0027096800040453672f, 0.0020177180413156748f, 0.00213606096804142f, 0.0021402963902801275f, 0.002265811199322343f, 0.001961521804332733f, 0.0025104356463998556f, 0.002426277380436659f, 0.0024459129199385643f, 0.002102322643622756f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #175 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005759101477451622f, 0.001001635449938476f, 0.0007646966259926558f, 0.0008364389650523663f, 0.0006063469918444753f, 0.0005213365657255054f, 0.0009336060611531138f, 0.0004853066348005086f, 0.0006036831182427704f, 0.0006212258012965322f, 0.0007426096126437187f, 0.0005797861376777291f, 0.0006958071608096361f, 0.0005873903864994645f, 0.0005845904815942049f, 0.0006013034144416451f, 0.0008045936119742692f, 0.000692054396495223f, 0.0007054537418298423f, 0.0006106081418693066f, 0.0005489465547725558f, 0.0006819512345828116f, 0.0008348457049578428f, 0.0006063677719794214f, 0.0008020696695894003f, 0.0005191659438423812f, 0.0005712699494324625f, 0.0007518432103097439f, 0.0006610846030525863f, 0.0006100923055782914f, 0.0008756265160627663f, 0.0008010505698621273f, 0.0005839893128722906f, 0.0007302853045985103f, 0.000498600653372705f, 0.000553894555196166f, 0.0005493849748745561f, 0.0010425394866615534f, 0.0005609329091385007f, 0.0005573561647906899f, 0.0010066221002489328f, 0.0005731903365813196f, 0.0008472585468553007f, 0.0008681537001393735f, 0.0006504311459138989f, 0.0005840608500875533f, 0.0006737723015248775f, 0.0006277572247199714f, 0.0008316826424561441f, 0.0006807420868426561f, 0.0008138151606544852f, 0.0007879140903241932f, 0.000719915668014437f, 0.0006804599543102086f, 0.0008197709685191512f, 0.0006923028267920017f, 0.0006622793735004961f, 0.0005022874684073031f, 0.0005399908986873925f, 0.0010333963437005877f, 0.0008309948025271297f, 0.00056393415434286f, 0.00046753627248108387f, 0.0005612512468360364f, 0.0006344581488519907f, 0.0005757788894698024f, 0.0007307622581720352f, 0.0005199967999942601f, 0.0006215309840627015f, 0.0007548663998022676f, 0.0007594813941977918f, 0.00058470678050071f, 0.0010382791515439749f, 0.0005406209966167808f, 0.0009405739256180823f, 0.0005285131046548486f, 0.0006234945612959564f, 0.000995374284684658f, 0.000687741267029196f, 0.0005338603514246643f, 0.0006452484522014856f, 0.0006757493829354644f, 0.0005013784975744784f, 0.0006823310977779329f, 0.0004978825454600155f, 0.0005411384627223015f, 0.0004919967614114285f, 0.000602578220423311f, 0.000665735627990216f, 0.0007839439786039293f, 0.0006799020920880139f, 0.0005558257689699531f, 0.0005835742340423167f, 0.0006616195314563811f, 0.0006079644663259387f, 0.0005430558230727911f, 0.0005233868141658604f, 0.0005678286543115973f, 0.0006013380479998887f, 0.0005258318269625306f, 0.0008386111003346741f, 0.0006012563826516271f, 0.000561310036573559f, 0.0007909305859357119f, 0.0007827705121599138f, 0.0007627457962371409f, 0.0006447957130149007f, 0.0006330210599116981f, 0.0005790747236460447f, 0.0006437027477659285f, 0.0005648315418511629f, 0.0007960951770655811f, 0.0005201200838200748f, 0.0005094115040265024f, 0.0007621446857228875f, 0.0011053364723920822f, 0.0006888748030178249f, 0.0004875646554864943f, 0.0007533479947596788f, 0.0005939743132330477f, 0.0005719870096072555f, 0.0007850116235204041f, 0.0005574557580985129f, 0.0006750299362465739f, 0.0009277861099690199f, 0.0006388797191902995f, 0.0007002722704783082f, 0.0006183481309562922f, 0.0005004497361369431f, 0.0007300914730876684f, 0.0005960454000160098f, 0.0006084959022700787f, 0.00048386180424131453f, 0.0006315702921710908f, 0.0006075605633668602f, 0.0008834023028612137f, 0.0005483755376189947f, 0.0007191052427515388f, 0.0006506486679427326f, 0.000580265827011317f, 0.0007397703011520207f, 0.0006728732259944081f, 0.000664014252834022f, 0.0006161201163195074f, 0.0006515533314086497f, 0.000980886397883296f, 0.0006300495588220656f, 0.0006045909831300378f, 0.0005819728248752654f, 0.0006511365063488483f, 0.0005679744062945247f, 0.0007192866178229451f, 0.0006137270829640329f, 0.000983124366030097f, 0.0007601288380101323f, 0.0008512625354342163f, 0.0006170731503516436f, 0.0006462830351665616f, 0.0004513665335252881f, 0.000534463266376406f, 0.0007733397069387138f, 0.00045440078247338533f, 0.000747455982491374f, 0.0006658101920038462f, 0.0005761238862760365f, 0.0009136591688729823f, 0.0006921034655533731f, 0.000832845049444586f, 0.0009562234627082944f, 0.0009027295163832605f, 0.0006549598765559494f, 0.0006845915922895074f, 0.0007566784042865038f, 0.0005325221573002636f, 0.0006503842887468636f, 0.0006723544793203473f, 0.0010589554440230131f, 0.0005668838857673109f, 0.0005220460589043796f, 0.0006293566548265517f, 0.0007071865838952363f, 0.0006205120589584112f, 0.00042630048119463027f, 0.0008343927329406142f, 0.0005312975263223052f, 0.0006258350913412869f, 0.0008168763597495854f, 0.0005675266729667783f, 0.0006847050390206277f, 0.0007589036831632257f, 0.0006109937676228583f, 0.000763123098295182f, 0.0007900224300101399f, 0.0008385200053453445f, 0.0006276788772083819f, 0.0006014328682795167f, 0.0005599343567155302f, 0.0005043658311478794f, 0.0005085502634756267f, 0.000592083961237222f, 0.0006660254439339042f, 0.0008310190751217306f, 0.0006225278484635055f, 0.0007359927403740585f, 0.000624202482867986f, 0.0007396264700219035f, 0.0005768279079347849f, 0.000463916570879519f, 0.0006359952385537326f, 0.0005316137103363872f, 0.0005433937767520547f, 0.0006424774765037f, 0.00046588541590608656f, 0.00047888720291666687f, 0.0008305173250846565f, 0.0006289120065048337f, 0.0007731422665528953f, 0.0009104495984502137f, 0.0005885694990865886f, 0.000644767947960645f, 0.0006458773859776556f, 0.0005863812402822077f, 0.0006429274217225611f, 0.0007319670403376222f, 0.000753966742195189f, 0.0009363972349092364f, 0.0007920804200693965f, 0.0005847213906235993f, 0.0006288204458542168f, 0.0005683326744474471f, 0.0008860852685756981f, 0.0005941857234574854f, 0.0006965494249016047f, 0.0007604004349559546f, 0.00070779281668365f, 0.0004899183986708522f, 0.0005933163920417428f, 0.0007615709328092635f, 0.0006617268663831055f, 0.0006839653360657394f, 0.0006854002713225782f, 0.0005928172031417489f, 0.0006988962413743138f, 0.0007458187174052f, 0.0008359646890312433f, 0.0007574313203804195f, 0.0008776120957918465f, 0.0009945033816620708f, 0.000995430164039135f, 0.0008244391647167504f, 0.0005447726580314338f, 0.0008558877161704004f, 0.0005226964130997658f, 0.0006431774236261845f, 0.0006389059708453715f, 0.000576191523578018f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #176 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010213069152086973f),
    AI_PACK_UINTQ_ZP(116)))

/* Int quant #177 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0354011245071888f, 0.012114360928535461f, 0.00861532986164093f, 0.010556723922491074f, 0.009276585653424263f, 0.01563437283039093f, 0.01177556999027729f, 0.028250202536582947f, 0.011574342846870422f, 0.007097636349499226f, 0.005916918627917767f, 0.007142290938645601f, 0.014793257229030132f, 0.00738721014931798f, 0.01320226863026619f, 0.016484476625919342f, 0.017441170290112495f, 0.0060735223814845085f, 0.020984428003430367f, 0.012567606754601002f, 0.0091257244348526f, 0.007031296845525503f, 0.012616750784218311f, 0.010502886958420277f, 0.020862553268671036f, 0.012911515310406685f, 0.025515669956803322f, 0.01153636071830988f, 0.005987042561173439f, 0.009271583519876003f, 0.009916655719280243f, 0.007922840304672718f, 0.01271802093833685f, 0.01990334875881672f, 0.012813285924494267f, 0.018870409578084946f, 0.007651580031961203f, 0.008051898330450058f, 0.009356613270938396f, 0.00944389495998621f, 0.007892938330769539f, 0.02587287873029709f, 0.004618323408067226f, 0.009572163224220276f, 0.00926025677472353f, 0.00719679519534111f, 0.00914833229035139f, 0.007760900538414717f, 0.011223999783396721f, 0.0077076503075659275f, 0.0062592546455562115f, 0.011023245751857758f, 0.016676800325512886f, 0.01022867951542139f, 0.010748608969151974f, 0.015471340157091618f, 0.008546652272343636f, 0.011800405569374561f, 0.01000647246837616f, 0.0068984185345470905f, 0.012192459776997566f, 0.010334236547350883f, 0.011332291178405285f, 0.003717980580404401f, 0.015415403060615063f, 0.014614386484026909f, 0.010654374957084656f, 0.01930404268205166f, 0.010168459266424179f, 0.005843955557793379f, 0.008309029042720795f, 0.009670618921518326f, 0.010078915394842625f, 0.01185699738562107f, 0.012162365950644016f, 0.018769051879644394f, 0.011200372129678726f, 0.007500386796891689f, 0.00628347834572196f, 0.009797634556889534f, 0.0065590753220021725f, 0.010073606856167316f, 0.008909398689866066f, 0.009674387983977795f, 0.019067324697971344f, 0.010354351252317429f, 0.016397392377257347f, 0.00869603082537651f, 0.009296867065131664f, 0.00895290169864893f, 0.015124054625630379f, 0.012719512917101383f, 0.007661367766559124f, 0.013558982871472836f, 0.012179031036794186f, 0.006454493850469589f, 0.010748657397925854f, 0.022279497236013412f, 0.021923495456576347f, 0.013765043579041958f, 0.0063911606557667255f, 0.016755660995841026f, 0.012156213633716106f, 0.01215494517236948f, 0.005941594950854778f, 0.008379175327718258f, 0.0254187174141407f, 0.007093056105077267f, 0.0075835734605789185f, 0.01125872042030096f, 0.009679701179265976f, 0.008272625505924225f, 0.011618807911872864f, 0.010936157777905464f, 0.009903838858008385f, 0.012305408716201782f, 0.0108049176633358f, 0.017998605966567993f, 0.011150682345032692f, 0.012097254395484924f, 0.00536205992102623f, 0.010917224921286106f, 0.008132481016218662f, 0.01416673045605421f, 0.00973524246364832f, 0.010778436437249184f, 0.014137902297079563f, 0.014669975265860558f, 0.011394823901355267f, 0.008124832063913345f, 0.017401745542883873f, 0.016731977462768555f, 0.01646926812827587f, 0.00904318317770958f, 0.009134179912507534f, 0.0057398658245801926f, 0.011208167299628258f, 0.01054316945374012f, 0.015893569216132164f, 0.015490281395614147f, 0.008699851110577583f, 0.014266692101955414f, 0.008746077306568623f, 0.011174049228429794f, 0.012235847301781178f, 0.006403750739991665f, 0.01586752198636532f, 0.009754386730492115f, 0.01439686119556427f, 0.007917164824903011f, 0.010914892889559269f, 0.009349550120532513f, 0.010425901040434837f, 0.008465658873319626f, 0.016037775203585625f, 0.006805491168051958f, 0.007926877588033676f, 0.010555990971624851f, 0.011634211987257004f, 0.01971280388534069f, 0.011082587763667107f, 0.011792835779488087f, 0.013017564080655575f, 0.013126078993082047f, 0.010752893052995205f, 0.013237428851425648f, 0.013821152038872242f, 0.014796825125813484f, 0.01281747780740261f, 0.004503997042775154f, 0.011772898957133293f, 0.006337147671729326f, 0.009564819745719433f, 0.011273018084466457f, 0.01632400043308735f, 0.006918713450431824f, 0.007320856209844351f, 0.013799918815493584f, 0.03669517859816551f, 0.02362756058573723f, 0.01686592772603035f, 0.010783087462186813f, 0.010181840509176254f, 0.018759755417704582f, 0.012361297383904457f, 0.009554047137498856f, 0.005993417464196682f, 0.01073639839887619f, 0.009529545903205872f, 0.011838915757834911f, 0.007247963920235634f, 0.009968377649784088f, 0.009985308162868023f, 0.008524999022483826f, 0.010256023146212101f, 0.0162510983645916f, 0.012121030129492283f, 0.016788659617304802f, 0.019178016111254692f, 0.007306618150323629f, 0.009717060253024101f, 0.007973690517246723f, 0.02237137220799923f, 0.010719121433794498f, 0.015180407091975212f, 0.014368878677487373f, 0.011985162273049355f, 0.015298631973564625f, 0.0171941090375185f, 0.011665413156151772f, 0.008748508989810944f, 0.013350625522434711f, 0.011168417520821095f, 0.016648294404149055f, 0.010239261202514172f, 0.008717384189367294f, 0.009224480018019676f, 0.014301982708275318f, 0.0101547222584486f, 0.004738185554742813f, 0.007938428781926632f, 0.023593278601765633f, 0.008312215097248554f, 0.004784388933330774f, 0.005340115167200565f, 0.00817844644188881f, 0.01712561398744583f, 0.008300431072711945f, 0.007633094675838947f, 0.011439003981649876f, 0.010014791041612625f, 0.004836957901716232f, 0.013552229851484299f, 0.01190475095063448f, 0.013942000456154346f, 0.013030479662120342f, 0.013184875249862671f, 0.0062935808673501015f, 0.01260926853865385f, 0.010730158537626266f, 0.00822988711297512f, 0.009084123186767101f, 0.011019178666174412f, 0.0037502050399780273f, 0.009074820205569267f, 0.01593911461532116f, 0.008026862516999245f, 0.0066526965238153934f, 0.009501355700194836f, 0.01317489892244339f, 0.011696421541273594f, 0.015288583002984524f, 0.007920577190816402f, 0.01578456163406372f, 0.0070402175188064575f, 0.007718833163380623f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #178 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007539351703599095f),
    AI_PACK_UINTQ_ZP(139)))

/* Int quant #179 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(_blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0031745173037052155f, 0.002701330231502652f, 0.0038723424077033997f, 0.0023761240299791098f, 0.0033252956345677376f, 0.0035587267484515905f, 0.002931809751316905f, 0.003015505848452449f, 0.0028504272922873497f, 0.0024328993167728186f, 0.005920664872974157f, 0.0028246664442121983f, 0.0037757065147161484f, 0.0026163330767303705f, 0.0024430849589407444f, 0.0035364131908863783f, 0.0043091983534395695f, 0.004396628122776747f, 0.002922993153333664f, 0.0033229226246476173f, 0.004071720875799656f, 0.002452288754284382f, 0.0026196453254669905f, 0.004994608927518129f, 0.0024408092722296715f, 0.002591308206319809f, 0.003549435641616583f, 0.004739579278975725f, 0.003802710911259055f, 0.0043778312392532825f, 0.0028275770600885153f, 0.003310828236863017f, 0.003910654690116644f, 0.0022210320457816124f, 0.003173916833475232f, 0.003201679792255163f, 0.002623121254146099f, 0.0027827699668705463f, 0.003604027908295393f, 0.0035159343387931585f, 0.0034475193824619055f, 0.0033378584776073694f, 0.0027707661502063274f, 0.0036202867049723864f, 0.0029349150136113167f, 0.0028598709031939507f, 0.002376825548708439f, 0.002297336235642433f, 0.0035554117057472467f, 0.0034113391302525997f, 0.0055330898612737656f, 0.003201935673132539f, 0.003607539227232337f, 0.0031885183416306973f, 0.0023678047582507133f, 0.003605989506468177f, 0.003668355057016015f, 0.0026582262944430113f, 0.0028107711113989353f, 0.003107497002929449f, 0.0027504253666847944f, 0.004236552864313126f, 0.0027751047164201736f, 0.002845634473487735f, 0.0035581248812377453f, 0.0026774450670927763f, 0.003216665703803301f, 0.0032062307000160217f, 0.0028165075927972794f, 0.002617558464407921f, 0.0023791473358869553f, 0.0028901207260787487f, 0.0030910661444067955f, 0.0034081023186445236f, 0.004300344735383987f, 0.0028083501383662224f, 0.0031840133015066385f, 0.0033450741320848465f, 0.0026748175732791424f, 0.0022175097838044167f, 0.0031716658268123865f, 0.0035232529044151306f, 0.0031614399049431086f, 0.003731454722583294f, 0.003898960305377841f, 0.002699274802580476f, 0.003963646478950977f, 0.0026024167891591787f, 0.002537697320804f, 0.0026790292467921972f, 0.002425288548693061f, 0.0031713703647255898f, 0.0030800302047282457f, 0.002852349542081356f, 0.00481607997789979f, 0.002864788519218564f, 0.0026303804479539394f, 0.002784027485176921f, 0.0031856070272624493f, 0.0034987065009772778f, 0.0029994945507496595f, 0.0035737589932978153f, 0.0032708151265978813f, 0.0023615278769284487f, 0.0025591980665922165f, 0.004469339270144701f, 0.003815547563135624f, 0.0026931955944746733f, 0.0022045776713639498f, 0.003069184022024274f, 0.0028486966621130705f, 0.002377523109316826f, 0.003388599492609501f, 0.003122087102383375f, 0.0029367362149059772f, 0.002291774144396186f, 0.003353422274813056f, 0.0027495278045535088f, 0.0036872131749987602f, 0.0028009526431560516f, 0.0033483521547168493f, 0.006958886049687862f, 0.002708397340029478f, 0.0034901981707662344f, 0.0034824558533728123f, 0.0032406237442046404f, 0.002389655914157629f, 0.004045410547405481f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_weights, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 512), AI_STRIDE_INIT(4, 1, 128, 65536, 65536),
  1, &_conv2_conv_Conv_output_0_weights_array, &_conv2_conv_Conv_output_0_weights_array_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_bias, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2048, 2048),
  1, &_conv2_conv_Conv_output_0_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  input_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 112, 3), AI_STRIDE_INIT(4, 1, 1, 96, 10752),
  1, &input_output_array, &input_output_array_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_alpha, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 512), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_conv2_conv_Conv_output_0_alpha_array, &_conv2_conv_Conv_output_0_alpha_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  input_Transpose_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 96, 112), AI_STRIDE_INIT(4, 1, 1, 3, 288),
  1, &input_Transpose_output_array, &input_Transpose_output_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_weights, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 512, 6, 7, 1), AI_STRIDE_INIT(4, 1, 512, 512, 3072),
  1, &_linear7_conv_Conv_output_0_weights_array, &_linear7_conv_Conv_output_0_weights_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 48, 56), AI_STRIDE_INIT(4, 1, 1, 64, 3072),
  1, &_conv1_conv_Conv_output_0_output_array, &_conv1_conv_Conv_output_0_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 48, 56), AI_STRIDE_INIT(4, 1, 1, 64, 3072),
  1, &_dw_conv1_conv_Conv_output_0_output_array, &_dw_conv1_conv_Conv_output_0_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_bias, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2048, 2048),
  1, &_linear7_conv_Conv_output_0_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 48, 56), AI_STRIDE_INIT(4, 1, 1, 128, 6144),
  1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_0_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_weights, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 512, 1, 1, 128), AI_STRIDE_INIT(4, 1, 512, 65536, 65536),
  1, &_linear1_conv_Conv_output_0_weights_array, &_linear1_conv_Conv_output_0_weights_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_0_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_0_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_bias, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_linear1_conv_Conv_output_0_bias_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_1_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_1_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_1_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_1_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_scratch0, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 4460, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4460, 4460),
  1, &_conv1_conv_Conv_output_0_scratch0_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_Add_output_0_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_1_Add_output_0_output_array, &_blocks_blocks_1_Add_output_0_output_array_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_2_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_scratch1, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 48, 56), AI_STRIDE_INIT(4, 1, 1, 64, 3072),
  1, &_conv1_conv_Conv_output_0_scratch1_array, &_conv1_conv_Conv_output_0_scratch1_array_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_2_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_2_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_2_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_Add_output_0_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_2_Add_output_0_output_array, &_blocks_blocks_2_Add_output_0_output_array_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &_dw_conv1_conv_Conv_output_0_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_3_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_3_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_scratch1, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 48, 56), AI_STRIDE_INIT(4, 1, 1, 64, 3072),
  1, &_dw_conv1_conv_Conv_output_0_scratch1_array, &_dw_conv1_conv_Conv_output_0_scratch1_array_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_3_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_3_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_Add_output_0_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_3_Add_output_0_output_array, &_blocks_blocks_3_Add_output_0_output_array_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_4_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_4_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_4_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_4_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 48, 56), AI_STRIDE_INIT(4, 1, 1, 128, 6144),
  1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_Add_output_0_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 28), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &_blocks_blocks_4_Add_output_0_output_array, &_blocks_blocks_4_Add_output_0_output_array_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 24, 28), AI_STRIDE_INIT(4, 1, 1, 256, 6144),
  1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_5_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_5_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_5_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_output, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_6_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_6_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_6_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_6_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_Add_output_0_output, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_6_Add_output_0_output_array, &_blocks_blocks_6_Add_output_0_output_array_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_7_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_7_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_output, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_7_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_7_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_Add_output_0_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_7_Add_output_0_output_array, &_blocks_blocks_7_Add_output_0_output_array_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_8_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_output, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_8_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_output, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_8_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_8_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_Add_output_0_output, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_8_Add_output_0_output_array, &_blocks_blocks_8_Add_output_0_output_array_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_output, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_9_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_output, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_9_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_output, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_9_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_9_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_Add_output_0_output, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_9_Add_output_0_output_array, &_blocks_blocks_9_Add_output_0_output_array_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_output, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_10_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &_blocks_blocks_1_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_output, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_10_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_output, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_10_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_10_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_Add_output_0_output, AI_STATIC,
  66, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_10_Add_output_0_output_array, &_blocks_blocks_10_Add_output_0_output_array_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_output, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_11_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_output, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_11_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_output, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_11_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_11_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_Add_output_0_output, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 12, 14), AI_STRIDE_INIT(4, 1, 1, 128, 1536),
  1, &_blocks_blocks_11_Add_output_0_output_array, &_blocks_blocks_11_Add_output_0_output_array_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_output, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 12, 14), AI_STRIDE_INIT(4, 1, 1, 512, 6144),
  1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_12_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_output, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 6, 7), AI_STRIDE_INIT(4, 1, 1, 512, 3072),
  1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_12_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_output, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 7), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_12_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_output, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_13_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_output, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_13_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_output, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 7), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &_blocks_blocks_13_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_13_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &_blocks_blocks_2_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_Add_output_0_output, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 7), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &_blocks_blocks_13_Add_output_0_output_array, &_blocks_blocks_13_Add_output_0_output_array_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_output, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_output_array, &_blocks_blocks_14_conv_conv_0_Conv_output_0_output_array_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_output, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_output_array, &_blocks_blocks_14_conv_conv_3_Conv_output_0_output_array_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_output, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 7), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &_blocks_blocks_14_conv_conv_6_Conv_output_0_output_array, &_blocks_blocks_14_conv_conv_6_Conv_output_0_output_array_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_Add_output_0_output, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 7), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &_blocks_blocks_14_Add_output_0_output_array, &_blocks_blocks_14_Add_output_0_output_array_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_output, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 6, 7), AI_STRIDE_INIT(4, 1, 1, 512, 3072),
  1, &_conv2_conv_Conv_output_0_output_array, &_conv2_conv_Conv_output_0_output_array_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_output, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &_linear7_conv_Conv_output_0_output_array, &_linear7_conv_Conv_output_0_output_array_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_output, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &_linear1_conv_Conv_output_0_output_array, &_linear1_conv_Conv_output_0_output_array_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_weights, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 64), AI_STRIDE_INIT(4, 1, 3, 192, 576),
  1, &_conv1_conv_Conv_output_0_weights_array, &_conv1_conv_Conv_output_0_weights_array_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_bias, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_conv1_conv_Conv_output_0_bias_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_alpha, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 64), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_conv1_conv_Conv_output_0_alpha_array, &_conv1_conv_Conv_output_0_alpha_array_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &_blocks_blocks_3_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_weights, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 64, 192),
  1, &_dw_conv1_conv_Conv_output_0_weights_array, &_dw_conv1_conv_Conv_output_0_weights_array_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_bias, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_dw_conv1_conv_Conv_output_0_bias_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_alpha, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 64), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_dw_conv1_conv_Conv_output_0_alpha_array, &_dw_conv1_conv_Conv_output_0_alpha_array_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 8192, 8192),
  1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 24, 28), AI_STRIDE_INIT(4, 1, 1, 128, 3072),
  1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &_blocks_blocks_4_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 8192),
  1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 2816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2816, 2816),
  1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 8192, 8192),
  1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  116, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 24, 28), AI_STRIDE_INIT(4, 1, 1, 256, 6144),
  1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  118, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  122, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 8192),
  1, &_blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_blocks_blocks_1_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 8192, 8192),
  1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  130, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  136, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 8192),
  1, &_blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_6_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_blocks_blocks_2_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  140, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 8192, 8192),
  1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  143, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  144, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  145, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  148, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  149, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  150, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 8192),
  1, &_blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_blocks_blocks_3_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_7_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 8192, 8192),
  1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  156, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  158, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 128, 384),
  1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  161, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 128), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  162, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 8192, 8192),
  1, &_blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &_blocks_blocks_4_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  165, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 256), AI_STRIDE_INIT(4, 1, 64, 16384, 16384),
  1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_8_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  168, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  169, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  170, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  176, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  177, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  178, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_9_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  180, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  181, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  183, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  186, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  187, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_6_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  190, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  191, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  193, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_10_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  194, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  197, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  198, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  199, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  200, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_7_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  203, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  204, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 12, 14), AI_STRIDE_INIT(4, 1, 1, 256, 3072),
  1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  205, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  206, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_11_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  208, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  210, 0x0,
  AI_SHAPE_INIT(4, 1, 5632, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5632, 5632),
  1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  211, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  212, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 12, 14), AI_STRIDE_INIT(4, 1, 1, 512, 6144),
  1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  213, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_8_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  215, 0x0,
  AI_SHAPE_INIT(4, 1, 18945, 1, 1), AI_STRIDE_INIT(4, 1, 1, 18945, 18945),
  1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  216, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  217, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 6, 7), AI_STRIDE_INIT(4, 1, 1, 512, 3072),
  1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  219, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  220, 0x0,
  AI_SHAPE_INIT(4, 1, 3328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3328, 3328),
  1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  221, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  223, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  224, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  225, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  226, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  227, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_9_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  228, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  230, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  231, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  232, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  233, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_13_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  235, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  236, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch0, AI_STATIC,
  237, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_scratch0_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  238, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1, AI_STATIC,
  239, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1_array, &_blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1_array_intq)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  240, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_10_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  241, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch0, AI_STATIC,
  242, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_scratch0_array, NULL)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  244, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1, AI_STATIC,
  245, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 6, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1536),
  1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1_array, &_blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1_array_intq)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  246, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  247, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_scratch0, AI_STATIC,
  248, 0x0,
  AI_SHAPE_INIT(4, 1, 2304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2304, 2304),
  1, &_blocks_blocks_14_conv_conv_6_Conv_output_0_scratch0_array, NULL)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  249, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  250, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_scratch0, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 1, 5632, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5632, 5632),
  1, &_conv2_conv_Conv_output_0_scratch0_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  252, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_11_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_scratch1, AI_STATIC,
  253, 0x1,
  AI_SHAPE_INIT(4, 1, 512, 6, 7), AI_STRIDE_INIT(4, 1, 1, 512, 3072),
  1, &_conv2_conv_Conv_output_0_scratch1_array, &_conv2_conv_Conv_output_0_scratch1_array_intq)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  254, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 512), AI_STRIDE_INIT(4, 1, 128, 65536, 65536),
  1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  255, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2048, 2048),
  1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_scratch0, AI_STATIC,
  256, 0x0,
  AI_SHAPE_INIT(4, 1, 69633, 1, 1), AI_STRIDE_INIT(4, 1, 1, 69633, 69633),
  1, &_linear7_conv_Conv_output_0_scratch0_array, NULL)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  257, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 512), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  258, 0x1,
  AI_SHAPE_INIT(4, 512, 3, 3, 1), AI_STRIDE_INIT(4, 1, 512, 512, 1536),
  1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_scratch0, AI_STATIC,
  259, 0x0,
  AI_SHAPE_INIT(4, 1, 3328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3328, 3328),
  1, &_linear1_conv_Conv_output_0_scratch0_array, NULL)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  260, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2048, 2048),
  1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  261, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 512), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  262, 0x1,
  AI_SHAPE_INIT(4, 512, 1, 1, 128), AI_STRIDE_INIT(4, 1, 512, 65536, 65536),
  1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  263, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #264 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  264, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #265 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  265, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #266 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  266, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #267 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  267, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #268 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  268, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #269 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  269, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #270 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  270, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #271 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  271, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_13_conv_conv_6_Conv_output_0_bias_array, NULL)

/* Tensor #272 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_weights, AI_STATIC,
  272, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 32768, 32768),
  1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array, &_blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array_intq)

/* Tensor #273 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_bias, AI_STATIC,
  273, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_bias_array, NULL)

/* Tensor #274 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_alpha, AI_STATIC,
  274, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array, &_blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array_intq)

/* Tensor #275 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_weights, AI_STATIC,
  275, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 256, 768),
  1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array, &_blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array_intq)

/* Tensor #276 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_bias, AI_STATIC,
  276, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_bias_array, NULL)

/* Tensor #277 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_alpha, AI_STATIC,
  277, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 256), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array, &_blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array_intq)

/* Tensor #278 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_weights, AI_STATIC,
  278, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 128), AI_STRIDE_INIT(4, 1, 256, 32768, 32768),
  1, &_blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array, &_blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array_intq)

/* Tensor #279 */
AI_TENSOR_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_bias, AI_STATIC,
  279, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &_blocks_blocks_14_conv_conv_6_Conv_output_0_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_linear7_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_linear1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_linear1_conv_Conv_output_0_weights, &_linear1_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_linear1_conv_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _linear1_conv_Conv_output_0_layer, 385,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_linear1_conv_Conv_output_0_chain,
  NULL, &_linear1_conv_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_linear7_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_linear7_conv_Conv_output_0_weights, &_linear7_conv_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_linear7_conv_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _linear7_conv_Conv_output_0_layer, 382,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_linear7_conv_Conv_output_0_chain,
  NULL, &_linear1_conv_Conv_output_0_layer, AI_STATIC, 
  .groups = 512, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv2_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_conv2_conv_Conv_output_0_weights, &_conv2_conv_Conv_output_0_bias, &_conv2_conv_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_conv2_conv_Conv_output_0_scratch0, &_conv2_conv_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _conv2_conv_Conv_output_0_layer, 379,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_conv2_conv_Conv_output_0_chain,
  NULL, &_linear7_conv_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_14_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_13_Add_output_0_output, &_blocks_blocks_14_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_14_Add_output_0_layer, 373,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_14_Add_output_0_chain,
  NULL, &_conv2_conv_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_14_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_14_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_6_Conv_output_0_layer, 370,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_14_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_14_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_14_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_14_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_14_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_14_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_3_Conv_output_0_layer, 367,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_14_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_14_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_14_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_14_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_14_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_14_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_14_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_14_conv_conv_0_Conv_output_0_layer, 361,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_14_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_14_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_13_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_12_conv_conv_6_Conv_output_0_output, &_blocks_blocks_13_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_13_Add_output_0_layer, 355,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_13_Add_output_0_chain,
  NULL, &_blocks_blocks_14_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_13_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_13_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_6_Conv_output_0_layer, 352,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_13_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_13_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_13_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_13_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_13_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_13_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_3_Conv_output_0_layer, 349,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_13_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_13_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_13_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_13_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_13_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_13_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_13_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_13_conv_conv_0_Conv_output_0_layer, 343,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_13_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_13_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_12_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_12_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_6_Conv_output_0_layer, 337,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_12_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_13_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_12_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_12_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_12_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_12_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_3_Conv_output_0_layer, 334,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_12_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_12_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 512, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_12_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_12_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_12_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_12_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_12_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_12_conv_conv_0_Conv_output_0_layer, 328,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_12_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_12_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_11_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_10_Add_output_0_output, &_blocks_blocks_11_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_11_Add_output_0_layer, 322,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_11_Add_output_0_chain,
  NULL, &_blocks_blocks_12_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_11_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_11_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_6_Conv_output_0_layer, 319,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_11_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_11_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_11_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_11_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_11_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_11_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_3_Conv_output_0_layer, 316,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_11_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_11_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_11_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_11_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_11_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_11_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_11_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_11_conv_conv_0_Conv_output_0_layer, 310,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_11_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_11_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_10_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_9_Add_output_0_output, &_blocks_blocks_10_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_10_Add_output_0_layer, 304,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_10_Add_output_0_chain,
  NULL, &_blocks_blocks_11_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_10_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_10_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_6_Conv_output_0_layer, 301,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_10_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_10_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_10_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_10_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_10_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_10_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_3_Conv_output_0_layer, 298,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_10_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_10_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_10_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_10_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_10_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_10_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_10_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_10_conv_conv_0_Conv_output_0_layer, 292,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_10_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_10_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_9_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_8_Add_output_0_output, &_blocks_blocks_9_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_9_Add_output_0_layer, 286,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_9_Add_output_0_chain,
  NULL, &_blocks_blocks_10_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_9_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_9_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_6_Conv_output_0_layer, 283,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_9_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_9_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_9_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_9_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_9_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_9_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_3_Conv_output_0_layer, 280,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_9_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_9_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_9_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_9_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_9_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_9_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_9_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_9_conv_conv_0_Conv_output_0_layer, 274,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_9_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_9_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_8_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_7_Add_output_0_output, &_blocks_blocks_8_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_8_Add_output_0_layer, 268,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_8_Add_output_0_chain,
  NULL, &_blocks_blocks_9_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_8_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_8_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_6_Conv_output_0_layer, 265,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_8_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_8_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_8_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_8_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_8_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_8_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_3_Conv_output_0_layer, 262,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_8_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_8_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_8_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_8_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_8_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_8_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_8_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_8_conv_conv_0_Conv_output_0_layer, 256,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_8_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_8_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_7_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_6_Add_output_0_output, &_blocks_blocks_7_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_7_Add_output_0_layer, 250,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_7_Add_output_0_chain,
  NULL, &_blocks_blocks_8_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_7_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_7_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_6_Conv_output_0_layer, 247,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_7_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_7_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_7_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_7_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_7_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_7_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_3_Conv_output_0_layer, 244,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_7_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_7_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_7_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_7_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_7_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_7_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_7_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_7_conv_conv_0_Conv_output_0_layer, 238,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_7_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_7_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_6_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_5_conv_conv_6_Conv_output_0_output, &_blocks_blocks_6_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_6_Add_output_0_layer, 232,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_6_Add_output_0_chain,
  NULL, &_blocks_blocks_7_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_6_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_6_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_6_Conv_output_0_layer, 229,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_6_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_6_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_6_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_6_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_6_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_6_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_3_Conv_output_0_layer, 226,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_6_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_6_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_6_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_6_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_6_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_6_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_6_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_6_conv_conv_0_Conv_output_0_layer, 220,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_6_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_6_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_5_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_5_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_6_Conv_output_0_layer, 214,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_5_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_6_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_5_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_5_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_5_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_5_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_3_Conv_output_0_layer, 211,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_5_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_5_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 256, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_5_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_5_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_5_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_5_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_5_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_5_conv_conv_0_Conv_output_0_layer, 205,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_5_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_5_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_4_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_3_Add_output_0_output, &_blocks_blocks_4_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_4_Add_output_0_layer, 199,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_4_Add_output_0_chain,
  NULL, &_blocks_blocks_5_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_4_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_4_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_6_Conv_output_0_layer, 196,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_4_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_4_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_4_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_4_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_4_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_4_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_3_Conv_output_0_layer, 193,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_4_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_4_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_4_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_4_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_4_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_4_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_4_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_4_conv_conv_0_Conv_output_0_layer, 187,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_4_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_4_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_3_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_2_Add_output_0_output, &_blocks_blocks_3_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_3_Add_output_0_layer, 181,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_3_Add_output_0_chain,
  NULL, &_blocks_blocks_4_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_3_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_3_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_6_Conv_output_0_layer, 178,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_3_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_3_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_3_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_3_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_3_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_3_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_3_Conv_output_0_layer, 175,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_3_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_3_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_3_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_3_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_3_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_3_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_3_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_3_conv_conv_0_Conv_output_0_layer, 169,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_3_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_3_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_2_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_1_Add_output_0_output, &_blocks_blocks_2_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_2_Add_output_0_layer, 163,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_2_Add_output_0_chain,
  NULL, &_blocks_blocks_3_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_2_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_2_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_6_Conv_output_0_layer, 160,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_2_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_2_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_2_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_2_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_2_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_2_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_3_Conv_output_0_layer, 157,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_2_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_2_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_2_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_2_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_2_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_2_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_2_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_2_conv_conv_0_Conv_output_0_layer, 151,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_2_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_2_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_1_Add_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_0_conv_conv_6_Conv_output_0_output, &_blocks_blocks_1_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_Add_output_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_1_Add_output_0_layer, 145,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &_blocks_blocks_1_Add_output_0_chain,
  NULL, &_blocks_blocks_2_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_1_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_1_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_6_Conv_output_0_layer, 142,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_1_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_1_Add_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_1_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_1_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_1_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_1_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_3_Conv_output_0_layer, 139,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_1_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_1_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_1_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_1_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_1_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_1_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_1_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_1_conv_conv_0_Conv_output_0_layer, 133,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_1_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_1_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_0_conv_conv_6_Conv_output_0_weights, &_blocks_blocks_0_conv_conv_6_Conv_output_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_6_Conv_output_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_6_Conv_output_0_layer, 127,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_0_conv_conv_6_Conv_output_0_chain,
  NULL, &_blocks_blocks_1_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_3_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_0_conv_conv_3_Conv_output_0_weights, &_blocks_blocks_0_conv_conv_3_Conv_output_0_bias, &_blocks_blocks_0_conv_conv_3_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_0_conv_conv_3_Conv_output_0_scratch0, &_blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_3_Conv_output_0_layer, 124,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_blocks_blocks_0_conv_conv_3_Conv_output_0_chain,
  NULL, &_blocks_blocks_0_conv_conv_6_Conv_output_0_layer, AI_STATIC, 
  .groups = 128, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_dw_conv1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_blocks_blocks_0_conv_conv_0_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_blocks_blocks_0_conv_conv_0_Conv_output_0_weights, &_blocks_blocks_0_conv_conv_0_Conv_output_0_bias, &_blocks_blocks_0_conv_conv_0_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_blocks_blocks_0_conv_conv_0_Conv_output_0_scratch0, &_blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _blocks_blocks_0_conv_conv_0_Conv_output_0_layer, 118,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &_blocks_blocks_0_conv_conv_0_Conv_output_0_chain,
  NULL, &_blocks_blocks_0_conv_conv_3_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_dw_conv1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_dw_conv1_conv_Conv_output_0_weights, &_dw_conv1_conv_Conv_output_0_bias, &_dw_conv1_conv_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_dw_conv1_conv_Conv_output_0_scratch0, &_dw_conv1_conv_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _dw_conv1_conv_Conv_output_0_layer, 112,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_sssa8_ch,
  &_dw_conv1_conv_Conv_output_0_chain,
  NULL, &_blocks_blocks_0_conv_conv_0_Conv_output_0_layer, AI_STATIC, 
  .groups = 64, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_Transpose_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &_conv1_conv_Conv_output_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &_conv1_conv_Conv_output_0_weights, &_conv1_conv_Conv_output_0_bias, &_conv1_conv_Conv_output_0_alpha),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &_conv1_conv_Conv_output_0_scratch0, &_conv1_conv_Conv_output_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  _conv1_conv_Conv_output_0_layer, 106,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_sssa8_ch,
  &_conv1_conv_Conv_output_0_chain,
  NULL, &_dw_conv1_conv_Conv_output_0_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_prelu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  input_Transpose_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_Transpose_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  input_Transpose_layer, 2,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &input_Transpose_chain,
  NULL, &_conv1_conv_Conv_output_0_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1019136, 1, 1),
    1019136, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 353408, 1, 1),
    353408, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1_OUT_NUM, &_linear1_conv_Conv_output_0_output),
  &input_Transpose_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1019136, 1, 1),
      1019136, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 353408, 1, 1),
      353408, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1_OUT_NUM, &_linear1_conv_Conv_output_0_output),
  &input_Transpose_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_1_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_1_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_output_array.data = AI_PTR(g_network_1_activations_map[0] + 182140);
    input_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 182140);
    
    input_Transpose_output_array.data = AI_PTR(g_network_1_activations_map[0] + 149884);
    input_Transpose_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 149884);
    
    _conv1_conv_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 182140);
    _conv1_conv_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 182140);
    
    _conv1_conv_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 6972);
    _conv1_conv_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 6972);
    
    _conv1_conv_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 6972);
    _conv1_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 6972);
    
    _dw_conv1_conv_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 179004);
    _dw_conv1_conv_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 179004);
    
    _dw_conv1_conv_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 700);
    _dw_conv1_conv_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 700);
    
    _dw_conv1_conv_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 181376);
    _dw_conv1_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 181376);
    
    _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 700);
    _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 700);
    
    _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 3200);
    _blocks_blocks_0_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 3200);
    
    _blocks_blocks_0_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 3200);
    _blocks_blocks_0_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 3200);
    
    _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 348668);
    _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 348668);
    
    _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_0_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_0_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_0_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_0_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 86016);
    _blocks_blocks_0_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 86016);
    
    _blocks_blocks_0_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_0_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_1_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_1_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 216192);
    _blocks_blocks_1_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 216192);
    
    _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_1_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_1_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_1_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_1_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_1_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_1_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 1152);
    _blocks_blocks_1_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 1152);
    
    _blocks_blocks_1_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 44160);
    _blocks_blocks_1_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 44160);
    
    _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_2_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_2_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 173184);
    _blocks_blocks_2_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 173184);
    
    _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_2_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_2_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 259200);
    _blocks_blocks_2_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 259200);
    
    _blocks_blocks_2_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_2_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_2_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 1152);
    _blocks_blocks_2_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 1152);
    
    _blocks_blocks_2_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_2_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_3_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_3_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 216192);
    _blocks_blocks_3_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 216192);
    
    _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_3_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_3_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_3_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_3_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_3_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_3_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 1152);
    _blocks_blocks_3_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 1152);
    
    _blocks_blocks_3_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 44160);
    _blocks_blocks_3_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 44160);
    
    _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_4_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_4_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 173184);
    _blocks_blocks_4_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 173184);
    
    _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_4_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_4_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 259200);
    _blocks_blocks_4_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 259200);
    
    _blocks_blocks_4_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_4_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_4_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 1152);
    _blocks_blocks_4_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 1152);
    
    _blocks_blocks_4_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 87168);
    _blocks_blocks_4_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 87168);
    
    _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_5_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_5_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 130176);
    _blocks_blocks_5_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 130176);
    
    _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 9476);
    _blocks_blocks_5_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 9476);
    
    _blocks_blocks_5_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 52484);
    _blocks_blocks_5_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 52484);
    
    _blocks_blocks_5_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_5_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_5_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_5_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 23808);
    _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 23808);
    
    _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 26880);
    _blocks_blocks_6_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 26880);
    
    _blocks_blocks_6_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 69888);
    _blocks_blocks_6_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 69888);
    
    _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 23808);
    _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 23808);
    
    _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 112896);
    _blocks_blocks_6_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 112896);
    
    _blocks_blocks_6_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 155904);
    _blocks_blocks_6_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 155904);
    
    _blocks_blocks_6_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_6_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_6_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 23808);
    _blocks_blocks_6_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 23808);
    
    _blocks_blocks_6_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_6_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 66816);
    _blocks_blocks_7_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 66816);
    
    _blocks_blocks_7_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 109824);
    _blocks_blocks_7_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 109824);
    
    _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 66816);
    _blocks_blocks_7_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 66816);
    
    _blocks_blocks_7_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 152832);
    _blocks_blocks_7_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 152832);
    
    _blocks_blocks_7_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_7_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_7_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_7_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_7_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 23808);
    _blocks_blocks_7_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 23808);
    
    _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_8_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_8_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 88320);
    _blocks_blocks_8_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 88320);
    
    _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_8_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_8_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 131328);
    _blocks_blocks_8_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 131328);
    
    _blocks_blocks_8_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_8_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_8_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_8_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_8_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_8_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 66816);
    _blocks_blocks_9_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 66816);
    
    _blocks_blocks_9_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 109824);
    _blocks_blocks_9_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 109824);
    
    _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 66816);
    _blocks_blocks_9_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 66816);
    
    _blocks_blocks_9_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 152832);
    _blocks_blocks_9_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 152832);
    
    _blocks_blocks_9_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_9_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_9_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_9_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_9_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 23808);
    _blocks_blocks_9_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 23808);
    
    _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_10_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_10_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 88320);
    _blocks_blocks_10_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 88320);
    
    _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_10_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_10_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 131328);
    _blocks_blocks_10_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 131328);
    
    _blocks_blocks_10_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_10_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_10_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_10_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_10_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_10_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 66816);
    _blocks_blocks_11_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 66816);
    
    _blocks_blocks_11_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 109824);
    _blocks_blocks_11_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 109824);
    
    _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 66816);
    _blocks_blocks_11_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 66816);
    
    _blocks_blocks_11_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 152832);
    _blocks_blocks_11_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 152832);
    
    _blocks_blocks_11_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_11_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_11_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_11_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_11_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 23808);
    _blocks_blocks_11_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 23808);
    
    _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 45312);
    _blocks_blocks_12_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 45312);
    
    _blocks_blocks_12_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 131328);
    _blocks_blocks_12_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 131328);
    
    _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 18948);
    _blocks_blocks_12_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 18948);
    
    _blocks_blocks_12_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 40452);
    _blocks_blocks_12_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 40452);
    
    _blocks_blocks_12_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_12_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_12_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 3328);
    _blocks_blocks_12_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 3328);
    
    _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 8704);
    _blocks_blocks_13_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 8704);
    
    _blocks_blocks_13_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 19456);
    _blocks_blocks_13_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 19456);
    
    _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 8704);
    _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 8704);
    
    _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 30208);
    _blocks_blocks_13_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 30208);
    
    _blocks_blocks_13_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 40960);
    _blocks_blocks_13_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 40960);
    
    _blocks_blocks_13_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_13_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_13_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 8704);
    _blocks_blocks_13_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 8704);
    
    _blocks_blocks_13_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 14080);
    _blocks_blocks_13_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 14080);
    
    _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 3072);
    _blocks_blocks_14_conv_conv_0_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 3072);
    
    _blocks_blocks_14_conv_conv_0_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 19456);
    _blocks_blocks_14_conv_conv_0_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 19456);
    
    _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 30208);
    _blocks_blocks_14_conv_conv_3_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 30208);
    
    _blocks_blocks_14_conv_conv_3_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 40960);
    _blocks_blocks_14_conv_conv_3_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 40960);
    
    _blocks_blocks_14_conv_conv_6_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _blocks_blocks_14_conv_conv_6_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _blocks_blocks_14_conv_conv_6_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 2304);
    _blocks_blocks_14_conv_conv_6_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 2304);
    
    _blocks_blocks_14_Add_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 7680);
    _blocks_blocks_14_Add_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 7680);
    
    _conv2_conv_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _conv2_conv_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _conv2_conv_Conv_output_0_scratch1_array.data = AI_PTR(g_network_1_activations_map[0] + 13056);
    _conv2_conv_Conv_output_0_scratch1_array.data_start = AI_PTR(g_network_1_activations_map[0] + 13056);
    
    _conv2_conv_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 34560);
    _conv2_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 34560);
    
    _linear7_conv_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 56064);
    _linear7_conv_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 56064);
    
    _linear7_conv_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 0);
    _linear7_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 0);
    
    _linear1_conv_Conv_output_0_scratch0_array.data = AI_PTR(g_network_1_activations_map[0] + 512);
    _linear1_conv_Conv_output_0_scratch0_array.data_start = AI_PTR(g_network_1_activations_map[0] + 512);
    
    _linear1_conv_Conv_output_0_output_array.data = AI_PTR(g_network_1_activations_map[0] + 3840);
    _linear1_conv_Conv_output_0_output_array.data_start = AI_PTR(g_network_1_activations_map[0] + 3840);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_1_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_1_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    _conv2_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _conv2_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 0);
    _conv2_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 0);
    
    _conv2_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _conv2_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 65536);
    _conv2_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 65536);
    
    _conv2_conv_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _conv2_conv_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 67584);
    _conv2_conv_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 67584);
    
    _linear7_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _linear7_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 68096);
    _linear7_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 68096);
    
    _linear7_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _linear7_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 89600);
    _linear7_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 89600);
    
    _linear1_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _linear1_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 91648);
    _linear1_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 91648);
    
    _linear1_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _linear1_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 157184);
    _linear1_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 157184);
    
    _conv1_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _conv1_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 157696);
    _conv1_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 157696);
    
    _conv1_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _conv1_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 159424);
    _conv1_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 159424);
    
    _conv1_conv_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _conv1_conv_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 159680);
    _conv1_conv_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 159680);
    
    _dw_conv1_conv_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _dw_conv1_conv_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 159744);
    _dw_conv1_conv_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 159744);
    
    _dw_conv1_conv_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _dw_conv1_conv_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 160320);
    _dw_conv1_conv_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 160320);
    
    _dw_conv1_conv_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _dw_conv1_conv_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 160576);
    _dw_conv1_conv_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 160576);
    
    _blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 160640);
    _blocks_blocks_0_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 160640);
    
    _blocks_blocks_0_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 168832);
    _blocks_blocks_0_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 168832);
    
    _blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 169344);
    _blocks_blocks_0_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 169344);
    
    _blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 169472);
    _blocks_blocks_0_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 169472);
    
    _blocks_blocks_0_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 170624);
    _blocks_blocks_0_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 170624);
    
    _blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 171136);
    _blocks_blocks_0_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 171136);
    
    _blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 171264);
    _blocks_blocks_0_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 171264);
    
    _blocks_blocks_0_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_0_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 179456);
    _blocks_blocks_0_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 179456);
    
    _blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 179712);
    _blocks_blocks_1_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 179712);
    
    _blocks_blocks_1_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 187904);
    _blocks_blocks_1_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 187904);
    
    _blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 188416);
    _blocks_blocks_1_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 188416);
    
    _blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 188544);
    _blocks_blocks_1_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 188544);
    
    _blocks_blocks_1_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 189696);
    _blocks_blocks_1_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 189696);
    
    _blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 190208);
    _blocks_blocks_1_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 190208);
    
    _blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 190336);
    _blocks_blocks_1_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 190336);
    
    _blocks_blocks_1_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_1_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 198528);
    _blocks_blocks_1_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 198528);
    
    _blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 198784);
    _blocks_blocks_2_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 198784);
    
    _blocks_blocks_2_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 206976);
    _blocks_blocks_2_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 206976);
    
    _blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 207488);
    _blocks_blocks_2_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 207488);
    
    _blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 207616);
    _blocks_blocks_2_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 207616);
    
    _blocks_blocks_2_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 208768);
    _blocks_blocks_2_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 208768);
    
    _blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 209280);
    _blocks_blocks_2_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 209280);
    
    _blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 209408);
    _blocks_blocks_2_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 209408);
    
    _blocks_blocks_2_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_2_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 217600);
    _blocks_blocks_2_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 217600);
    
    _blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 217856);
    _blocks_blocks_3_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 217856);
    
    _blocks_blocks_3_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 226048);
    _blocks_blocks_3_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 226048);
    
    _blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 226560);
    _blocks_blocks_3_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 226560);
    
    _blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 226688);
    _blocks_blocks_3_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 226688);
    
    _blocks_blocks_3_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 227840);
    _blocks_blocks_3_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 227840);
    
    _blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 228352);
    _blocks_blocks_3_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 228352);
    
    _blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 228480);
    _blocks_blocks_3_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 228480);
    
    _blocks_blocks_3_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_3_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 236672);
    _blocks_blocks_3_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 236672);
    
    _blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 236928);
    _blocks_blocks_4_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 236928);
    
    _blocks_blocks_4_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 245120);
    _blocks_blocks_4_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 245120);
    
    _blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 245632);
    _blocks_blocks_4_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 245632);
    
    _blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 245760);
    _blocks_blocks_4_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 245760);
    
    _blocks_blocks_4_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 246912);
    _blocks_blocks_4_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 246912);
    
    _blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 247424);
    _blocks_blocks_4_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 247424);
    
    _blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 247552);
    _blocks_blocks_4_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 247552);
    
    _blocks_blocks_4_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_4_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 255744);
    _blocks_blocks_4_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 255744);
    
    _blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 256000);
    _blocks_blocks_5_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 256000);
    
    _blocks_blocks_5_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 272384);
    _blocks_blocks_5_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 272384);
    
    _blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 273408);
    _blocks_blocks_5_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 273408);
    
    _blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 273664);
    _blocks_blocks_5_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 273664);
    
    _blocks_blocks_5_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 275968);
    _blocks_blocks_5_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 275968);
    
    _blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 276992);
    _blocks_blocks_5_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 276992);
    
    _blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 277248);
    _blocks_blocks_5_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 277248);
    
    _blocks_blocks_5_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_5_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 310016);
    _blocks_blocks_5_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 310016);
    
    _blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 310528);
    _blocks_blocks_6_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 310528);
    
    _blocks_blocks_6_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 343296);
    _blocks_blocks_6_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 343296);
    
    _blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 344320);
    _blocks_blocks_6_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 344320);
    
    _blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 344576);
    _blocks_blocks_6_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 344576);
    
    _blocks_blocks_6_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 346880);
    _blocks_blocks_6_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 346880);
    
    _blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 347904);
    _blocks_blocks_6_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 347904);
    
    _blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 348160);
    _blocks_blocks_6_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 348160);
    
    _blocks_blocks_6_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_6_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 380928);
    _blocks_blocks_6_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 380928);
    
    _blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 381440);
    _blocks_blocks_7_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 381440);
    
    _blocks_blocks_7_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 414208);
    _blocks_blocks_7_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 414208);
    
    _blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 415232);
    _blocks_blocks_7_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 415232);
    
    _blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 415488);
    _blocks_blocks_7_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 415488);
    
    _blocks_blocks_7_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 417792);
    _blocks_blocks_7_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 417792);
    
    _blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 418816);
    _blocks_blocks_7_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 418816);
    
    _blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 419072);
    _blocks_blocks_7_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 419072);
    
    _blocks_blocks_7_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_7_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 451840);
    _blocks_blocks_7_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 451840);
    
    _blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 452352);
    _blocks_blocks_8_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 452352);
    
    _blocks_blocks_8_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 485120);
    _blocks_blocks_8_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 485120);
    
    _blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 486144);
    _blocks_blocks_8_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 486144);
    
    _blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 486400);
    _blocks_blocks_8_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 486400);
    
    _blocks_blocks_8_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 488704);
    _blocks_blocks_8_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 488704);
    
    _blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 489728);
    _blocks_blocks_8_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 489728);
    
    _blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 489984);
    _blocks_blocks_8_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 489984);
    
    _blocks_blocks_8_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_8_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 522752);
    _blocks_blocks_8_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 522752);
    
    _blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 523264);
    _blocks_blocks_9_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 523264);
    
    _blocks_blocks_9_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 556032);
    _blocks_blocks_9_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 556032);
    
    _blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 557056);
    _blocks_blocks_9_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 557056);
    
    _blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 557312);
    _blocks_blocks_9_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 557312);
    
    _blocks_blocks_9_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 559616);
    _blocks_blocks_9_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 559616);
    
    _blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 560640);
    _blocks_blocks_9_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 560640);
    
    _blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 560896);
    _blocks_blocks_9_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 560896);
    
    _blocks_blocks_9_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_9_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 593664);
    _blocks_blocks_9_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 593664);
    
    _blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 594176);
    _blocks_blocks_10_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 594176);
    
    _blocks_blocks_10_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 626944);
    _blocks_blocks_10_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 626944);
    
    _blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 627968);
    _blocks_blocks_10_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 627968);
    
    _blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 628224);
    _blocks_blocks_10_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 628224);
    
    _blocks_blocks_10_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 630528);
    _blocks_blocks_10_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 630528);
    
    _blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 631552);
    _blocks_blocks_10_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 631552);
    
    _blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 631808);
    _blocks_blocks_10_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 631808);
    
    _blocks_blocks_10_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_10_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 664576);
    _blocks_blocks_10_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 664576);
    
    _blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 665088);
    _blocks_blocks_11_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 665088);
    
    _blocks_blocks_11_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 697856);
    _blocks_blocks_11_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 697856);
    
    _blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 698880);
    _blocks_blocks_11_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 698880);
    
    _blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 699136);
    _blocks_blocks_11_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 699136);
    
    _blocks_blocks_11_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 701440);
    _blocks_blocks_11_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 701440);
    
    _blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 702464);
    _blocks_blocks_11_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 702464);
    
    _blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 702720);
    _blocks_blocks_11_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 702720);
    
    _blocks_blocks_11_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_11_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 735488);
    _blocks_blocks_11_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 735488);
    
    _blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 736000);
    _blocks_blocks_12_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 736000);
    
    _blocks_blocks_12_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 801536);
    _blocks_blocks_12_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 801536);
    
    _blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 803584);
    _blocks_blocks_12_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 803584);
    
    _blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 804096);
    _blocks_blocks_12_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 804096);
    
    _blocks_blocks_12_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 808704);
    _blocks_blocks_12_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 808704);
    
    _blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 810752);
    _blocks_blocks_12_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 810752);
    
    _blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 811264);
    _blocks_blocks_12_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 811264);
    
    _blocks_blocks_12_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_12_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 876800);
    _blocks_blocks_12_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 876800);
    
    _blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 877312);
    _blocks_blocks_13_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 877312);
    
    _blocks_blocks_13_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 910080);
    _blocks_blocks_13_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 910080);
    
    _blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 911104);
    _blocks_blocks_13_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 911104);
    
    _blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 911360);
    _blocks_blocks_13_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 911360);
    
    _blocks_blocks_13_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 913664);
    _blocks_blocks_13_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 913664);
    
    _blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 914688);
    _blocks_blocks_13_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 914688);
    
    _blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 914944);
    _blocks_blocks_13_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 914944);
    
    _blocks_blocks_13_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_13_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 947712);
    _blocks_blocks_13_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 947712);
    
    _blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 948224);
    _blocks_blocks_14_conv_conv_0_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 948224);
    
    _blocks_blocks_14_conv_conv_0_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_0_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 980992);
    _blocks_blocks_14_conv_conv_0_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 980992);
    
    _blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 982016);
    _blocks_blocks_14_conv_conv_0_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 982016);
    
    _blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 982272);
    _blocks_blocks_14_conv_conv_3_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 982272);
    
    _blocks_blocks_14_conv_conv_3_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_3_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 984576);
    _blocks_blocks_14_conv_conv_3_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 984576);
    
    _blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array.data = AI_PTR(g_network_1_weights_map[0] + 985600);
    _blocks_blocks_14_conv_conv_3_Conv_output_0_alpha_array.data_start = AI_PTR(g_network_1_weights_map[0] + 985600);
    
    _blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array.data = AI_PTR(g_network_1_weights_map[0] + 985856);
    _blocks_blocks_14_conv_conv_6_Conv_output_0_weights_array.data_start = AI_PTR(g_network_1_weights_map[0] + 985856);
    
    _blocks_blocks_14_conv_conv_6_Conv_output_0_bias_array.format |= AI_FMT_FLAG_CONST;
    _blocks_blocks_14_conv_conv_6_Conv_output_0_bias_array.data = AI_PTR(g_network_1_weights_map[0] + 1018624);
    _blocks_blocks_14_conv_conv_6_Conv_output_0_bias_array.data_start = AI_PTR(g_network_1_weights_map[0] + 1018624);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_1_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_1_MODEL_NAME,
      .model_signature   = AI_NETWORK_1_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 194476864,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_1_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_1_MODEL_NAME,
      .model_signature   = AI_NETWORK_1_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 194476864,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_1_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_1_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_1_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_1_create(network, AI_NETWORK_1_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_1_data_params_get(&params) != true) {
        err = ai_network_1_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_1_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_1_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_1_init(*network, &params) != true) {
        err = ai_network_1_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_1_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_1_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_1_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_1_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_1_configure_weights(net_ctx, params);
  ok &= network_1_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_1_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_1_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_1_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

