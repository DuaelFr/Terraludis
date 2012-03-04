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
 * Implements hook_image_default_styles().
 */
function tl_univers_image_default_styles() {
  $styles = array();

  // Exported image style: universe_icon
  $styles['universe_icon'] = array(
    'name' => 'universe_icon',
    'effects' => array(
      1 => array(
        'label' => 'Mise à l\'échelle et recadrage',
        'help' => 'La mise à l\'échelle et le recadrage maintiendront les proportions originales de l\'image puis recadreront la dimension la plus large. C\'est très utile pour créer des vignettes carrées sans étirer les images.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '30',
          'height' => '30',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
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
