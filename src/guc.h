/*
 * This file and its contents are licensed under the Apache License 2.0.
 * Please see the included NOTICE for copyright information and
 * LICENSE-APACHE for a copy of the license.
 */
#pragma once

#include <postgres.h>
#include "export.h"
#include "config.h"

#ifdef USE_TELEMETRY
extern bool ts_telemetry_on(void);
extern bool ts_function_telemetry_on(void);
#endif

extern bool ts_guc_enable_deprecation_warnings;
extern bool ts_guc_enable_optimizations;
extern bool ts_guc_enable_constraint_aware_append;
extern bool ts_guc_enable_ordered_append;
extern bool ts_guc_enable_chunk_append;
extern bool ts_guc_enable_parallel_chunk_append;
extern bool ts_guc_enable_qual_propagation;
extern bool ts_guc_enable_runtime_exclusion;
extern bool ts_guc_enable_constraint_exclusion;
extern bool ts_guc_enable_cagg_reorder_groupby;
extern bool ts_guc_enable_now_constify;
extern TSDLLEXPORT bool ts_guc_enable_cagg_watermark_constify;
extern bool ts_guc_enable_osm_reads;
extern TSDLLEXPORT bool ts_guc_enable_dml_decompression;
extern TSDLLEXPORT int ts_guc_max_tuples_decompressed_per_dml;
extern TSDLLEXPORT bool ts_guc_enable_transparent_decompression;
extern TSDLLEXPORT bool ts_guc_enable_decompression_logrep_markers;
extern TSDLLEXPORT bool ts_guc_enable_decompression_sorted_merge;
extern TSDLLEXPORT bool ts_guc_enable_async_append;
extern TSDLLEXPORT bool ts_guc_enable_skip_scan;
extern TSDLLEXPORT bool ts_guc_enable_chunkwise_aggregation;
extern TSDLLEXPORT bool ts_guc_enable_vectorized_aggregation;
extern bool ts_guc_restoring;
extern int ts_guc_max_open_chunks_per_insert;
extern int ts_guc_max_cached_chunks_per_hypertable;

#ifdef USE_TELEMETRY
typedef enum TelemetryLevel
{
	TELEMETRY_OFF,
	TELEMETRY_NO_FUNCTIONS,
	TELEMETRY_BASIC,
} TelemetryLevel;

extern TelemetryLevel ts_guc_telemetry_level;
extern char *ts_telemetry_cloud;
#endif

extern TSDLLEXPORT char *ts_guc_license;
extern char *ts_last_tune_time;
extern char *ts_last_tune_version;
extern TSDLLEXPORT bool ts_guc_enable_2pc;
extern TSDLLEXPORT bool ts_guc_enable_compression_indexscan;
extern TSDLLEXPORT bool ts_guc_enable_bulk_decompression;
extern TSDLLEXPORT int ts_guc_bgw_log_level;

#ifdef TS_DEBUG
extern bool ts_shutdown_bgw;
extern char *ts_current_timestamp_mock;
#else
#define ts_shutdown_bgw false
#endif

typedef enum DebugRequireVectorQual
{
	RVQ_Allow = 0,
	RVQ_Forbid,
	RVQ_Only
} DebugRequireVectorQual;

extern TSDLLEXPORT DebugRequireVectorQual ts_guc_debug_require_vector_qual;

extern TSDLLEXPORT bool ts_guc_debug_compression_path_info;

extern TSDLLEXPORT bool ts_guc_debug_require_batch_sorted_merge;

void _guc_init(void);

typedef enum
{
	FEATURE_HYPERTABLE,
	FEATURE_HYPERTABLE_COMPRESSION,
	FEATURE_CAGG,
	FEATURE_POLICY
} FeatureFlagType;

extern TSDLLEXPORT void ts_feature_flag_check(FeatureFlagType);
