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

  $export['version'] = '2.0';

  $export['menu-menu-menu-footer'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-menu-footer',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'tl_ruban' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tl_ruban',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['nice_menus-1'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '1',
    'module' => 'nice_menus',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'tl_ruban' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tl_ruban',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['shoutbox-shoutbox'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'shoutbox',
    'module' => 'shoutbox',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'tl_ruban' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tl_ruban',
        'weight' => '4',
      ),
    ),
    'title' => 'Chat-box',
    'visibility' => '0',
  );

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'online',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'tl_ruban' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tl_ruban',
        'weight' => '8',
      ),
    ),
    'title' => 'Qui est connecté ?',
    'visibility' => '0',
  );

  $export['views-groupes-block_universe'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'groupes-block_universe',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'tl_ruban' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tl_ruban',
        'weight' => '10',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
