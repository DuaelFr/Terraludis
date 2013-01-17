<?php
/**
 * @file
 * tl_actualites.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function tl_actualites_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|actualite|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'actualite';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'author_linked',
      'ft' => array(
        'func' => 'theme_ds_field_minimal',
        'lb' => 'Publié par',
        'lb-col' => TRUE,
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'ds_post_date_date_court',
      'ft' => array(
        'func' => 'theme_ds_field_minimal',
        'lb' => 'le',
        'lb-col' => TRUE,
      ),
    ),
  );
  $export['node|actualite|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function tl_actualites_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|actualite|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'actualite';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'group_header',
        1 => 'author',
        2 => 'group_content',
        3 => 'comments',
        4 => 'post_date',
        5 => 'group_audience',
        6 => 'field_picture',
        7 => 'body',
        8 => 'field_news_links',
      ),
    ),
    'fields' => array(
      'group_header' => 'ds_content',
      'author' => 'ds_content',
      'group_content' => 'ds_content',
      'comments' => 'ds_content',
      'post_date' => 'ds_content',
      'group_audience' => 'ds_content',
      'field_picture' => 'ds_content',
      'body' => 'ds_content',
      'field_news_links' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|actualite|default'] = $ds_layout;

  return $export;
}
