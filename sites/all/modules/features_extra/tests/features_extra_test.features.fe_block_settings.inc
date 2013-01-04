<?php
/**
 * @file
 * features_extra_test.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function features_extra_test_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'block-features_extra_test_block' => array(
      'machine_name' => 'features_extra_test_block',
      'module' => 'block',
    ),
  );

  // Exported block settings for Bartik.
  $theme = array();

  $theme['block-features_extra_test_block'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Features Extra',
    'cache' => -1,
    'machine_name' => 'features_extra_test_block',
  );

  $export['theme']['bartik'] = $theme;

  // Exported block settings for Seven.
  $theme = array();

  $theme['block-features_extra_test_block'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Features Extra',
    'cache' => -1,
    'machine_name' => 'features_extra_test_block',
  );

  $export['theme']['seven'] = $theme;

  $theme_default = variable_get('theme_default', 'bartik');
  $themes = list_themes();
  foreach ($export['theme'] as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}
