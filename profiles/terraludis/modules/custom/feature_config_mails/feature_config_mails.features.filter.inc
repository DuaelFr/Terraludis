<?php
/**
 * @file
 * feature_config_mails.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function feature_config_mails_filter_default_formats() {
  $formats = array();

  // Exported format: Mail.
  $formats['mail'] = array(
    'format' => 'mail',
    'name' => 'Mail',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_autop' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
      'filter_emogrifier' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
