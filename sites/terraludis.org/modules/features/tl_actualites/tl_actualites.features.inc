<?php
/**
 * @file
 * tl_actualites.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tl_actualites_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
function tl_actualites_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tl_actualites_node_info() {
  $items = array(
    'actualite' => array(
      'name' => t('Actualité'),
      'base' => 'node_content',
      'description' => t('Actualité ou Brève publiée sur le site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
