<?php
/**
 * @file
 * tl_univers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tl_univers_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tl_univers_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function tl_univers_node_info() {
  $items = array(
    'groupe' => array(
      'name' => t('Groupe'),
      'base' => 'node_content',
      'description' => t('Groupe d\'utilisateurs. Comprend les Univers autant que les Groupes de travail.'),
      'has_title' => '1',
      'title_label' => t('Nom'),
      'help' => '',
    ),
  );
  return $items;
}
