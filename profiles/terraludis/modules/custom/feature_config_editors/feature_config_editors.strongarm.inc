<?php
/**
 * @file
 * feature_config_editors.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_config_editors_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_per_field_core';
  $strongarm->value = 1;
  $export['better_formats_per_field_core'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_fallback_format';
  $strongarm->value = 'plain_text';
  $export['filter_fallback_format'] = $strongarm;

  return $export;
}
