<?php
/**
 * @file
 * tl_context_global.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tl_context_global_default_fe_block_settings() {
  $export = array();

  // tl_ruban
  $theme = array();

  $theme['menu-menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-menu-footer',
    'theme' => 'tl_ruban',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'tl_ruban',
    'status' => 0,
    'weight' => '-2',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['shoutbox-shoutbox'] = array(
    'module' => 'shoutbox',
    'delta' => 'shoutbox',
    'theme' => 'tl_ruban',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Chat-box',
    'cache' => '1',
  );

  $theme['user-online'] = array(
    'module' => 'user',
    'delta' => 'online',
    'theme' => 'tl_ruban',
    'status' => 0,
    'weight' => '5',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Qui est connecté ?',
    'cache' => -1,
  );

  $theme['views-groupes-block_universe'] = array(
    'module' => 'views',
    'delta' => 'groupes-block_universe',
    'theme' => 'tl_ruban',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['tl_ruban'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
